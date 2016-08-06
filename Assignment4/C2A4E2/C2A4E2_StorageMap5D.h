#ifndef C2A4E2_STORAGEMAP5D_H
#define C2A4E2_STORAGEMAP5D_H

/*
 * Name:Balram Panwar
 * Email id: balram.panwar@gmail.com
 * Name of the file: C2A4E2_StorageMap5D.h
 * Win7
 * Microsoft Visual Studio
 *
 * Macro StorageMap5D: implements the storage map equation for a 5 Dimensional array
 * of arbitrary type. It may be used to access the elements of any existing 5 
 * dimensional array of any type
 */

/*
 * Macro StorageMap5D : implements the storage map equation for a 5 Dimensional array
 * of arbitrary type.It may be used to access the elements of any existing 5
 * dimensional array of any type
 */

#define StorageMap5D(ptr, idx0, idx1, idx2, idx3, idx4, dim1, dim2, dim3, dim4) \
 (*((ptr) + ((idx0)*(dim1)*(dim2)*(dim3)*(dim4)) + ((idx1)*(dim2)*(dim3)*(dim4)) \
 + ((idx2)*(dim3)*(dim4)) + ((idx3)*(dim4)) + (idx4)))

#endif
