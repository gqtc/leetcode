/*****************************************************
Follow up for N-Queens problem.

Now, instead outputting board configurations, return the total 
number of distinct solutions.

*******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isvalidqueen(char **board, int line, int col, int n)
{
	int i, j;

	for(i = 0; i < line; i++)
	{
		if(board[i][col] == 'Q')	return 0;
	}

	for(i = line-1, j = col-1; i>=0 && j>=0; i--,j--)
	{
		if(board[i][j] == 'Q')	return 0;
	}

	for(i = line-1, j = col+1; i>=0 && j<n; i--,j++)
	{
		if(board[i][j] == 'Q')	return 0;
	}

	return 1;
}


void nqueencore(char **board, int line, int n, int *reslen)
{
	int i;

	for(i = 0; i < n; i++)
	{
		if(isvalidqueen(board, line, i, n))
		{
			board[line][i] = 'Q';
			if(line == n-1)
			{
				*reslen += 1;
			}
			else
			{
				nqueencore(board, line+1, n, reslen);
			}	
			board[line][i] = '.';
		}
	}
}

int totalNQueens(int n)
{
	char **board = calloc(n, sizeof(char *));
	int i;
	int reslen = 0;

	for(i = 0; i < n; i++)
	{
		board[i] = calloc(n, sizeof(char));
		memset(board[i], '.', n);
	}

	nqueencore(board, 0, n, &reslen);
	
	for(i = 0; i < n; i++)
	{
		free(board[i]);
	}
	free(board);

	return reslen;
}

int main(int argc, char **argv)
{
	int n = atoi(argv[1]);
	int reslen = 0;

	reslen = totalNQueens(n);
	printf("reslen is %d\n", reslen);
}
