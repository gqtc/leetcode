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

int uniquePaths(int m, int n) 
{
    int **board = calloc(m, sizeof(int *));
    int i, j;
    int res = 0;
    for(i = 0; i < m; i++)
    {
        board[i] = calloc(n, sizeof(int));
    }
    
    for(i = m-1; i >= 0; i--)
    {
        for(j = n-1; j >= 0; j--)
        {
            if(i == m-1 || j == n-1)    board[i][j] = 1;
            else
            {
                board[i][j] = board[i+1][j] + board[i][j+1];
            }
        }
    }
    res = board[0][0];
    
    for(i = 0; i < m; i++)
    {
        free(board[i]);
    }
    free(board);
    
    return res;
}

int main()
{
	int m = 2;
	int n = 2;

	int res = uniquePaths(m,n);
	printf("res is %d\n", res);
}
