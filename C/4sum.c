/*****************************************************
Given an array S of n integers, are there elements a, b, c, and d in S 
such that a + b + c + d = target? Find all unique quadruplets in the 
array which gives the sum of target.

Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. 
(ie, a<=b<=c<=d)

The solution set must not contain duplicate quadruplets.
For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

A solution set is:
    (-1,  0, 0, 1)
    (-2, -1, 1, 2)
    (-2,  0, 0, 2)

*******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
    int a1;
    int a2;
    int a3;
    char isvalid;
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
            res[*Ssize].isvalid = 1;
            

            left++;
            right--;
            (*Ssize)++;
        }
    }

    return res;
} 
 
SumNode **threeSum(int* nums, int numsSize, int target, int* returnSize) 
{
    *returnSize = 0;
    SumNode *sum2 = NULL;
    int sum2size = 0;

    SumNode **res = NULL;
    
    res = calloc(numsSize, sizeof(SumNode *));
    int resindex = 0;
    
    int i = 0;
    int j;
    int lastnum = nums[0]-1;
    int a2, a3;
    for(i = 0; i < numsSize-2; i++)
    {
        if(nums[i] == lastnum)  continue;
        lastnum = nums[i];
        sum2 = findsum(nums+i+1, numsSize-i-1, target-nums[i], &sum2size);
        j = 0; 
		while(j < sum2size)
        {
            sum2[j].a1 = nums[i];
            j++;
        }
        if(sum2size != 0)
        {
            res[resindex++] = sum2;
        }
        else
        {
            free(sum2);
        }
    }
    *returnSize = resindex;
    return res;
}

/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int** fourSum(int* nums, int numsSize, int target, int* returnSize) 
{
    qsort2(nums, 0, numsSize-1);
    *returnSize = 0;
    int **resset = calloc(numsSize * numsSize * numsSize, sizeof(int *));
    SumNode **sum3 = NULL;
    SumNode *tmp = NULL;
    int sum3size = 0;
    
    int i = 0;
    int j, k;
    int lastnum = nums[0]-1;
    int a2, a3;
    for(i = 0; i < numsSize-3; i++)
    {
        if(nums[i] == lastnum)  continue;
        lastnum = nums[i];
        sum3 = threeSum(nums+i+1, numsSize-i-1, target-nums[i], &sum3size);
        j = 0; 
		while(j < sum3size)
        {
            tmp = sum3[j];
            for(k = 0; tmp[k].isvalid == 1; k++)
            {
                int *res = calloc(4, sizeof(int));
                res[0] = nums[i];
                res[1] = tmp[k].a1;
                res[2] = tmp[k].a2;
                res[3] = tmp[k].a3;
                resset[*returnSize] = res;
                *returnSize += 1;
            }
            free(tmp);
            j++;
        }
        free(sum3);
    }
    return resset;
}

int main()
{
	int sets[] = {1, 0, -1, 0, -2, 2};

	int **res;
	int reslen;

	res = fourSum(sets, sizeof(sets)/sizeof(int), 0, &reslen);
	int i = 0;

	for(i = 0; i < reslen; i++)
	{
		printf("%d %d %d %d\n", res[i][0], res[i][1], res[i][2], res[i][3]);
		free(res[i]);
	}

	free(res);
}
