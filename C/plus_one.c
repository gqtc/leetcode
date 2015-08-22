/*****************************************************
Given a non-negative number represented as an array of digits, 
plus one to the number.

The digits are stored such that the most significant digit is at the 
head of the list.

*******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) 
{
    int *res = calloc(digitsSize+1, sizeof(int));

    int i;
    int addbit = 1;
    int bitres = 0;
    
    for(i = digitsSize-1; i >= 0; i--)
    {
        bitres = digits[i]+addbit;
        res[i+1] = bitres%10;
        addbit = bitres/10;
    }
    if(addbit)
    {
        res[i+1] = addbit;
        *returnSize = digitsSize+1;
    }
    else
    {
        memmove(res, res+1, digitsSize*sizeof(int));
        *returnSize = digitsSize;
    }
    return res;
}


int main()
{
	//int bitsets[] = {1, 2, 3};
	int bitsets[] = {9, 9, 9};
	int setslen = sizeof(bitsets)/sizeof(int);
	
	int *res;
	int reslen = 0;
	int i;
	
	res = plusOne(bitsets, setslen, &reslen);
	for(i = 0; i < setslen; i++)
	{
		printf("%d", bitsets[i]);
	}
	printf(" + 1 = ");
	for(i = 0; i < reslen; i++)
	{
		printf("%d", res[i]);
	}
	printf("\n");
}
