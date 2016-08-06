/*
 * Name:Balram Panwar
 * Email id : balram.panwar@gmail.com
 * Name of the file : C2A7E4_OpenTemporaryFile.c
 * Win7
 * Microsoft Visual Studio
 *
 * Function OpenTemporaryFile: Opens a temporary file using the standard library 
 * tmpfile function. If the open fails an error message is output to stderr 
 * and the program is terminated with an error exit code. 
 */
#include <stdio.h>
#include <stdlib.h>

/*
 * OpenTemporaryFile: Opens a temporary file using the standard library
 * tmpfile function.If the open fails an error message is output to stderr
 * and the program is terminated with an error exit code.
 */
FILE *OpenTemporaryFile(void)
{
    FILE *fp;
    /* opening the tmpfile*/
    fp = tmpfile();
    /* checking the error in the tmpfile */
    if (fp == NULL)
    {
        fprintf(stderr, "Failed to open file \n");
        exit(EXIT_FAILURE);
    }
    fflush(fp);
    return fp;
}
