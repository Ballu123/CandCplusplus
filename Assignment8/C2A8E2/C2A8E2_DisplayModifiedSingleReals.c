/*
 * Name:Balram Panwar
 * Email id : balram.panwar@gmail.com
 * Name of the file : C2A8E2_DisplayModifiedSingleReals.c
 * Win7
 * Microsoft Visual Studio
 * function DisplayModifiedSingleReals : displays an aligned table in which hexa value
 * followed by Modified Single Real with plus or minus sign
 */
#include <stdio.h>
#include <math.h>

#define F_NORM      "Normal"
#define F_DENORM    "Denormal"
#define F_PZERO     "Zero"
#define F_NZERO     "Zero"
#define F_PINF      "+INF"
#define F_NINF      "-INF"
#define F_PNAN      "+NAN"
#define F_NNAN      "-NAN"

#define SIGN_MASK   0x80000000uL  
#define EXP_MASK    0x7FC00000uL
#define FRAC_MASK   0x003FFFFFuL
#define FRAC_BITS   22
#define EXP_NBIAS   255
#define EXP_DBIAS   254
#define EXP_MAX     511

#define COUNT       4
#define ZERO        0
#define ONE_NO      1
#define TWO_NO      2
#define TWO_F       2.0
#define THREE_NO    3
#define EIGHT_NO    8
#define ONE_SIX     16
#define TW_FOUR     24
/*
 * function DisplayModifiedSingleReals : displays an aligned table in which hexa value
 * followed by Modified Single Real with plus or minus sign
 */
void DisplayModifiedSingleReals(FILE *inFile)
{
    unsigned char pattern[COUNT];
    /* checking the end of the file. */
    while (!feof(inFile))
    {
        /* Reading the pattern from the file. */
        if (inFile != NULL)
        { 
            size_t count = fread(&pattern, ONE_NO, COUNT, inFile);
            if (count == COUNT)
            {
                unsigned int convert = ((unsigned long)(pattern[ZERO] & 0x000000FF) << TW_FOUR) +
                    ((unsigned long)(pattern[ONE_NO] & 0x000000FF) << ONE_SIX) +
                    ((unsigned long)(pattern[TWO_NO] & 0x000000FF) << EIGHT_NO) +
                    ((unsigned long)(pattern[THREE_NO] & 0x000000FF));
                /* true if negative value. */
                int signIsNegative = !!(SIGN_MASK & convert);
                /* value of the exponent field */
                int exponent = (EXP_MASK & convert) >> FRAC_BITS;
                /* value of the fraction field */
                long fraction = FRAC_MASK & convert;
                /* Test for negative and positive zero */
                if (exponent == 0 && fraction == 0)
                {
                    double result = 0;
                    char *status = signIsNegative ? F_NZERO : F_PZERO;
                    if (signIsNegative)
                    {
                        result = -result;
                        printf("%#010x %+15e %s\n", convert, result, status);
                    }
                    else
                        printf("0x%#08x %+15e %s\n", convert, result, status);
                }
                /* Test for negative and positive infinities */
                else if (exponent == EXP_MAX && fraction == 0)
                {
                    char *status = signIsNegative ? F_NINF : F_PINF;
                    printf("%#010x  %s\n", convert, status);
                }
                /* Test for negative and positive NANs */
                else if (exponent == EXP_MAX && fraction != 0)
                {
                    char *status = signIsNegative ? F_NNAN : F_PNAN;
                    printf("%#010x  %s\n", convert, status);
                }
                /* is Normailized and denormalized number */
                else
                {
                    int bias;
                    char *status;
                    /* value of fraction part */
                    double result = fraction * pow(TWO_F, -FRAC_BITS);
                    /* if number is normalized */
                    if (exponent != 0)
                    {
                        /* bias to use */
                        bias = EXP_NBIAS;
                        status = F_NORM;
                        /* add the implicit 1 integer part */
                        ++result;
                    }
                    /* else number is denormalized */
                    else
                    {
                        /* bias to use */
                        bias = EXP_DBIAS;
                        status = F_DENORM;
                    }
                    /* mantissa = mantissa*base of the exponent */
                    result = result * pow(TWO_F, exponent - bias);
                    /* if number is negative, negate the value */
                    if (signIsNegative)
                    {
                        result = -result;
                    }
                    printf("%#010x %+15e %s\n", convert, result, status);
                }
            }
            else
            {
		        if (count > 0)
                    printf("Unexpected  EOF\n");
            }
        }       
    }
}
