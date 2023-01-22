#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "menu.h"
#include <conio.h>
#include "funSys.h"


//---------------FONCTION------------SCANNER-----------------------------------------------------
void scanner(mat *matr){
    int i,j;
    printf("Entrer la dimension  de votre matrice\n");
    scanf("%d",&matr->m);
    matr->n=matr->m;

    printf("Entrer les elements de votre matrice\n");
for(i=1;i<=matr->m;i++){
    for(j=1;j<=matr->n;j++){
        scanf("%lf",&matr->A[i][j]);
    }
}


}

void scan_vect_colonn(mat *B,mat *matr){
int i;
B->m=matr->m;
 B->n=1;

for(i=1;i<=matr->m;i++){
        scanf("%lf",&B->A[i][B->n]);
}

}
//---------------FONCTION------------SCANNER-----------------------------------------------------
void scanner_syst(mat *matr,mat *B){


 scanner(matr);
 printf("\nEntrer les elements de votre matrice\n");
 scan_vect_colonn(B,matr);
}
//-----------------------------FONCTION----------AFFICHER---------------------------------------------
void afficher(mat *matr){
    int i,j;

for(i=1;i<=matr->m;i++){
    for(j=1;j<=matr->n;j++){
            if(j==1){
            printf("|");
            }
        printf(" %lf ",matr->A[i][j]);
        if(j==matr->n){
            printf("|\n");
        }
    }
}
}
void affich_syst(mat *A,mat *B){
printf("\nA:\n");
afficher(A);
 printf("\nB:\n");
 afficher(B);

}

int element_null(mat *A,int i,int j){
    if(A->A[i][j]==0)
        return 1;
    else
        return 0;
}

void init_ident(mat *L,mat *matr){
    int i,j;

    L->m=matr->m;
    L->n=matr->n;

    for(i=1;i<=L->m;i++){
        for(j=1;j<=L->n;j++){
                if(i==j){
                    L->A[i][j]=1;
                }
                else{
            L->A[i][j]=0;
                }
        }
    }


}


void init_zero(mat *U,mat *matr){
    int i,j;

    U->m=matr->m;
    U->n=matr->n;

    for(i=1;i<=U->m;i++){
        for(j=1;j<=U->n;j++){

            U->A[i][j]=0;

        }
    }


}
void elim_gauss_k(mat *A,mat *B,int k){
    int i,j;
    double l=0;
for(i=k+1;i<=A->m;i++){
    l=A->A[i][k]/A->A[k][k];

    for(j=k;j<=A->n;j++){
        A->A[i][j]=A->A[i][j]-l*A->A[k][j];

    }
B->A[i][1]=B->A[i][1]-l*B->A[k][1];
}

}
void rech_max_partiel(mat *A,int k,double *max,int *imax){
int i,imax1=k;
double max1=A->A[k][k];

for(i=k;i<=A->m;i++){
    if(fabs(A->A[i][k])>max1){
        max1=fabs(A->A[i][k]);
        imax1=i;
    }
}

*max=max1;
*imax=imax1;
}

void recherche_max_total(mat *A,int k,int *imax,int *jmax,double *max){
int i,j,ik=k,jk=k;
double max1=0;

for(i=k;i<=A->m;i++){
    for(j=k;j<=A->n;j++){

        if(fabs(A->A[i][j])>max1){
            max1=fabs(A->A[i][j]);
            ik=i;
            jk=j;
        }
    }
}
*imax=ik;
*jmax=jk;
*max=max1;
}
////--------------------PERMUTATION----MATRICE----COLONNE--K---ET----COLONNE----------M------------------------------------------

void permut_ligne(mat *matr,int k,int m){
    int j;
double perm;
if(k<1 || m<1 || k>matr->m || m>matr->m){
    printf("Desolé l'une des 02 lignes mentionnées n'existe pas sur cet intervalle\n");

}else{

for(j=1;j<=matr->n;j++){
    perm=matr->A[k][j];
    matr->A[k][j]=matr->A[m][j];
    matr->A[m][j]=perm;
}

}
}


