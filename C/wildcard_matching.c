/*****************************************************
'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") ¡ú false
isMatch("aa","aa") ¡ú true
isMatch("aaa","aa") ¡ú false
isMatch("aa", "*") ¡ú true
isMatch("aa", "a*") ¡ú true
isMatch("ab", "?*") ¡ú true
isMatch("aab", "c*a*b") ¡ú false

*******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isMatchcore(char* s, char* p, int *exitflag) 
{
	if(*s == '\0')
	{
		if(*p == '\0')	return 1;
		if(*p == '*' && *(p+1) == '\0') return 1;
		*exitflag = 1;
		return 0;
	}
	
	if(*p != '*')
	{
		if(*p == *s || *p == '?')	return isMatchcore(s+1, p+1, exitflag);
		return 0;
	}


	if(*p == '*')
	{		
		if(*(p+1) == '\0')	return 1;
		int i = 0;
		int slen = strlen(s);
		while(i < slen && (isMatchcore(s+i, p+1, exitflag) == 0))
		{
			if(*exitflag == 1)	
			{
			    return 0;
			}
			i++;
		}
		if(i < slen)	return 1;
		return 0;
	}
}


void predealpattern(char *p)
{
	int i = 0;
	int plen = strlen(p);

	int j = 0;
	int lastchar = 0;
	for(i = 0; i <= plen; i++)
	{
		if(p[i] != '*' || lastchar != '*')
		{
			p[j] = p[i];
			j++;
		}
		lastchar = p[i];
	}
}

int isMatch_recurse(char* s, char* p) 
{
    predealpattern(p);
    int exitflag = 0;
    return isMatchcore(s, p, &exitflag);
}


int isMatch_loop(char* s, char* p)
{
	char *lastp = NULL;
	char *lasts = NULL;
	
	while(*s != '\0')
	{
		if(*s == *p || *p == '?')
		{
			s++;	p++;
		}
		else if(*p == '*')
		{
			p++;
			if(*p == '\0')	return 1;
			lastp = p;
			lasts = s;
		}
		else if(lastp != NULL)
		{
			p = lastp;
			s = ++lasts;
		}
		else
		{
			return 0;
		}
	}

	while(*p == '*')p++;
	return *p == '\0';
}

int main(int argc, char **argv)
{
	//char *str = argv[1];
	//char *p = argv[2];

	char str[] = "abefcdgiescdfimde";
	char p[] = "ab*cd?i*de";

	printf("(%s) --- (%s)\n", str, p);
	printf("%s\n", isMatch_loop(str, p)?"Match":"not Match");
}
