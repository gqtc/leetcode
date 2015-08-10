/*****************************************************
Given two numbers represented as strings, return multiplication of 
the numbers as a string.

Note: The numbers can be arbitrarily large and are non-negative.

*******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *multiply_c(char *str, char c, int k)
{
	int base = c - '0';
	int slen = strlen(str);
	char *res = calloc(slen+2+k, sizeof(char));
	int i;
	int addbit = 0, tmpres = 0;
	
	for(i = slen-1; i >= 0; i--)
	{
		tmpres = base * (str[i]-'0') + addbit;
		res[i+1] = tmpres % 10 + '0';
		addbit = tmpres / 10;
	}
	res[i+1] = addbit + '0';
	for(i = slen+1; i < slen+1+k; i++)
	{
		res[i] = '0';
	}
	return res;
}

void adjust(char *str)
{
	int i = 0;
	int slen = strlen(str);
	int adjustlen = 0;

	while(i < slen && str[i] == '0')i++;
	adjustlen = i;
	if(adjustlen == slen)
	{
		str[1] = '\0';
	}
	else
	{
		for(i = 0; i < slen - adjustlen; i++)
		{
			str[i] = str[i+adjustlen];
		}
		str[i] = '\0';
	}
}

char* multiply(char* num1, char* num2) 
{
	int slen1 = strlen(num1);
	int slen2 = strlen(num2);
	
    char **resset = calloc(slen2, sizeof(char *));
    char *res = calloc(slen1+slen2+1, sizeof(char));

    int i, j, k;
    k = 0;
    for(i = slen2-1; i >= 0; i--)
    {
		resset[k] = multiply_c(num1, num2[i], k);
		k++;
    }

    int tmp = 0, index = 0, addbit = 0;
    for(i = 0; i < slen1+slen2; i++)
    {    	
    	for(j = 0; j < k; j++)
    	{
    		index = strlen(resset[j]) - 1 - i;
    		if(index >= 0)
    		{
				tmp += resset[j][index] - '0';
    		}
    	}
    	tmp += addbit;
    	res[slen1+slen2 - 1 - i] = tmp%10 + '0';
    	addbit = tmp/10;
    	tmp = 0;
    }
    adjust(res);

    for(j = 0; j < k; j++)
	{
		free(resset[j]);
	}
	free(resset);
    return res;
}

int main(int argc, char **argv)
{
	char *str1 = argv[1];
	char *str2 = argv[2];

	char *res = NULL;
	res = multiply(str1, str2);
	printf("%s * %s = %s\n", str1, str2, res);
}
