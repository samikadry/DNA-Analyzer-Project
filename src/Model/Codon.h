#ifndef DNA_CODON_H
#define DNA_CODON_H

#include <string>
#include <vector>
using namespace std;

class Codon
{
public:
    /*get Start Codon*/
    static string getStartCodon();
    /*get End Codon*/
    static vector<string> getEndCodon();

private:
    const static string m_start_codon;
    const static vector<string> m_end_codon;
    /*initialize the End-Codon vector*/
    static vector<string> getEndCodonVector();
};

#endif
