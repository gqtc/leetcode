/*****************************************************
There are two sorted arrays nums1 and nums2 of size m and n 
respectively. Find the median of the two sorted arrays. 
The overall run time complexity should be O(log (m+n)).
*******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int findkth(int *set1, int len1, int *set2, int len2, int k)
{
	int n1, n2;

	if(len1>len2)
	{
		return findkth(set2, len2, set1, len1, k); 
	}

	if(len1 == 0)	return set2[k-1];
	
	if(k == 1)	return (set1[0]<set2[0])?set1[0]:set2[0];

	n1 = (k/2<len1)?k/2:len1;
	n2 = k-n1;

	if(set1[n1-1] < set2[n2-1])
	{
		return findkth(set1+n1, len1-n1, set2, len2, k-n1);
	}
	else if(set1[n1-1] > set2[n2-1])
	{
		return findkth(set1, len1, set2+n2, len2-n2, k-n2);
	}
	else
	{
		return set1[n1-1];
	}
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) 
{
	if((nums1Size+nums2Size)%2)
		return findkth(nums1, nums1Size, nums2, nums2Size, (nums1Size+nums2Size+1)/2);
	else
		return (findkth(nums1, nums1Size, nums2, nums2Size, (nums1Size+nums2Size)/2) +
			findkth(nums1, nums1Size, nums2, nums2Size, (nums1Size+nums2Size)/2+1))/2.0;
}


int main()
{
	int set1[] = {1, 3, 7, 10, 100, 234, 289, 340};
	int set2[] = {1, 5, 8, 105, 203, 211, 300, 500};

	int len1 = sizeof(set1)/sizeof(int);
	int len2 = sizeof(set2)/sizeof(int);

	int k = 1;
	int res = -1;
	
	for(k = 1; k <= len1+len2; k++)
	{
		res = findkth(set1, len1, set2, len2, k);
		printf("[%d] is %d\n", k, res);
	}

	printf("res is %f\n", findMedianSortedArrays(set1, len1, set2, len2));
}
