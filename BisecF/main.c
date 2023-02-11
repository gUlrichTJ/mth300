#include <stdio.h>
#include <stdlib.h>
#include<math.h>
//#include "funSys.h"
//#include "menu.h"
//#include <conio.h>
//#include "funSys.h"
//#include "funIntegrat1.h"
//#include "funInterpol1.h"
///↓↓↓↓Méthode de la bissection
//Fonction pour calculer f(alpha)
double f(double X)
{
	//return pow(X, 2)*fabs(sin(X))-4.1;
	return 4*(X*X)-X-6;
}
//Fonction pour recueillir l'intervalle
double bissection()
{
	double a,  b;
	double Xm=0;
	double i=0, epta = 0;
	//Vérification des intervalles
	do
	{
		printf("\nEntrez la borne inférieure : ");
		scanf("%lf", &a);
		printf("Entrez la borne supérieure : ");
		scanf("%lf", &b);
	}
	while(a>=b);
	//Entrer epta
	printf("Entrez le critère d'arrêt : ");
	scanf("%lf", &epta);
	//Si l'une des bornes est le résultat
	if(f(a) ==0)
		printf("\nSolution : %lf\n", a);
	else if(f(b)==0)
		printf("\nSolution : %lf\n", b);
	//S'il n'y a pas de solution dans l'intervalle
	 if(f(a)*f(b)>0) {
		printf("\nPas de solution dans cet intervalle \n");
		//Vérification
		for(i=a; i<b; i+=0.01)
			while(f(i)==0) {
				printf("\nSolutions : %lf\n", i);
				break;
			}
	}
		//Dans ce cas, il y a une solution dans l'intervalle
	else
	{
		printf("\nLa solution se trouve dans l'intervalle\n");
		do
		{
			Xm = (a+b)/2;
			if(f(Xm)==0) {
				printf("\nSolution : %lf\n", Xm);
				break;
			}
			else if(f(Xm)*f(a)<0)
			{
				//printf("\nSolution dans [%f, %f]", a, Xm);
				b = Xm;
			}
			else //if(f(Xm)*f(b)<0)
			{
				//printf("\nSolution dans [%f, %f]", Xm, b);
				a = Xm;
			}
			if((b-a)<epta) {
				printf("\nLa solution est dans l'intervalle[%f, %f]\n", a, b);
				break;
			}
		}
		while(fabs(b-a)>0.0000000001);
	}
}
///↑↑↑↑Fin de la méthode de la bissection
///↓↓↓↓Méthode des points fixes
//Calculons les trois f
float f1PointFixe(float x)
{
	return sqrt(x+6);
}
float f2PointFixe(float x)
{
	return ((x*x)-6);
}
float f3PointFixe(float x)
{
	return 6/(x-1);
}
//Corps de la méthode des points fixes
float pointFixe()
{
	float Xo, gXo = 0;
	int N, i = 0;		//Nombre maximal d'itérations et compteur du nombre
					//d'itérations
	//printf("\n		###########################");
	//printf("\n		# Méthode des points fixes#\n");
	//printf("		###########################");
	printf("\nEntrez Xo : ");
	scanf("%f", &Xo);
	//Entrée du nombre maximal d'itérations
	printf("Entrez le nombre maximal d'itérations : ");
	scanf("%i", &N);
	//Calculons g(Xo) en fonction du nombre maximal d'itérations
	do
	{
		gXo = f1PointFixe(Xo);
		Xo = gXo;
		i++;
	}
	while(i<=N);
	printf("\nSolution 1 : %f\n", Xo);
	printf("\nEntrez Xo pour la seconde solution : ");
	scanf("%f", &Xo);
	printf("Entrez le nombre maximal d'itérations : ");
	scanf("%i", &N);
    do
	{
		gXo = f3PointFixe(Xo);
		Xo = gXo;
		i++;
	}
	while(i<=N);
	printf("\nSolution 2 : %f\n", Xo);

}
///↑↑↑↑Fin de la méthode des points fixes
///↓↓↓↓Méthode de Newton
//Renvoyer ce qu'il faut
float fonctionNewton(float x)
{
	return 4*(x*x)-x-6;
}
float deriveeNewton(float x)
{
	return 2*x-1;
}
float Newton()
{
    float Xo = 0, Xn = 0;	//Xp premier élément et Xn le suivant
    long N;						//Nombre maximal d'itérations
    int i = 0;					//i vérifie si le nombre maximal d'itérations est atteint
    puts("\n####Méthode de Newton####");
    printf("Entrez Xo : ");
    scanf("%f", &Xo);
    if(deriveeNewton(Xo)==0)
		printf("\n%f annule la dérivée. Opération impossible", Xo);
	else {
		printf("Entrez le nombre maximal d'itérations : ");
		scanf("%li", &N);
		do
		{
			Xn = Xo - (fonctionNewton(Xo)/deriveeNewton(Xo));
			Xo = Xn - (fonctionNewton(Xn)/deriveeNewton(Xn));
			i++;
		}
		while(i<=N);
		printf("\nSolution : %f\n", Xn);
	}
}
///↑↑↑Fin de la méthode de Newton
///↓↓↓Méthode de la sécante
//Fonction calculant l'image de x
float fsecante(float x)
{
	return x*x-x-6;
}
//Fonction calculant l'image de la dérivée de f
float deriveeSecante(float x)
{
    return 2*x-1;
}
//principale fonction
float Secante()
{
    float Xo=0, X1 = 0, Xn = 0;
    long N;		//Nombre maximal d'itérations
    int i=0;
    puts("\n#####Méthode de la sécante####\n");
    printf("\nEntrez Xo : ");
    scanf("%f", &Xo);
    printf("Entrez X1 : ");
    scanf("%f", &X1);
    printf("Entrez le nombre maximal d'itérations : ");
    scanf("%li", &N);
    //Calcul des itérations
    do
	{
        Xn = X1 - ((fsecante(X1)*(X1-Xo))/(fsecante(X1)-fsecante(Xo)));
        Xo = X1;
        X1 = Xn;
        i++;
	}
	while(i<=N);
	printf("\nSolution %f\n", Xn);
}
///Systèmes d'équations algébriques
void Gauss()
{
	double a[20][20], u[20][20], l[20][20];
	double b[20], y[20], x[20];
	double produit=1;
	int i, j, k, n;
	//Entrée des éléments
	do {
		printf("\nEntrez la dimension du tableau : ");
		scanf("%i", &n);
	}
	while (n<2||n>20);
	//Saisie des éléments
	puts("\nEntrez les éléments de la matrice ligne par ligne\n");
	for ( i = 0; i < n; i++) {
		for ( j = 0; j < n; j++) {
			printf("Elément[%i][%i] : ", i, j);
			scanf("%lf", &a[i][j]);
			u[i][j] = a[i][j];
		}
	}
	//Saisie des éléments de droite
	puts("\nEntrez les éléments de droite\n");
	for ( i = 0; i < n; i++){
		printf("Elément b%i : ", i);
		scanf("%lf", &b[i]);
		y[i]=b[i];
	}
	for ( i = 0; i < n; i++)
		produit*=a[i][i];
	if(produit==0)
		printf("\nDésolé il y a 0 sur la diagonale\n");
	else {
	   //Factorisation et descente
		for(i=0; i<n-1; i++){
			for(k=i+1; k<n; k++){
			 //if(u[i][i]!=0){
				l[k][i]=(u[k][i]/u[i][i]);
			//}
				for(j=i+1; j<n; j++){
					u[k][j]-=l[k][i]*u[i][j];
				}
				y[k]-=l[k][i]*y[i];
			}
		}
		//Remontée
		x[n-1]=y[n-1]/u[n-1][n-1];
		for(i=n-2; i>=0; i--) {
			x[i]=y[i];
			for(j=i+1; j<n; j++) {
				x[i]-=u[i][j]*x[j];
			}
			x[i]=(1/u[i][i])*x[i];
		}
		//Affichage des matrices
		puts("\nMatrice triangularisée\n");
		for(i=0; i<n; i++) {
			for(j=0; j<n; j++)
				printf("%15lf", u[i][j]);
		  printf("\n");
		}
		puts("\nMatrice triangularisée l\n");
		for(i=0; i<n; i++){
			for(j=0; j<n; j++)
				printf("%15lf", l[i][j]);
		  printf("\n");
		}
		puts("\nYi\n");
		for (i=0; i<n; i++){
			printf("%15lf", y[i]);
		}
		puts("\nMatrice solution\n");
		for(i=0; i<n; i++){
			printf("%15lf", x[i]);
		}
	}
	printf("\n");
}

