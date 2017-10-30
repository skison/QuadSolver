// 	qsolve.c
//
// 	int qsolve(float a, float b, float c, float &x1, float &x2)
// 	input : a*x^2 + b*x + c = 0,  x1 and x2 will be the two possible real roots
// 	output: roots can be	
//			0: correct 2 real roots
//			1: double root
//			2: complex roots
//			3: a=0 as in the equation is not a quadratic equation, just linear

#include <stdio.h>
#include <math.h>
#include "qsolve.h"

int qsolve(float a, float b, float c, float *x1, float *x2) {
	int ret = -1;
	float disc; // discriminant = b^2 - 4*a*c

	if(a==0.0)
	{
		ret=3;
		// my_log("ERROR : 3")
		return ret;
	}
	// log("\n")	

	disc = b*b - 4.0*a*c;
	if(disc < 0.0) // complex root
	{
		ret=2;
		// my_log("ERROR : 2")
		return ret;
	} 
	else if (disc == 0.0) // double root
	{
		*x1 = -b / (2.0*a);
		*x2 = -b / (2.0*a);
		ret=1;
		return ret;
	}
	else // two simple roots
	{
		float sqdisc = sqrt(disc);
		// printf("%f\n", sqdisc); USED for debugging purposes 
		*x1 = (-b + sqdisc) / (2.0*a);
		*x2 = (-b - sqdisc) / (2.0*a);
		ret=0;
		return ret;
	}	
}
