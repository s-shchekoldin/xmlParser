// ==============================================================
// Date: 2026-01-28 20:26:22 GMT
// Generated using vProto(2026.01.28)        https://www.cgen.dev
// Author: Sergey V. Shchekoldin     Email: shchekoldin@gmail.com
// ==============================================================

#ifndef XML_H
#define XML_H
#pragma once

#include <array>
#include <cstdint>
#include <cstdio>
#include <string>

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
    template<class... Args> explicit xml(Args && ... args) : xmlResult(std::forward<Args>(args)...) {}
    bool parse(const char * data, unsigned len);
    bool parse(const std::string & data) { return parse(data.data(), data.length()); }
    bool empty() const { return mstate.node == NodeT::NoState; }
    void reset();

private:
    enum class NodeT
    {
        Loop1_0, // line_1
            Label1_0, Loop1_1,
                Range2_0,
                Range3_0,
                Text4_0, Call4_1,
                Range5_0,
        Loop7_0, // line_7
            Label7_0, Loop7_1,
                Text8_0, Loop8_1,
                    Text9_0, Ret9_1,
                 // catch:
                    Range10_0,
                Text11_0, String11_1, Range11_2, Func11_3, Notify11_4, Ret11_5,
                String12_0, Func12_1, Range12_2, Loop12_3,
                    Text13_0, Ret13_1,
                    Range14_0, Text14_1, Func14_2, Notify14_3, Ret14_4,
                    String15_0, Range15_1, Text15_2, Range15_3, Range15_4, String15_5, Range15_6, Notify15_7, Range15_8,
        Loop17_0, // line_17
            Uint17_0,
        NoState
    };
    struct StateT
    {
        const char * data = nullptr;
        const char * end = nullptr;
        uint64_t consumed = 0;
        NodeT node = NodeT::Loop1_0;
        unsigned rcount = 0;
        std::array<NodeT, 2> rstack;
        unsigned remain() const { return unsigned(end - data); }
        const char * name() const;
    };
    StateT mstate;

    void parse(StateT & state);
    bool loop1_0(StateT & state) const;
    bool label1_0(StateT & state) const;
    bool loop1_1(StateT & state);
    bool range2_0(StateT & state) const;
    bool range3_0(StateT & state) const;
    bool text4_0(StateT & state) const;
    bool call4_1(StateT & state) const;
    bool range5_0(StateT & state);
    bool loop7_0(StateT & state) const;
    bool label7_0(StateT & state) const;
    bool loop7_1(StateT & state);
    bool text8_0(StateT & state, bool is_branch) const;
    bool loop8_1(StateT & state) const;
    bool text9_0(StateT & state, bool is_branch) const;
    bool ret9_1(StateT & state) const;
    bool range10_0(StateT & state) const;
    bool text11_0(StateT & state) const;
    bool string11_1(StateT & state);
    void string11_1(const char * data, unsigned len, uint64_t consumed);
    bool range11_2(StateT & state) const;
    bool func11_3(StateT & state);
    bool func11_3();
    bool notify11_4(StateT & state);
    bool ret11_5(StateT & state) const;
    bool string12_0(StateT & state);
    void string12_0(const char * data, unsigned len, uint64_t consumed);
    bool func12_1(StateT & state);
    bool func12_1();
    bool range12_2(StateT & state) const;
    bool loop12_3(StateT & state);
    bool text13_0(StateT & state) const;
    bool ret13_1(StateT & state) const;
    bool range14_0(StateT & state) const;
    bool text14_1(StateT & state) const;
    bool func14_2(StateT & state);
    bool func14_2();
    bool notify14_3(StateT & state);
    bool ret14_4(StateT & state) const;
    bool string15_0(StateT & state);
    void string15_0(const char * data, unsigned len, uint64_t consumed);
    bool range15_1(StateT & state) const;
    bool text15_2(StateT & state) const;
    bool range15_3(StateT & state) const;
    bool range15_4(StateT & state) const;
    bool string15_5(StateT & state);
    void string15_5(const char * data, unsigned len, uint64_t consumed);
    bool range15_6(StateT & state) const;
    bool notify15_7(StateT & state);
    bool range15_8(StateT & state) const;
    bool loop17_0(StateT & state);
    bool uint17_0(StateT & state);
    void uint17_0(const char * data, unsigned len, uint64_t consumed);
};
#endif
