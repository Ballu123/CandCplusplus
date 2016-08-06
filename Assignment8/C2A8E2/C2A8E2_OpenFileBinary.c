/*
 * Name:Balram Panwar
 * Email id : balram.panwar@gmail.com
 * Name of the file : C2A8E2_OpenFileBinary.c
 * Win7
 * Microsoft Visual Studio
 *
 * Function OpenFileBinary : Opens the file named in fileName in the read-only binary mode. 
 * If the open fails an error message is output to stderr and
 * the program is terminated with an error exit code.
 */
#include <stdio.h>
#include <stdlib.h>
/*
 * Opens the file named in fileName in the read - only binary mode.
 * If the open fails an error message is output to stderr and
 * the program is terminated with an error exit code.
 */
FILE *OpenFileBinary(const char *fileName)
{
    /* a pointer to the name of the file to be opened*/
    FILE *fp;
    fp = fopen(fileName, "rb");
    /* checking the error with the opened binary file*/
    if (fp == NULL)
    {
        fprintf(stderr, "Failed to open file %s \n", fileName);
        exit(EXIT_FAILURE);
    }
    return fp;
}
