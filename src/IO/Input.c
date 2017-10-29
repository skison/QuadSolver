/*
Input: a string of any kind

Output:

On positive float: 1
On negative float: 2
On zero: 0
On invalid input: -1
On too long input: -2
*/
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int Input(char* input)
{
	int MAXNUM = 20; //largest input size allowed
	float value = 0;
	int ret = 0;

	if((strlen(input) + 1) > MAXNUM)
	{
		ret = -2;
	}
	else
	{
		char *err;
		//value = atof(input);//will equal 0 on error
		value = strtof(input, &err); //err == 0 if ok
		printf("%s, %f, %c;\n", input, value, *err);

		if(*err != 0)
		{
			ret = -1;
		}
		else if(value == 0)
		{
			ret = 0;
		}
		else if(value > 0)
		{
			ret = 1;
		}
		else//value > 0
		{
			ret = 2;
		}
	}
	
	return ret;
}
