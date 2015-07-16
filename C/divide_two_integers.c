/*****************************************************
Divide two integers without using multiplication, division and mod 
operator.

If it is overflow, return MAX_INT.

*******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int divide(int dividend, int divisor) 
{
    unsigned res = 0;
    
    if(divisor == 0)    return 0x7fffffff;
    
    unsigned int posdividend = (dividend < 0)?-dividend:dividend;
    unsigned int posdivisor = (divisor < 0)?-divisor:divisor;
    
    while(posdividend >= posdivisor)
    {
    	int n = 0;
    	unsigned int tmp = posdivisor;
    	while(tmp <= posdividend)
    	{
    		tmp <<= 1;
    		n++;
    		if(tmp == 0)break;
    	}	

    	res += 1 << (n-1);
		if(tmp == 0)	posdividend -= 0x80000000;
		else    	posdividend -= tmp>>1;
    	
    }

    if((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0))
        return -res;
    if(res == 0x80000000)   return 0x7fffffff;
    return res;    
}

int main()
{
    printf("0/2 = %d\n", divide(0, 2));
    printf("10/2 = %d\n", divide(10, 2));
	printf("10/3 = %d\n", divide(10, 3));
	printf("10/5 = %d\n", divide(10, 5));
	printf("10/7 = %d\n", divide(10, 7));
	printf("10/10 = %d\n", divide(10, 10));
	printf("10/11 = %d\n", divide(10, 11));
	printf("-1/1 = %d\n", divide(-1, 1));
	printf("1/-1 = %d\n", divide(1, -1));
	printf("-1/-1 = %d\n", divide(-1, -1));
	printf("2147483647/1 = %d\n", divide(2147483647, 1));
	printf("-2147483647/1 = %d\n", divide(-2147483647, 1));
	printf("2147483647/-1 = %d\n", divide(2147483647, -1));
	printf("-2147483647/-1 = %d\n", divide(-2147483647, -1));
	printf("2147483647/2 = %d\n", divide(2147483647, 2));
	printf("-2147483647/10 = %d\n", divide(-2147483647, 10));
	printf("-2147483648/1 = %d\n", divide(-2147483648, 1));
	printf("-2147483648/-1 = %d\n", divide(-2147483648, -1));
}
