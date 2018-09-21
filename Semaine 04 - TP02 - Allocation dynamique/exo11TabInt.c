#include <stdio.h>
#include <stdlib.h>

//Programme exemple 
// - de passage de paramètres à la commande
// - allocation dynamique d'un tableau d'entiers 

// premier paramètre: taille
// deuxième paramètre: valeur
int main(int argc, char** argv)
{
	//Si le nombre de paramètre n'est pas correcte 
	//alors le processus s'arrête
	if(argc != 3)
	{
		printf("USAGE: %s [taille] [valeur]\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	
	//récupération des paramètres
	//ici nous avons besoin de convertir une chaîne de caractères en entier
	int taille = atoi(argv[1]);
	int valeur = atoi(argv[2]);
	
	//allocation dynamique du tableau d'entier
	int* tabInt = (int*) calloc(taille, sizeof(int));
	int i;
	
	//initialisation du tableau et affichage
	for(i=0; i<taille; i++)
	{
		tabInt[i]=valeur;
		printf("tabInt[%i]=%i\n", i, tabInt[i]);
	}
	
	//libération de la mémoire
	free(tabInt);
	
	//sortie du programme avec succès
	return EXIT_SUCCESS;
}
