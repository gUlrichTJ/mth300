#include<stdio.h>
int main()
{
    long sum = 0;
    int a, b, i, j;
    int *P;
    int T[4][10] = {{2, 3, 4, 5},
                    {6, 7, 8, 9}, 
                    {10, 11, 12, 13}
                   };
    for ( i = 0; i < 4; i++){
        for ( j = 0; j < 4; j++)
           printf("%7i", T[i][j]);
        printf("\n");
    }
    P = (int*)T;
    for(i=0; i<30; i++)
        sum+=*(P+i);
    
    printf("The sum is : %li\n", sum);
    
    
}