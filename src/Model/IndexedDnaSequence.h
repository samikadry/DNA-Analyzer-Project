#ifndef DNA_INDEXEDDNASEQUENCE_H
#define DNA_INDEXEDDNASEQUENCE_H

#include "DnaSequence.h"
#include "DataBase.h"
#include <map>

class IndexedDnaSequence : public DnaSequence
{
public:
    static int s_seq_id;

    IndexedDnaSequence() {};
    explicit IndexedDnaSequence(string name, string sequence);
    int getId();
    string getName();

private:
    string m_name;
    int m_id;
};

#endif
