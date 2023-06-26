/**
    Name     : simulSegMain.c
    Purpose : simulation des algorithmes de segmentation
    Authors  : class Promotion 2019-2022
    Created : 2021-04-06
    Updated : 2021-04-09
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>
#include <curses.h>
#include <locale.h>
#include <stdbool.h>

typedef struct TSegment TSegment;
struct TSegment
{
    unsigned int taille;
    bool libre;
    TSegment *adr;
};

void initialisation(TSegment tabDemande[], int nbSeg);

void showRAM(TSegment tabSeg[], int nbSeg);

bool allocation (TSegment TabSeg [], int *nbSeg, unsigned int demande, int typAlgo);

int firstFit(TSegment tabSeg[],  int nbSeg, unsigned int demande);

int bestFit(TSegment tabSeg[],  int nbSeg, unsigned int demande);

int worstFit(TSegment* tab, int nbSeg, unsigned int demande);

int main()
{
    setlocale(LC_CTYPE, "");

    const int nbMaxSeg = 9;
    char rep;
    int typeAlgo;
    unsigned int demande;
    TSegment tabSeg[nbMaxSeg];
    int nbSeg;
    bool result;

    do
    {
        printf("\nPROGRAMME SIMULATION ALGOS SEGMENTATION\n");
        printf("\nNombre de segments (<= %d) : ", nbMaxSeg);
        scanf("%d", &nbSeg);

        initialisation(tabSeg, nbSeg);

        showRAM(tabSeg, nbSeg);

        printf("\nChoix d'algorithme ");
        printf("\n\t1-First-Fit");
        printf("\n\t2-Best-Fit");
        printf("\n\t3-Worst-Fit");
        printf("\nChoisissez le numero de l'algorithme à appliquer : ");
        scanf("%d", &typeAlgo);

        do
        {
            printf("\nDonnez la taille à allouer (0 pour terminer) : ");
            scanf("%d", &demande);
            fflush(stdin);

            if(demande > 0)
            {
                result = allocation (tabSeg, &nbSeg, demande, typeAlgo);
                if(result)
                {
                    printf("\nDernière demande : OK\n");
                }
                else
                {
                    printf("\nDernière demande : KO\n");
                }   // if(result)
            }   //if(demande > 0
            showRAM(tabSeg, nbSeg);
        }
        while(demande > 0);

        printf("\nAutre test (O/N) : ");
//è        rep = toupper(getche());
        fflush(stdin);
        printf("\n-------------------------------------------------------------\n");
    }
    while(rep == 'O');
    return 0;
}   //int main()


void initialisation(TSegment tabDemande[], int nbSeg)
/** Goal : Lecture de l'etat initial de la RAM avant de commencer une simulation
**/
{
    int i, xTaille;
    printf("\nSaisir la taille des segments initiaux\n");
    for(i = 0; i < nbSeg; i++)
    {
        printf("\tDemande %d : ", i+1);
        scanf("%d", &xTaille);
        tabDemande[i].taille = xTaille;
        tabDemande[i].libre = true;
    }
}   //void initialisation(TSegment tabDemande[], int nbSeg)


void showRAM(TSegment tabSeg[], int nbSeg)
/** Goal : Afficher l'état de la RAM
**/
{
    char strEtat[9];
    int i = 0;
    printf("\n------------- ETAT DE LA RAM ------------------------------");
    printf("\n\tN⁰\tTaille\tEtat");
    for(i = 0; i < nbSeg; i++)
    {
        if (tabSeg[i].libre)
        {
            strcpy(strEtat, "libre");
        }
        else
        {
            strcpy(strEtat, "occupe");
        }
        printf("\n\t%2d\t%6u\t%-6s", i+1, tabSeg[i].taille, strEtat);
    }
    printf("\n------------- ********************* ------------------------------");
}   //void showRAM(TSegment tabSeg[], int nbSeg)

bool allocation (TSegment tabSeg [], int *pNbSeg, unsigned int demande, int typAlgo)
/** Goal : Traiter une demande de mémoire
**/
{
    bool rsltAllo;
    int posFit;
    unsigned int reste;
    //Recherche de la position d'un segment convenable
    switch (typAlgo)
    {
    case 1 :
        posFit = firstFit(tabSeg, *pNbSeg, demande);
        break;

    case 2 :
        posFit = bestFit(tabSeg, *pNbSeg, demande);
        break;

    case 3 :
        posFit = worstFit(tabSeg, *pNbSeg, demande);
        break;

    default :
        break;
    };
    //Traitement de la demande suivant le résultat de la recherche
    if(posFit == -1)        //Aucun segment convenable n'a été trouvé
    {
        rsltAllo = false;
    }
    else         //Un segment convenable a été trouvé
    {
        //Mise à jour table des segments avec fragmentation du segment trouvé
        unsigned int ind = (unsigned int)posFit;
        reste = tabSeg[ind].taille - demande;
        tabSeg [ind].taille = demande;
        tabSeg [ind].libre = false;
        //Création du nouveau segment libre
        if(reste > 0)
        {
            ind = *pNbSeg;
            tabSeg[ind].taille = reste;
            tabSeg [ind].libre = true;
            ++*pNbSeg; //Augmentation du nombre de segments
            rsltAllo = true;
        }
    }
    return rsltAllo;
}   //bool allocation (TSegment tabSeg [], unsigned int demande, int Tpalgo, int *nbSeg)

int firstFit(TSegment tabSeg[],  int nbSeg, unsigned int demande)
{
    int retour = -1;
    unsigned int ind = 0;

    while(retour < 0 && ind < nbSeg)
    {
        if(tabSeg[ind].libre && tabSeg[ind].taille > demande)
        {
            retour = ind;
        }
        ++ind;
    }
    return retour;
}   //int firstFit(TSegment tabSeg[], unsigned int demande, int n)

int bestFit(TSegment tabSeg[], int nbSeg, unsigned int demande)
{
    int retour = -1;
    int tabEcart[nbSeg];
    int minEcart;

    for(int i = 0 ; i < nbSeg ; i++)
    {
        tabEcart[i] = tabSeg[i].taille - demande;
    }

    for(int i = 0 ; i < nbSeg ; i++)
    {
        if(tabEcart[i] >= 0  && tabSeg[i].libre)
        {
            minEcart = tabEcart[i];
        }
    }

    for(int i = 0 ; i < nbSeg ; i++)
    {
        if(tabEcart[i] >= 0 && tabEcart[i] < minEcart  && tabSeg[i].libre == true)
        {
            minEcart = tabEcart[i];
        }
    }

    for(int i = 0 ; i < nbSeg ; i++)
    {
        if(tabSeg[i].libre && tabEcart[i] == minEcart)
            retour = i;
    }

    return retour;
}

int worstFit(TSegment* tab, int nSeg, unsigned int demande)
{
    int posWorstFit=-1;
    unsigned int oldSize=0;
    for(int i=0; i<nSeg; i++)
    {
        if(posWorstFit<0 && tab[i].taille>=demande && tab[i].libre)
        {
            //Récupération du premier Fit
            oldSize=tab[i].taille;
            posWorstFit=i;
        }
        if(tab[i].libre && tab[i].taille>=demande && tab[i].taille>oldSize)
        {
            //Mémorisation du fit courant
            posWorstFit=i;
            oldSize=tab[i].taille;
        }
    }

    return posWorstFit;
}   //int worstFit(TSegment* tab, int nSeg, unsigned int demande)
