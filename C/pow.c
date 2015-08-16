/*****************************************************
Implement pow(x, n).

*******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


double myPow(double x, int n) 
{
    double res = 1;
    double res2 = x;
	unsigned int m = 1;
	unsigned int nn = (n>=0)?n:(-n);

	while(1)
	{
		if(2 * m < nn)
		{
			res2 *= res2;
			m = 2 * m;
		}
		else if(2*m == nn)
		{
		    res *= res2 * res2;
		    if(n >= 0) 	return res;
		    else    return 1/res;
		}
		else
		{
			if(nn == 0)	
			{
			    if(n >= 0) 	return res;
		        else    return 1/res;
			}
			nn = nn-m;
			m = 1;
			res = res * res2;
			res2 = x;
		}
	}
}


int main(int argc, char **argv)
{
	double x = atoi(argv[1]);
	int n = atoi(argv[2]);

	printf("%f ^ %d = %f\n", x, n, myPow(x, n));
}
