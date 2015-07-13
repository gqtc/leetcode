/*****************************************************
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', 
determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all 
valid but "(]" and "([)]" are not.

*******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char *sets;
    int len;
    int top;
}Stack;

int push(Stack *s, char key)
{
    if(s->top >= s->len)  return -1;

    s->sets[s->top ++] = key;
   
    return 0;
}

char pop(Stack *s)
{
    if(s->top == 0)   return '\0';
    return s->sets[-- s->top];
}

int isValid(char* s) 
{
    int a = 0, b = 0, c = 0;
    int i;
    
    Stack st;
    st.sets = calloc(strlen(s), sizeof(char));
    st.top = 0;
    st.len = strlen(s);
    
    for(i = 0; s[i] != '\0'; i++)
    {
        switch( s[i] )
	    {
	        case '(':
	        case '[':
	        case '{':
	            if(push(&st, s[i]) < 0) return 0;
	            break;
	        case ')':
	            if(pop(&st) != '(')  return 0;
	            break;
	        case ']':
	            if(pop(&st) != '[')  return 0;
	            break;
	        case '}':
	            if(pop(&st) != '{')  return 0;
	            break;    
	        default:    
	            return 0;
	    }    
    }
    return st.top == 0;
}

int main()
{
	char str[] = "(([{(){}}]))";

	printf("%s is %s Parentheses String\n", str, isValid(str)?"valid":"invalid");
}
