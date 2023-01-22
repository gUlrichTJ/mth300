#include <stdio.h>
#include <stdlib.h>

int main()
{
    int deg, I;
    int N=0;//deg
    float coef=0;
    float Tcoef[30];
    float a = 0, b = 0, Xm = 0;
    float Fa =0, Fb = 0, FXm = 0;
    float FaFb = 0, FaFXm = 0, FXmFb = 0;
    float epta = 0;
    do{
		printf("Enter the degree of the polynomial : ");
		scanf("%i", &deg);
    }
    while(deg<2);
	//Receiving coef
	for(I=0; I<=deg; I++){
		printf("Enter the coef %i : ", I+1);
		scanf("%f", &coef);
		Tcoef[I] = coef;
	}
	printf("Entrez le critere d'arret : ");
	scanf("%f", &epta);
	//Display of the polynomial
	N=deg;
	for(I=0; I<deg; I++){
		printf("(%f)*X^%i + ", Tcoef[I], N);
		N--;
	}
	printf("(%f)", Tcoef[deg]);
	//
	printf("\n\nEntrez la borne inferieure : ");
	scanf("%f", &a);
	printf("\nEntrez la borne superieure : ");
	scanf("%f", &b);

	do
	{
		//Xm
		Fa = 0; Fb = 0; FXm = 0;
		//Calculation of F(a)
		N=deg;
		for(I=0; I<=deg; I++){
			Fa += Tcoef[I]*pow(a, N);
			N--;
		}
		//Calculation of F(b)
		N=deg;
		for(I=0; I<=deg; I++){
			Fb += Tcoef[I]*pow(b, N);
			N--;
		}
		//Calculation of FXm
		N=deg;
		Xm = (a+b)/2;
		for(I=0; I<=deg; I++){
			FXm += Tcoef[I]*pow(Xm, N);
			N--;
		}

		printf("\nF(%f) = %f", a, Fa);
		printf("\nF(%f) = %f", b, Fb);
		printf("\nF(%f) = %f", Xm, FXm);
		//Fa*Fb
		FaFb = Fa*Fb;
		FaFXm = Fa*FXm;
		FXmFb = FXm*Fb;
		//Case were
		if(FaFXm<0)
			b = Xm;
		else
			a = Xm;
	}
	while((fabs(b-a) > epta) || (FXm==0)|| Fa==0);
	//Result
	printf("\n\nLa racine est %f", Xm);
	printf("\n");
    return 0;
}
