/*****************************************************
Given an array of n integers where n > 1, nums, return an array 
output such that output[i] is equal to the product of all the elements 
of nums except nums[i].

Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6].

Follow up:
Could you solve it with constant space complexity? (Note: The output 
array does not count as extra space for the purpose of space complexity 
analysis.)

*******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) 
{
	*returnSize = numsSize;
    int *res = calloc(numsSize, sizeof(int));
    int i;

	int tmp;
	res[0] = 1;
    for(i = 1; i < numsSize; i++)
    {
		res[i] = res[i-1] * nums[i-1];
    }

    tmp = 1;
    for(i = numsSize-1; i >= 0; i--)
    {
		res[i] = res[i] * tmp;
		tmp = tmp * nums[i];
    }
    return res;
}

int main()
{
	int set[] = {1,2,3,4};
	int *res;
	int reslen;
	
	res = productExceptSelf(set, sizeof(set)/sizeof(int), &reslen);
	int i;
	for(i = 0; i < reslen; i++)
	{
		printf("%d ", res[i]);
	}
	printf("\n");
}
