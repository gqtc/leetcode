/*****************************************************
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct 
ways can you climb to the top?

*******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Time Limit Exceeded
int climbStairs_recurse(int n) 
{
	if(n <= 2)	return n;

	return climbStairs_recurse(n-1) + climbStairs_recurse(n-2);
}

int climbStairs_loop(int n)
{
	int i = 1;
	int res, res_1, res_2;

	res_1 = 1;
	res_2 = 0;
	res = 0;
	while(i <= n)
	{
		res = res_1 + res_2;
		res_2 = res_1;
		res_1 = res;
		i++;
	}
	return res;
}

int main(int argc, char **argv)
{
	int n = atoi(argv[1]);
	int res = climbStairs_loop(n);
	printf("climb %d stairs, there are %d distince ways\n", n, res);
}
