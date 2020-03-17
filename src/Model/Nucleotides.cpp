#include <iostream>
#include "Nucleotides.h"
using namespace std;

Nucleotides::Nucleotides(char type) : m_type(type)
{
    if (!(isNucleotide(type)))
        throw exception();
}

bool Nucleotides::isNucleotide(char type)
{
    if (type != 'A' && type != 'C' && type != 'T' && type != 'G')
    {
        cout << "Invalid DNA sequence!" << endl;
        return false;
    }
    return true;
}

char Nucleotides::getPair()
{
    switch (m_type)
    {
        case 'A': return 'T';
        case 'T': return 'A';
        case 'G': return 'C';
        case 'C': return 'G';
        default: throw exception();
    }
}