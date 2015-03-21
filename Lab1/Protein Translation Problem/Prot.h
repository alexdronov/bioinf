#ifndef Rosalind_Readfile_h
#define Rosalind_Readfile_h

#include <vector>
#include <stdio.h>
#include <iostream>
using namespace std;
#include <string.h>
using namespace std;
#include <iterator>
using namespace std;
#include <vector>
using namespace std;
#include <fstream>
using namespace std;
#include <iomanip>
#include <map>
using namespace std;

class Prot 
{
    
public:
    vector<int> numnt;
    void parser(string filename);
    void codeprotein(string rnastring,string codon,string aacid);
private:

};

#endif