#include <stdio.h>  //pour la fonciton println
#include <stdlib.h> //pour la macro EXIT_SUCCESS

// Programme de test pour la compilation d'un programme C
// utiliser gcc dans la console sous linux ou bash MinGw
// "gcc helloworld.c -o helloworld"

int main(int argc, char ** argv) //point d'entrée du programme C
{
    printf("Hello Wolrd! \n");
    return EXIT_SUCCESS;         //https://www.gnu.org/software/libc/manual/html_node/Exit-Status.html
}


