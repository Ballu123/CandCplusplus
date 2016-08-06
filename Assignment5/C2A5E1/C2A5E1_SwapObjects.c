/*
 * Name:Balram Panwar
 * Email id: balram.panwar@gmail.com
 * Name of the file: C2A5E1_SwapObjects.c
 * Win7
 * Microsoft Visual Studio
 *
 * Function SwapObjects : it will swap the object pa and pb
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
/* 
 * Function SwapObjects will swap the object pa and pb
 * and dynamically creating the memory for temp allocation.
 */
void SwapObjects(void *pa, void *pb, size_t size)
{
    // dynamically allocating memory
    void *temp = malloc(size);
    if (!temp)
    {
        printf("malloc() failed!");
        return;
    }
    memcpy(temp, pb, size);
    memcpy(pb, pa, size);
    memcpy(pa, temp, size);
    free(temp);
}