////--------------------PERMUTATION----MATRICE----COLONNE--K---ET----COLONNE----------M------------------------------------------

void permut_colonne(mat *matr,int k,int m){
    int i;
double perm;
if(k<1 || m<1 || k>matr->n || m>matr->n){
    printf("Desolé l'une des 02 lignes mentionnées n'existe pas sur cet intervalle\n");

}else{

for(i=1;i<=matr->m;i++){
    perm=matr->A[i][k];
    matr->A[i][k]=matr->A[i][m];
    matr->A[i][m]=perm;
}

}
}
void elim_gauss_k_jordan(mat *A,mat *B,int k){
    int i,j;
    double l;
for(i=1;i<=A->m;i++){

if(i!=k){
        l=A->A[i][k];
    for(j=1;j<=A->n;j++){
        A->A[i][j]=A->A[i][j]-l*A->A[k][j];
    }
B->A[i][1]=B->A[i][1]-l*B->A[k][1];
}

}
}
void div_piv_lign(mat *A,mat *B,int k){
    int j;
    double l=A->A[k][k];
for(j=1;j<=A->n;j++){

    A->A[k][j]=A->A[k][j]/l;
}
B->A[k][1]=B->A[k][1]/l;

}


void res_remonte(mat *U,mat *Y,mat *X ){
    int i,j;
    double s=0;
    init_zero(X,Y);

X->A[U->m][1]=(Y->A[U->m][1])/U->A[U->m][U->m];
for(i=U->m-1;i>=1;i--){
        s=0;
  for(j=i+1;j<=U->n;j++){
    s+=U->A[i][j]*X->A[j][1];
  }
X->A[i][1]=(Y->A[i][1]-s)/U->A[i][i];

}
printf("X:\n");
afficher(X);

}

void res_descente(mat *L,mat *B,mat *Y){
int i,j;
double s=0;

init_zero(Y,B);

Y->A[1][1]=(B->A[1][1])/L->A[1][1];
for(i=2;i<=L->m;i++){
        s=0;
    for(j=1;j<i;j++){
        s+=L->A[i][j]*Y->A[j][1];
    }
         Y->A[i][1]=(B->A[i][1]-s)/(L->A[i][i]);


}
printf("Y:\n");

afficher(Y);


}
void gauss_sans_pivot(mat A,mat B,mat *C){
int k;
mat X;
for(k=1;k<A.m;k++){
    if(element_null(&A,k,k)==1){
              printf("Pivot null à la %d-ieme iteration d'elimination\n--------        Jetez Un Coup D'Oeil Aux Autres Eliminations de GAUSS Plus sophistiqués\n",k);
        break;
    }

  elim_gauss_k(&A,&B,k);
}
if(element_null(&A,k,k)==0){
affich_syst(&A,&B);
res_remonte(&A,&B,&X);
printf("\n----------->Solution\nX:\n");
}
*C=X;
}

void gauss_partiel(mat A,mat B,mat *C){
int k,imax;
double max;
mat X;

for(k=1;k<A.m;k++){
    rech_max_partiel(&A,k,&max,&imax);
    if(max==0){
        printf("Pivot maximal null donc Matrice Singuliere\n");

       goto fin;
    }
    else{
        permut_ligne(&A,k,imax);
        permut_ligne(&B,k,imax);
          elim_gauss_k(&A,&B,k);
    }

}

affich_syst(&A,&B);
res_remonte(&A,&B,&X);
printf("\n----------->Solution\nX:\n");
*C=B;

fin:;

}



void gauss_total(mat A,mat B,mat *C){
int k,imax,jmax,perm[50];
mat X;
double max=0;
for(k=1;k<A.m;k++){
    recherche_max_total(&A,k,&imax,&jmax,&max);
    if(max==0){
        printf("Pivot maximal null donc Matrice Singuliere\n");

       goto fin;
    }

        permut_ligne(&A,k,imax);
        permut_ligne(&B,k,imax);
           perm[k]=jmax;
        permut_colonne(&A,k,jmax);
          elim_gauss_k(&A,&B,k);
          affich_syst(&A,&B);


}







affich_syst(&A,&B);
res_remonte(&A,&B,&X);
printf("\n");
for(k=A.m-1;k>=1;k--){
    permut_ligne(&X,k,perm[k]);
}
printf("\n----------->Solution\nX:\n");
afficher(&X);
*C=X;

fin:;
}



