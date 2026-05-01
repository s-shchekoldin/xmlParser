#include "xml.h"

#include <algorithm>
#include <chrono>
#include <cstdint>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <stdexcept>
#include <string>

namespace {

uint64_t g_payloadBytes = 0;
uint64_t g_payloadSegments = 0;
uint64_t g_payloadStarts = 0;
uint64_t g_payloadEnds = 0;
uint64_t g_finishTags = 0;
uint64_t g_attributes = 0;
uint64_t g_sink = 0;

[[noreturn]] void fail(const std::string & message)
{
    throw std::runtime_error(message);
}

std::string readFile(const std::string & path)
{
    std::ifstream file(path.c_str(), std::ios::binary);
    if (!file.good())
        fail("failed to open " + path);

    std::ostringstream out;
    out << file.rdbuf();
    return out.str();
}

std::size_t parsePositiveSize(const std::string & text, const char * name)
{
    std::size_t parsed = 0;
    const unsigned long long value = std::stoull(text, &parsed, 10);
    if (parsed != text.size() || value == 0)
        fail(std::string(name) + " must be a positive integer");
    if (value > std::numeric_limits<std::size_t>::max())
        fail(std::string(name) + " is too large");
    return static_cast<std::size_t>(value);
}

std::size_t parseChunkSize(const std::string & text)
{
    if (text == "full")
        return 0;
    return parsePositiveSize(text, "chunk size");
}

void ensureChunkFits(std::size_t size)
{
    if (size > std::numeric_limits<unsigned>::max())
        fail("chunk size exceeds parser API limit");
}

void parseFull(xml & parser, const std::string & input)
{
    ensureChunkFits(input.size());
    if (!parser.parse(input.data(), static_cast<unsigned>(input.size())))
        fail("parse failed in full-buffer mode");
}

void parseChunked(xml & parser, const std::string & input, std::size_t chunkSize)
{
    ensureChunkFits(chunkSize);

    for (std::size_t offset = 0; offset < input.size(); offset += chunkSize)
    {
        const std::size_t size = std::min(chunkSize, input.size() - offset);
        if (!parser.parse(input.data() + offset, static_cast<unsigned>(size)))
            fail("parse failed in chunked mode at offset " + std::to_string(offset));
    }
}

void printUsage(const char * exe)
{
    std::cerr << "usage: " << exe << " [input.xml] [repeat-count] [full|chunk-size]\n";
}

} // namespace

void xmlResult::payload(const char * data, unsigned len, bool isFirst, bool isLast)
{
    g_payloadBytes += len;
    ++g_payloadSegments;
    g_payloadStarts += isFirst ? 1 : 0;
    g_payloadEnds += isLast ? 1 : 0;
    if (len)
        g_sink += uint8_t(data[0]) + uint8_t(data[len - 1]);
}

void xmlResult::finishTag()
{
    ++g_finishTags;
    g_sink += opend + tag.size();
}

void xmlResult::getAttribute()
{
    ++g_attributes;
    g_sink += tag.size() + key.size() + value.size();
}

int main(int argc, char ** argv)
{
    try
    {
        if (argc > 4)
        {
            printUsage(argv[0]);
            return 1;
        }

        const std::string inputPath = argc >= 2 ? argv[1] : "input.txt";
        const std::size_t repeatCount = argc >= 3 ? parsePositiveSize(argv[2], "repeat count") : 1000;
        const std::string mode = argc >= 4 ? argv[3] : "full";
        const std::size_t chunkSize = parseChunkSize(mode);
        const std::string input = readFile(inputPath);
        const uint64_t totalBytes = static_cast<uint64_t>(input.size()) * repeatCount;

        xml parser;
        const auto start = std::chrono::steady_clock::now();
        for (std::size_t i = 0; i < repeatCount; ++i)
        {
            if (chunkSize == 0)
                parseFull(parser, input);
            else
                parseChunked(parser, input, chunkSize);
        }
        const auto stop = std::chrono::steady_clock::now();

        const std::chrono::duration<double> elapsed = stop - start;
        const double seconds = elapsed.count();
        const double mib = static_cast<double>(totalBytes) / (1024.0 * 1024.0);
        const double throughput = seconds > 0.0 ? mib / seconds : 0.0;

        std::cout << std::fixed << std::setprecision(6)
                  << "input=" << inputPath
                  << " repeat=" << repeatCount
                  << " mode=" << mode
                  << " bytes=" << totalBytes
                  << " seconds=" << seconds
                  << " mib_per_sec=" << throughput
                  << " payload_bytes=" << g_payloadBytes
                  << " payload_segments=" << g_payloadSegments
                  << " payload_starts=" << g_payloadStarts
                  << " payload_ends=" << g_payloadEnds
                  << " finish_tags=" << g_finishTags
                  << " attributes=" << g_attributes
                  << " sink=" << g_sink
                  << '\n';
    }
    catch (const std::exception & error)
    {
        std::cerr << "xmlBenchmark: " << error.what() << '\n';
        printUsage(argv[0]);
        return 1;
    }

    return 0;
}
