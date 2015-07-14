/*****************************************************
Given n pairs of parentheses, write a function to generate all 
combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"

*******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

//对于n，结果集的最大值，就是针对n-1的
//结果集中的每一个结果，在其中的每个'(' 的
//前后，都增加一个"()"。
int getreslen(int n)
{
	if(n == 1)	return 1;

	return 2 * (n-1) * getreslen(n-1);
}

void getres(int left, int right, char *oneres, int oneresindex, char **res, int *index)
{	
	if(left == 0 && right == 0)
	{
		char *buf = calloc(strlen(oneres)+1, sizeof(char));
		sprintf(buf, "%s", oneres);
		res[*index] = buf;
		(*index)++;
		return;
	}

	if(left > 0)
	{
		oneres[oneresindex] = '(';
		getres(left-1, right, oneres, oneresindex+1, res, index);
	}

	if(right > 0 && right > left)
	{
		oneres[oneresindex] = ')';
		getres(left, right-1, oneres, oneresindex+1, res, index);
	}
}

char** generateParenthesis(int n, int* returnSize) 
{
	char **resn;
	int sizen = 0;
	int curindex = 0;

	sizen = getreslen(n);
	resn = calloc(sizen, sizeof(char *));

	char *oneres = calloc(2*n+1, sizeof(char));

	getres(n, n, oneres, 0, resn, &curindex);
	
	*returnSize = curindex;

	free(oneres);
	return resn;
}

int main()
{
	int n = 5;
	int i, j;

	char **res;
	int reslen;
	
	for(i = 1; i <= n; i++)
	{
		res = generateParenthesis(i, &reslen);
		printf("\n-------%d-------\n", i);
		for(j = 0; j < reslen; j++)
		{
			printf("%s\n", res[j]);
			free(res[j]);
		}
		free(res);
	}
}
