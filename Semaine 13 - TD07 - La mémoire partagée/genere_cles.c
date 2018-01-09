/* binaire : genere_cle */
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <stdlib.h>
#include <stdio.h>

struct stat buf;

int main(int argc, char ** argv)
{
	printf("nom du fichier %s\n", argv[1]);
        if(stat(argv[1], &buf) == -1)
		{
                printf("fichier %s inexistant\n", argv[1]);
				exit(1);
		}
        printf("numero d'index: %d\n", buf.st_ino); \\tester "ls -i"
        printf("Cle associe au numero 0: %x\n", (int)ftok(argv[1], 0));
        printf("Cle associe au numero 1: %x\n", (int)ftok(argv[1], 1));

	return 0;
}

