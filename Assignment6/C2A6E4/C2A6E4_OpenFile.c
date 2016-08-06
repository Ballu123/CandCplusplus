/*
 * Name:Balram Panwar
 * Email id: balram.panwar@gmail.com
 * Name of the file: C2A6E4_OpenFile.c
 * Win7
 * Microsoft Visual Studio
 *
 * Function OpenFile : Opening the file in read-only text mode and error checking in it.
 */
#include <stdio.h>
#include <stdlib.h>
/*
 * OpenFile function opening a file in read-only text mode and error checking
 * for the file. It will exit from the error checking condition, if there is an
 * issue in opening the file
 */
FILE *OpenFile(const char *fileName)
{
    FILE *fp;
    fp = fopen(fileName, "r");
    /* checking the error while opening the file*/
    if (fp == NULL)
    {
        fprintf(stderr, "Can't open file %s \n", fileName);
        exit(1);
    }
    return fp;
}
