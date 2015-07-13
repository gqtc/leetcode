/*****************************************************
Given a string containing just the characters '(' and ')', find the 
length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", 
which has length = 2.

Another example is ")()())", where the longest valid parentheses 
substring is "()()", which has length = 4.
*******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int *sets;
    int len;
    int top;
}Stack;

int push(Stack *s, int key)
{
    if(s->top >= s->len)  return -1;

    s->sets[s->top ++] = key;
   
    return 0;
}

int pop(Stack *s)
{
    if(s->top == 0)   return -1;
    return s->sets[-- s->top];
}

Stack *initstack(int stlen)
{
	Stack *st = calloc(1, sizeof(Stack));
	st->sets = calloc(stlen, sizeof(int));
	st->len = stlen;
	st->top = 0;

	return st;

}

int longestValidParentheses(char* s) 
{
	int slen = strlen(s);
	char *ressets = calloc(slen+1 ,sizeof(char));

	Stack *st = initstack(slen);

	int reslen = 0;
	int i, j;
	for(i = 0; i < slen; i++)
	{
		switch(s[i])
		{
			case '(':
				push(st, i);
				break;
			case ')':
				if(st->top == 0)	continue;
				j = pop(st);
				ressets[j] = '(';
				ressets[i] = ')';
				break;
		}
	}

	i = 0; 
	while(i < slen)
	{
		if(ressets[i] == '\0')
		{
			i++;
			continue;
		}	

		int tmplen = strlen(ressets+i);
		if(reslen < tmplen)
		{
			reslen = tmplen;
		}
		i += tmplen;
	}
	return reslen;
}



int longestValidParentheses2(char* s) 
{
	int slen = strlen(s);

	Stack *st = initstack(slen);

	int reslen = 0;
	int tmplen = 0;
	int startindex = -1;
	int i;
	for(i = 0; i < slen; i++)
	{
		switch(s[i])
		{
			case '(':
				push(st, i);
				break;
			case ')':
				if(st->top == 0)
				{
					startindex = i;
				}
				else
				{
					pop(st);
					if(st->top == 0)
					{
						tmplen = i-startindex;
					}
					else
					{
						tmplen = i - st->sets[st->top-1];
					}
					if(reslen < tmplen)	reslen = tmplen;
				}
				break;
		}
	}
	return reslen;
}

int main()
{
	char *str = "()((()(";

	printf("longest substr is %d\n", longestValidParentheses(str));
}
