/*****************************************************
Determine whether an integer is a palindrome. Do this without 
extra space.

Some hints:
Could negative integers be palindromes? (ie, -1)

If you are thinking of converting the integer to string, 
note the restriction of using extra space.

You could also try reversing an integer. However, 
if you have solved the problem "Reverse Integer", you know that 
the reversed integer might overflow. How would you handle such case?

There is a more generic way of solving this problem.

*******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isPalindrome(int x) 
{
	int bitnums;
	int specialbit;

	int y;
	int i;

	if(x < 0)	return 0;
	if(x < 10)  return 1;

	y = x;
	bitnums = 0;
	while(y)
	{
		bitnums++;
		y /= 10;
	}

	specialbit = (bitnums+1)/2;

	y = 0;
	i = 0;
	while(1)
	{
		i++;
		y = y * 10 + x%10;
		if(bitnums % 2 == 0 || specialbit != i)
		{
			x = x/10;
		}
		
		if(specialbit == i)
		{
			return x == y;
		}
	}
}

int main()
{
	int a1 = 12321;
	int a2 = 1221;
	int a3 = 1234;

	printf("%d %s a Palindrome Number\n", a1, isPalindrome(a1)?"is":"is not");
	printf("%d %s a Palindrome Number\n", a2, isPalindrome(a2)?"is":"is not");
	printf("%d %s a Palindrome Number\n", a3, isPalindrome(a3)?"is":"is not");	
}
