#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#define SIZE 2048

//Commande cp
//Version avec buffer
int main(int argc, char** argv)
{
	//test pour savoir si un fichier est passé en paramètre
	if(argc != 3)
	{
		printf("USAGE: %s [source][cible]\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	
	//ouverture du fichier source
	int source = open(argv[1], O_RDONLY);
	if(source == -1)
	{
		printf("Erreur lors de l'ouverture du fichier %s \n", argv[1]);
		perror("Open ");
		exit(1);
	}
	
	//creation du fichier cible
	int cible = open(argv[2], O_WRONLY | O_CREAT);
	if(cible == -1)
	{
		printf("Erreur lors de la création du fichier %s \n", argv[2]);
		perror("Open ");
		exit(1);
	}
		
	//affiche du contenu
	char buffer[SIZE];
	int nbLus = 0; //nombre de caractères lus
	while(nbLus = read(source, buffer, SIZE))
		write(cible, buffer, nbLus);
	
	//fermeture du fichier
	close(source);
	close(cible);
		
	return 0;
}
		
