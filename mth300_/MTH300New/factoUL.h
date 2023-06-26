#ifndef FACTOUL_H_INCLUDED
#define FACTOUL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "gauss.h"
#include "matrice.h"
#include "operationMatrice.h"
#include "operationVecteur.h"
#include "gaussJordan.h"


void Crout(float M[], float T[] , int N)
{
    int I=0, J, K;
    float *L=NULL, *U=NULL;

    L=(N*N*malloc(sizeof(float)));
    U=(N*N*malloc(sizeof(float)));

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


}

#endif // FACTOUL_H_INCLUDED
