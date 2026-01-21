// ==============================================================
// Date: 2026-01-21 18:12:37 GMT
// Generated using vProto(2026.01.21)        https://www.cgen.dev
// Author: Sergey V. Shchekoldin     Email: shchekoldin@gmail.com
// autoSSE: 1 cpp98: 0 (SSE4.2: 0 AVX2: 1 SSE2: 1)
// ==============================================================

// To enable AVX2 use: -mavx2
// To enable SSE2 use: -msse2
// Or: -march=native (may break compatibility)
#include "xml.h"
#if defined(__SSE4_2__) || defined(__AVX2__)
#include <immintrin.h>
#endif
#if defined(__SSE2__)
#include <emmintrin.h>
#endif

#if defined(_MSC_VER)
#include <intrin.h>
inline unsigned __ctz32(uint32_t x) { return _tzcnt_u32(x); }
#else
inline unsigned __ctz32(uint32_t x) { return __builtin_ctz(x); }
#endif

inline void xml::parse(StateT & state)
{
    while(true)
    {
#ifdef DEBUG_MODE
        printf("State%s: %s data: [%x, %x, %x, %x, %x]=%.*s\n", &state == &mstate ? "" : "*", state.name(),
            uint8_t(&state.data[0] < state.end ? state.data[0] : 0),
            uint8_t(&state.data[1] < state.end ? state.data[1] : 0),
            uint8_t(&state.data[2] < state.end ? state.data[2] : 0),
            uint8_t(&state.data[3] < state.end ? state.data[3] : 0),
            uint8_t(&state.data[4] < state.end ? state.data[4] : 0),
            10, state.data);
#endif
        NodeT n = state.node;
        const char * d = state.data;
        switch(state.node)
        {
            case NodeT::Loop1_0: loop1_0(state); break;
            case NodeT::Label1_0: if (!label1_0(state) || state.node != NodeT::Loop1_1) break; [[fallthrough]];
            case NodeT::Loop1_1: loop1_1(state); break;
            case NodeT::Range2_0: range2_0(state); break;
            case NodeT::Range3_0: range3_0(state); break;
            case NodeT::Text4_0: if (!text4_0(state) || state.node != NodeT::Call4_1) break; [[fallthrough]];
            case NodeT::Call4_1: call4_1(state); break;
            case NodeT::Range5_0: range5_0(state); break;
            case NodeT::Loop7_0: loop7_0(state); break;
            case NodeT::Label7_0: if (!label7_0(state) || state.node != NodeT::Loop7_1) break; [[fallthrough]];
            case NodeT::Loop7_1: loop7_1(state); break;
            case NodeT::Text8_0: if (!text8_0(state, false) || state.node != NodeT::Loop8_1) break; [[fallthrough]];
            case NodeT::Loop8_1: loop8_1(state); break;
            case NodeT::Text9_0: if (!text9_0(state, false) || state.node != NodeT::Ret9_1) break; [[fallthrough]];
            case NodeT::Ret9_1: ret9_1(state); break;
            case NodeT::Range10_0: range10_0(state); break;
            case NodeT::Text11_0: if (!text11_0(state) || state.node != NodeT::String11_1) break; [[fallthrough]];
            case NodeT::String11_1: if (!string11_1(state) || state.node != NodeT::Range11_2) break; [[fallthrough]];
            case NodeT::Range11_2: if (!range11_2(state) || state.node != NodeT::Func11_3) break; [[fallthrough]];
            case NodeT::Func11_3: if (!func11_3(state) || state.node != NodeT::Notify11_4) break; [[fallthrough]];
            case NodeT::Notify11_4: if (!notify11_4(state) || state.node != NodeT::Ret11_5) break; [[fallthrough]];
            case NodeT::Ret11_5: ret11_5(state); break;
            case NodeT::String12_0: if (!string12_0(state) || state.node != NodeT::Func12_1) break; [[fallthrough]];
            case NodeT::Func12_1: if (!func12_1(state) || state.node != NodeT::Range12_2) break; [[fallthrough]];
            case NodeT::Range12_2: if (!range12_2(state) || state.node != NodeT::Loop12_3) break; [[fallthrough]];
            case NodeT::Loop12_3: loop12_3(state); break;
            case NodeT::Text13_0: if (!text13_0(state) || state.node != NodeT::Ret13_1) break; [[fallthrough]];
            case NodeT::Ret13_1: ret13_1(state); break;
            case NodeT::Range14_0: if (!range14_0(state) || state.node != NodeT::Text14_1) break; [[fallthrough]];
            case NodeT::Text14_1: if (!text14_1(state) || state.node != NodeT::Func14_2) break; [[fallthrough]];
            case NodeT::Func14_2: if (!func14_2(state) || state.node != NodeT::Notify14_3) break; [[fallthrough]];
            case NodeT::Notify14_3: if (!notify14_3(state) || state.node != NodeT::Ret14_4) break; [[fallthrough]];
            case NodeT::Ret14_4: ret14_4(state); break;
            case NodeT::String15_0: if (!string15_0(state) || state.node != NodeT::Range15_1) break; [[fallthrough]];
            case NodeT::Range15_1: if (!range15_1(state) || state.node != NodeT::Text15_2) break; [[fallthrough]];
            case NodeT::Text15_2: if (!text15_2(state) || state.node != NodeT::Range15_3) break; [[fallthrough]];
            case NodeT::Range15_3: if (!range15_3(state) || state.node != NodeT::Range15_4) break; [[fallthrough]];
            case NodeT::Range15_4: if (!range15_4(state) || state.node != NodeT::String15_5) break; [[fallthrough]];
            case NodeT::String15_5: if (!string15_5(state) || state.node != NodeT::Range15_6) break; [[fallthrough]];
            case NodeT::Range15_6: if (!range15_6(state) || state.node != NodeT::Notify15_7) break; [[fallthrough]];
            case NodeT::Notify15_7: if (!notify15_7(state) || state.node != NodeT::Range15_8) break; [[fallthrough]];
            case NodeT::Range15_8: range15_8(state); break;
            case NodeT::Loop17_0: loop17_0(state); break;
            case NodeT::Uint17_0: uint17_0(state); break;
            case NodeT::NoState:
            default: return;
        }; // switch
        if (d == state.data && n == state.node) [[unlikely]]
            break;
    }
}

bool xml::parse(const char * data, unsigned len)
{
    mstate.data = data;
    mstate.end = &data[len];
    parse(mstate);
    return mstate.node != NodeT::NoState;
}

inline bool xml::loop1_0(StateT & state) const
{
    return label1_0(state);
}

inline bool xml::label1_0(StateT & state) const
{
    state.node = NodeT::Loop1_1;
    return true;
}

inline bool xml::loop1_1(StateT & state)
{
    if (state.data == state.end)
        return true;
    if (range2_0(state)) // case_1
        return true;
    if (range3_0(state)) // case_2
        return true;
    if (text4_0(state)) // case_3
        return true;
    if (range5_0(state)) // case_4
        return true;
    state.node = NodeT::NoState;
    return true;
}

