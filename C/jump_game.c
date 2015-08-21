/*****************************************************
Given an array of non-negative integers, you are initially 
positioned at the first index of the array.

Each element in the array represents your maximum jump 
length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.

*******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int canJump(int* nums, int numsSize) 
{
	int i, j;
	if(numsSize == 1)	return 1;
	
	int maxnum = nums[0];
	int lastmaxnum = nums[0];
	
	if(lastmaxnum == 0) return 0;

	for(i = 1; i < numsSize; i++)
	{
	    if(lastmaxnum >= numsSize-1)    return 1;
		
		if(i < lastmaxnum)
		{
			if(nums[i]+i > maxnum)
			{
				maxnum = nums[i] + i;
			}
		}
		else
		{
			if(nums[i]+i > maxnum)
			{
				maxnum = nums[i] + i;
			}

			if(maxnum <= lastmaxnum)	return 0;

			lastmaxnum = maxnum;
		}
	}
}

int main()
{
	int set[] = {2,3,1,1,4};
	//int set[] = {3,2,1,0,4};
	int res = 0;
	res = canJump(set, sizeof(set)/sizeof(int));

	printf("can %s reach\n", res?"\b":"not");
}
