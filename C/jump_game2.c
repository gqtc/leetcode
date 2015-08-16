/*****************************************************
Given an array of non-negative integers, you are initially positioned 
at the first index of the array.

Each element in the array represents your maximum jump length 
at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. 
(Jump 1 step from index 0 to 1, then 3 steps to the last index.)

*******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max(x, y)  (((x)>(y))?(x):(y))

int jump(int* nums, int numsSize) 
{
	int i;
	int lastmaxnum;
	int curmaxnum = 0;
	int res = 0;
	
	lastmaxnum = 0 + nums[0];

	for(i = 1; i < numsSize; i++)
	{
		if(lastmaxnum >= numsSize-1) return res+1;
		if(i < lastmaxnum)
		{
			curmaxnum = max(curmaxnum, i+nums[i]);
		}
		else if(i == lastmaxnum)
		{
			curmaxnum = max(curmaxnum, i+nums[i]);
			res++;	
			lastmaxnum = curmaxnum;			
		}
	}
	return res;
}



int main()
{
	int set[] = {1,1,1,1,1};
	int res = jump(set, sizeof(set)/sizeof(int));
	printf("res is %d\n", res);
}
