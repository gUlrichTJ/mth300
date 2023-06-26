
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matrice.h"




void saisir_matrice(double *T,int l,int c)

{
    int i,j;
    for(i=0; i<l; i++)
    {
        for(j=0; j<c; j++)
        {
            printf("\n[%d][%d] :",i+1,j+1);
            scanf("%lf",T+i*c+j);
        }
    }
}
void afficher_matrice(float A[100][100], int n)
{
    /* Variables locales */
    int I,J;
    /* Affichage des composantes de la matrice */
    for (I=0; I<n; I++)
    {
        for (J=0; J<n; J++){
            printf("%7f\t", A[I][J]);
        }
        printf("\n");
    }
}

void permuter(double *A,int l1,int l2,int l,int c)
{
    int i,j;
    double* temp=NULL;
    for(i=0; i<l; i++)
    {
        for(j=0; j<c; j++)
        {
            *(temp+i*c+j)=*(A + i*c + j);
        }
    }
    i=l1;
    for(j=0; j<c; j++)
    {
        *(A + i*c + j)=*(A + l2*c + j);
    }
    i=l2;
    for(j=0; j<c; j++)
    {
        *(A + i*c + j)=*(temp + l1*c + j);
    }
}

/* Méthode d'élimination de Gauss */

float * * malloc2 ( int rows, int cols )
{
    float * * ptr = ( float * * ) malloc ( sizeof ( float * ) * rows + sizeof ( float ) * cols * rows ) ;
    float *   dat = ( float *   ) ( ptr + rows ) ;
    int i ;
    if ( ptr == NULL )
        exit( EXIT_FAILURE ) ;
    for ( i = 0 ; i < rows ; ++ i, dat += cols )
        ptr [ i ] = dat ;
    return ptr ;
}

/* Saisie des éléments de la matrice A */
void saisie_mat(float **A,int n)
{
    int i, j,code ;
    printf(" ===>Saisie de la matrice : \n\n\n");

    for(i = 0 ; i < n ; i++)
    {
        for( j = 0 ; j < n ; j++)
        {
            do
            {
                printf("  A[%d][%d] : ",i+1,j+1);
                code=scanf("%f",&A[i][j]);
                fflush(stdin);
            }
            while(code==0);
        }
        printf("\n");
    }
}

/* Saisie des éléments de la matrice B */
void saisie_vect(float *b,int n)
{
    int i,code ;
    printf(" ===>Saisie du vecteur : \n\n\n");

    for(i = 0 ; i < n ; i++)
    {
        do
        {
            printf("  b[%d] : ",i+1);
            code=scanf("%f",&b[i]);
            fflush(stdin);
        }
        while(code==0);
        printf("\n");
    }
}

/* Affichage du système */
void affich_systeme(float **A,float *b,int n)
{
    int i, j ;
    printf(" ===>Affichage du systeme : \n\n\n");

    for(i = 0 ; i < n ; i++)
    {
        printf("  (");
        for(j = 0 ; j < n ; j++)
        {
            printf("  %.3f  ",A[i][j]);
        }
        printf(" )    (X%d)   =",i+1);
        printf("\t%.3f",b[i]);
        printf("\n\n");
    }
}

/* Affichage de la solution du système */
void affich_sol(float *x, int n)
{
    int i ;
    printf(" ===>Affichage de la solution : \n\n\n");

    for(i = 0 ; i < n ; i++)
    {
        printf("(X%d)   =",i+1);
        printf("\t%.6f",x[i]);
        printf("\n\n");
    }
}

