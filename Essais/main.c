//Essai repère
#include <stdio.h>
#include <stdlib.h>
#include<math.h>

//Fonction
double fBis(double x)
{
	return (x*x*x)+(4*x*x)-10;
    //return pow(x, 2)*fabs(sin(x))-4.1;
    //return pow(x, 6)-x-1;
    //return (x*x)*(x*x)*(x*x)-(x)-1;
	//return (1-0.61*x)/x;
	//return exp(x)-3*x*x;
}
double bissection()
{
	double a, b, Xm = 0, epta = 0;		//Critère d'arrêt
	long N, i=0;
	do
	{
		printf("\nEntrez la borne inférieure de l'intervalle : ");
		scanf("%lf", &a);
		printf("\nEntrez la borne supérieure de l'intervalle : ");
		scanf("%lf", &b);
	}
	while(b<=a);
	printf("\nEntrez le nombre maximal d'itérations : ");
	scanf("%li", &N);
	printf("\nEntrez le critère d'arrêt : ");
	scanf("%lf", &epta);
    if(fBis(a)==0)
		printf("\nSolution : %lf", a);
	else if(fBis(b)==0)
		printf("\nSolution : %lf", b);
    if(fBis(a)*fBis(b)>0)
	{
        printf("\nf(%f)xf(%f)>0", a, b);
	}
	else
	{
        do
        {
            Xm = (a+b)/2;
            if(fBis(Xm)==0){
				printf("\nSolution : %f\n", Xm); break; }

			else if(fBis(a)*fBis(Xm)<0)
                b = Xm;
			else
				a = Xm;
			//i++;
			if(fabs(b-a)<=epta)
			{
				printf("\nLa solution est dans l'intervalle [%f, %f]\n", a, b);
				break;
			}
        }
        //while(i<=N);
        while(b-a>0.00000000000000000001);
	}
}
int main()
{
	bissection();
    //PointFixe();
    return 0;
}
