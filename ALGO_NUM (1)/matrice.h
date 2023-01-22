#ifndef MATRICE_H_INCLUDED
#define MATRICE_H_INCLUDED

/*void saisir_matrice(double *T ,int l,lignes,int c);
void afficher_matrice(double *MAT, int l,int c);
void permuter(double *A,int l1,int l2,int l,int c);*/

float * * malloc2 ( int rows , int cols ) ;
void saisie_mat(float **A ,int n) ;
void saisie_vect(float *b ,int n) ;
void affich_systeme(float **A ,float *b ,int n) ;
void gauss(float **A, float *b, float *x, int n) ;
void affich_sol(float *x, int n) ;
void gauss_jordan(float **A, float *b, float *x, int n);
void LU(float **A, float *b, /*float *x,*/ int n);
void lu();
void cholesky();
void int_lagr();
void int_lagr2();;
void newton();
void jacobie(float a[19][19],float b[19],int n);
float norme(float x[19],int n);
void gauss_seidel(float a[19][19],float b[19],int n);
void cholesky(float a[19][19],float b[19],int n);
void afficher_matrice(float A[100][100], int n);
void LU_crout(float a[19][19],float b[19],int n);
#endif // MATRICE_H_INCLUDED
