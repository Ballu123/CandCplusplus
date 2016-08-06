/*
 * Name:Balram Panwar
 * Email id : balram.panwar@gmail.com
 * Name of the file : C2A7E3_ReverseEndian.c
 * Win7
 * Microsoft Visual Studio
 *
 * ReverseEndian: Swaps the bytes in the object in ptr, thereby converting
 * it from big endian to little endian or vice versa
 */
#include <stdio.h>
#include <stdlib.h>
/*
 * ReverseEndian: Swaps the bytes in the object in ptr, thereby converting
 * it from big endian to little endian or vice versa
 */
void *ReverseEndian(void *ptr, size_t size)
{
    char *p = ptr;
    size_t lo, hi;
    /* swapping using the the temp varialbe */
    for (lo = 0, hi = size - 1; hi > lo; lo++, hi--)
    {
        char tmp = p[lo];
        p[lo] = p[hi];
        p[hi] = tmp;
    }
    return p;
}
