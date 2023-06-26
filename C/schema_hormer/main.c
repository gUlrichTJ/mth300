#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, coef=1, fct=0, x, prod=0, i;
		printf("Entrez la valeur de X : "),
		scanf("%i", &x);
	do
	{
		printf("Entrez la valeur de n : ");
		scanf("%i", &n);
		for(i=0; i<n+1; i++)
		{
			printf("Entrez le coefficient N°%i : ", i+1);
			scanf("%i",&coef);
			prod=coef*x;
			fct+=prod;
		}
	}
	while(n<1);
	printf("f(%i) = %i", x, fct);
return 0;
}
