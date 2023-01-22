#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <curses.h>
#include <ctype.h>
#include "matrice.h"
#define N 1000

int Eq_Differentielle()
{
    double DoubleControl()
        {
            int k=0;
            double x;
            do
            {
                printf("\nsaisie des paramètres : ");
                k = scanf("%lf", &x);
                fflush(stdin);
            }while(k != 1);
            return x;
    }

    int IntControl(){
            int x, k=0;
            do
            {
                printf("\nVeuillez saisir la valeur : ");
                k = scanf("%d", &x);
                fflush(stdin);
            }while(k != 1);
            return x;
    }

    double f(double y, double t){
            int f = -y + t + 1;
            return f;
    }

    int euler(double TY[N][2], int n, double etap){
            for (int i=0; i< n; i++){
                TY[i+1][1] = TY[i][1] + etap*f( TY[i][0], TY[i][1] );
                TY[i+1][0] = TY[i][0] + etap;
                printf("\n\tt%d = %lf  ;  y%d = %lf", i+1, TY[i+1][0], i+1, TY[i+1][1]);
        }

        return 0;
    }

    int euler_mod(double TY[N][2], int n, double etap){
            for (int i=0; i< n; i++){
                double tmp = TY[i][1] + etap*f( TY[i][0], TY[i][1] );
                TY[i+1][1] = TY[i][1] + (f( TY[i][0], TY[i][1] ) + f( TY[i][0] + etap, tmp ));
                TY[i+1][0] = TY[i][0] + etap;
                printf("\n\tt%d = %lf  ;  y%d = %lf",i+1, TY[i+1][0], i+1, TY[i+1][1]);
        }

        return 0;
    }

    int point_mil(double TY[N][2], int n, double etap){
            for (int i=0; i< n; i++){
                double tmp = etap*f( TY[i][0], TY[i][1] );
                TY[i+1][1] = TY[i][1] + etap*f( TY[i][0] + etap/2, TY[i][1] + tmp/2 );
                TY[i+1][0] = TY[i][0] + etap;
                printf("\n\tt%d = %lf  ==>  y%d = %lf", i+1, TY[i+1][0], i+1, TY[i+1][1]);
        }

        return 0;
    }

    int rk4(double TY[N][2], int n, double etap){
            for (int i=0; i< n; i++){
                double k1 = etap*f( TY[i][0], TY[i][1] );
                double k2 = etap*f( TY[i][0] + etap/2, TY[i][1] + k1/2);
                double k3 = etap*f( TY[i][0] + etap/2, TY[i][1] + k2/2);
                double k4 = etap*f( TY[i][0] + etap, TY[i][1] + k3);
                TY[i+1][1] = TY[i][1] + (k1 + 2*k2 + 2*k3 + k4) / 6;
                TY[i+1][0] = TY[i][0] + etap;
                printf("\n\tt%d = %lf  ;  y%d = %lf", i+1, TY[i+1][0], i+1, TY[i+1][1]);
        }


        return 0;
    }
        int rk2(double TY[N][2], int n, double etap){
        for (int i=0; i< n; i++){
                double k1 = etap*f( TY[i][0], TY[i][1] );
                double k2 = etap*f( TY[i][0] + etap/2, TY[i][1] + k1/2);
                TY[i+1][1] = TY[i][1] + (k1 + 2*k2) / 2;
                TY[i+1][0] = TY[i][0] + etap;
                printf("\n\tt%d = %lf  ;  y%d = %lf", i+1, TY[i+1][0], i+1, TY[i+1][1]);
        }
        return 0;
    }

    int n, t;
    double TY[N][2];
    double h;
    char rep;


    printf("\nENTREZ LE CHOIX QUE VOUS VOULEZ :");
    printf("\n\n\n1-la Methode d'EULER\n\n2-Methode d'EULER MODIFIEE\n\n3-Methode du POINT MILIEU");
    printf("\n\n4-Methode de RUNGE - KUTTA d'ordre 4\n\n5-Methode de RUNGE - KUTTA d'ordre 2\n\n6-QUITTER\n\t\t");

    do{
        t = IntControl();
    }while (t<1 || t>6);

    if (t==5){
        printf("\n\nMENU PRINCIPAL ?\nO pour OUI\nAUTRES CARACTERES pour NON : ");
        fflush(stdin);
//        rep = toupper(getche());
        if (rep == 'O')
            return 0;
        else
            return Eq_Differentielle();
    }

    printf("\n\n veuillez saisir le Pas de temps (0<h<5)");
    do{
        h = DoubleControl();
    }while (h<0.0000000000000000 || h>5);

    printf("\n\n veuillez entrer les valeurs initiales :");
    printf("\nentrez de t0"); TY[0][0] = DoubleControl();
    printf("\nentrez de y0"); TY[0][1] = DoubleControl();
    printf("\n\nVeuillez entrer le nombre itération avec N<1000");
    n = IntControl();

    switch (t)
    {
    case 1 :
        printf("\nMethode d'EULER EXPLICITE.\n\nles solutions sont :\n\n");
        euler(TY, n, h);

        break ;

    case 2:
        printf("\nMethode d'EULER MODIFIEE.\n\nles solutions sont :\n\n");
        euler_mod(TY, n, h);

        break;

    case 3 :
        printf("\nMethode du POINT MILIEU.\n\n les solutions sont :\n\n");
        point_mil(TY, n, h);

        break;

    case 4 :
        printf("\nMethode de RUNGE - KUNTA d'ordre 4.\n\nles solutions sont :\n\n");
        rk4(TY, n, h);

        break;
    case 5:
        printf("\nMéthode de RUNGE-KUNTA ordre 2");
        rk2(TY,n,h);

        break;


    return Eq_Differentielle();
    }


    return 0;
}
