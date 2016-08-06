/*
 * Name:Balram Panwar
 * Email id : balram.panwar@gmail.com
 * Name of the file : C2A5E2_Create2D.c
 * Win7
 * Microsoft Visual Studio
 *
 * function Create2D : Creates a 2-dimensional pointer array of data type Type having   
 * the number of rows and columns 21 specified by rows and cols. All memory needed  
 * for this array is dynamically-allocated at once 22 using a single call to the
 * appropriate memory allocation function
 * function  Free2D : it will free all the memory which is allocated by the Create2D
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "C2A5E2_Type-Driver.h"
/*
 * Creates a 2 - dimensional pointer array of data type Type having the number of
 * rows and columns 21 specified by rows and cols.All memory needed for this array
 * is dynamically - allocated at once 22 using a single call to the appropriate memory
 * allocation function
 */
Type **Create2D(size_t rows, size_t cols)
{
    size_t value;
    Type *buf;
    /* prows allocate contiguous block using the header and rows */
    Type **prows = (Type **)malloc((rows * sizeof(Type *)) + (rows * cols * sizeof(Type)));
    /* checking the error for prows */
    if (prows == NULL)
    {
        fputs("Out of Memory\n", stderr);
        exit(EXIT_FAILURE);
    }
    /* allocation of all the rows */
    buf = (Type *)(prows + rows);
    for (value = 0; value < rows; ++value)
    {
        prows[value] = buf + value * cols;
    }
    return prows;
}
/*
 * function  Free2D : it will free all the memory which is allocated by the Create2D
 */
void Free2D(void *p)
{
    free(p);
}
