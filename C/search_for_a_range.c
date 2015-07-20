/*****************************************************
Implement next permutation, which rearranges numbers into the 
lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest 
possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and 
its corresponding outputs are in the right-hand column.
1,2,3 ¡ú 1,3,2
3,2,1 ¡ú 1,2,3
1,1,5 ¡ú 1,5,1

*******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize) 
{
    int resleft, resright;
    int left, right;
	int mid = -1;
	int resmid;

    left = 0; right = numsSize - 1;
    while(left <= right)
    {
		mid = left + (right-left)/2;
		if(nums[mid] == target)
		{
			break;
		}
		if(nums[mid] > target)
		{
			right -= 1;
		}
		else
		{
			left += 1;
		}
    }

    if(left > right)
    {
		int *res = calloc(2, sizeof(int));
		res[0] = -1;
		res[1] = -1;
		*returnSize = 2;
		return res;
    }

    left = 0;
    right = mid;
    while(left < right)
    {
		resmid = left + (right-left)/2;
		if(nums[resmid] < target)
		{
			left = resmid+1;
		}
		else
		{
			right = resmid;
		}
    }
    resleft = left;

    left = mid;
    right = numsSize - 1;
    while(left <= right)
    {
		resmid = left + (right-left)/2;
		if(nums[resmid] == target)
		{
			left = resmid+1;
		}
		else
		{
			right = resmid-1;
		}
    }
    resright = right;

	int *res = calloc(2, sizeof(int));
	res[0] = resleft;
	res[1] = resright;
	*returnSize = 2;
	return res;
}

int main()
{
	int nums[] = {5, 7, 7, 8, 8, 8, 10};
	int *res = NULL;
	int reslen;

	res = searchRange(nums, sizeof(nums)/sizeof(int), 8, &reslen);

	printf("%d-->%d\n", res[0], res[reslen-1]);
}

