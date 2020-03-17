#ifndef DNA_INDEXEDDNASEQUENCE_H
#define DNA_INDEXEDDNASEQUENCE_H

#include "DnaSequence.h"
#include <map>

class IndexedDnaSequence : public DnaSequence
{
public:
    IndexedDnaSequence() {};
    explicit IndexedDnaSequence(string name, string sequence);
    static map<int, string> m_database_by_id;
    static map<string, string> m_database_by_name;
    static int seq_id;

    int getId();
    string getName();

private:
    string m_name;
    int m_id;
};

#endif
