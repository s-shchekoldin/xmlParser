// ==============================================================
// Date: 2025-09-04 06:13:37 GMT
// Generated using vProto(2025.09.04)        https://www.cgen.dev
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

inline void xml::parse(state_t & state)
{
    while(true)
    {
#ifdef DEBUG_MODE
        printf("State%s: %s data: [%x, %x, %x, %x, %x]=%.*s\n", &state == &mainState ? "" : "*", state.name(),
            uint8_t(&state.data[0] < state.end ? state.data[0] : 0),
            uint8_t(&state.data[1] < state.end ? state.data[1] : 0),
            uint8_t(&state.data[2] < state.end ? state.data[2] : 0),
            uint8_t(&state.data[3] < state.end ? state.data[3] : 0),
            uint8_t(&state.data[4] < state.end ? state.data[4] : 0),
            10, state.data);
#endif
        node_t n = state.node;
        const char * d = state.data;
        switch(state.node)
        {
            case node_t::LOOP_1_0: loop_1_0(state); break;
            case node_t::LABEL_1_0: if (!label_1_0(state) || state.node != node_t::LOOP_1_1) break; [[fallthrough]];
            case node_t::LOOP_1_1: loop_1_1(state); break;
            case node_t::RANGE_2_0: range_2_0(state); break;
            case node_t::RANGE_3_0: range_3_0(state); break;
            case node_t::TEXT_4_0: if (!text_4_0(state) || state.node != node_t::GOTO_4_1) break; [[fallthrough]];
            case node_t::GOTO_4_1: goto_4_1(state); break;
            case node_t::RANGE_5_0: range_5_0(state); break;
            case node_t::LOOP_7_0: loop_7_0(state); break;
            case node_t::LABEL_7_0: if (!label_7_0(state) || state.node != node_t::LOOP_7_1) break; [[fallthrough]];
            case node_t::LOOP_7_1: loop_7_1(state); break;
            case node_t::TEXT_8_0: if (!text_8_0(state, false) || state.node != node_t::LOOP_8_1) break; [[fallthrough]];
            case node_t::LOOP_8_1: loop_8_1(state); break;
            case node_t::TEXT_9_0: if (!text_9_0(state, false) || state.node != node_t::RET_9_1) break; [[fallthrough]];
            case node_t::RET_9_1: ret_9_1(state); break;
            case node_t::RANGE_10_0: range_10_0(state); break;
            case node_t::TEXT_11_0: if (!text_11_0(state) || state.node != node_t::STRING_11_1) break; [[fallthrough]];
            case node_t::STRING_11_1: if (!string_11_1(state) || state.node != node_t::RANGE_11_2) break; [[fallthrough]];
            case node_t::RANGE_11_2: if (!range_11_2(state) || state.node != node_t::FUNC_11_3) break; [[fallthrough]];
            case node_t::FUNC_11_3: if (!func_11_3(state) || state.node != node_t::NOTIFY_11_4) break; [[fallthrough]];
            case node_t::NOTIFY_11_4: if (!notify_11_4(state) || state.node != node_t::RET_11_5) break; [[fallthrough]];
            case node_t::RET_11_5: ret_11_5(state); break;
            case node_t::STRING_12_0: if (!string_12_0(state) || state.node != node_t::FUNC_12_1) break; [[fallthrough]];
            case node_t::FUNC_12_1: if (!func_12_1(state) || state.node != node_t::RANGE_12_2) break; [[fallthrough]];
            case node_t::RANGE_12_2: if (!range_12_2(state) || state.node != node_t::LOOP_12_3) break; [[fallthrough]];
            case node_t::LOOP_12_3: loop_12_3(state); break;
            case node_t::TEXT_13_0: if (!text_13_0(state) || state.node != node_t::RET_13_1) break; [[fallthrough]];
            case node_t::RET_13_1: ret_13_1(state); break;
            case node_t::RANGE_14_0: if (!range_14_0(state) || state.node != node_t::TEXT_14_1) break; [[fallthrough]];
            case node_t::TEXT_14_1: if (!text_14_1(state) || state.node != node_t::FUNC_14_2) break; [[fallthrough]];
            case node_t::FUNC_14_2: if (!func_14_2(state) || state.node != node_t::NOTIFY_14_3) break; [[fallthrough]];
            case node_t::NOTIFY_14_3: if (!notify_14_3(state) || state.node != node_t::RET_14_4) break; [[fallthrough]];
            case node_t::RET_14_4: ret_14_4(state); break;
            case node_t::STRING_15_0: if (!string_15_0(state) || state.node != node_t::RANGE_15_1) break; [[fallthrough]];
            case node_t::RANGE_15_1: if (!range_15_1(state) || state.node != node_t::TEXT_15_2) break; [[fallthrough]];
            case node_t::TEXT_15_2: if (!text_15_2(state) || state.node != node_t::RANGE_15_3) break; [[fallthrough]];
            case node_t::RANGE_15_3: if (!range_15_3(state) || state.node != node_t::RANGE_15_4) break; [[fallthrough]];
            case node_t::RANGE_15_4: if (!range_15_4(state) || state.node != node_t::STRING_15_5) break; [[fallthrough]];
            case node_t::STRING_15_5: if (!string_15_5(state) || state.node != node_t::RANGE_15_6) break; [[fallthrough]];
            case node_t::RANGE_15_6: if (!range_15_6(state) || state.node != node_t::NOTIFY_15_7) break; [[fallthrough]];
            case node_t::NOTIFY_15_7: if (!notify_15_7(state) || state.node != node_t::RANGE_15_8) break; [[fallthrough]];
            case node_t::RANGE_15_8: range_15_8(state); break;
            case node_t::LOOP_17_0: loop_17_0(state); break;
            case node_t::UINT_17_0: uint_17_0(state); break;
            case node_t::NO_STATE:
            default: return;
        }; // switch
        if (d == state.data && n == state.node) [[unlikely]]
            break;
    }
}

