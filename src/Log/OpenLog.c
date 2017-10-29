/*
Input: a string containing the filepath of the .log file, and an int to specify which mode
to write in (0 for append, 1 for overwrite)

Output: a file pointer to the file specified by 'filepath', or null if error

Note: Log can be written to in append mode or in overwrite mode. Regardless of which is chosen, it is important to write a date & version number to the file!
*/
#include <stdio.h>

FILE* OpenLog(char* filepath, int mode)
{
	FILE* fp = NULL;

	if (mode == 0)
	{
		//Open file for writing in append mode
		fp = fopen(filepath, "a");
	}
	else if (mode == 1)
	{
		//Open file for writing in overwrite mode
		fp = fopen(filepath, "w");
	}
	
	//Check for valid
	if(fp) {return fp;}
	else{ return NULL;}
}
