/*****************************************************
Given an array of words and a length L, format the text such that 
each line has exactly L characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as 
many words as you can in each line. Pad extra spaces ' ' when necessary 
so that each line has exactly L characters.

Extra spaces between words should be distributed as evenly as possible. 
If the number of spaces on a line do not divide evenly between words, 
the empty slots on the left will be assigned more spaces than the slots on 
the right.

For the last line of text, it should be left justified and no extra space is 
inserted between words.

For example,
words: ["This", "is", "an", "example", "of", "text", "justification."]
L: 16.

Return the formatted lines as:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
Note: Each word is guaranteed not to exceed L in length.

Corner Cases:
A line other than the last line might contain only one word. What 
should you do in this case?
In this case, that line should be left-justified.

*******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char * reformat(char **words, int startpos, int endpos, int charslen, int maxWidth)
{
	char *buf = calloc(maxWidth+1, sizeof(char));
	int wordcnts = endpos-startpos;

	int leftspacelen = 0;
	int rightspacelen = 0;
	int leftcnts = 0;
	int rightcnts = 0;

	int spacecnts = 0;
	int spaceslen = 0;
	
	int i;

	
	if(wordcnts == 1)
	{
		rightspacelen = maxWidth-charslen;
		sprintf(buf, "%s%*s", words[startpos], rightspacelen, "");
		return buf;
	}

	/*
		spacecnts表示空格块(empty slots)的个数，也就是单词数减1
		spaceslen表示空格的总数
		为了尽量均匀，将所有空格块分成左右两部分
		leftcnts表示左边空格块的个数
		rightcnts表示右边空格块的个数
		leftspacelen表示每个左边空格块包含的空格数
		rightspacelen表示每个右边空格块包含的空格数
	*/

	spacecnts = wordcnts - 1;
	spaceslen = maxWidth-charslen;
	leftcnts = spaceslen - spacecnts * (spaceslen/spacecnts);
	rightcnts = spacecnts - leftcnts;
	leftspacelen = spaceslen/spacecnts + 1;
	rightspacelen = spaceslen/spacecnts;
	

	sprintf(buf, "%s", words[startpos]);


	for(i = startpos+1; i < endpos; i++)
	{
		if(i - startpos <= leftcnts)
		{
			sprintf(buf+strlen(buf), "%*s%s", leftspacelen, "", words[i]);
		}
		else
		{
			sprintf(buf+strlen(buf), "%*s%s", rightspacelen, "", words[i]);
		}
	}
	return buf;
}



char** fullJustify(char** words, int wordsSize, int maxWidth, int* returnSize) 
{
	int i;
	char *buf = NULL;

	int leftlen = 0;
	int wordlen = 0;
	int charslen = 0;

	int startpos = 0;
	int endpos = 0;

	char **res = calloc(wordsSize, sizeof(char *));
	int reslen = 0;

    /*
		扫描words数组，看哪些单词可以放到一行中
		startpos表示起点索引，endpos-1表示终点索引
		所以，endpos-startpos就表示一行中单词的总数
		charslen表示一行中字母的总数
	*/

	leftlen = maxWidth;
	for(i = 0; i < wordsSize; i++)
	{
		if((wordlen = strlen(words[i])) > leftlen)
		{
			res[reslen++] = reformat(words, startpos, endpos, charslen, maxWidth);
			startpos = endpos;
			leftlen = maxWidth;
			charslen = 0;
		}
		
		charslen += wordlen;
		endpos++;
		leftlen -= wordlen+1;
	}	

	/*
		最后一行特殊处理，根据题目要求，
		最后一行的单词间只能有一个空格
	*/
	buf = calloc(maxWidth+1, sizeof(char));
	for(i = startpos; i < endpos; i++)
	{
		if(i < endpos-1)
			sprintf(buf+strlen(buf), "%s ", words[i]);
		else
			sprintf(buf+strlen(buf), "%s", words[i]);
	}

	//填充最后一行剩下的空格
	sprintf(buf+strlen(buf), "%*s", maxWidth-strlen(buf), "");
	res[reslen++] = buf;

	*returnSize = reslen;
	return res;
}

int main()
{
	char *words[] = {"My","momma","always","said,","Life","was","like",
					"a","box","of","chocolates.","You","never","know",
					"what","you're","gonna","get."};

	int wordslen = sizeof(words)/sizeof(char *);

	char **res = NULL;
	int reslen = 0;
	int i;
	
	res = fullJustify(words, wordslen, 20, &reslen);
	for(i = 0; i < reslen; i++)
	{
		printf("\"%s\"\n", res[i]);
		free(res[i]);
	}
	free(res);
}

