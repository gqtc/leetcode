/*****************************************************
Given a set of non-overlapping intervals, insert a new interval into 
the intervals (merge if necessary).

You may assume that the intervals were initially sorted according 
to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as 
[1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].

*******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Interval 
{
	int start;
	int end;
};

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct Interval* insert(struct Interval* intervals, int intervalsSize, struct Interval newInterval, int* returnSize) 
{
	struct Interval *res = NULL;
	int reslen = 0;
	int laststart, lastend;

	struct Interval *curnode = NULL;
	int i = 0, j = 0;
	int flag = 0;

	if(intervalsSize == 0)
	{
		res = calloc(1, sizeof(struct Interval));
		res->start = newInterval.start;
		res->end = newInterval.end;
		*returnSize = 1;
		return res;
	}
	
	if(newInterval.start < intervals[0].start)
	{
		laststart = newInterval.start;
		lastend = newInterval.end;
		j = 0;
	}
	else
	{
		laststart = intervals[0].start;
		lastend = intervals[0].end;
		j = 1;
	}
	
	for(i = j; i < intervalsSize; i++)
	{
		if(newInterval.start > intervals[i].start || flag)
		{
			curnode = intervals+i;
		}
		else
		{
			curnode = &newInterval;
			flag = 1;
			i--;
		}

		if(curnode->start <= lastend)
		{
			if(curnode->end > lastend)
			{
				lastend = curnode->end;
			}
		}
		else
		{
			reslen++;
			res = realloc(res, reslen*sizeof(struct Interval));
			res[reslen-1].start = laststart;
			res[reslen-1].end = lastend;
			laststart = curnode->start;
			lastend = curnode->end;
		}
	}

	if(flag == 0)
	{
		if(newInterval.start <= lastend)
		{
			if(newInterval.end > lastend)
			{
				lastend = newInterval.end;
			}
		}
		else
		{
			reslen++;
			res = realloc(res, reslen*sizeof(struct Interval));
			res[reslen-1].start = laststart;
			res[reslen-1].end = lastend;
			laststart = newInterval.start;
			lastend = newInterval.end;
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
	//struct Interval isets[] = {{1,2},{3,5},{6,7},{8,10},{12,16}};
	//struct Interval newnode = {4, 9};


	struct Interval isets[] = {{1,5}};
	struct Interval newnode = {2, 3};


	struct Interval *res = NULL;
	int reslen = 0; 
	int i;

	res = insert(isets, sizeof(isets)/sizeof(struct Interval), newnode, &reslen);

	for(i = 0; i < reslen; i++)
	{
		printf("(%d, %d) ", res[i].start, res[i].end);
	}
	printf("\n");
}

