/*****************************************************
Given n non-negative integers representing an elevation map 
where the width of each bar is 1, compute how much water it is 
able to trap after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

*******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	int value;
	int index;
}Node;

#define min(x, y)  (((x)<(y))?(x):(y))

void swapnode(Node *n1, Node *n2)
{
	Node tmp;
	tmp.value = n1->value;
	tmp.index = n1->index;

	n1->value = n2->value;
	n1->index = n2->index;

	n2->value = tmp.value;
	n2->index = tmp.index;
}
int partition(Node *nset, int left, int right)
{
	int key = nset[right].value;
	int i = left-1;
	int j;
	for(j = left; j < right; j++)
	{
		if(nset[j].value > key)
		{
			i++;
			swapnode(nset+i, nset+j);
		}
	}
	swapnode(nset+i+1, nset+right);
	return i+1;
}


void qsortnode(Node *nset, int left, int right)
{
	int q = -1;
	if(left < right)
	{
		q = partition(nset, left, right);
		qsortnode(nset, left, q-1);
		qsortnode(nset, q+1, right);
	}
}

int trap(int* height, int heightSize) 
{
	if(heightSize <= 2)return 0;
	
	Node *vi = calloc(heightSize, sizeof(Node));
	int i;
	int sum = 0;
	int left, right, minvalue;

	for(i = 0; i < heightSize; i++)
	{
		vi[i].value = height[i];
		vi[i].index = i;
	}

	qsortnode(vi, 0, heightSize-1);

	left = right = vi[0].index;
	sum = 0;
	
	for(i = 1; i < heightSize; i++)
	{
		int index = vi[i].index;
		int value = vi[i].value;
		if(index < right && index > left)
		{
			sum -= value;
		}
		else if(index < left)
		{
			minvalue = min(height[index], height[left]);
			sum += minvalue * (left-index-1);
			left = index;
		}
		else if(index > right)
		{
			minvalue = min(height[index], height[right]);
			sum += minvalue * (index-right-1);
			right = index;
		}
	}
	
	return sum;
}



int trap_nb(int* height, int heightSize) 
{
	
	int i;
	int sum = 0;
	int maxindex = 0;
	int prehight = 0;

	for(i = 1; i < heightSize; i++)
	{
		if(height[i] > height[maxindex])
		{
			maxindex = i;
		}
	}

	prehight = 0;
	for(i = 0; i < maxindex; i++)
	{
		if(height[i] > prehight)
		{
			prehight = height[i];
		}
		sum += prehight - height[i];
	}

	prehight = 0;
	for(i = heightSize-1; i > maxindex; i--)
	{
		if(height[i] > prehight)
		{
			prehight = height[i];
		}
		sum += prehight - height[i];
	}
	return sum;
}

int main()
{
	int height[] = {0,1,0,2,1,0,1,3,2,1,2,1};

	int res = trap_nb(height, sizeof(height)/sizeof(int));
	printf("res is %d\n", res);
}
