#include<stdio.h>
int main()
 {
 	///Pas encore compris mais par la grâce de Dieu je comprendrai
 	///Et j'ai compris par la grâce de Dieu
 	//Affichage du nombre à rebours
 	/*Explication : par exemple si je rentre 4, nombre prend la va-
 	leur 4×1; quand je rentre 6, nombre prend la valeur 6×10 + 4;
 	si je rentre 8, nombre prend la valeur 8×100 + l'ancienne valeur
 	de nombre qui fait en tout 864 et ainsi de suite on a ×1000ensuite ×10000
 	...*/
 	int chiffre, nombre, i=0, val_position_decimale=1;
	do
	{
		printf("Entrez un chiffre : ");
		scanf("%i", &chiffre);
		if (chiffre <1 || chiffre >9)
			printf("\a");
		else if (chiffre)
		{
			nombre += chiffre*val_position_decimale;
			i++;
			val_position_decimale*=10;
		}
	}
	while(chiffre);
	printf("Le nombre renversé est : %i", nombre);
	return 0;
 }


///Étoiles
		/*int LIG; /* nombre de lignes /
		int L; /* compteur des lignes /
		int ESP; /* nombre d'espaces /
		int I; /* compteur des caractères /
		char rep;
	do
	{
		do
		{
			printf("Nombres de lignes : ");
			scanf("%d", &LIG);
		}
		while (LIG<1 || LIG>40);
		for (L=0 ; L<LIG ; L++)
		{
			ESP = LIG-L-1;
			for (I=0 ; I<ESP ; I++)
				putchar(' ');
			for (I=	0 ; I<2*L+1 ; I++)
				putchar('*');
				putchar('\n');
		}
		printf("Voulez-vous continuer?(O/N) ");
		scanf("%s", &rep);
	}
	while (rep == 'O');
	return 0;
}*/
