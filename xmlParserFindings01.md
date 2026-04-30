I inspected `xmlParser01.zip`. The C++ project builds cleanly and the included behavior tests pass. I also ran a no-op/counting-callback benchmark by repeating `input.txt`; absolute numbers are machine/container-specific, but the relative trends are useful. The table now includes original `HEAD` code measured from a temp build and the implemented C++ changes measured on 2026-05-01 with `xmlBenchmark input.txt 500000 ...`.

| Variant tested locally | Full-buffer parse | 4 KiB chunks | 1-byte chunks | Takeaway |
|---|---:|---:|---:|---|
| Original C++ code, `-O3 -march=native` | ~1090 MiB/s | ~1116 MiB/s | ~157 MiB/s | Same benchmark harness, no PGO |
| Original C++ code + GCC PGO | ~1396 MiB/s | ~1475 MiB/s | ~194 MiB/s | Same benchmark harness, trained in a temp build |
| Implemented dispatch/whitespace changes | ~1190 MiB/s | ~1198 MiB/s | ~165 MiB/s | Current code, no PGO |
| Implemented dispatch/whitespace + GCC PGO | ~1470 MiB/s | ~1513 MiB/s | ~193 MiB/s | Current code, trained with the benchmark target |

GCC documents that `-O3` enables additional optimizations beyond `-O2`, `-march=native` enables instruction subsets supported by the build machine and may reduce portability, `-fprofile-generate`/`-fprofile-use` enable profile-guided optimization, and `-flto` enables link-time optimization across translation units. CMake also has a target property for interprocedural optimization.

## Highest-value ideas

### 1. Do not benchmark `main.cc` as-is

`main.cc` prints each payload byte with one `printf("%c", data[i])`. That makes I/O dominate runtime and hides parser performance.

Replace this:

```cpp
for(unsigned i = 0; i < len; i++)
    printf("%c", data[i]);
```

with:

```cpp
std::fwrite(data, 1, len, stdout);
```

For real benchmarking, make callbacks no-op or count bytes/events only.

Implemented: `main.cc` now uses `std::fwrite`, and `xml_bench.cc` provides no-op/counting callbacks for parser timing.

---

### 2. Add PGO before changing much code

For this state-machine parser, branch probabilities matter. PGO is well-suited because the parser has many small states and predictable hot paths.

Implemented CMake flow:

```powershell
cmake -B .\build -DXML_PGO_MODE=GENERATE
cmake --build .\build --target xmlBenchmark
.\build\xmlBenchmark.exe input.txt 500000 full
.\build\xmlBenchmark.exe input.txt 500000 4096
.\build\xmlBenchmark.exe input.txt 500000 1

cmake -B .\build -DXML_PGO_MODE=USE
cmake --build .\build --target xmlBehaviorTests xmlBenchmark xmlParser
ctest --test-dir .\build --output-on-failure
```

`XML_PGO_DIR` defaults to `build/pgo`. In `USE` mode, CMake adds `-Wno-error=missing-profile` so untrained targets such as `xmlParser` or `xmlBehaviorTests` can warn without failing the build.

---

### 3. Change branch-selection loops to dispatch on the first byte

The current generated code often tries several cases sequentially. For example, at top level it tests newline range, whitespace range, `<`, then payload. For normal text payload, the parser pays for several failed tests before reaching the payload scanner.

A faster generated shape is:

```cpp
inline bool xml::loop1_1(StateT& state)
{
    if (state.data == state.end)
        return true;

    const uint8_t c = uint8_t(state.data[0]);

    if (c == '\r' || c == '\n')
        return range2_0(state);

    if (c == ' ' || c == '\t')
        return range3_0(state);

    if (c == '<')
        return text4_0(state);

    return range5_0(state);   // payload
}
```

Similar first-byte dispatch helps in:

```cpp
loop7_1   // after '<': comment, close-tag, open-tag
loop12_3  // inside an opening tag: '>', '/>', '?>', attribute
```

This keeps grammar behavior but removes a lot of failed branch work.

---

### 4. Replace short whitespace table scans with direct loops