inline bool xml::range2_0(StateT & state) const
{
    const static std::array<bool, 256> terminator = {
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true, false,  true,  true, false,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true}; // [0xa][0xd]
    const char * datastart = state.data;
    while(state.data < state.end) [[likely]]
    {
        if(&state.data[16] <= state.end)
        {
            if (terminator[uint8_t(state.data[0])]) [[unlikely]]
                state.data += 0;
            else if (terminator[uint8_t(state.data[1])]) [[unlikely]]
                state.data += 1;
            else if (terminator[uint8_t(state.data[2])]) [[unlikely]]
                state.data += 2;
            else if (terminator[uint8_t(state.data[3])]) [[unlikely]]
                state.data += 3;
            else if (terminator[uint8_t(state.data[4])]) [[unlikely]]
                state.data += 4;
            else if (terminator[uint8_t(state.data[5])]) [[unlikely]]
                state.data += 5;
            else if (terminator[uint8_t(state.data[6])]) [[unlikely]]
                state.data += 6;
            else if (terminator[uint8_t(state.data[7])]) [[unlikely]]
                state.data += 7;
            else if (terminator[uint8_t(state.data[8])]) [[unlikely]]
                state.data += 8;
            else if (terminator[uint8_t(state.data[9])]) [[unlikely]]
                state.data += 9;
            else if (terminator[uint8_t(state.data[10])]) [[unlikely]]
                state.data += 10;
            else if (terminator[uint8_t(state.data[11])]) [[unlikely]]
                state.data += 11;
            else if (terminator[uint8_t(state.data[12])]) [[unlikely]]
                state.data += 12;
            else if (terminator[uint8_t(state.data[13])]) [[unlikely]]
                state.data += 13;
            else if (terminator[uint8_t(state.data[14])]) [[unlikely]]
                state.data += 14;
            else if (terminator[uint8_t(state.data[15])]) [[unlikely]]
                state.data += 15;
            else
            {
                state.data += 16;
                continue;
            }
        }
        else if (!(terminator[uint8_t(state.data[0])])) [[unlikely]]
        {
            state.data++;
            continue;
        }
        uint64_t total = state.consumed + unsigned(state.data - datastart);
        state.consumed = 0;
        if (total >= 1)
        {
            state.node = NodeT::Loop1_1;
            return true;
        } else {
            state.node = NodeT::NoState;
            return false;
        }
    }
    state.consumed += unsigned(state.data - datastart);
    state.node = NodeT::Range2_0;
    return true;
}

inline bool xml::range3_0(StateT & state) const
{
    const static std::array<bool, 256> terminator = {
         true,  true,  true,  true,  true,  true,  true,  true,  true, false,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
        false,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true}; // [0x9][0x20]
    const char * datastart = state.data;
    while(state.data < state.end) [[likely]]
    {
        if(&state.data[16] <= state.end)
        {
            if (terminator[uint8_t(state.data[0])]) [[unlikely]]
                state.data += 0;
            else if (terminator[uint8_t(state.data[1])]) [[unlikely]]
                state.data += 1;
            else if (terminator[uint8_t(state.data[2])]) [[unlikely]]
                state.data += 2;
            else if (terminator[uint8_t(state.data[3])]) [[unlikely]]
                state.data += 3;
            else if (terminator[uint8_t(state.data[4])]) [[unlikely]]
                state.data += 4;
            else if (terminator[uint8_t(state.data[5])]) [[unlikely]]
                state.data += 5;
            else if (terminator[uint8_t(state.data[6])]) [[unlikely]]
                state.data += 6;
            else if (terminator[uint8_t(state.data[7])]) [[unlikely]]
                state.data += 7;
            else if (terminator[uint8_t(state.data[8])]) [[unlikely]]
                state.data += 8;
            else if (terminator[uint8_t(state.data[9])]) [[unlikely]]
                state.data += 9;
            else if (terminator[uint8_t(state.data[10])]) [[unlikely]]
                state.data += 10;
            else if (terminator[uint8_t(state.data[11])]) [[unlikely]]
                state.data += 11;
            else if (terminator[uint8_t(state.data[12])]) [[unlikely]]
                state.data += 12;
            else if (terminator[uint8_t(state.data[13])]) [[unlikely]]
                state.data += 13;
            else if (terminator[uint8_t(state.data[14])]) [[unlikely]]
                state.data += 14;
            else if (terminator[uint8_t(state.data[15])]) [[unlikely]]
                state.data += 15;
            else
            {
                state.data += 16;
                continue;
            }
        }
        else if (!(terminator[uint8_t(state.data[0])])) [[unlikely]]
        {
            state.data++;
            continue;
        }
        uint64_t total = state.consumed + unsigned(state.data - datastart);
        state.consumed = 0;
        if (total >= 1)
        {
            state.node = NodeT::Loop1_1;
            return true;
        } else {
            state.node = NodeT::NoState;
            return false;
        }
    }
    state.consumed += unsigned(state.data - datastart);
    state.node = NodeT::Range3_0;
    return true;
}

inline bool xml::text4_0(StateT & state) const
{
    if(state.data < state.end)
    {
        if (uint8_t(0x3C) != uint8_t(state.data[0]))
        {
            state.node = NodeT::NoState;
            return false;
        } else {
            state.data++;
            state.node = NodeT::Call4_1;
            return true;
        }
    }
    state.node = NodeT::Text4_0;
    return true;
}

inline bool xml::call4_1(StateT & state) const
{
    state.node = NodeT::Label7_0;
    if (state.rcount < state.rstack.size())
        state.rstack[state.rcount++] = NodeT::Loop1_1;
    else
    {
        for(unsigned i = 1; i < state.rstack.size(); i++)
            state.rstack[i - 1] = state.rstack[i];
        state.rstack[state.rstack.size() - 1] = NodeT::Loop1_1;
    }
    return true;
}

