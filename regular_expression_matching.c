/*****************************************************
Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") �� false
isMatch("aa","aa") �� true
isMatch("aaa","aa") �� false
isMatch("aa", "a*") �� true
isMatch("aa", ".*") �� true
isMatch("ab", ".*") �� true
isMatch("aab", "c*a*b") �� true

*******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char isMatch(char* s, char* p) 
{  	 
	if (*p == 0) return *s == 0;  
	
	if (*(p+1) != '*')	
	{  
		if (*s != 0 && (*p == *s || *p == '.')) return isMatch(s+1, p+1);  
		else return 0;	
	}  
	else  
	{  
		// *s == *p  
		while (*s != 0 && (*s == *p || *p == '.'))	
		{  
			if (isMatch(s, p+2)) return 1;  
			s++;  
		}  
		return (isMatch(s, p+2));  
	}  
} 


int main()
{
	char str[] = "aaabcab";
	char pat[] = "a*ab*cabd*";

	//match
	printf("%s %s %s\n", str, 
		isMatch(str,pat)?"match":"not match", pat);
}
