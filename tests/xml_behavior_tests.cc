#include "xml.h"

#include <algorithm>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

namespace {

enum class EventKind
{
    Payload,
    FinishTag,
    Attribute
};

struct Event
{
    EventKind kind = EventKind::Payload;
    std::string tag;
    std::string key;
    std::string value;
    std::string data;
    uint32_t depth = 0;
    bool isFirst = false;
    bool isLast = false;
};

std::vector<Event> g_events;

void clearEvents()
{
    g_events.clear();
}

[[noreturn]] void fail(const std::string & message)
{
    throw std::runtime_error(message);
}

void require(bool condition, const std::string & message)
{
    if (!condition)
        fail(message);
}

std::string readFile(const std::string & path)
{
    std::ifstream file(path.c_str(), std::ios::binary);
    require(file.good(), "failed to open " + path);
    std::ostringstream out;
    out << file.rdbuf();
    return out.str();
}

Event attributeEvent(const std::string & tag, const std::string & key, const std::string & value)
{
    Event event;
    event.kind = EventKind::Attribute;
    event.tag = tag;
    event.key = key;
    event.value = value;
    return event;
}

Event finishEvent(const std::string & tag, uint32_t depth)
{
    Event event;
    event.kind = EventKind::FinishTag;
    event.tag = tag;
    event.depth = depth;
    return event;
}

bool sameControlEvent(const Event & left, const Event & right)
{
    return left.kind == right.kind
        && left.tag == right.tag
        && left.key == right.key
        && left.value == right.value
        && left.depth == right.depth;
}

std::string describeControlEvent(const Event & event)
{
    std::ostringstream out;
    if (event.kind == EventKind::Attribute)
        out << "attribute(" << event.tag << "): " << event.key << "->" << event.value;
    else if (event.kind == EventKind::FinishTag)
        out << "finish(" << event.tag << "): " << event.depth;
    else
        out << "payload(" << event.data << ")";
    return out.str();
}

std::vector<Event> normalizeEvents(const std::vector<Event> & rawEvents)
{
    std::vector<Event> normalized;
    Event currentPayload;
    bool hasPayload = false;

    for (const Event & event : rawEvents)
    {
        if (event.kind != EventKind::Payload)
        {
            require(!hasPayload, "payload did not finish before " + describeControlEvent(event));
            normalized.push_back(event);
            continue;
        }

        if (!hasPayload)
        {
            currentPayload = Event();
            currentPayload.kind = EventKind::Payload;
            hasPayload = true;
        }

        currentPayload.data.append(event.data);
        if (event.isLast)
        {
            normalized.push_back(currentPayload);
            hasPayload = false;
        }
    }

    require(!hasPayload, "payload did not finish before input ended");
    return normalized;
}

std::vector<Event> controlEvents(const std::vector<Event> & events)
{
    std::vector<Event> controls;
    for (const Event & event : events)
    {
        if (event.kind != EventKind::Payload)
            controls.push_back(event);
    }
    return controls;
}

std::vector<std::string> payloads(const std::vector<Event> & events)
{
    std::vector<std::string> values;
    for (const Event & event : events)
    {
        if (event.kind == EventKind::Payload)
            values.push_back(event.data);
    }
    return values;
}

std::string joinedPayloads(const std::vector<Event> & events)
{
    std::string joined;
    for (const std::string & payload : payloads(events))
        joined += payload;
    return joined;
}

void requireControlsEqual(const std::vector<Event> & actual, const std::vector<Event> & expected)
{
    require(actual.size() == expected.size(),
        "control event count mismatch: got " + std::to_string(actual.size())
            + ", expected " + std::to_string(expected.size()));

    for (std::size_t i = 0; i < expected.size(); ++i)
    {
        if (!sameControlEvent(actual[i], expected[i]))
        {
            fail("control event mismatch at index " + std::to_string(i)
                + ": got " + describeControlEvent(actual[i])
                + ", expected " + describeControlEvent(expected[i]));
        }
    }
}

bool sameNormalizedEvent(const Event & left, const Event & right)
{
    if (left.kind != right.kind)
        return false;
    if (left.kind == EventKind::Payload)
        return left.data == right.data;
    return sameControlEvent(left, right);
}

void requireNormalizedEqual(const std::vector<Event> & actual, const std::vector<Event> & expected)
{
    require(actual.size() == expected.size(),
        "normalized event count mismatch: got " + std::to_string(actual.size())
            + ", expected " + std::to_string(expected.size()));

    for (std::size_t i = 0; i < expected.size(); ++i)
    {
        if (!sameNormalizedEvent(actual[i], expected[i]))
        {
            fail("normalized event mismatch at index " + std::to_string(i)
                + ": got " + describeControlEvent(actual[i])
                + ", expected " + describeControlEvent(expected[i]));
        }
    }
}

std::vector<Event> parseInChunks(const std::string & input, const std::vector<std::size_t> & chunkSizes)
{
    xml parser;
    clearEvents();

    std::size_t offset = 0;
    std::size_t chunkIndex = 0;
    while (offset < input.size())
    {
        const std::size_t requested = chunkSizes[chunkIndex % chunkSizes.size()];
        const std::size_t size = std::min(requested, input.size() - offset);
        require(parser.parse(input.data() + offset, static_cast<unsigned>(size)),
            "parse failed at offset " + std::to_string(offset));
        offset += size;
        ++chunkIndex;
    }

    return normalizeEvents(g_events);
}

void testGoldenInput()
{
    const std::string input = readFile("input.txt");
    const std::vector<Event> events = parseInChunks(input, std::vector<std::size_t>(1, input.size()));

    const std::vector<Event> expectedControls = {
        attributeEvent("recipe", "name", "bread"),
        attributeEvent("recipe", "preptime", "5"),
        attributeEvent("recipe", "cooktime", "180"),
        finishEvent("title", 1),
        attributeEvent("ingredient", "amount", "3"),
        attributeEvent("ingredient", "unit", "cup"),
        finishEvent("ingredient", 1),
        attributeEvent("ingredient", "amount", "0.25"),
        attributeEvent("ingredient", "unit", "gram"),
        finishEvent("ingredient", 1),
        attributeEvent("ingredient", "amount", "1.5"),
        attributeEvent("ingredient", "unit", "cup"),
        finishEvent("ingredient", 1),
        attributeEvent("ingredient", "amount", "1"),
        attributeEvent("ingredient", "unit", "tea spoon"),
        finishEvent("ingredient", 1),
        finishEvent("step", 2),
        finishEvent("step", 2),
        finishEvent("step", 2),
        finishEvent("instructions", 1),
        finishEvent("recipe", 0)
    };
    requireControlsEqual(controlEvents(events), expectedControls);

    const std::vector<std::string> data = payloads(events);
    require(data.size() == 9, "payload count mismatch: got " + std::to_string(data.size()));
    require(data[0] == "Simple bread", "title payload mismatch");
    require(data[1] == "flour", "first ingredient payload mismatch");
    require(data[2] == "yeast", "second ingredient payload mismatch");
    require(data[3] == "warm water", "third ingredient payload mismatch");
    require(data[4] == "salt", "fourth ingredient payload mismatch");
    require(data[5].find("!!!here can be text!!!") == 0, "free text payload mismatch");
    require(data[6] == "Mix all ingredients together and knead thoroughly..", "first step payload mismatch");
    require(data[7] == "Cover with a cloth and leave in a warm room for one hour.", "second step payload mismatch");
    require(data[8] == "Knead again, place on a baking sheet, and put it in the oven.", "third step payload mismatch");
    require(joinedPayloads(events).find("Read yesterday") == std::string::npos, "comment text leaked into payloads");
}

void testFragmentationMatchesFullInput()
{
    const std::string input = readFile("input.txt");
    const std::vector<Event> full = parseInChunks(input, std::vector<std::size_t>(1, input.size()));
    const std::vector<Event> oneByte = parseInChunks(input, std::vector<std::size_t>(1, 1));
    const std::vector<std::size_t> mixedSizes = {1, 7, 2, 31, 5, 13};
    const std::vector<Event> mixed = parseInChunks(input, mixedSizes);

    requireNormalizedEqual(oneByte, full);
    requireNormalizedEqual(mixed, full);
}

void testGrammarCoverage()
{
    const std::string input = "<root alpha = \"1\" beta='two'>hello<!-- ignored --><child />tail</root>";
    const std::vector<Event> events = parseInChunks(input, std::vector<std::size_t>(1, input.size()));

    const std::vector<Event> expectedControls = {
        attributeEvent("root", "alpha", "1"),
        attributeEvent("root", "beta", "two"),
        finishEvent("child", 1),
        finishEvent("root", 0)
    };
    requireControlsEqual(controlEvents(events), expectedControls);

    const std::vector<std::string> data = payloads(events);
    require(data.size() == 2, "grammar payload count mismatch: got " + std::to_string(data.size()));
    require(data[0] == "hello", "grammar leading payload mismatch");
    require(data[1] == "tail", "grammar trailing payload mismatch");
    require(joinedPayloads(events).find("ignored") == std::string::npos, "comment text leaked into grammar payloads");
}

void testFailureRecoveryAndPartialInput()
{
    xml parser;
    clearEvents();
    require(!parser.parse("</root>"), "unmatched closing tag unexpectedly parsed");
    require(parser.empty(), "parser should be empty after unmatched closing tag");

    parser.reset();
    clearEvents();
    require(parser.parse("<root>ok</root>"), "parser did not recover after reset");
    std::vector<Event> events = normalizeEvents(g_events);
    require(payloads(events).size() == 1 && payloads(events)[0] == "ok", "reset parse payload mismatch");
    requireControlsEqual(controlEvents(events), std::vector<Event>(1, finishEvent("root", 0)));

    parser.reset();
    clearEvents();
    require(parser.parse("<root>he"), "partial parse failed");
    require(!parser.empty(), "parser should retain state after partial parse");
    require(parser.parse("llo</root>"), "continued parse failed");
    events = normalizeEvents(g_events);
    require(payloads(events).size() == 1 && payloads(events)[0] == "hello", "continued payload mismatch");
    requireControlsEqual(controlEvents(events), std::vector<Event>(1, finishEvent("root", 0)));
}

void testStringLimits()
{
    const std::string longTag(300, 't');
    const std::string longKey(300, 'k');
    const std::string longValue(300, 'v');
    const std::string input = "<" + longTag + " " + longKey + "=\"" + longValue + "\"></" + longTag + ">";
    const std::vector<Event> events = parseInChunks(input, std::vector<std::size_t>(1, input.size()));
    const std::vector<Event> controls = controlEvents(events);

    require(controls.size() == 2, "limit control event count mismatch");
    require(controls[0].kind == EventKind::Attribute, "limit first control should be an attribute");
    require(controls[0].tag == longTag.substr(0, 256), "tag was not truncated to 256 bytes on attribute");
    require(controls[0].key == longKey.substr(0, 256), "key was not truncated to 256 bytes");
    require(controls[0].value == longValue.substr(0, 256), "value was not truncated to 256 bytes");
    require(controls[1].kind == EventKind::FinishTag, "limit second control should be a finish tag");
    require(controls[1].tag == longTag.substr(0, 256), "tag was not truncated to 256 bytes on close");
    require(controls[1].depth == 0, "limit close depth mismatch");
}

struct TestCase
{
    const char * name;
    void (*run)();
};

} // namespace

