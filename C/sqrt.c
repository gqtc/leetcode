/*****************************************************
Implement int sqrt(int x).

Compute and return the square root of x.

*******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <float.h>
#include <math.h>

#define ABS(a)	( (a) < 0 ) ? (- (a)):(a)


double mySqrt_binarysearch(int x) 
{
	if(x <= 0)	return 0;

	double begin = 1;
	double end = x/2+1;
	double mid, lastmid;

	mid = begin + (end-begin)/2;
	do{
		if(mid < x/mid) begin = mid;
		else	end = mid;

		lastmid = mid;
		mid = begin + (end-begin)/2;
	}
	while(ABS(lastmid-mid) > FLT_MIN);
	
	return mid;
}


double mySqrt_newton(int x) 
{
	if(x <= 0)	return 0;

	double res, lastres;

	res = x;	//初始值，可以为任意非0的值
	
	do{
		lastres = res;
		res = (res + x/res)/2;
	}
	while(ABS(lastres-res) > FLT_MIN);

	return res;
}


float InvSqrt(float x)
{
    float xhalf = 0.5f * x;
    int i = *(int*)&x; 
    i = 0x5f375a86 - (i>>1); 
    x = *(float*)&i;
    x = x*(1.5f-xhalf*x*x); 
    x = x*(1.5f-xhalf*x*x); 
    x = x*(1.5f-xhalf*x*x);

    return 1/x;
}


int main(int argc, char **argv)
{
	clock_t begin, end;
	int num = atoi(argv[1]);
	double res;
	
	int i;
	int loopcnts = 1000000;
	

	begin = clock();
	for(i = 0; i < loopcnts; i++)
		res = mySqrt_binarysearch(num);
	end = clock();
	printf("mySqrt_binarysearch(%d) = %f, spent time is %f\n", num, res, (double)(end-begin));


	begin = clock();
	for(i = 0; i < loopcnts; i++)
		res = mySqrt_newton(num);
	end = clock();
	printf("mySqrt_newton(%d) = %f, spent time is %f\n", num, res, (double)(end-begin));


	begin = clock();
	for(i = 0; i < loopcnts; i++)
		res = InvSqrt(num);
	end = clock();
	printf("InvSqrt(%d) = %f, spent time is %f\n", num, res, (double)(end-begin));



	begin = clock();
	for(i = 0; i < loopcnts; i++)
		res = sqrt(num);
	end = clock();
	printf("system sqrt(%d) = %f, spent time is %f\n", num, res, (double)(end-begin));

}
