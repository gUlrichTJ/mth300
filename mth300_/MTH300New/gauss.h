#ifndef GAUSS_H_INCLUDED
#define GAUSS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include "matrice.h"
#include "operationMatrice.h"
#include "operationVecteur.h"

/** Triangulariser la matrice afin de la rendre triangulaire supérieure .
Si pendant la matrice n'est pas inversible on renvoie -1 puis on quitte la fonction sinon
on renvoie pour dire que tout a bien fonctionné**/
int diagonaliser(float M[],float T[], int L)
{
    int i=0,j,k;
    int next=0, find;
    float tmp=0;
    float pivot=0;
    while(i<L)
    {
        /** si le pivot à la ligne I l'élément M[I*N+I] est nul alors on cherche dans la matrice
        le plus grand pivot non nul en valeur absolue ; si un pivot est trouvé alors on
        permute la ligne du nouveau pivot avec  celle de l'ancien sinon on renvoie pour signaler que
        la matrice n'est pas inversible**/

        if(verifierPivotNonNul(M,L,i)==0)
        {
            find=RechercherPivotNonNul(M,L,i,&next);
            if(find==0)
            {
                intervertir(M,L,i,next);
                permuter(T,i,next);
            }
            else
            {
                return -1;
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
    return 0;
}



void remontee(float M[],float T[],float result[], int L)
{
    int i=L-1,j;
    float som;
    while(i>=0)
    {
        j=i+1;
        som=0;
        while(j<L)
        {
            som+=M[i*L+j]*result[j];
            j++;
        }
        result[i]=(T[i]-som)/(M[i*L+i]);
        i--;
    }
}

void gauss(float M[],float T[],float result[], int L, int N)
{
    int test;
    void remontee(float M[],float T[],float result[], int L);
    int diagonaliser(float M[],float T[], int L);
    test=diagonaliser(M,T,L);
    if(test==0)
    {
        printf("\n---------------MATRICE  TRIANGULAIRE SUPERIEURE ---------------\n");
        ecrireMatrice(M,L,L);
        remontee(M,T,result,L);
        printf("\n------------------------SOLUTION DU SYSTEME---------------------\n");
        ecrire_solution(result,L);

    }
    else
    {
        printf("\nImpossible d'appliquer la méthode de Gauss");
        printf("\nLa matrice n'est pas inversible ");

    }
}

#endif // GAUSS_H_INCLUDED
