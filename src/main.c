#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./qsolve/qsolve.h"
#include "./IO/Input.h"

#define MAX_SIZE 40  

int main()
{
    float a,b,c; // ax^2 + bx + c
    float x1,x2; // the two real roots of a quadratic equation 
    char *input = malloc(3*MAX_SIZE);
    char sa[MAX_SIZE], sb[MAX_SIZE], sc[MAX_SIZE]; // string inputs of a,b,c
    char err[MAX_SIZE];
    int ret; 	  // whatever qsolve(a,b,c,&x1,&x2) returns
    int x,y,z,i;

    printf("Quadratic Solver <qsolve.c> V1.3\nContributors: Alan Alvarez,\tSamuel Kison,\tOmar Santana\n");

    printf("\nPlease enter the values for a, b, and c for a given quadratic equation following this format:\na*x^2 + b*x + c\n");

    //scanf("%f %f %f", &a, &b, &c);

    fgets(input, 3*MAX_SIZE, stdin);
    printf("%s", input);

    for (i=0; i<strlen(input); i++){
        if(input[i] == ' ' && i !=0 && i!=strlen(input)){
            if(x==0)
                x=i;
            else if(y==0 && i-1 > x)
                y=i;
            else   
                z=1;
        }    
    }

    if(x!=0 && y!=0 && z!=1) {
        int scanfret = sscanf(input,"%s %s %s", sa, sb, sc);
        if(scanfret == 3 && Input(sa)>0 && Input(sb)>=0 && Input(sc)>=0){
            printf("The numbers are valid...");
            char *err;
            a = strtof(sa, &err); //err == 0 if ok
            b = strtof(sb, &err); //err == 0 if ok
            c = strtof(sc, &err); //err == 0 if ok

            printf("%f %f %f\n", a, b, c);
        }

        ret = qsolve(a,b,c,&x1,&x2);

        if (ret==3.0 || ret==2.0)
            printf("qsolve has returned: %d meaning that there are no roots to show here because roots are complex roots or the polynomial is linear.\n", ret);
        else
            printf("qsolve has returned: %d meaning that the roots were found.\nx1 is : %f\nx2 is: %f\n", ret, x1, x2);

    }
    else { // too many variables in input!
        printf("incorrect input format, please try again.\n");
    }
    


    return  0;
}
