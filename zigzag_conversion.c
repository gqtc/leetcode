/*****************************************************
The string "PAYPALISHIRING" is written in a zigzag pattern on a 
given number of rows like this: (you may want to display this pattern 
in a fixed font for better legibility)

P    A    H   N
A P L S I I G
Y    I    R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given 
a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

*******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getlinenum(int k, int linenum)
{
	int i = 0;
	int res = 0;

	if(k == 0)
	{
		return linenum-1;
	}

	if(linenum == 1)
	{
		return 0;
	}
	else
	{
		return k+1 + (linenum-2) * (2 * (k+1) - 1);
	}
}

char *expandset(int setsize, int n, int *expandk)
{
	int k;
	int mod, div;
	mod = (setsize-n)%(2*n - 2);
	div = (setsize-n)/(2*n - 2);
	if(setsize < n)
	{
		k = 0;
	}
	else if(mod == 0)
	{
		k = div;
	}
	else
	{
		k = div + 1;
	}

	*expandk = k;

	char *resset = calloc(n + (2*n - 2) * k, sizeof(char));
	return resset;
}

char* convert(char* s, int numRows) 
{
    int size = strlen(s);
    int n = numRows;
	int linenum, colnum;
	int mod, div;
	int i, j;
	int k;
	if(n == 1)return s;

	char *resset = calloc(size+1, sizeof(char));
	
	if(n == 2)
	{
		for(i = 0; i < size; i++)
		{
			if(i%2 == 0)
			{
				resset[i/2] = s[i];
			}
			else
			{
				resset[(size+1)/2+i/2] = s[i];
			}
		}
		return resset;
	}
	
	char *expset = expandset(size, n, &k);

	for(i = 0; i < size; i++)
	{
		mod = i % (2*n-2);
		div = i / (2*n-2);

		if(mod < n)
		{
			linenum = mod + 1;
			if(mod == 0 || mod == n-1)
			{
				colnum = div + 1;
			}
			else
			{
				colnum = 2 * div + 1;
			}	
		}
		else
		{
			linenum = 2*n-1 - mod;
			colnum = 2 * (div + 1);
		}

		j = getlinenum(k, linenum) + colnum - 1;
        expset[j] = s[i];
	}

	j = 0;
	for(i = 0; i < n + k*(2*n-2); i++)
	{
		if(expset[i])
		{
			resset[j++] = expset[i];
		}
	}
	free(expset);
	return resset;
}

int main()
{
	char *str = "PAYPALISHIRING";

	char *res = convert(str, 3);

	printf("res is %s\n", res);

	free(res);
}
