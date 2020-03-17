#ifndef DNA_PARSER_H
#define DNA_PARSER_H

#include <vector>
#include <string>
using namespace std;

class Parser
{
public:
    static vector<string> parse_input(string line);
};
#endif