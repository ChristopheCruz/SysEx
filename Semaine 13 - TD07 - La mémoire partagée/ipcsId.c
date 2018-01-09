/* cons.c */

/*
	Ce programme affiche périodiquement le contenu de la 
	mémoire partagée. Arrêt par Contrôle-C
  */

#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <signal.h>
#include <string.h>

#define DELAI 2

void abandon(char message[])
{
	perror(message);
	exit(EXIT_FAILURE);
}

struct donnees {
	int nb;
	int total;
};

int continuer_boucle = 1;

void arreter_boucle(int signal)
{
	continuer_boucle = 0;
}

int main(int argc, char** argv)
 {
	key_t cle;
	int id;
	int longueur;
	
	if(argc!=3)
	{
		printf("USAGE: %s shmId longueur\n", argv[0]);
		exit(1);
	}

	cle = atoi(argv[1]);
	longueur = atoi(argv[2]);

	id = shmget(cle, longueur, 0);
	if (id == -1) 
	{
		switch (errno) 
		{
			case ENOENT:
				abandon("pas de segment\n");	
			default:
				abandon("shmget");
				break;
		}
	}

	char * tab = shmat( id, NULL, SHM_R);
	if (tab == NULL)
		abandon("shmat");

	int i; 
	for(i=0; i<longueur; i++)
		printf("%u ", tab[i]);
	putchar('\n');


	if (shmdt((char *) tab) == -1)
		abandon("shmdt");

	return EXIT_SUCCESS;
 }
 
