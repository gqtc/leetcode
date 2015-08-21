/*****************************************************
Find the contiguous subarray within an array (containing at least one 
number) which has the largest sum.

For example, given the array [-2, 1, -3, 4, -1, 2, 1, -5, 4],
the contiguous subarray [4, -1, 2, 1] has the largest sum = 6.

click to show more practice.

More practice:
If you have figured out the O(n) solution, try coding another solution 
using the divide and conquer approach, which is more subtle.

*******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int maxSubArray(int* nums, int numsSize) 
{
    int sumn = nums[0];
    int res = nums[0];

    int i;
    for(i = 1; i < numsSize; i++)
    {
		if(sumn > 0)
		{
			sumn += nums[i];
		}
		else
		{
			sumn = nums[i];
		}

		if(res < sumn)
		{
			res = sumn;
		}
    }

    return res;
}

int main()
{
	int sets[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

	int res;
	res = maxSubArray(sets, sizeof(sets)/sizeof(int));

	printf("res is %d\n", res);
}
