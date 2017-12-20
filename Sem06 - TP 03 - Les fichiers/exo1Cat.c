#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

//Commande cat
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
		printf("Erreur de l'ouverture du fichier %s \n", argv[1]);
		perror("Open ");
		exit(1);
	}
		
	//affiche du contenu
	char c;
	while(read(fd, &c, 1))
		putchar(c);
	
	//fermeture du fichier
	close(fd);
		
	return 0;
}
		
