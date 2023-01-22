#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "funSys.h"


void scan_int_point(mat *X,int n){
int i;
X->m=n-1;
 X->n=1;

for(i=0;i<=X->m;i++){
        scanf("%lf",&X->A[i][1]);
}

}
void reconvert_mat(mat *A){
    int i,j;
    printf("\n");

for(i=1;i<=A->m;i++){
    for(j=1;j<=A->n;j++){
        A->A[i-1][j-1]=A->A[i][j];
    }
}
A->m--;
A->n--;


for(i=0;i<=A->m;i++){
    for(j=0;j<=A->m;j++){
            if(j==0){
                printf("|");
            }
        printf(" %lf ",A->A[i][j]);
        if(j==A->m){
                printf("|\n");
            }
    }
}





}
void convert_tableau(mat *A,mat *B){
int i,j;
printf("A:\n");
for(i=0;i<=A->m;i++){
    for(j=0;j<=A->m;j++){
            if(j==0){
                printf("|");
            }
        printf(" %lf ",A->A[i][j]);
        if(j==A->m){
                printf("|\n");
            }
    }
}
printf("B:\n");
for(i=0;i<=B->m;i++){
    printf("|%lf|\n",B->A[i][1]);
}

printf("Conversion\n");
for(i=A->m;i>=0;i--){
    for(j=A->n;j>=0;j--){
        A->A[i+1][j+1]=A->A[i][j];
    }
}
A->m++;
A->n++;
for(i=B->m;i>=0;i--){
    B->A[i+1][1]=B->A[i][1];
}
B->m++;
affich_syst(A,B);



}
void reconvert_colonne(mat *B){
int i;
for(i=1;i<=B->m;i++){
    B->A[i-1][1]=B->A[i][1];
}
B->m--;
printf("B:\n");
for(i=0;i<=B->m;i++){
    printf("|%lf|\n",B->A[i][1]);
}



}
void inter_moindre_carre(mat *X,mat *Y,int p){
mat A,B,C;
int i,j,k;

A.m=p;
A.n=p;
B.m=p;
B.n=1;


for(i=0;i<=A.m;i++){

    for(j=0;j<=A.n;j++){
        for(k=0;k<=X->m;k++){
            A.A[i][j]+=pow(X->A[k][1],2*p-(i+j));
        }
    }

}
for(i=0;i<=B.m;i++){
for(k=0;k<=X->m;k++){
            B.A[i][1]+=Y->A[k][1]*pow(X->A[k][1],p-i);
        }
}

convert_tableau(&A,&B);
cholesky(A,B,&C);
printf("Reconversion\n");
reconvert_colonne(&C);
for(i=p;i>=0;i--){
    if(i!=p){
        printf("+");
    }
    printf("%lf*x^%d",C.A[p-i][1],i);
}


}

void Li(int i,mat *X){
    int j;

for(j=0;j<=X->m;j++){
    if(j!=i){
            if(j!=0 && i==X->m){
            printf("*");
            }
          if(X->A[j][1]<0){
            printf("((x+%lf)/(%lf))",-X->A[j][1],X->A[i][1]-X->A[j][1]);
          }
          else{
             printf("((x-%lf)/(%lf))",X->A[j][1],X->A[i][1]-X->A[j][1]);
          }

        if(j!=X->m && i!=X->m){
            printf("*");
            }

    }
}
    }

void Ni(int i,mat *X){
int k;
if(i==0){
    printf("1");
}
else{
        for(k=0;k<i;k++){
            if(k!=0){
            printf("*");

            }
         if(X->A[k][1]<0){
            printf("(x+%lf)",-X->A[k][1]);
         }
         else{
                printf("(x-%lf)",X->A[k][1]);
         }

        }

}
}

double di(int k,int n,mat *X,mat *Y){
double df;
if(n-k==0){
        df=Y->A[k][1];
    return df ;
}
else{
    df=(di(k+1,n,X,Y)-di(k,n-1,X,Y))/(X->A[n][1]-X->A[k][1]);
return df;
}
}

void interp_langr(mat *X,mat *Y){
    int i;
    printf("P(x)=");
for(i=0;i<=X->m;i++){


            if(i!=0){
                     if(Y->A[i][1]<0){

                    printf("-");

                    printf("%lf*",-Y->A[i][1]);

                     }
                     else{

                    printf("+");

                    printf("%lf*",Y->A[i][1]);
                     }
            }
            else{
                printf("%lf*",Y->A[i][1]);
            }


    Li(i,X);
        }

}

void interp_newton(mat *X,mat *Y){
    printf("P(x)=");
    int i;
for(i=0;i<=X->m;i++){


        if(i!=0){
                if(di(0,i,X,Y)<0){
            printf("-");
            printf("%lf*",-di(0,i,X,Y));
                }
                else{
                    printf("+");
            printf("%lf*",di(0,i,X,Y));

                }
        }
        else{

            printf("%lf*",di(0,i,X,Y));
        }


       Ni(i,X);
        }


        }


