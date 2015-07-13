/*****************************************************
Given an array of integers, find two numbers such that they 
add up to a specific target number.

The function twoSum should return indices of the two numbers
such that they add up to the target, where index1 must be less 
than index2. Please note that your returned answers (both 
index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
*******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*quick sort*/
void swap(int *a, int *b)
{
	int tmp;
	tmp = *b;
	*b = *a;
	*a = tmp;
}
int partition(int *sets, int left, int right)
{
    int i, j;
    int key;
    int index = rand()%(right-left+1) + left;
    swap(&sets[index], &sets[right]);
    key = sets[right];
    i = left - 1;
    for(j = left; j < right; j++)
    {
        if(sets[j] < key)
        {
            i += 1;
            swap(&sets[i], &sets[j]);
        }
    }
    swap(&sets[i+1], &sets[right]);
    return i+1;
}
void quicksort(int *sets, int left, int right)
{
    int q = -1;
    if(left < right)
    {
        q = partition(sets, left, right);
        quicksort(sets, left, q-1);
        quicksort(sets, q+1, right);
    }
}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) 
{
    int index1, index2;
    int i = 0;
    int tmpres;
    int *res = calloc(2, sizeof(int));
    int *tmpnums = calloc(numsSize, sizeof(int));
    memcpy(tmpnums, nums, sizeof(int) * numsSize);
    
    quicksort(tmpnums, 0, numsSize - 1);

    for(index1 = 0, index2 = numsSize-1; index1 < index2;)
    {
        tmpres = tmpnums[index1] + tmpnums[index2];
        if(tmpres > target)
            index2--;
        else if(tmpres < target)
            index1++;
        else
        {
            break;
        }
    }
    
    for(i = 0; i < numsSize; i++)
    {
        if(!res[0] && nums[i] == tmpnums[index1])
            res[0] = i+1;
        else if(!res[1] && nums[i] == tmpnums[index2])
            res[1] = i+1;
            
        if(res[0] && res[1])
        {
            if(res[0] > res[1])
                swap(res, res+1);
                return res;

        }
    }
}

int main()
{
	int sets[] = {2, 7, 11, 15};
	int target = 9;
	int *res = twoSum(sets, sizeof(sets)/sizeof(int), target);

	printf("res[0] is %d\n", res[0]);
	printf("res[1] is %d\n", res[1]);
}
