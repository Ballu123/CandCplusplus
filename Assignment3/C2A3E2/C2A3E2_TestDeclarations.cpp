// Name:Balram Panwar,
// Email id: balram.panwar@gmail.com
// Name of the file: C2A3E2_TestDeclarations.cpp
// Win7
// Microsoft Visual Studio
//
// Declaration of void pointer and intialize vp to 0;
// function fcnA take a integer paramater and retrun an Integer
// Declare ppa is a pointer to a pointer to an array of 9 floats
// Declare rppa is a reference to a pointer to a pointer to an array 
//  of 9 floats and initialize rppa to ppa 
// Type cast to a pointer to a pointer to an array of 9 floats

void TestDeclarations()
{
    // Declaration of void pointer and intialize vp to 0;
    void *vp=0;
    // function fcnA take a integer paramater and retrun an Integer
    int fcnA(int val);
    // Declare ppa is a pointer to a pointer to an array of 9 floats
    float **ppa[9];
    // Declare rppa is a reference to a pointer to a pointer to an array 
    //  of 9 floats and initialize rppa to ppa 
    float **(&rppa)[9] = ppa;
    // Type cast to a pointer to a pointer to an array of 9 floats
    ppa = (*(float *)vp)[9] ;
}
