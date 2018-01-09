#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#define SIZE 2048

//Commande cat
//Version avec buffer
int main(int argc, char** argv)
{
	//test pour savoir si un fichier est passé en paramètre
	if(argc != 2)
	{
		printf("USAGE: %s [fichier]\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	
	//ouverture du fichier
	int fd = open(argv[1], O_RDONLY);
	if(fd == -1)
	{
		printf("Erreur lors de l'ouverture du fichier %s \n", argv[1]);
		perror("Open ");
		exit(1);
	}
		
	//affiche du contenu
	char buffer[SIZE];
	int nbLus = 0; //nombre de caractères lus
	while(nbLus = read(fd, buffer, SIZE))
	{
		buffer[nbLus]='\0'; //pour que le pritf ne lire pas le buffer entièrement
		printf("%s", buffer);
	}
	
	//fermeture du fichier
	close(fd);
		
	return 0;
}
		
