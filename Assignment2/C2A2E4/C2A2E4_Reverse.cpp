// Name:Balram Panwar,
// Email id: balram.panwar@gmail.com
// Name of the file: C2A2E4_Reverse.cpp
// Win7
// Microsoft Visual Studio
//
// This file contains:
// Function CheckSeparator : it is a inline function, which check only Separator.
// Function Reverse : Recursively reads character and display them in reverse order.
//
#include <fstream>
#include <cstdlib>
#include <iostream>
using namespace std;

static char returnva;
// CheckSeparator function checks for the separator in the sentence, it is an inline function
// separator may be whitespace, a period, a question mark, an exclamation point, a comma, a colon,
// a semicolon, or EOF.
inline int checkSeparator(const char value)
{
    if (isspace(value) || (value == '.') || (value == '?') || (value == '!') || (value == ',') 
                       || (value == ':') || (value == ';'))
    {
        returnva = value;
        return 1;   
    }
    return 0;
}
// Reverse function recursively reads one character at a time from the text file in inFile till
// a separtor is encountered. Non -separator char are displayed in reverse order with the last
// character displayed being capitialized. Finally, the separator is returned to the calling function.
// Separators are not reversed and are not printed by reverse. The main code displayed the separator.
int Reverse(ifstream &inFile, const int level)
{
    char thisChar;
    int levelVal = level;
    if (!inFile.eof())
    {
        while (inFile.get(thisChar))
        {
            int separator = checkSeparator(thisChar);
            if (!separator)
            { 
                levelVal++;
                Reverse(inFile, levelVal);
               
                levelVal--;
                if (levelVal == 1)
                {
                    if (thisChar >= 'a' && thisChar <= 'z')
                    {
                        thisChar = 'A' + thisChar - 'a' ;
                    }
                    else 
                    {
                        thisChar = thisChar;
                    }
                }
                cout << thisChar;
            }
            levelVal--;
            return (int)returnva;
        }       
    }
    exit(EXIT_SUCCESS);
}
