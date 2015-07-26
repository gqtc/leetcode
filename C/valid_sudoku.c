/*****************************************************
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The 
Rules.

The Sudoku board could be partially filled, where empty cells are 
filled with the character '.'.


A partially filled sudoku which is valid.

Note:
A valid Sudoku board (partially filled) is not necessarily solvable. 
Only the filled cells need to be validated.

*******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isValidSudoku(char** board, int boardRowSize, int boardColSize) 
{
    int hash[10] = {};
    int i, j;
    int tmp = -1;
    for(i = 0; i < boardRowSize; i++)
    {
        memset(hash, 0, sizeof(int)*10);
        for(j = 0; j < boardColSize; j++)
        {
            tmp = board[i][j];
            if(tmp != '.')
            {
                if(hash[tmp-'0'])   return 0;
                hash[tmp-'0'] = 1;
            }
        }
    }
    
    for(j = 0; j < boardColSize; j++)
    {
        memset(hash, 0, sizeof(int)*10);
        for(i = 0; i < boardRowSize; i++)
        {
            tmp = board[i][j];
            if(tmp != '.')
            {
                if(hash[tmp-'0'])   return 0;
                hash[tmp-'0'] = 1;
            }
        }
    }
    

    int m = 0, n = 0;
    while(1)
    {
        memset(hash, 0, sizeof(int)*10);
        for(i = 3*m; i < 3*m + 3; i++)
        {
        
            for(j = 3*n; j < 3*n + 3; j++)
            {
                tmp = board[i][j];
                
                if(tmp != '.')
                {
                    if(hash[tmp-'0'])   return 0;
                    hash[tmp-'0'] = 1;
                }
            }

        }
        n++;
        if(3*n == boardColSize) {m++; n = 0;}
        if(3*m == boardRowSize) break;
    }
    return 1;
}

int isValidSudoku2(char** board, int boardRowSize, int boardColSize) 
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

int main()
{
	char *sudoku[] = {
		"53..7....",
		"6..195...",
		".98....6.",
		"8...6...3",
		"4..8.3..1",
		"7...2...6",
		".6....28.",
		"...419..5",
		"....8..79"
	};

	int i, j;
	printf("\n");
	for(i = 0; i < 9; i++)
	{
		for(j = 0; j < 9; j++)
		{
			printf("%c ", sudoku[i][j]);
		}
		printf("\n");
	}

	printf("\nis %s Sudoku\n", (isValidSudoku2(sudoku, 9, 9))?"Valid":"not Valid");
}
