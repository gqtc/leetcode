/*****************************************************
Given a sorted array and a target value, return the index if the target 
is found. If not, return the index where it would be if it were inserted 
in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 ¡ú 2
[1,3,5,6], 2 ¡ú 1
[1,3,5,6], 7 ¡ú 4
[1,3,5,6], 0 ¡ú 0

*******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int searchInsert(int* nums, int numsSize, int target) 
{
    int left, right, mid;
    int res;
    left = 0;
    right = numsSize-1;
    while(left <= right)
    {
        mid = left + (right-left)/2;
        if(nums[mid] == target) return mid;
        
        if(nums[mid] > target) right = mid - 1;
        else    left = mid+1;
    }
    return left;
}


int searchInsert2(int* nums, int numsSize, int target) 
{
    int left, right, mid;
    int res;
    left = 0;
    right = numsSize;
    while(left < right)
    {
        mid = left + (right-left)/2;
        if(nums[mid] == target) return mid;
        
        if(nums[mid] > target) right = mid;
        else    left = mid+1;
    }
    return left;
}

int main()
{
	int set[] = {1, 3, 5, 7, 9};
	int setsize = sizeof(set)/sizeof(int);
	int target;
	int res1 = -1;
	int res2 = -1;
	for(target = 0; target <= 10; target+=2)
	{
		res1 = searchInsert(set, setsize, target);
		res2 = searchInsert2(set, setsize, target);

		printf("for target %d\n", target);
		printf("res1 is %d\n", res1);
		printf("res2 is %d\n\n", res2);
	}
}