bool xml::parse(const char * data, unsigned len)
{
    mainState.data = data;
    mainState.end = &data[len];
    parse(mainState);
    return mainState.node != node_t::NO_STATE;
}

inline bool xml::loop_1_0(state_t & state)
{
    return label_1_0(state);
}

inline bool xml::label_1_0(state_t & state)
{
    state.node = node_t::LOOP_1_1;
    return true;
}

inline bool xml::loop_1_1(state_t & state)
{
    if (state.data == state.end)
        return true;
    if (range_2_0(state)) // case_1
        return true;
    if (range_3_0(state)) // case_2
        return true;
    if (text_4_0(state)) // case_3
        return true;
    if (range_5_0(state)) // case_4
        return true;
    state.node = node_t::NO_STATE;
    return true;
}

inline bool xml::range_2_0(state_t & state)
{
    const static bool exitSym[256] = {
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
    const char * beginData = state.data;
    while(state.data < state.end) [[likely]]
    {
        if(&state.data[16] <= state.end)
        {
            if (exitSym[uint8_t(state.data[0])]) [[unlikely]]
                state.data += 0;
            else if (exitSym[uint8_t(state.data[1])]) [[unlikely]]
                state.data += 1;
            else if (exitSym[uint8_t(state.data[2])]) [[unlikely]]
                state.data += 2;
            else if (exitSym[uint8_t(state.data[3])]) [[unlikely]]
                state.data += 3;
            else if (exitSym[uint8_t(state.data[4])]) [[unlikely]]
                state.data += 4;
            else if (exitSym[uint8_t(state.data[5])]) [[unlikely]]
                state.data += 5;
            else if (exitSym[uint8_t(state.data[6])]) [[unlikely]]
                state.data += 6;
            else if (exitSym[uint8_t(state.data[7])]) [[unlikely]]
                state.data += 7;
            else if (exitSym[uint8_t(state.data[8])]) [[unlikely]]
                state.data += 8;
            else if (exitSym[uint8_t(state.data[9])]) [[unlikely]]
                state.data += 9;
            else if (exitSym[uint8_t(state.data[10])]) [[unlikely]]
                state.data += 10;
            else if (exitSym[uint8_t(state.data[11])]) [[unlikely]]
                state.data += 11;
            else if (exitSym[uint8_t(state.data[12])]) [[unlikely]]
                state.data += 12;
            else if (exitSym[uint8_t(state.data[13])]) [[unlikely]]
                state.data += 13;
            else if (exitSym[uint8_t(state.data[14])]) [[unlikely]]
                state.data += 14;
            else if (exitSym[uint8_t(state.data[15])]) [[unlikely]]
                state.data += 15;
            else
            {
                state.data += 16;
                continue;
            }
        }
        else if (!(exitSym[uint8_t(state.data[0])])) [[unlikely]]
        {
            state.data++;
            continue;
        }
        uint64_t totalConsumed = state.consumed + unsigned(state.data - beginData);
        state.consumed = 0;
        if (totalConsumed >= 1)
        {
            state.node = node_t::LOOP_1_1;
            return true;
        } else {
            state.node = node_t::NO_STATE;
            return false;
        }
    }
    state.consumed += unsigned(state.data - beginData);
    state.node = node_t::RANGE_2_0;
    return true;
}

inline bool xml::range_3_0(state_t & state)
{
    const static bool exitSym[256] = {
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
    const char * beginData = state.data;
    while(state.data < state.end) [[likely]]
    {
        if(&state.data[16] <= state.end)
        {
            if (exitSym[uint8_t(state.data[0])]) [[unlikely]]
                state.data += 0;
            else if (exitSym[uint8_t(state.data[1])]) [[unlikely]]
                state.data += 1;
            else if (exitSym[uint8_t(state.data[2])]) [[unlikely]]
                state.data += 2;
            else if (exitSym[uint8_t(state.data[3])]) [[unlikely]]
                state.data += 3;
            else if (exitSym[uint8_t(state.data[4])]) [[unlikely]]
                state.data += 4;
            else if (exitSym[uint8_t(state.data[5])]) [[unlikely]]
                state.data += 5;
            else if (exitSym[uint8_t(state.data[6])]) [[unlikely]]
                state.data += 6;
            else if (exitSym[uint8_t(state.data[7])]) [[unlikely]]
                state.data += 7;
            else if (exitSym[uint8_t(state.data[8])]) [[unlikely]]
                state.data += 8;
            else if (exitSym[uint8_t(state.data[9])]) [[unlikely]]
                state.data += 9;
            else if (exitSym[uint8_t(state.data[10])]) [[unlikely]]
                state.data += 10;
            else if (exitSym[uint8_t(state.data[11])]) [[unlikely]]
                state.data += 11;
            else if (exitSym[uint8_t(state.data[12])]) [[unlikely]]
                state.data += 12;
            else if (exitSym[uint8_t(state.data[13])]) [[unlikely]]
                state.data += 13;
            else if (exitSym[uint8_t(state.data[14])]) [[unlikely]]
                state.data += 14;
            else if (exitSym[uint8_t(state.data[15])]) [[unlikely]]
                state.data += 15;
            else
            {
                state.data += 16;
                continue;
            }
        }
        else if (!(exitSym[uint8_t(state.data[0])])) [[unlikely]]
        {
            state.data++;
            continue;
        }
        uint64_t totalConsumed = state.consumed + unsigned(state.data - beginData);
        state.consumed = 0;
        if (totalConsumed >= 1)
        {
            state.node = node_t::LOOP_1_1;
            return true;
        } else {
            state.node = node_t::NO_STATE;
            return false;
        }
    }
    state.consumed += unsigned(state.data - beginData);
    state.node = node_t::RANGE_3_0;
    return true;
}

inline bool xml::text_4_0(state_t & state)
{
    if(state.data < state.end)
    {
        if (uint8_t(0x3C) != uint8_t(state.data[0]))
        {
            state.node = node_t::NO_STATE;
            return false;
        } else {
            state.data++;
            state.node = node_t::GOTO_4_1;
            return true;
        }
    }
    state.node = node_t::TEXT_4_0;
    return true;
}

inline bool xml::goto_4_1(state_t & state)
{
    state.node = node_t::LABEL_7_0;
    if (state.retStackCount < sizeof(state.retStack)/sizeof(state.retStack[0]))
        state.retStack[state.retStackCount++] = node_t::LOOP_1_1;
    else
    {
        for(unsigned i = 1; i < sizeof(state.retStack)/sizeof(state.retStack[0]); i++)
            state.retStack[i - 1] = state.retStack[i];
        state.retStack[sizeof(state.retStack)/sizeof(state.retStack[0]) - 1] = node_t::LOOP_1_1;
    }
    return true;
}

inline bool xml::range_5_0(state_t & state)
{
    const char * beginData = state.data;
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
        xmlResult::payload(beginData, unsigned(state.data - beginData), !state.consumed, true);
        uint64_t totalConsumed = state.consumed + unsigned(state.data - beginData);
        state.consumed = 0;
        if (totalConsumed >= 1)
        {
            state.node = node_t::LOOP_1_1;
            return true;
        } else {
            state.node = node_t::NO_STATE;
            return false;
        }
    }
    if (beginData < state.data)
        xmlResult::payload(beginData, unsigned(state.data - beginData), !state.consumed, false);
    state.consumed += unsigned(state.data - beginData);
    state.node = node_t::RANGE_5_0;
    return true;
}

inline bool xml::loop_7_0(state_t & state)
{
    return label_7_0(state);
}

inline bool xml::label_7_0(state_t & state)
{
    state.node = node_t::LOOP_7_1;
    return true;
}

inline bool xml::loop_7_1(state_t & state)
{
    if (state.data == state.end)
        return true;
    if (text_8_0(state, true)) // case_1
        return true;
    if (text_11_0(state)) // case_2
        return true;
    if (string_12_0(state)) // case_3
        return true;
    state.node = node_t::NO_STATE;
    return true;
}

inline bool xml::text_8_0(state_t & state, bool isCaseCall)
{
    const static uint8_t text[] = { 0x21, 0x2d, 0x2d}; // !--
    for(; state.data < state.end; state.data++)
    {
        if (text[state.consumed] != uint8_t(state.data[0]))
        {
            state.node = node_t::NO_STATE;
            bool ret = isCaseCall && state.consumed;
            state.consumed = 0;
            return ret;
        }
        else if (++state.consumed >= sizeof(text))
        {
            state.data++;
            state.consumed = 0;
            state.node = node_t::LOOP_8_1;
            return true;
        }
    }
    state.node = node_t::TEXT_8_0;
    return true;
}

inline bool xml::loop_8_1(state_t & state)
{
    return text_9_0(state, false);
}

inline bool xml::text_9_0(state_t & state, bool isCaseCall)
{
    const static uint8_t text[] = { 0x2d, 0x2d, 0x3e}; // -->
    for(; state.data < state.end; state.data++)
    {
        if (text[state.consumed] != uint8_t(state.data[0]))
        {
            state.node = node_t::RANGE_10_0;
            bool ret = isCaseCall && state.consumed;
            state.consumed = 0;
            return ret;
        }
        else if (++state.consumed >= sizeof(text))
        {
            state.data++;
            state.consumed = 0;
            state.node = node_t::RET_9_1;
            return true;
        }
    }
    state.node = node_t::TEXT_9_0;
    return true;
}

inline bool xml::ret_9_1(state_t & state)
{
    state.node = state.retStackCount ? state.retStack[--state.retStackCount] : node_t::NO_STATE;
    return state.node != node_t::NO_STATE;
}

inline bool xml::range_10_0(state_t & state)
{
    const char * beginData = state.data;
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
        state.node = node_t::LOOP_8_1;
        return true;
    }
    state.consumed += unsigned(state.data - beginData);
    state.node = node_t::RANGE_10_0;
    return true;
}

