// Name:Balram Panwar,
// Email id: balram.panwar@gmail.com
// Name of the file: C2A4E1_RandomizeArray.cpp
// Win7
// Microsoft Visual Studio
//
// Function RandomizeArray : for the initializing the 4D array, which the srand and time 
// function , also using the rand() to generate the random value to fill the array.
//
#include <cstdlib>
#include <ctime>
#include "C2A4E1_ArraySize.h"

//
// Function RandomizeArray : for the initializing the 4D array, which the srand and time 
// function , also using the rand() to generate the random value to fill the array.
//
void RandomizeArray(float set[][DIM1][DIM2][DIM3])
{
    //seeds the random number generator with the value of the real time clock (RTC) 
    //using the standard library srand and time functions;
    srand((unsigned int)time(NULL));
    for (int index0 = 0; index0 < DIM0; ++index0)
        for (int index1 = 0; index1 < DIM1; ++index1)
            for (int index2 = 0; index2 < DIM2; ++index2)
                for (int index3 = 0; index3 < DIM3; ++index3)
                    set[index0][index1][index2][index3] = (float)rand();
}
