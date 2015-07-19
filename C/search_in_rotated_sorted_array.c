/*****************************************************
Suppose a sorted array is rotated at some pivot unknown to you 
beforehand.
(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return 
its index, otherwise return -1.

You may assume no duplicate exists in the array.

*******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findrotate(int *sets, int nums)
{
	int left = 0, right = nums-1;
	int mid, lastmid = -1;

	while(left <= right)
	{
		mid = left + (right-left)/2;
		if(sets[left] <= sets[mid] && sets[mid] <= sets[right])	break;

		if(sets[mid] >= sets[left] && sets[mid] >= sets[right])
		{
			left = mid+1;
			lastmid = mid;
		}
		else
		{
			right = mid-1;
			lastmid = mid;
		}
	}

	if(mid < lastmid)	return lastmid;
	else 		return lastmid+1;
}

int search(int* nums, int numsSize, int target) 
{
	int left[2], right[2];
	int start, end, mid;
	left[1] = findrotate(nums, numsSize);
	left[0] = 0;
	right[0] = left[1]-1;
	right[1] = numsSize-1;

	int i = 0;
	for(i = 0; i < 2; i++)
	{
		start = left[i];
		end = right[i];
	
		while(start <= end)
		{
			mid = start + (end-start)/2;
			if(nums[mid] == target)	return mid;
			if(nums[mid] < target)
			{
				start = mid+1;
			}
			else
			{
				end = mid-1;
			}
		}
	}
	return -1;
}


int gcd(int m, int n)
{
	if(n == 0)	return m;
	return gcd(n, m%n);
}


void rotatesets(int *sets, int nums, int rk)
{
	int listnums = gcd(nums, rk);
	int i, j;
	int lastindex;
	int key;
	for(i = 0; i < listnums; i++)
	{	
		lastindex = i;
		key = sets[i];
		for(j = (i + rk) % nums; j != i; j = (j+rk)%nums)
		{
			sets[lastindex] = sets[j];
			lastindex = j;
		}
		sets[lastindex] = key;
	}
}

void printsets(int *sets, int nums)
{
	int i;
	for(i = 0; i < nums; i++)
	{
		printf("%d ", sets[i]);
	}
	printf("\n");
}

int main()
{
	int sets[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int dsets[10]; 
	int i;
	int index = -1;
	for(i = 0; i < 10; i++)
	{
		memcpy(dsets, sets, sizeof(int)*10);
		rotatesets(dsets, 10, i);
		printsets(dsets, 10);
		index = findrotate(dsets, 10);
		printf("rotate is %d\n", dsets[index]);

		printf("the index of 5 is %d\n", search(dsets, 10, 5));
		printf("the index of 100 is %d\n\n", search(dsets, 10, 100));
	}
}

