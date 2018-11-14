#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

/*
 * Exemple 2: Exécusion d'une commande en paramètre
 * exemple : a.out ls -l
 */

int main(int argc, char** argv)
{
	if(argc <2 )
	{
		fprintf(stderr, "Usage: %s commande [arg1] [arg2] ...\n", argv[0]);
		exit(1);
	}
	execvp(argv[1], argv+1);
	perror("execvp erreur !\n");
	exit(1);
}
