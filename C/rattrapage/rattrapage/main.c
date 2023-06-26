/*//exo 6.12 suite
#include <stdio.h>
#include <stdlib.h>

int main()
{
    long U1 = 1, U2 = 1, Un = 0;
    long N = 0;
    int i;
    printf("\nEntrez la valeur de N : ");
    scanf("%li", &N);
    if(N==1)
        printf("\nU1 = 1\n");
    else if (N==2)
        printf("\nU2 = 1\n");
    else{
        for(i=2; i<N; i++)
        {
            Un = U1+U2;
            U1=U2;
            U2 = Un;
        }
        printf("La valeur de U%li est %li\n", N, Un);
    }
    return 0;
}*/
/*
//exo 7.1 tab
#include<stdio.h>
int main()
{
    int T[50], N=0, i;
    int TPOS[50], TNEG[50];
    int pos = 0, neg = 0;
    do{
        printf("Entrez la dimension du tableau : ");
        scanf("%i", &N);
    }
    while(N<1|| N>50);
    //Remplissage du tableau
    for(i=0; i<N; i++){
        printf("Entrez le %i%s element : ", (i+1), (i) ? "e" : "er");
        scanf("%i", &T[i]);
    }
    //Affichage du tableau
    printf("\n\nTableau donné \n");
    for(i = 0; i<N; i++)
        printf("%i  ", T[i]);
    putchar('\n');
    //Remplissage des deux autres tableaux
    for(i=0; i<N; i++)
    {
        if(T[i]<0){
            TNEG[neg]=T[i];
            neg++;
        }
        else{
            TPOS[pos] = T[i];
            pos++;
        }
    }
    //Affichage des tableaux
    if(neg)
    {
        printf("\n\nElements negatifs\n");
        for(i=0; i<neg; i++)
            printf("%i ", TNEG[i]);
        printf("\n");
    }
    if(pos)
    {
        printf("\n\nElements positifs\n");
        for(i=0; i<pos; i++)
            printf("%i ", TPOS[i]);
        printf("\n");
    }
}
*/
//exo 7.6 somme de lignes et de colonnes
//transfert dans tableau a une dimension
/*
#include<stdio.h>
int main()
{
    int T[10][10], V[100];
    int L, C;
    int i, j, somme = 0, aide = 0;
    do
    {
        printf("Entrez le nombre de lignes : ");
        scanf("%i", &L);
    }
    while(L<1 || L>10);
    do
    {
        printf("Entrez le nombre de colonnes : ");
        scanf("%i", &C);
    }
    while(C<1 || C>10);
    //Entree des elements dans le tableau a deux dimension
    for(i=0; i<L; i++)
    {
        for(j=0; j<C; j++)
        {
            printf("Element [%i][%i] : ", i, j);
            scanf("%i", &T[i][j]);
        }
    }
    printf("\nTableau donne\n");
    for(i=0; i<L; i++)
    {
        for(j=0; j<C; j++)
            printf("%7i", T[i][j]);
        printf("\n");
    }
    //Transfert dans le tableau a une dimension
    for(i=0; i<L; i++)
        for(j=0; j<C; j++)
            V[i*C+j] = T[i][j];///

    for(i=0; i<L*C; i++)
        printf("%i ", V[i]);
}
*/
//exponentiel
//Schema d'horner
#include<stdio.h>
int main()
{

}
