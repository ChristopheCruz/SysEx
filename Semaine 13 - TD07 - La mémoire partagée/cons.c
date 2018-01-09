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
	struct donnees *commun;
	struct sigaction a;

	cle = ftok(argv[1], 1);
	if (cle == -1)
		abandon("ftok");

	id = shmget(cle, sizeof(struct donnees), 0);
	if (id == -1) 
	{
		switch (errno) 
		{
			case ENOENT:
				abandon("pas de segment\n");	
			default:
				abandon("shmget");
			}
		}

		commun = (struct donnees *) shmat(id, NULL, SHM_R);
		if (commun == NULL)
			abandon("shmat");
		
		continuer_boucle = 1;

		signal(SIGINT, arreter_boucle);

		while (continuer_boucle) {
			sleep(DELAI);
			printf("sous-total %d= %d\n", commun->nb, commun->total);
		}

		printf("---\n");
		if (shmdt((char *) commun) == -1)
			abandon("shmdt");

		return EXIT_SUCCESS;
 }
 
