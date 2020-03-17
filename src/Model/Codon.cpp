#include "Codon.h"

const string Codon::m_start_codon("ATG");
const vector<string> Codon::m_end_codon(getEndCodonVector());

string Codon::getStartCodon()
{

    return m_start_codon;
}

vector<string> Codon::getEndCodon()
{
    return m_end_codon;
}

vector<string> Codon::getEndCodonVector()
{
    vector<string> end_codon;
    end_codon.push_back("TAA");
    end_codon.push_back("TAG");
    end_codon.push_back("TGA");
    return end_codon;
}
