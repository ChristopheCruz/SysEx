
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* 
    Programme pour tester le synchronisation entre le père et le fils
*/

int main(int argc, char **argv)
{
    int i = 0;
    // création d'un procéssus fils
    pid_t pid = fork();
    if(!pid) // si le pid != alors le fils entre dans ce bloque
    {
        printf("Je suis le fils mon pid est %i, mon père est %i.\n", getpid(), getppid());
    }else{
        wait(NULL); //le pid n'est pas spécifier, le premier procéssus zombi fils sera éliminé.
        printf("Je suis le père mon pid est %i, mon fils est %i.\n", getpid(), pid);
    }

    return EXIT_SUCCESS;
}