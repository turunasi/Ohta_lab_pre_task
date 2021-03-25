#include <stdio.h>
#include <math.h>

#define NUMS_NUM 3
#define FUNCS_NUM 2
#define FUNCS_SHIMP_NUM 2

double shimpson13(int len, double h, double fx[]);
double shimpson38(int len, double h, double fx[]);
double function1(double x);

int main(void) {
    int num;
    int nums[NUMS_NUM];
    int nums_13[NUMS_NUM] = {2,4,6};
    int nums_38[NUMS_NUM] = {3,6,9};
    double range_start = 0;
    double range_end = 1;
    double range = range_end - range_start;
    double h;
    double ans;
    char shimp_labels[FUNCS_SHIMP_NUM][64] = {"shimpson13", "shimpson38"};

    for(int j=0; j < FUNCS_SHIMP_NUM ; j++){
        for (int k=0; k < NUMS_NUM; k++) {
            nums[k] = j == 0 ? nums_13[k] : nums_38[k];
        }
        for(int k=0; k < NUMS_NUM; k++) {
            num = nums[k];
            double fx[num+1];
            h = range/num;
            for(int l=0; l <= num; l++) {
                fx[l] = function1(range_start+l*h);
            }
            ans = j == 0 ? shimpson13(num, h, fx) : shimpson38(num, h, fx);
            printf("1/(x+1), %s, num=%d: %lf\n", shimp_labels[j], num,  ans);
        }
    }
    return 0;
}

double shimpson13(int len, double h, double fx[]) {
    double ans = 0;
    double val;
    for(int i = 0; i <= len ; i++) {
        if (i == 0 || i == len) {
            val =  fx[i];
        } else if (i%2 == 0) {
            val = 2.0*fx[i];
        } else {
            val = 4.0*fx[i];
        }
        ans += h/3*val;
    }
    return ans;
}

double shimpson38(int len, double h, double fx[]) {
    double ans = 0;
    double val;
    for(int i = 0; i <= len ; i++) {
        if (i == 0 || i == len) {
            val = fx[i];
        } else if (i%3 == 0) {
            val = 2.0*fx[i];
        } else {
            val = 3.0*fx[i];
        }
        ans += h*3/8*val;
    }
    return ans;
}

double function1(double x) {
    return 1/(x+1);
}