#include "IndexedDnaSequence.h"

int IndexedDnaSequence::seq_id = 0;
map<int, string> IndexedDnaSequence::m_database_by_id;
map<string, string> IndexedDnaSequence::m_database_by_name;

IndexedDnaSequence::IndexedDnaSequence(string name, string sequence) : DnaSequence(sequence), m_name(name)
{
    m_id = ++seq_id;
    m_database_by_id.insert(pair<int, string>(m_id, sequence));
    m_database_by_name.insert(pair<string, string>(name, sequence));
}

int IndexedDnaSequence::getId()
{
    return this->m_id;
}

string IndexedDnaSequence::getName()
{
    return this->m_name;
}


