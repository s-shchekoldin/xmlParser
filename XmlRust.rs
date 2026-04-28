// ==============================================================
// Date: 2026-04-28 17:05:32 GMT
// Generated using vProto(2026.04.28)        https://www.cgen.dev
// Author: Sergey V. Shchekoldin     Email: shchekoldin@gmail.com
// ==============================================================

// Example usage:
// let mut m = crate::XmlRust::XmlRust::<XmlRust::XmlRustExample>::new();
// m.parse(&byte_slice);
// Also, you can redefine XmlRustTrait implementation for interacting with the XmlRust module.


#[cfg(target_arch = "x86_64")]
use std::arch::x86_64::*;

#[derive(Debug, PartialEq, Eq, Copy, Clone)]
#[allow(dead_code)]
enum NodeT {
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
}
impl std::fmt::Display for NodeT {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(f, "{:?}", self)
    }
}

#[derive(Debug, Copy, Clone)]
pub struct StateT {
    node: NodeT,
    left: usize,
    right: usize,
    consumed: usize,
    rcount: usize,
    rstack: [NodeT; 2],
}
impl StateT {
    pub fn new() -> Self { Self{ node: NodeT::Loop1_0, left: 0, right: 0, consumed: 0, rcount: 0, rstack: [NodeT::NoState; 2] } }
    pub fn remain(&self) -> usize { self.right - self.left }
}
impl std::fmt::Display for StateT {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(f, "{} remain:{}({}->{}) consumed:{}", self.node, self.remain(), self.left, self.right, self.consumed)
    }
}

#[allow(unreachable_code)]
pub trait XmlRustTrait {
    fn new() -> Self;

    // field accessors:
    fn key(&mut self) -> &mut String;
    fn opend(&mut self) -> &mut u32;
    fn tag(&mut self) -> &mut String;
    fn value(&mut self) -> &mut String;

    // callbacks to be implemented by the user:
    fn payload(&mut self, data: &[u8], is_first: bool, is_last: bool) { println!("payload({}:{})={:X?}", is_first, is_last, data); }
    fn finishTag(&mut self) { println!("Notify::finishTag"); }
    fn getAttribute(&mut self) { println!("Notify::getAttribute"); }

    // private functions:
    fn _func11_3(&mut self) -> bool {  let tmp = *self.opend(); *self.opend() -= 1; return tmp > 0;  return true; }
    fn _func12_1(&mut self) -> bool {  *self.opend() += 1;  return true; }
    fn _func14_2(&mut self) -> bool {  let tmp = *self.opend(); *self.opend() -= 1; return tmp > 0;  return true; }
}

pub struct XmlRustExample
{
    key: String,
    tag: String,
    value: String,
    opend: u32
}
#[allow(dead_code)]
impl XmlRustTrait for XmlRustExample {
    fn new() -> Self { Self{key: String::new(), tag: String::new(), value: String::new(), opend: 0} }
    fn key(&mut self) -> &mut String { &mut self.key }
    fn opend(&mut self) -> &mut u32 { &mut self.opend }
    fn tag(&mut self) -> &mut String { &mut self.tag }
    fn value(&mut self) -> &mut String { &mut self.value }
}

