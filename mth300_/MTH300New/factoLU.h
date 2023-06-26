#ifndef FACTOLU_H_INCLUDED
#define FACTOLU_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "gauss.h"
#include "matrice.h"
#include "operationMatrice.h"
#include "operationVecteur.h"
#include "gaussJordan.h"



void remonteeTriangulaire (float U[],float y[], float x[], int N);
void descenteTriangulaire(float L[], float y[], float B[], int N);

/**
    SECTION 1 : Factoristaion LU par la méthode de Crout
    PRINCIPE : La méthode de Crout se propose de déterminer les deux matrices L et U de la factorisation LU
    en mettant des 1 sur la matrice triangulaire supérieure ( matrice U); le reste du principe reste identique à la
    méthode de Crout : aprés avoir déterminer les deux matrices L et U ,procédé à une descente sur la matrice L
    en utilisant le système Ly = B pour trouvé le vecteur y puis ensuite procédé à une remontée sur la matrice utilisant
    le système Ux = y pour déterminer la solution X du sytème Ax=B
    ATTENTION : Si pendant l'éxécution on constate la matrice n'est pas inversible on envoie un message à l'utilisateur
     et  on arrête l'éxecution de la fonction
**/

void Crout(float M[], float T[], float x[], int N)
{
    int I=0, J, K;
    int next=0, nouveau=0;
    int trouve, find;
    float *L=NULL, *U=NULL, *y=NULL;
    float som;
    float SomLigne;
    float somColonne;
    float pivot=0;
    int  search(float tmp[],int L,int I, int *newLine);

    L=malloc(N*N*(sizeof(float)));
    U=malloc(N*N*(sizeof(float)));
    y=malloc(N*(sizeof(float)));

    /**initialisation des deux matrices**/
    while(I<N)
    {
        J=0;
        while(J<N)
        {
            L[I*N+J]=0;
            U[I*N+J]=0;
            J++;
        }
        I++;
    }

    /**initialisation des valeurs respective de la première colonne et de la deuxième ligne
    dans les matrices L et U**/

    if(M[0*N+0]==0)
    {
        trouve=search(M,N,0,&next);
        printf("\n%d",trouve);
        printf("\n%d",next);
        putchar('\n');
        if(trouve==0)
        {
            intervertir(M,N,0,next);
            permuter(T,0,next);
        }
        else
        {
            printf("\nImpossible d'appliquer la méthode de Crout\n");
            printf("\nLa matrice n'est pas inversible");
            return ;
        }
    }

    I=0;
    while(I<N)
    {
        L[I*N+0]=M[I*N+0];
        U[0*N+I]=M[0*N+I]/L[0*N+0];

        I++;
    }

    I=1;
    while(I<N)
    {
        ///calcul du pivot
        K=0;
        som=0;
        while(K<I)
        {
            som+=L[I*N+K]*U[K*N+I];
            K++;
        }
        L[I*N+I]=M[I*N+I]-som;
        ///calcul de la ième colonne de L
        J=I+1;
        while(J<N)
        {
            K=0;
            somColonne=0;
            SomLigne=0;
            while(K<I)
            {
                somColonne+=L[J*N+K]*U[K*N+I];
                K++;
            }

            L[J*N+I]=M[J*N+I]-somColonne;
            J++;
        }

        if(L[I*N+I]==0)
        {
            find=search(L,N,I,&nouveau);
            printf("\n%d",nouveau);
            if(find==0)
            {
                intervertir(L,N,I,nouveau);
                intervertir(M,N,I,nouveau);
                permuter(T,I,nouveau);
            }
            else
            {
                printf("\nImpossible d'appliquer la méthode de Crout\n");
                printf("\nLa matrice n'est pas inversible");
                return ;
            }
        }


        ///calcul de la ième ligne de U
        J=I+1;
        while(J<N)
        {

            K=0;
            somColonne=0;
            SomLigne=0;
            while(K<I)
            {
                SomLigne+=L[I*N+K]*U[K*N+J];
                K++;
            }

            pivot=M[I*N+J]-SomLigne;
            U[I*N+J]=pivot/L[I*N+I];
            J++;
        }

        I++;

    }

    /// calcul du dernier terme Lnn de la matrice triangulaire supérieure L
    K=0;
    som=0;
    I=N-1;
    while(K<N-1)
    {
        som+=L[I*N+K]*U[K*N+I];
        K++;
    }

    L[I*N+I]=M[I*N+I]-som;

    /** tous les éléments diagonaux de la matrice triangulaire
      supérieure U sont mis à 1**/
    I=0;
    while(I<N)
    {
        U[I*N+I]=1;
        I++;
    }
    printf("\n------------------------MATRICE  L ------------------------\n");
    ecrireMatrice(L,N,N);
    printf("\n-------------------------MATRICE  U ------------------------\n");
    ecrireMatrice(U,N,N);
    descenteTriangulaire(L,y,T,N);
    ///remonteeTriangulaire(U,y,x,N);
    remontee(U,y,x,N);
    printf("\n------------------------VECTEUR  Y------------------------\n");
    ecrireVect(y,N);
    printf("\n------------------------SOLUTION DU SYSTEME---------------------\n");
    ecrire_solution(x,N);
}

