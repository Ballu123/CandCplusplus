// Name:Balram Panwar
// Email id: balram.panwar@gmail.com
// Name of the file: C2A6E2_SortValues.cpp
// Win7
// Microsoft Visual Studio
//
// This file contains:
// Function SortValues :sorts the array in first in descending order using
// the bubble sort algorithm
//

#include <cstdlib>
using namespace std;

const int NUMBERZER0 = 0;
const int NUMBERONE = 1;
//
// Function SortValues :sorts the array in first in descending order using
// the bubble sort algorithm
//
float *SortValues(float *first, size_t elements)
{
    float *last = &first[elements - 1];
    bool didSwap;
    // checking the each value in the first array
    do
    {
        didSwap = false;
        // loop for sorting the complete array
        for (float *current = first; current < last; ++current)
        {
            // if 2nd value is greater than first one, then swap
            if (current[NUMBERZER0] < current[NUMBERONE])
            {
                float temp = current[NUMBERZER0];
                current[NUMBERZER0] = current[NUMBERONE];
                current[NUMBERONE] = temp;
                didSwap = true;
            }
        }
        --last;
    } while (didSwap);
    return first;
}
