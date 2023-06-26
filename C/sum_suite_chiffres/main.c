#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*int main()
{
    int somme, N, i, a, b, c;
    /*int valChiffre;
    printf("Nombre de chiffres : ");
    scanf("%i", &N);
    somme = 0;
    printf("\nEntrez les chiffres : \n");
    for(i=0; i<N; i++)*
	{
		scanf("%i", &valChiffre);
		somme+=valChiffre;
	}*
	scanf("%i%i%i",&a,&b,&c);
	printf("La somme de la suite de chiffres est %i", a+b+c);
    return 0;
}
*/
///Somme, Produit et Moyenne de chiffres entrés
/*int main()
{
	int C, S/*somme/=0, N/*nombre de chiffres/=0;
	long P/*produit/=1; ///float R/*racine des sommes/;
	do
	{
		printf("Entrez un chiffre : ");
		scanf("%1i", &C);
		if(C<0 || C>9){
			printf("Erreur!!!");}
		else if (C<10 && C>0)
		{
			S+=C;
			N++;
			P*=C;
		}
	}
	while(C>0 && C<10);
	printf("\nNombre de chiffres : %i\n", N);
	printf("Somme = %i", S);
	printf("\nProduit = %li", P);
	printf("\nMoyenne = %f", (float)S/N);
	printf("\nRacine des sommes : %f\n", sqrt(S));
}*/

///Lu à rebours
#include <stdio.h>
main()
{
	int X; /* Le chiffre courant */
	int N=0; /* Le compteur des décimales */
	long VALD=1; /* Valeur de la position décimale courante */
	long NOMB=0; /* Le nombre résultat */
	do
	{
		printf("Entrez le %d%s chiffre : ", (N+1), (N)?"e":"er");
		scanf("%d", &X);
		if (X<0||X>9)
			printf("\a");
		else if (X)
			{
				NOMB += VALD*X;
				N++;
				VALD *= 10;
			}
		else
			printf("La valeur du nombre renversé est %ld\n", NOMB);
	}
	while (X);
	printf("\n********************************************"
	"*****************************");
	return 0;
}
