// Name:Balram Panwar
// Email id: balram.panwar@gmail.com
// Name of the file: C2A7E2_OpenFileBinary.cpp
// Win7
// Microsoft Visual Studio
//
// This file contains:
// Function Openfile : Opens the file in the read-only text mode using the inFileOjbect.
//
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

//Opens the file in the read-only text mode using the inFile Object and checking 
//the failure message and if it fails to open,it wiil terminated with an error exit
void OpenFileBinary(const char *fileName, ifstream &inFile)
{
    // Open file for read only.
    inFile.open(fileName, ios::binary);
    // If open fails print an error message and terminate with an error code.
    if (!inFile.is_open())
    {
        cerr << "File " << fileName << " didn't open.\n";
        exit(EXIT_FAILURE);
    }
}
