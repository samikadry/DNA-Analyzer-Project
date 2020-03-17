#ifndef DNA_NUCLEOTIDES_H
#define DNA_NUCLEOTIDES_H

class Nucleotides
{
public:
    /*constructor*/
    explicit Nucleotides(char type);
    /*Check if valid nucleotide*/
    static bool isNucleotide(char type);
    /*get the pair of ​ nucleotide*/
    char getPair();

protected:
    char m_type;
};

#endif
