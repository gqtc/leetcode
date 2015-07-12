/*****************************************************
Given a string S, find the longest palindromic substring in S. 
You may assume that the maximum length of S is 1000, and 
there exists one unique longest palindromic substring.
*******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findpasubstr(char *s, int index1, int index2, int slen, char **begin, char **end)
{
    int res;
    while(index1 >= 0 && index2 <= slen-1)
    {
        if(s[index1] == s[index2])
        {
            index1--;
            index2++;
        }
        else
        {
            break;
        }
    }
    res = index2-index1-1;
    if(res != 0)
    {
        *begin = s+index1+1;
        *end = s+index2-1;
    }
    return res;
    
}

char* longestPalindrome(char* s) 
{
    int res = 0;
    int len1, len2;
    int i;
    int slen = strlen(s);
    char *begin, *end;
    char *resbegin, *resend;
    char *resbuf = NULL;
    for(i = 0; i < slen; i++)
    {
        len1 = findpasubstr(s, i, i, slen, &begin, &end);
        if(res < len1)
        {
            resbegin = begin;
            resend = end;
            res = len1;
        }
        
        len2 = findpasubstr(s, i, i+1, slen, &begin, &end);
        if(res < len2)
        {
            resbegin = begin;
            resend = end;
            res = len2;
        }
        
    }
    resbuf = calloc((resend-resbegin+2), sizeof(char));
    memcpy(resbuf, resbegin, resend-resbegin+1);
    return resbuf;
}

int main()
{
	char str[] = "abacdfgdcaba";
	char *res;

	res = longestPalindrome(str);
	if(res)
	{
		printf("the longest palindrome is %s\n", res);
		free(res);
	}
}
