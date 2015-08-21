/*****************************************************
The n-queens puzzle is the problem of placing n queens on an n*n 
chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' 
placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]

*******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct queennode
{ 
	char **board;
	struct queennode *next;
}QueenNode;


void printboard(char **board, int n)
{
	int i, j;

	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("-------------------\n");
}

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

QueenNode *copyboard(char **board, int n)
{
	int i;
	QueenNode *res = calloc(1, sizeof(QueenNode));
	res->board = calloc(n, sizeof(char *));

	for(i = 0; i < n; i++)
	{
		res->board[i] = calloc(n, sizeof(char));
		memcpy(res->board[i], board[i], n*sizeof(char));
	}
	return res;
}

void nqueencore(char **board, int line, int n, QueenNode **head, int *listlen)
{
	int i;
	QueenNode *res;
	for(i = 0; i < n; i++)
	{
		if(isvalidqueen(board, line, i, n))
		{
			board[line][i] = 'Q';
			if(line == n-1)
			{
				res = copyboard(board, n);
				res->next = *head;
				*head = res;
				*listlen += 1;
			}
			else
			{
				nqueencore(board, line+1, n, head, listlen);
			}	
			board[line][i] = '.';
		}
	}
}


char*** solveNQueens(int n, int* returnSize)
{
	char **board = calloc(n, sizeof(char *));
	int i, j;
	int reslen = 0;
	char ***res;
	for(i = 0; i < n; i++)
	{
		board[i] = calloc(n, sizeof(char));
		memset(board[i], '.', n);
	}

	QueenNode *head = NULL;
	QueenNode *p = NULL;
	QueenNode *q = NULL;

	nqueencore(board, 0, n, &head, &reslen);
	res = calloc(reslen, sizeof(char **));

	for(i = 0, p = head; i < reslen && p != NULL; i++)
	{
		res[i] = p->board;
		q = p;
		p = p->next;
		free(q);
	}
	*returnSize = reslen;

	return res;
}

int main(int argc, char **argv)
{
	int n = atoi(argv[1]);
	int reslen = 0;
	char ***res = NULL;
	res = solveNQueens(n, &reslen);
	int i, j;

	printf("reslen is %d\n", reslen);
	for(i = 0; i < reslen; i++)
	{
		printboard(res[i], n);
	}

	for(i = 0; i < reslen; i++)
	{
		for(j = 0; j < n; j++)
		{
			free(res[i][j]);
		}
		free(res[i]);
	}
	free(res);
}
