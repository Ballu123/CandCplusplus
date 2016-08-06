/*
 * Name:Balram Panwar
 * Email id : balram.panwar@gmail.com
 * Name of the file : C2A6E1_GetPointers.c 
 * Win7
 * Microsoft Visual Studio
 *
 * GetPrintfPointer: Declares a pointer named pPrintf of appropriate type to point to the standard
 * library printf function and initializes it to point to that function.
 * GetPutsPointer : Declares a pointer named pPuts of appropriate type to point to the standard  
 * library puts function  and initializes it to point to that function.
 */
#include <stdio.h>
/*
 * GetPrintfPointer: Declares a pointer named pPrintf of appropriate type to point to the standard
 * library printf function and initializes it to point to that function.
 */
int (*GetPrintfPointer(void))(const char *format, ...)
{
    int (*pPrintf)(const char *format, ...);
    int printf(const char *format, ...);
    pPrintf = printf;
    return pPrintf;
}
/*
 * GetPutsPointer : Declares a pointer named pPuts of appropriate type to point to the standard
 * library puts function  and initializes it to point to that function.
 */
int (*GetPutsPointer(void))(const char *str)
{
    int (*pPuts)(const char *str);
    int puts(const char *str);
    pPuts = puts;
    return pPuts;
}
