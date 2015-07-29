/*****************************************************
The count-and-say sequence is the sequence of integers beginning 
as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.

*******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRLEN 10240

char* countAndSay_loop(int n) 
{
    int last = 1;
    
    char *res = calloc(STRLEN, sizeof(char));

    char buf[STRLEN] = {};
    snprintf(res, STRLEN, "%s", "1");
    
    int count = 1;
    int slen = 0;
    int i;
    int pos = 0;
    while(n > 1)
    {
        slen = strlen(res);
        pos = 0;
        
        for(i = 1; i <= slen; i++)
        {
            if(res[i] == res[i-1])count++;
            else
            {
                snprintf(buf+pos, STRLEN-pos, "%d%c", count, res[i-1]);
				pos = strlen(buf);
                count = 1;
            }
        }
        memcpy(res, buf, STRLEN);
        memset(buf, 0, STRLEN);
        count = 1;
        n--;
    }
    return res;
}


char* countAndSay_recurse(int n) 
{
	if(n == 1)
	{
		char *resn = calloc(2, sizeof(char));
		snprintf(resn, 2, "1");
		return resn;
	}

	char *resn_1 = countAndSay_recurse(n-1);
	int i;
	int slen_1 = strlen(resn_1);
	int slen = 2*slen_1+1;
	char *resn = calloc(slen, sizeof(char));
	int pos = 0;
	int count = 1;
	
	for(i = 1; i <= slen_1; i++)
	{
		if(resn_1[i] == resn_1[i-1])count++;
		else
		{
			snprintf(resn+pos, slen-pos, "%d%c", count, resn_1[i-1]);
			pos = strlen(resn);
		    count = 1;
		}
	}
	free(resn_1);
	return resn;
}


int main()
{
	int i = 0;
	char *res = NULL;
	for(i = 1; i <= 10; i++)
	{
		res = countAndSay_loop(i);
		printf("%s\n", res);
		printf("--------------------------\n\n");
		free(res);
	}
}
