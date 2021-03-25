#include <stdio.h>
#include <math.h>

double trapezium(int len, double h, double fx[]);

int main(void) {
    int num;
    int nums[] = {2,6,12};
    double range_start = 0;
    double range_end   = M_PI/2;
    double range = range_end-range_start;
    double h;
    double ans;

    for(int i=0; i < sizeof nums/ sizeof nums[0]; i++) {
        num = nums[i];
        h = range/num;
        double x[num], fx[num];
        for(int j=0; j <= num; j++) {
            x[j] = range_start + j*h;
            fx[j] = sin(x[j]);
            printf("x:%lf, fx:%lf\n", x[j], fx[j]);
        }
        printf("x[0] = %lf\n", x[0]);
        double ans = trapezium(num, h, fx);
        printf("n=%d: %lf\n", num,  ans);
    }
    return 0;
}

double trapezium(int len, double h, double fx[]) {
    double ans = 0;
    for(int i = 1; i <= len ; i++) {
        ans += h/2*(fx[i-1] + fx[i]);
    }
    return ans;
}