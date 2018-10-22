#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* 

    Programmation d'une séquence simple de processus. 
    Un père crée un fils, et visualisation du résultat
*/

int main(int argc, char **argv)
{
    // création d'un procéssus fils
    pid_t pid = fork();
    if(!pid) // si le pid != alors le fils entre dans ce bloque
    {
        sleep(1);
        printf("Je suis le fils mon pid est %i, mon père est %i.\n", getpid(), getppid());
    }else{
        //sleep(1);
        printf("Je suis le père mon pid est %i, mon fils est %i.\n", getpid(), pid);
    }

    return EXIT_SUCCESS;
}