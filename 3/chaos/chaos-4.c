#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define X_0 0
#define Y_0 0
#define Z_0 0.5
#define a_1 -1.164
#define a_2 -0.827824
#define a_3 -1.306011
#define c_1 1.2482
#define c_2 -8.532633
#define c_3 16.98886
#define h 0.01
#define LOOP_NUM 10000
#define FILE_NAME "chaos-4.txt"

void rungeKutta(double x_p, double y_p, double z_p, double *x_n, double *y_n, double *z_n);
double x_func(double x, double y, double z);
double y_func(double x, double y, double z);
double z_func(double x, double y, double z);

double x;
double y;
double z;
double x_n;
double y_n;
double z_n;
char command[100];

int main(void) {
    sprintf(command, "rm %s ; touch %s", FILE_NAME, FILE_NAME);
    system(command);
        x = X_0;
        y = Y_0;
        z = Z_0;
        x_n = 0;
        y_n = 0;
        z_n = 0;
        for (int i = 0; i < LOOP_NUM; i++) {
            sprintf(command, "echo '%lf %lf %lf' >> %s", x, y, z, FILE_NAME);
            system(command);
            rungeKutta(x,y,z,&x_n,&y_n,&z_n);
            if (isnan(x_n) || isnan(y_n) || isnan(z_n)) break;
            if (isinf(x_n) || isinf(y_n) || isinf(z_n)) break;
            x = x_n;
            y = y_n;
            z = z_n;
        }
    return 0;
}

void rungeKutta(double x_p, double y_p, double z_p, double *x_n, double *y_n, double *z_n) {
    double k_x_1 = h*x_func(x,y,z);
    double k_y_1 = h*y_func(x,y,z);
    double k_z_1 = h*z_func(x,y,z);
    double k_x_2 = h*x_func(x+k_x_1/2,y+k_y_1/2,z+k_z_1/2);
    double k_y_2 = h*y_func(x+k_x_1/2,y+k_y_1/2,z+k_z_1/2);
    double k_z_2 = h*z_func(x+k_x_1/2,y+k_y_1/2,z+k_z_1/2);
    double k_x_3 = h*x_func(x+k_x_2/2,y+k_y_2/2,z+k_z_2/2);
    double k_y_3 = h*y_func(x+k_x_2/2,y+k_y_2/2,z+k_z_2/2);
    double k_z_3 = h*z_func(x+k_x_2/2,y+k_y_2/2,z+k_z_2/2);
    double k_x_4 = h*x_func(x+k_x_3,y+k_y_3,z+k_z_3);
    double k_y_4 = h*y_func(x+k_x_3,y+k_y_3,z+k_z_3);
    double k_z_4 = h*z_func(x+k_x_3,y+k_y_3,z+k_z_3);
    (*x_n) = x_p + (k_x_1+2*k_x_2+2*k_x_3+k_x_4)/6;
    (*y_n) = y_p + (k_y_1+2*k_y_2+2*k_y_3+k_y_4)/6;
    (*z_n) = z_p + (k_z_1+2*k_z_2+2*k_z_3+k_z_4)/6;
}

double x_func(double x, double y, double z) {
    return c_1*x+y+c_1*(abs(x-1)-abs(x+1))/2;
}

double y_func(double x, double y, double z) {
    return c_2*x+z+c_2*(abs(x-1)-abs(x+1))/2;
}

double z_func(double x, double y, double z) {
    return (c_3+a_3)*x+a_2*y+a_1*z+c_3*(abs(x-1)-abs(x+1))/2;
}