/* Méthode d'élimination de Gauss */
void gauss(float **A, float *b, float *x, int n)
{
    int i, j, k ;
    int imin ;
    float p ;
    float sum, valmin, tump1, tump2 ;

    for(k = 0 ; k < n-1 ; k++)
    {
        /* Dans un premier temps, on cherche l'élément minimum (non */
        /* nul) en valeur absolue dans la colonne k et d'indice i   */
        /* supérieur ou égal à k.                                   */

        valmin = A[k][k] ;
        imin = k ;
        for(i = k+1 ; i < n ; i++)
        {
            if (valmin != 0)
            {
                if (abs(A[i][k]) < abs(valmin) && A[i][k] != 0)
                {
                    valmin = A[i][k] ;
                    imin = i ;
                }
            }
            else
            {
                valmin = A[i][k] ;
                imin = i ;
            }
        }

        /* Si l'élément minimum est nul, on peut en déduire */
        /* que la matrice est singulière. Le programme est   */
        /* alors interrompu.                                */

        if (valmin == 0.)
        {
            printf("\n\n\nLa matrice entrée n'est pas singulière!\n\n\n") ;
            exit( EXIT_FAILURE ) ;
        }

        /* Si la matrice n'est pas singulière, on inverse    */
        /* les éléments de la ligne imax avec les éléments   */
        /* de la ligne k. On fait de même avec le vecteur b. */

        for(j = 0 ; j < n ; j++)
        {
            tump1 = A[imin][j] ;
            A[imin][j] = A[k][j] ;
            A[k][j] = tump1 ;
        }

        tump2 = b[imin] ;
        b[imin] = b[k] ;
        b[k] = tump2 ;


        /* On procède à la réduction de la matrice par la */
        /* méthode d'élimination de Gauss. */

        for(i = k+1 ; i < n ; i++)
        {
            p = A[i][k]/A[k][k] ;

            for(j = 0 ; j < n ; j++)
            {
                A[i][j] = A[i][j] - p*A[k][j] ;
            }

            b[i] = b[i] - p*b[k] ;
        }
    }

    /* On vérifie que la matrice n'est toujours pas singulière. */
    /* Si c'est le cas, on interrompt le programme. */

    if (A[n-1][n-1] == 0)
    {
        printf("\n\n\nAttention! Matrice singuliere!\n\n\n") ;
        exit( EXIT_FAILURE ) ;
    }

    /* Une fois le système réduit, on obtient une matrice triangulaire */
    /* supérieure et la résolution du système se fait très simplement. */

    x[n-1] = b[n-1]/A[n-1][n-1] ;

    for(i = n-2 ; i > -1 ; i--)
    {
        sum = 0 ;

        for(j = n-1 ; j > i ; j--)
        {
            sum = sum + A[i][j]*x[j] ;
        }
        x[i] = (b[i] - sum)/A[i][i] ;
    }
}

/*.......methode de gauss jordan.................*/
void gauss_jordan(float **A, float *b, float *x, int n)
{
    int i, j, k ;
    int imin,m ;
    float p ;
    float sum, valmin, tump1, tump2 ;

    for(k = 0 ; k < n-1 ; k++)
    {
        /* Dans un premier temps, on cherche l'élément minimum (non */
        /* nul) en valeur absolue dans la colonne k et d'indice i   */
        /* supérieur ou égal à k.                                   */

        valmin = A[k][k] ;
        imin = k ;
        for(i = k+1 ; i < n ; i++)
        {
            if (valmin != 0)
            {
                if (abs(A[i][k]) < abs(valmin) && A[i][k] != 0)
                {
                    valmin = A[i][k] ;
                    imin = i ;
                }
            }
            else
            {
                valmin = A[i][k] ;
                imin = i ;
            }
        }

        /* Si l'élément minimum est nul, on peut en déduire */
        /* que la matrice est singulière. Le programme est   */
        /* alors interrompu.                                */

        if (valmin == 0.)
        {
            printf("\n\n\nLa matrice entrée n'est pas singuliere!\n\n\n") ;
            exit( EXIT_FAILURE ) ;
        }

        /* Si la matrice n'est pas singulière, on inverse    */
        /* les éléments de la ligne imax avec les éléments   */
        /* de la ligne k. On fait de même avec le vecteur b. */

        for(j = 0 ; j < n ; j++)
        {
            tump1 = A[imin][j] ;
            A[imin][j] = A[k][j] ;
            A[k][j] = tump1 ;
        }

        tump2 = b[imin] ;
        b[imin] = b[k] ;
        b[k] = tump2 ;


        /* On procède à la réduction de la matrice par la */
        /* méthode d'élimination de Gauss. */

        for(i = k+1 ; i < n ; i++)
        {
            p = A[i][k]/A[k][k] ;

            for(j = 0 ; j < n ; j++)
            {
                A[i][j] = A[i][j] - p*A[k][j] ;
            }

            b[i] = b[i] - p*b[k] ;
        }
    }
    printf("\n le systeme initiale ");

    affich_systeme(A,b,n) ;
    /*trouver des 1 sur la diagonale*/
    for(i=0; i<n; i++)
    {
        b[i] = b[i]/A[i][i];
        for(j=i+1; j<n; j++)
        {
            A[i][j] =    A[i][j]/A[i][i];
            printf("\n ==>  %f",A[i][j]);
        }
        A[i][i]=A[i][i]/A[i][i];
    }
    printf("\n le systeme avec les 1");
    affich_systeme(A,b,n) ;


    for(i=n-1; i>0; i--)
    {
        for(m=i+1; m<n ; m++)
        {
            b[i]=b[i]-A[i][m]*b[m];

            for(j=i+1; j<n; j++)
            {
                /* A[i][j] = A[i][j] - A[i][m]*A[m][j] ;*/
                A[i][j]=0;
            }

        }

    }
    printf("\n le systeme diagonal 1,1...1");


    /* On vérifie que la matrice n'est toujours pas singulière. */
    /* Si c'est le cas, on interrompt le programme. */

    if (A[n-1][n-1] == 0)
    {
        printf("\n\n\nLa  matrice entrée n'est pas singuliere!\n\n\n") ;
        exit( EXIT_FAILURE ) ;
    }

    /* Une fois le système réduit, on obtient une matrice triangulaire */
    /* supérieure et la résolution du système se fait très simplement. */

    x[n-1] = b[n-1]/A[n-1][n-1] ;

    for(i = n-2 ; i > -1 ; i--)
    {
        sum = 0 ;

        for(j = n-1 ; j > i ; j--)
        {
            sum = sum + A[i][j]*x[j] ;
        }
        x[i] = (b[i] - sum)/A[i][i] ;
    }

}

