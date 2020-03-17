#ifndef DNA_INTERFACECMD_H
#define DNA_INTERFACECMD_H

#include <string>
#include "../Model/DnaSequence.h"
using namespace std;

class InterfaceCmd{
public:
    virtual void runCommand(vector<string> input) = 0;
};

#endif
