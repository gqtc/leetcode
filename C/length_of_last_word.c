/*****************************************************
Given a string s consists of upper/lower-case alphabets and empty 
space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space 
characters only.

For example, 
Given s = "Hello World",
return 5.

*******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lengthOfLastWord(char* s) 
{
    int slen = strlen(s);

    int reslen = 0;
    int i, j;

	j = slen-1;
	while(j >= 0 && s[j] == ' ')j--;

    for(i = 0; i <= j; i++)
    {
		if(s[i] == ' ')
		{
			reslen = 0;
		}
		else
		{
			reslen++;
		}
    }
    return reslen;
}

int main(int argc, char **argv)
{
	char *str = argv[1];
	int res = lengthOfLastWord(str);
	printf("the last word len of \"%s\" is %d\n", str, res);
}
