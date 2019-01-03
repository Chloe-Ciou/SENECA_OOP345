
#include <iostream>
#include <fstream>
#include "process.h"

using namespace std;

// TODO: Declare (without defining) the global variable
// you have defined in CString.cpp
extern unsigned STORED;

int main(int argc, char* argv[])
{
    cout << "Command Line: ";
    for (int i = 0; i < argc; i++)
    {
        cout << argv[i] << ' ';
    }
    if (argc < 2)
    {
        cout << "\nInsufficient number of arguments\n";
        return 1;
    }
    
    // TODO: Add code here that will print out max characters
    // stored by your CString object
    cout << "\nMaximum number of characters stored: " << STORED << endl;
    
    for (int i = 1; i < argc; i++)
    {
        process(argv[i], cout);
    }
    
    return 0;
}
