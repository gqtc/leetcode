/*****************************************************
Given an array of strings, group anagrams together.

For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
Return:

[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note:
For the return value, each inner list's elements must follow the lexicographic order.
All inputs will be in lower-case.

*******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
 
typedef struct 
{
	char charsets[26];
	int index;
}Node;

int comparstr(const void *a, const void *b)
{
	return  strcmp(*((char **)a), *((char **)b)) ;
}

int comparnode(const void *a, const void *b)
{
	return  memcmp(((Node *)a)->charsets, ((Node *)b)->charsets, 26) ;
}

void setcharbit(char *str, char *charset)
{
	int i;
	int slen = strlen(str);
	unsigned int res = 0;
	
	for(i = 0; i < slen; i++)
	{
		charset[str[i]-'a']++;	
	}
}

char*** groupAnagrams(char** strs, int strsSize, int** columnSizes, int* returnSize) 
{
    unsigned int *bitset = calloc(strsSize, sizeof(unsigned int ));
    int i, j, k;

	int reslen = 0;
	
	Node *reshash = calloc(strsSize, sizeof(Node));
	
	qsort(strs, strsSize, sizeof(char *), comparstr);
	for(i = 0; i < strsSize; i++)
	{
		setcharbit(strs[i], reshash[i].charsets);
		reshash[i].index = i;
	}
	qsort(reshash, strsSize, sizeof(Node), comparnode);

	int *colsizes = calloc(strsSize, sizeof(int));
	j = 0;
	colsizes[0]++;
	for(i = 1; i < strsSize; i++)
	{
		if(memcmp(reshash[i].charsets, reshash[i-1].charsets, 26) == 0)
		{
			colsizes[j]++;
		}
		else
		{
			colsizes[++j]++;
		}
	}

	reslen = j+1;
	
	char ***res = calloc(reslen, sizeof(char **));
	k = 0;
	for(i = 0; i < reslen; i++)
	{
		res[i] = calloc(colsizes[i], sizeof(char *));
		for(j = 0; j < colsizes[i]; j++)
		{
			res[i][j] = strs[reshash[k++].index];
		}
	}

	*columnSizes = colsizes;
	*returnSize = reslen;
	return res;
}


int main()
{
	char *list[] = {"ate", "eat", "tea", "ghl", "acd", "bob", "boo"};
	int listlen = sizeof(list)/sizeof(char *);

	int reslen;
	int *colsize;
	int i, j;
	char ***res;
	res = groupAnagrams(list, listlen, &colsize, &reslen);

	for(i = 0; i < reslen; i++)
	{
		for(j = 0; j < colsize[i]; j++)
		{
			printf("%s ", res[i][j]);
		}
		
		printf("\n");
	}
}