inline bool xml::text_11_0(state_t & state)
{
    if(state.data < state.end)
    {
        if (uint8_t(0x2F) != uint8_t(state.data[0]))
        {
            state.node = node_t::NO_STATE;
            return false;
        } else {
            state.data++;
            state.node = node_t::STRING_11_1;
            return true;
        }
    }
    state.node = node_t::TEXT_11_0;
    return true;
}

void xml::_string_11_1(const char * data, unsigned len, uint64_t consumed)
{
    if (!consumed)
        xmlResult::tag.clear();
    if ((xmlResult::tag.length() + len) > 256)
        len = 256 - xmlResult::tag.length();
    xmlResult::tag.append(data, len);
}

inline bool xml::string_11_1(state_t & state)
{
    const char * beginData = state.data;
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
        _string_11_1(beginData, unsigned(state.data - beginData), state.consumed);
        uint64_t totalConsumed = state.consumed + unsigned(state.data - beginData);
        state.consumed = 0;
        if (totalConsumed >= 1)
        {
            state.node = node_t::RANGE_11_2;
            return true;
        } else {
            state.node = node_t::NO_STATE;
            return false;
        }
    }
    if (beginData < state.data)
        _string_11_1(beginData, unsigned(state.data - beginData), state.consumed);
    state.consumed += unsigned(state.data - beginData);
    state.node = node_t::STRING_11_1;
    return true;
}

inline bool xml::range_11_2(state_t & state)
{
    const char * beginData = state.data;
    while(state.data < state.end)
    {
        if (uint8_t(state.data[0]) != uint8_t(0x3e)) [[unlikely]]
        {
            state.consumed += unsigned(state.data - beginData);
            state.node = (state.consumed >= 1) ? node_t::FUNC_11_3 : node_t::NO_STATE;
            bool ret = (state.node == node_t::FUNC_11_3);
            state.consumed = 0;
            return ret;
        }
        state.data++;
        state.node = node_t::FUNC_11_3;
        return true;
    }
    state.consumed += unsigned(state.data - beginData);
    state.node = node_t::RANGE_11_2;
    return true;
}

