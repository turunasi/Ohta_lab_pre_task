#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAX_T 0.2
#define DELTA_T 0.00025
#define DELTA_X 0.025
#define N 3
#define FILE_NAME "theoretic_heat_conduction.txt"

double get_temperature(double x, double t);

double u;
int t_num = MAX_T/DELTA_T;
int x_num = 1.0/DELTA_X;
char command[100];

int main(void) {
    double x;
    double t;
    double u;
    sprintf(command, "rm %s ; touch %s", FILE_NAME, FILE_NAME);
    system(command);
    
    for (int j = 0; j < t_num; j++) {
        t = DELTA_T*j;
        for (int i = 0; i < x_num; i++) {
            x = DELTA_X*i;
            u = get_temperature(x,t);
            sprintf(command, "echo '%lf %lf ' >> %s", x, u, FILE_NAME);
            system(command);
        }
    }
    return 0;
}

// @todo 引数を可変長にしたい
double get_temperature(double x, double t) {
    if (x == 0 || x == 1) return 0;
    if (t == 0) {
        if (0 <= x && x <= 0.5) return 2*x;
        else if (0.5 <= x && x <= 1) return 2*(1-x);
        else return 0;
    }
    double ans = 0;
    for (int i = 1; i <= N; i++) {
        ans += sin(i*M_PI/2)*sin(i*M_PI*x)*exp(-i*i*M_PI*M_PI*t)/i/i;
    }
    return 8*ans/M_PI/M_PI;
}