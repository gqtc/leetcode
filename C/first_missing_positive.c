/*****************************************************
Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.

*******************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int firstMissingPositive(int* nums, int numsSize) 
{
    int i, tmp;
    for(i = 0; i < numsSize; i++)
    {
        tmp = nums[i];
        while(tmp != i+1)
        {
            if(tmp > numsSize || tmp < 1 || tmp == nums[tmp-1])
            {
                nums[i] = 0;
                break;
            }
            nums[i] = nums[tmp-1];
            nums[tmp-1] = tmp;
            tmp = nums[i];
        }
    }
    for(i = 0; i < numsSize; i++)
    {
        if(nums[i] == 0)    return i+1;
    }
    return numsSize+1;
}



int main()
{
	int set[] = {3, 4, -1, 1};


	printf("first missing positive is %d\n", 
		firstMissingPositive(set, sizeof(set)/sizeof(int)));
}
