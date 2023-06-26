/*
#include <stdio.h>
#include <stdlib.h>
typedef struct Choix
{
	int x;
	float y;
}Choix;

int main()
{
    Choix d;
    int choice;
    printf("Enter : \n1 for integer\n2 for a float \n");
    printf("\nEnter you choice : ");
    scanf("%i", &choice);
    switch(choice)
    {
    	case 1 : printf("\nEnter an enteger : ");
					scanf("%i", &d.x);
					printf("You've entered : %i\n", d.x);
			break;
		case 2 : printf("Enter a float : ");
					scanf("%f", &d.y);
					printf("You've entered : %i\n", d.y);
			break;
		default : printf("\nIncorrect value\nbye and have a good day\n");
    }
    return 0;
}
*/
//Merci beaucoup Seigneur Jésus. Merci encore Seigneur
//Structure Père
/*
#include<stdio.h>
#include<stdlib.h>
typedef struct pere
{
	char nom[20]; char date_nais[10];
	int nbr_enf;
	char liste_enf[10][15];
}Pere;
//This function gives information on dad
Pere father(Pere pere1)
{
	int i, rep = 0;
	do
	{
	    printf("\nDonnez le nom de papa : ");
		scanf("%s", pere1.nom);
		printf("Donnez la date de naissance de papa : ");
		scanf("%s", pere1.date_nais);
		printf("Papa a combien d'enfants ? ");
		scanf("%i", &pere1.nbr_enf);
		putchar('\n');
		for(i = 0; i<pere1.nbr_enf; i++)
		{
			printf("Nom de l'enfant %i : ", i+1);
			scanf("%s", pere1.liste_enf[i]);
		}
		puts("Information on dad");
		printf("Name %s\nBirthday : %s\nNumber of children"
			" : %i", pere1.nom, pere1.date_nais, pere1.nbr_enf);
		putchar('\n');

		for(i = 0; i<pere1.nbr_enf; i++)
			printf("Child N° %i : %s\n", i+1, pere1.liste_enf[i]);
		puts("\nMerci beaucoup Seigneur Jésus\n");
		printf("\nEnter 1 if you want to continue : ");
		scanf("%i", &rep);
	}
	while(rep == 1);
}
int main()
{
	int i;//Counter of the number of children
    Pere pere1;
	father(pere1);
}*/

//Tableau de pères
#include<stdio.h>
#include<stdlib.h>
typedef struct Pere
{
	char name[15], date_nais[15];
	int nbr_enf;
	char liste_enf[50];
}Pere;
//Let's declare a function which takes fathers components
Pere array()
{
	Pere pere;
	Pere tabFather[5];
	int i;
	for(i=0; i<5; i++)
	{
		printf("\nEnter dad n°%i's name : ", i+1);
		scanf("%s", tabFather[i].name);
		printf("Enter dad's birthday : ");
		scanf("%s", tabFather[i].date_nais);
		printf("\nHow many children does dad have ? ");
		scanf("%i", &tabFather[i].nbr_enf);
		printf("Enter father's children : ");
		scanf("%s", tabFather[i].liste_enf);
		//gets(tabFather[i].liste_enf);
	}
	puts("\nInformation on fathers\n");
	for(i=0; i<5; i++)
		{
			printf("\nFather's %i \n", i+1);
			printf("Name : %s", tabFather[i].name);
			printf("\nBirthday : %s", tabFather[i].date_nais);
			printf("\nNumber of children : %i", tabFather[i].nbr_enf);
			printf("\nListe of children : %s", tabFather[i].liste_enf);
			puts(tabFather[i].liste_enf);
			printf("\n");
		}
}
//In main function, we declare an array of 5 dim
int main()
{
	array();
}
