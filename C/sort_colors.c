/*****************************************************
Given an array with n objects colored red, white or blue, sort them 
so that objects of the same color are adjacent, with the colors in the 
order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, 
white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.

Follow up:
A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite 
array with total number of 0's, then 1's and followed by 2's.

Could you come up with an one-pass algorithm using only constant space?

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


void sortColors(int* nums, int numsSize) 
{
    int start1 = 0, end1 = numsSize-1;
    int i;

	while(start1 <= end1 && nums[start1] == 0)start1++;
	while(end1 >= start1 && nums[end1] == 2)end1 --;

    for(i = start1; i <= end1; )
    {
		if(nums[i] == 0)
		{
			swap(nums+i, nums+start1);
			while(start1 <= end1 && nums[start1] == 0)start1++;
			i = start1;
		}
		else if(nums[i] == 2)
		{
			swap(nums+i, nums+end1);
			while(end1 >= start1 && nums[end1] == 2)end1 --;
		}
		else
		{
			i++;
		}
    }
}

void sortColors2(int* nums, int numsSize) 
{
    int start1 = 0, end1 = numsSize-1;
    int i;


    for(i = start1; i <= end1; i++)
    {
		if(nums[i] == 0)
		{
			swap(nums+i, nums+start1);
			start1++;
		}
		if(nums[i] == 2)
		{
			swap(nums+i, nums+end1);
			end1--;
			i--;
		}
    }
}



int main()
{
	int nums[] = {1, 1, 1, 0, 2};
	int size = sizeof(nums)/sizeof(int);

	int i;
	sortColors2(nums, size);
	for(i = 0; i < size; i++)
	{
		printf("%d ", nums[i]);
	}
	printf("\n");
}
