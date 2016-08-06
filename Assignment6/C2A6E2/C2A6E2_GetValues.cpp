// Name:Balram Panwar
// Email id: balram.panwar@gmail.com
// Name of the file: C2A6E2_GetValues.cpp
// Win7
// Microsoft Visual Studio
//
// This file contains:
// Function GetValues : prompt the user to input elements whitespace-separated 
// floating point values, which it then reads with cin and stores into the 
// successive elements of the array in first starting with element 0.
//

#include <cstdlib>
#include <iostream>
using namespace std;
// 
// Function GetValues : prompt the user to input elements whitespace-separated 
// floating point values, which it then reads with cin and stores into the 
// successive elements of the array in first starting with element 0.
//
float *GetValues(float *first, size_t elements)
{  
    // Enter the array elements
    cout << "Enter the values for the array \n";
    for (size_t noofelement = 0; noofelement < elements; noofelement++)
    {
        // Collecting the input value from the prompt
        cin >> first[noofelement];
    }
    return first;
}
