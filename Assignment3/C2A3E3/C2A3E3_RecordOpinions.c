/*
 * Name:Balram Panwar
 * Email id: balram.panwar@gmail.com
 * Name of the file: C2A3E3_RecordOpinions.c
 * Win7
 * Microsoft Visual Studio
 *
 * Function RecordOpinions : Prompts users for their ratings of a product 
 *  and counts the quantity of each rating.
 * Function Dispaly : Display a table of the total quantity of each rating
 * Function checkEndpoint : checking the Endpoint value enter by the users.
 * Function checkTerminate : checking the Termination value enter by the users.
 */
#include <stdio.h>

# define TWOVAL 2
/*
 *Function Dispaly : Display a table of the total quantity of each rating
 */
static void Display(int endpoint, int *Responses)
{
    int quality = 0;
    printf("Rating    Responses\n");
    printf("------    ---------\n");
    for (quality = -endpoint; quality <= endpoint; quality++)
    {
        printf("%2d  %8d\n", quality, Responses[quality]);
    }
}
/*
 *Function checkEndpoint : checking the Endpoint value enter by the users.
 */
static int checkEndpoint(int value, int endpoint)
{
    if (-endpoint <= value && value <= endpoint)
    {
        return 1;
    }
    return 0;
}
/*
 *Function checkTerminate : checking the Termination value enter by the users.
 */
static int checkTerminate(int value, int terminate)
{
    if (terminate == value)
    {
        return 1;
    }
    return 0;
}
/*
 *Function RecordOpinions : Prompts users for their ratings of a product
 *  and counts the quantity of each rating.
 */
void RecordOpinions(void)
{
    int terminate;
    int endpoint;
    int value;
    int arrayindex;
    printf("Enter the Endpoint : ");
    scanf("%d", &endpoint);
    printf("Enter the Terminate : ");
    scanf("%d", &terminate);
    int *Responses = (int *)calloc((TWOVAL * (endpoint))+1, sizeof(int));
    for (arrayindex = -endpoint; arrayindex <= endpoint; arrayindex++)
    {
        Responses[arrayindex] = 0;
    }
    int valueScan = scanf("%d", &value);
    for (;;)
    {
        if (valueScan == 1)
        {
            if (checkTerminate(value, terminate) == 1)
            {
                Display(endpoint, Responses);
            }
            else
            {
                if (checkEndpoint(value, endpoint) == 1)
                {
                    Responses[value]++;
                }
                valueScan = scanf("%d", &value);                
            }
        }
    }
}