Several `[ \t]*` states use 256-entry tables and a 16-byte unrolled scan. That is good for long runs, but XML attribute spacing is usually 0–2 bytes. Direct checks were faster in my local test.

For a zero-or-more whitespace state:

```cpp
inline bool xml::range12_2(StateT& state) const
{
    const char* start = state.data;

    while (state.data < state.end &&
          (state.data[0] == ' ' || state.data[0] == '\t'))
    {
        ++state.data;
    }

    if (state.data == state.end)
    {
        state.consumed += unsigned(state.data - start);
        state.node = NodeT::Range12_2;
        return true;
    }

    state.consumed = 0;
    state.node = NodeT::Loop12_3;
    return true;
}
```

Good candidates:

```cpp
range12_2  // spaces after tag name
range15_1  // spaces after attribute key
range15_3  // spaces after '='
range15_8  // spaces after attribute value
range3_0   // top-level spaces/tabs, but keep + semantics
```

This was the best pure code modification I tested.

---

### 5. Do not assume `memchr` is a free win

I tested replacing the `<` payload scan and `-` comment scan with `std::memchr`. On this sample it did not reliably beat the generated scanner; for 1-byte fragmentation it was worse. It may still help on workloads with very long text/comment runs, but it should be benchmarked against your real input.

A more controlled version would be to reuse the project’s existing AVX2/SSE2 style and add SIMD scanners for:

```cpp
range5_0   // scan until '<'
range10_0  // scan until '-'
string12_0 // tag name until space/tab/>
string15_0 // key until space/tab/=
```

The current file already uses AVX2/SSE2 for some string scans, and Intel’s Intrinsics Guide documents the SIMD intrinsics used for byte comparisons/masks.

---

### 6. Reduce `std::string` work for tag/key/value

The parser caps `tag`, `key`, and `value` at 256 bytes, but still uses `std::string::clear`, `length`, and `append`.

Lowest-risk tweak:

```cpp
struct xmlResult
{
    xmlResult()
    {
        key.reserve(256);
        tag.reserve(256);
        value.reserve(256);
    }

    std::string key;
    std::string tag;
    std::string value;
    uint32_t opend = 0;

    // ...
};
```

This helps long attributes/tags, but may hurt if almost all tokens fit in small-string optimization and you create many parser objects. Benchmark both.

Higher-impact API-breaking idea: replace the three `std::string`s with fixed buffers:

```cpp
struct Token256
{
    char data[256];
    uint16_t len = 0;

    void clear() { len = 0; }

    void append(const char* p, unsigned n)
    {
        const unsigned room = 256 - len;
        if (n > room) n = room;
        std::memcpy(data + len, p, n);
        len += uint16_t(n);
    }

    std::string_view view() const { return {data, len}; }
};
```

This avoids heap allocation entirely and makes the 256-byte cap explicit. It does change the public `xmlResult` shape, so it is only appropriate if you control downstream users.

---

### 7. Simplify the return stack for this grammar

`call4_1` always pushes `NodeT::Loop1_1`, and returns pop from `rstack`. For this generated grammar, the return target appears fixed.

Current pattern:

```cpp
state.node = NodeT::Label7_0;
state.rstack[state.rcount++] = NodeT::Loop1_1;
```

Possible generated special case:

```cpp
state.node = NodeT::Label7_0;
state.rstack[0] = NodeT::Loop1_1;
state.rcount = 1;
```

Or for this grammar only, return handlers could directly set:

```cpp
state.node = NodeT::Loop1_1;
return true;
```

This is a minor speedup, but it removes stack bookkeeping on every tag/comment.

---

### 8. Clean up close-tag depth handling

Current code uses:

```cpp
return opend--;
```

That relies on post-decrement converting the old value to `bool`; it also underflows on an unmatched closing tag. It is fast, but brittle.

Safer version:

```cpp
inline bool xml::func11_3()
{
    if (opend == 0)
        return false;
    --opend;
    return true;
}
```

This may add a branch. The tradeoff is correctness and avoiding `uint32_t` underflow after malformed input. Given the test suite already checks unmatched close-tag behavior, I would prefer the safer version unless a profiler proves it matters.