void luCrout()
{
    int I, J, k, N;
    double L[20][20], U[20][20], T[20][20];
    double y[20], x[20], b[20];
    double produitDiag=1, somme=0;
	//Entrée de la matrice
	do
		{
		printf("\nEntrez la dimension du tableau : ");
		scanf("%i", &N);
	}
	while(N<2||N>20);
	///Entrée des éléments
    for(I=0; I<N; I++){
		for(J=0; J<N; J++){
			printf("Element [%i][%i] : ", I, J);
			scanf("%lf", &T[I][J]);
		}
	}
	//Entrée des bi
	puts("\nEntrez les éléments de droite\n");
	for (I=0; I<N; I++){
		printf("Entrez b%i : ", I+1);
		scanf("%lf", &b[I]);
	}
    //Multiplication des diagonales
    for(I=0; I<N; I++) {
		for(J=0; J<N; J++) {
			if(I==J) {
				produitDiag*=T[I][J];
			}
		}
    }
	//Si le produit des diagonales est nul, la matrice n'est pas inversible
	if(produitDiag==0)
		printf("\nDésolé!! Il y a un zéro sur la diagonale\n");
	else {
		//Initialisation de la diagonale de U a 1
		for(I=0; I<N; I++) {
			for(J=0; J<N; J++) {
				if (I==J) {
					U[I][J]=1;
				}
			}
		}
		//Calcul des éléments de la premiere colonne de L
		for(I=0; I<N; I++)
			L[I][0]=T[I][0];
		//Calcul des éléments de la premiere ligne de U
		for(J=1; J<N; J++)
			U[0][J]=(T[0][J]/L[0][0]);

		for(I=1; I<N; I++) {
			//Calcul du pivot
			somme=0;
				for(k=0; k<I-1; k++)
					somme+=L[I][k]*U[k][I];
				L[I][I] = T[I][I]-somme;
			//Merci Seigneur Jesus. Merci beaucoup Seigneur Jesus
			//Calcul des ième colonnes et lignes
			for(J=I+1; J<N; J++) {
				//calcul de la ieme colonne de L
				somme=0;
				for (k=0; k<I-1; k++)
					somme+=L[J][k]*U[k][I];
				L[J][I] = T[J][I]-somme;
				//Calcul de la ieme ligne de U
				somme=0;
				for (k=0; k<I-1; k++)
					somme+=L[I][k]*U[k][J];
				U[I][J]=(T[I][J]-somme)/L[I][I];
			//Mc SJ
			}
		}
		//Calcul de Lnn
		somme=0;
		for (k=0; k<N-1; k++)
			somme+=L[N-1][k]*U[k][N-1];
		L[N-1][N-1] = T[N-1][N-1] - somme;
		//Descentes et remontées triangulaires
		//Descente triangulaire pour resoudre Ly=b
		y[0] = b[0]/L[0][0];
		for (I=1; I<N; I++){
			somme=0;
			for (k=0; k<I-1; k++)
				somme+=L[I][k]*y[k];
			y[I]=(b[I]-somme)/L[I][I];
		}
		//Remontée triangulaire pour resoudre Ux=y
		x[N-1] = y[N-1];
		for (I=N-2; I>=0; I--){
			somme=0;
			for (k=I+1; k<N; k++)
				somme+=U[I][k]*x[k];
			x[I] = y[I]-somme;
		}
		//Affichage des matrices
		puts("\nL");
		for(I=0; I<N; I++) {
			for(J=0; J<N; J++)
				printf("%15lf", L[I][J]);
			printf("\n");
		}
		puts("\nU");
		for(I=0; I<N; I++) {
			for(J=0; J<N; J++)
				printf("%15lf", U[I][J]);
			printf("\n");
		}
		puts("\nYi");
		for (I=0; I<N; I++)
			printf("%15lf", y[I]);
		puts("\n\nSolutions Xi");
		for (I=0; I<N; I++){
			printf("%15lf", x[I]);
		}
	}
	printf("\n");
}
///Doolittle
#include<stdio.h>
#include<stdlib.h>
void luDoolittle() {
	double a[20][20], u[20][20], l[20][20];
	double b[20], y[20], x[20];
	double somme=0;
	int i, j, k, n;
	//Entree du nombre maximal d'elements
	do {
		printf("\nEntrez la dimension du tableau : ");
		scanf("%i", &n);
	}
	while (n<2||n>20);
	//Saisie des elements
	puts("\nEntrez les elements de la matrice ligne par ligne\n");
	for ( i = 0; i < n; i++) {
		for ( j = 0; j < n; j++) {
			printf("Elément[%i][%i] : ", i, j);
			scanf("%lf", &a[i][j]);
			u[i][j]=a[i][j];
		}
	}
	//Saisie des elements de droite
	puts("\nEntrez les elements de droite\n");
	for ( i = 0; i < n; i++) {
		printf("Elément b%i : ", i);
		scanf("%lf", &b[i]);
	}
	//1 Factorisation
	for(i=0; i<n-1; i++) {
		for(k=i+1; k<n; k++) {
			if(u[i][i]!=0) {
				l[k][i]=(u[k][i]/u[i][i]);
				for(j=i+1; j<n; j++) {
					u[k][j]-=l[k][i]*u[i][j];
				}
			}
		}
	}
	//Mettre des 1 sur la diagonale de L
	for ( i = 0; i < n; i++) {
		l[i][i]=1;
	}
	//Mettre à 0 les éléments de U pour i supérieur à j
	for (i=0; i<n; i++) {
		for (j = 0; j < n; j++) {
			if (i>j) {
				u[i][j]=0;
			}
		}
	}
	//Descente en calculant y avec Ly=b
	for(i=0; i<n; i++) {
		somme=0;
		for(k=0; k<i; k++) {
			somme+=l[i][k]*y[k];
		}
		y[i]=b[i]-somme;
	}
	//Remontee on calcule x avec Ux=y
	for(i=n-1; i>=0; i--) {
		somme=0;
		for(j=i+1; j<n; j++)
			somme+=u[i][j]*x[j];
		x[i]=(1/u[i][i])*(y[i]-somme);
	}
	//Affichage des matrices
	puts("\nL");
	for(i=0; i<n; i++) {
		for(j=0; j<n; j++)
			printf("%15lf", l[i][j]);
		printf("\n");
	}
	puts("\nU");
	for(i=0; i<n; i++) {
		for(j=0; j<n; j++)
			printf("%15lf", u[i][j]);
		printf("\n");
	}
	///Merci Seigneur Jesus-Christ
	//Affichage des Yi
	puts("\nYi");
	for(i=0; i<n; i++)
		printf("%15lf", y[i]);
	//Affichage des solutions
	puts("\nXi");
	for(i=0; i<n; i++)
			printf("%15lf", x[i]);
	printf("\n");
}

