/*****************************************************
Implement next permutation, which rearranges numbers into the 
lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest 
possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and 
its corresponding outputs are in the right-hand column.
1,2,3 ¡ú 1,3,2
3,2,1 ¡ú 1,2,3
1,1,5 ¡ú 1,5,1

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

void reverse(int *nums, int left, int right)
{
    int tmp;
    while(left < right)
    {
        swap(nums+left, nums+right);
        left++;
        right--;
    }
}

void nextPermutation(int* nums, int numsSize) 
{
    if(numsSize <= 1)   return;
    
    int i = numsSize-2;
    while(i >= 0 && nums[i] >= nums[i+1])i--;

    if(i < 0)
    {
        reverse(nums, 0, numsSize - 1);
    }
    else
    {
        int j = numsSize-1;
        while(j > i && nums[j] <= nums[i])j--;

        swap(nums+i, nums+j);
        reverse(nums, i+1, numsSize-1);
    }
}

int main()
{
	int set[] = {1, 2, 4, 6, 5, 3};
	int i;
	int size = sizeof(set)/sizeof(int);
	nextPermutation(set, size);

	for(i = 0; i < size; i++)
	{
		printf("%d ", set[i]);
	}
	printf("\n");
}

