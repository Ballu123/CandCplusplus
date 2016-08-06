// Name:Balram Panwar,
// Email id: balram.panwar@gmail.com
// Name of the file: C2A4E1_WorkerFunction.cpp
// Win7
// Microsoft Visual Studio
//
// function WorkerFunction : making the function call to the two diffent functions
// RandomizeArray() and ComputeAverages(). Both the function are called from the 
// workerfunction and also declaring the testarray which is 4 Dimensional array
// 

#include "C2A4E1_ArraySize.h"

void RandomizeArray(float set[][DIM1][DIM2][DIM3]);
void ComputeAverages(float set[][DIM1][DIM2][DIM3], float *nestedAvg, float *linearAvg);
//
// function WorkerFunction : making the function call to the two diffent functions
// RandomizeArray() and ComputeAverages(). Both the function are called from the 
// workerfunction and also declaring the testarray which is 4 Dimensional array
// 
void WorkerFunction(float *nestedAvg, float *linearAvg)
{
    float testArray[DIM0][DIM1][DIM2][DIM3];
    RandomizeArray(testArray);
    ComputeAverages(testArray, nestedAvg, linearAvg);
}
