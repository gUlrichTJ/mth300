/*  Name : tab_multi.c
    Purpose : Table de multiplication
    Authors : Équipe de travail dirigée par le chargé du cours
    Date : 2015/01/20
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>

int main()
{
    int mult, nLigne, cpt, result;
    char rep;

    do
    {
        system("f0");
        system("CLS");
        printf("\nProgramme Table de multiplication");

        //Entr�es
        printf("\nMultiplicateur = ");
        scanf("%d", &mult);
        printf("\nNombre de lignes = ");
        scanf("%d", &nLigne);

        //Calcul et affichage
        for(cpt=0; cpt<=nLigne; cpt++)
        {
            result=mult*cpt;
            printf("\n%5d  * %5d = %7d", mult, cpt, result);
        }
        fflush(stdin);

        printf("\nVoulez-vous essayer encore (O/N) ? ");
        rep = toupper(getche());
    }
    while(rep=='O');
    return 0;
}
