/*****************************************************
Given a m x n matrix, if an element is 0, set its entire row and 
column to 0. Do it in place.

click to show follow up.

Follow up:
Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?

*******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void setZeroes(int** matrix, int matrixRowSize, int matrixColSize) 
{
	int bufrow = -1;
	int set0flag = 0;
	int i, j;

	for(i = 0; i < matrixRowSize; i++)
	{
		for(j = 0; j < matrixColSize; j++)
		{
			if(matrix[i][j] == 0)
			{
				if(bufrow == -1)
				{
					bufrow = i;
					break;
				}
				else
				{
					matrix[bufrow][j] = 0;
					set0flag = 1;
				}
			}
		}
		
		if(set0flag)
		{
			memset(matrix[i], 0, sizeof(int) * matrixColSize);
			set0flag = 0;
		}
	}


	if(bufrow != -1)
	{
		for(j = 0; j < matrixColSize; j++)
		{
			if(matrix[bufrow][j] == 0)
			{
				for(i = 0; i < matrixRowSize; i++)
				{
					matrix[i][j] = 0;
				}
			}
		}
		memset(matrix[bufrow], 0, sizeof(int) * matrixColSize);
	}	
}


void printmatrix(int** matrix, int matrixRowSize, int matrixColSize)
{
	int i, j;
	for(i = 0; i < matrixRowSize; i++)
	{
		for(j = 0; j < matrixColSize; j++)
		{
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
}	

int main()
{
	int line1[] = {1,2,3,4};
	int line2[] = {5,6,0,8};
	int line3[] = {9,0,11,12};
	int line4[] = {13,14,15,16};
	int *matrix[] = {line1, line2, line3, line4};

	printmatrix(matrix, 4, 4);
	setZeroes(matrix, 4, 4);
	printmatrix(matrix, 4, 4);
}	