inline bool xml::range5_0(StateT & state)
{
    const char * datastart = state.data;
    while(state.data < state.end) [[likely]]
    {
        if(&state.data[16] <= state.end)
        {
            if (uint8_t(state.data[0]) == uint8_t(0x3c)) [[unlikely]]
                state.data += 0;
            else if (uint8_t(state.data[1]) == uint8_t(0x3c)) [[unlikely]]
                state.data += 1;
            else if (uint8_t(state.data[2]) == uint8_t(0x3c)) [[unlikely]]
                state.data += 2;
            else if (uint8_t(state.data[3]) == uint8_t(0x3c)) [[unlikely]]
                state.data += 3;
            else if (uint8_t(state.data[4]) == uint8_t(0x3c)) [[unlikely]]
                state.data += 4;
            else if (uint8_t(state.data[5]) == uint8_t(0x3c)) [[unlikely]]
                state.data += 5;
            else if (uint8_t(state.data[6]) == uint8_t(0x3c)) [[unlikely]]
                state.data += 6;
            else if (uint8_t(state.data[7]) == uint8_t(0x3c)) [[unlikely]]
                state.data += 7;
            else if (uint8_t(state.data[8]) == uint8_t(0x3c)) [[unlikely]]
                state.data += 8;
            else if (uint8_t(state.data[9]) == uint8_t(0x3c)) [[unlikely]]
                state.data += 9;
            else if (uint8_t(state.data[10]) == uint8_t(0x3c)) [[unlikely]]
                state.data += 10;
            else if (uint8_t(state.data[11]) == uint8_t(0x3c)) [[unlikely]]
                state.data += 11;
            else if (uint8_t(state.data[12]) == uint8_t(0x3c)) [[unlikely]]
                state.data += 12;
            else if (uint8_t(state.data[13]) == uint8_t(0x3c)) [[unlikely]]
                state.data += 13;
            else if (uint8_t(state.data[14]) == uint8_t(0x3c)) [[unlikely]]
                state.data += 14;
            else if (uint8_t(state.data[15]) == uint8_t(0x3c)) [[unlikely]]
                state.data += 15;
            else
            {
                state.data += 16;
                continue;
            }
        }
        else if (!(uint8_t(state.data[0]) == uint8_t(0x3c))) [[unlikely]]
        {
            state.data++;
            continue;
        }
        xmlResult::payload(datastart, unsigned(state.data - datastart), !state.consumed, true);
        uint64_t total = state.consumed + unsigned(state.data - datastart);
        state.consumed = 0;
        if (total >= 1)
        {
            state.node = NodeT::Loop1_1;
            return true;
        } else {
            state.node = NodeT::NoState;
            return false;
        }
    }
    if (datastart < state.data)
        xmlResult::payload(datastart, unsigned(state.data - datastart), !state.consumed, false);
    state.consumed += unsigned(state.data - datastart);
    state.node = NodeT::Range5_0;
    return true;
}

inline bool xml::loop7_0(StateT & state) const
{
    return label7_0(state);
}

inline bool xml::label7_0(StateT & state) const
{
    state.node = NodeT::Loop7_1;
    return true;
}

inline bool xml::loop7_1(StateT & state)
{
    if (state.data == state.end)
        return true;
    if (text8_0(state, true)) // case_1
        return true;
    if (text11_0(state)) // case_2
        return true;
    if (string12_0(state)) // case_3
        return true;
    state.node = NodeT::NoState;
    return true;
}

inline bool xml::text8_0(StateT & state, bool is_branch) const
{
    const static std::array<uint8_t, 3> text = {0x21, 0x2d, 0x2d}; // !--
    for(; state.data < state.end; state.data++)
    {
        if (text[state.consumed] != uint8_t(state.data[0]))
        {
            state.node = NodeT::NoState;
            bool ret = is_branch && state.consumed;
            state.consumed = 0;
            return ret;
        }
        else if (++state.consumed >= text.size())
        {
            state.data++;
            state.consumed = 0;
            state.node = NodeT::Loop8_1;
            return true;
        }
    }
    state.node = NodeT::Text8_0;
    return true;
}

inline bool xml::loop8_1(StateT & state) const
{
    if (state.data == state.end)
        return true;
    if (text9_0(state, true)) // case_1
        return true;
    state.node = NodeT::Range10_0;
    return true;
}

inline bool xml::text9_0(StateT & state, bool is_branch) const
{
    const static std::array<uint8_t, 3> text = {0x2d, 0x2d, 0x3e}; // -->
    for(; state.data < state.end; state.data++)
    {
        if (text[state.consumed] != uint8_t(state.data[0]))
        {
            state.node = NodeT::Range10_0;
            bool ret = is_branch && state.consumed;
            state.consumed = 0;
            return ret;
        }
        else if (++state.consumed >= text.size())
        {
            state.data++;
            state.consumed = 0;
            state.node = NodeT::Ret9_1;
            return true;
        }
    }
    state.node = NodeT::Text9_0;
    return true;
}

inline bool xml::ret9_1(StateT & state) const
{
    state.node = state.rcount ? state.rstack[--state.rcount] : NodeT::NoState;
    return state.node != NodeT::NoState;
}

inline bool xml::range10_0(StateT & state) const
{
    const char * datastart = state.data;
    while(state.data < state.end) [[likely]]
    {
        if(&state.data[16] <= state.end)
        {
            if (uint8_t(state.data[0]) == uint8_t(0x2d)) [[unlikely]]
                state.data += 0;
            else if (uint8_t(state.data[1]) == uint8_t(0x2d)) [[unlikely]]
                state.data += 1;
            else if (uint8_t(state.data[2]) == uint8_t(0x2d)) [[unlikely]]
                state.data += 2;
            else if (uint8_t(state.data[3]) == uint8_t(0x2d)) [[unlikely]]
                state.data += 3;
            else if (uint8_t(state.data[4]) == uint8_t(0x2d)) [[unlikely]]
                state.data += 4;
            else if (uint8_t(state.data[5]) == uint8_t(0x2d)) [[unlikely]]
                state.data += 5;
            else if (uint8_t(state.data[6]) == uint8_t(0x2d)) [[unlikely]]
                state.data += 6;
            else if (uint8_t(state.data[7]) == uint8_t(0x2d)) [[unlikely]]
                state.data += 7;
            else if (uint8_t(state.data[8]) == uint8_t(0x2d)) [[unlikely]]
                state.data += 8;
            else if (uint8_t(state.data[9]) == uint8_t(0x2d)) [[unlikely]]
                state.data += 9;
            else if (uint8_t(state.data[10]) == uint8_t(0x2d)) [[unlikely]]
                state.data += 10;
            else if (uint8_t(state.data[11]) == uint8_t(0x2d)) [[unlikely]]
                state.data += 11;
            else if (uint8_t(state.data[12]) == uint8_t(0x2d)) [[unlikely]]
                state.data += 12;
            else if (uint8_t(state.data[13]) == uint8_t(0x2d)) [[unlikely]]
                state.data += 13;
            else if (uint8_t(state.data[14]) == uint8_t(0x2d)) [[unlikely]]
                state.data += 14;
            else if (uint8_t(state.data[15]) == uint8_t(0x2d)) [[unlikely]]
                state.data += 15;
            else
            {
                state.data += 16;
                continue;
            }
        }
        else if (!(uint8_t(state.data[0]) == uint8_t(0x2d))) [[unlikely]]
        {
            state.data++;
            continue;
        }
        state.consumed = 0;
        state.node = NodeT::Loop8_1;
        return true;
    }
    state.consumed += unsigned(state.data - datastart);
    state.node = NodeT::Range10_0;
    return true;
}

inline bool xml::text11_0(StateT & state) const
{
    if(state.data < state.end)
    {
        if (uint8_t(0x2F) != uint8_t(state.data[0]))
        {
            state.node = NodeT::NoState;
            return false;
        } else {
            state.data++;
            state.node = NodeT::String11_1;
            return true;
        }
    }
    state.node = NodeT::Text11_0;
    return true;
}

void xml::string11_1(const char * data, unsigned len, uint64_t consumed)
{
    if (!consumed)
        xmlResult::tag.clear();
    if ((xmlResult::tag.length() + len) > 256)
        len = 256 - xmlResult::tag.length();
    xmlResult::tag.append(data, len);
}

