#include <stdio.h>
#include <math.h>

#define Y_LENGTH 2
#define X_LENGTH 2
#define N 10
#define l 4.0
#define g 9.80665
#define phi 1.02332670795
#define GNUPLOT_PATH "/mnt/c/Program Files/gnuplot/bin/wgnuplot.exe"

double omega;

int main(void) {
	FILE *gp;
    omega = sqrt(g/l);

	if ((gp = popen(GNUPLOT_PATH, "w")) == NULL) {
		fprintf(stderr,"gnuplot is not found.");
		return 1;
    }
    fprintf(gp, "plot sin(x)\n");
    pclose(gp);
}