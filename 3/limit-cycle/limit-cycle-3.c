#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define X_LENGTH 2
#define Y_LENGTH 2
#define h 0.1
#define INIT_NUM 16
#define LOOP_NUM 100
#define FILE_NAME "limit-cycle-3.txt"

void rungeKutta(double x_p, double y_p, double *x_n, double *y_n);
double x_func(double x, double y);
double y_func(double x, double y);

double x;
double y;
double x_n;
double y_n;
double coeff;
char command[100];

int main(void) {
    sprintf(command, "rm %s ; touch %s", FILE_NAME, FILE_NAME);
    system(command);
    for (int i = 0; i < INIT_NUM; i++) {
        coeff = (i < 8) ? 1.021 : 0.3;
        x = coeff*cos(M_PI/4*i);
        y = coeff*sin(M_PI/4*i);
        x_n = 0;
        y_n = 0;
        for (int j = 0; j < LOOP_NUM; j++) {
            sprintf(command, "echo '%lf %lf' >> %s", x, y, FILE_NAME);
            system(command);
            rungeKutta(x,y,&x_n,&y_n);
            if (isnan(x_n) || isnan(y_n)) break;
            if (isinf(x_n) || isinf(y_n)) break;
            x = x_n;
            y = y_n;
        }
        sprintf(command, "echo '' >> %s", FILE_NAME);
        system(command);
    }
    return 0;
}

void rungeKutta(double x_p, double y_p, double *x_n, double *y_n) {
    double k_x_1 = h*x_func(x,y);
    double k_y_1 = h*y_func(x,y);
    double k_x_2 = h*x_func(x+k_x_1/2,y+k_y_1/2);
    double k_y_2 = h*y_func(x+k_x_1/2,y+k_y_1/2);
    double k_x_3 = h*x_func(x+k_x_2/2,y+k_y_2/2);
    double k_y_3 = h*y_func(x+k_x_2/2,y+k_y_2/2);
    double k_x_4 = h*x_func(x+k_x_3,y+k_y_3);
    double k_y_4 = h*y_func(x+k_x_3,y+k_y_3);
    (*x_n) = x_p + (k_x_1+2*k_x_2+2*k_x_3+k_x_4)/6;
    (*y_n) = y_p + (k_y_1+2*k_y_2+2*k_y_3+k_y_4)/6;
}

double x_func(double x, double y) {
    return y+x*sqrt(x*x+y*y)*pow((x*x+y*y-1), 2.0);
}

double y_func(double x, double y) {
    return -x+y*sqrt(x*x+y*y)*pow((x*x+y*y-1), 2.0);
}