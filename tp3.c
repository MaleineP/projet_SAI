#include "tp3.h"

/*
			Changement d'échelle

	matrice_plan S;
	S.p= malloc(3*sizeof(int*));
	for(int i=0; i<3; i++){
		S.p[i] = malloc(3*sizeof(int));
	}
	for(int i =0; i<3; i++)
		for(int j=0; j<3; j++)
			S.p[i][j] = 0;
	S.p[0][0] = 2;
	S.p[1][1] = 3;
	S.p[2][2] = 1;

	A1 = multP(S, A);
	B1 = multP(S, B);
	C1 = multP(S, C);
	D1 = multP(S, D);

			Rotation

	matrice_plan R;
	matrice_plan tmp;
	R.p= malloc(3*sizeof(int*));
	tmp.p = malloc(3*sizeof(int*));
	for(int i=0; i<3; i++){
		R.p[i] = malloc(3*sizeof(int));
		tmp.p[i] = malloc(3*sizeof(int));
	}
	for(int i =0; i<3; i++)
		for(int j=0; j<3; j++){
			R.p[i][j] = 0;
			tmp.p[i][j] = 0;
		}
	tmp.p[0][0] = 1;
	tmp.p[1][1] = 1;
	tmp.p[0][2] = 2;
	tmp.p[1][2] = 1;
	tmp.p[2][2] = 1;

	R.p[0][0] = cos(PI/3);
	R.p[0][1] = -sin(PI/3);
	R.p[1][0] = sin(PI/3);
	R.p[1][1] = cos(PI/3);
	R.p[2][2] = 1;

	R = multM(multM(tmp, R), tmp);

	A2 = multP(R, A);
	B2 = multP(R, B);
	C2 = multP(R, C);
	D2 = multP(R, D);

			Translation

	matrice_plan T;
	T.p= malloc(3*sizeof(int*));
	for(int i=0; i<3; i++){
		T.p[i] = malloc(3*sizeof(int));
	}
	for(int i =0; i<3; i++)
		for(int j=0; j<3; j++)
			T.p[i][j] = 0;
	T.p[0][0] = 1;
	T.p[0][2] = -3;
	T.p[1][1] = 1;
	T.p[1][2] = -1;
	T.p[2][2] = 1;

	A3 = multP(R, A);
	B3 = multP(R, B);
	C3 = multP(R, C);
	D3 = multP(R, D);
*/

matrice_plan multM(matrice_plan m1, matrice_plan m2){
    int i;
    matrice_plan res;
    res.p = malloc(3*sizeof(int*));
    for(i=0; i<3; i++){
        res.p[i] = malloc(3*sizeof(int));
    }
    res.p[0][0] = m1.p[0][0]*m2.p[0][0]+m1.p[0][1]*m2.p[1][0]+m1.p[0][2]*m2.p[2][0];
    res.p[0][1] = m1.p[0][0]*m2.p[0][1]+m1.p[0][1]*m2.p[1][1]+m1.p[0][2]*m2.p[2][1];
    res.p[0][2] = m1.p[0][0]*m2.p[0][2]+m1.p[0][1]*m2.p[1][2]+m1.p[0][2]*m2.p[2][2];
    res.p[1][0] = m1.p[1][0]*m2.p[0][0]+m1.p[1][1]*m2.p[1][0]+m1.p[1][2]*m2.p[2][0];
    res.p[1][1] = m1.p[1][0]*m2.p[0][1]+m1.p[1][1]*m2.p[1][1]+m1.p[1][2]*m2.p[2][1];
    res.p[1][2] = m1.p[1][0]*m2.p[0][2]+m1.p[1][1]*m2.p[1][2]+m1.p[1][2]*m2.p[2][2];
    res.p[2][0] = m1.p[2][0]*m2.p[0][0]+m1.p[2][1]*m2.p[1][0]+m1.p[2][2]*m2.p[2][0];
    res.p[2][1] = m1.p[2][0]*m2.p[0][1]+m1.p[2][1]*m2.p[1][1]+m1.p[2][2]*m2.p[2][1];
    res.p[2][2] = m1.p[2][0]*m2.p[0][2]+m1.p[2][1]*m2.p[1][2]+m1.p[2][2]*m2.p[2][2];
    return res;
}

point multP(matrice_plan m, point p){
	int i;
	point ret;
    ret.x = m.p[0][0]*p.x + m.p[0][1]*p.y + m.p[0][2]*p.z;
    ret.y = m.p[1][0]*p.x + m.p[1][1]*p.y + m.p[1][2]*p.z;
    ret.z = m.p[2][0]*p.x + m.p[2][1]*p.y + m.p[2][2]*p.z;
    return ret;
}

