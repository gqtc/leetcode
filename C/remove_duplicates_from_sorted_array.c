/*****************************************************
Given a sorted array, remove the duplicates in place such that each 
element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in 
place with constant memory.

For example,
Given input array nums = [1,1,2],

Your function should return length = 2, with the first two elements 
of nums being 1 and 2 respectively. 

It doesn't matter what you leave beyond the new length.

*******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int removeDuplicates(int* nums, int numsSize) 
{
	int pos = 0;
	int i;
	if(numsSize <= 1)	return numsSize;
	
	for(i = 1; i < numsSize; i++)
	{
		if(nums[i] != nums[pos])
		{
			nums[++pos] = nums[i];
		}
	}
	return pos+1;
}


int main()
{
	int set[] = {1,1,2,2,2,3,4,5,5,5,6,6,6};

	int reslen = removeDuplicates(set, sizeof(set)/sizeof(int));

	int i;
	for(i = 0; i < reslen; i++)
	{
		printf("%d ", set[i]);
	}
	printf("\n");
}
