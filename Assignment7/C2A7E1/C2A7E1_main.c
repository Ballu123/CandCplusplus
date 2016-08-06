/*
 * Name:Balram Panwar
 * Email id : balram.panwar@gmail.com
 * Name of the file : C2A7E1_main.c
 * Win7
 * Microsoft Visual Studio
 *
 * Function CreateTable : CreateTable creates and initializes the hash table and its bins 
 * Function BuildList : BuildList will search bin bp of the list for a node representing
 * the string in str.  If found, its string count will be incremented.
 * If not found, a new node for that string will be created, put at
 * the top of the list, and its string count set to 1.
 * Function BuildTree will search the binary tree at pNode for a node representing the
 * string in str.  If found, its string count will be incremented.  If not
 * found, a new node for that string will be created, put in alphabetical
 * order, and its count set to 1.  A pointer to the node for string str is returned
 * FunctionPrintTree recursively prints the binary tree in pNode alphabetically 
 * Function FreeTree recursively frees the binary tree in pNode
 * Function PrintTable prints the hash table
 * Function FreeTable frees the hash table 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_LEN 256                 /* size of input buffer */
#define BUFFMT "%255"                /* field width for input buffer scan */

#ifdef TREE
#else
#define MIN_ARGS 3
#define FILE_ARG_IX 1
#define BINS_ARG_IX 2

typedef struct Node NODE;
struct Node
{
    char *strng;
    size_t count;
    NODE *next;
};
struct binaryNode
{
    char *strng;
    size_t count;
    struct binaryNode *left, *right;
};
/* type of table array elements */
typedef struct
{
    size_t nodes;
    NODE *firstNode;
} BIN;
/* type of hash table descriptor */
typedef struct
{
    size_t bins;
    BIN *firstBin;
} TABLE;

/* checking the allocated memory error */
void *SafeMalloc(size_t size)
{
    void *vp;
    /* checking the allocated memory error */
    if ((vp = malloc(size)) == NULL)
    {
        fputs("Out of memory\n", stderr);
        exit(EXIT_FAILURE);
    }
    return(vp);
}

/* Opening the file and error checking */
FILE *OpenFile(const char *fileName)
{
    FILE *fp;
    /* Opening the file and error checking */
    if ((fp = fopen(fileName, "r")) == NULL)
    {
        fprintf(stderr, "File %s didn't open.\n", fileName);
        perror(fileName);
        exit(EXIT_FAILURE);
    }
    return fp;
}
/* get bin value from key */
int HashFunction(const char *key, size_t bins)
{
    return((int)(strlen(key) % bins));
}

/* CreateTable creates and initializes the hash table and its bins */
TABLE *CreateTable(size_t bins)
{
    TABLE *hashTable;
    BIN *bin, *end;
    hashTable = (TABLE *)SafeMalloc(sizeof(TABLE));   /* alloc desc struct */
    hashTable->bins = bins;                           /* how many bins */
    /* alloc bins */
    hashTable->firstBin = (BIN *)SafeMalloc(bins * sizeof(BIN));
    end = hashTable->firstBin + bins;
    /* initialize bins */
    for (bin = hashTable->firstBin; bin < end; ++bin)
    {
        bin->nodes = 0;
        bin->firstNode = NULL;
    }
    return(hashTable);
}
/*
 * BuildList will search bin bp of the list for a node representing
 * the string in str.  If found, its string count will be incremented.
 * If not found, a new node for that string will be created, put at
 * the top of the list, and its string count set to 1.
 */
void BuildList(BIN *bp, const char *str)
{
    /* creating the node of type NODE*/
    NODE *pNode = bp->firstNode;
    /* comparing the pNode with new string */
    for (; pNode != NULL; pNode = pNode->next)
        if (!strcmp(pNode->strng, str))
            break;
    if (pNode == NULL)
    {
        size_t length = strlen(str) + 1;
        /* allocating the memory for the NODE*/
        pNode = (NODE *)SafeMalloc(sizeof(NODE));
        pNode->strng = (char *)SafeMalloc(length);
        memcpy(pNode->strng, str, length);
        pNode->count = 1;
        pNode->next = bp->firstNode;
        bp->firstNode = pNode;
        ++bp->nodes;
    }
    else
        ++pNode->count;
}
/*
 * BuildTree will search the binary tree at pNode for a node representing the
 * string in str.  If found, its string count will be incremented.  If not
 * found, a new node for that string will be created, put in alphabetical
 * order, and its count set to 1.  A pointer to the node for string str is
 * returned.
 */
