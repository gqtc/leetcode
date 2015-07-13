/*****************************************************
Write a function to find the longest common prefix string amongst 
an array of strings.

*******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize) 
{
    int i, j;
    char c;
    if(strsSize == 0)return "";
    char *buf = calloc(strlen(strs[0]) + 1, sizeof(char));
    for(i = 0; i < strlen(strs[0]); i++)
    {
        c = strs[0][i];
        for(j = 1; j < strsSize; j++)
        {
            if(strs[j][i] != c)
                break;
        }
        if(j < strsSize)
            break;
    }
    if(i == 0)  return "";
    memcpy(buf, strs[0], i);
    return buf;
}


int main()
{
	char *strset[] = {"abcd", "abce", "abcfe", "abc"};
	char *res;

	res = longestCommonPrefix(strset, sizeof(strset)/sizeof(char *));
	free(res);
	printf("res is %s\n", res);
}

