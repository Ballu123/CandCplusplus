/*
 * Name:Balram Panwar
 * Email id : balram.panwar@gmail.com
 * Name of the file : C2A6E4_List.c
 * Win7
 * Microsoft Visual Studio
 *
 * function CreateList :Reads strings from the text file in fp and creates a new non-sorted
 * singly-linked list in which each node represents a unique case-dependent string found 
 * in the file. As each string is read the current list is searched for a node that may 
 * already exist for that string. If one is found, its string occurrence count is merely
 * incremented. If none is found, a new node is created at the head of the list  (pushed) 
 * to represent the new string, and its occurrence count is set to 1. Reading of the file
 * stops when EOF is reached.
 * function  PrintList : Displays a non-sorted table of the data attributes from the list 
 * whose head pointer is passed to it, starting at the head of the list. The display must 
 * be in the format illustrated on the next page, in which the first character in each 
 * string is aligned and the least significant digits of the occurrence counts are aligned.
 * function FreeList : The FreeList function must call no functions or macros other than 
 * the standard library free  function, which it may call as needed.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "C2A6E4_List-Driver.h"

#define NO_OF_CHAR 256
/*
 * function CreateList : Reads strings from the text file in fp and creates a new non - sorted
 * singly - linked list in which each node represents a unique case-dependent string found
 * in the file.As each string is read the current list is searched for a node that may
 * already exist for that string.If one is found, its string occurrence count is merely
 * incremented.If none is found, a new node is created at the head of the list(pushed)
 * to represent the new string, and its occurrence count is set to 1. Reading of the file
 * stops when EOF is reached.
 */
List *CreateList(FILE *fp)
{
    char buffer[NO_OF_CHAR];
    List *head = NULL, *temp;
    int found;
    while (!feof(fp))
    {       
        fscanf(fp, "%255s", buffer);
        temp = head;
        found = 0;
        /* checking if the string is present in the list*/
        while (temp != NULL)
        {
            if (strcmp(temp->str, buffer) == 0)
            {
                ++temp->count;
                found = 1;
            }   
            temp = temp->next;
        }
        /* if the string is first time */        
        if (found == 0)
        {   
            /* calculate the length of the string */
            size_t length = strlen(buffer);
            /* allocating the memory for the new list */
            List *newNode = (List *)malloc(sizeof(List));
            /* checking the fail allocation of the list */
            if (newNode == NULL)
            {
                fprintf(stderr, "failed to allocate memory\n");
                exit(EXIT_FAILURE);
            }
            /* allocating the memory for the new string */
            newNode->str = (char *)malloc(length + 1);
            /* checking the fail allocation of the string */
            if (newNode->str == NULL)
            {
                fprintf(stderr, "failed to allocate memory\n");
                exit(EXIT_FAILURE);
            }
            newNode->count = 1;
            memcpy(newNode->str, buffer, length + 1);
            newNode->next = head;
            head = newNode;
        }        
    }
    return head;
}
/*
 * function PrintList : Displays a non - sorted table of the data attributes from the list
 * whose head pointer is passed to it, starting at the head of the list.The display must
 * be in the format illustrated on the next page, in which the first character in each
 * string is aligned and the least significant digits of the occurrence counts are aligned.
 */
List *PrintList(const List *head)
{
    const List *current = head;
    /* checking the list is empty or not*/
    if (current == NULL)
        return NULL;
    else
    {
        /* traversing the list and printing every item in the list*/
        while (current != NULL)
        {
            printf("%-15s %15d ea\n", current->str, current->count);
            current = current->next;
        }        
    }
    return (List *)head;
}
/*
 * function FreeList : The FreeList function must call no functions or macros other than
 * the standard library free  function, which it may call as needed.
 */
void FreeList(List *head)
{
    List *current = head;
    /* checking the list is empty or not*/
    if (current == NULL)
        return;
    else
    {
        /* traversing the list and deleting every item in the list*/
        while ((current = head) != NULL)
        {
            head = head->next;
            free(current->str);
            free(current);
        }
    }
}