/* ..........decomposition LU.................;*/
void LU(float **A, float *b, /*float *x,*/ int n)
{
    int i,j;
    float **L = NULL, **U = NULL ;
    int k;


    int imin ;
    float sum, valmin, tump1, tump2 ;

    for(k = 0 ; k < n-1 ; k++)
    {
        /* Dans un premier temps, on cherche l'élément minimum (non */
        /* nul) en valeur absolue dans la colonne k et d'indice i   */
        /* supérieur ou égal à k.                                   */

        valmin = A[k][k] ;
        imin = k ;
        for(i = k+1 ; i < n ; i++)
        {
            if (valmin != 0)
            {
                if (abs(A[i][k]) < abs(valmin) && A[i][k] != 0)
                {
                    valmin = A[i][k] ;
                    imin = i ;
                }
            }
            else
            {
                valmin = A[i][k] ;
                imin = i ;
            }
        }

        /* Si l'élément minimum est nul, on peut en déduire */
        /* que la matrice est singulière. Le programme est   */
        /* alors interrompu.                                */

        if (valmin == 0.)
        {
            printf("\n\n\n La matrice entrée n'est pas singuliere!\n\n\n") ;
            exit( EXIT_FAILURE ) ;
        }

        /* Si la matrice n'est pas singulière, on inverse    */
        /* les éléments de la ligne imax avec les éléments   */
        /* de la ligne k. On fait de même avec le vecteur b. */

        for(j = 0 ; j < n ; j++)
        {
            tump1 = A[imin][j] ;
            A[imin][j] = A[k][j] ;
            A[k][j] = tump1 ;
        }

        tump2 = b[imin] ;
        b[imin] = b[k] ;
        b[k] = tump2 ;


        printf("\n voici la matrice perm :");
        affich_systeme(A,b,n);


        /* On procède à la réduction de la matrice par la */
        /* méthode d'élimination de Gauss. */

        /*for(d=0; d<n; d++)
        {
         for(e=0; e<n; e++)
         {
             if(e<=d)
             {
                 U[e][d]=A[e][d];
                 for(f=0; f<e-1; f++)
                     U[e][d]-=L[e][f]*U[f][d];
                 if(e==d)
                     L[e][d]=1;
                 else
                     L[e][d]=0;
             }
             else
             {
                 L[e][d]=A[e][d];
                 for(f=0; f<=d-1; f++)
                     L[e][d]-=L[e][f]*U[f][d];
                 L[e][d]/=U[d][d];
                 U[e][d]=0;
             }
         }
        }*/
    }
    /* traitement de la premiere ligne de L et la premiere colonne de U*/
    for(i=0; i<n; i++)
    {
        L[i][1]= A[i][1];
        U[1][i]=A[1][i]/A[1][1];
    }
    /*traitement de la diagonale de U*/
    for(i=0; i<n; i++)
    {
        U[i][i]= 1;
    }
    /*traitement de la diagonale de L */
    for(i=1; i<n; i++)
    {
        sum=0;
        for(k=0; k<i-1; k++)
        {
            sum=sum + L[i][k]*U[k][i];
        }
        L[i][i] = A[i][i] - sum;
    }
    /*traitement des autres elements de L*/
    for(i=0; i<n; i++)
    {
        for(j=1; j<n; j++)
        {
            if(i>j)
            {
                sum=0;
                for(k=0; k<j-1; k++)
                {
                    sum= sum + L[i][k]*U[k][i];
                }
                L[i][j]=A[i][j] - sum;
            }
        }
    }
    /*traitement des zeros de L et de U*/
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(j<i)
            {
                U[i][j]=0;
            }
            else
            {
                L[i][j]=0;
            }
        }
    }
    /*traitement des autres elements de U*/
    for(i=1; i<n-1; i++)
    {
        for(j=0; j<n; j++)
        {
            if(i<j)
            {
                sum=0;
                for(k=0; k<i-1; k++)
                {
                    sum= sum + L[i][k]*U[k][j];
                }
                U[i][j] = ( A[i][j]- sum )/ A[i][i];
            }
        }
    }


}
/*lu final retenu par thierry*/

