 /* This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */   

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./qsolve/qsolve.h"
#include "./IO/Input.h"
#include "./Log/OpenLog.h"
#include "./Log/CloseLog.h"
#include "./Log/WriteLog.h"
#define MAX_SIZE 1000  

int main()
{
    FILE* logFile;
    logFile = OpenLog("mainLog.txt", 1);
    printf("Quadratic Solver <qsolve.c>\nContributors: Alan Alvarez,\tSamuel Kison,\tOmar Santana\n");
    int menu = 2;
    while (menu!=0){
        menu = 2;
        float a,b,c; // ax^2 + bx + c
        float x1,x2; // the two real roots of a quadratic equation 
        char *input = malloc(3*MAX_SIZE);
        char sa[MAX_SIZE], sb[MAX_SIZE], sc[MAX_SIZE]; // string inputs of a,b,c
        char logString[3*MAX_SIZE + 100]; // used for logging
        int ret; 	  // whatever qsolve(a,b,c,&x1,&x2) returns
        int x=0;
        int y=0;
        int z=0,i;

        printf("\nPlease enter the values for a, b, and c for a given quadratic equation following this format:\na*x^2 + b*x + c\n");

        //scanf("%f %f %f", &a, &b, &c);

        fgets(input, 3*MAX_SIZE+10, stdin);
        //printf("<%s>", input);

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
            int scanfret = sscanf(input," %s %s %s", sa, sb, sc);
            if(scanfret == 3 && Input(sa)>=0 && Input(sb)>=0 && Input(sc)>=0){
                //printf("The numbers are valid...");
                char *err;
                a = strtof(sa, &err); //err == 0 if ok
                b = strtof(sb, &err); //err == 0 if ok
                c = strtof(sc, &err); //err == 0 if ok

                //printf("%f %f %f\n", a, b, c);
                ret = qsolve(a,b,c,&x1,&x2);
                if (a < (10^(-10)) || a > (10^8) 
                    || b < (10^(-10)) || b > (10^8) 
                    || c < (10^(-10)) || c > (10^8))
                    printf("\n**********\nWarning: qsolve may lose precision due to small or large values.\n**********\n");

                if (ret==3.0 || ret==2.0) {    
                    if (ret==3.0) {
                        strcat(logString,"3\n");
                        //strcat(logString,"a*x^2 + b*x + c: ");
                        //sprintf(logString+100, "0 %f %f", b, c);
                    }
                    else if (ret==2.0) {
                        strcat(logString,"2\n");
                    }    
                    printf("\n\nqsolve has returned: %d meaning that there are no roots to show here because roots are complex roots or the polynomial is linear.\n", ret);
                    WriteLog(logFile, logString);  
                }    
                else { //roots found!
                    if (ret==1.0) {
                        strcat(logString,"1\n");
                        sprintf(logString+3, "%f %f", x1, x2);
                    }
                    else if (ret==0.0) {
                        strcat(logString,"0\n");
                        sprintf(logString+3, "%f %f", x1, x2);
                    }
                    printf("qsolve has returned: %d meaning that the roots were found.\nx1 is : %f\nx2 is: %f\n", ret, x1, x2);
                    WriteLog(logFile, logString);  
                }    
            }
            else { //incorrect input format, too long or inf numbers
                printf("incorrect input format, please try again.\n");
            }

        }
        else { // too many variables in input!
            printf("incorrect input format, please try again.\n");
        }
        logString[0]='\0';
        while(menu != 0 && menu != 1) {
            printf("\nPlease input a command.\n1: run again\t0: exit\n");
            scanf("%d", &menu);
            fgets(input, 3*MAX_SIZE, stdin);
        }    
    }
    CloseLog(logFile);
    return  0;
}