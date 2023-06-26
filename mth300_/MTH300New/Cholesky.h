#ifndef CHOLESKY_H_INCLUDED
#define CHOLESKY_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "FactorisationLU.h"
#include "matrice.h"
#include "operationVecteur.h"
#include "gauss.h"
#include <stdbool.h>

void cholesky(float A[], float B[], int N)
{
    float *L=NULL, *tL=NULL, *y=NULL, *x=NULL;
    int I,J,K;
    float som, tmp;
    bool symetric , positive ;
    bool verifier_symetric(float M[], int N);
    bool verifier_definie_postive(float M[], int N);
    L=malloc(N*N*sizeof(float));
    tL=malloc(N*N*sizeof(float));
    x=malloc(N*sizeof(float));
    y=malloc(N*sizeof(float));
    /**initialisation de la matrice**/
    I=0;
    while(I<N)
    {
        J=0;
        while(J<N)
        {
            L[I*N+J]=0;
            J++;
        }
        I++;
    }
    /**vérifier si la méthode de sholesky peut converger
    vers la solution pour cette matrice**/
    symetric=verifier_symetric(A,N);
    if(symetric == false)
    {
        printf("\nImpossible d'appliquer la méthode de sholesky à ce système;\n ");
        printf("il n'est pas symétrique\n");
        return ;
    }

    positive=verifier_definie_postive(A,N);
    if(positive== false)
    {
        printf("\nLa matrice n'est pas définie positive \n");
        return ;
    }
    /**on calcule le premier de la matrice L**/
    L[0*N+0]=sqrt(A[0*N+0]);

    I=1;
    while(I<N)
    {
        /**calculer les éléments de la première colonne**/
        L[I*N+0]=A[0*N+I]/L[0*N+0];
        som=0;
        K=0;
        /**calcul l'élément situé sur la diagonale**/
        while(K<I)
        {
            som+=L[I*N+K]*L[I*N+K];
            K++;
        }
        L[I*N+I]=sqrt(A[I*N+I]-som);
        /**calculer l'élément L[I][J]*-*/
        J=1;
        while(J<I)
        {
            K=0;
            som=0;
            while(K<J)
            {
                som+=L[I*N+K]*L[J*N+K];
                K++;
            }
            tmp=A[I*N+J]-som;
            L[I*N+J]=tmp/L[J*N+J];
            J++;
        }
        I++;

    }
///édition de la matrice transposée de L
    ///transposition de la matrice
    I=0;
    while(I<N)
    {
        J=0;
        while (J<N)
        {
            tL[I*N+J]=L[J*N+I];
            J++;
        }
        I++;
    }


    descenteTriangulaire(L,y,B,N);
    remontee(tL,y,x,N);
    ///remonteeTriangulaire(tL,y,x,N);
    printf("\n------------------------MATRICE \"L\"------------------------\n");
    ecrireMatrice(L,N,N);
    printf("\n-----------------MATRICE TRANSPOSEE DE \"L\"----------------\n");
    ecrireMatrice(tL,N,N);
    printf("\n---------------------SOLUTIONS DU SYSTEME--------------------\n");
    ecrire_solution(x,N);
}


bool verifier_symetric(float M[] ,int N)
{
    bool converge = true, symetric= true , test =true;
    int I=0, J;
    while((I<N)&&(symetric==true))
    {
        J=0;
        while((J<N)&&(test==true))
        {
            if(M[I*N+J] !=M[J*N+I])
            {
                test=false;

            }
            J++;
        }
        if(test==false)
        {
            symetric=false;
        }
        I++;
    }

    if(symetric==false)
    {
        converge=false;
    }
    return converge;
}

bool verifier_definie_postive(float M[] ,int N)
{
    bool positive =true ,converge = true;
    int I=0, J;
    float som;
    while((I<N)&&(positive==true))
    {
        /**calculer les éléments de la première colonne**/
        som=0;
        J=0;
        /**calcul l'élément situé sur la diagonale**/
        while(J<I)
        {
            som+=M[I*N+J]*M[I*N+J];
            J++;
        }
        if(M[I*N+I]<som)
        {
            positive=false;
        }
        I++;
    }
    if(positive==false)
    {
        converge=false;
    }
    return converge;

}

#endif // CHOLESKY_H_INCLUDED
