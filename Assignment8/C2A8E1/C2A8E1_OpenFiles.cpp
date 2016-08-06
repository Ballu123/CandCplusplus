// Name:Balram Panwar
// Email id: balram.panwar@gmail.com
// Name of the file: C2A8E1_OpenFiles.cpp
// Win7
// Microsoft Visual Studio
//
// This file contains:
// Function Openfile : Opens the file in the read-only text mode using the inFileOjbect.
//
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <String>
using namespace std;

//Opens the file in the read-only text mode using the inFile Object and checking 
//the failure message and if it fails to open,it wiil terminated with an error exit
ifstream *OpenFiles(char * const fileNames[], size_t count)
{
    string line;
    ifstream *inFile = new (nothrow) ifstream[count];
    if (inFile == NULL)
    {
        cerr << "error opening the file";
    }
    // checking the count.
    if (count <= 1)
    {
        cerr << "There is no arguments.\n";
        //display message and wait for response before exiting.
        cin.get();
        exit(EXIT_FAILURE);
    }
    // Open file for read only.
    for (size_t numFile = 0; numFile < count; numFile++)
    {
        inFile[numFile].open(fileNames[numFile]);
        // If open fails print an error message and terminate with an error code.
        if (!inFile[numFile].is_open())
        {
            cerr << "File " << fileNames[numFile] << " didn't open.\n";
            exit(EXIT_FAILURE);
        }
    }
    return inFile;
}
