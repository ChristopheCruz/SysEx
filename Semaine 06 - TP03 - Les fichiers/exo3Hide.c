#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#define SIZE 2048

void insert(char *source, char* cible)
{
	printf("insert !\n");
}

void extract(char *source, char* cible)
{
	printf("extract !\n");
}

//Commande hide
int main(int argc, char** argv)
{
	//test pour savoir si un fichier est passé en paramètre
	if(argc != 4)
	{
		printf("USAGE: %s [-i|-e] [source] [cible]\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	
	
	if(!strcmp("-i", argv[1]))
		insert(argv[2], argv[3]);
	
	else if(!strcmp("-e", argv[1]))
		extract(argv[2], argv[3]);
	
	
	return 0;
	
}
/*
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
		
*/