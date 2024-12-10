// ==============================================================
// Date: 2024-08-17 12:08:56 GMT
// Generated using vProto(2024.08.17)         https://www.vsyn.ru
// Author: Sergey V. Shchekoldin     Email: shchekoldin@gmail.com
// ==============================================================

#ifndef XML_H
#define XML_H
#pragma once

#include <string>
#include <vector>
#include <cstdint>

struct xmlResult
{
    std::string key;
    std::string tag;
    std::string value;
    uint32_t opend = 0;

    // Don't forget to declare:
    void payload([[maybe_unused]] const char * data, [[maybe_unused]] unsigned len, [[maybe_unused]] bool isFirst, [[maybe_unused]] bool isLast);
    void finishTag();
    void getAttribute();
};

struct xml : xmlResult
{
    bool parse(const char * data, unsigned len);
    bool parse(const std::string & data) { return parse(data.data(), data.length()); }
    void reset();
    bool empty() const { return mainState.node == node_t::NO_STATE; }

private:
    enum class node_t
    {
        LOOP_1_0, // line_1
            LABEL_1_0, LOOP_1_1,
                RANGE_2_0, 
                RANGE_3_0, 
                TEXT_4_0, GOTO_4_1, 
                RANGE_5_0, 
        LOOP_7_0, // line_7
            LABEL_7_0, LOOP_7_1,
                TEXT_8_0, LOOP_8_1,
                    TEXT_9_0, RET_9_1, 
                 // catch:
                    RANGE_10_0, 
                TEXT_11_0, STRING_11_1, RANGE_11_2, FUNC_11_3, NOTIFY_11_4, RET_11_5, 
                STRING_12_0, FUNC_12_1, RANGE_12_2, LOOP_12_3,
                    TEXT_13_0, RET_13_1, 
                    RANGE_14_0, TEXT_14_1, FUNC_14_2, NOTIFY_14_3, RET_14_4, 
                    STRING_15_0, RANGE_15_1, TEXT_15_2, RANGE_15_3, RANGE_15_4, STRING_15_5, RANGE_15_6, NOTIFY_15_7, RANGE_15_8, 
        LOOP_17_0, // line_17
            UINT_17_0, 
        NO_STATE
    };
    struct state_t
    {
        const char * data = nullptr;
        const char * end = nullptr;
        uint64_t consumed = 0;
        node_t node = node_t::LOOP_1_0;
        unsigned retStackCount = 0;
        node_t retStack[2];

        unsigned remainDataLen() const { return (unsigned)(end - data); }
        const char * name() const;
    };
    state_t mainState;

    void parse(state_t & state);
    bool loop_1_0(state_t & state);
    bool label_1_0(state_t & state);
    bool loop_1_1(state_t & state);
    bool range_2_0(state_t & state);
    bool range_3_0(state_t & state);
    bool text_4_0(state_t & state);
    bool goto_4_1(state_t & state);
    bool range_5_0(state_t & state);
    bool loop_7_0(state_t & state);
    bool label_7_0(state_t & state);
    bool loop_7_1(state_t & state);
    bool text_8_0(state_t & state, bool isCaseCall);
    bool loop_8_1(state_t & state);
    bool text_9_0(state_t & state, bool isCaseCall);
    bool ret_9_1(state_t & state);
    bool range_10_0(state_t & state);
    bool text_11_0(state_t & state);
    bool string_11_1(state_t & state);
    void _string_11_1(const char * data, unsigned len, uint64_t consumed);
    bool range_11_2(state_t & state);
    bool func_11_3(state_t & state);
    bool _func_11_3();
    bool notify_11_4(state_t & state);
    bool ret_11_5(state_t & state);
    bool string_12_0(state_t & state);
    void _string_12_0(const char * data, unsigned len, uint64_t consumed);
    bool func_12_1(state_t & state);
    bool _func_12_1();
    bool range_12_2(state_t & state);
    bool loop_12_3(state_t & state);
    bool text_13_0(state_t & state);
    bool ret_13_1(state_t & state);
    bool range_14_0(state_t & state);
    bool text_14_1(state_t & state);
    bool func_14_2(state_t & state);
    bool _func_14_2();
    bool notify_14_3(state_t & state);
    bool ret_14_4(state_t & state);
    bool string_15_0(state_t & state);
    void _string_15_0(const char * data, unsigned len, uint64_t consumed);
    bool range_15_1(state_t & state);
    bool text_15_2(state_t & state);
    bool range_15_3(state_t & state);
    bool range_15_4(state_t & state);
    bool string_15_5(state_t & state);
    void _string_15_5(const char * data, unsigned len, uint64_t consumed);
    bool range_15_6(state_t & state);
    bool notify_15_7(state_t & state);
    bool range_15_8(state_t & state);
    bool loop_17_0(state_t & state);
    bool uint_17_0(state_t & state);
    void _uint_17_0(const char * data, unsigned len, uint64_t consumed);
};
#endif
