#ifndef DNA_COMMANDS_H
#define DNA_COMMANDS_H

#include "../Model/IndexedDnaSequence.h"
#include "InterfaceCMD.h"

class New : public InterfaceCmd
{
public:
    static int new_seq_name_id;

    void runCommand(vector<string> input);
};

class Save : public InterfaceCmd
{
public:
    IndexedDnaSequence m_sequence;

    void runCommand(vector<string> input);
};

class Load : public InterfaceCmd
{
public:
    IndexedDnaSequence m_sequence;

    void runCommand(vector<string> input);
};

class Dup : public InterfaceCmd
{
public:
    static int dup_seq_name_id;

    void runCommand(vector<string> input);
};

class Slice : public InterfaceCmd
{
public:
    static int slice_seq_name_id;

    void runCommand(vector<string> input);
};

class Replace : public InterfaceCmd
{
public:
    static int replace_seq_name_id;

    void runCommand(vector<string> input);
};

class Concat : public InterfaceCmd
{
public:
    static int concat_seq_name_id;

    void runCommand(vector<string> input);
};

class Pair : public InterfaceCmd
{
public:
    static int pair_seq_name_id;

    void runCommand(vector<string> input);
};

class Quit : public InterfaceCmd
{
public:
    void runCommand(vector<string> input);
};

#endif
