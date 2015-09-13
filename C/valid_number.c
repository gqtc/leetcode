/*****************************************************
Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
Note: It is intended for the problem statement to be ambiguous. 
You should gather all requirements up front before implementing one.

*******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ISDIGIT(X)	(((X) >= '0') && ((X) <= '9'))
#define ISSPACE(X)	(((X) == ' ') || ((X) == '\t') || ((X) == '\0'))

int isNumber(char* s) 
{
    int slen = strlen(s);
    int i, begin = 0, end = slen;
    int eflag = 0;
    int dotflag = 0;

	while(begin <= end && ISSPACE(s[begin]))	begin++;
	while(end >= begin && ISSPACE(s[end]))	end--;

    if(begin > end)    return 0;
    
	if(s[begin] == '+' || s[begin] == '-')
	{
		begin += 1;
	}

    if(s[begin] == 'e') return 0;
    
    if(s[begin] == '.')
	{
	    dotflag = 1;
		if(ISDIGIT(s[begin+1]))	begin += 2;
		else return 0;
	}
	
    for(i = begin; i <= end; i++)
    {
    	if(s[i] == 'e')
    	{
    	    if(eflag)  return 0;
    	    eflag = 1;
    	    if(ISDIGIT(s[i+1]) || s[i+1] == '+' || s[i+1] == '-')
    			continue;
    		else
    		    return 0;
    	}
    	if(s[i] == '.')
    	{   
    	    if(dotflag)  return 0;
    	    dotflag = 1;
    	    if(eflag)   return 0;
    	    continue;
    	}    
    	if(s[i] == '+' || s[i] == '-')
    	{
    	    if(s[i-1] != 'e' || !ISDIGIT(s[i+1]))
    	        return 0;
    	    
    	    continue;
    	}
    	
		if(! ISDIGIT(s[i]))
			return 0;
    }
    return 1;
}

int main(int argc, char **argv)
{
	char *str = argv[1];

	printf("%s is %s a valid number\n", str, (isNumber(str)?"\b":"not"));
}
