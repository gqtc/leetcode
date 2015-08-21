/*****************************************************
Given an integer n, generate a square matrix filled with elements
from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]

*******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int** generateMatrix(int n) 
{
	int i, j, k;
	int index;
	
	int **res = calloc(n, sizeof(int *));
	int reslen = n * n;
	
	for(i = 0; i < n; i++)
	{
		res[i] = calloc(n, sizeof(int));
	}

	index = 1;
	i = j = k = 0;
	while(index <= reslen)
	{
		res[i][j] = index++;
		if(index > reslen)	break;
		
		if(i == k)
		{
			j++;
			if(j < n-k)	continue;
			j--;
		}
		if(j == n-k-1)
		{
			i++;
			if(i < n-k)	continue;
			i--;
		}
		if(i == n-k-1)
		{
			j--;
			if(j >= k)	continue;
			j++;
		}
		if(j == k)
		{
			i--;
			if(i == k)
			{
				i = j = ++k;
			}
		}
	}

	return res;
}


int main(int argc, char **argv)
{
	int n = atoi(argv[1]);
	int i, j;
	int **res = generateMatrix(n);

	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			printf("%d ", res[i][j]);
		}
		printf("\n");
	}

	for(i = 0; i < n; i++)
	{
		free(res[i]);
	}
	free(res);
}
