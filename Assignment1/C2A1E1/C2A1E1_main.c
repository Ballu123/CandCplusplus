/*
 *Name:Balram Panwar,
 *Email id: balram.panwar@gmail.com
 *Name of the file: C2A1E1_main.c
 *Win7
 *Microsoft Visual Studio
 *
 *Macro Sum : return sum of two numbers
 *Macro Elements :  return the number of elements in an array
 *Function CreateArray : Dynamically allocating memory for an array for element count
 *Function OpenFile : Opening a file in binary read and append mode and error checking
 *Function CopyString : Copy string from source to destination
 *Function DisplayClearedArray: Display the value of each element in an array
 *Function Main: Display content of printf statement
 */

#include <stdio.h>
#include <stdlib.h>
/*
 *Macro Sum : return sum of two numbers
 */
#define Sum(addend1, addend2) ((addend1) + (addend2))
/*
*Macro Elements :  return the number of elements in an array
*/
#define Elements(arrayDesig) ((sizeof(arrayDesig))/(sizeof(*(arrayDesig))))
/*
 *CreateArray : Dynamically allocating memory for element of an array
 */
long *CreateArray(size_t elementCount)
{
	long *Noofelments = (long *)malloc(elementCount * sizeof(Noofelments));
	if (Noofelments == NULL)
	{
		fprintf(stderr, "Malloc failed\n");
		exit(EXIT_FAILURE);
	}
	return Noofelments;
}
/*
 *OpenFile : Opening a file in binary read and append mode and error checking
 */
FILE *OpenFIle(const char *filePath)
{
	FILE *fp;
	fp = fopen(filePath, "a+b");
	if (fp == NULL)
	{
		fprintf(stderr, "Can not open %s path", filePath);
		exit(EXIT_FAILURE);
	}
	return fp;
}
/*
 *CopyString : Copy string from source to destination
 */
void CopyString(char *destination, const char *source)
{
	while (*source)
	{
		*destination = *source;
		destination++;
		source++;
	}
	*destination = '\0';
}
/*
 *DisplayClearedArray: Display the value of each element in an array
 */
void DisplayClearedArray()
{
	double testArray[sizeof(long double)] = { 0 };
	int length = sizeof(testArray) / sizeof(testArray[0]);
	int arraycount = 0;
	/* Display all the elements on separate lines*/
	for (arraycount = 0; arraycount < length; arraycount++)
	{
		printf("%lf\n", testArray[arraycount]);
	}
}
/*
*Main: Display content of printf statement
*/
int main(void)
{
	printf("Assignment 1 Exercise 1 Complete!\n");
	return (EXIT_SUCCESS);
}