void gauss_jordan(mat A,mat B,mat *C){
int k,imax,jmax,perm[50];
double max=0;
for(k=1;k<=A.m;k++){
    recherche_max_total(&A,k,&imax,&jmax,&max);
    if(max==0){
        printf("Pivot maximal null donc Matrice Singuliere\n");

       goto fin;
    }
    else{

        permut_ligne(&A,k,imax);
        permut_ligne(&B,k,imax);
        perm[k]=jmax;
        permut_colonne(&A,k,jmax);
         div_piv_lign(&A,&B,k);
         elim_gauss_k_jordan(&A,&B,k);

          affich_syst(&A,&B);
    }

}
for(k=A.m-1;k>=1;k--){
    permut_ligne(&B,k,perm[k]);
}
printf("\n----------->Solution\nB:\n");

afficher(&B);
  *C=B;

fin:;
}






void decomp_doolittle(mat *A,mat *B,mat *L,mat *U,int *alert){
int i,j,k;
double s=0;
init_ident(L,A);
init_zero(U,A);
//calcul premiere ligne U
for(i=1;i<=L->m;i++){
    U->A[1][i]=A->A[1][i];
}
//ELIMINATION GAUSS PARTIEL
//calcul premiere colonne L
for(i=2;i<=L->m;i++){
        if(U->A[1][1]==0){
            printf("Pivot U11 null lors du calcul de la premiere colonne de L de recherche de Li1\n");
            *alert=1;
            goto fin;

        }
    L->A[i][1]=(A->A[i][1])/(U->A[1][1]);



}
for(i=2;i<=L->m-1;i++){
        //calcul du pivot
        s=0;
        for(k=1;k<=i-1;k++){
            s+=L->A[i][k]*U->A[k][i];
        }
        U->A[i][i]=A->A[i][i]-s;


        //

        for(j=i+1;j<=L->m;j++){
                //Calcul i-eme ligne de U
           s=0;
           for(k=1;k<=i-1;k++){
            s+=L->A[i][k]*U->A[k][j];
           }
           U->A[i][j]=A->A[i][j]-s;
                //Calcul de la i-eme colonne de L
                if(U->A[i][i]==0){
            printf("Pivot Uii null lors du calcul de la %d-ieme colonne de L   Lji\n",i);
                 *alert=1;
                 goto fin;
        }
                s=0;
                for(k=1;k<=i-1;k++){

                    s+=L->A[j][k]*U->A[k][i];
                }
                L->A[j][i]=(A->A[j][i]-s)/U->A[i][i];


        }


}
s=0;
for(k=1;k<=L->m-1;k++){
  s+=L->A[L->m][k]*U->A[k][L->m];
}
U->A[L->m][L->m]=A->A[L->m][L->m]-s;

printf("--------->L\n");
afficher(L);
printf("--------->U\n");
afficher(U);
fin:;
}