---

### 9. Consider LTO/IPO, but test it

CMake version:

```cmake
include(CheckIPOSupported)
check_ipo_supported(RESULT ipo_supported OUTPUT ipo_error)

if(ipo_supported)
    set_property(TARGET xml PROPERTY INTERPROCEDURAL_OPTIMIZATION_RELEASE TRUE)
    set_property(TARGET xmlParser PROPERTY INTERPROCEDURAL_OPTIMIZATION_RELEASE TRUE)
endif()
```

LTO may inline callbacks and improve state-machine layout, but it can also expose callback costs that were previously hidden behind function calls. Use it with representative callbacks, not only no-op callbacks.

---

## Rust-specific observations

`XmlRust.rs` has two likely high-impact issues:

First, it keeps `vstate: Vec<StateT>` and runs a multi-state/reparse loop, while the C++ parser uses a single state. If this grammar is deterministic, changing Rust to a single `StateT` should remove vector indexing, resize, copying, and outer reparse overhead.

Second, token accumulation does this:

```rust
self.output.tag().push_str(&String::from_utf8_lossy(&data[0 .. len]));
```

That may allocate or copy more than necessary. If XML bytes are guaranteed UTF-8, use:

```rust
let s = unsafe { std::str::from_utf8_unchecked(&data[..len]) };
self.output.tag().push_str(s);
```

If arbitrary bytes are allowed, store `Vec<u8>` or a fixed `[u8; 256]` token instead of `String`.

For Rust scanning, the `memchr` crate provides optimized 1-, 2-, and 3-byte search routines and documents SIMD support on major targets; Rust’s `std::arch`/`core::arch` intrinsics are available but non-portable and target-feature-gated.

## Implemented order of work

- [x] Benchmark hygiene: replaced per-byte payload printing in `main.cc` with `std::fwrite`.
- [x] Reproducible benchmark target: added `xmlBenchmark`, with file path, repeat count, and `full` or numeric chunk-size arguments.
- [x] CMake PGO workflow: added `XML_PGO_MODE=OFF|GENERATE|USE` and `XML_PGO_DIR`.
- [x] Parser dispatch: changed `loop1_1`, `loop7_1`, and `loop12_3` to first-byte routing while keeping full-buffer fallback for `<!not-comment>` and `/` or `?` attribute keys.
- [x] Whitespace scans: simplified `range3_0`, `range12_2`, `range15_1`, `range15_3`, and `range15_8` to direct space/tab loops.
- [x] Depth safety: replaced `return opend--;` with explicit zero checks and decrement logic.
- [x] Tests: expanded behavior coverage for whitespace fragmentation, ambiguous branch fallback, and unmatched close-tag depth underflow.

Commands used for the final measurements:

```powershell
cmake -B .\build -DXML_PGO_MODE=OFF
cmake --build .\build --target xmlBehaviorTests xmlBenchmark xmlParser
ctest --test-dir .\build --output-on-failure
.\build\xmlBenchmark.exe input.txt 500000 full
.\build\xmlBenchmark.exe input.txt 500000 4096
.\build\xmlBenchmark.exe input.txt 500000 1

cmake -B .\build -DXML_PGO_MODE=GENERATE
cmake --build .\build --target xmlBehaviorTests xmlBenchmark
.\build\xmlBenchmark.exe input.txt 500000 full
.\build\xmlBenchmark.exe input.txt 500000 4096
.\build\xmlBenchmark.exe input.txt 500000 1

cmake -B .\build -DXML_PGO_MODE=USE
cmake --build .\build --target xmlBehaviorTests xmlBenchmark xmlParser
ctest --test-dir .\build --output-on-failure
.\build\xmlBenchmark.exe input.txt 500000 full
.\build\xmlBenchmark.exe input.txt 500000 4096
.\build\xmlBenchmark.exe input.txt 500000 1
```

Still deferred: SIMD scanner work, replacing `std::string` tokens with fixed buffers, Rust parser changes, and LTO/IPO tuning.
