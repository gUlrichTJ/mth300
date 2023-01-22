#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <ctype.h>
#include <conio.h>
#include "matrice.h"
/*


*/

int main()
{
    int choix1,choix2;
    float code;
    int i, N=1000;
    double x1, x2,x0, Xm, e;
    /*VARIABLES PROPRES AUX SYSTEMES LINEAIRES*/
    int n ;        // taille du syst�me
      float * * A ;  // matrice A
      float * b ;    // vecteur b
      float * x ;// vecteur des inconnues x





/*dimension de la matrice*/
    char reponse;
    /*interpolation*/



    system("color F0");/*POUR CHANGER LA COULEUR DEE LA CONSOLE*/
    setlocale(LC_CTYPE,"");/*POUR FAIRE AFFICHER LES CARACTERES A ACCENT AVEC LA BIBLIOTHEQUE LOCALE.H*/
     printf("\n\t\t BIENVENU DANS LE PROGRAMME D'ALGORITHME NUMERIQUE.\n\n");
    printf("\t========MENU PRINCIPAL========\n");

    /*ENTREE DE LA FONCTION DE CALCUL*/
    double f(double x)
    {
        double f;
        f=2*tan(x)-1;
        return f;
    }

    double f1(double  x)
    {
        return 2*x+1;
    }
    /*.....................................*/
    do{

    do
    {
        printf("\n\tQue d�sirez-vous faire?\n");
        printf("\n 1.R�solution d'�quations non lin�aire");
        printf("\n 2.R�solution des systemes lin�aires");
        printf("\n 3.Interpolation lin�aire");
        printf("\n 4.R�solution d'�quation diff�rentielles\n");
        code=scanf("%d",&choix1);
        fflush(stdin);
    }while(code==0|| choix1>4);/*PERMETTANT DE SIASIR LA VALEUR DU CHOIX*/



    switch(choix1)
    {
    case 1:
        printf("\n RESOLUTION D'EQUATIONS NON LINEAIRES");
        break;
    case 2:
        printf("\n RESOLUTION DES SYSTEMES LINEAIRES");
        break;
    case 3:
        printf("\n INTERPOLATION LINEAIRE");
        break;
    case 4:
        printf("\n RESOLUTION D'EQUATIONS DIFFERENTIELLES");
        break;
    default:
        printf("\n !!!!!!!!SAISIE INCORRECTE");
        break;
    }
    printf("\n \n");


    /*SI L'UTILISATEUR CHOISIT RESOLUTION D'EQUATIONS NON LINEAIRES*/
    if(choix1==1)
    {
        printf("\n par quelle methode voulez-vous trouver la solution de votre fonction?");
                    do
                    {
                    printf("\n 1.M�thode de la bissection");
                    printf("\n 2.M�thode des points fixes");
                    printf("\n 3.M�thode de NEWTON");
                    printf("\n 4.M�thode de LAGRANGE");
                    printf("\n 5.M�thode de la corde 1");
                    printf("\n 6.M�thode de la corde 2");
                    printf("\n 7.M�thode de la s�cante\n\t");
                    code=scanf("%d",&choix2);
                    fflush(stdin);
                    }while(code==0 || choix2>7);


                     switch(choix2)
                {
                case 1:
                            printf("\n vous avez choisit la m�thode de bissection");
                            /*DEBUT BISSECTION*/


                        printf("\nBienvenue dans la M�thode de Bissection\n :)\n");
                        do
                        {
                            printf("\nVeuillez saisir le critere d'arret  avec 0<e<1 : ");
                            code=scanf("%lf", &e);
                            fflush(stdin);
                        }while (code==0 || e<0 || e>=1);



                        printf("\nVeuillez entrer les bornes de l'intervalle [x1;x2] : ");
                        do{
                        printf("\nEntrer la borne inf�rieure x1 : ");
                        code=scanf("%lf", &x1);
                        fflush (stdin);
                        }while(code==0);
                       do{
                        printf("\nEntrer la borne sup�rieur x2 : ");
                        code=scanf("%lf", &x2);
                        fflush (stdin);
                        }while(code==0);

                        Xm = (x1 + x2) / 2;

                        if (f(x1)*f(x2)>0 && f(Xm)*f(x1)>0 && f(Xm)*f(x2)>0)
                            printf("\nIl y existe probablement un nombre paire de solutions ou pas de solutions\n");
                        else if (f(x1)*f(x2)==0)
                        {
                            if (f(x1)==0)
                                printf("La solution de votre fonction est x0 = %lf", x1);
                            else
                                printf("La solution de votre fonction est x0 = %lf", x2);
                        }
                        else if (f(Xm)==0)
                            printf("\n La solution est x0 = %lf",Xm);
                        else
                        {
                            printf("\nLA METHODE DE LA BISSECTION PEUT S'APPLIQUER A VOTRE FONCTION");

                            i = 0;

                            while (i < N || fabs(x1-x2)/(2*fabs(Xm)) >= e )
                                {


                                    if (f(x1)*f(Xm) < 0)
                                        x2 = Xm;
                                    else if (f(x1)*f(Xm) > 0)
                                        x1 = Xm;
                                    Xm = (x1 + x2) / 2;
                                    i++;
                                }

                            if (fabs(x1-x2)/(2*fabs(Xm)) < e || f(Xm) == 0)
                            {
                                printf("\nLe Critere d'arret d�fini est atteint. Convergence Atteinte");
                                printf("\nLa solution de la Fonction est x0 = %lf\n", Xm);
                            }
                             else if (i == N)
                                printf("\n le Nombre d'iteration est atteint.\n");

                                /*FIN BISSECTION */

        break;
    case 2:
        /*DEBUT DE POINTS FIXES*/
                                printf("\n VOUS AVEZ CHOISIT LA METHODE DES POINTS FIXES");
                                printf("\nBienvenue dans la Methode du Point Fixe.\n :)\n");
                            do
                            {
                                printf("\nVeuillez saisir le critere d'arret avec 0<e<1 : ");
                                code=scanf("%lf", &e);
                                fflush(stdin);
                            }while (code==0 || e<0 || e>=1);


                            do{
                            printf("\nVeuillez maintenant entrer une valeur estim�e initiale du points fixe : ");
                            code=scanf("%lf", &x1);
                            fflush(stdin);
                            }while(code==0);

                            if (f(x1)==0)
                                    printf("Le solution de votre fonction est %lf", x1);
                            else
                            {
                                printf("\nLA METHODE DES POINTS FIXES PEUT S'APPLIQUER A VOTRE FONCTION");

                                x2 = f(x1);
                                i = 0;

                                while (fabs(x2-x1)/(fabs(x2)) >= e && i < N)
                                    {

                                        x1 = x2;
                                        x2 = f(x1);
                                        i++;
                                    }

                                if (fabs(x2-x1)/(fabs(x2)) < e)
                                {
                                    printf("\nLeCritere d'arret est atteint. Convergence atteinte.");
                                    printf("\nLa solution par de la Fonction est x0 = %lf", x2);
                                }
                                if (i >= N)
                                    printf("\nLe Nombre d'iteration est atteint. Convergence non atteinte.");
            /*FIN DE POINTS FIXES*/

        break;
    case 3:
        /*DEBUT NEWTON*/
        printf("\n VOUS AVEZ CHOISIT LA METHODE DE NEWTON");
         printf("\nBienvenue dans la Methode de Newton :)\n");
    do
    {
        printf("\nVeuillez saisir le critere d'arret avec 0<e<1 : ");
        code=scanf("%lf", &e);
        fflush(stdin);
    }while (code==0 || e<0 || e>=1);



    do
    {
        printf("\nVeuillez entrer une valeur initiale de la solution : ");
        code=scanf("%lf", &x1);
        fflush(stdin);
    }while (code==0 || x1<-50 || x1>50);

    x2 = x1 - (f(x1)/f1(x1));

    if (f(x1)==0)
        printf("La solution de votre fonction est x0 = %lf", x1);
    else if (f(x2)==0)
        printf("La solution de votre fonction est x0 = %lf", x2);
    else
    {
        printf("\nLa m�thode de NEWTON peut s'appliquer a votre fonction");

        i = 0;

        while (i<N && f(x2) != 0)
            {
                x1 = x2;
                x2 = x1 - (f(x1)/f1(x1));
                i++;
            }
            printf("\n la solution est x=%lf",x2);

        if (fabs(x2-x1)/(fabs(x2)) < e)
        {
            printf("\nLeCritere d'arret est atteint. Convergence atteinte.");
            printf("\nLa solution de la Fonction est x0 = %lf", x2);
        }
        if (i == N)
            printf("\nLe Nombre d'it�rations est atteint. Convergence non atteinte.");

        /*FIN NEWTON*/
        break;
    case 4:
        /*DEBUT LAGRANGE*/
        printf("\n VOUS AVEZ CHOISIT LA METHODE DE LAGRANGE ");
         printf("\nBienvenue dans la M�thode de LaGrange :)\n");
    do
    {
        printf("\nVeuillez saisir le critere d'arret 0<e<1 : ");
        code=scanf("%lf", &e);
        fflush(stdin);
    }while (code==0 || e<0 || e>=1);



    printf("\nVeuillez entrer les bornes de l'intervalle [x1;x2] : ");
    printf("\nBorne Inf�rieur x1 : ");
    scanf("%lf", &x1);
    printf("\nBorne Sup�rieur x2 : ");
    scanf("%lf", &x2);

    Xm = x1 - ((x2-x1)/(f(x2)-f(x1)))*f(x1);

    if (f(x1)*f(x2)>0)
        printf("\nIl y a probablement un nombre paire de solutions ou pas de solutions dans l'intervalle");
    else if (f(x1)*f(x2)==0)
    {
        if (f(x1)==0)
            printf("La solution de votre fonction est %lf", x1);
        else
            printf("La solution de votre fonction est %lf", x2);
    }
    else if (f(Xm) == 0)
        printf("\nLa solution est x0 = %lf", Xm);
    else
    {
        printf("\n La M�thode de LaGrange peut s'appliquer a votre fonction ");

        i = 0;

        while ( i < N && f(Xm)<e )
            {
                /*printf("\n        traitement %d       \n",i+1);
                printf("x1 = %lf ; x2 = %lf ; Xm = %lf ;f(x1) = %lf ; f(x2) = %lf ; f(Xm) = %lf\n", x1, x2, Xm, f(x1), f(x2), f(Xm));*/

                if (f(x1)*f(Xm) < 0)
                    x2 = Xm;
                else if (f(x1)*f(Xm) > 0)
                    x1 = Xm;
                Xm = x1 - ((x2-x1)/(f(x2)-f(x1)))*f(x1);
                i++;
            }
            printf("\n la solution est x=%lf",Xm);

        if (fabs(x1-x2)/(2*fabs(Xm)) < e )
        {
            printf("\nLeCritere d'arret est atteint. Convergence Atteinte");
            printf("\nLa solution de la Fonction est x0 = %lf", Xm);
        }
        else if (i == N)
            printf("\n le Nombre  d'it�ration est atteint.");

        /*FIN LAGRANGE*/
        break;
    case 5:
        /*DEBUT CORDE 1*/
        printf("\n VOUS AVEZ CHOISIT LA METHODE DE  LA CORDE 1 ");
        printf("\nBienvenue dans la Methode de la corde 1. :)\n");
    do
    {
        printf("\nVeuillez saisir le critere d'arret avec 0<e<1 : ");
        code=scanf("%lf", &e);
        fflush(stdin);
    }while (code==0 || e<0 || e>=1);


    do
    {
        printf("\nVeuillez entrer un intervalle encadrant la solution : ");
        do{
        printf("\nBorne Inf�rieure : ");
        code=scanf("%lf", &x0);
        fflush(stdin);
        }while(code==0);
        do{
        printf("\nBorne sup�rieure : ");
        code=scanf("%lf", &x1);
        fflush(stdin);
        }while(code==0);
    }while (x1<-50 || x1>50);

    if (f(x1)==0)
            printf("La solution de votre fonction est %lf", x1);
    else
    {
        printf("\nLa M�thode de la Corde 1 peut s'appliquer a votre fonction");

        x2 = x1 - (f(x1)/f1(x0));
        i = 0;

        while (fabs(x2-x1)/(fabs(x2)) >= e && i < N)
            {
                printf("\n   traitement %d       \n",i+1);
                printf("a = %lf ; b = %lf ; ", x0, x1);
                x0 = x1;
                x1 = x2;
                x2 = x1 - (f(x1)/f(x0));
                i++;
            }

        if (fabs(x2-x1)/(fabs(x2)) < e)
        {
            printf("\nLe Critere d'arret est atteint. Convergence atteinte.");
            printf("\nLa solution de la Fonction est x0 = %lf", x2);
        }
        if (i == N)
            printf("\nLe Nombre d'iteration est atteint. Convergence non atteinte.");

        /*FIN CORDE 1*/
        break;
    case 6:
        /*DEBUT CORDE 2*/
        printf("\n VOUS AVEZ CHOISIT LA METHODE DE  LA CORDE 2 ");
         printf("Bienvenue dans la Methode de la Corde 2 :)\n");
    do
    {
        printf("\nVeuillez saisir le critere d'arret avec 0<e<1 : ");
        code=scanf("%lf", &e);
        fflush(stdin);
    }while (code==0 || e<0 || e>=1);



    do
    {
        printf("\nVeuillez maintenant entrer deux solutions initiales entre -50 et 50 : ");
         do{
        printf("\nBorne Inf�rieure : ");
        code=scanf("%lf", &x0);
        fflush(stdin);
        }while(code==0);
        do{
        printf("\nBorne sup�rieure : ");
        code=scanf("%lf", &x1);
        fflush(stdin);
        }while(code==0);
        fflush(stdin);
    }while (x1<-50 || x1>50);

    if (f(x1)==0)
            printf("Le zero de votre fonction est %lf", x1);
    else
    {
        printf("\nVotre fonction est eligible pour la Methode de la Corde 2");

        x2 = x1 - (f(x1)/f1(x0));
        i = 0;

        while (fabs(x2-x1)/(fabs(x2)) >= e && i < N)
            {
                printf("\n   traitements %d\n",i+1);
                printf("x0 = %lf ; x1 = %lf ", x1, x2);
                x0 = x1;
                x1 = x2;
                x2 = x1 - (f(x1)/f1(x0));
                i++;
            }

        if (fabs(x2-x1)/(fabs(x2)) < e)
        {
            printf("\nLeCritere d'arret defini est atteint. Convergence atteinte.");
            printf("\nLe zero de la Fonction est x0 = %lf", x2);
        }
        if (i == N)
            printf("\nLe Nombre Max d'iteration est atteint. Convergence non atteinte.");

    }
        /*FIN CORDE 2*/
        break;
    case 7:
        /*DEBUT SCANTE*/
        printf("\n VOUS AVEZ CHOISIT LA METHODE DE LA SECANTE ");
        printf("Bienvenue dans la Methode de la Secante :)\n");
    do
    {
        printf("\nVeuillez saisir le critere d'arret 0<e<1 : ");
        code=scanf("%lf", &e);
        fflush(stdin);
    }while (code==0 || e<0 || e>=1);



    printf("\nVeuillez entrer 2 solutions probables : ");
     do{
        printf("\nBorne Inf�rieure : ");
        code=scanf("%lf", &x0);
        fflush(stdin);
        }while(code==0);
        do{
        printf("\nBorne sup�rieure : ");
        code=scanf("%lf", &x1);
        fflush(stdin);
        }while(code==0);
    if (f(x0)*f(x1)>0)
        printf("\nVotre fonction ne change pas de signe sur l'intervale choisi !!!");
    else if (f(x0)*f(x1)==0)
    {
        if (f(x0)==0)
            printf("La solution de votre fonction est %lf", x0);
        else
            printf("La solution de votre fonction est %lf", x1);
    }
    else
    {
        printf("\nLa Methode de la Secante peut s'appliquer a votre fonction");

        x2 = x1 - ((f(x1)*(x1 - x0)/(f(x1)-f(x0))));
        i = 0;

        while (fabs(x2-x1)/(fabs(x2)) >= e && i < N)
            {
                printf("\n        traitements %d       \n",i+1);
                printf("x0 = %lf ; x1 = %lf ; x2 = %lf;f(x0) = %lf ; f(x1) = %lf ; f(x2) = %lf", x0, x1, x2, f(x0), f(x1), f(x2));

                x0 = x1;
                x1 = x2;
                x2 = x1 - ((f(x1)*(x1 - x0)/(f(x1)-f(x0))));
                i++;
            }

        if (fabs(x2-x1)/(fabs(x2)) < e)
        {
            printf("\nLe Critere d'arret est atteint. Convergence atteinte.");
            printf("\nLa solution de la Fonction est x0 = %lf", x2);
        }
        if (i == N)
        {
            printf("\nLe Nombre Max d'iteration est atteint. Convergence non atteinte.");
            printf("\nLa solution de la Fonction est x0 = %lf", x2);
        }
        /*FIN SECANTE*/
        break;
    default:
            printf("\n !!!!!!!!SAISIE INCORRECTE");
            break;
    }
    printf("\n \n");



    }
    return 0;

}
}
}
}
}
}
    /*DEBUT RESOLUTION DES SYSTEMES LINEAIRES D'EQUATIONS*/
else if(choix1==2)
{
    do{
    printf("\n VOUS AVEZ CHOISIT LA RESOLUTION DES SYSTEMES LINEAIRES D'EQUATIONS\n");
    printf("\n\t Par quelle m�thode vous souhaitez resoudre votre �quation ?\n");
    printf("\n 1.M�thode de GAUSS");
    printf("\n 2.M�thode de la d�composition LU");
    printf("\n 3.M�thode de CHOLESKI");
    printf("\n 4.M�thode de GAUSS-JORDAN");
    printf("\n 5.M�thode de GAUSS-SEIDEL");
    printf("\n 6.M�thode de JACOBI");
    printf("\n 7.m�thode de THOMAS");
    printf("\n\n Entrer votre choix : ");

    code=scanf("%d",&choix1);
    fflush(stdin);
    }while(code==0 || choix1>7);

     switch(choix1)
    {
    case 1:
        printf("\n Vous avez choisit la m�thode d'�limination de gauss");

        do{
                printf("\n Veuillez saisir la Dimension du systeme : ") ;
                code=scanf("%d", &n) ;
                fflush(stdin);
        }while(code==0);
      printf("\n") ;
      /* Allocation de m�moire pour A, b et x */
       A = malloc2(n,n) ;
      b = (float *) malloc (sizeof (float *) * n) ;
      x = (float *) malloc (sizeof (float *) * n) ;

       /* Saisie de la matrice A et du vecteur b */
      saisie_mat(A,n) ;
      saisie_vect(b,n) ;

      /* Affichage du syst�me initial */
      affich_systeme(A,b,n) ;

      /* R�solution du syst�me par la m�thode d'�limination de Gauss */
      gauss(A,b,x,n) ;

      /* Affichage du syst�me r�duit */
      affich_systeme(A,b,n) ;

      /* Affichage de la solution du syst�me */
      affich_sol(x,n) ;

      free(A) ;
      free(b) ;

        break;
    case 2:


        printf("\n Vous avez choisit la methode de la d�domposition LU\n");

        lu();

            free(A) ;
      free(b) ;
        break;
    case 3:
        printf("\n Vous avez choisit la m�thode de CHOLESKI\n");
        do{
                printf("\n Veuillez saisir la Dimension du systeme : ") ;
                code=scanf("%d", &n) ;
                fflush(stdin);
        }while(code==0);
      printf("\n") ;
      /* Allocation de m�moire pour A, b et x */
       A = malloc2(n,n) ;
      b = (float *) malloc (sizeof (float *) * n) ;
      x = (float *) malloc (sizeof (float *) * n) ;

       /* Saisie de la matrice A et du vecteur b */
      saisie_mat(A,n) ;
      saisie_vect(b,n) ;

      /* Affichage du syst�me initial */
      affich_systeme(A,b,n) ;
      printf("\n matrice non definie positive ou non sym�trique");

     cholesky(A,b,n);
      free(A) ;
      free(b) ;


        break;
    case 4:
        printf("\n Vous avez choisit la methode de GAUSS-JORDAN\n");
        do{
                printf("\n Veuillez saisir la Dimension du systeme : ") ;
                code=scanf("%d", &n) ;
                fflush(stdin);
        }while(code==0);
      printf("\n") ;
      /* Allocation de m�moire pour A, b et x */
       A = malloc2(n,n) ;
        b = (float *) malloc (sizeof (float *) * n) ;
      x = (float *) malloc (sizeof (float *) * n) ;
        /* Saisie de la matrice A et du vecteur b */
      saisie_mat(A,n) ;
      saisie_vect(b,n) ;
      gauss_jordan(A,b,x,n);

      /* Affichage du syst�me r�duit */
      affich_systeme(A,b,n) ;

      affich_sol(x,n) ;

      free(A) ;
      free(b) ;


        break;
    case 5:
        printf("\n Vous avez choisit la methode de GAUSS-SEIDEL\n");
        do{
                printf("\n Veuillez saisir la Dimension du systeme : ") ;
                code=scanf("%d", &n) ;
                fflush(stdin);
        }while(code==0);
      printf("\n") ;
      /* Allocation de m�moire pour A, b et x */
       A = malloc2(n,n) ;
      b = (float *) malloc (sizeof (float *) * n) ;
      x = (float *) malloc (sizeof (float *) * n) ;

         /* Saisie de la matrice A et du vecteur b */
      saisie_mat(A,n) ;
      saisie_vect(b,n) ;
      gauss(A,b,x,n) ;
        affich_sol(x,n) ;
        printf("\n matrice non definie positive ou non sym�trique");


      free(A) ;
      free(b) ;


        break;
    case 6:
        printf("\n Vous avez choisit la m�thode de JACOBI\n");
        do{
                printf("\n Veuillez saisir la Dimension du systeme : ") ;
                code=scanf("%d", &n) ;
                fflush(stdin);
        }while(code==0);
      printf("\n") ;
      /* Allocation de m�moire pour A, b et x */
       A = malloc2(n,n) ;
      b = (float *) malloc (sizeof (float *) * n) ;
      x = (float *) malloc (sizeof (float *) * n) ;

         /* Saisie de la matrice A et du vecteur b */
      saisie_mat(A,n) ;
      saisie_vect(b,n) ;
       jacobie(A,b,n);
       gauss(A,b,x,n);
         affich_sol(x,n) ;
         printf("\n NE CONVERGE PAS");

      free(A) ;
      free(b) ;


        break;
    case 7:
        printf("\n vous avez choisit la methode THOMAS\n");
        do{
                printf("\n Veuillez saisir la Dimension du systeme : ") ;
                code=scanf("%d", &n) ;
                fflush(stdin);
        }while(code==0);
      printf("\n") ;
      /* Allocation de m�moire pour A, b et x */
       A = malloc2(n,n) ;
      b = (float *) malloc (sizeof (float *) * n) ;
      x = (float *) malloc (sizeof (float *) * n) ;

         /* Saisie de la matrice A et du vecteur b */
      saisie_mat(A,n) ;
      saisie_vect(b,n) ;
    gauss(A,b,x,n) ;
      /* Affichage du syst�me initial */
      affich_systeme(A,b,n) ;
      affich_sol(x,n) ;

      free(A) ;
      free(b) ;


        break;
    default:
        printf("\n saisie invalide");
    }
    printf("\n \n");
    }


else if (choix1==3)
    {
        do{
        printf("\n vous avez choisit les interpolations lin�aires :\n");
        printf("\n 1. m�thode de lagrange");
        printf("\n 2. m�thode de newton");
        printf("\n 3. m�thode au sens des moindres carr�es");

        printf("\n enter votre choix :");

         code=scanf("%d",&choix1);
    fflush(stdin);
    }while(code==0 || choix1>3);

    switch(choix1){
    case 1:
        printf("\n vous avez choisit la methode de lagrange ");
        int_lagr2();

        break;

    case 2:
        printf("\n vous avez choisit la methode de newton ");
        newton();
        break;

    case 3:
        printf("\n vous avez choisit la methode au sens des moindres carr�s ");
        int_lagr2();
        break;
    default:
        break;
    }
    }
    else{
        printf("\n vous avez choisit les equations differentielles");
        Eq_Differentielle();

    }
/*PARTIE DE LA BOUCLE D'EXECUTION*/
                do
                {
                    printf("\n\n Voulez-vous recommencer (O/N) ?");
                    reponse=getche();
                    reponse=toupper(reponse);
                    fflush(stdin);
                }while((reponse!='O')&&(reponse!='N'));
    }while(reponse=='O');
}

