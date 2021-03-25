#include <stdio.h>
#include <math.h>

#define Y_LENGTH 2
#define X_LENGTH 2
#define N 10
#define l 4.0
#define g 9.80665
#define phi 1.02332670795

double omega;

int main(void) {
    omega = sqrt(g/l);
}