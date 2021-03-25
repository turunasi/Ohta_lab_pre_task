// 動かなさそうなので廃棄

#include <stdio.h>
#include <math.h>

#define NUMS_NUM 3
#define FUNCS_NUM 2
#define FUNCS_SHIMP_NUM 2

double shimpson13(int len, double h, double fx[]);
double shimpson38(int len, double h, double fx[]);
double function1(double x);
double function2(double x);

int main(void) {
    int num;
    int nums[NUMS_NUM];
    int nums_13[NUMS_NUM] = {2,4,6};
    int nums_38[NUMS_NUM] = {3,6,9};
    double range_start[FUNCS_NUM] = {0, 0};
    double range_end[FUNCS_NUM] = {0, M_PI};
    double (*func)(double);
    double funcs[FUNCS_NUM][64] = {function1, function2};
    char funcs_labels[FUNCS_NUM][64] = {'1/(x+1)', 'SQRT((1+cos(x))/2)'};
    double (*func_shimp)(int, double, double[]);
    char funcs_shimp[FUNCS_SHIMP_NUM][64] = {shimpson13, shimpson38};
    double range;
    double h;
    double ans;

    for(int i=0; i < FUNCS_NUM; i++) {
        range = range_end[i] - range_start[i];
        func = funcs[i];
        for(int j=0; j < FUNCS_SHIMP_NUM ; j++){
            func_shimp = funcs_shimp[j];
            for (int k=0; k < NUMS_NUM; k++) {
                nums[k] = j == 0 ? nums_13[k] : nums_38[k];
            }
            for(int k=0; k < NUMS_NUM; k++) {
                num = nums[k];
                double fx[num+1];
                h = range/num;
                for(int l=0; l <= num; l++) {
                    fx[l] = func(range_start[i]+l*h);
                }
                ans = func_shimp(num, h, fx);
                printf("%s, %s, num=%d: %lf\n", funcs_labels[i], funcs_shimp[j], num,  ans);
            }
        }
    }
    return 0;
}

double shimpson13(int len, double h, double fx[]) {
    double ans = 0;
    double val;
    for(int i = 0; i <= len ; i++) {
        if (i == 0 || i == len) {
            val = fx[i];
        } else if (i%2 == 0) {
            val = 2*fx[i];
        } else {
            val = 4*fx[i];
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
            val = 2*fx[i];
        } else {
            val = 3*fx[i];
        }
        ans += h*8/3*val;
    }
    return ans;
}

double function1(double x) {
    return 1/(x+1);
}

double function2(double x) {
    return pow((1+cos(x))/2,1/2);
}