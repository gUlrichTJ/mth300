/*
#include<stdio.h>
int main()
{
	int I, J, max;
	printf(" X*Y  I");
	for(J=0, max= 11; J<max; J++)
		printf("%4i", J);
	printf("\n");
	printf("-------");
	for(J=0, max=11; J<max; J++)
		printf("----");
	printf("\n");
	//Affichage du tableau
//	for(I=0)
	int i, n=10, k=7;
	i=n<k;
	printf("%d", i);
}*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main ( int argc, char** argv )
{
	int nombreMystere = 0, nombreEntre = 0;
	const int MAX = 100, MIN = 1;
	// Génération du nombre aléatoire

	srand(time(NULL));
	nombreMystere = (rand() % (MAX - MIN + 1)) + MIN;
	/* La boucle du programme. Elle se répète tant que l'utilisateur
,	→ n'a pas trouvé le nombre mystère */
	do
	{
	// On demande le nombre
		printf("Quel est le nombre ? ");
		scanf("%d", &nombreEntre);
		// On compare le nombre entré avec le nombre mystère
		if (nombreMystere > nombreEntre)
			printf("C'est plus !\n\n");
		else if (nombreMystere < nombreEntre)
			printf("C'est moins !\n\n");
		else
			printf ("Bravo, vous avez trouve le nombre mystere !!!\n\n");
	}

	while (nombreEntre != nombreMystere);
}
