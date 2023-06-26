//thanks Lord it ran
/*#include<stdio.h>
int main()
{
	int entier, nombre1, nombre, somme, compteur;
	char rep;
	do
	{
		do
		{
			printf("Entrez un nombre (11< nombre <10000) : ");
			scanf("%i", &nombre);
		}
		while(nombre<11||nombre>10000);
		nombre1=nombre;
		somme=0; entier=0; compteur=0;
		while (nombre>0)
		{
			entier=nombre%10;
			somme+=entier;
			nombre/=10;
			compteur++;
		}
		printf("Somme des chiffres contenus dans %i : %i", nombre1, somme);
		printf("\nVoulez-vous continuer? (Y/N) : ");
		scanf("\n%s", &rep);
	}
	while(rep=='Y');
	return 0;
}*/

//pgcd par le prof
/*#include<stdio.h>
int main()
 {
 	int a, b, x, y, reste;
 	do
	{
		printf("Entrez la valeur de l'entier A (non nul) : ");
		scanf("%i",&a);
	}
	while(!a);
	 	do
	{
		printf("Entrez la valeur de l'entier B (non nul) : ");
		scanf("%i",&b);
	}
	while(!b);
	for (reste =a,x=a,y=b; reste; x=y, y=reste)
	{reste=x%y;}
	printf("le pgcd de %i et de %i est %i", a, b, x);
	return 0;
}*/

//suite de fibonacci
/*#include<stdio.h>
int main()
{
	int U1=1, U2= 1, Un, n, i; 	/**compteur/
		do
		{
			printf("Entrez le terme de Un à calculer(0< n <10000) : ");
			scanf("%i", &n);
		}
		while(n<1);
		if (n==1)
			Un=U1;
		else if(n==2)
			Un=U2;
		else
			{
				for(i=3; i<n+1; i++)
				{
					Un = U1+U2;
					U1=U2;
					U2=Un;
				}
			}
		printf("U%i = %i\n", n, Un);
	return 0;
}*/

//Approximation racine carrée
/*#include <stdio.h>
int main()
{
	double A; /* donnée /
	double X; /* approximation de la racine carrée de A /
	int N; /* degré/précision de l'approximation /
	int J; /* degré de l'approximation courante /
	char rep;
	do
	{
		do
		{
			printf("Entrer le réel positif A : ");
			scanf("%lf", &A);
		}
		while(A<0);
		do
		{
			printf("Entrer le degré de l'approximation : ");
			scanf("%d", &N);
		}
		while(N<=0 || N>=50);

		for(X=A, J=1 ; J<=N ; J++)
		{
			X = (X + A/X) / 2;
			printf("La %2d%s approximation de la racine carrée"
			" de %.2f est %.2f\n", J, (J==1)?"ère":"e", A, X);
		}
		printf("\nVoulez-vous continuer?(0/N) : ");
		scanf("\n%s", &rep);
	}
	while(rep=='O');
	return 0;
}*/

//Les tableaux
//somme, affichage sans zéro et avec zéro
/*#include <stdio.h>
int main()
{
	int A[20], I, somme, N, i; /*Nombre de valeurs différentes de zéro/
	do
	{
		printf("Entrez la dimension du tableau : ");
		scanf("%i", &N);
	}
	while(N<1 || N>20);
	for(I=0; I<N; I++)
	{
		printf("Élément N°%i : ", I+1);
		scanf("%i", &A[I]);
		somme+=A[I];
	}
	printf("\nLa somme des valeurs entrées est : %i", somme);
	printf("\nAffichage des valeurs avec zéro : ");
	for(I=0; I<N; I++)
		printf("%i  ", A[I]);
	printf("\nAffichage des valeurs sans zéro : ");
	for(I=0, i=0; I<N; I++)
	{
		if(A[I] != 0)
		{
			printf("%i  ", A[I]);
			i++;
		}
	}
	printf("\nIl y a %i valeurs différentes de 0 \n", i);
}*/

//Avec renversement des valeurs
/*#include<stdio.h>
int main()
{
	int A[20], I, J, N, aide;
	do
	{
		printf("Entrez la dimension du tableau : ");
		scanf("%i", &N);
	}
	while(N<1 || N>20);
	for(I=0; I<N; I++)
	{
		printf("Élément N°%i : ", I+1);
		scanf("%i", &A[I]);
	}
	printf("\n\nAffichage du tableau entré : ");
	for(I=0; I<N; I++)
		printf("%i ", A[I]);
	printf("\n\nAffichage du tableau renversé : ");
	for(I=0, J=N-1; I<J; I++, J--)
	{
		aide=A[I];
		A[I]=A[J];
		A[J]=aide;
	}
	for(I=0; I<N; I++)
		printf("%i ", A[I]);
	printf("\n");
	return 0;
}*/
//Tableau et affichage des valeurs positives et négatives
#include<stdio.h>
int main()
{
	int T[20], TPOS[20], TNEG[20];
	int N, neg, pos, I;
	do
	{
		printf("Dimension du tableau(max=20) : ");
		scanf("%i", &N);
	}
	while(N<1 || N>20);
	/*Remplissage du tableau */
	for(I=0; I<N; I++)
	{
		printf("Valeur N°%i : ", I+1);
		scanf("%i", &T[I]);
	}
	/*Affichage des valeurs entrées*/
	printf("\nValeurs entrées : ");
	for(I=0; I<N; I++)
		printf("%i ", T[I]);
	printf("\n");
	/*Affectation des valeurs positives et négatives
	respectivement à tpos et tneg*/
	neg=0; pos=0;
	for(I=0; I<N; I++)
	{
		if(T[I]<0)
		{
			TNEG[neg]=T[I];
			neg++;
		}
		if(T[I]>0)
		{
			TPOS[pos]=T[I];
			pos++;
		}
	}
	//si une valeur positives est entrée
	if(pos)
	{
		printf("\nValeurs strictement positives : ");
		for (I=0; I<pos; I++)
			printf("%i ", TPOS[I]);
		printf("\n");
	}
	//Si une valeur négative est entrée
	if(neg)
	{
		printf("\nValeurs strictement négatives : ");
		for(I=0; I<neg; I++)
			printf("%i ", TNEG[I]);
		printf("\n");
	}
	return 0;
}

//fait par les prof
/*#include <stdio.h>
main()
{
	/* Déclarations */
	/* Les tableaux et leurs dimensions /
	int T[50], TPOS[50], TNEG[50];
	int N, NPOS, NNEG;
	int I; /* indice courant */
	/* Saisie des données /
	printf("Dimension du tableau (max.50) : ");
	scanf("%d", &N );
	for (I=0; I<N; I++)
	{
		printf("Elément %d : ", I+1);
		scanf("%d", &T[I]);
	}
	/* Affichage du tableau /
	printf("Tableau donné :\n");
	for (I=0; I<N; I++)
		printf("%d ", T[I]);
	printf("\n");
	/* Initialisation des dimensions de TPOS et TNEG /
	NPOS=0;
	NNEG=0;
	/* Transfer des données /
	for (I=0; I<N; I++)
	{
		if (T[I]>0)
		{
			TPOS[NPOS]=T[I];
			NPOS++;
		}
		if (T[I]<0)
		{
			TNEG[NNEG]=T[I];
			NNEG++;
		}
	}
	/* Edition du résultat /
	printf("Tableau TPOS :\n");
	for (I=0; I<NPOS; I++)
		printf("%d ", TPOS[I]);
	printf("\n");
	printf("Tableau TNEG :\n");
	for (I=0; I<NNEG; I++)
		printf("%d ", TNEG[I]);
	printf("\n");
return 0;
}*/
