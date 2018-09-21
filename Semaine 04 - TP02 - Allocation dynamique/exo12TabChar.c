#include <stdio.h>
#include <stdlib.h>

//Programme exemple 
// - de passage de paramètres à la commande
// - allocation dynamique d'une matrice à 2 dimensions de caractères

// premier paramètre: hauteur
// deuxième paramètre: largeur
// troisième paramètre: un caractère
int main(int argc, char** argv)
{
	//Si le nombre de paramètre n'est pas correcte 
	//alors le processus s'arrête
	if(argc != 4)
	{
		printf("USAGE: %s [hauteur] [largeur] [caractère]\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	
	//récupération des paramètres
	//ici nous avons besoin de convertir une chaîne de caractère en entiers
	int hauteur = atoi(argv[1]);
	int largeur = atoi(argv[2]);
	char c = argv[3][0];
	
	int i,j;

	//allocation dynamique de la matrice de caractères
	char** matChar = (char**) calloc(largeur, sizeof(char*));
	for(i=0; i<largeur; i++)
		matChar[i] = (char*) calloc(hauteur, sizeof(char));
	
	//initialisation de la matrice et affichage
	for(i=0; i<largeur; i++)
	{
		for(j=0; j<hauteur; j++)
		{
			matChar[i][j]=c;
			printf(" %c", matChar[i][j]);
		}
		printf("\n");
	}
	
	//libération de la mémoire
	for(i=0; i<largeur; i++)
		free(matChar[i]);
	free(matChar);
	//sortie du programme avec succès
	return EXIT_SUCCESS;
}
