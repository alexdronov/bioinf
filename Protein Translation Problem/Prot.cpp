#include "Prot.h"



void Prot::parser(string filename)
{
    string line, rnastring, codon, aacid;
    std::ifstream infile(filename.c_str());
    if (infile.is_open())
    {
        while (getline(infile, line))
        {
            rnastring = line;
        }
    }
    else
        printf("Error: Unable to open file!\n");
    
    //translation table in the form of a map
    map<string, string> rnatable;

    rnatable["UUU"] = "F";
    rnatable["UUC"] = "F";
    rnatable["UUA"] = "L";
    rnatable["UUG"] = "L";
    rnatable["UCU"] = "S";
    rnatable["UCC"] = "S";
    rnatable["UCA"] = "S";
    rnatable["UCG"] = "S";
    rnatable["UAU"] = "Y";
    rnatable["UAC"] = "Y";
    rnatable["UAA"] = "Stop";
    rnatable["UAG"] = "Stop";
    rnatable["UGU"] = "C";
    rnatable["UGC"] = "C";
    rnatable["UGA"] = "Stop";
    rnatable["UGG"] = "W";
    rnatable["CUU"] = "L";
    rnatable["CUC"] = "L";
    rnatable["CUA"] = "L";
    rnatable["CUG"] = "L";
    rnatable["CCU"] = "P";
    rnatable["CCC"] = "P";
    rnatable["CCA"] = "P";
    rnatable["CCG"] = "P";
    rnatable["CAU"] = "H";
    rnatable["CAC"] = "H";
    rnatable["CAA"] = "Q";
    rnatable["CAG"] = "Q";
    rnatable["CGU"] = "R";
    rnatable["CGC"] = "R";
    rnatable["CGA"] = "R";
    rnatable["CGG"] = "R";
    rnatable["AUU"] = "I";
    rnatable["AUC"] = "I";
    rnatable["AUA"] = "I";
    rnatable["AUG"] = "M";
    rnatable["ACU"] = "T";
    rnatable["ACC"] = "T";
    rnatable["ACA"] = "T";
    rnatable["ACG"] = "T";
    rnatable["AAU"] = "N";
    rnatable["AAC"] = "N";
    rnatable["AAA"] = "K";
    rnatable["AAG"] = "K";
    rnatable["AGU"] = "S";
    rnatable["AGC"] = "S";
    rnatable["AGA"] = "R";
    rnatable["AGG"] = "R";
    rnatable["GUU"] = "V";
    rnatable["GUC"] = "V";
    rnatable["GUA"] = "V";
    rnatable["GUG"] = "V";
    rnatable["GCU"] = "A";
    rnatable["GCC"] = "A";
    rnatable["GCA"] = "A";
    rnatable["GCG"] = "A";
    rnatable["GAU"] = "D";
    rnatable["GAC"] = "D";
    rnatable["GAA"] = "E";
    rnatable["GAG"] = "E";
    rnatable["GGU"] = "G";
    rnatable["GGC"] = "G";
    rnatable["GGA"] = "G";
    rnatable["GGG"] = "G";
    
    //reading the input file
    unsigned int i =0;
    while (i <= rnastring.length())
    {
        string prot;
        //append the new protein
        prot.push_back(rnastring[i]);
        prot.push_back(rnastring[i+1]);
        prot.push_back(rnastring[i+2]);
        
        //do not print the stop codon
        if (rnatable[prot] == "Stop")
            break;
        cout << rnatable[prot];
        i=i+3;
    }
    printf("\n");
}