pub struct XmlRust <T> {
    output: T,
    vstate: Vec<StateT>
}
#[allow(dead_code)]
#[allow(unused_variables)]
impl <T: XmlRustTrait> XmlRust<T> {
    pub fn new() -> Self { Self{ output: T::new(), vstate: vec![StateT::new()] } }
    pub fn empty(&self) -> bool { self.vstate.is_empty() }
    pub fn reset(&mut self) {
        *self.output.key()= String::new();
        *self.output.opend() = 0;
        *self.output.tag()= String::new();
        *self.output.value()= String::new();
        for v in & mut self.vstate {
            v.node = NodeT::NoState;
        }
        self.vstate.push(StateT::new());
    }
    pub fn parse(&mut self, data : &[u8]) -> bool {
        for v in & mut self.vstate {
            v.left = 0;
            v.right = data.len();
        }
        let mut reparse = true;
        while reparse {
            reparse = false;
            let mut d_flow = 0;
            let mut s_flow = 0;
            while s_flow < self.vstate.len() {
                if self.vstate[s_flow].node == NodeT::NoState {
                    s_flow += 1;
                } else if self.vstate[s_flow].remain() == 0 {
                    if s_flow != d_flow {
                        self.vstate[d_flow] = self.vstate[s_flow];
                    }
                    d_flow += 1;
                    s_flow += 1;
                } else {
                    reparse = true;
                    let mut state = self.vstate[s_flow];
                    self.parse_s(&mut state, data);
                    if state.node != NodeT::NoState {
                        self.vstate[d_flow] = state;
                        d_flow += 1;
                    }
                    s_flow += 1;
                }
            } // while
            if d_flow < self.vstate.len() {
                self.vstate.resize(d_flow, StateT::new());
            }
        }
        return !self.empty();
    }
    fn parse_s(&mut self, state: &mut StateT, data: &[u8]) {
        loop {
            if cfg!(debug_assertions) {
                println!("State: {} data: [{:#04X}, {:#04X}, {:#04X}, {:#04X}, {:#04X}]", state.node,
                    if state.remain() > 0 { data[state.left+0] } else { 0 },
                    if state.remain() > 1 { data[state.left+1] } else { 0 },
                    if state.remain() > 2 { data[state.left+2] } else { 0 },
                    if state.remain() > 3 { data[state.left+3] } else { 0 },
                    if state.remain() > 4 { data[state.left+4] } else { 0 });
            }
            let n = state.node;
            let d = state.left;
            match state.node {
                NodeT::Loop1_0 => { self.loop1_0(state, data); }
                NodeT::Label1_0 => { self.label1_0(state, data); }
                NodeT::Loop1_1 => { self.loop1_1(state, data); }
                NodeT::Range2_0 => { self.range2_0(state, data); }
                NodeT::Range3_0 => { self.range3_0(state, data); }
                NodeT::Text4_0 => { self.text4_0(state, data); }
                NodeT::Call4_1 => { self.call4_1(state, data); }
                NodeT::Range5_0 => { self.range5_0(state, data); }
                NodeT::Loop7_0 => { self.loop7_0(state, data); }
                NodeT::Label7_0 => { self.label7_0(state, data); }
                NodeT::Loop7_1 => { self.loop7_1(state, data); }
                NodeT::Text8_0 => { self.text8_0(state, data, false); }
                NodeT::Loop8_1 => { self.loop8_1(state, data); }
                NodeT::Text9_0 => { self.text9_0(state, data, false); }
                NodeT::Ret9_1 => { self.ret9_1(state, data); }
                NodeT::Range10_0 => { self.range10_0(state, data); }
                NodeT::Text11_0 => { self.text11_0(state, data); }
                NodeT::String11_1 => { self.string11_1(state, data); }
                NodeT::Range11_2 => { self.range11_2(state, data); }
                NodeT::Func11_3 => { self.func11_3(state, data); }
                NodeT::Notify11_4 => { self.notify11_4(state, data); }
                NodeT::Ret11_5 => { self.ret11_5(state, data); }
                NodeT::String12_0 => { self.string12_0(state, data); }
                NodeT::Func12_1 => { self.func12_1(state, data); }
                NodeT::Range12_2 => { self.range12_2(state, data); }
                NodeT::Loop12_3 => { self.loop12_3(state, data); }
                NodeT::Text13_0 => { self.text13_0(state, data); }
                NodeT::Ret13_1 => { self.ret13_1(state, data); }
                NodeT::Range14_0 => { self.range14_0(state, data); }
                NodeT::Text14_1 => { self.text14_1(state, data); }
                NodeT::Func14_2 => { self.func14_2(state, data); }
                NodeT::Notify14_3 => { self.notify14_3(state, data); }
                NodeT::Ret14_4 => { self.ret14_4(state, data); }
                NodeT::String15_0 => { self.string15_0(state, data); }
                NodeT::Range15_1 => { self.range15_1(state, data); }
                NodeT::Text15_2 => { self.text15_2(state, data); }
                NodeT::Range15_3 => { self.range15_3(state, data); }
                NodeT::Range15_4 => { self.range15_4(state, data); }
                NodeT::String15_5 => { self.string15_5(state, data); }
                NodeT::Range15_6 => { self.range15_6(state, data); }
                NodeT::Notify15_7 => { self.notify15_7(state, data); }
                NodeT::Range15_8 => { self.range15_8(state, data); }
                NodeT::Loop17_0 => { self.loop17_0(state, data); }
                NodeT::Uint17_0 => { self.uint17_0(state, data); }
                NodeT::NoState => { break; }
            }; // match
            if d == state.left && n == state.node {
                break;
            }
        } // loop
    }
    fn loop1_0(&mut self, state: &mut StateT, data: &[u8]) -> bool {
        return self.label1_0(state, data);
    }
    fn label1_0(&mut self, state: &mut StateT, data: &[u8]) -> bool {
        state.node = NodeT::Loop1_1;
        return true;
    }
    fn loop1_1(&mut self, state: &mut StateT, data: &[u8]) -> bool {
        if state.left == state.right {
            return true;
        }
        if self.range2_0(state, data) { // case_1
            return true;
        }
        if self.range3_0(state, data) { // case_2
            return true;
        }
        if self.text4_0(state, data) { // case_3
            return true;
        }
        if self.range5_0(state, data) { // case_4
            return true;
        }
        state.node = NodeT::NoState;
        return true;
    }
    fn range2_0(&mut self, state: &mut StateT, data: &[u8]) -> bool {
        static TERMINATOR:[bool;256] = [
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
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true]; // [0xa][0xd]
        let datastart = state.left;
        while state.left < state.right {
            if (state.left + 8) <= state.right {
                if TERMINATOR[usize::from(data[state.left])] {
                    state.left += 0;
                }
                else if TERMINATOR[usize::from(data[state.left + 1])] {
                    state.left += 1;
                }
                else if TERMINATOR[usize::from(data[state.left + 2])] {
                    state.left += 2;
                }
                else if TERMINATOR[usize::from(data[state.left + 3])] {
                    state.left += 3;
                }
                else if TERMINATOR[usize::from(data[state.left + 4])] {
                    state.left += 4;
                }
                else if TERMINATOR[usize::from(data[state.left + 5])] {
                    state.left += 5;
                }
                else if TERMINATOR[usize::from(data[state.left + 6])] {
                    state.left += 6;
                }
                else if TERMINATOR[usize::from(data[state.left + 7])] {
                    state.left += 7;
                }
                else
                {
                    state.left += 8;
                    continue;
                }
            }
            else if !(TERMINATOR[usize::from(data[state.left])]) {
                state.left += 1;
                continue;
            }
            let total = state.consumed + state.left - datastart;
            state.consumed = 0;
            if total >= 1 {
                state.node = NodeT::Loop1_1;
                return true;
            } else {
                state.node = NodeT::NoState;
                return false;
            }
        }
        state.consumed += state.left - datastart;
        state.node = NodeT::Range2_0;
        return true;
    }
    fn range3_0(&mut self, state: &mut StateT, data: &[u8]) -> bool {
        static TERMINATOR:[bool;256] = [
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
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true]; // [0x9][0x20]
        let datastart = state.left;
        while state.left < state.right {
            if (state.left + 8) <= state.right {
                if TERMINATOR[usize::from(data[state.left])] {
                    state.left += 0;
                }
                else if TERMINATOR[usize::from(data[state.left + 1])] {
                    state.left += 1;
                }
                else if TERMINATOR[usize::from(data[state.left + 2])] {
                    state.left += 2;
                }
                else if TERMINATOR[usize::from(data[state.left + 3])] {
                    state.left += 3;
                }
                else if TERMINATOR[usize::from(data[state.left + 4])] {
                    state.left += 4;
                }
                else if TERMINATOR[usize::from(data[state.left + 5])] {
                    state.left += 5;
                }
                else if TERMINATOR[usize::from(data[state.left + 6])] {
                    state.left += 6;
                }
                else if TERMINATOR[usize::from(data[state.left + 7])] {
                    state.left += 7;
                }
                else
                {
                    state.left += 8;
                    continue;
                }
            }
            else if !(TERMINATOR[usize::from(data[state.left])]) {
                state.left += 1;
                continue;
            }
            let total = state.consumed + state.left - datastart;
            state.consumed = 0;
            if total >= 1 {
                state.node = NodeT::Loop1_1;
                return true;
            } else {
                state.node = NodeT::NoState;
                return false;
            }
        }
        state.consumed += state.left - datastart;
        state.node = NodeT::Range3_0;
        return true;
    }
    fn text4_0(&mut self, state: &mut StateT, data: &[u8]) -> bool {
        if state.left < state.right {
            if 0x3C != data[state.left] {
                state.node = NodeT::NoState;
                return false;
            } else {
                state.left += 1;
                state.node = NodeT::Call4_1;
                return true;
            }
        }
        state.node = NodeT::Text4_0;
        return true;
    }
    fn call4_1(&mut self, state: &mut StateT, data: &[u8]) -> bool {
        state.node = NodeT::Label7_0;
        let rlen = state.rstack.len();
        if state.rcount < rlen {
            let rcount = state.rcount;
            state.rstack[rcount] = NodeT::Loop1_1;
            state.rcount = state.rcount + 1;
        } else {
            for i in 1 .. rlen {
                state.rstack[i - 1] = state.rstack[i];
            }
            state.rstack[rlen - 1] = NodeT::Loop1_1;
        }
        return true;
    }
    fn range5_0(&mut self, state: &mut StateT, data: &[u8]) -> bool {
        let datastart = state.left;
        while state.left < state.right {
            if (state.left + 8) <= state.right {
                if data[state.left] == 0x3c {
                    state.left += 0;
                }
                else if data[state.left + 1] == 0x3c {
                    state.left += 1;
                }
                else if data[state.left + 2] == 0x3c {
                    state.left += 2;
                }
                else if data[state.left + 3] == 0x3c {
                    state.left += 3;
                }
                else if data[state.left + 4] == 0x3c {
                    state.left += 4;
                }
                else if data[state.left + 5] == 0x3c {
                    state.left += 5;
                }
                else if data[state.left + 6] == 0x3c {
                    state.left += 6;
                }
                else if data[state.left + 7] == 0x3c {
                    state.left += 7;
                }
                else
                {
                    state.left += 8;
                    continue;
                }
            }
            else if !(data[state.left] == 0x3c) {
                state.left += 1;
                continue;
            }
            let left = state.left;
            self.output.payload(&data[datastart .. left], state.consumed == 0, true);
            let total = state.consumed + state.left - datastart;
            state.consumed = 0;
            if total >= 1 {
                state.node = NodeT::Loop1_1;
                return true;
            } else {
                state.node = NodeT::NoState;
                return false;
            }
        }
        if datastart < state.left {
            let left = state.left;
            self.output.payload(&data[datastart .. left], state.consumed == 0, false);
        }
        state.consumed += state.left - datastart;
        state.node = NodeT::Range5_0;
        return true;
    }
    fn loop7_0(&mut self, state: &mut StateT, data: &[u8]) -> bool {
        return self.label7_0(state, data);
    }
    fn label7_0(&mut self, state: &mut StateT, data: &[u8]) -> bool {
        state.node = NodeT::Loop7_1;
        return true;
    }
    fn loop7_1(&mut self, state: &mut StateT, data: &[u8]) -> bool {
        if state.left == state.right {
            return true;
        }
        if self.text8_0(state, data, true) { // case_1
            return true;
        }
        if self.text11_0(state, data) { // case_2
            return true;
        }
        if self.string12_0(state, data) { // case_3
            return true;
        }
        state.node = NodeT::NoState;
        return true;
    }
    fn text8_0(&mut self, state: &mut StateT, data: &[u8], is_branch: bool) -> bool {
        static TEXT:[u8;3] = [0x21, 0x2d, 0x2d]; // !--
        while state.left < state.right {
            if TEXT[state.consumed] != data[state.left] {
                state.node = NodeT::NoState;
                let ret = is_branch && state.consumed != 0;
                state.consumed = 0;
                return ret;
            }
            else if {state.consumed += 1; state.consumed >= TEXT.len()} {
                state.left += 1;
                state.consumed = 0;
                state.node = NodeT::Loop8_1;
                return true;
            }
            state.left += 1;
        }
        state.node = NodeT::Text8_0;
        return true;
    }
    fn loop8_1(&mut self, state: &mut StateT, data: &[u8]) -> bool {
        if state.left == state.right {
            return true;
        }
        if self.text9_0(state, data, true) { // case_1
            return true;
        }
        state.node = NodeT::Range10_0;
        return true;
    }
    fn text9_0(&mut self, state: &mut StateT, data: &[u8], is_branch: bool) -> bool {
        static TEXT:[u8;3] = [0x2d, 0x2d, 0x3e]; // -->
        while state.left < state.right {
            if TEXT[state.consumed] != data[state.left] {
                state.node = NodeT::Range10_0;
                let ret = is_branch && state.consumed != 0;
                state.consumed = 0;
                return ret;
            }
            else if {state.consumed += 1; state.consumed >= TEXT.len()} {
                state.left += 1;
                state.consumed = 0;
                state.node = NodeT::Ret9_1;
                return true;
            }
            state.left += 1;
        }
        state.node = NodeT::Text9_0;
        return true;
    }
    fn ret9_1(&mut self, state: &mut StateT, data: &[u8]) -> bool {
        if state.rcount > 0 {
            state.rcount = state.rcount - 1;
            state.node = state.rstack[state.rcount]
        } else {
            state.node = NodeT::NoState;
        }
        return state.node != NodeT::NoState;
    }
    fn range10_0(&mut self, state: &mut StateT, data: &[u8]) -> bool {
        let datastart = state.left;
        while state.left < state.right {
            if (state.left + 8) <= state.right {
                if data[state.left] == 0x2d {
                    state.left += 0;
                }
                else if data[state.left + 1] == 0x2d {
                    state.left += 1;
                }
                else if data[state.left + 2] == 0x2d {
                    state.left += 2;
                }
                else if data[state.left + 3] == 0x2d {
                    state.left += 3;
                }
                else if data[state.left + 4] == 0x2d {
                    state.left += 4;
                }
                else if data[state.left + 5] == 0x2d {
                    state.left += 5;
                }
                else if data[state.left + 6] == 0x2d {
                    state.left += 6;
                }
                else if data[state.left + 7] == 0x2d {
                    state.left += 7;
                }
                else
                {
                    state.left += 8;
                    continue;
                }
            }
            else if !(data[state.left] == 0x2d) {
                state.left += 1;
                continue;
            }
            state.consumed = 0;
            state.node = NodeT::Loop8_1;
            return true;
        }
        state.consumed += state.left - datastart;
        state.node = NodeT::Range10_0;
        return true;
    }
    fn text11_0(&mut self, state: &mut StateT, data: &[u8]) -> bool {
        if state.left < state.right {
            if 0x2F != data[state.left] {
                state.node = NodeT::NoState;
                return false;
            } else {
                state.left += 1;
                state.node = NodeT::String11_1;
                return true;
            }
        }
        state.node = NodeT::Text11_0;
        return true;
    }
    fn _string11_1(&mut self, state: &mut StateT, data: &[u8]) {
        if state.consumed == 0 {
            self.output.tag().clear();
        }
        let len = if (self.output.tag().len() + data.len()) > 256 { 256 - self.output.tag().len() } else { data.len() };
        self.output.tag().push_str(&String::from_utf8_lossy(&data[0 .. len]));
    }
    fn string11_1(&mut self, state: &mut StateT, data: &[u8]) -> bool {
        let datastart = state.left;
        let is_avx2 = is_x86_feature_detected!("avx2");
        let is_sse2 = is_x86_feature_detected!("sse2");
        while state.left < state.right {
            if is_avx2 && (state.left + 32) <= state.right {
                unsafe {
                    let d = _mm256_lddqu_si256(data.as_ptr().add(state.left) as *const __m256i);
                    let m = _mm256_cmpeq_epi8(_mm256_set1_epi8(0x3e), d);
                    let r: u32 = _mm256_movemask_epi8(m) as u32;
                    if r > 0 {
                        state.left += r.trailing_zeros() as usize;
                    } else {
                        state.left += 32;
                        continue;
                    }
                }
            }
            else if is_sse2 && (state.left + 16) <= state.right {
                unsafe {
                    let d = _mm_loadu_si128(data.as_ptr().add(state.left) as *const __m128i);
                    let m = _mm_cmpeq_epi8(_mm_set1_epi8(0x3e), d);
                    let r: u16 = _mm_movemask_epi8(m) as u16;
                    if r > 0 {
                        state.left += r.trailing_zeros() as usize;
                    } else {
                        state.left += 16;
                        continue;
                    }
                }
            }
            else if (state.left + 8) <= state.right {
                if data[state.left] == 0x3e {
                    state.left += 0;
                }
                else if data[state.left + 1] == 0x3e {
                    state.left += 1;
                }
                else if data[state.left + 2] == 0x3e {
                    state.left += 2;
                }
                else if data[state.left + 3] == 0x3e {
                    state.left += 3;
                }
                else if data[state.left + 4] == 0x3e {
                    state.left += 4;
                }
                else if data[state.left + 5] == 0x3e {
                    state.left += 5;
                }
                else if data[state.left + 6] == 0x3e {
                    state.left += 6;
                }
                else if data[state.left + 7] == 0x3e {
                    state.left += 7;
                }
                else
                {
                    state.left += 8;
                    continue;
                }
            }
            else if !(data[state.left] == 0x3e) {
                state.left += 1;
                continue;
            }
            let left = state.left;
            self._string11_1(state, &data[datastart .. left]);
            let total = state.consumed + state.left - datastart;
            state.consumed = 0;
            if total >= 1 {
                state.node = NodeT::Range11_2;
                return true;
            } else {
                state.node = NodeT::NoState;
                return false;
            }
        }
        if datastart < state.left {
            let left = state.left;
            self._string11_1(state, &data[datastart .. left]);
        }
        state.consumed += state.left - datastart;
        state.node = NodeT::String11_1;
        return true;
    }
    fn range11_2(&mut self, state: &mut StateT, data: &[u8]) -> bool {
        let datastart = state.left;
        while state.left < state.right {
            if data[state.left] != 0x3e {
                state.consumed += state.left - datastart;
                state.node = if state.consumed >= 1 { NodeT::Func11_3 } else { NodeT::NoState };
                let ret = state.node == NodeT::Func11_3;
                state.consumed = 0;
                return ret;
            }
            state.left += 1;
            state.node = NodeT::Func11_3;
            return true;
        }
        state.consumed += state.left - datastart;
        state.node = NodeT::Range11_2;
        return true;
    }
    fn func11_3(&mut self, state: &mut StateT, data: &[u8]) -> bool {
        if self.output._func11_3() {
            state.node = NodeT::Notify11_4;
            return true;
        }
        state.node = NodeT::NoState;
        return false;
    }
    fn notify11_4(&mut self, state: &mut StateT, data: &[u8]) -> bool {
        self.output.finishTag();
        state.node = NodeT::Ret11_5;
        return true;
    }
    fn ret11_5(&mut self, state: &mut StateT, data: &[u8]) -> bool {
        if state.rcount > 0 {
            state.rcount = state.rcount - 1;
            state.node = state.rstack[state.rcount]
        } else {
            state.node = NodeT::NoState;
        }
        return state.node != NodeT::NoState;
    }
    fn _string12_0(&mut self, state: &mut StateT, data: &[u8]) {
        if state.consumed == 0 {
            self.output.tag().clear();
        }
        let len = if (self.output.tag().len() + data.len()) > 256 { 256 - self.output.tag().len() } else { data.len() };
        self.output.tag().push_str(&String::from_utf8_lossy(&data[0 .. len]));
    }
    fn string12_0(&mut self, state: &mut StateT, data: &[u8]) -> bool {
        static TERMINATOR:[bool;256] = [
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
            false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false]; // ^[0x9][0x20][0x3e]
        let datastart = state.left;
        while state.left < state.right {
            if (state.left + 8) <= state.right {
                if TERMINATOR[usize::from(data[state.left])] {
                    state.left += 0;
                }
                else if TERMINATOR[usize::from(data[state.left + 1])] {
                    state.left += 1;
                }
                else if TERMINATOR[usize::from(data[state.left + 2])] {
                    state.left += 2;
                }
                else if TERMINATOR[usize::from(data[state.left + 3])] {
                    state.left += 3;
                }
                else if TERMINATOR[usize::from(data[state.left + 4])] {
                    state.left += 4;
                }
                else if TERMINATOR[usize::from(data[state.left + 5])] {
                    state.left += 5;
                }
                else if TERMINATOR[usize::from(data[state.left + 6])] {
                    state.left += 6;
                }
                else if TERMINATOR[usize::from(data[state.left + 7])] {
                    state.left += 7;
                }
                else
                {
                    state.left += 8;
                    continue;
                }
            }
            else if !(TERMINATOR[usize::from(data[state.left])]) {
                state.left += 1;
                continue;
            }
            let left = state.left;
            self._string12_0(state, &data[datastart .. left]);
            let total = state.consumed + state.left - datastart;
            state.consumed = 0;
            if total >= 1 {
                state.node = NodeT::Func12_1;
                return true;
            } else {
                state.node = NodeT::NoState;
                return false;
            }
        }
        if datastart < state.left {
            let left = state.left;
            self._string12_0(state, &data[datastart .. left]);
        }
        state.consumed += state.left - datastart;
        state.node = NodeT::String12_0;
        return true;
    }
    fn func12_1(&mut self, state: &mut StateT, data: &[u8]) -> bool {
        if self.output._func12_1() {
            state.node = NodeT::Range12_2;
            return true;
        }
        state.node = NodeT::NoState;
        return false;
    }
    fn range12_2(&mut self, state: &mut StateT, data: &[u8]) -> bool {
        static TERMINATOR:[bool;256] = [
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
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true]; // [0x9][0x20]
        let datastart = state.left;
        while state.left < state.right {
            if (state.left + 8) <= state.right {
                if TERMINATOR[usize::from(data[state.left])] {
                    state.left += 0;
                }
                else if TERMINATOR[usize::from(data[state.left + 1])] {
                    state.left += 1;
                }
                else if TERMINATOR[usize::from(data[state.left + 2])] {
                    state.left += 2;
                }
                else if TERMINATOR[usize::from(data[state.left + 3])] {
                    state.left += 3;
                }
                else if TERMINATOR[usize::from(data[state.left + 4])] {
                    state.left += 4;
                }
                else if TERMINATOR[usize::from(data[state.left + 5])] {
                    state.left += 5;
                }
                else if TERMINATOR[usize::from(data[state.left + 6])] {
                    state.left += 6;
                }
                else if TERMINATOR[usize::from(data[state.left + 7])] {
                    state.left += 7;
                }
                else
                {
                    state.left += 8;
                    continue;
                }
            }
            else if !(TERMINATOR[usize::from(data[state.left])]) {
                state.left += 1;
                continue;
            }
            state.consumed = 0;
            state.node = NodeT::Loop12_3;
            return true;
        }
        state.consumed += state.left - datastart;
        state.node = NodeT::Range12_2;
        return true;
    }
    fn loop12_3(&mut self, state: &mut StateT, data: &[u8]) -> bool {
        if state.left == state.right {
            return true;
        }
        if self.text13_0(state, data) { // case_1
            return true;
        }
        if self.range14_0(state, data) { // case_2
            return true;
        }
        if self.string15_0(state, data) { // case_3
            return true;
        }
        state.node = NodeT::NoState;
        return true;
    }
    fn text13_0(&mut self, state: &mut StateT, data: &[u8]) -> bool {
        if state.left < state.right {
            if 0x3E != data[state.left] {
                state.node = NodeT::NoState;
                return false;
            } else {
                state.left += 1;
                state.node = NodeT::Ret13_1;
                return true;
            }
        }
        state.node = NodeT::Text13_0;
        return true;
    }
    fn ret13_1(&mut self, state: &mut StateT, data: &[u8]) -> bool {
        if state.rcount > 0 {
            state.rcount = state.rcount - 1;
            state.node = state.rstack[state.rcount]
        } else {
            state.node = NodeT::NoState;
        }
        return state.node != NodeT::NoState;
    }
    fn range14_0(&mut self, state: &mut StateT, data: &[u8]) -> bool {
        static TERMINATOR:[bool;256] = [
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
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true]; // [0x2f][0x3f]
        let datastart = state.left;
        while state.left < state.right {
            if TERMINATOR[usize::from(data[state.left])] {
                state.consumed += state.left - datastart;
                state.node = if state.consumed >= 1 { NodeT::Text14_1 } else { NodeT::NoState };
                let ret = state.node == NodeT::Text14_1;
                state.consumed = 0;
                return ret;
            }
            state.left += 1;
            state.node = NodeT::Text14_1;
            return true;
        }
        state.consumed += state.left - datastart;
        state.node = NodeT::Range14_0;
        return true;
    }
    fn text14_1(&mut self, state: &mut StateT, data: &[u8]) -> bool {
        if state.left < state.right {
            if 0x3E != data[state.left] {
                state.node = NodeT::NoState;
                return false;
            } else {
                state.left += 1;
                state.node = NodeT::Func14_2;
                return true;
            }
        }
        state.node = NodeT::Text14_1;
        return true;
    }
    fn func14_2(&mut self, state: &mut StateT, data: &[u8]) -> bool {
        if self.output._func14_2() {
            state.node = NodeT::Notify14_3;
            return true;
        }
        state.node = NodeT::NoState;
        return false;
    }
    fn notify14_3(&mut self, state: &mut StateT, data: &[u8]) -> bool {
        self.output.finishTag();
        state.node = NodeT::Ret14_4;
        return true;
    }
    fn ret14_4(&mut self, state: &mut StateT, data: &[u8]) -> bool {
        if state.rcount > 0 {
            state.rcount = state.rcount - 1;
            state.node = state.rstack[state.rcount]
        } else {
            state.node = NodeT::NoState;
        }
        return state.node != NodeT::NoState;
    }
    fn _string15_0(&mut self, state: &mut StateT, data: &[u8]) {
        if state.consumed == 0 {
            self.output.key().clear();
        }
        let len = if (self.output.key().len() + data.len()) > 256 { 256 - self.output.key().len() } else { data.len() };
        self.output.key().push_str(&String::from_utf8_lossy(&data[0 .. len]));
    }
    fn string15_0(&mut self, state: &mut StateT, data: &[u8]) -> bool {
        static TERMINATOR:[bool;256] = [
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
            false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false]; // ^[0x9][0x20][0x3d]
        let datastart = state.left;
        while state.left < state.right {
            if (state.left + 8) <= state.right {
                if TERMINATOR[usize::from(data[state.left])] {
                    state.left += 0;
                }
                else if TERMINATOR[usize::from(data[state.left + 1])] {
                    state.left += 1;
                }
                else if TERMINATOR[usize::from(data[state.left + 2])] {
                    state.left += 2;
                }
                else if TERMINATOR[usize::from(data[state.left + 3])] {
                    state.left += 3;
                }
                else if TERMINATOR[usize::from(data[state.left + 4])] {
                    state.left += 4;
                }
                else if TERMINATOR[usize::from(data[state.left + 5])] {
                    state.left += 5;
                }
                else if TERMINATOR[usize::from(data[state.left + 6])] {
                    state.left += 6;
                }
                else if TERMINATOR[usize::from(data[state.left + 7])] {
                    state.left += 7;
                }
                else
                {
                    state.left += 8;
                    continue;
                }
            }
            else if !(TERMINATOR[usize::from(data[state.left])]) {
                state.left += 1;
                continue;
            }
            let left = state.left;
            self._string15_0(state, &data[datastart .. left]);
            let total = state.consumed + state.left - datastart;
            state.consumed = 0;
            if total >= 1 {
                state.node = NodeT::Range15_1;
                return true;
            } else {
                state.node = NodeT::NoState;
                return false;
            }
        }
        if datastart < state.left {
            let left = state.left;
            self._string15_0(state, &data[datastart .. left]);
        }
        state.consumed += state.left - datastart;
        state.node = NodeT::String15_0;
        return true;
    }
    fn range15_1(&mut self, state: &mut StateT, data: &[u8]) -> bool {
        static TERMINATOR:[bool;256] = [
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
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true]; // [0x9][0x20]
        let datastart = state.left;
        while state.left < state.right {
            if (state.left + 8) <= state.right {
                if TERMINATOR[usize::from(data[state.left])] {
                    state.left += 0;
                }
                else if TERMINATOR[usize::from(data[state.left + 1])] {
                    state.left += 1;
                }
                else if TERMINATOR[usize::from(data[state.left + 2])] {
                    state.left += 2;
                }
                else if TERMINATOR[usize::from(data[state.left + 3])] {
                    state.left += 3;
                }
                else if TERMINATOR[usize::from(data[state.left + 4])] {
                    state.left += 4;
                }
                else if TERMINATOR[usize::from(data[state.left + 5])] {
                    state.left += 5;
                }
                else if TERMINATOR[usize::from(data[state.left + 6])] {
                    state.left += 6;
                }
                else if TERMINATOR[usize::from(data[state.left + 7])] {
                    state.left += 7;
                }
                else
                {
                    state.left += 8;
                    continue;
                }
            }
            else if !(TERMINATOR[usize::from(data[state.left])]) {
                state.left += 1;
                continue;
            }
            state.consumed = 0;
            state.node = NodeT::Text15_2;
            return true;
        }
        state.consumed += state.left - datastart;
        state.node = NodeT::Range15_1;
        return true;
    }
    fn text15_2(&mut self, state: &mut StateT, data: &[u8]) -> bool {
        if state.left < state.right {
            if 0x3D != data[state.left] {
                state.node = NodeT::NoState;
                return false;
            } else {
                state.left += 1;
                state.node = NodeT::Range15_3;
                return true;
            }
        }
        state.node = NodeT::Text15_2;
        return true;
    }
    fn range15_3(&mut self, state: &mut StateT, data: &[u8]) -> bool {
        static TERMINATOR:[bool;256] = [
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
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true]; // [0x9][0x20]
        let datastart = state.left;
        while state.left < state.right {
            if (state.left + 8) <= state.right {
                if TERMINATOR[usize::from(data[state.left])] {
                    state.left += 0;
                }
                else if TERMINATOR[usize::from(data[state.left + 1])] {
                    state.left += 1;
                }
                else if TERMINATOR[usize::from(data[state.left + 2])] {
                    state.left += 2;
                }
                else if TERMINATOR[usize::from(data[state.left + 3])] {
                    state.left += 3;
                }
                else if TERMINATOR[usize::from(data[state.left + 4])] {
                    state.left += 4;
                }
                else if TERMINATOR[usize::from(data[state.left + 5])] {
                    state.left += 5;
                }
                else if TERMINATOR[usize::from(data[state.left + 6])] {
                    state.left += 6;
                }
                else if TERMINATOR[usize::from(data[state.left + 7])] {
                    state.left += 7;
                }
                else
                {
                    state.left += 8;
                    continue;
                }
            }
            else if !(TERMINATOR[usize::from(data[state.left])]) {
                state.left += 1;
                continue;
            }
            state.consumed = 0;
            state.node = NodeT::Range15_4;
            return true;
        }
        state.consumed += state.left - datastart;
        state.node = NodeT::Range15_3;
        return true;
    }
    fn range15_4(&mut self, state: &mut StateT, data: &[u8]) -> bool {
        static TERMINATOR:[bool;256] = [
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
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true]; // [0x22][0x27]
        let datastart = state.left;
        while state.left < state.right {
            if TERMINATOR[usize::from(data[state.left])] {
                state.consumed += state.left - datastart;
                state.node = if state.consumed >= 1 { NodeT::String15_5 } else { NodeT::NoState };
                let ret = state.node == NodeT::String15_5;
                state.consumed = 0;
                return ret;
            }
            state.left += 1;
            state.node = NodeT::String15_5;
            return true;
        }
        state.consumed += state.left - datastart;
        state.node = NodeT::Range15_4;
        return true;
    }
    fn _string15_5(&mut self, state: &mut StateT, data: &[u8]) {
        if state.consumed == 0 {
            self.output.value().clear();
        }
        let len = if (self.output.value().len() + data.len()) > 256 { 256 - self.output.value().len() } else { data.len() };
        self.output.value().push_str(&String::from_utf8_lossy(&data[0 .. len]));
    }
    fn string15_5(&mut self, state: &mut StateT, data: &[u8]) -> bool {
        static TERMINATOR:[bool;256] = [
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
            false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false]; // ^[0x22][0x27]
        let datastart = state.left;
        let is_avx2 = is_x86_feature_detected!("avx2");
        let is_sse2 = is_x86_feature_detected!("sse2");
        while state.left < state.right {
            if is_avx2 && (state.left + 32) <= state.right {
                unsafe {
                    let d = _mm256_lddqu_si256(data.as_ptr().add(state.left) as *const __m256i);
                    let mut m = _mm256_cmpeq_epi8(_mm256_set1_epi8(0x22), d);
                    m = _mm256_or_si256(m, _mm256_cmpeq_epi8(_mm256_set1_epi8(0x27), d));
                    let r: u32 = _mm256_movemask_epi8(m) as u32;
                    if r > 0 {
                        state.left += r.trailing_zeros() as usize;
                    } else {
                        state.left += 32;
                        continue;
                    }
                }
            }
            else if is_sse2 && (state.left + 16) <= state.right {
                unsafe {
                    let d = _mm_loadu_si128(data.as_ptr().add(state.left) as *const __m128i);
                    let mut m = _mm_cmpeq_epi8(_mm_set1_epi8(0x22), d);
                    m = _mm_or_si128(m, _mm_cmpeq_epi8(_mm_set1_epi8(0x27), d));
                    let r: u16 = _mm_movemask_epi8(m) as u16;
                    if r > 0 {
                        state.left += r.trailing_zeros() as usize;
                    } else {
                        state.left += 16;
                        continue;
                    }
                }
            }
            else if (state.left + 8) <= state.right {
                if TERMINATOR[usize::from(data[state.left])] {
                    state.left += 0;
                }
                else if TERMINATOR[usize::from(data[state.left + 1])] {
                    state.left += 1;
                }
                else if TERMINATOR[usize::from(data[state.left + 2])] {
                    state.left += 2;
                }
                else if TERMINATOR[usize::from(data[state.left + 3])] {
                    state.left += 3;
                }
                else if TERMINATOR[usize::from(data[state.left + 4])] {
                    state.left += 4;
                }
                else if TERMINATOR[usize::from(data[state.left + 5])] {
                    state.left += 5;
                }
                else if TERMINATOR[usize::from(data[state.left + 6])] {
                    state.left += 6;
                }
                else if TERMINATOR[usize::from(data[state.left + 7])] {
                    state.left += 7;
                }
                else
                {
                    state.left += 8;
                    continue;
                }
            }
            else if !(TERMINATOR[usize::from(data[state.left])]) {
                state.left += 1;
                continue;
            }
            let left = state.left;
            self._string15_5(state, &data[datastart .. left]);
            state.consumed = 0;
            state.node = NodeT::Range15_6;
            return true;
        }
        if datastart < state.left {
            let left = state.left;
            self._string15_5(state, &data[datastart .. left]);
        }
        state.consumed += state.left - datastart;
        state.node = NodeT::String15_5;
        return true;
    }
    fn range15_6(&mut self, state: &mut StateT, data: &[u8]) -> bool {
        static TERMINATOR:[bool;256] = [
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
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true]; // [0x22][0x27]
        let datastart = state.left;
        while state.left < state.right {
            if TERMINATOR[usize::from(data[state.left])] {
                state.consumed += state.left - datastart;
                state.node = if state.consumed >= 1 { NodeT::Notify15_7 } else { NodeT::NoState };
                let ret = state.node == NodeT::Notify15_7;
                state.consumed = 0;
                return ret;
            }
            state.left += 1;
            state.node = NodeT::Notify15_7;
            return true;
        }
        state.consumed += state.left - datastart;
        state.node = NodeT::Range15_6;
        return true;
    }
    fn notify15_7(&mut self, state: &mut StateT, data: &[u8]) -> bool {
        self.output.getAttribute();
        state.node = NodeT::Range15_8;
        return true;
    }
    fn range15_8(&mut self, state: &mut StateT, data: &[u8]) -> bool {
        static TERMINATOR:[bool;256] = [
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
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true]; // [0x9][0x20]
        let datastart = state.left;
        while state.left < state.right {
            if (state.left + 8) <= state.right {
                if TERMINATOR[usize::from(data[state.left])] {
                    state.left += 0;
                }
                else if TERMINATOR[usize::from(data[state.left + 1])] {
                    state.left += 1;
                }
                else if TERMINATOR[usize::from(data[state.left + 2])] {
                    state.left += 2;
                }
                else if TERMINATOR[usize::from(data[state.left + 3])] {
                    state.left += 3;
                }
                else if TERMINATOR[usize::from(data[state.left + 4])] {
                    state.left += 4;
                }
                else if TERMINATOR[usize::from(data[state.left + 5])] {
                    state.left += 5;
                }
                else if TERMINATOR[usize::from(data[state.left + 6])] {
                    state.left += 6;
                }
                else if TERMINATOR[usize::from(data[state.left + 7])] {
                    state.left += 7;
                }
                else
                {
                    state.left += 8;
                    continue;
                }
            }
            else if !(TERMINATOR[usize::from(data[state.left])]) {
                state.left += 1;
                continue;
            }
            state.consumed = 0;
            state.node = NodeT::Loop12_3;
            return true;
        }
        state.consumed += state.left - datastart;
        state.node = NodeT::Range15_8;
        return true;
    }
    fn loop17_0(&mut self, state: &mut StateT, data: &[u8]) -> bool {
        return self.uint17_0(state, data);
    }
    fn _uint17_0(&mut self, state: &mut StateT, data: &[u8]) {
        if state.consumed == 0 {
            *self.output.opend() = 0;
        }
        for x in data {
            *self.output.opend() = *self.output.opend()*10 + u32::from(*x - b'0');
        }
    }
    fn uint17_0(&mut self, state: &mut StateT, data: &[u8]) -> bool {
        static TERMINATOR:[bool;256] = [
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
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true]; // [0-9]
        let datastart = state.left;
        while state.left < state.right {
            if (state.left + 8) <= state.right {
                if TERMINATOR[usize::from(data[state.left])] {
                    state.left += 0;
                }
                else if TERMINATOR[usize::from(data[state.left + 1])] {
                    state.left += 1;
                }
                else if TERMINATOR[usize::from(data[state.left + 2])] {
                    state.left += 2;
                }
                else if TERMINATOR[usize::from(data[state.left + 3])] {
                    state.left += 3;
                }
                else if TERMINATOR[usize::from(data[state.left + 4])] {
                    state.left += 4;
                }
                else if TERMINATOR[usize::from(data[state.left + 5])] {
                    state.left += 5;
                }
                else if TERMINATOR[usize::from(data[state.left + 6])] {
                    state.left += 6;
                }
                else if TERMINATOR[usize::from(data[state.left + 7])] {
                    state.left += 7;
                }
                else
                {
                    state.left += 8;
                    continue;
                }
            }
            else if !(TERMINATOR[usize::from(data[state.left])]) {
                state.left += 1;
                continue;
            }
            let left = state.left;
            self._uint17_0(state, &data[datastart .. left]);
            let total = state.consumed + state.left - datastart;
            state.consumed = 0;
            if total >= 1 {
                state.node = NodeT::Loop17_0;
                return true;
            } else {
                state.node = NodeT::NoState;
                return false;
            }
        }
        if datastart < state.left {
            let left = state.left;
            self._uint17_0(state, &data[datastart .. left]);
        }
        state.consumed += state.left - datastart;
        state.node = NodeT::Uint17_0;
        return true;
    }
} // impl
