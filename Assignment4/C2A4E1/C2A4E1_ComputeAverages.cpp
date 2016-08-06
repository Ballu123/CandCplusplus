// Name:Balram Panwar, 
// Email id: balram.panwar@gmail.com
// Name of the file: C2A4E1_ComputeAverages.cpp
// Win7
// Microsoft Visual Studio
//
// function ComputeAverage : computers the average of all elements in the 4D array by
// two different methods such as using nested for loops and 4D indexing . The second 
// method is accessing by the function's 3rd parameter

#include "C2A4E1_ArraySize.h"

//
// function ComputeAverage : computers the average of all elements in the 4D array by
// two different methods such as using nested for loops and 4D indexing . The second 
// method is accessing by the function's 3rd parameter
//
void ComputeAverages(float set[][DIM1][DIM2][DIM3], float *nestedAvg, float *linearAvg)
{
    float subTotal1 = 0;
    float subTotal2 = 0;
    float *pointer;

    for (int index0 = 0; index0 < DIM0; ++index0)
        for (int index1 = 0; index1 < DIM1; ++index1)
            for (int index2 = 0; index2 < DIM2; ++index2)
                for (int index3 = 0; index3 < DIM3; ++index3)
                    subTotal1 += set[index0][index1][index2][index3];

    // calculate the average using the index method
    *nestedAvg = subTotal1 / (DIM0 * DIM1 * DIM2 * DIM3);

    // using the pointer we are accessing the 4-dimensional array.
    for (pointer = (float *)set; pointer < (float *)set + DIM0 * DIM1 * DIM2 * DIM3; ++pointer)
        subTotal2 += *pointer;

    // calculate the average using the linear method by pointer
    *linearAvg = subTotal2 / (DIM0 * DIM1 * DIM2 * DIM3);
}
