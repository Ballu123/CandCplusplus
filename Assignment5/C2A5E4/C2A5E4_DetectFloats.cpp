// Name:Balram Panwar,
// Email id: balram.panwar@gmail.com
// Name of the file: C2A5E4_DetectFloats.cpp
// Win7
// Microsoft Visual Studio
//
// This file contains:
// Function DetectFloats : it Analyzes the string and determine if it represents a 
// syntactically legal floating literal and if so, its data type
//
#include <fstream>
#include "C2A5E4_StatusCode-Driver.h"
using namespace std;

// 
// Function DetectFloats : it Analyzes the string and determine if it represents a 
// syntactically legal floating literal and if so, its data type
//
StatusCode DetectFloats(const char *chPtr)
{
    // create enum to store the states
    enum States
    {
        S0, S1, S2, S3, S4, S5, S6, S7, S8
    } state = S0;
    //creating the temp variable 
    char *temp = (char *)chPtr;
    // continous reading the string.
    for (;;)
    {
        char inChar = temp[0];
        temp++;
        switch (state)
        {
            case S0:
                if (inChar == '.')
                {
                    state = S2;
                }
                else if (isdigit(inChar))
                {
                    state = S1;
                }
                else
                {
                    return NOTFLOATING;
                }
                break;
            case S1:
                if (inChar == '.')
                {
                    state = S3;
                }
                else if (isdigit(inChar))
                {
                    state = S1;
                }
                else if (inChar == 'E' || inChar == 'e')
                {
                    state = S4;
                }
                else
                {
                    return NOTFLOATING;
                }
                break;
            case S2:
                if (isdigit(inChar))
                {
                    state = S3;
                }
                else
                {
                    return NOTFLOATING;
                }
                break;
            case S3:
                if (inChar == '\0')
                { 
                    return TYPE_DOUBLE;
                }
                else if (isdigit(inChar))
                {
                    state = S3;
                }
                else if (inChar == 'E' || inChar == 'e')
                {
                    state = S4;
                }
                else if (inChar == 'F' || inChar == 'f')
                {
                    state = S7;
                }
                else if (inChar == 'L' || inChar == 'l')
                {
                    state = S8;
                }
                else
                {
                    return NOTFLOATING;
                }
                break;
            case S4:
                if (isdigit(inChar))
                {
                    state = S6;
                }
                else if (inChar == '+' || inChar == '-')
                {
                    state = S5;
                }
                else
                {
                    return NOTFLOATING;
                }
                break;
            case S5:
                if (isdigit(inChar))
                {
                    state = S6;
                }
                else
                {
                    return NOTFLOATING;
                }
                break;
            case S6:
                if (inChar == '\0')
                { 
                    return TYPE_DOUBLE;
                }
                else if (isdigit(inChar))
                {
                    state = S6;
                }
                else if (inChar == 'F' || inChar == 'f')
                {
                    state = S7;
                }
                else if (inChar == 'L' || inChar == 'l')
                {
                    state = S8;
                }
                else
                {
                    return NOTFLOATING;
                }
                break;
            case S7:
                if (inChar == '\0')
                { 
                    return TYPE_FLOAT;
                }
                else
                {
                    return NOTFLOATING;
                }
            case S8:
                if (inChar == '\0')
                { 
                    return TYPE_LDOUBLE;
                }
                else 
                {
                    return NOTFLOATING;
                }
            default:
                return NOTFLOATING;
        }
    }
}
