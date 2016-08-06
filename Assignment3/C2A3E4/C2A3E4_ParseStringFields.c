/*
 *Name:Balram Panwar,
 *Email id: balram.panwar@gmail.com
 *Name of the file: C2A3E4_ParseStringFields.c
 *Win7
 *Microsoft Visual Studio
 *
 *Function ParseStringFields : this function uses the strkok function to 
 * find each delimited field and display it on a separate output line.
 *Function checkingWhitespace : checking the whitespace at the beginning 
 * of the line
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define NO_OF_CHAR 254

/*
 * checkingWhitespace function is checking all the whitespace at the beginning of any
 * field and using the standard isspace function to skip all the whitespace
 */
static char *checkingWhitespace(char *line)
{
    char *start = line;
    while (isspace(*start))
    {
        start++;
    }
    line = start;
    return line;
}
/*
 * ParseStringFields function will read a text file by Fp one line at a time and 
 * use the strtok function to find each delimited filed and printout it on a separate
 * output line in which all whitespace at the beginning of any field is skipped
 */
void ParseStringFields(FILE *fp)
{
    char line[NO_OF_CHAR];
    const char *delimiters = "AEIOUaeiou\n";    
    while (fgets(line, sizeof(line), fp) != NULL)
    {
        char *withoutSpace = checkingWhitespace(line);
        char *value = strtok(withoutSpace, delimiters);
        while (value != NULL)
        {
            printf("%s\n", value);
            value = strtok(NULL, delimiters);
        }
        printf("\n");
    }
}
