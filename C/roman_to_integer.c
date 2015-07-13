/*****************************************************
Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.

1				I
5				V
10				X
50				L
100				C
500				D
1000			M

*******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int romanchar2int(char *s, int index)
{
    switch(s[index])
    {
        case 'I':   return 1;
        case 'V':
        {
            if(index > 0 && s[index-1] == 'I')  return 3;
            else    return 5;
        }
        case 'X':
        {
            if(index > 0 && s[index-1] == 'I')  return 8;
            else    return 10;
        }
        case 'L':
        {
            if(index > 0 && s[index-1] == 'X')  return 30;
            else    return 50;
        }
        case 'C':
        {
            if(index > 0 && s[index-1] == 'X')  return 80;
            else    return 100;
        }
        case 'D':
        {
            if(index > 0 && s[index-1] == 'C')  return 300;
            else    return 500;
        }
        case 'M':
        {
            if(index > 0 && s[index-1] == 'C')  return 800;
            else    return 1000;
        }
        
    }
    
}

int romanToInt(char* s) 
{
    int i = 0;
    int res = 0;
    
    while(i < strlen(s))
    {
        res += romanchar2int(s, i);
        i++;
    }
    return res;
}


int main()
{
	char str[] = "MMMCMLXXXVIII";
	int res = romanToInt(str);

	printf("%s-->%d\n", str, res);
}
