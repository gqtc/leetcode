/*****************************************************
Given a sorted array of integers, find the starting and ending position 
of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].

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

