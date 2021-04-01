#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define DATA_NUM 9
#define DEVIDE_NUM 36
#define FILE_NAME_TEMPLATE "data/joukowski_%d.txt"
#define a 1

double xi_0s[DATA_NUM] = {0,0,0,-0.1,-0.2,-0.3,-0.1,-0.1,-0.1};
double eta_0s[DATA_NUM] = {0.1,0.2,0.3,0,0,0,0.1,0.2,0.3};
char command[500];
char file_name[100];

int main(void) {
    double x;
    double y;
    double theta;
    double xi;
    double xi_0;
    double eta;
    double eta_0;
    double r;
    for (int i = 0; i < DATA_NUM; i++) {
        xi_0 = xi_0s[i];
        eta_0 = eta_0s[i];
        r = sqrt(pow((a-xi_0),2.0)+eta_0*eta_0);
        sprintf(file_name, FILE_NAME_TEMPLATE, (i+1));
        sprintf(command, "rm %s ; touch %s", file_name, file_name);
        system(command);
        for (int j = 0; j < DEVIDE_NUM; j++) {
            theta = 2*M_PI/DEVIDE_NUM*j;
            xi = xi_0 + r*cos(theta);
            eta = eta_0 + r*sin(theta);
            x = xi*(1+a*a/(xi*xi+eta*eta));
            y = eta*(1-a*a/(xi*xi+eta*eta));
            sprintf(command, "echo '%lf %lf ' >> %s", x, y, file_name);
            system(command);
        }
    }
    
    return 0;
}