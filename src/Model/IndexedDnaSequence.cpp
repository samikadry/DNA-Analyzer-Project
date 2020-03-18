#include "IndexedDnaSequence.h"

int IndexedDnaSequence::s_seq_id = 0;
map<int, string> DataBase::m_id_database;
map<string, string> DataBase::m_name_database;
map< pair<int, string>, string> DataBase::m_database;

IndexedDnaSequence::IndexedDnaSequence(string name, string sequence) : DnaSequence(sequence), m_name(name)
{
    m_id = ++s_seq_id;
    DataBase::m_database.insert(make_pair(make_pair(m_id, m_name), sequence));
    DataBase::m_id_database.insert(pair<int, string>(m_id, sequence));
    DataBase::m_name_database.insert(pair<string, string>(name, sequence));
}

int IndexedDnaSequence::getId()
{
    return this->m_id;
}

string IndexedDnaSequence::getName()
{
    return this->m_name;
}


