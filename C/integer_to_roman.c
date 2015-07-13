/*****************************************************
Given an integer, convert it to a roman numeral.

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

int num2char(char *resbuf, int pos, int bits, int bit)
{
	switch(bits)
	{
		case 1:
		{
			if(bit == 4)
			{
				resbuf[pos--] = 'V';
				resbuf[pos--] = 'I';
				return pos;
			}
			if(bit == 9)
			{
				resbuf[pos--] = 'X';
				resbuf[pos--] = 'I';
				return pos;
			}
			while(bit)
			{
				if(bit == 5)
				{
					resbuf[pos--] = 'V';

					break;
				}
				resbuf[pos--] = 'I';
				bit--;
			}
			return pos;

			break;
		}
		case 2:
		{
			if(bit == 4)
			{
				resbuf[pos--] = 'L';

				resbuf[pos--] = 'X';
				return pos;
			}
			if(bit == 9)
			{
				resbuf[pos--] = 'C';
				resbuf[pos--] = 'X';
				return pos;
			}
			while(bit)
			{
				if(bit == 5)
				{
					resbuf[pos--] = 'L';

					break;
				}
				resbuf[pos--] = 'X';
				bit--;
			}
			return pos;

		}
		case 3:
		{
			if(bit == 4)
			{
				resbuf[pos--] = 'D';

				resbuf[pos--] = 'C';
				return pos;
			}
			if(bit == 9)
			{
				resbuf[pos--] = 'M';
				resbuf[pos--] = 'C';
				return pos;
			}
			while(bit)
			{
				if(bit == 5)
				{
					resbuf[pos--] = 'D';

					break;
				}
				resbuf[pos--] = 'C';
				bit--;
			}
			return pos;
		}
		case 4:
		{
			while(bit)
			{
				resbuf[pos--] = 'M';
				bit--;
			}
			return pos;
		}
	}
}


char* intToRoman(int num) 
{
    char resbuf[20] = {0};
    int i;
    int bit;
    int temp = 0;

	int pos = 18;
    while(num)
    {
        temp++;
        bit = num%10;
        num = num/10;
        pos = num2char(resbuf, pos, temp, bit);
    }

    char *buf = malloc(20);
    snprintf(buf, 20, "%s", resbuf+pos+1);
	return buf;
}

int main()
{
	int i;
	char *res = NULL;

	for(i = 1; i<= 3999; i++)
	{
		res = intToRoman(i);
		printf("%d--->%s\n", i, res);
		free(res);
	}
}