///Lu pivot partiel
void luPivotPartiel() {
	double a[20][20], u[20][20], l[20][20];
	double b[20], y[20], x[20];
    int t[20];
	double somme=0, max=0, p=0;
	int i, j, k, n, ie;
	//Entree du nombre maximal d'elements
	do {
		printf("\nEntrez la dimension du tableau : ");
		scanf("%i", &n);
	}
	while (n<2|| n>20);
	//Saisie des elements
	puts("\nEntrez les elements de la matrice ligne par ligne\n");
	for ( i = 0; i < n; i++) {
		for ( j = 0; j < n; j++) {
			printf("Elément[%i][%i] : ", i, j);
			scanf("%lf", &a[i][j]);
			u[i][j]=a[i][j];
		}
	}
	//Saisie des elements de droite
	puts("\nEntrez les elements de droite\n");
	for ( i = 0; i < n; i++) {
		printf("Elément b%i : ", i);
		scanf("%lf", &b[i]);
	}
    //Initialisation
    for(i=0; i<n; i++)
        t[i]=i;
    //Factorisation
    for(i=0; i<n; i++) {
        max=a[i][i];
        //Recherche de i*
        for(k=i; k<n; k++){
            if(fabs(a[k][i]>fabs(max))){
                ie=k;
                max=a[k][i];
                //Permutation
                p=t[ie];
                t[ie]=t[i];
                t[i]=p;
            }
            //On ne change pas la ligne t(i)
            for(j=i; j<n; j++){
                u[t[i]][j]=a[t[i]][j];
            }
        }
        //on modifie les lignes t(k), k>i
        for(k=i+1; k<n; k++) {
            l[t[k]][i]=(a[t[k]][i]/a[t[i]][i]);
            for(j=i+1; j<n; j++) {
                a[t[k]][j]-=l[t[k]][i]*u[t[i]][j];
            }
        }
        //Merci Seigneur Jesus-Christ
    }
    //Descente: on calcule y
    for(i=0; i<n; i++) {
        somme=0;
        for(j=0; j<i; j++){
            somme+=l[t[i]][j]*y[j];
        }
        y[i]=b[t[i]]-somme;
    }
    //Remontee on calcule x
    for(i=n-1; i>=0; i--) {
        somme=0;
        for(j=i; j<n; j++) {
            somme+=u[t[i]][j]*x[j];
        }
        x[i]=(1/u[t[i]][i])*(y[i]-somme);
    }
    //Affichage des tableaux
    puts("\nTab A\n");
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++)
            printf("%14lf", a[i][j]);
        printf("\n");
    }
    printf("\n");
    puts("\nTab U\n");
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++)
            printf("%14lf", u[i][j]);
        printf("\n");
    }
    printf("\n t[i]");
    for(i=0; i<n; i++)
        printf("%14i", t[i]);
    printf("\n");
    //tab y
    printf("\n Y[i]");
    for(i=0; i<n; i++)
        printf("%14lf", y[i]);
    printf("\n");
    //tab xi
    printf("\nSolutions x[i]");
    for(i=0; i<n; i++)
        printf("%14lf", x[i]);
    puts("\n");
}

