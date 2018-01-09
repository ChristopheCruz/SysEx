/* prod.c */

/*
          Ce programme lit une suite de nombres, et effectue le cumul dans une
         variable en mémoire partagée. */

#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

void abandon(char message[])
{
	perror(message);
	exit(EXIT_FAILURE);
}

struct donnees {
	int nb;
	int total;
 };

 int main(int argc, char** argv)
 {
	key_t cle;
	int id;
	struct donnees *commun;
	int reponse;

	cle = ftok(argv[1], 1);
	if (cle == -1)
		abandon("ftok");

	id = shmget(cle, sizeof(struct donnees), IPC_CREAT | IPC_EXCL | 0666);
 
	if (id == -1) {
		switch (errno) {
		case EEXIST:
			abandon("Note: le segment existe déjà\n");
		default:
			abandon("shmget");
		}
	}
 
	commun = (struct donnees *) shmat(id, NULL, SHM_R | SHM_W);
 
	if (commun == NULL)
		abandon("shmat");

	commun->nb = 0;
	commun->total = 0;

	while (1) {
		printf("+ ");
		if (scanf("%d", &reponse) != 1)
			break;
		commun->nb++;
		commun->total += reponse;
		printf("sous-total %d= %d\n", commun->nb, commun->total);
	}
	printf("---\n");

	if (shmdt((char *) commun) == -1)
		abandon("shmdt");

	/* suppression segment */
	if (shmctl(id, IPC_RMID, NULL) == -1)
		abandon("shmctl(remove)");

	return EXIT_SUCCESS;
}
