/*****************************************************
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?

*******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void rotate(int** matrix, int matrixRowSize, int matrixColSize) 
{
    int i, j, k;
    int loopnums = matrixRowSize/2;
    int starti, startj, tmpi;
    
    int lastnum = 0;
    int curnum = 0;
    
    for(k = 0; k < loopnums; k++)
    {
        for(i = k, j = k; j < matrixColSize-1-k; j++)
        {
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[matrixRowSize-1-j][i];
            matrix[matrixRowSize-1-j][i] = matrix[matrixRowSize-1-i][matrixRowSize-1-j];
            matrix[matrixRowSize-1-i][matrixRowSize-1-j] = matrix[j][matrixRowSize-1-i];
            matrix[j][matrixRowSize-1-i] = tmp;
        }
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
	int line2[] = {5,6,7,8};
	int line3[] = {9,10,11,12};
	int line4[] = {13,14,15,16};
	int *matrix[] = {line1, line2, line3, line4};

	printf("the matrix:\n");
	printmatrix(matrix, 4, 4);

	rotate(matrix, 4, 4);
	printf("\nafter rotate:\n");
	printmatrix(matrix, 4, 4);
}