void lu()
{





    int imin ;

    float sum, valmin, tump1, tump2 ;
    float A[100][100],L[100][100],U[100][100];
    float b[100],X[100],Y[100];
    int i,j,k,n;
    printf("Entrer la dimension de la matrice: ");
    scanf("%d",&n);
    printf("\nEntrer les elements:\n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("Entrer A[%d][%d] : ",i+1,j+1);
            scanf("%f",&A[i][j]);
        }
    }
    printf("\nEntrer le vecteur b: \n");
    for(i=0; i<n; i++)
    {
        printf("b[%d] :",i);
        scanf("%f",&b[i]);
    }
    /*traitement des pivots*/

    for(k = 0 ; k < n-1 ; k++)
    {
        /* Dans un premier temps, on cherche l'élément minimum (non */
        /* nul) en valeur absolue dans la colonne k et d'indice i   */
        /* supérieur ou égal à k.                                   */

        valmin = A[k][k] ;
        imin = k ;
        for(i = k+1 ; i < n ; i++)
        {
            if (valmin != 0)
            {
                if (abs(A[i][k]) < abs(valmin) && A[i][k] != 0)
                {
                    valmin = A[i][k] ;
                    imin = i ;
                }
            }
            else
            {
                valmin = A[i][k] ;
                imin = i ;
            }
        }

        /* Si l'élément minimum est nul, on peut en déduire */
        /* que la matrice est singulière. Le programme est   */
        /* alors interrompu.                                */

        if (valmin == 0.)
        {
            printf("\n\n\nLa matrice entrée n'est pas singulière!\n\n\n") ;
            exit( EXIT_FAILURE ) ;
        }

        /* Si la matrice n'est pas singulière, on inverse    */
        /* les éléments de la ligne imax avec les éléments   */
        /* de la ligne k. On fait de même avec le vecteur b. */

        for(j = 0 ; j < n ; j++)
        {
            tump1 = A[imin][j] ;
            A[imin][j] = A[k][j] ;
            A[k][j] = tump1 ;
        }

        tump2 = b[imin] ;
        b[imin] = b[k] ;
        b[k] = tump2 ;


        /* On procède à la réduction de la matrice par la */
        /* méthode d'élimination de Gauss. */


    }


    for(j=0; j<n; j++)
    {
        for(i=0; i<n; i++)
        {
            if(i<=j)
            {
                U[i][j]=A[i][j];
                for(k=0; k<i-1; k++)
                    U[i][j]-=L[i][k]*U[k][j];
                if(i==j)
                    L[i][j]=1;
                else
                    L[i][j]=0;
            }
            else
            {
                L[i][j]=A[i][j];
                for(k=0; k<=j-1; k++)
                    L[i][j]-=L[i][k]*U[k][j];
                L[i][j]/=U[j][j];
                U[i][j]=0;
            }
        }
    }
    printf("[L]: \n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
            printf("%9.3f",L[i][j]);
        printf("\n");
    }
    printf("\n\n[U]: \n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
            printf("%9.3f",U[i][j]);
        printf("\n");
    }
    Y[1]=b[1];
    for(i=1; i<n; i++)
    {
        for(j=0; j<i-1; j++)
        {
            sum=0;
            for(k=0;k<i-1;k++){
                sum=sum+L[i][k];
            }
            Y[i]=b[i]-sum;
        }
    }
    printf("\n\n[Y]: \n");
    for(i=0; i<n; i++)
    {
        printf("%9.3f",Y[i]);
    }
    for(i=n-1; i>=0; i--)
    {
        X[i]= Y[i];
        for(j=i+1; j<n; j++)
        {
            X[i]-=U[i][j]*X[j];
        }
        X[i]/=U[i][i];
    }
    printf("\n\n[X]: \n");
    for(i=0; i<n; i++)
    {
        printf("%9.3f",X[i]);
    }
}





