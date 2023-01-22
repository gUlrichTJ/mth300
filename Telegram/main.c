#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "menu.h"

int main(int argc,char *argv[])
{

int choix;
    do{
            printf("***************************************************\n");
            printf("*           MENU--------GENERAL                   *\n");
            printf("***************************************************\n");
printf("\n1-EQUATIONS NON LINEAIRES\n2-SYSTEMES NON LINEAIRES\n3-INTERPOLATIONS\n4-EQUATIONS DIFFERENTIELLES\n5-INTEGRATIONS NUMERIQUES\n");


printf("-->Entrer votre Choix\n");
scanf("%d",&choix);

if(choix==1){

                printf("***************************************************\n");
                printf("*          EQUATIONS NON LINEAIRES                *\n");
                printf("***************************************************\n");
    menuequa();


}
else if(choix==2){

                printf("***************************************************\n");
                printf("*          SYSTEMES      LINEAIRES                *\n\n");
                printf("***************************************************\n");

     menuSys();

}
else if(choix==3){
                printf("***************************************************\n");
                printf("*          INTERPOLATIONS  POLYNOMIALES           *\n\n");
                printf("***************************************************\n");
     menuInterp();

}
else if(choix==4){

                printf("***************************************************\n");
                printf("*          EQUATIONS    DIFFERENTIELLES           *\n\n");
                printf("***************************************************\n");
     menuEquaDiff();

}
else if(choix==5){

                printf("***************************************************\n");
                printf("*         INTEGRATIONS       NUMÉRIQUES           *\n\n");
                printf("***************************************************\n");
     menuIntegratNum();

}
do{
  printf("Voulez vous recommencer!!??\n0-Non\n1-Oui\n");
  scanf("%d",&choix);
}while(choix!=0 && choix != 1);

}while(choix==1);



    return 0;
}
