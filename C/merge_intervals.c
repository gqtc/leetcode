/*****************************************************
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].

*******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Interval 
{
	int start;
	int end;
};

int compar(const void *a, const void *b)
{
	return  ((struct Interval *)a)->start - ((struct Interval *)b)->start;
}

struct Interval* merge(struct Interval* intervals, int intervalsSize, int* returnSize) 
{
	int i;
	int laststart, lastend;
	struct Interval *res = NULL;
	int reslen = 0;

	if(intervalsSize == 0)	return res;
	qsort(intervals, intervalsSize, sizeof(struct Interval), compar);

	laststart = intervals[0].start;
	lastend = intervals[0].end;
	
	for(i = 1; i < intervalsSize; i++)
	{
		if(intervals[i].start <= lastend)
		{
			if(lastend < intervals[i].end)
			{
				lastend = intervals[i].end;
			}
		}
		else
		{
			reslen++;
			res = realloc(res, reslen*sizeof(struct Interval));
			res[reslen-1].start = laststart;
			res[reslen-1].end = lastend;

			laststart = intervals[i].start;
			lastend = intervals[i].end;
		}
	}
	
	reslen++;
	res = realloc(res, reslen*sizeof(struct Interval));
	res[reslen-1].start = laststart;
	res[reslen-1].end = lastend;

	*returnSize = reslen;
	return res;
}


int main()
{
	struct Interval isets[] = {{1,1},{5,7},{4,6},{1,1},{5,7},{3,4},{4,4},{0,0},{2,2},{4,4}};

	struct Interval *res = NULL;
	int reslen = 0; 
	int i;

	res = merge(isets, sizeof(isets)/sizeof(isets[0]), &reslen);

	for(i = 0; i < reslen; i++)
	{
		printf("(%d, %d) ", res[i].start, res[i].end);
	}
	printf("\n");
}