/*..............algo de cholesky..........................*/
/*void cholesky(){
     float *x=NULL;
    float sum;
    float A[100][100],L[100][100],aide[100][100],AIDE;
    float b[100];
    int i,j,k,n;
    printf("Entrer la dimension de la matrice: ");
    scanf("%d",&n);
    printf("\nEntrer les elements:\n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("Entrer A[%d][%d] : ",i+1,j+1);
            scanf("%f",&A[i][j]);
        }
    }
    printf("\nEntrer le vecteur b: \n");
    for(i=0; i<n; i++)
    {
        printf("b[%d] :",i);
        scanf("%f",&b[i]);
    }*/
    /*traitement des pivots*/

    /*for(k=0;k<n;k++){
        if(A[k][k]<=0){
            printf("\n la matrice n'est pas probablement symétrique ou définie positive\n\n\n\n");
            exit(EXIT_FAILURE);
        }
    }
    printf("\n cholesky peut s'appliquer à votre matrice ");
    L[0][0] = sqrt(A[0][0]);
    for(i=1;i<n;i++){
        L[i][0]=A[i][0]/L[0][0];
    }
    for(k=1;k<n;k++){
            sum=0;
            for(j=0;j<k-1;j++){
                sum=sum+ L[k][j]*L[0][0];
            }
            L[k][k]=sqrt(A[k][k]-sum);

            for(i=k+1;i<n;i++){
                    sum=0;
                for(j=0;j<k-1;j++){
                    sum=sum+L[i][j]*L[k][j];
                }
                L[i][k]= (A[i][k]-sum)/L[k][k];
            }
    }

    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++){
                if(i<j){
                    A[i][j]=0;
                }
        }
    }*/

/*...............afficher la matrice L.........*/
    /* printf("[L]: \n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
            printf("%9.3f",L[i][j]);
        printf("\n");
    }

     for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++){
            aide[i][j]=L[i][j];
        }

    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            AIDE=A[i][j];
            A[i][j]=A[j][i];
            A[j][i]=AIDE;
        }
    }
    printf("\n la matrice transposée de L est :\n");


    for(i=0; i<n; i++)
    {
       for(j=0; j<n; j++)
            printf("%9.3f",L[i][j]);
        printf("\n");

    }
    i=aide[0][0];

}*/

void int_lagr(){
    float num,deno;
    float I[100],x[100],y[100];
    int i,j,n;
    float Y;

    printf("\nveuillez entrer le degré : ");
    scanf("%d",&n);
    //saisi des points
    printf("saisir les coordonnées des points\n");
    for(i=1;i<=n;i++)
    {
        printf("saisir x(%d)\ty(%d)\n",i,i);
        scanf("%f%f",&x[i],&y[i]);
    }
    printf("le polynome obtenue est :");
    for(j=0;j<n;j++)
    {
        num=1;
        deno=1;
        for(i=0;i<n;i++)
        {
            if(j!=i)
            {
                num = num*(x[i]);
                deno = deno*(1/(x[i]-x[j]));
            }
        }
        //I[j] = num*deno;
        Y =Y+I[j]*y[j];
        if(num>0)

        {
            printf("(x - %.2f)*(%.2f)+",num,deno*y[j]);
        }
        else
            printf("(x  + %.2f)*(%.2f)+",-num,deno*y[j]);

    }
}

