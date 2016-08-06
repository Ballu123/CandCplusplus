// Name:Balram Panwar,
// Email id: balram.panwar@gmail.com
// Name of the file: C2A2E2_CountIntBitsF.cpp
// Win7
// Microsoft Visual Studio
//
// This file contains:
// Function CountIntBitsF : Determine the no. of bits in type int
//
#include <climits>

// This function determine the no. of bits in int data type
int CountIntBitsF()
{
    return(sizeof(int)* CHAR_BIT);
}
