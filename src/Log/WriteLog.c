/*
Input: a filepointer to the log file, and a string to output

Output: 0 on success, -1 on failure

Note: You MUST include the \n at the end of each line you intend to be printed on its own line!
*/
#include <stdio.h>

int WriteLog(FILE* fp, char* outputText)
{
	if (fp != NULL)
	{
	        fputs(outputText, fp);
        	return 0;
    	}
   	else
    	{
    		return -1;
    	}
}
