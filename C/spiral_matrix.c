/*****************************************************
Given a matrix of m x n elements (m rows, n columns), return all 
elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].

*******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define min(x, y)  (((x)<(y))?(x):(y))


int* spiralOrder(int** matrix, int matrixRowSize, int matrixColSize) 
{
    int i, j, k;

	if(matrixRowSize == 0 || matrixColSize == 0)	return NULL;

    int *res = calloc(matrixRowSize * matrixColSize, sizeof(int));
    int index = 0;
    int reslen = matrixRowSize * matrixColSize;

    k = 0;
    i = j = k;
    while(index < reslen)
    {
	    res[index++] = matrix[i][j];
	    
		if(index == reslen) break;
		
		if(i == k)
		{
			j++;
			if(j < matrixColSize-k)	continue;
			j--;		
		}
		if(j == matrixColSize-1-k)
		{
			i++;
			if(i < matrixRowSize-k)	continue;
			i--;	
		}
					
		if(i == matrixRowSize-1-k)
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

int main()
{
	int line1[] = {1,2,3,4};
	int line2[] = {5,6,7,8};
	int line3[] = {9,10,11,12};
	int line4[] = {13,14,15,16};
	int *matrix[] = {line1, line2, line3, line4};

	int *res = NULL;

	int rows = 4;
	int cols = 4;
	res = spiralOrder(matrix, rows, cols);

	int i;
	for(i = 0; i < rows*cols; i++)
	{
		printf("%d ", res[i]);
	}
	printf("\n");

	free(res);
}