struct binaryNode *BuildTree(struct binaryNode *pNode, char *str, size_t countNo)
{
    /* checking initial element of the binary tree*/
    if (pNode == NULL)
    {
        size_t length = strlen(str) + 1;
        /* allocate a node */
        pNode = (struct binaryNode *)SafeMalloc(sizeof(struct binaryNode));
        pNode->strng = (char *)SafeMalloc(length);
        memcpy(pNode->strng, str, length);
        pNode->count = countNo;
        pNode->left = pNode->right = NULL;
    }
    else
    {
        /* comparing the node with the string */
        int result = strcmp(str, pNode->strng);
        if (result == 0)
            ++pNode->count;
        else if (result < 0)
            pNode->left = BuildTree(pNode->left, str, countNo);
        else
            pNode->right = BuildTree(pNode->right, str, countNo);
    }
    return(pNode);
}

/* PrintTree recursively prints the binary tree in pNode alphabetically */
void PrintTree(const struct binaryNode *pNode)
{
    /*Printing the binary tree in pNode alphabetically */
    if (pNode != NULL)
    {
        PrintTree(pNode->left);
        printf("%4d  %s\n", (int)pNode->count, pNode->strng);
        PrintTree(pNode->right);
    }
}
/*  FreeTree recursively frees the binary tree in pNode */
void FreeTree(struct binaryNode *pNode)
{
    /*Free the binary tree Node */
    if (pNode != NULL)
    {
        FreeTree(pNode->left);
        FreeTree(pNode->right);
        free(pNode->strng);
        free(pNode);
    }
}
/*PrintTable prints the hash table */
void PrintTable(const TABLE *hashTable)
{
    BIN *bin, *end;
    end = hashTable->firstBin + hashTable->bins;     /* end of bins */
    for (bin = hashTable->firstBin; bin < end; ++bin)  /* visit bins */
    {
        NODE *node = bin->firstNode;
        struct binaryNode *temp = NULL;
        printf("%d entries for bin %d:\n", (int)bin->nodes, (int)(bin - hashTable->firstBin));
        /* Print Tree in the every bin of the hash table */
        while (node != NULL)
        {
            temp = BuildTree(temp, node->strng, node->count);
            node = node->next;
        }
        PrintTree(temp);
        FreeTree(temp);
    }
}

/* FreeTable frees the hash table */
void FreeTable(TABLE *hashTable)
{
    BIN *bin, *end;
    end = hashTable->firstBin + hashTable->bins;
    /* traversing the bin for FreeTable of the hash table */
    for (bin = hashTable->firstBin; bin < end; ++bin)
    {
        NODE *node;
        /* traversing the every node of the bin */
        for (node = bin->firstNode; node != NULL;)
        {
            NODE *pNode = node;
            node = node->next;
            free(pNode->strng);
            free(pNode);
        }
    }
    free(hashTable->firstBin);
    free(hashTable);
}

int main(int argc, char *argv[])
{
    char buf[LINE_LEN];              /* word string buffer */
    char fileName[LINE_LEN];         /* file name buffer */
    int howManyBins;                 /* number of bins to create */
    TABLE *hashTable;                /* pointer to hash table */
    FILE *fp;

    /* Read file name from command line */
    if (argc < MIN_ARGS || sscanf(argv[FILE_ARG_IX], BUFFMT "s", fileName) != 1)
    {
        fprintf(stderr, "No file name specified on command line\n");
        return EXIT_FAILURE;
    }
    fp = OpenFile(fileName);

    /* Read bin count from command line */
    if (sscanf(argv[BINS_ARG_IX], "%d", &howManyBins) != 1)
    {
        fprintf(stderr, "No bin count specified on command line\n");
        return EXIT_FAILURE;
    }
    hashTable = CreateTable((size_t)howManyBins);  /* allocate table array */

    /*
     * The following loop will read one string at a time from stdin until
     * EOF is reached.  For each string read the BuildList function will
     * be called to update the hash table.
     */
    while (fscanf(fp, BUFFMT "s", buf) != EOF) /* get string from file */
    {
        /* find appropriate bin */
        BIN *bin = &hashTable->firstBin[HashFunction(buf, (size_t)howManyBins)];
        BuildList(bin, buf);
    }
    fclose(fp);
    PrintTable(hashTable);
    FreeTable(hashTable);
    return(EXIT_SUCCESS);
}
#endif