inline bool xml::string11_1(StateT & state)
{
    const char * datastart = state.data;
    while(state.data < state.end) [[likely]]
    {
#if defined(__AVX2__)
        if(&state.data[32] <= state.end)
        {
            const __m256i d = _mm256_lddqu_si256((const __m256i *)state.data);
            __m256i m = _mm256_cmpeq_epi8(_mm256_set1_epi8(0x3e), d);
            uint32_t r = _mm256_movemask_epi8(m);
            if (r)
                state.data += __ctz32(r);
            else
            {
                state.data += 32;
                continue;
            }
        }
#elif defined(__SSE2__)
        if(&state.data[16] <= state.end)
        {
            const __m128i d = _mm_loadu_si128((const __m128i *)state.data);
            __m128i m = _mm_cmpeq_epi8(_mm_set1_epi8(0x3e), d);
            uint16_t r = _mm_movemask_epi8(m);
            if (r)
                state.data += __ctz32(r);
            else
            {
                state.data += 16;
                continue;
            }
        }
#else
        if(&state.data[16] <= state.end)
        {
            if (uint8_t(state.data[0]) == uint8_t(0x3e)) [[unlikely]]
                state.data += 0;
            else if (uint8_t(state.data[1]) == uint8_t(0x3e)) [[unlikely]]
                state.data += 1;
            else if (uint8_t(state.data[2]) == uint8_t(0x3e)) [[unlikely]]
                state.data += 2;
            else if (uint8_t(state.data[3]) == uint8_t(0x3e)) [[unlikely]]
                state.data += 3;
            else if (uint8_t(state.data[4]) == uint8_t(0x3e)) [[unlikely]]
                state.data += 4;
            else if (uint8_t(state.data[5]) == uint8_t(0x3e)) [[unlikely]]
                state.data += 5;
            else if (uint8_t(state.data[6]) == uint8_t(0x3e)) [[unlikely]]
                state.data += 6;
            else if (uint8_t(state.data[7]) == uint8_t(0x3e)) [[unlikely]]
                state.data += 7;
            else if (uint8_t(state.data[8]) == uint8_t(0x3e)) [[unlikely]]
                state.data += 8;
            else if (uint8_t(state.data[9]) == uint8_t(0x3e)) [[unlikely]]
                state.data += 9;
            else if (uint8_t(state.data[10]) == uint8_t(0x3e)) [[unlikely]]
                state.data += 10;
            else if (uint8_t(state.data[11]) == uint8_t(0x3e)) [[unlikely]]
                state.data += 11;
            else if (uint8_t(state.data[12]) == uint8_t(0x3e)) [[unlikely]]
                state.data += 12;
            else if (uint8_t(state.data[13]) == uint8_t(0x3e)) [[unlikely]]
                state.data += 13;
            else if (uint8_t(state.data[14]) == uint8_t(0x3e)) [[unlikely]]
                state.data += 14;
            else if (uint8_t(state.data[15]) == uint8_t(0x3e)) [[unlikely]]
                state.data += 15;
            else
            {
                state.data += 16;
                continue;
            }
        }
#endif
        else if (!(uint8_t(state.data[0]) == uint8_t(0x3e))) [[unlikely]]
        {
            state.data++;
            continue;
        }
        string11_1(datastart, unsigned(state.data - datastart), state.consumed);
        uint64_t total = state.consumed + unsigned(state.data - datastart);
        state.consumed = 0;
        if (total >= 1)
        {
            state.node = NodeT::Range11_2;
            return true;
        } else {
            state.node = NodeT::NoState;
            return false;
        }
    }
    if (datastart < state.data)
        string11_1(datastart, unsigned(state.data - datastart), state.consumed);
    state.consumed += unsigned(state.data - datastart);
    state.node = NodeT::String11_1;
    return true;
}

inline bool xml::range11_2(StateT & state) const
{
    const char * datastart = state.data;
    while(state.data < state.end)
    {
        if (uint8_t(state.data[0]) != uint8_t(0x3e)) [[unlikely]]
        {
            state.consumed += unsigned(state.data - datastart);
            state.node = (state.consumed >= 1) ? NodeT::Func11_3 : NodeT::NoState;
            bool ret = (state.node == NodeT::Func11_3);
            state.consumed = 0;
            return ret;
        }
        state.data++;
        state.node = NodeT::Func11_3;
        return true;
    }
    state.consumed += unsigned(state.data - datastart);
    state.node = NodeT::Range11_2;
    return true;
}

inline bool xml::func11_3()
{
     return opend--; 
    return true;
}
inline bool xml::func11_3(StateT & state)
{
    if (func11_3())
    {
        state.node = NodeT::Notify11_4;
        return true;
    }
    state.node = NodeT::NoState;
    return false;
}

inline bool xml::notify11_4(StateT & state)
{
    finishTag();
    state.node = NodeT::Ret11_5;
    return true;
}

inline bool xml::ret11_5(StateT & state) const
{
    state.node = state.rcount ? state.rstack[--state.rcount] : NodeT::NoState;
    return state.node != NodeT::NoState;
}

void xml::string12_0(const char * data, unsigned len, uint64_t consumed)
{
    if (!consumed)
        xmlResult::tag.clear();
    if ((xmlResult::tag.length() + len) > 256)
        len = 256 - xmlResult::tag.length();
    xmlResult::tag.append(data, len);
}

inline bool xml::string12_0(StateT & state)
{
    const static std::array<bool, 256> terminator = {
        false, false, false, false, false, false, false, false, false,  true, false, false, false, false, false, false, 
        false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, 
         true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, 
        false, false, false, false, false, false, false, false, false, false, false, false, false, false,  true, false, 
        false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, 
        false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, 
        false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, 
        false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, 
        false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, 
        false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, 
        false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, 
        false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, 
        false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, 
        false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, 
        false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, 
        false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false}; // ^[0x9][0x20][0x3e]
    const char * datastart = state.data;
    while(state.data < state.end) [[likely]]
    {
        if(&state.data[16] <= state.end)
        {
            if (terminator[uint8_t(state.data[0])]) [[unlikely]]
                state.data += 0;
            else if (terminator[uint8_t(state.data[1])]) [[unlikely]]
                state.data += 1;
            else if (terminator[uint8_t(state.data[2])]) [[unlikely]]
                state.data += 2;
            else if (terminator[uint8_t(state.data[3])]) [[unlikely]]
                state.data += 3;
            else if (terminator[uint8_t(state.data[4])]) [[unlikely]]
                state.data += 4;
            else if (terminator[uint8_t(state.data[5])]) [[unlikely]]
                state.data += 5;
            else if (terminator[uint8_t(state.data[6])]) [[unlikely]]
                state.data += 6;
            else if (terminator[uint8_t(state.data[7])]) [[unlikely]]
                state.data += 7;
            else if (terminator[uint8_t(state.data[8])]) [[unlikely]]
                state.data += 8;
            else if (terminator[uint8_t(state.data[9])]) [[unlikely]]
                state.data += 9;
            else if (terminator[uint8_t(state.data[10])]) [[unlikely]]
                state.data += 10;
            else if (terminator[uint8_t(state.data[11])]) [[unlikely]]
                state.data += 11;
            else if (terminator[uint8_t(state.data[12])]) [[unlikely]]
                state.data += 12;
            else if (terminator[uint8_t(state.data[13])]) [[unlikely]]
                state.data += 13;
            else if (terminator[uint8_t(state.data[14])]) [[unlikely]]
                state.data += 14;
            else if (terminator[uint8_t(state.data[15])]) [[unlikely]]
                state.data += 15;
            else
            {
                state.data += 16;
                continue;
            }
        }
        else if (!(terminator[uint8_t(state.data[0])])) [[unlikely]]
        {
            state.data++;
            continue;
        }
        string12_0(datastart, unsigned(state.data - datastart), state.consumed);
        uint64_t total = state.consumed + unsigned(state.data - datastart);
        state.consumed = 0;
        if (total >= 1)
        {
            state.node = NodeT::Func12_1;
            return true;
        } else {
            state.node = NodeT::NoState;
            return false;
        }
    }
    if (datastart < state.data)
        string12_0(datastart, unsigned(state.data - datastart), state.consumed);
    state.consumed += unsigned(state.data - datastart);
    state.node = NodeT::String12_0;
    return true;
}

