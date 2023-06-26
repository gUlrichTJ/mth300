/*
#include<stdio.h>
#include<string.h>
int main()
{
	char txt1[300], txt2[300], gros[1000];
	int a, n=1;
	printf("Enter the first chain : ");
	gets(txt1);
	printf("Enter the second chain : ");
	gets(txt2);
	///Précédence lexicographique
	a = strcmp(txt1, txt2);
	if(a<0)
		puts("La chaine 1 précède la chaine 2");
	else if(a==0)
		puts("Les chaînes sont égales");
	else
		puts("\nLa chaîne 1 suit la chaîne 2");
	///Length of chains
	printf("\nLength of the first chain : %i", strlen(txt1));
	printf("\n\nLength of the second chain : %i\n", strlen(txt2));
	///Ajout de la seconde chaine à la première
	puts("\nAjout de la seconde chaine à la première");
	puts(strcat(txt1, txt2));
	puts("\nAjout de la première chaine à la seconde");
	puts(strcat(txt2, txt1));
    ///Actions de copie
    puts("\nRemplacement de chaînes");
    puts(strcpy(gros, txt2));

}
*/
//To be continued
/*
#include<stdio.h>
#include<stdlib.h>
typedef struct element element;
struct element
{
	int valeur;
	struct element *suivant;
};
typedef element* llist;
int main()
{
	//Declaration de trois listes de facons differentes
	llist maListe1 = null;

}*/
//This worked by the grace of my Lord
/*
#include<stdio.h>
#include<stdlib.h>
typedef int Entier;
main()
{
	Entier x, y;
	printf("Enter a integer : ");
	scanf("%i", &x);
	printf("Enter an integer ");
	scanf("%i", &y);
	printf("You've entered %i and %i", x, y);
	return 0;
}
*/
/*#include<stdio.h>
typedef struct Personne
{
	char nom[10], prenom[20];
	short age;
}Personne;
//Fonction pour afficher les caracteristiques de la structure
void Afficher(Personne p)
{
	puts("\nInformations necessaires");
	printf("\nNom : %s\nPrenom : %s\nAge : %i\n", p.nom, p.prenom, p.age);
}
//Fonction main
main()
{
	Personne pere;
	Personne mere, gSoeur, pSoeur, cousin;
	printf("Nom de papa : ");
	scanf("%s", pere.nom);
	printf("Prenom de papa : ");
	scanf("%s", pere.prenom);
	printf("Age de papa : ");
	scanf("%i", &pere.age);
	//Maman
	printf("Nom de maman : ");
	scanf("%s", mere.nom);
	printf("Prenom de maman : ");
	scanf("%s", mere.prenom);
	printf("Age de maman : ");
	scanf("%i", &mere.age);
	printf("Nom de Grande soeur : ");
	scanf("%s", gSoeur.nom);
	printf("Prenom de grande soeur : ");
	scanf("%s", gSoeur.prenom);
	printf("Age de grande soeur : ");
	scanf("%i", &gSoeur.age);
	Afficher(pere);
	Afficher(mere);
	Afficher(gSoeur);
	Afficher(pere);
	Afficher(mere);
	//return 0;
}
*/
//Utiliser malloc et free
/*
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *Y;
    Y = (int*)malloc(sizeof(int));
    *Y = 18;
    printf("Contenu de Y : %i", *Y);
    //Libérer la mémoire
    free(Y);
	printf("\nContenu de Y : %i", *Y);
	*Y = 4;
	printf("\n*Y = %i", *Y);
	printf("\nY = %i", Y);
	printf("\n&Y = %i", &Y);
    return 0;
}
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Ville
{
	char Des[100];
	struct Ville *suivant;
}Ville;
//Création de tete et queue
Ville *tete, *queue;
//Fonction pour insérer au début de la liste
void insertAtBegining(char V[100])
{
	//Creer l'espace pour l'élément
	Ville *newElement = (Ville*)malloc(sizeof(Ville));
	newElement->suivant = tete;
    strcpy(newElement->Des, V);
	tete = newElement ;
}
//Fonction pour insérer à la fin
void insertAtEnd(char V[100])
{
    queue->suivant = (Ville*)malloc(sizeof(Ville));
    //Queue va pointer sur le nouvel élément créé
    queue = queue->suivant;
    //Nous mettons le nom de la ville grâce au pointeur queue
    strcpy(queue->Des , V);
    //Il faut que suivant pointe sur null
    queue->suivant = NULL;
}
//Fonction pour afficher la liste
//Merci Seigneur Jésus. Je l'ai écrite moi même
void displayList()
{
	Ville *courant;
	courant=tete;
    int i = 0;
	while(courant!=NULL)
	{
		printf("\n%s", courant);
		courant = courant->suivant;
		i++;
	}
	printf("\nLe nombre d'éléments de la liste est %i\n", i);
}
//Fonction principale
main()
{
	//création d'un bloc pour la tête
    tete = (Ville*)malloc(sizeof(Ville));
    //tete et queue pointent sur le même élément
    queue = tete;
    //Nous mettons l'élément dans le bloc à l'aide du pointeur tete
    strcpy(tete->Des , "Adetikopé");
    //suivant pointe sur null
    queue->suivant = NULL;
    //Nous ajoutons les autres villes
	insertAtBegining("Premier");
    insertAtEnd("Amakpape"); insertAtEnd("Gblenkome");
    insertAtEnd("Koumakope"); insertAtEnd("Hédjranawoe");
    insertAtEnd("Pourquoi?"); insertAtEnd("Merci");
    insertAtEnd("humm!");
    insertAtEnd("Impossible Cela a marché par la grâce de Dieu\n");
    insertAtBegining("First Jesus");
    insertAtBegining("Merci Jésus-Christ");
    printf("\nC'est Dieu qui donne l'intelligence.");
    puts(" Merci Jésus. Merci beaucoup Seigneur Jésus");
    puts("\nMerci beaucoup Seigneur cela a marché. Merci encore Seigneur\n");
    puts("\nThanks You Jesus-Christ thank You so much Jesus-Christ. T"
		"hank You Jesus-Christ. Oh thank You Lord Jesus. Thanks. Thanks again");
    //Maintenant comment afficher les villes?
    displayList();
}