void descenteTriangulaire(float L[], float y[], float B[], int N)
{
    int I=1, K;
    float som;
    float pivot=0;
    y[0]=B[0]/L[0*N+0];

    while(I<N)
    {
        K=0;
        som=0;
        pivot=L[I*N+I];
        while(K<I)
        {
            som+=L[I*N+K]*y[K];
            K++;
        }
        y[I]=(B[I]-som)/pivot;
        I++;
    }

}

///à rechercher : notation compacte
void remonteeTriangulaire (float U[],float y[], float x[], int N)
{
    int I=N-2, K;
    float som;
    x[N-1]=y[N-1];

    while(I>=0)
    {
        K =I+1;
        som=0;
        while(K<N)
        {
            som+=U[I*N+K]*x[K];
            K++;
        }

        x[I]=y[I]-som;
        I--;
    }
}
/**
    SECTION 2 : Factoristaion LU par la méthode Dotlit
    PRINCIPE : Contrairement  à la méthode crout ; la méthode de Dotlit met des 1 sur toute la
    diagonale  de la matrice triangulaire inférieure ( matrice L) ; le reste du principe reste identique à la
    méthode de Crout : aprés avoir déterminer les deux matrices L et U ,procédé à une descente sur la matrice L
    en utilisant le système Ly = B pour trouvé le vecteur y puis ensuite procédé à une remontée sur la matrice utilisant
    le système Ux = y pour déterminer la solution X du sytème Ax=B
    ATTENTION : Si pendant l'éxécution on constate la matrice n'est pas inversible on envoie un message à l'utilisateur
     et  on arrête l'éxecution de la fonction
 ***/

