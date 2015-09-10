/*****************************************************
Implement int sqrt(int x).

Compute and return the square root of x.

*******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int mySqrt(int x) 
{
	if(x == 0)	return 0;
	unsigned int left = 1, right = x;
	unsigned int begin ,end, mid;

	while(left < right)
	{
		left <<= 1;
		right >>= 1;
	}

	if(left == right)	return left;

	begin = right;
	end = left;

	while(begin <= end)
	{
		mid = begin + (end-begin)/2;
		if(mid == x/mid)	return mid;

		if(mid < x/mid) begin = mid+1;
		else	end = mid-1;
	}

	return end;

}


int main(int argc, char **argv)
{
	int num = atoi(argv[1]);

	printf("sqrt(%d) = %d\n", num, mySqrt(num));
}
