// Name:Balram Panwar
// Email id: balram.panwar@gmail.com
// Name of the file: C2A7E2_ListHex.cpp
// Win7
// Microsoft Visual Studio
//
// This file contains:
// Function ListHex : Displays the contents of the file in inFile as 
// one pair of hexadecimal characters per file byte, zero-filled on the 
// left if necessary to produce the two characters. Pairs are single-space-separated 
// and the number of pairs that are placed on each line is specified by parameter
// bytesPerLine. Pairs are aligned from one line to the next and the last line will
// contain less than the specified number of pairs per line if EOF is reached prior to the
// completion of that line. You may assume that a byte consists of 8 bits for this exercise.
// 
//
#include <fstream>
#include <iostream>
#include <iomanip>     
using namespace std;

// 
//Displays the contents of the file in inFile as 
// one pair of hexadecimal characters per file byte, zero-filled on the 
// left if necessary to produce the two characters. Pairs are single-space-separated 
// and the number of pairs that are placed on each line is specified by parameter
// bytesPerLine. Pairs are aligned from one line to the next and the last line will
// contain less than the specified number of pairs per line if EOF is reached prior
//  to the completion of that line. 
//
void ListHex(ifstream &inFile, int bytesPerLine)
{
    char thisChar;
    int count = 0;
    cout << setfill('0');
    cout << hex;
    // reading the file till the end of the file
    if (!inFile.eof())
    {
        // reading every single character from the file
        while (inFile.get(thisChar))
        {
            // check the count and it should be less than bytes per line
            if (count < bytesPerLine)
            {
                cout << setw(2);
                cout << (0xFF & (unsigned char)thisChar) << " ";
                ++count;
            }
            else
            {
                cout << "\n";
                count = 0;
            }
        }
    }
}
