/*****************************************************
Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a 
challenge, please do not see below and ask yourself what are the 
possible input cases.

Notes: It is intended for this problem to be specified vaguely 
(ie, no given input specs). You are responsible to gather all the 
input requirements up front.

*******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int myAtoi(char* str) 
{
    int isminus = 0;
    char *num;
    int res = 0;

    while(*str == ' ')str++;

    if(str[0] == '+')
    {
        isminus = 0;
        str++;
    }
    else if(str[0] == '-')
    {
        isminus = 1;
        str++;
    }

    int bitnum = 0;
    
    for(num = str; *num != '\0'; num++)
    {
        bitnum = *num - '0';
        if(bitnum > 9 || bitnum < 0)  break;

        if(isminus)
        {
            if(res > (0x80000000-bitnum)/10)    return 0x80000000;
        }
        else
        {
            if(res > (0x7fffffff-bitnum)/10)    return 0x7fffffff;
            
        }
        res = res * 10 + bitnum;
    }
    if(isminus) return -res;
    else        return res;
}

int main()
{
	int res;
	char *str = "-19347534";

	res = myAtoi(str);
	printf("res is %d\n", res);
}
