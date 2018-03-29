#include "tp1.h"

#define PI 3.14

typedef struct{
    float x;
    float y;
    float z;
}point;

typedef struct{
    int **p;
}matrice_plan;

matrice_plan multM(matrice_plan m1, matrice_plan m2);
point multP(matrice_plan m, point p);
