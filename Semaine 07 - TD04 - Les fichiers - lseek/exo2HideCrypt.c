#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <rpc/des_crypt.h>

#define SIZE 8

// ce programme est la version cryptant le fichier à cacher à l'aide d'une clé symétrique

// fonction d'insertion du fichier source à la fin du fichier cible
void insert(char *source, char* cible, char* mdp)
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
    int i=0;
	while(nbLus = read(descSource, buffer, SIZE))
	{
        //encryptage du buffer
        ecb_crypt( mdp, buffer, SIZE, DES_ENCRYPT | DES_HW);
		write(descCible, buffer, SIZE);
		nbTotalLus += nbLus;
	}

	//sérialisaion à la fin du fichier de la taille du fichier caché
	printf("La taille du fichier à cacher est de %i\n", nbTotalLus);
	write(descCible, &nbTotalLus, sizeof(int));
	printf("Fichier %s inseré dans fichier %s !\n", source, cible);
}

//fonction d'extraction du fichier caché
//celui-ci ne sera pas supprimé du fichier qui le contient
void extract(char *source, char* cible, char* mdp)
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
	int offset = sizeof(int)+ ((taille/SIZE)+1)*SIZE  ;
	cur = lseek(descSource, -offset, SEEK_END); //positionnement du cuseur de fichier
	if(cur == -1){
		perror("Erreur d'accès au fichier source: ");
		exit(EXIT_FAILURE);
	}

	char buffer[SIZE];
	int nbLus = 0; //nombre de caractères lus
	int i = 0;

	
	for(i=0; i<(taille/SIZE); i++)
	{
		read(descSource, buffer, SIZE);
		ecb_crypt( mdp, buffer, SIZE, DES_DECRYPT | DES_HW);
		write(descCible, buffer, SIZE);
	}

	read(descSource, buffer, SIZE);
	ecb_crypt( mdp, buffer, SIZE, DES_DECRYPT | DES_HW);
	write(descCible, buffer, taille - (taille/SIZE)*SIZE);

	printf("Extraction de %s terminée !\n", cible);
}

/////////////////////////////////////
// Commande hideCrypt
/////////////////////
int main(int argc, char** argv)
{
	//test pour savoir si un fichier est passé en paramètre
	if(argc != 5)
	{
		printf("USAGE: %s [-i|-e] [source] [cible] [clé]\n", argv[0]);
        printf("La taille de la clé doit être inferieure à 64 octets\n");
		exit(EXIT_FAILURE);
	}	
	
	if(!strcmp("-i", argv[1]))
		insert(argv[2], argv[3], argv[4]);
	
	else if(!strcmp("-e", argv[1]))
		extract(argv[2], argv[3], argv[4]);
	
	return EXIT_SUCCESS;
}