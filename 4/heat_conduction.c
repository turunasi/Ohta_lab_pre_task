#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAX_T 0.2
#define DELTA_T 0.00025
#define DELTA_X 0.025
#define FILE_NAME "heat_conduction.txt"

double get_temperature(double x, double t, double u, double u_l, double u_r);

double r = DELTA_T/DELTA_X/DELTA_X;
double u;
int t_num = MAX_T/DELTA_T;
int x_num = 1.0/DELTA_X;
char command[100];

int main(void) {
    double x;
    double t;
    double temp_temp;
    double u;
    double u_l;
    double u_r;
    double us[x_num];
    double us_n[x_num];
    sprintf(command, "rm %s ; touch %s", FILE_NAME, FILE_NAME);
    system(command);
    
    for (int j = 0; j < t_num; j++) {
        t = DELTA_T*j;
        for (int i = 0; i < x_num; i++) {
            u = us[i] ?: 0;
            u_l = us[i-1] ?: 0;
            u_r = us[i+1] ?: 0;
            x = DELTA_X*i;
            us_n[i] = get_temperature(x,t,u,u_l,u_r);
            sprintf(command, "echo '%lf %lf ' >> %s", x, us_n[i], FILE_NAME);
            system(command);
        }
        for (int i = 0; i < x_num; i++) {
            us[i] = us_n[i];
        }
    }
    return 0;
}

// @todo 引数を可変長にしたい
double get_temperature(double x, double t, double u, double u_l, double u_r) {
    if (x == 0 || x == 1) return 0;
    if (t == 0) {
        if (0 <= x && x <= 0.5) return 2*x;
        else if (0.5 <= x && x <= 1) return 2*(1-x);
        else return 0;
    }
    return u+r*(u_r+u_l-2*u);
}