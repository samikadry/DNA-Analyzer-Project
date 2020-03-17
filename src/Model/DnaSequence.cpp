#include <cstring>
#include "Nucleotides.h"
#include "Codon.h"
#include "DnaSequence.h"

DnaSequence::DnaSequence(const char* sequence)
{
    m_size = (int)strlen(sequence);
    if(m_size%3 != 0)
        throw exception();
    for (int i = 0; i < m_size; i++)
    {
        if(!Nucleotides::isNucleotide(sequence[i]))
            throw exception();
    }
    m_nucleotides = sequence;
}

DnaSequence::DnaSequence(const string& sequence)
{
    m_size = (int)sequence.size();
    if(m_size%3 != 0)
        throw exception();
    for (int i = 0; i < m_size; i++)
    {
        if(!Nucleotides::isNucleotide(sequence[i]))
            throw exception();
    }
    m_nucleotides = sequence;
}

DnaSequence::DnaSequence(const DnaSequence& dnaSequence)
{
    m_size = (int)dnaSequence.m_nucleotides.size();
    if(m_size%3 != 0)
        throw exception();
    for (int i = 0; i < m_size; i++)
    {
        if(!Nucleotides::isNucleotide(dnaSequence.m_nucleotides[i]))
            throw exception();
    }
    m_nucleotides = dnaSequence.m_nucleotides;
}

string DnaSequence::getNucleotides() const
{
    return m_nucleotides;
}

size_t DnaSequence::getSequenceLength()
{
    return m_nucleotides.size();
}

DnaSequence& DnaSequence::operator=(const DnaSequence& sequence)
{
    m_nucleotides = sequence.m_nucleotides;
    return *this;
}

DnaSequence& DnaSequence::operator=(char* sequence)
{
    m_nucleotides = sequence;
    return *this;
}

DnaSequence& DnaSequence::operator=(const string& sequence)
{
    m_nucleotides = sequence;
    return *this;
}

char DnaSequence::operator[](size_t index) const
{
    return this->m_nucleotides[index];
}

ostream &operator<<(ostream &ostream, DnaSequence &dnaSequence)
{
    return ostream << "The DNA sequence is: " << dnaSequence.m_nucleotides << endl;
}

string DnaSequence::readDNASequenceFromFile(const string& file_name)
{
    fstream file(file_name.c_str());
    if (file.is_open())
    {
        while(getline(file, this->m_nucleotides));
        file.flush();
        file.close();
        return this->m_nucleotides;
    }
    else
    {
        cout << "Unable to open file!!\n";
        return "AAA";
    }
}

bool DnaSequence::writeDNASequenceToFile(const string& file_name)
{
    ofstream myfile(file_name.c_str());
    if (myfile.is_open())
    {
        myfile << this->m_nucleotides;
        myfile.flush();
        myfile.close();
        return true;
    }
    else
    {
        cout << "Unable to open file!!";
        return false;
    }
}

string DnaSequence::sliceOnDNASequence(int start_index, int end_index)
{
    if(start_index >= this->m_size || end_index >= this->m_size)
        return "\nInvalid index!!\n";
    return this->m_nucleotides.substr(start_index, end_index-start_index + 1);
}

string DnaSequence::getPairedSequence()
{
    string pairedSequence;
    for (int i = m_size-1; i >= 0 ; i--)
    {
        Nucleotides temp(m_nucleotides[i]);
        pairedSequence += temp.getPair();
    }
    return pairedSequence;
}

bool DnaSequence::findSubsequence(string subSequence, int index)
{
    return m_nucleotides.find(subSequence, index) != string::npos;
}

int DnaSequence::subSequneceOccurrencesTimes(string subSequence)
{
    int count = 0;
    long unsigned int index = 0;
    while((index = m_nucleotides.find(subSequence, index)) != string::npos)
    {
        count++;
        index++;
    }
    return count;
}

vector<int> DnaSequence::subSequneceOccurrencesPlaces(string subSequence)
{
    vector<int> indexes;
    long unsigned int index = 0;
    while((index = m_nucleotides.find(subSequence, index)) != string::npos)
    {
        indexes.push_back((int)index);
        index++;
    }
    return indexes;
}

list<string> DnaSequence::getConsensusSequences()
{
    Codon codon;
    long unsigned int start_index = 0, end_index = 0;
    list<string> result = list<string>();

    while((start_index = m_nucleotides.find(codon.getStartCodon(), start_index)) != string::npos)
    {
        if((end_index = m_nucleotides.find(codon.getEndCodon().at(0), start_index+3)) != string::npos)
            result.push_back(m_nucleotides.substr(start_index,end_index-start_index+3));
        else if ((end_index = m_nucleotides.find(codon.getEndCodon().at(1), start_index+3)) != string::npos)
            result.push_back(m_nucleotides.substr(start_index,end_index-start_index+3));
        else if((end_index = m_nucleotides.find(codon.getEndCodon().at(2), start_index+3)) != string::npos)
            result.push_back(m_nucleotides.substr(start_index,end_index-start_index+3));
        else
            break;
        start_index = end_index;
    }
    return result;
}

bool operator==(const DnaSequence &sequence1, const DnaSequence& sequence2)
{
    return sequence1.getNucleotides() == sequence2.getNucleotides();
}

bool operator!=(const DnaSequence &sequence1,const DnaSequence& sequence2)
{
    return sequence1.getNucleotides() != sequence2.getNucleotides();
}