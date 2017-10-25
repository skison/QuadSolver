#include <stdio.h>
#include "qsolve.h"

int main()
{
    float a,b,c; // ax^2 + bx + c
    float x1,x2; // the two real roots of a quadratic equation 
    int ret; 	  // whatever qsolve(a,b,c,&x1,&x2) returns

    printf("Quadratic Solver <qsolve.c> V1.0\nContributors: Alan Alvarez,\tSamuel Kison,\tOmar Santana\n");

    printf("Please enter the values for a, b, and c for a given quadratic equation following this format:\n a*x^2 + b*x + c\n");
    scanf("%f", &a);
    scanf("%f", &b);
    scanf("%f", &c);

    ret = qsolve(a,b,c,&x1,&x2);

    if (ret==3.0 || ret==2.0)
    	printf("qsolve has returned: %d\nNo roots to show here, either complex roots or a=0\n", ret);
    else
    	printf("qsolve has returned: %d\nThe roots x1 and x2 are: %f   and %f\n", ret, x1, x2);

    return 0;
}