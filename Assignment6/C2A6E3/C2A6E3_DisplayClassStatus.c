/*
 * Name:Balram Panwar
 * Email id : balram.panwar@gmail.com
 * Name of the file : C2A6E3_DisplayClassStatus.c
 * Win7
 * Microsoft Visual Studio
 *
 * function Compare : Compares the names represented by elemA and elemB 
 * using the standard library function strcmp
 * function SortStudents : Uses the standard library qsort function and the 
 * Compare function above to sort the array in studentList into alphabetical order 
 * function DisplayClassStatus : Determines and displays which of the registrants did not 
 * attend the first meeting by repeatedly calling the standard library bsearch function 
 * to search the attendees array for each name in the registrants array.
 * Determines and displays which of the attendees were not registered by repeatedly calling 
 * bsearch to search the registrants array for each name in the attendees array.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
 * function Compare : Compares the names represented by elemA and elemB
 * using the standard library function strcmp
 */
int Compare(const void *elemA, const void *elemB)
{
    return(strcmp(*(char **)elemA, *(char **)elemB));
}
/*
 * function SortStudents : Uses the standard library qsort function and the
 * Compare function above to sort the array in studentList into alphabetical order
 */
void SortStudents(const char *studentList[], size_t studentCount)
{
    qsort((char *)studentList, studentCount, sizeof(studentList[0]), Compare);
}
/*
 * function DisplayClassStatus : Determines and displays which of the registrants did not
 * attend the first meeting by repeatedly calling the standard library bsearch function
 * to search the attendees array for each name in the registrants array.
 * Determines and displays which of the attendees were not registered by repeatedly calling
 * bsearch to search the registrants array for each name in the attendees array.
 */
void DisplayClassStatus(const char *registrants[], size_t registrantCount,
    const char *attendees[], size_t attendeeCount)
{
    size_t registval;
    size_t attCountval;
    printf("Not present:\n");
    /*displays which of the registrants did not attend the first meeting*/
    for (registval = 0; registval < registrantCount; registval++)
    {
        const char *key = registrants[registval];
        const char **key1 = &key;
        /*search which of the registrants did not attend the first meeting*/
        char *ptr = bsearch(key1, attendees, attendeeCount, sizeof(attendees[0]), Compare);
        if (ptr == NULL)
            printf("     %s \n", key);      
    }
    printf("Not registered:\n");
    /*displays which of the attendees were not registered*/
    for (attCountval = 0; attCountval < attendeeCount; attCountval++)
    {
        const char *key = attendees[attCountval];
        const char **key1 = &key;
        /*search which of the attendees were not registered*/
        char *ptr = bsearch(key1, registrants, registrantCount, sizeof(registrants[0]), Compare);
        if (ptr == NULL)
            printf("     %s \n", key);
    }
}