inline bool xml::func12_1()
{
     opend++; 
    return true;
}
inline bool xml::func12_1(StateT & state)
{
    if (func12_1())
    {
        state.node = NodeT::Range12_2;
        return true;
    }
    state.node = NodeT::NoState;
    return false;
}

inline bool xml::range12_2(StateT & state) const
{
    const static std::array<bool, 256> terminator = {
         true,  true,  true,  true,  true,  true,  true,  true,  true, false,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
        false,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true}; // [0x9][0x20]
    const char * datastart = state.data;
    while(state.data < state.end) [[likely]]
    {
        if(&state.data[16] <= state.end)
        {
            if (terminator[uint8_t(state.data[0])]) [[unlikely]]
                state.data += 0;
            else if (terminator[uint8_t(state.data[1])]) [[unlikely]]
                state.data += 1;
            else if (terminator[uint8_t(state.data[2])]) [[unlikely]]
                state.data += 2;
            else if (terminator[uint8_t(state.data[3])]) [[unlikely]]
                state.data += 3;
            else if (terminator[uint8_t(state.data[4])]) [[unlikely]]
                state.data += 4;
            else if (terminator[uint8_t(state.data[5])]) [[unlikely]]
                state.data += 5;
            else if (terminator[uint8_t(state.data[6])]) [[unlikely]]
                state.data += 6;
            else if (terminator[uint8_t(state.data[7])]) [[unlikely]]
                state.data += 7;
            else if (terminator[uint8_t(state.data[8])]) [[unlikely]]
                state.data += 8;
            else if (terminator[uint8_t(state.data[9])]) [[unlikely]]
                state.data += 9;
            else if (terminator[uint8_t(state.data[10])]) [[unlikely]]
                state.data += 10;
            else if (terminator[uint8_t(state.data[11])]) [[unlikely]]
                state.data += 11;
            else if (terminator[uint8_t(state.data[12])]) [[unlikely]]
                state.data += 12;
            else if (terminator[uint8_t(state.data[13])]) [[unlikely]]
                state.data += 13;
            else if (terminator[uint8_t(state.data[14])]) [[unlikely]]
                state.data += 14;
            else if (terminator[uint8_t(state.data[15])]) [[unlikely]]
                state.data += 15;
            else
            {
                state.data += 16;
                continue;
            }
        }
        else if (!(terminator[uint8_t(state.data[0])])) [[unlikely]]
        {
            state.data++;
            continue;
        }
        state.consumed = 0;
        state.node = NodeT::Loop12_3;
        return true;
    }
    state.consumed += unsigned(state.data - datastart);
    state.node = NodeT::Range12_2;
    return true;
}

inline bool xml::loop12_3(StateT & state)
{
    if (state.data == state.end)
        return true;
    if (text13_0(state)) // case_1
        return true;
    if (range14_0(state)) // case_2
        return true;
    if (string15_0(state)) // case_3
        return true;
    state.node = NodeT::NoState;
    return true;
}

inline bool xml::text13_0(StateT & state) const
{
    if(state.data < state.end)
    {
        if (uint8_t(0x3E) != uint8_t(state.data[0]))
        {
            state.node = NodeT::NoState;
            return false;
        } else {
            state.data++;
            state.node = NodeT::Ret13_1;
            return true;
        }
    }
    state.node = NodeT::Text13_0;
    return true;
}

inline bool xml::ret13_1(StateT & state) const
{
    state.node = state.rcount ? state.rstack[--state.rcount] : NodeT::NoState;
    return state.node != NodeT::NoState;
}

inline bool xml::range14_0(StateT & state) const
{
    const static std::array<bool, 256> terminator = {
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, false, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, false, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true}; // [0x2f][0x3f]
    const char * datastart = state.data;
    while(state.data < state.end)
    {
        if (terminator[uint8_t(state.data[0])]) [[unlikely]]
        {
            state.consumed += unsigned(state.data - datastart);
            state.node = (state.consumed >= 1) ? NodeT::Text14_1 : NodeT::NoState;
            bool ret = (state.node == NodeT::Text14_1);
            state.consumed = 0;
            return ret;
        }
        state.data++;
        state.node = NodeT::Text14_1;
        return true;
    }
    state.consumed += unsigned(state.data - datastart);
    state.node = NodeT::Range14_0;
    return true;
}

inline bool xml::text14_1(StateT & state) const
{
    if(state.data < state.end)
    {
        if (uint8_t(0x3E) != uint8_t(state.data[0]))
        {
            state.node = NodeT::NoState;
            return false;
        } else {
            state.data++;
            state.node = NodeT::Func14_2;
            return true;
        }
    }
    state.node = NodeT::Text14_1;
    return true;
}

inline bool xml::func14_2()
{
     return opend--; 
    return true;
}
inline bool xml::func14_2(StateT & state)
{
    if (func14_2())
    {
        state.node = NodeT::Notify14_3;
        return true;
    }
    state.node = NodeT::NoState;
    return false;
}

inline bool xml::notify14_3(StateT & state)
{
    finishTag();
    state.node = NodeT::Ret14_4;
    return true;
}

inline bool xml::ret14_4(StateT & state) const
{
    state.node = state.rcount ? state.rstack[--state.rcount] : NodeT::NoState;
    return state.node != NodeT::NoState;
}

void xml::string15_0(const char * data, unsigned len, uint64_t consumed)
{
    if (!consumed)
        xmlResult::key.clear();
    if ((xmlResult::key.length() + len) > 256)
        len = 256 - xmlResult::key.length();
    xmlResult::key.append(data, len);
}

