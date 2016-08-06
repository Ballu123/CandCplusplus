// Name:Balram Panwar,
// Email id: balram.panwar@gmail.com
// Name of the file: C2A2E2_Rotate.cpp
// Win7
// Microsoft Visual Studio
//
// This file contains:
// Function Rotate : Rotate all bits in objects by the number of bits positions
//
int CountIntBitsF(void);

// Rotates all bits in objects by the number of bit positions and 
// direction specified by count. If the count is negative , rotation is left side
// or if the count is positive, rotation is right side.
unsigned Rotate(unsigned object, int count)
{
    int noOfBits = CountIntBitsF();
    if (count > 0)
    {
        return (object >> count) | (object << (noOfBits - count));
    }
    else 
    {
        count = -count;
        return (object << count) | (object >> (noOfBits - count));
    }
}
