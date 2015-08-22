/*****************************************************
The set [1,2,3,бн,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.

This is because the new interval [4,9] overlaps 
with [3,5],[6,7],[8,10].

*******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char *a, char *b)
{
    char tmp;
    tmp = *b;
    *b = *a;
    *a = tmp;
}

void reverse(char *nums, int left, int right)
{
    while(left < right)
    {
        swap(nums+left, nums+right);
        left++;
        right--;
    }
}


char* getPermutation(int n, int k) 
{
	int i, j, m;
	int num = 0;
	
	char *res = calloc(n+1, sizeof(char));
	
	for(i = 1; i <= n; i++)
	{
		res[i-1] = i+'0';
	}


	for(i = 1; i < k; i++)
	{	
		j = n-2;
		while(j >= 0 && res[j]>res[j+1])j--;
		m = n-1;
		while(res[m]<res[j])m--;
		swap(res+j, res+m);
		reverse(res, j+1, n-1);
	}

	return res;
}

char* getPermutation_nb(int n, int k) 
{
	int i;
	int total = 1;
	
	int grouplen = 0;
	int groupth = 0;
	
	char *num = calloc(n+1, sizeof(char));
	
	for(i = 1; i <= n; i++)
	{
		num[i-1] = i+'0';
		total *= i;
	}

	if(k > total)
	{
		free(num);
		return NULL;
	}	
	
	char *res = calloc(n+1, sizeof(char));
	int index = 0;

	grouplen = total;
	while(n > 0)
	{
		grouplen = grouplen / n;
		groupth = (k-1)/grouplen;
		res[index++] = num[groupth];
		i = groupth;
		while(i < n-1)
		{
			num[i] = num[i+1];
			i++;
		}
		k -= groupth * grouplen;
		n -= 1;
	}
	
	free(num);
	return res;
}


int main(int argc, char **argv)
{
	int n = atoi(argv[1]);
	int kmax = 1;
	char *res = NULL;

	int i = 1;
	for(i = 1; i <= n; i++)
	{
		kmax *= i;
	}

	for(i = 1; i <= kmax; i++)
	{
		res = getPermutation_nb(n, i);
		printf("%d-->%s\n", i, res);
		free(res);
	}
}
