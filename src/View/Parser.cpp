#include <sstream>
#include <iterator>
#include "Parser.h"

vector<string> Parser::parse_input(string line)
{
    vector<string> cmd;
    istringstream iss(line);
    copy(istream_iterator<string>(iss), istream_iterator<string>(), back_inserter(cmd));
    return cmd;
}