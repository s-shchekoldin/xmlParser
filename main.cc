#include "xml.h"

void xmlResult::payload(__attribute__((unused)) const char * data, __attribute__((unused)) unsigned len, __attribute__((unused)) bool isFirst, __attribute__((unused)) bool isLast)
{
    printf("\tDATA(%u)[%u_%u]: ", len, isFirst, isLast);
    for(unsigned i = 0; i < len; i++)
        printf("%c", data[i]);
    printf("\n");
}

void xmlResult::finishTag()
{
    printf("finishTag: %s deep: %u\n", tag.c_str(), (unsigned)opend);
}

void xmlResult::getAttribute()
{
    printf("getAttribute(%s): %s->%s\n", tag.c_str(), key.c_str(), value.c_str());
}

int main()
{
    std::vector<std::string> examples;
    std::string s;
    s += "<recipe name=\"bread\" preptime=\"5\" cooktime=\"180\">";
    s += "  <title>Simple bread</title>";
    s += "  <ingredient amount=\"3\" unit=\"cup\">flour</ingredient>";
    s += "  <ingredient amount=\"0.25\" unit=\"gram\">yeast</ingredient>";
    s += "  <ingredient amount=\"1.5\" unit=\"cup\">warm water</ingredient>";
    s += "  <ingredient amount=\"1\" unit=\"tea spoon\">salt</ingredient>";
    s += "  !!!here can be text!!!";
    s += "  <instructions>";
    s += "   <step>Mix all ingredients together and knead thoroughly..</step>";
    s += "   <step>Cover with a cloth and leave in a warm room for one hour.</step>";
    s += "   <!-- <step>Read yesterday's newspaper.</step> - this is a questionable move.... -->";
    s += "   <step>Knead again, place on a baking sheet, and put it in the oven.</step>";
    s += "  </instructions>";
    s += "</recipe>";

    examples.push_back(s);

    xml state;

    printf("===Stage1 - full request:===\n");
    for(const auto & e : examples)
        if (!state.parse(e))
            printf("Error parse\n");

    printf("===Stage2 - data fragmentation 1 byte===\n");
    for(const auto & e : examples)
    {
        for(const auto & c : e)
            if (!state.parse(&c, 1))
                printf("Error parse\n");
    }

    return 0;
}
