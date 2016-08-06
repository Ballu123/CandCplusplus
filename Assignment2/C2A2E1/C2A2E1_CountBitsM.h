/*
 * Name:Balram Panwar, 
 * Email id: balram.panwar@gmail.com
 * Name of the file: C2A2E1_CountBitsM.h
 * Win7
 * Microsoft Visual Studio
 *
 * This file contains:
 * Macro CountBitsM : Determine the no. of bits in any ObjectType 
 */

#include <limits.h>

/* 
 * CountBitsM determine the no. of bits in any data type
 */
#define CountBitsM(objectOrType) ((int)(sizeof(objectOrType) * CHAR_BIT))
