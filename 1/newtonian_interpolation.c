#include <stdio.h>

double newtonInterpolation(int N, double x[], double fx[], double xs);

int main(void) {
    int N;
    printf("input N:");
    scanf("%d" , &N);

    double x[N], fx[N];
    printf("input x (space delimited)\n");
    for (int i=0; i < N; i++) {
        scanf("%lf", &x[i]);
    }
    printf("input fx (space delimited)\n");
    for (int i=0; i < N; i++) {
        scanf("%lf", &fx[i]);
    }

    double xs;
    printf("input xs:");
    scanf("%lf" , &xs);

    double ans = newtonInterpolation(N, x, fx, xs);
    printf("f(%lf) = %lf\n", xs, ans);
    return 0;
}

double newtonInterpolation(int N, double x[], double fx[], double xs) {
    double h = x[1] - x[0];
    double s = (xs - x[0]) / h;
    double deltas_x[N-1];
    double deltas[N];
    for (int i=0; i <= N; i++) {
        deltas[i] = fx[i];
    }
    double new_deltas[N-1];
    for (int i=N; i > 0; i--) {
        for (int j = 0; j < i-1; j++) {
            new_deltas[j] = deltas[j+1] - deltas[j];
        }
        deltas_x[N-i] = new_deltas[0]; 
        for (int j = 0; j < i-1; j++) {
            deltas[j] = new_deltas[j];
        }
    }
    double ans = fx[0];
    double coeff = s;
    for (int i=0; i < N-1; i++) {
        ans += coeff * deltas_x[i];
        printf("%lf %lf %lf\n", deltas_x[i], ans, coeff);
        coeff *= (s-i-1)/(i+2);
    }
    return ans;
}
