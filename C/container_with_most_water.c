/*****************************************************
Given n non-negative integers a1, a2, ..., an, where each represents 
a point at coordinate (i, ai). n vertical lines are drawn such that the 
two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which 
together with x-axis forms a container, such that the container 
contains the most water.

Note: You may not slant the container.

*******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define min(x, y)  (((x)<(y))?(x):(y))

int maxArea(int* height, int heightSize) 
{
	int i, j;
	int res = 0;
	int area = 0;
	
	i = 0; 
	j = heightSize-1;
	
	while(i < j)
	{
	    area = min(height[i], height[j])*(j-i);
	    if(res < area)  res = area;
	    
	    if(height[i] < height[j])   i++;
	    else    j--;
	}

	return res;
}

int main()
{
	int height[] = {10, 15, 25, 5, 100, 105, 50, 20};

	int res = maxArea(height, sizeof(height)/sizeof(int));

	printf("res is %d\n", res);
}
