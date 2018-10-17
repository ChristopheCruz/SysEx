#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#define SIZE 2048


// fonction d'insertion du fichier source à la fin du fichier cible
void insert(char *source, char* cible)
{
	//ouverture des fichiers
	int descSource = open(source, O_RDONLY);
	int descCible = open(cible, O_WRONLY | O_APPEND);
	if(descCible == -1) 
	{
		perror("Erreur d'ouverture du cible: ");
		exit(EXIT_FAILURE);
	}else if(descSource == -1){
		perror("Erreur d'ouverture du source: ");
		exit(EXIT_FAILURE);
	}

	//copie des octets du fichier
	char buffer[SIZE];
	int nbLus = 0; //nombre de caractères lus
	int nbTotalLus = 0;
	while(nbLus = read(descSource, buffer, SIZE))
	{
		write(descCible, buffer, nbLus);
		nbTotalLus += nbLus;
	}

	//sérialisaion à la fin du fichier de la taille du fichier caché
	printf("La taille du fichier à cacher est de %i\n", nbTotalLus);
	write(descCible, &nbTotalLus, sizeof(int));
	printf("Fichier %s inseré dans fichier %s !\n", source, cible);
}

//fonction d'extraction du fichier caché
//celui-ci ne sera pas supprimé du fichier qui le contient
void extract(char *source, char* cible)
{
	//ouverture des fichiers
	int descSource = open(source, O_RDONLY);
	int descCible = open(cible, O_WRONLY|O_CREAT|O_TRUNC);
	if(descCible == -1) 
	{
		perror("Erreur d'ouverture du cible: ");
		exit(EXIT_FAILURE);
	}else if(descSource == -1){
		perror("Erreur d'ouverture du source: ");
		exit(EXIT_FAILURE);
	}
	
	//extraction de la taille du fichier caché
	int cur = lseek(descSource, -sizeof(int), SEEK_END);
	if(cur == -1){
		perror("Erreur d'accès au fichier source: ");
		exit(EXIT_FAILURE);
	}
	int taille;
	read(descSource, &taille, sizeof(int));
	printf("La taille du fichier caché est de %i octets\n", taille);
	
	// extraction des octets
	cur = lseek(descSource, -(sizeof(int)+taille), SEEK_END); //positionnement du cuseur de fichier
	if(cur == -1){
		perror("Erreur d'accès au fichier source: ");
		exit(EXIT_FAILURE);
	}

	char buffer[SIZE];
	int nbLus = 0; //nombre de caractères lus
	int i;

	for(i=0; i<(taille/SIZE); i++)
	{
		nbLus = read(descSource, buffer, SIZE);
		write(descCible, buffer, nbLus);
	}
	nbLus = read(descSource, buffer, taille%SIZE); //gestion du buffer pour ne pas enregistrer les octets non nécessaires
	write(descCible, buffer, nbLus); 
	printf("Extraction de %s terminée !\n", cible);
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
	
	return EXIT_SUCCESS;
}