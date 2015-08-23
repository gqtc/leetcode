/*****************************************************
A robot is located at the top-left corner of a m x n grid 
(marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. 
The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

*******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridRowSize, int obstacleGridColSize) 
{

    int i, j;
    int res = 0;

    
    for(i = obstacleGridRowSize-1; i >= 0; i--)
    {
        for(j = obstacleGridColSize-1; j >= 0; j--)
        {
            if(obstacleGrid[i][j] == 1)
            {
                obstacleGrid[i][j] = 0;
                continue;
            }
            if(i == obstacleGridRowSize-1)
            {
                if(j == obstacleGridColSize-1)  obstacleGrid[i][j] = 1;
                else obstacleGrid[i][j] = obstacleGrid[i][j+1];
            }
            else if(j == obstacleGridColSize-1)
            {
                obstacleGrid[i][j] = obstacleGrid[i+1][j];
            }    
            else
            {
                obstacleGrid[i][j] = obstacleGrid[i+1][j] + obstacleGrid[i][j+1];
            }
        }
    }
    res = obstacleGrid[0][0];
    
    return res;
}

int main()
{
	int m = 3, n = 3;
	int line0[] = {0, 0, 0};
	int line1[] = {0, 1, 0};
	int line2[] = {0, 0, 0};

	int **board = calloc(m, sizeof(int *));
	board[0] = line0;
	board[1] = line1;
	board[2] = line2;

	int res = uniquePathsWithObstacles(board, 3, 3);
	printf("res is %d\n", res);
	
}
