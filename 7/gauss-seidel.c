#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

#define DELTA_X 0.2
#define DELTA_Y DELTA_X
#define X_LENGTH 15
#define Y_LENGTH 5
#define LIMIT_NUM 0.001
#define B_X X_LENGTH/3
#define E_X X_LENGTH*2/3
#define F_X X_LENGTH
#define C_Y Y_LENGTH/2
#define H_Y Y_LENGTH
#define Y_NUM (int)H_Y/DELTA_Y + 1
#define X_NUM (int)F_X/DELTA_X + 1
#define FILE_NAME "gauss-seidel.txt"

int x_num = (int)X_NUM;
int y_num = (int)Y_NUM;
double x;
double y;
char command[500];

bool process_meshes(double meshes[x_num][y_num], double new_meshes[x_num][y_num]);
void init_meshes(double meshes[x_num][y_num]);
double get_psy(int i, int j, double meshes[x_num][y_num], double new_meshes[x_num][y_num]);
double init_psy(int i, int j);

int main(void) {
    double meshes[x_num][y_num];
    double new_meshes[x_num][y_num];
    bool result = true;
    double max = 0;
    int c = 0;
    sprintf(command, "echo '' > %s", FILE_NAME);
    system(command);
    for (int i = 0; i < X_NUM; i++) {
        x = DELTA_X*i;
        for (int j = 0; j < Y_NUM; j++) {
            y = DELTA_Y*j;
            meshes[i][j] = init_psy(i,j);
        }
    }
    while (result) {
        max = 0;
        for (int i = 0; i < X_NUM; i++) {
            x = DELTA_X*i;
            for (int j = 0; j < Y_NUM; j++) {
                y = DELTA_Y*j;
                new_meshes[i][j] = get_psy(i,j,meshes,new_meshes);
                if (fabs(new_meshes[i][j]-meshes[i][j]) != 0.0000) {
                    max = (fabs(new_meshes[i][j]-meshes[i][j]) > max) ? fabs(new_meshes[i][j]-meshes[i][j]) : max;
                }
            }
        }
        result = max > LIMIT_NUM;
        for (int i = 0; i < X_NUM; i++) {
            x = DELTA_X*i;
            for (int j = 0; j < Y_NUM; j++) {
                y = DELTA_Y*j;
                meshes[i][j] = new_meshes[i][j];
            }
        }
        c++;
        if (c%100 == 0) {
            printf("count:%d max:%lf\n", c, max);
        } 
    }
    for (int i = 0; i < X_NUM; i++) {
        x = DELTA_X*i;
        for (int j = 0; j < Y_NUM; j++) {
            y = DELTA_Y*j;
            sprintf(command, "echo '%lf %lf %lf' >> %s", x, y, new_meshes[i][j], FILE_NAME);
            system(command);
        }
        sprintf(command, "echo '' >> %s", FILE_NAME);
        system(command);
    }
    return 0;
}

double init_psy(int i, int j) {
    if (j == 0) return 0; 
    if (j == Y_NUM-1) return H_Y/DELTA_Y; 
    if (B_X/DELTA_X <= i && i <= E_X/DELTA_X) {
        if (j <= C_Y/DELTA_Y) return 0;
    }
    if (i == 0 || i == X_NUM-1) {
        for (int k = 1; k <= Y_NUM; k++) {
            if (j == k) return k;
        }
    }
    return 0;
}

double get_psy(int i, int j, double meshes[x_num][y_num], double new_meshes[x_num][y_num]) {
    if (j == 0) return 0; 
    if (j == Y_NUM-1) return H_Y/DELTA_Y; 
    if (B_X/DELTA_X <= i && i <= E_X/DELTA_X) {
        if (j <= C_Y/DELTA_Y) return 0;
    }
    if (i == 0 || i == X_NUM-1) {
        for (int k = 1; k <= Y_NUM; k++) {
            if (j == k) return k;
        }
    }
    return (meshes[i+1][j]+new_meshes[i-1][j]+meshes[i][j+1]+new_meshes[i][j-1])/4;
}