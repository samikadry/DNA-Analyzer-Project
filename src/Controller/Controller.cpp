#include <iostream>
#include "Controller.h"
#include "../View/Parser.h"

New new_object;
Save save_object;
Load load_object;
Dup dup_object;
Slice slice_object;
Replace replace_object;
Concat concat_object;
Pair pair_object;
Quit quit_object;
map<string ,InterfaceCmd*> commands_map;

void controller()
{
    commands_map.insert(pair<string ,InterfaceCmd*>("new", &new_object));
    commands_map.insert(pair<string ,InterfaceCmd*>("save", &save_object));
    commands_map.insert(pair<string ,InterfaceCmd*>("load", &load_object));
    commands_map.insert(pair<string ,InterfaceCmd*>("dup", &dup_object));
    commands_map.insert(pair<string ,InterfaceCmd*>("slice", &slice_object));
    commands_map.insert(pair<string ,InterfaceCmd*>("replace", &replace_object));
    commands_map.insert(pair<string ,InterfaceCmd*>("concat", &concat_object));
    commands_map.insert(pair<string ,InterfaceCmd*>("pair", &pair_object));
    commands_map.insert(pair<string ,InterfaceCmd*>("quit", &quit_object));
    string input_line;
    vector<string> cmd; /*used for the input parser*/

    while(getline(cin, input_line))
    {
        cmd = Parser::parse_input(input_line);
        commands_map.at(cmd.at(0))->runCommand(cmd);
    }
}