void Dotlit(float M[], float T[], float x[], int N)
{
    int I=0, J, K;
    int next=0, nouveau=0;
    int trouve, find;
    float *L=NULL, *U=NULL, *y=NULL;
    float som;
    float SomLigne;
    float somColonne;
    float pivot=0;
    int  search(float tmp[],int L,int I, int *newLine);

    L=malloc(N*N*(sizeof(float)));
    U=malloc(N*N*(sizeof(float)));
    y=malloc(N*(sizeof(float)));

    /**initialisation des deux matrices**/
    while(I<N)
    {
        J=0;
        while(J<N)
        {
            L[I*N+J]=0;
            U[I*N+J]=0;
            J++;
        }
        I++;
    }

    /**initialisation des valeurs respective de la première colonne et de la deuxième ligne
    dans les matrices L et U**/

    if(M[0*N+0]==0)
    {
        trouve=search(M,N,0,&next);
        putchar('\n');
        if(trouve==0)
        {
            intervertir(M,N,0,next);
            permuter(T,0,next);
        }
        else
        {
            printf("\nImpossible d'appliquer la méthode de Dotlit\n");
            printf("\nLa matrice n'est pas inversible");
            return ;
        }
    }

    I=0;
    while(I<N)
    {
        U[0*N+I]=M[0*N+I];
        L[I*N+0]=M[I*N+0]/U[0*N+0];

        I++;
    }

    I=1;
    while(I<N)
    {
        ///calcul du pivot
        K=0;
        som=0;
        while(K<I)
        {
            som+=L[I*N+K]*U[K*N+I];
            K++;
        }
        L[I*N+I]=M[I*N+I]-som;
        ///calcul de la ième colonne de L
        J=1;
        while(J<I)
        {
            K=0;
            somColonne=0;
            while(K<J)
            {
                somColonne+=L[I*N+K]*U[K*N+J];
                K++;
            }

            pivot=M[I*N+J]-somColonne;
            L[I*N+J]=pivot/U[J*N+J];
            J++;
        }



        ///calcul de la ième ligne de U
        J=I;
        while(J<N)
        {

            K=0;
            SomLigne=0;
            while(K<I)
            {
                SomLigne+=L[I*N+K]*U[K*N+J];
                K++;
            }

            U[I*N+J]=M[I*N+J]-SomLigne;
            J++;
        }

        if(U[I*N+I]==0)
        {
            find=search(U,N,I,&nouveau);
            if(find==0)
            {
                intervertir(U,N,I,nouveau);
                intervertir(M,N,I,nouveau);
                permuter(T,I,nouveau);
            }
            else
            {
                printf("\nImpossible d'appliquer la méthode de Dotlit\n");
                printf("\nLa matrice n'est pas inversible");
                return;
            }
        }


        I++;

    }


    /**tous les éléments diagonaux de la matrice triangulaire
      supérieure U sont mis à 1**/
    I=0;
    while(I<N)
    {
        L[I*N+I]=1;
        I++;
    }
    printf("\n------------------------MATRICE  L ------------------------\n");
    ecrireMatrice(L,N,N);
    printf("\n-------------------------MATRICE  U ------------------------\n");
    ecrireMatrice(U,N,N);
    descenteTriangulaire(L,y,T,N);
    ///remonteeTriangulaire(U,y,x,N);
    remontee(U,y,x,N);
    printf("\n------------------------VECTEUR  Y------------------------\n");
    ecrireVect(y,N);
    printf("\n------------------------SOLUTION DU SYSTEME---------------------\n");
    ecrire_solution(x,N);
}


int  search(float tmp[],int L,int I, int *newLine)
{
    int i=I+1,J;
    int trouve=0, nouveau =0, tmp1=0, tmp2=0;/**indicateurs logiques qui vérifie  si
    la ligne a été bien trouvée**/
    while((i<L)&&(trouve==0))
    {
        if(tmp[i*L+I]!=0)
        {
            trouve=1;
            tmp1=i;
        }
        i++;
    }

    /** si un élément est trouvé vérifier s'il est le plus grand en valeur absolue**/
    if(trouve==1)
    {
        J=tmp1+1;
        while((J<L)&&(nouveau==0))
        {
            if(tmp[J*L+I]>tmp[tmp1*L+I])
            {
                nouveau=1;
                tmp2=J;
            }
            J++;
        }
    }
    printf("%d",tmp2);
    if(nouveau ==1)
    {
        *newLine=tmp2;
    }
    else if((trouve==1)&&(nouveau==0))
    {
        *newLine=tmp1;
    }
    else0
    {
        return -1;
    }

    return 0;
}
/**SECTION 3 : TDMA (TriDiagonal Matrix Algorithm (Algorithme de Thomas 0

**/

