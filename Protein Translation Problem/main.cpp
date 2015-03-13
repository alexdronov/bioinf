#include <iostream>
using namespace std;
#include "Prot.h"

int main(int argc, const char * argv[])
{

    // insert code here...
//    cout << "Hello, World!\n";
    
    Prot* M = new Prot();
    M->parser("rosalind_dataset.txt");
    
    
    return 0;
    
}