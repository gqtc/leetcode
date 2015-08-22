/*****************************************************
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".

*******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max(x, y)  (((x)>(y))?(x):(y))

char* addBinary(char* a, char* b) 
{
	int alen = strlen(a);
	int blen = strlen(b);

	int reslen = max(alen, blen)+2;
	char *res = calloc(reslen, sizeof(char));
	int addbit = 0;
	int bitres = 0;

	int i, j, index = reslen-2;
	for(i = alen-1, j = blen-1; i >= 0 || j >= 0; i--, j--)
	{
		bitres = 0;
		if(i >= 0)	bitres += a[i]-'0';
		
		if(j >= 0)	bitres += b[j]-'0';

		bitres += addbit;
		res[index--] = bitres%2 + '0';
		
		addbit = bitres/2;
	}
	
	if(addbit)
	{
		res[index--] = addbit + '0';
	}

	index++;
	if(index > 0)
	{
		memmove(res, res+index, reslen-index);
	}
	return res;
}

int main()
{
	char *a = "111";
	char *b = "1";

	char *res = NULL;

	res = addBinary(a, b);
	printf("%s + %s = %s\n", a, b, res);
	free(res);
}
