#include<stdio.h>
int main(){
   int t[50], tpos[50], tneg[50];
   int i, j, n, aide = 0;
   int pos = 0, neg = 0;
   int tab[50][50];
   int L=0, C=0, somme =0;
   do{
      printf("\nEnter the dimension of the board : ");
      scanf("%i", &n);
   }
   while (n<2 || n>49);
   for ( i = 0; i < n; i++)
   {
      printf("Element %i : ", i+1);
      scanf("%i", &t[i]);
   }
   printf("\nGiven table : ");
   for ( i = 0; i < n; i++)
        printf("%i ", t[i]);
    printf("\n");
    //affichage dans l'ordre inverse
    for( i = 0, j=n-1; i < j; i++, j--)
        {
            aide = t[i];
            t[i] = t[j];
            t[j] = aide;
        }
    printf("\nInversed table : ");
    for( i = 0; i < n; i++)
        printf("%i ", t[i]);
    putchar('\n');
    //Copie des valeurs dans tpos et tneg
    for( i = 0; i < n; i++)
        {
            if(t[i]<0)
                {
                    tneg[neg] = t[i];
                    neg++;
                }
            if(t[i]>0)
                {
                    tpos[pos] = t[i];
                    pos++;
                }
        }
    if(pos)
    {
        printf("\nValeurs positives  : ");
        for(i=0; i<pos; i++)
            printf("%i ", tpos[i]);
    }
    if(neg){
        printf("\nValeurs negatives : ");
        for(i=0; i<neg; i++)
            printf("%i ", tneg[i]);
        putchar('\n');
    }
    //Tableau a deux dimensions
    do{
        printf("\nNombre de lignes : ");
        scanf("%i", &L);
    }
    while(L<2 || L>50);
    do{
        printf("\nNombre de colonnes : ");
        scanf("%i", &C);
    }
    while(C<2 || C>50);
    //Entree des elements
    for(i=0; i<L; i++)
        {
          for(j=0; j<C; j++)
                {
                 printf("Element [%i][%i] : ", i, j);
                 scanf("%i", &tab[i][j]);
                }
        }
    putchar('\n');
    //Affichage du tableau
    for(i=0; i<L; i++)
    {
        for(j=0; j<C; j++)
            printf("%7i", tab[i][j]);
        putchar('\n');
    }
    //Affichage de la somme ligne par ligne et colonne par colonne
    for(i=0; i<L; i++){
        somme = 0;
        for(j=0; j<C; j++){
            somme+=tab[i][j];
        }
        printf("Somme de la ligne %i = %i\n", i, somme);
    }
}