inline bool xml::string15_0(StateT & state)
{
    const static std::array<bool, 256> terminator = {
        false, false, false, false, false, false, false, false, false,  true, false, false, false, false, false, false, 
        false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, 
         true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, 
        false, false, false, false, false, false, false, false, false, false, false, false, false,  true, false, false, 
        false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, 
        false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, 
        false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, 
        false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, 
        false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, 
        false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, 
        false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, 
        false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, 
        false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, 
        false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, 
        false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, 
        false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false}; // ^[0x9][0x20][0x3d]
    const char * datastart = state.data;
    while(state.data < state.end) [[likely]]
    {
        if(&state.data[16] <= state.end)
        {
            if (terminator[uint8_t(state.data[0])]) [[unlikely]]
                state.data += 0;
            else if (terminator[uint8_t(state.data[1])]) [[unlikely]]
                state.data += 1;
            else if (terminator[uint8_t(state.data[2])]) [[unlikely]]
                state.data += 2;
            else if (terminator[uint8_t(state.data[3])]) [[unlikely]]
                state.data += 3;
            else if (terminator[uint8_t(state.data[4])]) [[unlikely]]
                state.data += 4;
            else if (terminator[uint8_t(state.data[5])]) [[unlikely]]
                state.data += 5;
            else if (terminator[uint8_t(state.data[6])]) [[unlikely]]
                state.data += 6;
            else if (terminator[uint8_t(state.data[7])]) [[unlikely]]
                state.data += 7;
            else if (terminator[uint8_t(state.data[8])]) [[unlikely]]
                state.data += 8;
            else if (terminator[uint8_t(state.data[9])]) [[unlikely]]
                state.data += 9;
            else if (terminator[uint8_t(state.data[10])]) [[unlikely]]
                state.data += 10;
            else if (terminator[uint8_t(state.data[11])]) [[unlikely]]
                state.data += 11;
            else if (terminator[uint8_t(state.data[12])]) [[unlikely]]
                state.data += 12;
            else if (terminator[uint8_t(state.data[13])]) [[unlikely]]
                state.data += 13;
            else if (terminator[uint8_t(state.data[14])]) [[unlikely]]
                state.data += 14;
            else if (terminator[uint8_t(state.data[15])]) [[unlikely]]
                state.data += 15;
            else
            {
                state.data += 16;
                continue;
            }
        }
        else if (!(terminator[uint8_t(state.data[0])])) [[unlikely]]
        {
            state.data++;
            continue;
        }
        string15_0(datastart, unsigned(state.data - datastart), state.consumed);
        uint64_t total = state.consumed + unsigned(state.data - datastart);
        state.consumed = 0;
        if (total >= 1)
        {
            state.node = NodeT::Range15_1;
            return true;
        } else {
            state.node = NodeT::NoState;
            return false;
        }
    }
    if (datastart < state.data)
        string15_0(datastart, unsigned(state.data - datastart), state.consumed);
    state.consumed += unsigned(state.data - datastart);
    state.node = NodeT::String15_0;
    return true;
}

inline bool xml::range15_1(StateT & state) const
{
    const static std::array<bool, 256> terminator = {
         true,  true,  true,  true,  true,  true,  true,  true,  true, false,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
        false,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true}; // [0x9][0x20]
    const char * datastart = state.data;
    while(state.data < state.end) [[likely]]
    {
        if(&state.data[16] <= state.end)
        {
            if (terminator[uint8_t(state.data[0])]) [[unlikely]]
                state.data += 0;
            else if (terminator[uint8_t(state.data[1])]) [[unlikely]]
                state.data += 1;
            else if (terminator[uint8_t(state.data[2])]) [[unlikely]]
                state.data += 2;
            else if (terminator[uint8_t(state.data[3])]) [[unlikely]]
                state.data += 3;
            else if (terminator[uint8_t(state.data[4])]) [[unlikely]]
                state.data += 4;
            else if (terminator[uint8_t(state.data[5])]) [[unlikely]]
                state.data += 5;
            else if (terminator[uint8_t(state.data[6])]) [[unlikely]]
                state.data += 6;
            else if (terminator[uint8_t(state.data[7])]) [[unlikely]]
                state.data += 7;
            else if (terminator[uint8_t(state.data[8])]) [[unlikely]]
                state.data += 8;
            else if (terminator[uint8_t(state.data[9])]) [[unlikely]]
                state.data += 9;
            else if (terminator[uint8_t(state.data[10])]) [[unlikely]]
                state.data += 10;
            else if (terminator[uint8_t(state.data[11])]) [[unlikely]]
                state.data += 11;
            else if (terminator[uint8_t(state.data[12])]) [[unlikely]]
                state.data += 12;
            else if (terminator[uint8_t(state.data[13])]) [[unlikely]]
                state.data += 13;
            else if (terminator[uint8_t(state.data[14])]) [[unlikely]]
                state.data += 14;
            else if (terminator[uint8_t(state.data[15])]) [[unlikely]]
                state.data += 15;
            else
            {
                state.data += 16;
                continue;
            }
        }
        else if (!(terminator[uint8_t(state.data[0])])) [[unlikely]]
        {
            state.data++;
            continue;
        }
        state.consumed = 0;
        state.node = NodeT::Text15_2;
        return true;
    }
    state.consumed += unsigned(state.data - datastart);
    state.node = NodeT::Range15_1;
    return true;
}

inline bool xml::text15_2(StateT & state) const
{
    if(state.data < state.end)
    {
        if (uint8_t(0x3D) != uint8_t(state.data[0]))
        {
            state.node = NodeT::NoState;
            return false;
        } else {
            state.data++;
            state.node = NodeT::Range15_3;
            return true;
        }
    }
    state.node = NodeT::Text15_2;
    return true;
}

inline bool xml::range15_3(StateT & state) const
{
    const static std::array<bool, 256> terminator = {
         true,  true,  true,  true,  true,  true,  true,  true,  true, false,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
        false,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true}; // [0x9][0x20]
    const char * datastart = state.data;
    while(state.data < state.end) [[likely]]
    {
        if(&state.data[16] <= state.end)
        {
            if (terminator[uint8_t(state.data[0])]) [[unlikely]]
                state.data += 0;
            else if (terminator[uint8_t(state.data[1])]) [[unlikely]]
                state.data += 1;
            else if (terminator[uint8_t(state.data[2])]) [[unlikely]]
                state.data += 2;
            else if (terminator[uint8_t(state.data[3])]) [[unlikely]]
                state.data += 3;
            else if (terminator[uint8_t(state.data[4])]) [[unlikely]]
                state.data += 4;
            else if (terminator[uint8_t(state.data[5])]) [[unlikely]]
                state.data += 5;
            else if (terminator[uint8_t(state.data[6])]) [[unlikely]]
                state.data += 6;
            else if (terminator[uint8_t(state.data[7])]) [[unlikely]]
                state.data += 7;
            else if (terminator[uint8_t(state.data[8])]) [[unlikely]]
                state.data += 8;
            else if (terminator[uint8_t(state.data[9])]) [[unlikely]]
                state.data += 9;
            else if (terminator[uint8_t(state.data[10])]) [[unlikely]]
                state.data += 10;
            else if (terminator[uint8_t(state.data[11])]) [[unlikely]]
                state.data += 11;
            else if (terminator[uint8_t(state.data[12])]) [[unlikely]]
                state.data += 12;
            else if (terminator[uint8_t(state.data[13])]) [[unlikely]]
                state.data += 13;
            else if (terminator[uint8_t(state.data[14])]) [[unlikely]]
                state.data += 14;
            else if (terminator[uint8_t(state.data[15])]) [[unlikely]]
                state.data += 15;
            else
            {
                state.data += 16;
                continue;
            }
        }
        else if (!(terminator[uint8_t(state.data[0])])) [[unlikely]]
        {
            state.data++;
            continue;
        }
        state.consumed = 0;
        state.node = NodeT::Range15_4;
        return true;
    }
    state.consumed += unsigned(state.data - datastart);
    state.node = NodeT::Range15_3;
    return true;
}

