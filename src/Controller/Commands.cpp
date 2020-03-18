#include <sstream>
#include <cstdlib>
#include "Commands.h"
#include "../View/Print.h"

int New::new_seq_name_id = 0;
int Dup::dup_seq_name_id = 0;
int Slice::slice_seq_name_id = 0;
int Replace::replace_seq_name_id = 0;
int Concat::concat_seq_name_id = 0;
int Pair::pair_seq_name_id = 0;

void New::runCommand(vector<string> input)
{
    IndexedDnaSequence indexedDnaSequence;
    string name;
    stringstream ss;

    if(input.size() == 2)
    {
        ostringstream convert;
        convert << ++new_seq_name_id;
        indexedDnaSequence = IndexedDnaSequence(name = "seq"+convert.str(), input.at(1));
    }
    else if(input.size() == 3)
        indexedDnaSequence = IndexedDnaSequence(name = input.at(2).substr(1),input.at(1));

    ss << indexedDnaSequence.getId();
    Print::print("[" + ss.str() + "] " + name + ": " + input.at(1) + "\n");
}

void Load::runCommand(vector<string> input)
{
    IndexedDnaSequence indexedDnaSequence;
    string name, sequence = m_sequence.readDNASequenceFromFile(input.at(1));
    stringstream ss;

    if(input.size() == 2)
        indexedDnaSequence = IndexedDnaSequence(name=input.at(1).substr(0,input.at(1).length()-7), sequence);
    else if(input.size() == 3)
        indexedDnaSequence = IndexedDnaSequence(name = input.at(2),sequence);

    ss << indexedDnaSequence.getId();
    Print::print("[" + ss.str() + "] " + name + ": " + m_sequence.getNucleotides() + "\n");
}

void Dup::runCommand(vector<string> input)
{
    IndexedDnaSequence indexedDnaSequence;
    int id;
    string name;
    stringstream ss;

    if(input.size() == 2)
    {
        ostringstream convert;
        convert << ++dup_seq_name_id;
        if(input.at(1)[0] == '#') /*if given id of sequence*/
        {
            stringstream stoi(input.at(1).substr(1));
            stoi >> id;
            string key = "";

            for (map<string, string>::iterator it = DataBase::m_name_database.begin();
                 it != DataBase::m_name_database.end(); ++it)
            {
                if (it->second == DataBase::m_id_database.find(id)->second)
                {
                    key = it->first;
                    break;
                }
            }
            indexedDnaSequence = IndexedDnaSequence(name = key + "_" + convert.str(),
                                                    DataBase::m_id_database.find(id)->second);
        }
        else /*if given name of sequence*/
        {
            int key = -1;
            stringstream temp;

            for (map<int, string>::iterator it = DataBase::m_id_database.begin();
                 it != DataBase::m_id_database.end(); ++it)
            {
                if (it->second == DataBase::m_name_database.find(input.at(1))->second)
                {
                    key = it->first;
                    break;
                }
            }
            temp << key;
            indexedDnaSequence = IndexedDnaSequence(name = temp.str() + "_" + convert.str(),
                                                    DataBase::m_name_database.find(input.at(1))->second);
        }
    }
    else if(input.size() == 3)
    {
        ostringstream convert;
        convert << ++dup_seq_name_id;
        if(input.at(1)[0] == '#') /*if given id of sequence*/
        {
            stringstream stoi(input.at(1).substr(1));
            stoi >> id;
            string key = "";

            for (map<string, string>::iterator it = DataBase::m_name_database.begin();
                 it != DataBase::m_name_database.end(); ++it)
            {
                if (it->second == DataBase::m_id_database.find(id)->second)
                {
                    key = it->first;
                    break;
                }
            }
            indexedDnaSequence = IndexedDnaSequence(name = input.at(2).substr(1),
                                                    DataBase::m_id_database.find(id)->second);
        }
        else /*if given name of sequence*/
        {
            int key = -1;
            stringstream temp;

            for (map<int, string>::iterator it = DataBase::m_id_database.begin();
                 it != DataBase::m_id_database.end(); ++it)
            {
                if (it->second == DataBase::m_name_database.find(input.at(1))->second)
                {
                    key = it->first;
                    break;
                }
            }
            temp << key;
            indexedDnaSequence = IndexedDnaSequence(name = input.at(2).substr(1),
                                                    DataBase::m_name_database.find(input.at(1))->second);
        }
    }

    ss << indexedDnaSequence.getId();
    Print::print("[" + ss.str() + "] " + name + ": " +
                 DataBase::m_id_database.at(indexedDnaSequence.getId()) + "\n");
}

void Slice::runCommand(vector<string> input)
{

}

void Replace::runCommand(vector<string> input)
{

}

void Concat::runCommand(vector<string> input)
{

}

void Pair::runCommand(vector<string> input)
{

}

void Rename::runCommand(vector<string> input)
{
    map<pair<int, string>, string>::iterator it;
    string* name_ptr;

    for(it = DataBase::m_database.begin(); it != DataBase::m_database.end(); it++)
    {
        if ((it->first).second == input.at(2).substr(1))
        {
            Print::print("The name is already exist\n");
            return;
        }
    }

    if(input.at(1)[0] == '#') /*if given id of sequence*/
    {
        int id;
        for(it = DataBase::m_database.begin(); it != DataBase::m_database.end(); it++)
        {
            stringstream stoi(input.at(1).substr(1));
            stoi >> id;
            if((it->first).first == id)
            {
                name_ptr = const_cast<string*>(&((it->first).second));
                *name_ptr = input.at(2).substr(1);
            }
        }
        if (it == DataBase::m_database.end())
            Print::print("The sequence id doesn't exist!!\n");
    }
    else if(input.at(1)[0] == '@') /*if given name of sequence*/
    {
        string name = input.at(1).substr(1);
        for (it = DataBase::m_database.begin(); it != DataBase::m_database.end(); it++)
        {
            if ((it->first).second == name) {
                name_ptr = const_cast<string *>(&((it->first).second));
                *name_ptr = input.at(2).substr(1);
            }
        }

        if (it == DataBase::m_database.end())
            Print::print("The sequence name doesn't exist!!\n");
    }
    else
        Print::print("Invalid syntax, if your approach by the sequence id please put '#' before the id,"
                "if it's by the name so put '@' before the name.\n");
}

