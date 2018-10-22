
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX 10000
/* 
    Accès concurrentiel à un fichier
    cat temp.txt | more
*/

int main(int argc, char **argv)
{
    int i = 0;
    //creation d'un fichier
    int fd = open("temp.txt", O_WRONLY|O_CREAT|O_TRUNC);

    // création d'un procéssus fils
    pid_t pid = fork();
    if(fork()) // si le pid != alors le fils entre dans ce bloque
    {
        for(i=0; i<MAX; i++)
            write(fd, "F", 1);
        close(fd);
    }
    
    if(fork()){
        for(i=0; i<MAX; i++)
            write(fd, "P", 1);
        close(fd);
    }
    wait(0);
    wait(0);
    return EXIT_SUCCESS;
}