///Fonction principale
int main()
{
	int choix;
    ///↓↓↓Menu↓↓↓
    puts("\nEntrez : ");
    puts("1 pour la méthode de la bissection ");
    puts("2 pour la méthode des points fixes ");
    puts("3 pour la méthode de Newton ");
    puts("4 pour la méthode de la sécante ");
    puts("\nSystemes d'équations linéaires\n");
    puts("5 pour la méthode d'élimination de Gauss sans permutation");
    puts("6 pour la décomposition LU de Crout");
    puts("7 pour la décomposition LU de Doolittle");
    puts("8 pour la décompositon LU avec pivot partiel");
    do{
		printf("\nEntrez votre choix : ");
		scanf("%i", &choix);
	}
	while(choix<1 || choix>12);
	//propositions
    switch(choix)
    {
    	case 1 :
    		puts("\nMethode de la bissection\n");
			bissection();
			break;
		case 2 :
			puts("\nMéthode des points fixes\n");
			pointFixe();
			break;
		case 3 :
			puts("Méthode de Newton\n");
			Newton();
			break;
		case 4 :
			puts("\nMethode de la sécante\n");
			Secante();
			break;
		case 5 :
			puts("\nMéthode de Gauss");
			Gauss();
			break;
		case 6:
			puts("\nCrout\n");
			luCrout();
			break;
		case 7:
			puts("\nDoolittle\n");
			luDoolittle();
			break;
		case 8:
            luPivotPartiel();
            break;
    }
    return 0;
}
