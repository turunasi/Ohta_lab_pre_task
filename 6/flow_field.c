#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define XI_0 -0.2
#define ETA_0 0.2
#define C_NUM 9
#define DEVIDE_NUM 200
#define R_LENGTH 8.0
#define FILE_NAME "flow_field.txt"
#define alpha M_PI/12
#define gamma -10
#define a 1

double get_theta (double r, double c);

char command[500];
char file_name[100];
double c;
double cs[C_NUM] = {-4,-3,-2,-1,0,1,2,3,4};

int main(void) {
    double h = R_LENGTH/DEVIDE_NUM;
    double r;
    double theta;
    double xi;
    double eta;
    double xi_rot;
    double eta_rot;
    double x;
    double y;
    sprintf(command, "rm %s ; touch %s", FILE_NAME, FILE_NAME);
    system(command);
    for (int i = 0; i < C_NUM; i++) {
        c = cs[i];
        for (int j = DEVIDE_NUM; j >= 0; j--) {
            r = h*j;
            if (r < a) continue;
            theta = get_theta(r,c);
            if (isnan(theta)) continue;
            eta = r*cos(theta) - ETA_0;
            xi = r*sin(theta) - XI_0;
            xi_rot = xi*cos(alpha)-eta*sin(alpha);
            eta_rot = xi*sin(alpha)+eta*cos(alpha);
            x = xi_rot*(1+a*a/r/r);
            y = eta_rot*(1-a*a/r/r);
            if (isnan(x) || isnan(y)) continue;
            sprintf(command, "echo '%lf %lf' >> %s", x, y, FILE_NAME);
            system(command);
        }
        for (int j = 0; j < DEVIDE_NUM; j++) {
            r = h*j;
            if (r < a) continue;
            theta = get_theta(r,c);
            if (isnan(theta)) continue;
            eta = r*cos(-theta) - ETA_0;
            xi = r*sin(-theta) - XI_0;
            xi_rot = xi*cos(alpha)-eta*sin(alpha);
            eta_rot = xi*sin(alpha)+eta*cos(alpha);
            x = xi_rot*(1+a*a/r/r);
            y = eta_rot*(1-a*a/r/r);
            if (isnan(x) || isnan(y)) continue;
            sprintf(command, "echo '%lf %lf' >> %s", x, y, FILE_NAME);
            system(command);
        }
        sprintf(command, "echo '' >> %s", FILE_NAME);
        system(command);
    }
    
    r = sqrt(pow((a-XI_0),2.0)+ETA_0*ETA_0);
    for (int j = 0; j < DEVIDE_NUM; j++) {
        theta = 2*M_PI/DEVIDE_NUM*j;
        xi = XI_0 + r*cos(theta);
        eta = ETA_0 + r*sin(theta);
        x = xi*(1+a*a/(xi*xi+eta*eta));
        y = eta*(1-a*a/(xi*xi+eta*eta));
        sprintf(command, "echo '%lf %lf ' >> %s", x, y, FILE_NAME);
        system(command);
    }
    return 0;
}

double get_theta (double r, double c) {
    double theta = acos((c+gamma/(2*M_PI)*log(r))/(r-a*a/r));
    return theta;
}