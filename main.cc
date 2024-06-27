#include "xml.h"
#include <fstream>

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
    std::ifstream f("input.txt");
    std::string input((std::istreambuf_iterator<char>(f)), std::istreambuf_iterator<char>());

    xml state;

    printf("===Test1 - full request:===\n");
    state.parse(input);

    printf("===Test2 - data fragmentation 1 byte===\n");
    for(const auto & c : input)
        if (!state.parse(&c, 1))
            printf("Error parse\n");

    return 0;
}
