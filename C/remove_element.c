/*****************************************************
Given an array and a value, remove all instances of that value in 
place and return the new length.

The order of elements can be changed. It doesn't matter what you 
leave beyond the new length.

*******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int removeElement(int* nums, int numsSize, int val) 
{
    int pos = 0;
    int i;
    for(i = 0; i < numsSize; i++)
    {
        if(nums[i] != val)
        {
            nums[pos++] = nums[i];
        }
    }
    return pos;
}



int main()
{
	int set[] = {1,1,2,2,2,3,4,5,5,5,6,6,6};

	int reslen = removeElement(set, sizeof(set)/sizeof(int), 3);

	int i;
	for(i = 0; i < reslen; i++)
	{
		printf("%d ", set[i]);
	}
	printf("\n");
}

