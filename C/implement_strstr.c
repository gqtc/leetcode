/*****************************************************
Implement strStr().

Returns the index of the first occurrence of needle in haystack, 
or -1 if needle is not part of haystack.

*******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strStr(char* haystack, char* needle) 
{
    int hlen = strlen(haystack);
    int nlen = strlen(needle);
    
    int i, j, k;
    
    for(i = 0; i <= hlen-nlen; i++)
    {
        j = i;
        k = 0;
        
        while(k < nlen && haystack[j++] == needle[k])k++;
        if(k == nlen)   return i;
    }
    return -1;
}


int main()
{
	char haystack[] = "abcdefghijklmnopqrstuvwxyz";
	char needle[] = "ijkl";

	int res = strStr(haystack, needle);

	printf("res is %d\n", res);
}

