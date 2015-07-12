/*****************************************************
Given a string, find the length of the longest substring without 
repeating characters. 

For example, the longest substring without repeating letters 
for "abcabcbb" is "abc", which the length is 3. 

For "bbbbb" the longest substring is "b", with the length of 1.
*******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void resethash(char *left, char *right, int *hash, char *src)
{
    int i;
    for(i = 0; i < 128; i++)
    {
        hash[i] = -1;
    }
    while(left < right)
    {
        hash[*left] = left - src;
        left++;
    }
}

int lengthOfLongestSubstring(char* s) 
{
    int hash[128] = {};
    char *left, *right;
    int i, j;
    int res = 0;

    for(i = 0; i < 128; i++)
    {
        hash[i] = -1;
    }
    for(left = right = s, i = 0; s[i] != '\0'; i++, right++)
    {
        if(hash[*right] != -1)
        {
            if(res < right - left)
            {
                res = right - left;
            }
            
            j = hash[*right];
            left = s + j + 1;
            resethash(left, right, hash, s);
        }
        hash[*right] = i;
    }
    if(res < right - left)
    {
        res = right - left;
    }
    return res;
}

int lengthOfLongestSubstring2(char* s) 
{
    int hash[128] = {};
    char *left, *right;
    int i, j;
    int res = 0;

    for(i = 0; i < 128; i++)
    {
        hash[i] = -1;
    }
    for(left = right = s, i = 0; s[i] != '\0'; i++, right++)
    {
        if(hash[*right] >= left-s)
        {
            left = hash[*right] + 1 + s;
        }
        if(res < right - left + 1)
        {
            res = right - left + 1;
        }
        hash[*right] = i;
    }
    return res;
}

int main(int argc, char **argv)
{
	char *str = argv[1];
	int res;

	res = lengthOfLongestSubstring2(str);
	printf("res is %d\n", res);
}