void xmlResult::payload(const char * data, unsigned len, bool isFirst, bool isLast)
{
    Event event;
    event.kind = EventKind::Payload;
    event.data.assign(data, data + len);
    event.isFirst = isFirst;
    event.isLast = isLast;
    g_events.push_back(event);
}

void xmlResult::finishTag()
{
    Event event;
    event.kind = EventKind::FinishTag;
    event.tag = tag;
    event.depth = opend;
    g_events.push_back(event);
}

void xmlResult::getAttribute()
{
    Event event;
    event.kind = EventKind::Attribute;
    event.tag = tag;
    event.key = key;
    event.value = value;
    g_events.push_back(event);
}

int main()
{
    const TestCase tests[] = {
        {"golden input", testGoldenInput},
        {"fragmentation matches full input", testFragmentationMatchesFullInput},
        {"grammar coverage", testGrammarCoverage},
        {"failure recovery and partial input", testFailureRecoveryAndPartialInput},
        {"string limits", testStringLimits}
    };

    int failures = 0;
    for (const TestCase & test : tests)
    {
        try
        {
            clearEvents();
            test.run();
            std::cout << "[PASS] " << test.name << '\n';
        }
        catch (const std::exception & error)
        {
            ++failures;
            std::cerr << "[FAIL] " << test.name << ": " << error.what() << '\n';
        }
    }

    return failures == 0 ? 0 : 1;
}
