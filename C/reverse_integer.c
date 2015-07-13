/*****************************************************
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

Have you thought about this?

Here are some good questions to ask before coding. 
Bonus points for you if you have already thought through this!

If the integer's last digit is 0, what should the output be? 
ie, cases such as 10, 100.

Did you notice that the reversed integer might overflow? 
Assume the input is a 32-bit integer, then the reverse of 
1000000003 overflows. How should you handle such cases?

For the purpose of this problem, assume that your function 
returns 0 when the reversed integer overflows.

*******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int reverse(int x) 
{
    int tmpx;
    int res = 0;
    int i;
    if((unsigned)x == 0x80000000) return 0;
    tmpx = (x < 0)?-x:x;
    while(tmpx)
    {
        if(0x7fffffff / 10 < res)	return 0;
        res = res * 10 + tmpx%10;
        tmpx /= 10;
    }
    return (x < 0)?-res:res;
}

int main()
{
	int num = 1234;
	int res = reverse(num);

	printf("res is %d\n", res);
}