void decomp_crout(mat *A,mat *B,mat *L,mat *U,int *alert){
int i,j,k;
double s=0;
init_ident(U,A);
init_zero(L,A);
//calcul de la premiere colonne de L
for(i=1;i<=L->m;i++){
    L->A[i][1]=A->A[i][1];
}
//Calcul de la premiere ligne de U

for(i=2;i<=L->m;i++){
    if(L->A[1][1]==0){
        printf("L11 null pour le calcul de la première  ligne de U1i\n");
        *alert=1;
        goto fin;
    }

    U->A[1][i]=(A->A[1][i])/(L->A[1][1]);
}
for(i=2;i<=L->m-1;i++){
        //calcul du pivot Lii
        s=0;
        for(k=1;k<=i-1;k++){
            s+=L->A[i][k]*U->A[k][i];
        }
        L->A[i][i]=A->A[i][i]-s;

        //

        for(j=i+1;j<=L->m;j++){
                //Calcul i-eme colonne  de L
           s=0;
           for(k=1;k<=i-1;k++){
            s+=L->A[j][k]*U->A[k][i];
           }
           L->A[j][i]=A->A[j][i]-s;
                //Calcul de la i-eme ligne de U
                s=0;
                for(k=1;k<=i-1;k++){

                    s+=L->A[i][k]*U->A[k][j];
                }
                if(L->A[i][i]==0){
        printf("Lii null pour le calcul de la %d-eme  ligne de U Uij\n",i);
        *alert=1;
        goto fin;
    }
                U->A[i][j]=(A->A[i][j]-s)/L->A[i][i];


        }


}
//------------------CALCUL DU DERNIER ELEMENT Lnn
s=0;
for(k=1;k<=L->m-1;k++){
  s+=L->A[L->m][k]*U->A[k][L->m];
}
L->A[L->m][L->m]=A->A[L->m][L->m]-s;

printf("------------>L\n");
afficher(L);
printf("------------>U\n");
afficher(U);
fin:;
}

void decomp_LU_doolitle(mat A,mat B,mat *C){
        mat L,U;
        int alert=0;
decomp_doolittle(&A,&B,&L,&U,&alert);
if(alert==1){
    goto fin;
}
mat Y;
res_descente(&L,&B,&Y);
mat X;
printf("-------->Solution\n");
res_remonte(&U,&Y,&X);

*C=X;
fin:;

}
void decomp_LU_crout(mat A,mat B,mat *C){
    mat L,U;
    int alert=0;
    decomp_crout(&A,&B,&L,&U,&alert);
    if(alert==1){
        goto fin;
    }
    mat Y;
   res_descente(&L,&B,&Y);
   mat X;
   printf("-------->Solution\n");
   res_remonte(&U,&Y,&X);

   *C=X;
   fin:;
}
int  symetrique(mat *A){
    int i,j,k;
for(i=1;i<=A->m;i++){
    for(j=1;j<=A->n;j++){
        if(A->A[i][j]!=A->A[j][i]){
            k=0;
                goto fin;
        }
        else{
            k=1;
        }
    }
}
fin: return k;

}
void transpos(mat *Lt,mat *L){
int i,j;
init_zero(Lt,L);
for(i=1;i<=L->m;i++){
    for(j=1;j<=L->n;j++){
        Lt->A[i][j]=L->A[j][i];
    }
}



}
void decomp_cholesky(mat *A,mat *L,mat *Lt){

    double s;
    int k,i,j;
init_ident(L,A);
for(j=1;j<=A->m;j++){
 //CALCUL DU PIVOT Ljj DE LA COLONNE
      s=0;
      for(k=1;k<j;k++){
         s+=pow(L->A[j][k],2);
                      }
                      if((A->A[j][j]-s)<=0){
                        if((A->A[j][j]-s)<0){
                            printf("Matrice non define positive\n");
                        }
                        else{
                          printf("Pivot Null en %d ieme iteration\n",k);
                        }
                        exit(0);
                      }

      L->A[j][j]=sqrt(A->A[j][j]-s);

         //CALCUL DES AUTRES ELEMENTS DE LA COLONNE

      for(i=j+1;i<=L->m;i++){
         s=0;
         for(k=1;k<j;k++){
            s+=L->A[i][k]*L->A[j][k];
        }
     L->A[i][j]=(A->A[i][j]-s)/L->A[j][j];

                            }

}
printf("L:\n");
afficher(L);
transpos(Lt,L);
printf("\nLt:\n");
afficher(Lt);

}
void cholesky(mat A,mat B,mat *C){

mat L,Lt,X,Y;
if(symetrique(&A)==0){
    printf("Matrice non symetrique\n");
    goto fin;
}
decomp_cholesky(&A,&L,&Lt);

res_descente(&L,&B,&Y);
printf("descente \n");
res_remonte(&Lt,&Y,&X);
*C=X;
fin:;
}

