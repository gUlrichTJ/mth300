#include <stdio.h>
#include <stdlib.h>
/*programme donnant la somme de 1+(1/2)+(1/3)+...+(1/N)*/
int main()
{
	int N, i; float somme;
	do
    {
    	printf("Entrez N : ");
		scanf("%i", &N);

		for(i=1, somme=0; i<(N+1); i++)
		{
			somme+=(1.0/i);
		}
		printf("La somme de cette série est : %f\n", somme);
		printf("1+");
		for (i=2; i<N; i++)
		{
			printf("(1/%i) + ", i);
		}
		printf("(1/%i) = %f", N, somme);
	}
	while (N<2);
    return 0;
}


//par les profs

/*main()
{
	int X; /* Le chiffre courant /
	int N=0; /* Le compteur des données /
	int SOM=0; /* La somme actuelle /
	long PROD=1; /* Le produit actuel - Type long à */
		/* cause de la grandeur du résultat. /

	do
	{
		/* Saisie des données (pour perfectionnistes) /
		printf("Entrez le %d%s chiffre : ", (N+1), (N)?"e":"er");
		scanf("%d", &X);
		if (X<0||X>9)
		printf("\a");
		else if (X)
		{
			N++;
			SOM+=X;
			PROD*=X;
		}
		else if (!X && N>0)
		{/* Seulement si au moins un chiffre a été accepté /
		printf("La somme des chiffres est %d \n", SOM);
		printf("Le produit des chiffres est %ld\n", PROD);
		printf("La moyenne des chiffres est %f \n", (float)SOM/N);
		}
	}
	while (X);
	return 0;
}
*/
///Somme suite chiffres
//fait par Graciano et ça a marché. Merci Seigneur
/*int main()
{
	int chiffre, somme= 0;
	long produit = 1;
	float N=0;/*Nombre de chiffres*/
	/*do
	{
		printf("Entrez un chiffre : ");
		scanf("%i", &chiffre);
		if(chiffre<1 || chiffre >9)
			{printf("\a");}
		else if (chiffre != 0){
			somme+=chiffre;
			produit*=chiffre;
			N++;}
	}
	while(chiffre!=0);
		printf("\nSomme des chiffres : %i", somme);
		printf("\nProduit : %li", produit);
		printf("\nMoyenne : %lf", somme/N);
	return 0;
}*/

//affichage d'étoiles
//#include <stdio.h>
/*int main()
{
    int lignes, i;
    do
    {
     printf("Entrez le nombre de lignes : ");
     scanf("%i",&lignes);
    }
    while(lignes <1 || lignes>40);
    for(i=0; i<lignes+1; i++)
    {
        putchar('\n*');
    }
    return 0;
}
*/
