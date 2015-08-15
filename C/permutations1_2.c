/*****************************************************
Given a collection of numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].

*******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int *a, int *b)
{
    int tmp;
    tmp = *b;
    *b = *a;
    *a = tmp;
}

void reverse(int *nums, int left, int right)
{
    int tmp;
    while(left < right)
    {
        swap(nums+left, nums+right);
        left++;
        right--;
    }
}

int nextPermutation(int* nums, int numsSize) 
{
    if(numsSize <= 1)   return -1;
    
    int i = numsSize-2;
    while(i >= 0 && nums[i] >= nums[i+1])i--;

    if(i < 0)
    {
        return -1;
    }
    else
    {
        int j = numsSize-1;
        while(j > i && nums[j] <= nums[i])j--;

        swap(nums+i, nums+j);
        reverse(nums, i+1, numsSize-1);
        return 0;
    }
}


int compar(const void *a, const void *b)
{
	return  *((int *)a) - *((int *)b);
}

int** permute(int* nums, int numsSize, int* returnSize) 
{
	int i, j;   
	int ressize = 1;
	for(i = numsSize; i >= 1; i--)
	{
		ressize *= i;
	}
	*returnSize = ressize;

	int **res = calloc(ressize, sizeof(int *));
	int k = 0;
	int *set;

	for(k = 0; k < ressize; k++)
	{
		res[k] = calloc(numsSize, sizeof(int));
	}
	qsort(nums, numsSize, sizeof(int), compar);
	memcpy(res[0], nums, sizeof(int)*numsSize);

	k = 1;
	while(nextPermutation(nums, numsSize) != -1)
	{
		memcpy(res[k++], nums, sizeof(int)*numsSize);
	}
	return res;
}

int main()
{
	int set[] = {4,1,2,3};
	int reslen = 0;
	int i, j;
	int setlen = sizeof(set)/sizeof(int);
	int **res = permute(set, setlen, &reslen);

	for(i = 0; i < reslen; i++)
	{
		for(j = 0; j < setlen; j++)
		{
			printf("%d ", res[i][j]);
		}
		printf("\n");
		free(res[i]);
	}
	free(res);
}
