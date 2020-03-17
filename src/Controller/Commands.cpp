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

void Save::runCommand(vector<string> input)
{
    string file_name;
    if(input.size() == 2)
        file_name = input.at(1);
    if(input.size() == 3)
        file_name = input.at(2);
    m_sequence = IndexedDnaSequence(file_name += ".rawdna", input.at(1));
    m_sequence.writeDNASequenceToFile(file_name);
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

            for (map<string, string>::iterator it = IndexedDnaSequence::m_database_by_name.begin();
                 it != IndexedDnaSequence::m_database_by_name.end(); ++it)
            {
                if (it->second == indexedDnaSequence.m_database_by_id.find(id)->second)
                {
                    key = it->first;
                    break;
                }
            }
            indexedDnaSequence = IndexedDnaSequence(name = key + "_" + convert.str(),
                                                    indexedDnaSequence.m_database_by_id.find(id)->second);
        }
        else /*if given name of sequence*/
        {
            int key = -1;
            stringstream temp;

            for (map<int, string>::iterator it = IndexedDnaSequence::m_database_by_id.begin();
                 it != IndexedDnaSequence::m_database_by_id.end(); ++it)
            {
                if (it->second == indexedDnaSequence.m_database_by_name.find(input.at(1))->second)
                {
                    key = it->first;
                    break;
                }
            }
            temp << key;
            indexedDnaSequence = IndexedDnaSequence(name = temp.str() + "_" + convert.str(),
                                                    indexedDnaSequence.m_database_by_name.find(input.at(1))->second);
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

            for (map<string, string>::iterator it = IndexedDnaSequence::m_database_by_name.begin();
                 it != IndexedDnaSequence::m_database_by_name.end(); ++it)
            {
                if (it->second == indexedDnaSequence.m_database_by_id.find(id)->second)
                {
                    key = it->first;
                    break;
                }
            }
            indexedDnaSequence = IndexedDnaSequence(name = input.at(2).substr(1),
                                                    indexedDnaSequence.m_database_by_id.find(id)->second);
        }
        else /*if given name of sequence*/
        {
            int key = -1;
            stringstream temp;

            for (map<int, string>::iterator it = IndexedDnaSequence::m_database_by_id.begin();
                 it != IndexedDnaSequence::m_database_by_id.end(); ++it)
            {
                if (it->second == indexedDnaSequence.m_database_by_name.find(input.at(1))->second)
                {
                    key = it->first;
                    break;
                }
            }
            temp << key;
            indexedDnaSequence = IndexedDnaSequence(name = input.at(2).substr(1),
                                                    indexedDnaSequence.m_database_by_name.find(input.at(1))->second);
        }
    }

    ss << indexedDnaSequence.getId();
    Print::print("[" + ss.str() + "] " + name + ": " +
                 indexedDnaSequence.m_database_by_id.at(indexedDnaSequence.getId()) + "\n");
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

void Quit::runCommand(vector<string> input)
{
    string choice;
    cout << "There are N modified and N new sequences. Are you sure you want to quit?\n"
            "Please confirm by 'y' or 'Y', or cancel by 'n' or 'N'.\n"
            "> confirm >>> ";
    cin >> choice;
    while (choice.compare("n") && choice.compare("N") && choice.compare("y") && choice.compare("Y"))
    {
        cout << "You have typed an invalid response. Please either confirm by 'y'/'Y', or cancel by 'n'/'N'.\n"
                "> confirm >>>";
        cin >> choice;
    }

    if (!choice.compare("y") || !choice.compare("Y"))
    {
        cout << "Thank you for using Dna Analyzer.\nGoodbye!";
        exit(EXIT_SUCCESS);
    }
    else
        return;
}
