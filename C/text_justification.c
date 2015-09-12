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
		spacecnts��ʾ�ո��(empty slots)�ĸ�����Ҳ���ǵ�������1
		spaceslen��ʾ�ո������
		Ϊ�˾������ȣ������пո��ֳ�����������
		leftcnts��ʾ��߿ո��ĸ���
		rightcnts��ʾ�ұ߿ո��ĸ���
		leftspacelen��ʾÿ����߿ո������Ŀո���
		rightspacelen��ʾÿ���ұ߿ո������Ŀո���
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
		ɨ��words���飬����Щ���ʿ��Էŵ�һ����
		startpos��ʾ���������endpos-1��ʾ�յ�����
		���ԣ�endpos-startpos�ͱ�ʾһ���е��ʵ�����
		charslen��ʾһ������ĸ������
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
		���һ�����⴦��������ĿҪ��
		���һ�еĵ��ʼ�ֻ����һ���ո�
	*/
	buf = calloc(maxWidth+1, sizeof(char));
	for(i = startpos; i < endpos; i++)
	{
		if(i < endpos-1)
			sprintf(buf+strlen(buf), "%s ", words[i]);
		else
			sprintf(buf+strlen(buf), "%s", words[i]);
	}

	//������һ��ʣ�µĿո�
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