void int_lagr2(){
    float x[100],y[100];
    int i,j,n;

     printf("\nveuillez entrer le degré : ");
    scanf("%d",&n);

    printf("saisir les coordonnées des points\n");
    for(i=0;i<n+1;i++)
    {
        printf("saisir x(%d)\ty(%d)\n",i+1,i+1);
        scanf("%f%f",&x[i],&y[i]);
    }
     printf("\n le polynome d'interpolation est\n ==> f(x)=");
    for(i=0;i<n;i++){
            printf("%.3f",y[i]);
            for(j=0;j<n+1;j++){
                    if(j!=i){
                printf("((x+(%.3f))/%.3f)",-1*x[j],x[i]-x[j]);
                }
            }
            printf("+");
    }
    printf("%.3f",y[n]);
    for(j=0;j<n+1;j++){
            if(j!=n){
                printf("((x+(%.3f))/%.3f)",-1*x[j],x[i]-x[j]);
            }
            }

}
void newton(){
    float A[100][100];
    float x[100],y[100];
    int i,j,k,n;
    float x0=0;

    printf("\n entrer le degré du polynome :");
    scanf("%d",&n);
    for(i=0;i<n+1;i++)
    {
        printf("saisir x(%d)\ty(%d)\n",i+1,i+1);
        scanf("%f%f",&x[i],&y[i]);
    }
    for(i=0;i<n+1;i++){
        for(j=0;j<n+1;j++){
            if(j>i){
                A[i][j]=0;
            }
        }
    }

    for(i=0;i<n+1;i++){
        A[i][0]=y[i];
    }
    for(i=1;i<n+1;i++){
        j=1;
        A[i][j]= (y[i]-y[i-1])/(x[i]-x[i-1]);
    }

    for(j=2;j<n+1;j++){
             k=0;
        for(i=2;i<n+1;i++){
            if(i>=j){
                    A[i][j] = (A[i][j-1]- A[i-1][j-1])/(x[i]-x[k]);
                    k++;
            }
        }
}

    printf("\n methode de newton :\n\n");
    for(i=0; i<n+1; i++)
    {
        for(j=0; j<n+1; j++){
            printf("%.3f\t",A[i][j]);
        }
        printf("\n");
    }

    printf("\n\t le polynome de collocation de newton est :\n");
    printf("\n P(x) = %.3f+ ",A[0][0]);

    for(i=1;i<n;i++){
            printf("%.3f",A[i][i]);
            for(j=0;j<i;j++){
                printf("(x+(%.3f))",-1*x[j]);
            }
          printf("+");
    }
    printf("%.3f",A[n][n]);
    for(j=0;j<n;j++){
        printf("(x+(%.3f))",-1*x[j]);
    }
}
/*.........................................................*/
void jacobie(float a[19][19],float b[19],int n)
{
    float x[19],x1[19],x2[19],s,eps=1e-4;
    int i,j,k,iter=0;

//initialisation du vecteur
    printf("\n  Veuillez initialisez le vecteur solution initiale :\n");
    for (i=0; i<n; i++)
    {
        printf(" X(0)[%d]= ",i+1);
        scanf("%f",&x1[i]);
    }

    do
    {
        for(i=0; i<n; i++)
        {
            s=0;
            for (j=0; j<n; j++) if (i!=j) s=s+a[i][j]*x1[j];
            x2[i]=(b[i]-s)/a[i][i];
        }
        for (k=0; k<n; k++)
        {
            x[k]=fabs(x1[k]-x2[k]);
            x1[k]=x2[k];
        }

        iter++;
    }
    while (norme(x,n)>eps) ;

    printf("\n\tJacobie \n");
    printf("\n  La resolution donne :\n");
    for (i=0; i<n; i++) printf(" X_%d = %1.2f ;\n",i+1,x2[i]);
    printf("\n Apres %d iteration, precision 10^-4. \n",iter);
}


float norme(float x[19],int n)
{
    float ref;
    int i;
    ref=0;
    for(i=0; i<n; i++) if (x[i]>ref) ref=x[i];
    return(ref);
}

// -------------------------------------------------------------
// Résolution Par Gauss-Seidel
// -------------------------------------------------------------

void gauss_seidel(float a[19][19],float b[19],int n)
{
    float x[19],x1[19],x2[19],s,p,eps=1e-4;
    int i,j,k,iter=0;

//initialisation du vecteur
    printf("\n * Veuillez initialisez le vecteur solution : \n\n");
    for (i=0; i<n; i++)
    {
        printf(" X(0)[%d]= ",i+1);
        scanf("%f",&x1[i]);
    }

    do
    {
        for(i=0; i<n; i++)
        {
            s=0;
            p=0;
            for (j=i+1; j<n; j++) s=s+a[i][j]*x1[j];
            for (j=0; j<i; j++) p=p+a[i][j]*x2[j];
            x2[i]=(b[i]-s-p)/a[i][i];
        }
        for (k=0; k<n; k++)
        {
            x[k]=fabs(x1[k]-x2[k]);
            x1[k]=x2[k];
        }

        iter++;
    }
    while (norme(x,n)>eps) ;

    printf("\n\tGauss-Seidel \n");
    printf("\n La résolution donne :\n");
    for (i=0; i<n; i++) printf(" X_%d = %1.2f ;\n",i+1,x2[i]);
    printf("\n Apres %d itération, precision 10^-4. \n",iter);
}
/*........................cholesky........................................*/