void Thomas(float M[], float T[], float x[], int N)
{
    float *L, *U, *y;
    int I=0,J,K;
    float som;
    ////void tridiagonale(float M[],float T[], int L);
    L=malloc(N*N*sizeof(float));
    U=malloc(N*N*sizeof(float));
    y=malloc(N*sizeof(float));

    /**triagonaliser la matrice passée en paramètre**/
    ///tridiagonale(M,T,N);
    /**initialisation des deux matrices**/
    while(I<N)
    {
        J=0;
        while(J<N)
        {
            L[I*N+J]=0;
            U[I*N+J]=0;
            J++;
        }
        I++;
    }


    I=0;
    while(I<N)
    {
        K=0;
        som=0;
        ///calcul du pivot
        while(K<I)
        {
            som+=L[I*N+K]*U[K*N+I];
            K++;
        }
        U[I*N+I]=M[I*N+I]-som;
        L[I*N+I]=1;

        J=I+1;
        U[I*N+J]=M[I*N+J];

        L[J*N+I]=M[J*N+I]/U[I*N+I];
        I++;
    }
    printf("\n------------------------MATRICE  L ------------------------\n");
    ecrireMatrice(L,N,N);
    printf("\n-------------------------MATRICE  U ------------------------\n");
    ecrireMatrice(U,N,N);
    descenteTriangulaire(L,y,T,N);
    remontee(U,y,x,N);
    ///remonteeTriangulaire(U,y,x,N);
    printf("\n------------------------VECTEUR  Y------------------------\n");
    ecrireVect(y,N);
    printf("\n------------------------SOLUTION DU SYSTEME---------------------\n");
    ecrire_solution(x,N);

}

int rechercher_pivot(float tmp[],int L,int I, int *newLine)
{
    int i=I+1,J;
    int trouve=0, nouveau =0, tmp1=0, tmp2=0;/**indicateurs logiques qui vérifie  si
    la ligne a été bien trouvée**/
    while((i<L)&&(trouve==0))
    {
        if(tmp[i*L+I]!=0)
        {
            trouve=1;
            tmp1=i;
        }
        i++;
    }

    /** si un élément est trouvé vérifier s'il est le plus grand en valeur absolue**/
    if(trouve==1)
    {
        J=tmp1+1;
        while((J<L)&&(nouveau==0))
        {
            if(tmp[J*L+I]>tmp[tmp1*L+I])
            {
                nouveau=1;
                tmp2=J;
            }
            J++;
        }
    }
    printf("%d",tmp2);
    if(nouveau ==1)
    {
        *newLine=tmp2;
    }
    else if((trouve==1)&&(nouveau==0))
    {
        *newLine=tmp1;
    }
    else
    {
        return -1;
    }

    return 0;
}

/**void tridiagonale(float M[],float T[], int L)**/
/**{
        int i=1,j,k;
    int next=0, find;
    float tmp=0;
    float pivot=0;

    créer une matrice triangulaire supérieure
    while(i<L)
    {

        if(verifierPivotNonNul(M,L,i)==0)
        {
            find=search(M,L,i,&next);
            printf("\n%d",next);
            if(find==0)
            {
                intervertir(M,L,i,next);
                permuter(T,i,next);
            }
            else
            {
                printf("\nImpossible d'appliquer la méthode de Gauss\n");
                printf("\nLa matrice n'est pas inversible ");
                return ;
            }

        }
        k=i+1;
        pivot=M[i*L+i];
        while(k<L)
        {
            tmp=M[k*L+i]/pivot;
            j=i;
            while(j<L)
            {
                M[k*L+j]=M[k*L+j]-tmp*M[i*L+j];
                j++;
            }
            T[k]=T[k]-tmp*T[i];
            k++;
        }
        i++;

    }

    ----------------------------------------
    éliminer tous les éléments qui ne sont pas
    sur la sur-diagonale
    i=L-2;
        while(i>=0)
    {
        k=i-1;
        pivot=M[i*L+i];
        while(k>=0)
        {
            tmp=M[k*L+i]/pivot;
            j=L-1;
            while(j>=i-1)
            {
                M[k*L+j]=M[k*L+j]-tmp*M[i*L+j];
                j--;
            }
            T[k]=T[k]-tmp*T[i];
            k--;
        }
        i--;
    }

}
***/

#endif // FACTOLU_H_INCLUDED