inline bool xml::range15_4(StateT & state) const
{
    const static std::array<bool, 256> terminator = {
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true, false,  true,  true,  true,  true, false,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true}; // [0x22][0x27]
    const char * datastart = state.data;
    while(state.data < state.end)
    {
        if (terminator[uint8_t(state.data[0])]) [[unlikely]]
        {
            state.consumed += unsigned(state.data - datastart);
            state.node = (state.consumed >= 1) ? NodeT::String15_5 : NodeT::NoState;
            bool ret = (state.node == NodeT::String15_5);
            state.consumed = 0;
            return ret;
        }
        state.data++;
        state.node = NodeT::String15_5;
        return true;
    }
    state.consumed += unsigned(state.data - datastart);
    state.node = NodeT::Range15_4;
    return true;
}

void xml::string15_5(const char * data, unsigned len, uint64_t consumed)
{
    if (!consumed)
        xmlResult::value.clear();
    if ((xmlResult::value.length() + len) > 256)
        len = 256 - xmlResult::value.length();
    xmlResult::value.append(data, len);
}

inline bool xml::string15_5(StateT & state)
{
    const static std::array<bool, 256> terminator = {
        false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, 
        false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, 
        false, false,  true, false, false, false, false,  true, false, false, false, false, false, false, false, false, 
        false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, 
        false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, 
        false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, 
        false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, 
        false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, 
        false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, 
        false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, 
        false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, 
        false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, 
        false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, 
        false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, 
        false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, 
        false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false}; // ^[0x22][0x27]
    const char * datastart = state.data;
    while(state.data < state.end) [[likely]]
    {
#if defined(__AVX2__)
        if(&state.data[32] <= state.end)
        {
            const __m256i d = _mm256_lddqu_si256((const __m256i *)state.data);
            __m256i m = _mm256_cmpeq_epi8(_mm256_set1_epi8(0x22), d);
            m = _mm256_or_si256(m, _mm256_cmpeq_epi8(_mm256_set1_epi8(0x27), d));
            uint32_t r = _mm256_movemask_epi8(m);
            if (r)
                state.data += __ctz32(r);
            else
            {
                state.data += 32;
                continue;
            }
        }
#elif defined(__SSE2__)
        if(&state.data[16] <= state.end)
        {
            const __m128i d = _mm_loadu_si128((const __m128i *)state.data);
            __m128i m = _mm_cmpeq_epi8(_mm_set1_epi8(0x22), d);
            m = _mm_or_si128(m, _mm_cmpeq_epi8(_mm_set1_epi8(0x27), d));
            uint16_t r = _mm_movemask_epi8(m);
            if (r)
                state.data += __ctz32(r);
            else
            {
                state.data += 16;
                continue;
            }
        }
#else
        if(&state.data[16] <= state.end)
        {
            if (terminator[uint8_t(state.data[0])]) [[unlikely]]
                state.data += 0;
            else if (terminator[uint8_t(state.data[1])]) [[unlikely]]
                state.data += 1;
            else if (terminator[uint8_t(state.data[2])]) [[unlikely]]
                state.data += 2;
            else if (terminator[uint8_t(state.data[3])]) [[unlikely]]
                state.data += 3;
            else if (terminator[uint8_t(state.data[4])]) [[unlikely]]
                state.data += 4;
            else if (terminator[uint8_t(state.data[5])]) [[unlikely]]
                state.data += 5;
            else if (terminator[uint8_t(state.data[6])]) [[unlikely]]
                state.data += 6;
            else if (terminator[uint8_t(state.data[7])]) [[unlikely]]
                state.data += 7;
            else if (terminator[uint8_t(state.data[8])]) [[unlikely]]
                state.data += 8;
            else if (terminator[uint8_t(state.data[9])]) [[unlikely]]
                state.data += 9;
            else if (terminator[uint8_t(state.data[10])]) [[unlikely]]
                state.data += 10;
            else if (terminator[uint8_t(state.data[11])]) [[unlikely]]
                state.data += 11;
            else if (terminator[uint8_t(state.data[12])]) [[unlikely]]
                state.data += 12;
            else if (terminator[uint8_t(state.data[13])]) [[unlikely]]
                state.data += 13;
            else if (terminator[uint8_t(state.data[14])]) [[unlikely]]
                state.data += 14;
            else if (terminator[uint8_t(state.data[15])]) [[unlikely]]
                state.data += 15;
            else
            {
                state.data += 16;
                continue;
            }
        }
#endif
        else if (!(terminator[uint8_t(state.data[0])])) [[unlikely]]
        {
            state.data++;
            continue;
        }
        string15_5(datastart, unsigned(state.data - datastart), state.consumed);
        state.consumed = 0;
        state.node = NodeT::Range15_6;
        return true;
    }
    if (datastart < state.data)
        string15_5(datastart, unsigned(state.data - datastart), state.consumed);
    state.consumed += unsigned(state.data - datastart);
    state.node = NodeT::String15_5;
    return true;
}

inline bool xml::range15_6(StateT & state) const
{
    const static std::array<bool, 256> terminator = {
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true, false,  true,  true,  true,  true, false,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true}; // [0x22][0x27]
    const char * datastart = state.data;
    while(state.data < state.end)
    {
        if (terminator[uint8_t(state.data[0])]) [[unlikely]]
        {
            state.consumed += unsigned(state.data - datastart);
            state.node = (state.consumed >= 1) ? NodeT::Notify15_7 : NodeT::NoState;
            bool ret = (state.node == NodeT::Notify15_7);
            state.consumed = 0;
            return ret;
        }
        state.data++;
        state.node = NodeT::Notify15_7;
        return true;
    }
    state.consumed += unsigned(state.data - datastart);
    state.node = NodeT::Range15_6;
    return true;
}

inline bool xml::notify15_7(StateT & state)
{
    getAttribute();
    state.node = NodeT::Range15_8;
    return true;
}

