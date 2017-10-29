/*
Input: a filepointer to the log file

Output: 0 on success, -1 on failure
*/
#include <stdio.h>

int CloseLog(FILE* fp)
{
	if (fp != NULL)
    	{
		fclose(fp);
		return 0;
	}
    	else
    	{
    		return -1;
    	}
}
