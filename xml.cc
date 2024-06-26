#include "xml.h"

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
            case node_t::LABEL_1_0: label_1_0(state); break;
            case node_t::LOOP_1_1: loop_1_1(state); break;
            case node_t::RANGE_2_0: range_2_0(state); break;
            case node_t::RANGE_3_0: range_3_0(state); break;
            case node_t::TEXT_4_0: text_4_0(state); break;
            case node_t::GOTO_4_1: goto_4_1(state); break;
            case node_t::RANGE_5_0: range_5_0(state); break;
            case node_t::LOOP_7_0: loop_7_0(state); break;
            case node_t::LABEL_7_0: label_7_0(state); break;
            case node_t::LOOP_7_1: loop_7_1(state); break;
            case node_t::TEXT_8_0: text_8_0(state, false); break;
            case node_t::LOOP_8_1: loop_8_1(state); break;
            case node_t::TEXT_9_0: text_9_0(state, false); break;
            case node_t::RET_9_1: ret_9_1(state); break;
            case node_t::RANGE_10_0: range_10_0(state); break;
            case node_t::TEXT_11_0: text_11_0(state); break;
            case node_t::STRING_11_1: string_11_1(state); break;
            case node_t::RANGE_11_2: range_11_2(state); break;
            case node_t::FUNC_11_3: func_11_3(state); break;
            case node_t::NOTIFY_11_4: notify_11_4(state); break;
            case node_t::RET_11_5: ret_11_5(state); break;
            case node_t::STRING_12_0: string_12_0(state); break;
            case node_t::FUNC_12_1: func_12_1(state); break;
            case node_t::RANGE_12_2: range_12_2(state); break;
            case node_t::LOOP_12_3: loop_12_3(state); break;
            case node_t::TEXT_13_0: text_13_0(state); break;
            case node_t::RET_13_1: ret_13_1(state); break;
            case node_t::RANGE_14_0: range_14_0(state); break;
            case node_t::TEXT_14_1: text_14_1(state); break;
            case node_t::FUNC_14_2: func_14_2(state); break;
            case node_t::NOTIFY_14_3: notify_14_3(state); break;
            case node_t::RET_14_4: ret_14_4(state); break;
            case node_t::STRING_15_0: string_15_0(state); break;
            case node_t::RANGE_15_1: range_15_1(state); break;
            case node_t::TEXT_15_2: text_15_2(state); break;
            case node_t::RANGE_15_3: range_15_3(state); break;
            case node_t::RANGE_15_4: range_15_4(state); break;
            case node_t::STRING_15_5: string_15_5(state); break;
            case node_t::RANGE_15_6: range_15_6(state); break;
            case node_t::NOTIFY_15_7: notify_15_7(state); break;
            case node_t::RANGE_15_8: range_15_8(state); break;
            case node_t::LOOP_17_0: loop_17_0(state); break;
            case node_t::UINT_17_0: uint_17_0(state); break;
            case node_t::NO_STATE:
            default: return;
        }; // switch
        if (n == state.node && d == state.data)
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
    state_t startState = state;
    if (range_2_0(state)) // case_1
        return true;
    state = startState;
    if (range_3_0(state)) // case_2
        return true;
    state = startState;
    if (text_4_0(state)) // case_3
        return true;
    state = startState;
    if (range_5_0(state)) // case_4
        return true;
    state = startState;
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
    while(state.data < state.end)
    {
        unsigned exitCount = 0;
        if(&state.data[8] <= state.end)
        {
            if (exitSym[uint8_t(state.data[0])])
                exitCount = 0;
            else if (exitSym[uint8_t(state.data[1])])
                exitCount = 1;
            else if (exitSym[uint8_t(state.data[2])])
                exitCount = 2;
            else if (exitSym[uint8_t(state.data[3])])
                exitCount = 3;
            else if (exitSym[uint8_t(state.data[4])])
                exitCount = 4;
            else if (exitSym[uint8_t(state.data[5])])
                exitCount = 5;
            else if (exitSym[uint8_t(state.data[6])])
                exitCount = 6;
            else if (exitSym[uint8_t(state.data[7])])
                exitCount = 7;
            else
            {
                state.data += 8;
                continue;
            }
        }
        else if (!exitSym[uint8_t(state.data[0])])
        {
            state.data++;
            continue;
        }
        state.data += exitCount;
        state.eatSymCount += unsigned(state.data - beginData);
        state.node = (state.eatSymCount >= 1) ? node_t::LOOP_1_1 : node_t::NO_STATE;
        bool ret = (state.node == node_t::LOOP_1_1);
        state.eatSymCount = 0;
        return ret;
    }
    state.eatSymCount += unsigned(state.data - beginData);
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
    while(state.data < state.end)
    {
        unsigned exitCount = 0;
        if(&state.data[8] <= state.end)
        {
            if (exitSym[uint8_t(state.data[0])])
                exitCount = 0;
            else if (exitSym[uint8_t(state.data[1])])
                exitCount = 1;
            else if (exitSym[uint8_t(state.data[2])])
                exitCount = 2;
            else if (exitSym[uint8_t(state.data[3])])
                exitCount = 3;
            else if (exitSym[uint8_t(state.data[4])])
                exitCount = 4;
            else if (exitSym[uint8_t(state.data[5])])
                exitCount = 5;
            else if (exitSym[uint8_t(state.data[6])])
                exitCount = 6;
            else if (exitSym[uint8_t(state.data[7])])
                exitCount = 7;
            else
            {
                state.data += 8;
                continue;
            }
        }
        else if (!exitSym[uint8_t(state.data[0])])
        {
            state.data++;
            continue;
        }
        state.data += exitCount;
        state.eatSymCount += unsigned(state.data - beginData);
        state.node = (state.eatSymCount >= 1) ? node_t::LOOP_1_1 : node_t::NO_STATE;
        bool ret = (state.node == node_t::LOOP_1_1);
        state.eatSymCount = 0;
        return ret;
    }
    state.eatSymCount += unsigned(state.data - beginData);
    state.node = node_t::RANGE_3_0;
    return true;
}

