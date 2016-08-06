/*
 * Name:Balram Panwar
 * Email id : balram.panwar@gmail.com
 * Name of the file : C2A7E4_ProcessStructures.c
 * Win7
 * Microsoft Visual Studio
 *
 * Function ReverseMembersEndian: Calls ReverseEndian for each member of 
 * the structure in ptr, thereby converting each from big endian to little endian
 * format or vice versa. ReverseEndian will fail if the member is not scalar or 
 * contains padding.
 * 1. Were the results you got correct for your implementation?
 * Answer : It is depand upon the machine of your system. According to my 
 * system, it looks like OK to me.
 * 2. How many padding bytes were in your structure? 
 * Answer : 8 bytes
 * Function ReadStructures: Reads count structures from fp and stores them in memory 
 * starting at address ptr. If count structures can't be read an error message
 * is output to stderr and the program is terminated with an error exit code
 * Function WriteStructures: Reads count structures from memory starting at address
 * ptr and writes them to the file fp. If count structures can't be written an
 * error message is output to stderr and the program is terminated with an error exit code.
 */
#include <stdio.h>
#include <stdlib.h>
#include "C2A7E4_Test-Driver.h"
#define FLOATVAL (ptr->flt)
#define DOUVBLEVAL (ptr->dbl)
#define VOIDVAL (ptr->vp)
void *ReverseEndian(void *ptr, size_t size);
/*
 * Function ReverseMembersEndian : Calls function ReverseEndian for each member of
 * the structure in ptr, thereby converting each from big endian to little endian
 * format or vice versa.ReverseEndian will fail if the member is not scalar or
 * contains padding.
 */
struct Test *ReverseMembersEndian(struct Test *ptr)
{
    /* allocating memory for the structure*/
    ReverseEndian((void *)&FLOATVAL, sizeof(FLOATVAL));
    ReverseEndian((void *)&DOUVBLEVAL, sizeof(DOUVBLEVAL));
    ReverseEndian((void *)&VOIDVAL, sizeof(VOIDVAL));
    return ptr;
}
/*
 * Function ReadStructures : Reads count structures from fp and stores them in memory
 * starting at address ptr.If count structures can't be read an error message
 * is output to stderr and the program is terminated with an error exit code
 */
struct Test *ReadStructures(struct Test *ptr, size_t count, FILE *fp)
{
    size_t element;
    /* traversing for the every struct in the file */
    for (element = 0; element < count; element++)
    {
        /* Reading from the file */
        size_t read = fread(&ptr[element], sizeof(*ptr), 1, fp);
        /*checking the read */
        if (read != 1)
        {
            fprintf(stderr, "Failed to read\n");
            exit(EXIT_FAILURE);
        }
    }
    return ptr;
}
/*
 * Function WriteStructures : Reads count structures from memory starting at address
 * ptr and writes them to the file fp.If count structures can't be written an
 * error message is output to stderr and the program is terminated with an error exit code.
 */
struct Test *WriteStructures(const struct Test *ptr, size_t count, FILE *fp)
{
    struct Test *pt = (struct Test *)ptr;
    size_t element;
    /* traversing for the every struct to write in the file */
    for (element = 0; element < count; element++)
    {
        /* writing to the file */
        size_t written = fwrite(&pt[element], sizeof(*pt), 1, fp);
        /* checking the write to the file */
        if (written != 1)
        {
            fprintf(stderr, "Failed to write\n");
            exit(EXIT_FAILURE);
        }
    }
    return pt;
}
