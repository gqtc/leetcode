/*****************************************************
Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution.

*******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	int i, j;
	int value;
}node;

typedef struct
{
	node **sets;
	int len;
	int top;
}Stack;

int push(Stack *s, node *key)
{
	if(s->top >= s->len)  return -1;

	s->sets[s->top ++] = key;

	return 0;
}

node *pop(Stack *s)
{
	if(s->top == 0)   return NULL;
	return s->sets[-- s->top];
}

Stack *initstack(int stlen)
{
	Stack *st = calloc(1, sizeof(Stack));
	st->sets = calloc(stlen, sizeof(node *));
	st->len = stlen;
	st->top = 0;

	return st;
}

void freestack(Stack *s)
{
	node *top = NULL;
	while((top = pop(s)) != NULL)
	{
		free(top);
	}
	free(s);
}

int isSafe(char** board, int boardRowSize, int boardColSize, node *top) 
{
	int i, j, value;
	int tmp = -1;
	i = top->i;
	j = top->j;
	value = top->value;

	int m, n;
	for(m = 0; m < boardColSize; m++)
	{
		if(m == j)	continue;
		tmp = board[i][m] - '0';
		if(tmp == value)	return 0;
	}

	for(m = 0; m < boardRowSize; m++)
	{
		if(m == i)	continue;
		tmp = board[m][j] - '0';
		if(tmp == value)	return 0;
	}

	int lineend = i/3 * 3 + 3;
	int colend = j/3 * 3 + 3;
	for(m = i/3 * 3; m < lineend; m++)
	{
		for(n = j/3 * 3; n < colend; n++)
		{
			if(m == i && n == j)	continue;
			tmp = board[m][n] - '0';
			if(tmp == value)	return 0;
		}
	}

	return 1;
}

void solveSudoku_loop(char **board, int boardRowSize, int boardColSize)
{
	int i, j, tmp;
	Stack *s = initstack(81);
	node *top = NULL;

	for(i = 0; i < boardRowSize; i++)
	{
		for(j = 0; j < boardColSize; j++)
		{
			if(board[i][j] == '.')
			{
				node *newnode = calloc(1, sizeof(node));
				newnode->i = i;
				newnode->j = j;
				newnode->value = 1;
				board[i][j] = newnode->value + '0';
				push(s, newnode);
				top = newnode;
				while(isSafe(board, boardRowSize, boardColSize, top) == 0)
				{
					top = pop(s);
					while(top != NULL && top->value == 9)	
					{
						board[top->i][top->j] = '.';
						top = pop(s);
					}
					if(top == NULL)	
					{
						printf("no solution\n");
						freestack(s);
						return;
					}

					top->value += 1;
					board[top->i][top->j] = top->value + '0';
					push(s, top);
				}
				i = top->i;
				j = top->j;
			}
		}
	}
	freestack(s);
}


int findemptyblank(char **board, int boardRowSize, int boardColSize, int *i, int *j)
{
	int m, n;
	for(m = 0; m < boardRowSize; m++)
	{
		for(n = 0; n < boardColSize; n++)
		{
			if(board[m][n] == '.')
			{
				*i = m;
				*j = n;
				return 1;
			}
		}
	}
	return 0;
}

int solveSudoku_recurse(char **board, int boardRowSize, int boardColSize)
{
	int i, j, k;

	if(findemptyblank(board, boardRowSize, boardColSize, &i, &j) == 0)
	{
		return 1;
	}

	node newnode;
	newnode.i = i;
	newnode.j = j;
	
	for(k = 1; k <= 9; k++)
	{
		newnode.value = k;
		if(isSafe(board, boardRowSize, boardColSize, &newnode))
		{
			board[i][j] = k + '0';
			if(solveSudoku_recurse(board, boardRowSize, boardColSize))
			{
				return 1;
			}
		}
	}
	board[i][j] = '.';
	return 0;
}


int isValidSudoku(char** board, int boardRowSize, int boardColSize) 
{
	int hashline[10][10];
	int hashcol[10][10];
	int hashzone[10][10];
	int i, j;
	int tmp = -1;
	int zone = -1;
	for(i = 0; i < 10; i++)
	{
		for(j = 0; j < 10; j++)
		{
			hashline[i][j] = hashcol[i][j] = hashzone[i][j] = 0;
		}
	}
    
	for(i = 0; i < boardRowSize; i++)
	{
		for(j = 0; j < boardColSize; j++)
		{
			tmp = board[i][j];
			if(tmp == '.')  continue;
			else    tmp = tmp - '0';

			zone = (i / 3) * 3 + j / 3;
			if(hashline[tmp][i]) return 0;
			if(hashcol[tmp][j]) return 0;
			if(hashzone[tmp][zone]) return 0;

			hashline[tmp][i] = hashcol[tmp][j] = hashzone[tmp][zone] = 1;
		}
	}
	return 1;
}

void printsudoku(char** board, int boardRowSize, int boardColSize)
{
	int i, j;
	printf("\n");
	for(i = 0; i < boardRowSize; i++)
	{
		if(i % 3 == 0)
		{
			printf("--------------------\n");
		}
		for(j = 0; j < boardColSize; j++)
		{
			if(j % 3 == 0)
			{
				printf("|");
			}
			printf("%c ", board[i][j]);
		}
		
		printf("\n");
	}
}

void solveSudoku(char **board, int boardRowSize, int boardColSize)
{
	solveSudoku_loop(board, boardRowSize, boardColSize);	
	//solveSudoku_recurse(board, boardRowSize, boardColSize);
}

int main()
{
	char l1[] = "53..7....";
	char l2[] = "6..195...";
	char l3[] = ".98....6.";
	char l4[] = "8...6...3";
	char l5[] = "4..8.3..1";
	char l6[] = "7...2...6";
	char l7[] = ".6....28.";
	char l8[] = "...419..5";
	char l9[] = "....8..79";

	char *sudoku[] = {l1, l2, l3, l4, l5, l6, l7, l8, l9};

	printsudoku(sudoku, 9, 9);
	solveSudoku(sudoku, 9, 9);
	printsudoku(sudoku, 9, 9);

	printf("\nis %s Sudoku\n", (isValidSudoku(sudoku, 9, 9))?"Valid":"not Valid");
}

