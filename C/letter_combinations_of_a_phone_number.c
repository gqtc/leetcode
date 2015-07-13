/*****************************************************
Given a digit string, return all possible letter combinations that the 
number could represent.

A mapping of digit to letters (just like on the telephone buttons) is 
given below.

0:" ", 					2:"abc",
3:"def", 		4:"ghi", 		5:"jkl",
6:"mno", 	7:"pqrs", 	8:"tuv",	
9:"wxyz"

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

*******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void getres(char *digits, char *str, int j, char **resset, char **dset)
{
	int dig = -1;

	if(j >= strlen(digits))
	{
		char *res = calloc(strlen(str)+1, sizeof(char));
		int k = 0;
		memcpy(res, str, strlen(str));
		while(resset[k] != NULL)k++;
		resset[k] = res;
		return;
	}
	
	dig = digits[j] - '0';

	int k = 0;
	while(k < strlen(dset[dig]))
	{
		str[j] = dset[dig][k];
		getres(digits, str, j+1, resset, dset);
		k++;
	}	
}	


char** letterCombinations(char* digits, int* returnSize) 
{
    int i;
    int totallen = 1;
    int dig;
    
    char* dset[] = {
	    " ", "", "abc",
	    "def", "ghi", "jkl",
	    "mno", "pqrs", "tuv",	
	    "wxyz"
    };
    
    for(i = 0; i < strlen(digits); i++)
    {
    	dig = digits[i] - '0';
		totallen *= strlen(dset[dig]);
    }

    if(totallen == 1)
    {
        *returnSize = 0;
        return NULL;
    }
    *returnSize = totallen;
    
    int resindex = 0;

    char **res = calloc(totallen, sizeof(char *));

	char *str = calloc(strlen(digits)+1, sizeof(char));
	getres(digits, str, 0, res, dset);

	free(str);
    return res;
}


int main(int argc, char **argv)
{
	char **res;
	int reslen;
	int i;

	char digits[] = "2457";
	res = letterCombinations(digits, &reslen);

	for(i = 0; i < reslen; i++)
	{
		printf("%s\n", res[i]);
		free(res[i]);
	}
	free(res);
}