inline bool xml::_func_11_3()
{
     return opend--; 
    return true;
}
inline bool xml::func_11_3(state_t & state)
{
    bool ret = _func_11_3();
    state.node = ret ? node_t::NOTIFY_11_4 : node_t::NO_STATE;
    return ret;
}

inline bool xml::notify_11_4(state_t & state)
{
    finishTag();
    state.node = node_t::RET_11_5;
    return true;
}

inline bool xml::ret_11_5(state_t & state)
{
    state.node = state.retStackCount ? state.retStack[--state.retStackCount] : node_t::NO_STATE;
    return state.node != node_t::NO_STATE;
}

void xml::_string_12_0(const char * data, unsigned len, uint64_t consumed)
{
    if (!consumed)
        xmlResult::tag.clear();
    if ((xmlResult::tag.length() + len) > 256)
        len = 256 - xmlResult::tag.length();
    xmlResult::tag.append(data, len);
}

inline bool xml::string_12_0(state_t & state)
{
    const static bool exitSym[256] = {
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
    const char * beginData = state.data;
    while(state.data < state.end) [[likely]]
    {
        if(&state.data[16] <= state.end)
        {
            if (exitSym[uint8_t(state.data[0])]) [[unlikely]]
                state.data += 0;
            else if (exitSym[uint8_t(state.data[1])]) [[unlikely]]
                state.data += 1;
            else if (exitSym[uint8_t(state.data[2])]) [[unlikely]]
                state.data += 2;
            else if (exitSym[uint8_t(state.data[3])]) [[unlikely]]
                state.data += 3;
            else if (exitSym[uint8_t(state.data[4])]) [[unlikely]]
                state.data += 4;
            else if (exitSym[uint8_t(state.data[5])]) [[unlikely]]
                state.data += 5;
            else if (exitSym[uint8_t(state.data[6])]) [[unlikely]]
                state.data += 6;
            else if (exitSym[uint8_t(state.data[7])]) [[unlikely]]
                state.data += 7;
            else if (exitSym[uint8_t(state.data[8])]) [[unlikely]]
                state.data += 8;
            else if (exitSym[uint8_t(state.data[9])]) [[unlikely]]
                state.data += 9;
            else if (exitSym[uint8_t(state.data[10])]) [[unlikely]]
                state.data += 10;
            else if (exitSym[uint8_t(state.data[11])]) [[unlikely]]
                state.data += 11;
            else if (exitSym[uint8_t(state.data[12])]) [[unlikely]]
                state.data += 12;
            else if (exitSym[uint8_t(state.data[13])]) [[unlikely]]
                state.data += 13;
            else if (exitSym[uint8_t(state.data[14])]) [[unlikely]]
                state.data += 14;
            else if (exitSym[uint8_t(state.data[15])]) [[unlikely]]
                state.data += 15;
            else
            {
                state.data += 16;
                continue;
            }
        }
        else if (!(exitSym[uint8_t(state.data[0])])) [[unlikely]]
        {
            state.data++;
            continue;
        }
        _string_12_0(beginData, unsigned(state.data - beginData), state.consumed);
        uint64_t totalConsumed = state.consumed + unsigned(state.data - beginData);
        state.consumed = 0;
        if (totalConsumed >= 1)
        {
            state.node = node_t::FUNC_12_1;
            return true;
        } else {
            state.node = node_t::NO_STATE;
            return false;
        }
    }
    if (beginData < state.data)
        _string_12_0(beginData, unsigned(state.data - beginData), state.consumed);
    state.consumed += unsigned(state.data - beginData);
    state.node = node_t::STRING_12_0;
    return true;
}

inline bool xml::_func_12_1()
{
     opend++; 
    return true;
}
inline bool xml::func_12_1(state_t & state)
{
    bool ret = _func_12_1();
    state.node = ret ? node_t::RANGE_12_2 : node_t::NO_STATE;
    return ret;
}

inline bool xml::range_12_2(state_t & state)
{
    const static bool exitSym[256] = {
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
    const char * beginData = state.data;
    while(state.data < state.end) [[likely]]
    {
        if(&state.data[16] <= state.end)
        {
            if (exitSym[uint8_t(state.data[0])]) [[unlikely]]
                state.data += 0;
            else if (exitSym[uint8_t(state.data[1])]) [[unlikely]]
                state.data += 1;
            else if (exitSym[uint8_t(state.data[2])]) [[unlikely]]
                state.data += 2;
            else if (exitSym[uint8_t(state.data[3])]) [[unlikely]]
                state.data += 3;
            else if (exitSym[uint8_t(state.data[4])]) [[unlikely]]
                state.data += 4;
            else if (exitSym[uint8_t(state.data[5])]) [[unlikely]]
                state.data += 5;
            else if (exitSym[uint8_t(state.data[6])]) [[unlikely]]
                state.data += 6;
            else if (exitSym[uint8_t(state.data[7])]) [[unlikely]]
                state.data += 7;
            else if (exitSym[uint8_t(state.data[8])]) [[unlikely]]
                state.data += 8;
            else if (exitSym[uint8_t(state.data[9])]) [[unlikely]]
                state.data += 9;
            else if (exitSym[uint8_t(state.data[10])]) [[unlikely]]
                state.data += 10;
            else if (exitSym[uint8_t(state.data[11])]) [[unlikely]]
                state.data += 11;
            else if (exitSym[uint8_t(state.data[12])]) [[unlikely]]
                state.data += 12;
            else if (exitSym[uint8_t(state.data[13])]) [[unlikely]]
                state.data += 13;
            else if (exitSym[uint8_t(state.data[14])]) [[unlikely]]
                state.data += 14;
            else if (exitSym[uint8_t(state.data[15])]) [[unlikely]]
                state.data += 15;
            else
            {
                state.data += 16;
                continue;
            }
        }
        else if (!(exitSym[uint8_t(state.data[0])])) [[unlikely]]
        {
            state.data++;
            continue;
        }
        state.consumed = 0;
        state.node = node_t::LOOP_12_3;
        return true;
    }
    state.consumed += unsigned(state.data - beginData);
    state.node = node_t::RANGE_12_2;
    return true;
}

inline bool xml::loop_12_3(state_t & state)
{
    if (state.data == state.end)
        return true;
    if (text_13_0(state)) // case_1
        return true;
    if (range_14_0(state)) // case_2
        return true;
    if (string_15_0(state)) // case_3
        return true;
    state.node = node_t::NO_STATE;
    return true;
}

inline bool xml::text_13_0(state_t & state)
{
    if(state.data < state.end)
    {
        if (uint8_t(0x3E) != uint8_t(state.data[0]))
        {
            state.node = node_t::NO_STATE;
            return false;
        } else {
            state.data++;
            state.node = node_t::RET_13_1;
            return true;
        }
    }
    state.node = node_t::TEXT_13_0;
    return true;
}

inline bool xml::ret_13_1(state_t & state)
{
    state.node = state.retStackCount ? state.retStack[--state.retStackCount] : node_t::NO_STATE;
    return state.node != node_t::NO_STATE;
}

inline bool xml::range_14_0(state_t & state)
{
    const static bool exitSym[256] = {
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
    const char * beginData = state.data;
    while(state.data < state.end)
    {
        if (exitSym[uint8_t(state.data[0])]) [[unlikely]]
        {
            state.consumed += unsigned(state.data - beginData);
            state.node = (state.consumed >= 1) ? node_t::TEXT_14_1 : node_t::NO_STATE;
            bool ret = (state.node == node_t::TEXT_14_1);
            state.consumed = 0;
            return ret;
        }
        state.data++;
        state.node = node_t::TEXT_14_1;
        return true;
    }
    state.consumed += unsigned(state.data - beginData);
    state.node = node_t::RANGE_14_0;
    return true;
}

inline bool xml::text_14_1(state_t & state)
{
    if(state.data < state.end)
    {
        if (uint8_t(0x3E) != uint8_t(state.data[0]))
        {
            state.node = node_t::NO_STATE;
            return false;
        } else {
            state.data++;
            state.node = node_t::FUNC_14_2;
            return true;
        }
    }
    state.node = node_t::TEXT_14_1;
    return true;
}

inline bool xml::_func_14_2()
{
     return opend--; 
    return true;
}
inline bool xml::func_14_2(state_t & state)
{
    bool ret = _func_14_2();
    state.node = ret ? node_t::NOTIFY_14_3 : node_t::NO_STATE;
    return ret;
}

inline bool xml::notify_14_3(state_t & state)
{
    finishTag();
    state.node = node_t::RET_14_4;
    return true;
}

inline bool xml::ret_14_4(state_t & state)
{
    state.node = state.retStackCount ? state.retStack[--state.retStackCount] : node_t::NO_STATE;
    return state.node != node_t::NO_STATE;
}

void xml::_string_15_0(const char * data, unsigned len, uint64_t consumed)
{
    if (!consumed)
        xmlResult::key.clear();
    if ((xmlResult::key.length() + len) > 256)
        len = 256 - xmlResult::key.length();
    xmlResult::key.append(data, len);
}

inline bool xml::string_15_0(state_t & state)
{
    const static bool exitSym[256] = {
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
    const char * beginData = state.data;
    while(state.data < state.end) [[likely]]
    {
        if(&state.data[16] <= state.end)
        {
            if (exitSym[uint8_t(state.data[0])]) [[unlikely]]
                state.data += 0;
            else if (exitSym[uint8_t(state.data[1])]) [[unlikely]]
                state.data += 1;
            else if (exitSym[uint8_t(state.data[2])]) [[unlikely]]
                state.data += 2;
            else if (exitSym[uint8_t(state.data[3])]) [[unlikely]]
                state.data += 3;
            else if (exitSym[uint8_t(state.data[4])]) [[unlikely]]
                state.data += 4;
            else if (exitSym[uint8_t(state.data[5])]) [[unlikely]]
                state.data += 5;
            else if (exitSym[uint8_t(state.data[6])]) [[unlikely]]
                state.data += 6;
            else if (exitSym[uint8_t(state.data[7])]) [[unlikely]]
                state.data += 7;
            else if (exitSym[uint8_t(state.data[8])]) [[unlikely]]
                state.data += 8;
            else if (exitSym[uint8_t(state.data[9])]) [[unlikely]]
                state.data += 9;
            else if (exitSym[uint8_t(state.data[10])]) [[unlikely]]
                state.data += 10;
            else if (exitSym[uint8_t(state.data[11])]) [[unlikely]]
                state.data += 11;
            else if (exitSym[uint8_t(state.data[12])]) [[unlikely]]
                state.data += 12;
            else if (exitSym[uint8_t(state.data[13])]) [[unlikely]]
                state.data += 13;
            else if (exitSym[uint8_t(state.data[14])]) [[unlikely]]
                state.data += 14;
            else if (exitSym[uint8_t(state.data[15])]) [[unlikely]]
                state.data += 15;
            else
            {
                state.data += 16;
                continue;
            }
        }
        else if (!(exitSym[uint8_t(state.data[0])])) [[unlikely]]
        {
            state.data++;
            continue;
        }
        _string_15_0(beginData, unsigned(state.data - beginData), state.consumed);
        uint64_t totalConsumed = state.consumed + unsigned(state.data - beginData);
        state.consumed = 0;
        if (totalConsumed >= 1)
        {
            state.node = node_t::RANGE_15_1;
            return true;
        } else {
            state.node = node_t::NO_STATE;
            return false;
        }
    }
    if (beginData < state.data)
        _string_15_0(beginData, unsigned(state.data - beginData), state.consumed);
    state.consumed += unsigned(state.data - beginData);
    state.node = node_t::STRING_15_0;
    return true;
}

inline bool xml::range_15_1(state_t & state)
{
    const static bool exitSym[256] = {
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
    const char * beginData = state.data;
    while(state.data < state.end) [[likely]]
    {
        if(&state.data[16] <= state.end)
        {
            if (exitSym[uint8_t(state.data[0])]) [[unlikely]]
                state.data += 0;
            else if (exitSym[uint8_t(state.data[1])]) [[unlikely]]
                state.data += 1;
            else if (exitSym[uint8_t(state.data[2])]) [[unlikely]]
                state.data += 2;
            else if (exitSym[uint8_t(state.data[3])]) [[unlikely]]
                state.data += 3;
            else if (exitSym[uint8_t(state.data[4])]) [[unlikely]]
                state.data += 4;
            else if (exitSym[uint8_t(state.data[5])]) [[unlikely]]
                state.data += 5;
            else if (exitSym[uint8_t(state.data[6])]) [[unlikely]]
                state.data += 6;
            else if (exitSym[uint8_t(state.data[7])]) [[unlikely]]
                state.data += 7;
            else if (exitSym[uint8_t(state.data[8])]) [[unlikely]]
                state.data += 8;
            else if (exitSym[uint8_t(state.data[9])]) [[unlikely]]
                state.data += 9;
            else if (exitSym[uint8_t(state.data[10])]) [[unlikely]]
                state.data += 10;
            else if (exitSym[uint8_t(state.data[11])]) [[unlikely]]
                state.data += 11;
            else if (exitSym[uint8_t(state.data[12])]) [[unlikely]]
                state.data += 12;
            else if (exitSym[uint8_t(state.data[13])]) [[unlikely]]
                state.data += 13;
            else if (exitSym[uint8_t(state.data[14])]) [[unlikely]]
                state.data += 14;
            else if (exitSym[uint8_t(state.data[15])]) [[unlikely]]
                state.data += 15;
            else
            {
                state.data += 16;
                continue;
            }
        }
        else if (!(exitSym[uint8_t(state.data[0])])) [[unlikely]]
        {
            state.data++;
            continue;
        }
        state.consumed = 0;
        state.node = node_t::TEXT_15_2;
        return true;
    }
    state.consumed += unsigned(state.data - beginData);
    state.node = node_t::RANGE_15_1;
    return true;
}

inline bool xml::text_15_2(state_t & state)
{
    if(state.data < state.end)
    {
        if (uint8_t(0x3D) != uint8_t(state.data[0]))
        {
            state.node = node_t::NO_STATE;
            return false;
        } else {
            state.data++;
            state.node = node_t::RANGE_15_3;
            return true;
        }
    }
    state.node = node_t::TEXT_15_2;
    return true;
}

inline bool xml::range_15_3(state_t & state)
{
    const static bool exitSym[256] = {
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
    const char * beginData = state.data;
    while(state.data < state.end) [[likely]]
    {
        if(&state.data[16] <= state.end)
        {
            if (exitSym[uint8_t(state.data[0])]) [[unlikely]]
                state.data += 0;
            else if (exitSym[uint8_t(state.data[1])]) [[unlikely]]
                state.data += 1;
            else if (exitSym[uint8_t(state.data[2])]) [[unlikely]]
                state.data += 2;
            else if (exitSym[uint8_t(state.data[3])]) [[unlikely]]
                state.data += 3;
            else if (exitSym[uint8_t(state.data[4])]) [[unlikely]]
                state.data += 4;
            else if (exitSym[uint8_t(state.data[5])]) [[unlikely]]
                state.data += 5;
            else if (exitSym[uint8_t(state.data[6])]) [[unlikely]]
                state.data += 6;
            else if (exitSym[uint8_t(state.data[7])]) [[unlikely]]
                state.data += 7;
            else if (exitSym[uint8_t(state.data[8])]) [[unlikely]]
                state.data += 8;
            else if (exitSym[uint8_t(state.data[9])]) [[unlikely]]
                state.data += 9;
            else if (exitSym[uint8_t(state.data[10])]) [[unlikely]]
                state.data += 10;
            else if (exitSym[uint8_t(state.data[11])]) [[unlikely]]
                state.data += 11;
            else if (exitSym[uint8_t(state.data[12])]) [[unlikely]]
                state.data += 12;
            else if (exitSym[uint8_t(state.data[13])]) [[unlikely]]
                state.data += 13;
            else if (exitSym[uint8_t(state.data[14])]) [[unlikely]]
                state.data += 14;
            else if (exitSym[uint8_t(state.data[15])]) [[unlikely]]
                state.data += 15;
            else
            {
                state.data += 16;
                continue;
            }
        }
        else if (!(exitSym[uint8_t(state.data[0])])) [[unlikely]]
        {
            state.data++;
            continue;
        }
        state.consumed = 0;
        state.node = node_t::RANGE_15_4;
        return true;
    }
    state.consumed += unsigned(state.data - beginData);
    state.node = node_t::RANGE_15_3;
    return true;
}

inline bool xml::range_15_4(state_t & state)
{
    const static bool exitSym[256] = {
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
    const char * beginData = state.data;
    while(state.data < state.end)
    {
        if (exitSym[uint8_t(state.data[0])]) [[unlikely]]
        {
            state.consumed += unsigned(state.data - beginData);
            state.node = (state.consumed >= 1) ? node_t::STRING_15_5 : node_t::NO_STATE;
            bool ret = (state.node == node_t::STRING_15_5);
            state.consumed = 0;
            return ret;
        }
        state.data++;
        state.node = node_t::STRING_15_5;
        return true;
    }
    state.consumed += unsigned(state.data - beginData);
    state.node = node_t::RANGE_15_4;
    return true;
}

void xml::_string_15_5(const char * data, unsigned len, uint64_t consumed)
{
    if (!consumed)
        xmlResult::value.clear();
    if ((xmlResult::value.length() + len) > 256)
        len = 256 - xmlResult::value.length();
    xmlResult::value.append(data, len);
}

inline bool xml::string_15_5(state_t & state)
{
    const static bool exitSym[256] = {
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
    const char * beginData = state.data;
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
            if (exitSym[uint8_t(state.data[0])]) [[unlikely]]
                state.data += 0;
            else if (exitSym[uint8_t(state.data[1])]) [[unlikely]]
                state.data += 1;
            else if (exitSym[uint8_t(state.data[2])]) [[unlikely]]
                state.data += 2;
            else if (exitSym[uint8_t(state.data[3])]) [[unlikely]]
                state.data += 3;
            else if (exitSym[uint8_t(state.data[4])]) [[unlikely]]
                state.data += 4;
            else if (exitSym[uint8_t(state.data[5])]) [[unlikely]]
                state.data += 5;
            else if (exitSym[uint8_t(state.data[6])]) [[unlikely]]
                state.data += 6;
            else if (exitSym[uint8_t(state.data[7])]) [[unlikely]]
                state.data += 7;
            else if (exitSym[uint8_t(state.data[8])]) [[unlikely]]
                state.data += 8;
            else if (exitSym[uint8_t(state.data[9])]) [[unlikely]]
                state.data += 9;
            else if (exitSym[uint8_t(state.data[10])]) [[unlikely]]
                state.data += 10;
            else if (exitSym[uint8_t(state.data[11])]) [[unlikely]]
                state.data += 11;
            else if (exitSym[uint8_t(state.data[12])]) [[unlikely]]
                state.data += 12;
            else if (exitSym[uint8_t(state.data[13])]) [[unlikely]]
                state.data += 13;
            else if (exitSym[uint8_t(state.data[14])]) [[unlikely]]
                state.data += 14;
            else if (exitSym[uint8_t(state.data[15])]) [[unlikely]]
                state.data += 15;
            else
            {
                state.data += 16;
                continue;
            }
        }
#endif
        else if (!(exitSym[uint8_t(state.data[0])])) [[unlikely]]
        {
            state.data++;
            continue;
        }
        _string_15_5(beginData, unsigned(state.data - beginData), state.consumed);
        state.consumed = 0;
        state.node = node_t::RANGE_15_6;
        return true;
    }
    if (beginData < state.data)
        _string_15_5(beginData, unsigned(state.data - beginData), state.consumed);
    state.consumed += unsigned(state.data - beginData);
    state.node = node_t::STRING_15_5;
    return true;
}

inline bool xml::range_15_6(state_t & state)
{
    const static bool exitSym[256] = {
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
    const char * beginData = state.data;
    while(state.data < state.end)
    {
        if (exitSym[uint8_t(state.data[0])]) [[unlikely]]
        {
            state.consumed += unsigned(state.data - beginData);
            state.node = (state.consumed >= 1) ? node_t::NOTIFY_15_7 : node_t::NO_STATE;
            bool ret = (state.node == node_t::NOTIFY_15_7);
            state.consumed = 0;
            return ret;
        }
        state.data++;
        state.node = node_t::NOTIFY_15_7;
        return true;
    }
    state.consumed += unsigned(state.data - beginData);
    state.node = node_t::RANGE_15_6;
    return true;
}

inline bool xml::notify_15_7(state_t & state)
{
    getAttribute();
    state.node = node_t::RANGE_15_8;
    return true;
}

inline bool xml::range_15_8(state_t & state)
{
    const static bool exitSym[256] = {
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
    const char * beginData = state.data;
    while(state.data < state.end) [[likely]]
    {
        if(&state.data[16] <= state.end)
        {
            if (exitSym[uint8_t(state.data[0])]) [[unlikely]]
                state.data += 0;
            else if (exitSym[uint8_t(state.data[1])]) [[unlikely]]
                state.data += 1;
            else if (exitSym[uint8_t(state.data[2])]) [[unlikely]]
                state.data += 2;
            else if (exitSym[uint8_t(state.data[3])]) [[unlikely]]
                state.data += 3;
            else if (exitSym[uint8_t(state.data[4])]) [[unlikely]]
                state.data += 4;
            else if (exitSym[uint8_t(state.data[5])]) [[unlikely]]
                state.data += 5;
            else if (exitSym[uint8_t(state.data[6])]) [[unlikely]]
                state.data += 6;
            else if (exitSym[uint8_t(state.data[7])]) [[unlikely]]
                state.data += 7;
            else if (exitSym[uint8_t(state.data[8])]) [[unlikely]]
                state.data += 8;
            else if (exitSym[uint8_t(state.data[9])]) [[unlikely]]
                state.data += 9;
            else if (exitSym[uint8_t(state.data[10])]) [[unlikely]]
                state.data += 10;
            else if (exitSym[uint8_t(state.data[11])]) [[unlikely]]
                state.data += 11;
            else if (exitSym[uint8_t(state.data[12])]) [[unlikely]]
                state.data += 12;
            else if (exitSym[uint8_t(state.data[13])]) [[unlikely]]
                state.data += 13;
            else if (exitSym[uint8_t(state.data[14])]) [[unlikely]]
                state.data += 14;
            else if (exitSym[uint8_t(state.data[15])]) [[unlikely]]
                state.data += 15;
            else
            {
                state.data += 16;
                continue;
            }
        }
        else if (!(exitSym[uint8_t(state.data[0])])) [[unlikely]]
        {
            state.data++;
            continue;
        }
        state.consumed = 0;
        state.node = node_t::LOOP_12_3;
        return true;
    }
    state.consumed += unsigned(state.data - beginData);
    state.node = node_t::RANGE_15_8;
    return true;
}

inline bool xml::loop_17_0(state_t & state)
{
    return uint_17_0(state);
}

void xml::_uint_17_0(const char * data, unsigned len, uint64_t consumed)
{
    if (!consumed)
        xmlResult::opend = 0;
    for(const char * end = &data[len]; data < end; data++)
        xmlResult::opend = xmlResult::opend*10 + *data - '0';
}

inline bool xml::uint_17_0(state_t & state)
{
    const static bool exitSym[256] = {
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
    const char * beginData = state.data;
    while(state.data < state.end) [[likely]]
    {
        if(&state.data[16] <= state.end)
        {
            if (exitSym[uint8_t(state.data[0])]) [[unlikely]]
                state.data += 0;
            else if (exitSym[uint8_t(state.data[1])]) [[unlikely]]
                state.data += 1;
            else if (exitSym[uint8_t(state.data[2])]) [[unlikely]]
                state.data += 2;
            else if (exitSym[uint8_t(state.data[3])]) [[unlikely]]
                state.data += 3;
            else if (exitSym[uint8_t(state.data[4])]) [[unlikely]]
                state.data += 4;
            else if (exitSym[uint8_t(state.data[5])]) [[unlikely]]
                state.data += 5;
            else if (exitSym[uint8_t(state.data[6])]) [[unlikely]]
                state.data += 6;
            else if (exitSym[uint8_t(state.data[7])]) [[unlikely]]
                state.data += 7;
            else if (exitSym[uint8_t(state.data[8])]) [[unlikely]]
                state.data += 8;
            else if (exitSym[uint8_t(state.data[9])]) [[unlikely]]
                state.data += 9;
            else if (exitSym[uint8_t(state.data[10])]) [[unlikely]]
                state.data += 10;
            else if (exitSym[uint8_t(state.data[11])]) [[unlikely]]
                state.data += 11;
            else if (exitSym[uint8_t(state.data[12])]) [[unlikely]]
                state.data += 12;
            else if (exitSym[uint8_t(state.data[13])]) [[unlikely]]
                state.data += 13;
            else if (exitSym[uint8_t(state.data[14])]) [[unlikely]]
                state.data += 14;
            else if (exitSym[uint8_t(state.data[15])]) [[unlikely]]
                state.data += 15;
            else
            {
                state.data += 16;
                continue;
            }
        }
        else if (!(exitSym[uint8_t(state.data[0])])) [[unlikely]]
        {
            state.data++;
            continue;
        }
        _uint_17_0(beginData, unsigned(state.data - beginData), state.consumed);
        uint64_t totalConsumed = state.consumed + unsigned(state.data - beginData);
        state.consumed = 0;
        if (totalConsumed >= 1)
        {
            state.node = node_t::LOOP_17_0;
            return true;
        } else {
            state.node = node_t::NO_STATE;
            return false;
        }
    }
    if (beginData < state.data)
        _uint_17_0(beginData, unsigned(state.data - beginData), state.consumed);
    state.consumed += unsigned(state.data - beginData);
    state.node = node_t::UINT_17_0;
    return true;
}

void xml::reset()
{
    xmlResult::key.clear();
    xmlResult::opend = 0;
    xmlResult::tag.clear();
    xmlResult::value.clear();
    xml::mainState = xml::state_t();
}

const char * xml::state_t::name() const
{
    switch(node)
    {
        case node_t::LOOP_1_0: return "LOOP_1_0";
        case node_t::LABEL_1_0: return "LABEL_1_0";
        case node_t::LOOP_1_1: return "LOOP_1_1";
        case node_t::RANGE_2_0: return "RANGE_2_0";
        case node_t::RANGE_3_0: return "RANGE_3_0";
        case node_t::TEXT_4_0: return "TEXT_4_0";
        case node_t::GOTO_4_1: return "GOTO_4_1";
        case node_t::RANGE_5_0: return "RANGE_5_0";
        case node_t::LOOP_7_0: return "LOOP_7_0";
        case node_t::LABEL_7_0: return "LABEL_7_0";
        case node_t::LOOP_7_1: return "LOOP_7_1";
        case node_t::TEXT_8_0: return "TEXT_8_0";
        case node_t::LOOP_8_1: return "LOOP_8_1";
        case node_t::TEXT_9_0: return "TEXT_9_0";
        case node_t::RET_9_1: return "RET_9_1";
        case node_t::RANGE_10_0: return "RANGE_10_0";
        case node_t::TEXT_11_0: return "TEXT_11_0";
        case node_t::STRING_11_1: return "STRING_11_1";
        case node_t::RANGE_11_2: return "RANGE_11_2";
        case node_t::FUNC_11_3: return "FUNC_11_3";
        case node_t::NOTIFY_11_4: return "NOTIFY_11_4";
        case node_t::RET_11_5: return "RET_11_5";
        case node_t::STRING_12_0: return "STRING_12_0";
        case node_t::FUNC_12_1: return "FUNC_12_1";
        case node_t::RANGE_12_2: return "RANGE_12_2";
        case node_t::LOOP_12_3: return "LOOP_12_3";
        case node_t::TEXT_13_0: return "TEXT_13_0";
        case node_t::RET_13_1: return "RET_13_1";
        case node_t::RANGE_14_0: return "RANGE_14_0";
        case node_t::TEXT_14_1: return "TEXT_14_1";
        case node_t::FUNC_14_2: return "FUNC_14_2";
        case node_t::NOTIFY_14_3: return "NOTIFY_14_3";
        case node_t::RET_14_4: return "RET_14_4";
        case node_t::STRING_15_0: return "STRING_15_0";
        case node_t::RANGE_15_1: return "RANGE_15_1";
        case node_t::TEXT_15_2: return "TEXT_15_2";
        case node_t::RANGE_15_3: return "RANGE_15_3";
        case node_t::RANGE_15_4: return "RANGE_15_4";
        case node_t::STRING_15_5: return "STRING_15_5";
        case node_t::RANGE_15_6: return "RANGE_15_6";
        case node_t::NOTIFY_15_7: return "NOTIFY_15_7";
        case node_t::RANGE_15_8: return "RANGE_15_8";
        case node_t::LOOP_17_0: return "LOOP_17_0";
        case node_t::UINT_17_0: return "UINT_17_0";
        case node_t::NO_STATE: return "NO_STATE";
        default: return "unknown";
    };
}

