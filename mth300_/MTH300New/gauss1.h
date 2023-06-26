#ifndef GAUSS1_H_INCLUDED
#define GAUSS1_H_INCLUDED

#ifndef GAUSS
#define GAUSS
int diagonaliser(float M[],float T[] ,int L);
void remontee(float M[],float T[],float result[], int L);
void gauss(float M[],float T[],float result[], int L, int N);
#endif // GAUSS

#endif // GAUSS1_H_INCLUDED
