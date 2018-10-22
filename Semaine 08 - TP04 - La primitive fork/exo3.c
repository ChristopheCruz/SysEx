
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX 10000
/* 
    L'objectif est la visualisation de l'exécution en concurrence du processus père et fils.
    L'affiche des "printf" s'alterne entre les processus père et le fils
*/

int main(int argc, char **argv)
{
    int i = 0;
    // création d'un procéssus fils
    pid_t pid = fork();
    if(!pid) // si le pid != alors le fils entre dans ce bloque
    {
        for(i=0; i<MAX; i++)
            printf("Je suis le fils mon pid est %i, mon père est %i.\n", getpid(), getppid());
    }else{
        for(i=0; i<MAX; i++)
            printf("Je suis le père mon pid est %i, mon fils est %i.\n", getpid(), pid);
    }

    return EXIT_SUCCESS;
}