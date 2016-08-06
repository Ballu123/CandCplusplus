/*
* Name:Balram Panwar,
* Email id: balram.panwar@gmail.com
* Name of the file: C2A2E1_CountIntBitsF.c
* Win7
* Microsoft Visual Studio
*
* This file contains:
* Function CountIntBitsF : Determine the no. of bits in type int
* Got the same result from both the int by macro and function.
*/
#include <limits.h>
/*
* CountIntBitsF : Determine the no. of bits in type int
* value on any machine on which it is run.
*/
int CountIntBitsF(void)
{
    int x = INT_MAX;
    int count = 2;
    while (x = x / 2) count++;
    return count;
}

