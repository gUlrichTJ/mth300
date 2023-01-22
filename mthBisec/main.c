#include <stdio.h>
#include <stdlib.h>
#include<math.h>

//Fonction Essai point Fixes
float fPfixe1(float x)
{
	return exp(-x);
}
float pointFixeEssai()
{
	float Xo=0, N, gXo = 0;
	int i;//Compteur
	printf("Entrez Xo : ");
	scanf("%f", &Xo);
	printf("Entrez le nombre maximal d'itérations : ");
	scanf("%f", &N);
	do
	{
        gXo = fPfixe1(Xo);
        Xo = gXo;
        i++;
	}
	while(i<=N);
	printf("\nSolution : %f", Xo);
}
int main()
{
	pointFixeEssai();
	//Bissection
	float a, b, fa, fb;
	float Xm = 0, fXm=0;
	float epta;
	printf("Entrez la borne inférieure : ");
	scanf("%f", &a);
	printf("Entrez la borne supérieure : ");
	scanf("%f", &b);
	printf("Entrez f(%f) : ", a);
	scanf("%f", &fa);
	printf("Entrez f(%f) : ", b);
	scanf("%f", &fb);
	//Critère d'arrêt
	printf("Entrez le critère d'arrêt : ");
	scanf("%f", &epta);
	if(fa*fb>0)
		printf("\nIl n'y a pas de solution dans l'intervalle [%f, %f]\n", a, b);
	else
	{
		do
		{
            Xm = (a+b)/2;
			printf("Entrez f(%f) : ", Xm);
			scanf("%f", &fXm);
			if(fXm == 0)
				printf("\nSolution : %f\n", Xm);
			else if(fa*fXm<0)
				b = Xm;
			else
				a = Xm;
			printf("\nEntrez f(%f) : ", a);
			scanf("%f", &fa);
			printf("Entrez f(%f) : ", b);
			scanf("%f", &fb);
		}
		while(b-a<epta);
	}
	//Édition du résultat
	printf("\nSolution : %f\n", Xm);
    return 0;
}
