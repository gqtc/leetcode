/*****************************************************
Write an efficient algorithm that searches for a value in an m x n matrix. 
This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of 
the previous row.

For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.

*******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) 
{
	int begin = 0, end =  matrixColSize *   matrixRowSize - 1;
	int mid;
	int row, col;

	while(begin <= end)
	{
		mid = begin+(end-begin)/2;
		row = mid/matrixColSize;
		col = mid%matrixColSize;

		if(matrix[row][col] == target)	return 1;

		if(matrix[row][col] < target)	begin = mid+1;
		else	end = mid-1;
	}
	return 0;
}

int main(int argc, char **argv)
{
	int line1[] = {1,2,3,4};
	int line2[] = {5,6,7,8};
	int line3[] = {9,10,11,12};
	int line4[] = {13,14,15,16};
	int *matrix[] = {line1, line2, line3, line4};

	int target = atoi(argv[1]);
	int res = searchMatrix(matrix, 4, 4, target);

	printf("%s\n", res?"True":"False");

}
