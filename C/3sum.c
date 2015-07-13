/*****************************************************
Given an array S of n integers, are there elements a, b, c in S such 
that a + b + c = 0? Find all unique triplets in the array which gives 
the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a<=b<=c)
The solution set must not contain duplicate triplets.

For example, given array S = {-1 0 1 2 -1 -4},
A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)

*******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int a2;
    int a3;
}SumNode;

void swap(int *a, int *b)
{
    int tmp;
    tmp = *b;
    *b = *a;
    *a = tmp;
}

int partition(int *set, int left, int right)
{
    int randint = rand()%(right-left+1) + left;
    swap(set+randint, set+right);
    int key = set[right];
    int i, j;
    i = left-1;
    for(j = left; j < right; j++)
    {
        if(set[j] < key)
        {
            i += 1;
            swap(set+i, set+j);
        }
    }
    swap(set+i+1, set+right);
    return i+1;
}

void qsort2(int *set, int left, int right)
{
    int q;
    if(left < right)
    {
        q = partition(set, left, right);
        qsort2(set, left, q-1);
        qsort2(set, q+1, right);
    }
    
}

SumNode *findsum(int *set, int size, int sum, int *Ssize)
{
	SumNode *res = calloc(size, sizeof(SumNode));
	*Ssize = 0;
    int left = 0, right = size-1;
    
    while(left < right)
    {
        if(*Ssize > 0 && set[left] == res[*Ssize-1].a2)
        {
            left++;
            continue;
        }
        if(*Ssize > 0 && set[right] == res[*Ssize-1].a3)
        {
            right--;
            continue;
        }

        if(set[left] + set[right] < sum)
        {
            left++;
        }
        else if(set[left] + set[right] > sum)
        {
            right--;
        }
        else
        {
        	
            res[*Ssize].a2 = set[left];
            res[*Ssize].a3 = set[right];
            
            left++;
            right--;
            (*Ssize)++;
        }
    }

    return res;
}

/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int** threeSum(int* nums, int numsSize, int* returnSize) 
{
    qsort2(nums, 0, numsSize-1);
    *returnSize = 0;
    int **resset = calloc(numsSize * numsSize, sizeof(int *));
    SumNode *sum2 = NULL;
    int sum2size = 0;
    
    int i = 0;
    int j;
    int lastnum = nums[0]-1;
    int a2, a3;
    for(i = 0; i < numsSize; i++)
    {
    	if(nums[i] > 0)	continue;
        if(nums[i] == lastnum)  continue;
        lastnum = nums[i];
        sum2 = findsum(nums+i+1, numsSize-i-1, -nums[i], &sum2size);
        j = 0; 
		while(j < sum2size)
        {
            int *res = calloc(3, sizeof(int));
            res[0] = nums[i];
            res[1] = sum2[j].a2;
            res[2] = sum2[j].a3;
            resset[*returnSize] = res;
            *returnSize += 1;
            j++;
        }
        free(sum2);
    }
    return resset;
}

int main()
{
	int set[] = {-1, 0, 1, 2, -1, -4};
	int reslen = 0;
	int **res = NULL;

	res = threeSum(set, 6, &reslen);

	int i, j;
	for(i = 0; i < reslen; i++)
	{
		for(j = 0; j < 3; j++)
		{
			printf("%d ", res[i][j]);
		}
		printf("\n");
	}
}