void comatr(mat *B,mat *A,int i,int j){
    int k,l;
    int k1=0,l1;
    B->m=A->m;
    B->n=A->n;
    for(k=1;k<=A->m;k++){
            if(k!=i){

                    k1++;
                    l1=0;
                for(l=1;l<=A->n;l++){
                    if(l!=j){

                        l1++;

                    B->A[k1][l1]=A->A[k][l];


                    }
                }
            }

    }
    B->m=A->m-1;
    B->n=A->n-1;


}
double deter(mat A){
    int j;
    double det=0;
    mat B;

if(A.m==2){
    det=A.A[1][1]*A.A[2][2]-A.A[1][2]*A.A[2][1];

}
else{
    for(j=1;j<=A.n;j++){
            comatr(&B,&A,1,j);
        det+=pow(-1,j+1)*A.A[1][j]*deter(B);
    }

}


return det;
}
double norm(mat *X){
    int i;
   double max=0;

    for(i=1;i<=X->m;i++){
      if(X->A[i][1]>max){
        max=X->A[i][1];
      }
    }

return max;
}
int strict_domi (mat *A,mat *B){
    double s;
    int i,j,k=0;
for(j=1;j<=A->n;j++){
    s=0;
    for(i=1;i<=A->m;i++){
           if(i!=j){
            s+=fabs(A->A[i][j]);
           }
    }
    if(fabs(A->A[j][j])>=s){
        k=1;
    }
    else{
        k=0;
        goto fin;
    }
}
fin:return k;
}

void jacobi(mat A,mat B,mat Y,double eps,int maxiter,mat *C){
    mat X,Z;
    double s,n;
    int i,j,iter=1;
init_zero(&X,&B);
init_zero(&Z,&B);


if(strict_domi(&A,&B)==0){
    printf("Matrice  non  dominante \n");
    goto fin;
}



do{
   for(i=1;i<=A.m;i++) {
        s=0;
    for(j=1;j<=A.n;j++){
        if(j!=i)
            s+=A.A[i][j]*Y.A[j][1];
    }
    X.A[i][1]=(B.A[i][1]-s)/A.A[i][i];
    Z.A[i][1]=fabs(X.A[i][1]-Y.A[i][1]);


   }
   Y=X;
   n=norm(&Z);
   iter++;


}while(n>eps && iter<maxiter);

       if(norm(&Z)>eps){
printf("Convergence non atteinte après %d iterations\n",iter);
}
else{
        printf("Convergence atteinte après %d iterations\n---SOLUTION\n",iter);

    afficher(&X);
*C=X;
}
fin:;
}
void gauss_seidel(mat A,mat B,mat Y,double eps,int maxiter,mat *C){
    mat X,Z;
    double s,p,n;
    int i,j,iter=1;
init_zero(&X,&B);
init_zero(&Z,&B);

if(strict_domi(&A,&B)==0){
    printf("Matrice non  dominante \n");
    goto fin;
}


do{
   for(i=1;i<=A.m;i++) {

        //Somme des recents valeurs s'il peut y avoir
        s=0;
    for(j=1;j<=i-1;j++){

            s+=A.A[i][j]*X.A[j][1];
    }
     p=0;
    for(j=i+1;j<=A.n;j++){

            p+=A.A[i][j]*Y.A[j][1];
    }

    X.A[i][1]=(B.A[i][1]-s-p)/A.A[i][i];
    Z.A[i][1]=fabs(X.A[i][1]-Y.A[i][1]);


   }
   Y=X;
   n=norm(&Z);
   iter++;


}while(n>eps && iter<maxiter);

       if(norm(&Z)>eps){
printf("Convergence non atteinte après %d iterations\n",iter);
}
else{
        printf("Convergence atteinte après %d iterations\n---SOLUTION\n",iter);

    afficher(&X);
*C=X;
}
fin:;
}
void range_dominante(mat *A,mat *B){

int k,imax;
double max;

  for(k=1;k<A->m;k++){
        rech_max_partiel(A,k,&max,&imax);
        permut_ligne(A,k,imax);
        permut_ligne(B,k,imax);
  }
  affich_syst(A,B);
 }




