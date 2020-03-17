#ifndef DNA_DNASEQUENCE_H
#define DNA_DNASEQUENCE_H

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
using namespace std;

class DnaSequence{
public:
    /*constructors and destructor*/
    DnaSequence() {};
    explicit DnaSequence(const char* sequence);
    explicit DnaSequence(const string& sequence);
    DnaSequence(const DnaSequence& dnaSequence);

    /*getter of DNA sequence*/
    string getNucleotides() const;

    /*get the length of DNA sequence*/
    size_t getSequenceLength();

    /*overloading operators*/
    DnaSequence& operator=(const DnaSequence & sequence);
    DnaSequence& operator=(char* sequence);
    DnaSequence& operator=(const string& sequence);
    char operator[](size_t index) const;
    friend ostream &operator<<(ostream &ostream, DnaSequence &dnaSequence);

    /*working with files*/
    string readDNASequenceFromFile(const string& file_name);
    bool writeDNASequenceToFile(const string& file_name);

    /*getting a “slice” of a DNA sequence*/
    string sliceOnDNASequence(int start_index, int end_index);

    /*Get the paired sequence of dna sequence*/
    string getPairedSequence();

    /*find subsequence within a sequence*/
    bool findSubsequence(string subSequence, int index);

    /*Count the number of occurrences of a subsequence within a sequence*/
    int subSequneceOccurrencesTimes(string subSequence);

    /*Find all the occurrences of a subsequence within a sequence*/
    vector<int> subSequneceOccurrencesPlaces(string subSequence);

    /*Get all consensus sequences*/
    list<string> getConsensusSequences();

private:
    string m_nucleotides;
    int m_size;
};

bool operator==(const DnaSequence& sequence1, const DnaSequence& sequence2);
bool operator!=(const DnaSequence& sequence1, const DnaSequence& sequence2);

#endif