inline bool xml::text_4_0(state_t & state)
{
    static uint8_t text[] = { 0x3c }; // <
    for(; state.data < state.end; state.data++)
    {
        uint8_t sym = (uint8_t)state.data[0];
        if (text[state.eatSymCount++] != sym)
        {
            state.node = node_t::NO_STATE;
            return false;
        }
        else if (state.eatSymCount >= sizeof(text))
        {
            state.data++;
            state.eatSymCount = 0;
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
    const static bool exitSym[256] = {
        false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, 
        false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, 
        false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, 
        false, false, false, false, false, false, false, false, false, false, false, false,  true, false, false, false, 
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
        false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false}; // ^[0x3c]
    bool isFirstData = !state.eatSymCount;
    const char * beginData = state.data;
    while(state.data < state.end)
    {
        unsigned exitCount = 0;
        if(&state.data[8] <= state.end)
        {
            if (exitSym[uint8_t(state.data[0])])
                exitCount = 0;
            else if (exitSym[uint8_t(state.data[1])])
                exitCount = 1;
            else if (exitSym[uint8_t(state.data[2])])
                exitCount = 2;
            else if (exitSym[uint8_t(state.data[3])])
                exitCount = 3;
            else if (exitSym[uint8_t(state.data[4])])
                exitCount = 4;
            else if (exitSym[uint8_t(state.data[5])])
                exitCount = 5;
            else if (exitSym[uint8_t(state.data[6])])
                exitCount = 6;
            else if (exitSym[uint8_t(state.data[7])])
                exitCount = 7;
            else
            {
                state.data += 8;
                continue;
            }
        }
        else if (!exitSym[uint8_t(state.data[0])])
        {
            state.data++;
            continue;
        }
        state.data += exitCount;
        xmlResult::payload(beginData, unsigned(state.data - beginData), isFirstData, true);
        state.eatSymCount += unsigned(state.data - beginData);
        state.node = (state.eatSymCount >= 1) ? node_t::LOOP_1_1 : node_t::NO_STATE;
        bool ret = (state.node == node_t::LOOP_1_1);
        state.eatSymCount = 0;
        return ret;
    }
    state.eatSymCount += unsigned(state.data - beginData);
    if (beginData < state.data)
        xmlResult::payload(beginData, unsigned(state.data - beginData), isFirstData, false);
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
    state_t startState = state;
    if (text_8_0(state, true)) // case_1
        return true;
    state = startState;
    if (text_11_0(state)) // case_2
        return true;
    state = startState;
    if (string_12_0(state)) // case_3
        return true;
    state = startState;
    state.node = node_t::NO_STATE;
    return true;
}

inline bool xml::text_8_0(state_t & state, bool isCaseCall)
{
    static uint8_t text[] = { 0x21, 0x2d, 0x2d }; // !--
    for(; state.data < state.end; state.data++)
    {
        uint8_t sym = (uint8_t)state.data[0];
        if (text[state.eatSymCount++] != sym)
        {
            state.node = node_t::NO_STATE;
            bool ret = isCaseCall && state.eatSymCount > 1;
            state.eatSymCount = 0;
            return ret;
        }
        else if (state.eatSymCount >= sizeof(text))
        {
            state.data++;
            state.eatSymCount = 0;
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
    static uint8_t text[] = { 0x2d, 0x2d, 0x3e }; // -->
    for(; state.data < state.end; state.data++)
    {
        uint8_t sym = (uint8_t)state.data[0];
        if (text[state.eatSymCount++] != sym)
        {
            state.node = node_t::RANGE_10_0;
            bool ret = isCaseCall && state.eatSymCount > 1;
            state.eatSymCount = 0;
            return ret;
        }
        else if (state.eatSymCount >= sizeof(text))
        {
            state.data++;
            state.eatSymCount = 0;
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
    const static bool exitSym[256] = {
        false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, 
        false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, 
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
        false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, 
        false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false}; // ^[0x2d]
    const char * beginData = state.data;
    while(state.data < state.end)
    {
        unsigned exitCount = 0;
        if(&state.data[8] <= state.end)
        {
            if (exitSym[uint8_t(state.data[0])])
                exitCount = 0;
            else if (exitSym[uint8_t(state.data[1])])
                exitCount = 1;
            else if (exitSym[uint8_t(state.data[2])])
                exitCount = 2;
            else if (exitSym[uint8_t(state.data[3])])
                exitCount = 3;
            else if (exitSym[uint8_t(state.data[4])])
                exitCount = 4;
            else if (exitSym[uint8_t(state.data[5])])
                exitCount = 5;
            else if (exitSym[uint8_t(state.data[6])])
                exitCount = 6;
            else if (exitSym[uint8_t(state.data[7])])
                exitCount = 7;
            else
            {
                state.data += 8;
                continue;
            }
        }
        else if (!exitSym[uint8_t(state.data[0])])
        {
            state.data++;
            continue;
        }
        state.data += exitCount;
        state.node = node_t::LOOP_8_1;
        bool ret = (state.node == node_t::LOOP_8_1);
        state.eatSymCount = 0;
        return ret;
    }
    state.eatSymCount += unsigned(state.data - beginData);
    state.node = node_t::RANGE_10_0;
    return true;
}

inline bool xml::text_11_0(state_t & state)
{
    static uint8_t text[] = { 0x2f }; // /
    for(; state.data < state.end; state.data++)
    {
        uint8_t sym = (uint8_t)state.data[0];
        if (text[state.eatSymCount++] != sym)
        {
            state.node = node_t::NO_STATE;
            return false;
        }
        else if (state.eatSymCount >= sizeof(text))
        {
            state.data++;
            state.eatSymCount = 0;
            state.node = node_t::STRING_11_1;
            return true;
        }
    }
    state.node = node_t::TEXT_11_0;
    return true;
}

inline void xml::_string_11_1(const char * data, unsigned len, bool isFirst)
{
    if (isFirst)
        xmlResult::tag.clear();
    else if ((xmlResult::tag.length() + len) > 256)
        len = 256 - xmlResult::tag.length();
    xmlResult::tag.append(data, len);
}

inline bool xml::string_11_1(state_t & state)
{
    const static bool exitSym[256] = {
        false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, 
        false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, 
        false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, 
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
        false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false}; // ^[0x3e]
    bool isFirstData = !state.eatSymCount;
    const char * beginData = state.data;
    while(state.data < state.end)
    {
        unsigned exitCount = 0;
        if(&state.data[8] <= state.end)
        {
            if (exitSym[uint8_t(state.data[0])])
                exitCount = 0;
            else if (exitSym[uint8_t(state.data[1])])
                exitCount = 1;
            else if (exitSym[uint8_t(state.data[2])])
                exitCount = 2;
            else if (exitSym[uint8_t(state.data[3])])
                exitCount = 3;
            else if (exitSym[uint8_t(state.data[4])])
                exitCount = 4;
            else if (exitSym[uint8_t(state.data[5])])
                exitCount = 5;
            else if (exitSym[uint8_t(state.data[6])])
                exitCount = 6;
            else if (exitSym[uint8_t(state.data[7])])
                exitCount = 7;
            else
            {
                state.data += 8;
                continue;
            }
        }
        else if (!exitSym[uint8_t(state.data[0])])
        {
            state.data++;
            continue;
        }
        state.data += exitCount;
        _string_11_1(beginData, unsigned(state.data - beginData), isFirstData);
        state.eatSymCount += unsigned(state.data - beginData);
        state.node = (state.eatSymCount >= 1) ? node_t::RANGE_11_2 : node_t::NO_STATE;
        bool ret = (state.node == node_t::RANGE_11_2);
        state.eatSymCount = 0;
        return ret;
    }
    state.eatSymCount += unsigned(state.data - beginData);
    if (beginData < state.data)
        _string_11_1(beginData, unsigned(state.data - beginData), isFirstData);
    state.node = node_t::STRING_11_1;
    return true;
}

inline bool xml::range_11_2(state_t & state)
{
    const static bool exitSym[256] = {
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, false,  true, 
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
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true}; // [0x3e]
    while(state.data < state.end)
    {
        unsigned stateDataCount = 1;
        for(unsigned i = 0; i < stateDataCount; i++)
            if (exitSym[uint8_t(state.data[i])])
            {
                state.data += i;
                state.eatSymCount += i;
                state.node = (state.eatSymCount >= 1) ? node_t::FUNC_11_3 : node_t::NO_STATE;
                bool ret = (state.node == node_t::FUNC_11_3);
                state.eatSymCount = 0;
                return ret;
            }
        state.data += stateDataCount;
        state.node = node_t::FUNC_11_3;
        return true;
    }
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

inline void xml::_string_12_0(const char * data, unsigned len, bool isFirst)
{
    if (isFirst)
        xmlResult::tag.clear();
    else if ((xmlResult::tag.length() + len) > 256)
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
    bool isFirstData = !state.eatSymCount;
    const char * beginData = state.data;
    while(state.data < state.end)
    {
        unsigned exitCount = 0;
        if(&state.data[8] <= state.end)
        {
            if (exitSym[uint8_t(state.data[0])])
                exitCount = 0;
            else if (exitSym[uint8_t(state.data[1])])
                exitCount = 1;
            else if (exitSym[uint8_t(state.data[2])])
                exitCount = 2;
            else if (exitSym[uint8_t(state.data[3])])
                exitCount = 3;
            else if (exitSym[uint8_t(state.data[4])])
                exitCount = 4;
            else if (exitSym[uint8_t(state.data[5])])
                exitCount = 5;
            else if (exitSym[uint8_t(state.data[6])])
                exitCount = 6;
            else if (exitSym[uint8_t(state.data[7])])
                exitCount = 7;
            else
            {
                state.data += 8;
                continue;
            }
        }
        else if (!exitSym[uint8_t(state.data[0])])
        {
            state.data++;
            continue;
        }
        state.data += exitCount;
        _string_12_0(beginData, unsigned(state.data - beginData), isFirstData);
        state.eatSymCount += unsigned(state.data - beginData);
        state.node = (state.eatSymCount >= 1) ? node_t::FUNC_12_1 : node_t::NO_STATE;
        bool ret = (state.node == node_t::FUNC_12_1);
        state.eatSymCount = 0;
        return ret;
    }
    state.eatSymCount += unsigned(state.data - beginData);
    if (beginData < state.data)
        _string_12_0(beginData, unsigned(state.data - beginData), isFirstData);
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
    while(state.data < state.end)
    {
        unsigned exitCount = 0;
        if(&state.data[8] <= state.end)
        {
            if (exitSym[uint8_t(state.data[0])])
                exitCount = 0;
            else if (exitSym[uint8_t(state.data[1])])
                exitCount = 1;
            else if (exitSym[uint8_t(state.data[2])])
                exitCount = 2;
            else if (exitSym[uint8_t(state.data[3])])
                exitCount = 3;
            else if (exitSym[uint8_t(state.data[4])])
                exitCount = 4;
            else if (exitSym[uint8_t(state.data[5])])
                exitCount = 5;
            else if (exitSym[uint8_t(state.data[6])])
                exitCount = 6;
            else if (exitSym[uint8_t(state.data[7])])
                exitCount = 7;
            else
            {
                state.data += 8;
                continue;
            }
        }
        else if (!exitSym[uint8_t(state.data[0])])
        {
            state.data++;
            continue;
        }
        state.data += exitCount;
        state.node = node_t::LOOP_12_3;
        bool ret = (state.node == node_t::LOOP_12_3);
        state.eatSymCount = 0;
        return ret;
    }
    state.eatSymCount += unsigned(state.data - beginData);
    state.node = node_t::RANGE_12_2;
    return true;
}

inline bool xml::loop_12_3(state_t & state)
{
    if (state.data == state.end)
        return true;
    state_t startState = state;
    if (text_13_0(state)) // case_1
        return true;
    state = startState;
    if (range_14_0(state)) // case_2
        return true;
    state = startState;
    if (string_15_0(state)) // case_3
        return true;
    state = startState;
    state.node = node_t::NO_STATE;
    return true;
}

inline bool xml::text_13_0(state_t & state)
{
    static uint8_t text[] = { 0x3e }; // >
    for(; state.data < state.end; state.data++)
    {
        uint8_t sym = (uint8_t)state.data[0];
        if (text[state.eatSymCount++] != sym)
        {
            state.node = node_t::NO_STATE;
            return false;
        }
        else if (state.eatSymCount >= sizeof(text))
        {
            state.data++;
            state.eatSymCount = 0;
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
    while(state.data < state.end)
    {
        unsigned stateDataCount = 1;
        for(unsigned i = 0; i < stateDataCount; i++)
            if (exitSym[uint8_t(state.data[i])])
            {
                state.data += i;
                state.eatSymCount += i;
                state.node = (state.eatSymCount >= 1) ? node_t::TEXT_14_1 : node_t::NO_STATE;
                bool ret = (state.node == node_t::TEXT_14_1);
                state.eatSymCount = 0;
                return ret;
            }
        state.data += stateDataCount;
        state.node = node_t::TEXT_14_1;
        return true;
    }
    state.node = node_t::RANGE_14_0;
    return true;
}

inline bool xml::text_14_1(state_t & state)
{
    static uint8_t text[] = { 0x3e }; // >
    for(; state.data < state.end; state.data++)
    {
        uint8_t sym = (uint8_t)state.data[0];
        if (text[state.eatSymCount++] != sym)
        {
            state.node = node_t::NO_STATE;
            return false;
        }
        else if (state.eatSymCount >= sizeof(text))
        {
            state.data++;
            state.eatSymCount = 0;
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

inline void xml::_string_15_0(const char * data, unsigned len, bool isFirst)
{
    if (isFirst)
        xmlResult::key.clear();
    else if ((xmlResult::key.length() + len) > 256)
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
    bool isFirstData = !state.eatSymCount;
    const char * beginData = state.data;
    while(state.data < state.end)
    {
        unsigned exitCount = 0;
        if(&state.data[8] <= state.end)
        {
            if (exitSym[uint8_t(state.data[0])])
                exitCount = 0;
            else if (exitSym[uint8_t(state.data[1])])
                exitCount = 1;
            else if (exitSym[uint8_t(state.data[2])])
                exitCount = 2;
            else if (exitSym[uint8_t(state.data[3])])
                exitCount = 3;
            else if (exitSym[uint8_t(state.data[4])])
                exitCount = 4;
            else if (exitSym[uint8_t(state.data[5])])
                exitCount = 5;
            else if (exitSym[uint8_t(state.data[6])])
                exitCount = 6;
            else if (exitSym[uint8_t(state.data[7])])
                exitCount = 7;
            else
            {
                state.data += 8;
                continue;
            }
        }
        else if (!exitSym[uint8_t(state.data[0])])
        {
            state.data++;
            continue;
        }
        state.data += exitCount;
        _string_15_0(beginData, unsigned(state.data - beginData), isFirstData);
        state.eatSymCount += unsigned(state.data - beginData);
        state.node = (state.eatSymCount >= 1) ? node_t::RANGE_15_1 : node_t::NO_STATE;
        bool ret = (state.node == node_t::RANGE_15_1);
        state.eatSymCount = 0;
        return ret;
    }
    state.eatSymCount += unsigned(state.data - beginData);
    if (beginData < state.data)
        _string_15_0(beginData, unsigned(state.data - beginData), isFirstData);
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
    while(state.data < state.end)
    {
        unsigned exitCount = 0;
        if(&state.data[8] <= state.end)
        {
            if (exitSym[uint8_t(state.data[0])])
                exitCount = 0;
            else if (exitSym[uint8_t(state.data[1])])
                exitCount = 1;
            else if (exitSym[uint8_t(state.data[2])])
                exitCount = 2;
            else if (exitSym[uint8_t(state.data[3])])
                exitCount = 3;
            else if (exitSym[uint8_t(state.data[4])])
                exitCount = 4;
            else if (exitSym[uint8_t(state.data[5])])
                exitCount = 5;
            else if (exitSym[uint8_t(state.data[6])])
                exitCount = 6;
            else if (exitSym[uint8_t(state.data[7])])
                exitCount = 7;
            else
            {
                state.data += 8;
                continue;
            }
        }
        else if (!exitSym[uint8_t(state.data[0])])
        {
            state.data++;
            continue;
        }
        state.data += exitCount;
        state.node = node_t::TEXT_15_2;
        bool ret = (state.node == node_t::TEXT_15_2);
        state.eatSymCount = 0;
        return ret;
    }
    state.eatSymCount += unsigned(state.data - beginData);
    state.node = node_t::RANGE_15_1;
    return true;
}

inline bool xml::text_15_2(state_t & state)
{
    static uint8_t text[] = { 0x3d }; // =
    for(; state.data < state.end; state.data++)
    {
        uint8_t sym = (uint8_t)state.data[0];
        if (text[state.eatSymCount++] != sym)
        {
            state.node = node_t::NO_STATE;
            return false;
        }
        else if (state.eatSymCount >= sizeof(text))
        {
            state.data++;
            state.eatSymCount = 0;
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
    while(state.data < state.end)
    {
        unsigned exitCount = 0;
        if(&state.data[8] <= state.end)
        {
            if (exitSym[uint8_t(state.data[0])])
                exitCount = 0;
            else if (exitSym[uint8_t(state.data[1])])
                exitCount = 1;
            else if (exitSym[uint8_t(state.data[2])])
                exitCount = 2;
            else if (exitSym[uint8_t(state.data[3])])
                exitCount = 3;
            else if (exitSym[uint8_t(state.data[4])])
                exitCount = 4;
            else if (exitSym[uint8_t(state.data[5])])
                exitCount = 5;
            else if (exitSym[uint8_t(state.data[6])])
                exitCount = 6;
            else if (exitSym[uint8_t(state.data[7])])
                exitCount = 7;
            else
            {
                state.data += 8;
                continue;
            }
        }
        else if (!exitSym[uint8_t(state.data[0])])
        {
            state.data++;
            continue;
        }
        state.data += exitCount;
        state.node = node_t::RANGE_15_4;
        bool ret = (state.node == node_t::RANGE_15_4);
        state.eatSymCount = 0;
        return ret;
    }
    state.eatSymCount += unsigned(state.data - beginData);
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
    while(state.data < state.end)
    {
        unsigned stateDataCount = 1;
        for(unsigned i = 0; i < stateDataCount; i++)
            if (exitSym[uint8_t(state.data[i])])
            {
                state.data += i;
                state.eatSymCount += i;
                state.node = (state.eatSymCount >= 1) ? node_t::STRING_15_5 : node_t::NO_STATE;
                bool ret = (state.node == node_t::STRING_15_5);
                state.eatSymCount = 0;
                return ret;
            }
        state.data += stateDataCount;
        state.node = node_t::STRING_15_5;
        return true;
    }
    state.node = node_t::RANGE_15_4;
    return true;
}

inline void xml::_string_15_5(const char * data, unsigned len, bool isFirst)
{
    if (isFirst)
        xmlResult::value.clear();
    else if ((xmlResult::value.length() + len) > 256)
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
    bool isFirstData = !state.eatSymCount;
    const char * beginData = state.data;
    while(state.data < state.end)
    {
        unsigned exitCount = 0;
        if(&state.data[8] <= state.end)
        {
            if (exitSym[uint8_t(state.data[0])])
                exitCount = 0;
            else if (exitSym[uint8_t(state.data[1])])
                exitCount = 1;
            else if (exitSym[uint8_t(state.data[2])])
                exitCount = 2;
            else if (exitSym[uint8_t(state.data[3])])
                exitCount = 3;
            else if (exitSym[uint8_t(state.data[4])])
                exitCount = 4;
            else if (exitSym[uint8_t(state.data[5])])
                exitCount = 5;
            else if (exitSym[uint8_t(state.data[6])])
                exitCount = 6;
            else if (exitSym[uint8_t(state.data[7])])
                exitCount = 7;
            else
            {
                state.data += 8;
                continue;
            }
        }
        else if (!exitSym[uint8_t(state.data[0])])
        {
            state.data++;
            continue;
        }
        state.data += exitCount;
        _string_15_5(beginData, unsigned(state.data - beginData), isFirstData);
        state.node = node_t::RANGE_15_6;
        bool ret = (state.node == node_t::RANGE_15_6);
        state.eatSymCount = 0;
        return ret;
    }
    state.eatSymCount += unsigned(state.data - beginData);
    if (beginData < state.data)
        _string_15_5(beginData, unsigned(state.data - beginData), isFirstData);
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
    while(state.data < state.end)
    {
        unsigned stateDataCount = 1;
        for(unsigned i = 0; i < stateDataCount; i++)
            if (exitSym[uint8_t(state.data[i])])
            {
                state.data += i;
                state.eatSymCount += i;
                state.node = (state.eatSymCount >= 1) ? node_t::NOTIFY_15_7 : node_t::NO_STATE;
                bool ret = (state.node == node_t::NOTIFY_15_7);
                state.eatSymCount = 0;
                return ret;
            }
        state.data += stateDataCount;
        state.node = node_t::NOTIFY_15_7;
        return true;
    }
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
    while(state.data < state.end)
    {
        unsigned exitCount = 0;
        if(&state.data[8] <= state.end)
        {
            if (exitSym[uint8_t(state.data[0])])
                exitCount = 0;
            else if (exitSym[uint8_t(state.data[1])])
                exitCount = 1;
            else if (exitSym[uint8_t(state.data[2])])
                exitCount = 2;
            else if (exitSym[uint8_t(state.data[3])])
                exitCount = 3;
            else if (exitSym[uint8_t(state.data[4])])
                exitCount = 4;
            else if (exitSym[uint8_t(state.data[5])])
                exitCount = 5;
            else if (exitSym[uint8_t(state.data[6])])
                exitCount = 6;
            else if (exitSym[uint8_t(state.data[7])])
                exitCount = 7;
            else
            {
                state.data += 8;
                continue;
            }
        }
        else if (!exitSym[uint8_t(state.data[0])])
        {
            state.data++;
            continue;
        }
        state.data += exitCount;
        state.node = node_t::LOOP_12_3;
        bool ret = (state.node == node_t::LOOP_12_3);
        state.eatSymCount = 0;
        return ret;
    }
    state.eatSymCount += unsigned(state.data - beginData);
    state.node = node_t::RANGE_15_8;
    return true;
}

inline bool xml::loop_17_0(state_t & state)
{
    return uint_17_0(state);
}

inline void xml::_uint_17_0(const char * data, unsigned len, bool isFirst)
{
    if (isFirst)
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
    bool isFirstData = !state.eatSymCount;
    const char * beginData = state.data;
    while(state.data < state.end)
    {
        unsigned exitCount = 0;
        if(&state.data[8] <= state.end)
        {
            if (exitSym[uint8_t(state.data[0])])
                exitCount = 0;
            else if (exitSym[uint8_t(state.data[1])])
                exitCount = 1;
            else if (exitSym[uint8_t(state.data[2])])
                exitCount = 2;
            else if (exitSym[uint8_t(state.data[3])])
                exitCount = 3;
            else if (exitSym[uint8_t(state.data[4])])
                exitCount = 4;
            else if (exitSym[uint8_t(state.data[5])])
                exitCount = 5;
            else if (exitSym[uint8_t(state.data[6])])
                exitCount = 6;
            else if (exitSym[uint8_t(state.data[7])])
                exitCount = 7;
            else
            {
                state.data += 8;
                continue;
            }
        }
        else if (!exitSym[uint8_t(state.data[0])])
        {
            state.data++;
            continue;
        }
        state.data += exitCount;
        _uint_17_0(beginData, unsigned(state.data - beginData), isFirstData);
        state.eatSymCount += unsigned(state.data - beginData);
        state.node = (state.eatSymCount >= 1) ? node_t::LOOP_17_0 : node_t::NO_STATE;
        bool ret = (state.node == node_t::LOOP_17_0);
        state.eatSymCount = 0;
        return ret;
    }
    state.eatSymCount += unsigned(state.data - beginData);
    if (beginData < state.data)
        _uint_17_0(beginData, unsigned(state.data - beginData), isFirstData);
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
        case LOOP_1_0: return "LOOP_1_0";
        case LABEL_1_0: return "LABEL_1_0";
        case LOOP_1_1: return "LOOP_1_1";
        case RANGE_2_0: return "RANGE_2_0";
        case RANGE_3_0: return "RANGE_3_0";
        case TEXT_4_0: return "TEXT_4_0";
        case GOTO_4_1: return "GOTO_4_1";
        case RANGE_5_0: return "RANGE_5_0";
        case LOOP_7_0: return "LOOP_7_0";
        case LABEL_7_0: return "LABEL_7_0";
        case LOOP_7_1: return "LOOP_7_1";
        case TEXT_8_0: return "TEXT_8_0";
        case LOOP_8_1: return "LOOP_8_1";
        case TEXT_9_0: return "TEXT_9_0";
        case RET_9_1: return "RET_9_1";
        case RANGE_10_0: return "RANGE_10_0";
        case TEXT_11_0: return "TEXT_11_0";
        case STRING_11_1: return "STRING_11_1";
        case RANGE_11_2: return "RANGE_11_2";
        case FUNC_11_3: return "FUNC_11_3";
        case NOTIFY_11_4: return "NOTIFY_11_4";
        case RET_11_5: return "RET_11_5";
        case STRING_12_0: return "STRING_12_0";
        case FUNC_12_1: return "FUNC_12_1";
        case RANGE_12_2: return "RANGE_12_2";
        case LOOP_12_3: return "LOOP_12_3";
        case TEXT_13_0: return "TEXT_13_0";
        case RET_13_1: return "RET_13_1";
        case RANGE_14_0: return "RANGE_14_0";
        case TEXT_14_1: return "TEXT_14_1";
        case FUNC_14_2: return "FUNC_14_2";
        case NOTIFY_14_3: return "NOTIFY_14_3";
        case RET_14_4: return "RET_14_4";
        case STRING_15_0: return "STRING_15_0";
        case RANGE_15_1: return "RANGE_15_1";
        case TEXT_15_2: return "TEXT_15_2";
        case RANGE_15_3: return "RANGE_15_3";
        case RANGE_15_4: return "RANGE_15_4";
        case STRING_15_5: return "STRING_15_5";
        case RANGE_15_6: return "RANGE_15_6";
        case NOTIFY_15_7: return "NOTIFY_15_7";
        case RANGE_15_8: return "RANGE_15_8";
        case LOOP_17_0: return "LOOP_17_0";
        case UINT_17_0: return "UINT_17_0";
        case NO_STATE: return "NO_STATE";
        default: return "unknown";
    };
}

