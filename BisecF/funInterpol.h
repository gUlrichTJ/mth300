#ifndef FUNINTERPOL_H_INCLUDED
#define FUNINTERPOL_H_INCLUDED

void scan_int_point(mat *X,int n);
void Li(int i,mat *X);
void Ni(int i,mat *X);
double di(int k,int n,mat *X,mat *Y);
void interp_langr(mat *X,mat *Y);
void interp_newton(mat *X,mat *Y);
void reconvert_mat(mat *A);
void convert_tableau(mat *A,mat *B);
void reconvert_colonne(mat *B);
void inter_moindre_carre(mat *X,mat *Y,int p);

#endif // FUNINTERPOL_H_INCLUDED
