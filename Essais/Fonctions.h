#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED
#include<stdlib.h>
#include<math.h>//<stdlib.h>

//Méthode le la sécante
float fPFixe(float x)
{
	return exp(x);
}
float pointFixe()
{
	float Xo=0, N, gXo = 0;
	int i;//Compteur
	printf("Entrez Xo : ");
	scanf("%f", &Xo);
	printf("Entrez le nombre maximal d'itérations : ");
	scanf("%f", &N);
	do
	{
        gXo = fPFixe(Xo);
        Xo = gXo;
        i++;
	}
	while(i<=N);
	printf("\nSolution : %f", Xo);
}

#endif // FONCTIONS_H_INCLUDED
