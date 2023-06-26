#ifndef FACTOLU1_H_INCLUDED
#define FACTOLU1_H_INCLUDED

void Crout(float M[], float T[] ,float x[] ,int N);
void Dotlit(float M[], float T[], float x[], int N);
void descenteTriangulaire(float L[], float y[], float B[], int N);
void remonteeTriangulaire (float U[],float y[], float x[], int N);
void Thomas(float M[], float T[], float x[], int N);

#endif // FACTOLU1_H_INCLUDED
