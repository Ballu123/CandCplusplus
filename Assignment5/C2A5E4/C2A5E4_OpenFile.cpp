// Name:Balram Panwar,
// Email id: balram.panwar@gmail.com
// Name of the file: C2A5E4_OpenFile.cpp
// Win7
// Microsoft Visual Studio
//
// This file contains:
// Function Openfile : Opens the file in the read-only text mode using the inFileOjbect.
//
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "C2A5E4_StatusCode-Driver.h"

using namespace std;

//Opens the file in the read-only text mode using the inFile Object and checking 
//the failure message and if it fails to open,it wiil terminated with an error exit
void OpenFile(const char *fileName, ifstream &inFile)
{
    // Open file for read only.
    inFile.open(fileName);
    // checking that file is open or not
    if (!inFile.is_open())
    {
        cerr << "\"" << fileName << "\": File access error \n";
        exit(EXIT_FAILURE);
    }
}
