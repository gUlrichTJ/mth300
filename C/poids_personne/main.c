/**
    Name     : bmi_main.c
    purpose : Calculer le poids idéal d'une personne ainsi que son BMI
    Author   : Rendu d'un ancien étudiant et modifié
    Date      : 2021/03/18
**/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
//#include <conio.h>

int main()
{
    setlocale(LC_CTYPE, "");

    // Déclaration des variables
    char sexe, reponse;
    float taille, poids, pi, bmi;

    do  //Boucle générale d'exécution
    {

        system("color f0");
        system("cls");
        printf("\nProgramme de calcul de BMI");
        do
        {
            printf("\nEntrez le sexe (M ou F) : ");
            scanf("%c", &sexe);
            fflush(stdin);
            if ((sexe != 'M') && (sexe != 'F'))
            {
                printf("\nVous devez saisir M ou F");
            }
        }
        while(sexe != 'M' && sexe != 'F');

        printf("\nEntrez la taille : ");
        scanf("%f",&taille);
        printf("\nEntrez le poids : ");
        scanf("%f",&poids);

        if (sexe=='M')
        {
            pi = (taille-100)-(taille-150)/4;
        }
        else
        {
            pi = (taille-100)-(taille-120)/4;
        }
        printf("\nLe poids id�al de cette personne est %.2f et ", pi);

        bmi = poids/taille*taille;

        if(bmi <= 27)
        {
            printf ("\nCette personne est normale");
        }
        else if (bmi > 27)
        {
            printf ("\nCette personne est ob�se");
        }
        else if (bmi >= 32)
        {
            printf ("\nCette personne est malade");
        }

        printf("\n\nVoulez-vous reprendre l'ex�cution (O/N) : ");
        do //Boucle pour lire la r�ponse
        {
//            reponse = toupper(getche());
            if(reponse!='O' || reponse!='N')
            {
                printf("\b\a");
            }
            fflush(stdin);
        }
        while (reponse!='O' && reponse!='N');

    }
    while (reponse == 'O');

    return 0;
}
