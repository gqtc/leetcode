/*****************************************************
Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
click to show corner cases.

Corner Cases:
Did you consider the case where path = "/../"?

In this case, you should return "/".
Another corner case is the path might contain multiple slashes '/' 
together, such as "/home//foo/".

In this case, you should ignore redundant slashes and return "/home/foo".

*******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* simplifyPath(char* path)
{
	int pathlen = strlen(path);
	char *srcpath = calloc(pathlen+1, sizeof(char));
	memcpy(srcpath, path, pathlen);

	char delimiter[] = "//";
	char *token = NULL;

	char *res = calloc(pathlen+1, sizeof(char));
	int pos = 0;
	res[0] = '/';
	
	token = strtok(srcpath, delimiter);
	while(token != NULL)
	{
		if(strcmp(token, "..") == 0)
		{
			if(pos != 0)
			{
				res[pos] = '\0';
				pos = strrchr(res, '/') - res;
			}
		}
		else if(strcmp(token, ".") != 0)
		{
			sprintf(res+pos+1, "%s/", token);
			pos += strlen(token) + 1;
		}

		token = strtok(NULL, delimiter);
	}
	
	if(pos != 0)	res[pos] = '\0';
	else	res[pos+1] = '\0';

	free(srcpath);
	return res;
}


int main(int argc, char **argv)
{
	char *path = argv[1];
	char *simplepath = NULL;
	simplepath = simplifyPath(path);
	printf("simplepath is %s\n", simplepath);
	free(simplepath);
}