void Del::runCommand(vector<string> input)
{
    string choice, name, sequence;
    int id;
    map<pair<int, string>, string>::iterator it;

    if(input.at(1)[0] == '#') /*if given id of sequence*/
    {
        for(it = DataBase::m_database.begin(); it != DataBase::m_database.end(); it++)
        {
            stringstream stoi(input.at(1).substr(1));
            stoi >> id;
            if((it->first).first == id)
            {
                name = it->first.second;
                sequence = it->second;
                break;
            }
        }
        if (it == DataBase::m_database.end())
        {
            Print::print("The sequence id doesn't exist!!\n");
            return;
        }
    }
    else if(input.at(1)[0] == '@') /*if given name of sequence*/
    {
        name = input.at(1).substr(1);
        for (it = DataBase::m_database.begin(); it != DataBase::m_database.end(); it++)
        {
            if ((it->first).second == name)
            {
                id = it->first.first;
                sequence = it->second;
                break;
            }
        }
        if (it == DataBase::m_database.end())
        {
            Print::print("The sequence name doesn't exist!!\n");
            return;
        }
    }
    else
    {
        Print::print("Invalid syntax, if your approach by the sequence id please put '#' before the id,"
                     "if it's by the name so put '@' before the name.\n");
        return;
    }

    Print::print("Do you really want to delete" + name + ": " + sequence +
    "?\nPlease confirm by 'y' or 'Y', or cancel by 'n' or 'N'.\n> confirm >>> ");
    cin >> choice;
    while (choice.compare("n") && choice.compare("N") && choice.compare("y") && choice.compare("Y"))
    {
        Print::print("You have typed an invalid response. Please either confirm by 'y'/'Y', or cancel by 'n'/'N'.\n"
                     "> confirm >>>");
        cin >> choice;
    }

    if (!choice.compare("y") || !choice.compare("Y"))
    {
        string str_id;          /* string which will contain the result */
        ostringstream convert;  /* stream used for the conversion */
        convert << id;          /* insert the textual representation of 'Number' in the characters in the stream */
        str_id = convert.str();
        Print::print("Deleted: [" + str_id + "] " + name + ": " + sequence);
        DataBase::m_database.erase(it);
    }
    else
        Print::print("Deletion canceled\n");

}

void ReEnum::runCommand(vector<string> input)
{
    if(input.size() > 1)
    {
        Print::print("Invalid syntax, try again\n");
        return;
    }
    map<pair<int, string>, string>::iterator it;
    int id_counter = 0;
    int* id_ptr;

    for(it = DataBase::m_database.begin(); it != DataBase::m_database.end(); it++)
    {
        id_ptr = const_cast<int*>(&it->first.first);
        *id_ptr = ++id_counter;
    }
    IndexedDnaSequence::s_seq_id = id_counter;
}

void Save::runCommand(vector<string> input)
{
    string file_name, sequence;
    map<pair<int, string>, string>::iterator it;

    if(input.at(1)[0] == '#') /*if given id of sequence*/
    {
        int id;
        for(it = DataBase::m_database.begin(); it != DataBase::m_database.end(); it++)
        {
            stringstream stoi(input.at(1).substr(1));
            stoi >> id;
            if ((it->first).first == id)
            {
                sequence = it->second;
                file_name = it->first.second;
            }
        }
        if (it != DataBase::m_database.end())
            Print::print("The sequence id doesn't exist!!\n");
    }
    else if(input.at(1)[0] == '@') /*if given name of sequence*/
    {
        string name = input.at(1).substr(1);
        for (it = DataBase::m_database.begin(); it != DataBase::m_database.end(); it++)
        {
            if ((it->first).second == name)
            {
                sequence = it->second;
                file_name = it->first.second;
            }
        }

        if (it != DataBase::m_database.end())
            Print::print("The sequence name doesn't exist!!\n");
    }
    else
    {
        Print::print("Invalid syntax, if your approach by the sequence id please put '#' before the id,"
                "if it's by the name so put '@' before the name.\n");
        return;
    }

    if(input.size() == 3)
        file_name = input.at(2);
    m_sequence = IndexedDnaSequence(file_name += ".rawdna", sequence);
    m_sequence.writeDNASequenceToFile(file_name);
}

void Quit::runCommand(vector<string> input)
{
    string choice;
    Print::print("There are N modified and N new sequences. Are you sure you want to quit?\n"
                 "Please confirm by 'y' or 'Y', or cancel by 'n' or 'N'.\n"
                 "> confirm >>> ");
    cin >> choice;
    while (choice.compare("n") && choice.compare("N") && choice.compare("y") && choice.compare("Y"))
    {
        Print::print("You have typed an invalid response. Please either confirm by 'y'/'Y', or cancel by 'n'/'N'.\n"
                     "> confirm >>>");
        cin >> choice;
    }

    if (!choice.compare("y") || !choice.compare("Y"))
    {
        Print::print("Thank you for using Dna Analyzer.\nGoodbye!");
        exit(EXIT_SUCCESS);
    }
    else
        return;
}