inline bool xml::range15_8(StateT & state) const
{
    const static std::array<bool, 256> terminator = {
         true,  true,  true,  true,  true,  true,  true,  true,  true, false,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
        false,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true}; // [0x9][0x20]
    const char * datastart = state.data;
    while(state.data < state.end) [[likely]]
    {
        if(&state.data[16] <= state.end)
        {
            if (terminator[uint8_t(state.data[0])]) [[unlikely]]
                state.data += 0;
            else if (terminator[uint8_t(state.data[1])]) [[unlikely]]
                state.data += 1;
            else if (terminator[uint8_t(state.data[2])]) [[unlikely]]
                state.data += 2;
            else if (terminator[uint8_t(state.data[3])]) [[unlikely]]
                state.data += 3;
            else if (terminator[uint8_t(state.data[4])]) [[unlikely]]
                state.data += 4;
            else if (terminator[uint8_t(state.data[5])]) [[unlikely]]
                state.data += 5;
            else if (terminator[uint8_t(state.data[6])]) [[unlikely]]
                state.data += 6;
            else if (terminator[uint8_t(state.data[7])]) [[unlikely]]
                state.data += 7;
            else if (terminator[uint8_t(state.data[8])]) [[unlikely]]
                state.data += 8;
            else if (terminator[uint8_t(state.data[9])]) [[unlikely]]
                state.data += 9;
            else if (terminator[uint8_t(state.data[10])]) [[unlikely]]
                state.data += 10;
            else if (terminator[uint8_t(state.data[11])]) [[unlikely]]
                state.data += 11;
            else if (terminator[uint8_t(state.data[12])]) [[unlikely]]
                state.data += 12;
            else if (terminator[uint8_t(state.data[13])]) [[unlikely]]
                state.data += 13;
            else if (terminator[uint8_t(state.data[14])]) [[unlikely]]
                state.data += 14;
            else if (terminator[uint8_t(state.data[15])]) [[unlikely]]
                state.data += 15;
            else
            {
                state.data += 16;
                continue;
            }
        }
        else if (!(terminator[uint8_t(state.data[0])])) [[unlikely]]
        {
            state.data++;
            continue;
        }
        state.consumed = 0;
        state.node = NodeT::Loop12_3;
        return true;
    }
    state.consumed += unsigned(state.data - datastart);
    state.node = NodeT::Range15_8;
    return true;
}

inline bool xml::loop17_0(StateT & state)
{
    return uint17_0(state);
}

void xml::uint17_0(const char * data, unsigned len, uint64_t consumed)
{
    if (!consumed)
        xmlResult::opend = 0;
    for(const char * end = &data[len]; data < end; data++)
        xmlResult::opend = xmlResult::opend*10 + *data - '0';
}

inline bool xml::uint17_0(StateT & state)
{
    const static std::array<bool, 256> terminator = {
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
        false, false, false, false, false, false, false, false, false, false,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true}; // [0-9]
    const char * datastart = state.data;
    while(state.data < state.end) [[likely]]
    {
        if(&state.data[16] <= state.end)
        {
            if (terminator[uint8_t(state.data[0])]) [[unlikely]]
                state.data += 0;
            else if (terminator[uint8_t(state.data[1])]) [[unlikely]]
                state.data += 1;
            else if (terminator[uint8_t(state.data[2])]) [[unlikely]]
                state.data += 2;
            else if (terminator[uint8_t(state.data[3])]) [[unlikely]]
                state.data += 3;
            else if (terminator[uint8_t(state.data[4])]) [[unlikely]]
                state.data += 4;
            else if (terminator[uint8_t(state.data[5])]) [[unlikely]]
                state.data += 5;
            else if (terminator[uint8_t(state.data[6])]) [[unlikely]]
                state.data += 6;
            else if (terminator[uint8_t(state.data[7])]) [[unlikely]]
                state.data += 7;
            else if (terminator[uint8_t(state.data[8])]) [[unlikely]]
                state.data += 8;
            else if (terminator[uint8_t(state.data[9])]) [[unlikely]]
                state.data += 9;
            else if (terminator[uint8_t(state.data[10])]) [[unlikely]]
                state.data += 10;
            else if (terminator[uint8_t(state.data[11])]) [[unlikely]]
                state.data += 11;
            else if (terminator[uint8_t(state.data[12])]) [[unlikely]]
                state.data += 12;
            else if (terminator[uint8_t(state.data[13])]) [[unlikely]]
                state.data += 13;
            else if (terminator[uint8_t(state.data[14])]) [[unlikely]]
                state.data += 14;
            else if (terminator[uint8_t(state.data[15])]) [[unlikely]]
                state.data += 15;
            else
            {
                state.data += 16;
                continue;
            }
        }
        else if (!(terminator[uint8_t(state.data[0])])) [[unlikely]]
        {
            state.data++;
            continue;
        }
        uint17_0(datastart, unsigned(state.data - datastart), state.consumed);
        uint64_t total = state.consumed + unsigned(state.data - datastart);
        state.consumed = 0;
        if (total >= 1)
        {
            state.node = NodeT::Loop17_0;
            return true;
        } else {
            state.node = NodeT::NoState;
            return false;
        }
    }
    if (datastart < state.data)
        uint17_0(datastart, unsigned(state.data - datastart), state.consumed);
    state.consumed += unsigned(state.data - datastart);
    state.node = NodeT::Uint17_0;
    return true;
}

void xml::reset()
{
    xmlResult::key.clear();
    xmlResult::opend = 0;
    xmlResult::tag.clear();
    xmlResult::value.clear();
    xml::mstate = xml::StateT();
}

const char * xml::StateT::name() const
{
    switch(node)
    {
        case NodeT::Loop1_0: return "Loop1_0";
        case NodeT::Label1_0: return "Label1_0";
        case NodeT::Loop1_1: return "Loop1_1";
        case NodeT::Range2_0: return "Range2_0";
        case NodeT::Range3_0: return "Range3_0";
        case NodeT::Text4_0: return "Text4_0";
        case NodeT::Call4_1: return "Call4_1";
        case NodeT::Range5_0: return "Range5_0";
        case NodeT::Loop7_0: return "Loop7_0";
        case NodeT::Label7_0: return "Label7_0";
        case NodeT::Loop7_1: return "Loop7_1";
        case NodeT::Text8_0: return "Text8_0";
        case NodeT::Loop8_1: return "Loop8_1";
        case NodeT::Text9_0: return "Text9_0";
        case NodeT::Ret9_1: return "Ret9_1";
        case NodeT::Range10_0: return "Range10_0";
        case NodeT::Text11_0: return "Text11_0";
        case NodeT::String11_1: return "String11_1";
        case NodeT::Range11_2: return "Range11_2";
        case NodeT::Func11_3: return "Func11_3";
        case NodeT::Notify11_4: return "Notify11_4";
        case NodeT::Ret11_5: return "Ret11_5";
        case NodeT::String12_0: return "String12_0";
        case NodeT::Func12_1: return "Func12_1";
        case NodeT::Range12_2: return "Range12_2";
        case NodeT::Loop12_3: return "Loop12_3";
        case NodeT::Text13_0: return "Text13_0";
        case NodeT::Ret13_1: return "Ret13_1";
        case NodeT::Range14_0: return "Range14_0";
        case NodeT::Text14_1: return "Text14_1";
        case NodeT::Func14_2: return "Func14_2";
        case NodeT::Notify14_3: return "Notify14_3";
        case NodeT::Ret14_4: return "Ret14_4";
        case NodeT::String15_0: return "String15_0";
        case NodeT::Range15_1: return "Range15_1";
        case NodeT::Text15_2: return "Text15_2";
        case NodeT::Range15_3: return "Range15_3";
        case NodeT::Range15_4: return "Range15_4";
        case NodeT::String15_5: return "String15_5";
        case NodeT::Range15_6: return "Range15_6";
        case NodeT::Notify15_7: return "Notify15_7";
        case NodeT::Range15_8: return "Range15_8";
        case NodeT::Loop17_0: return "Loop17_0";
        case NodeT::Uint17_0: return "Uint17_0";
        case NodeT::NoState: return "NoState";
        default: return "unknown";
    };
}

