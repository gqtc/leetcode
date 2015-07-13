/*****************************************************
Given an array S of n integers, find three integers in S such that 
the sum is closest to a given number, target. Return the sum of the 
three integers. You may assume that each input would have exactly 
one solution.

For example, given array S = {-1 2 1 -4}, and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

*******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ABS(x) (((x)<0)?(-(x)):(x))

int findclosesum(int *set, int size, int sum)
{
    int left = 0, right = size-1;
	int res = 0x7fffffff;
	int tmp;
	int beginflag = 1;
	
    
    while(left < right)
    {
    	tmp = set[left] + set[right];
    	if(tmp == sum)	return tmp;

		if(beginflag)
		{
			beginflag = 0;
			res = tmp;
		}
		else if(ABS(res-sum) > ABS(tmp-sum))	
		{
			res = tmp;
		}

    	
        if(tmp < sum)
        {
            left++;
        }
        else
        {
            right--;
        }
    }

    return res;
}
void swap(int *a, int *b)
{
    int tmp;
    tmp = *b;
    *b = *a;
    *a = tmp;
}

int partition(int *set, int left, int right)
{
    int randint = rand()%(right-left+1) + left;
    swap(set+randint, set+right);
    int key = set[right];
    int i, j;
    i = left-1;
    for(j = left; j < right; j++)
    {
        if(set[j] < key)
        {
            i += 1;
            swap(set+i, set+j);
        }
    }
    swap(set+i+1, set+right);
    return i+1;
}

void qsort2(int *set, int left, int right)
{
    int q;
    if(left < right)
    {
        q = partition(set, left, right);
        qsort2(set, left, q-1);
        qsort2(set, q+1, right);
    }
    
}
/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int threeSumClosest(int* nums, int numsSize, int target) 
{
    qsort2(nums, 0, numsSize-1);

	int sum2;
    
    int i = 0;

	int res = 0x7fffffff;
	int beginflag = 1;
    for(i = 0; i < numsSize-2; i++)
    {
        sum2 = findclosesum(nums+i+1, numsSize-i-1, target-nums[i]);
    	if(sum2 == target-nums[i])	return target;

    	if(beginflag)
		{
			beginflag = 0;
			res = sum2+nums[i];
		}
		else if(ABS(target-res) > ABS(target-sum2-nums[i]))	
		{
			res = sum2+nums[i];
		}
    }
    return res;
}

int main()
{
	int set[] = {-1, 2, 1, -4};
	int reslen = 0;
	int res;

	res = threeSumClosest(set, 4, 1);

	printf("res is %d\n", res);
}