void cholesky(float a[19][19],float b[19],int n)
{
    float L[19][19],Lt[19][19],x[19],y[19],s,p;
    int i,j,k;

// vérification de le symétrie
    for (i=0; i<n; i++) for (j=0; j<n; j++)
            if (a[i][j]!=a[j][i])
            {
                printf("\n Non symetrique => methode de Cholesky non applicable\n");
              //   return NULL;
              break;
            }

    for (i=0; i<n; i++) for (j=0; j<n; j++) L[i][j]=0;

    for (i=0; i<n; i++)
    {
        s=0;
        for (k=0; k<i; k++) s=s+pow(L[i][k],2);
        p=a[i][i]-s;

        if (p<=0)
        {
            printf("\n Non definie positive => methode de Cholesky non applicable\n");
         //    return NULL;
         break;
        }

        L[i][i]=sqrt(p);

        for(j=i+1; j<n; j++)
        {
            s=0;
            for (k=0; k<i; k++) s=s+L[i][k]*L[j][k];
            L[j][i]=(a[j][i]-s)/L[i][i];
        }
    }

    for (i=0; i<n; i++) for (j=0; j<n; j++) Lt[i][j]=L[j][i];

// resolution
    for(i=0; i<n; i++)
    {
        s=0;
        for(j=0; j<i; j++) s=s+L[i][j]*y[j];
        y[i]=(b[i]-s)/L[i][i];
    }

    for(i=n-1; i>=0; i--)
    {
        s=0;
        for(j=i+1; j<n; j++) s=s+Lt[i][j]*x[j];
        x[i]=(y[i]-s)/Lt[i][i];
    }

    printf("\n\tCholesky \n");
    printf("\n  A = L * Lt \n");
    printf("\n  La matrice L :\n");
    afficher_matrice(L,n);
    printf("\n  La matrice Lt :\n");
    afficher_matrice(Lt,n);
    printf("\n La resolution donne :\n");
    for (i=0; i<n; i++) printf(" (X%d) = %1.2f ;\n",i+1,x[i]);
}

/*.................LU DE CROUT...............................*/
void LU_crout(float a[19][19],float b[19],int n)

{
    float L[19][19],U[19][19],x[19],y[19],s;
    int i,j,k,m;

    for (i=0; i<n; i++) for (j=0; j<n; j++)
        {
            if(i==j) U[i][j]=1;
            else U[i][j]=0;
            L[i][j]=0;
        }

    for (m=0; m<n; m++)
    {
        for (i=m; i<n; i++)
        {
            s=0;
            for (k=0; k<m; k++) s=s+L[i][k]*U[k][m];
            L[i][m]=a[i][m]-s;
        }

        if (L[k][k]==0)
        {
            printf("\n Un mineur nul ! => methode de LU non applicable\n");
         //   return NULL;
         break;
        }

        for (j=m+1; j<n; j++)
        {
            s=0;
            for (k=0; k<m; k++) s=s+L[m][k]*U[k][j];
            U[m][j]=(a[m][j]-s)/L[m][m];
        }
    }

// resolution
    for(i=0; i<n; i++)
    {
        s=0;
        for(j=0; j<i; j++) s=s+L[i][j]*y[j];
        y[i]=(b[i]-s)/L[i][i];
    }

    for(i=n-1; i>=0; i--)
    {
        s=0;
        for(j=i+1; j<n; j++)s=s+U[i][j]*x[j];
        x[i]=(y[i]-s)/U[i][i];
    }

    printf("\n\tLU Crout\n");
    printf("\n  A = L * U \n");
    printf("\n  La matrice L :\n");
    afficher_matrice(L,n);
    printf("\n  La matrice U :\n");
    afficher_matrice(U,n);
    printf("\n  La resolution donne :\n");
    for (i=0; i<n; i++) printf(" X_%d = %1.2f ;\n",i+1,x[i]);
}
/*........LES EQUATIONS DIFFERENTIELLES.........*/


