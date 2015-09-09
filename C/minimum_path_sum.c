/*****************************************************
Given a m x n grid filled with non-negative numbers, find a path 
from top left to bottom right which minimizes the sum of all numbers 
along its path.

Note: You can only move either down or right at any point in time.

*******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define min(x, y)  (((x)>(y))?(y):(x))

int minPathSum(int** grid, int gridRowSize, int gridColSize) 
{
    int i, j;
    for(i = gridRowSize-1; i >= 0; i--)
    {
		for(j = gridColSize-1; j >= 0; j--)
		{
			if(i == gridRowSize-1 && j == gridColSize-1)	continue;
		
			if(i == gridRowSize-1)
			{
				grid[i][j] += grid[i][j+1];
				continue;
			}

			if(j == gridColSize-1)
			{
				grid[i][j] += grid[i+1][j];
				continue;
			}

			grid[i][j] += min(grid[i+1][j], grid[i][j+1]);
		}
    }

    return grid[0][0];
}

int main()
{
	int m = 4, n = 3;
	int line0[] = {1,		0,		2};
	int line1[] = {100,		10,		3};
	int line2[] = {1,		3,		6};
	int line3[] = {1,		13,		16};

	int **board = calloc(m, sizeof(int *));
	board[0] = line0;
	board[1] = line1;
	board[2] = line2;
	board[3] = line3;

	int res = minPathSum(board, 4, 3);
	printf("res is %d\n", res);
	
}

