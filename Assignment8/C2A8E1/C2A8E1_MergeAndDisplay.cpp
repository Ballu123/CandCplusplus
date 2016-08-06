// Name:Balram Panwar
// Email id: balram.panwar@gmail.com
// Name of the file: C2A8E1_MergeAndDisplay.cpp
// Win7
// Microsoft Visual Studio
//
// This file contains:
// Function MergeAndDisplay :Proceeding in order from the first file specified in files, 
// the first line in each file is read and displayed, followed by the second line in each,
// followed by the third, etc.When the end of any file is reached that file is closed 
// and the process continues using only the remaining open files until all files have
// finally been closed.Empty lines are displayed as empty lines.Empty files are simply
// closed and ignored.
// 
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <String>
using namespace std;
// 
// Function MergeAndDisplay :Proceeding in order from the first file specified in files, 
// the first line in each file is read and displayed, followed by the second line in each,
// followed by the third, etc.When the end of any file is reached that file is closed 
// and the process continues using only the remaining open files until all files have
// finally been closed.Empty lines are displayed as empty lines.Empty files are simply
// closed and ignored.
// 
void MergeAndDisplay(ifstream files[], size_t count)
{
    string line;
    bool checkAllFiles = true;
    size_t numFile = 0;
    size_t completedFiles = 0;
    size_t totalcount = count;
    // checking the files 
    if (files == NULL)
    {
        cerr << "error opening the file";
    }
    //checking the all the files are completed or not.
    while (checkAllFiles)
    {
        //checking the no. of files scanned.
        if (numFile < count)
        {
            // checking if the file is still open
            if (files[numFile].is_open())
            {
                if (getline(files[numFile], line))
                {
                    cout << line << "\n";
                    numFile++;
                    // intializing the no of files to 0
                    if (numFile == count)
                    {
                        numFile = 0;
                    }              
                }
                else
                {
                    // closing the completed file
                    files[numFile].close();
                    ++numFile;
                    // intializing the no of files to 0
                    if (numFile == count)
                    {
                        numFile = 0;
                    }
                    ++completedFiles;
                    //checking the completion of all files.
                    if (completedFiles == totalcount)
                    {
                        checkAllFiles = false;
                    }
                }
            }
            else
            {
                ++numFile;
                // intializing the no of files to 0
                if (numFile == count)
                {
                    numFile = 0;
                }
            }
        }
    }
}
