#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <fcntl.h>
#include <string.h>

/*
 * Programme de test des signaux
 * et des déroutements
 */
char fichier[255];
int cpt = 0;

//fonction de déroutement
void derout(int sig)
{
    printf("Signal %d/%s reçu \n", sig, strsignal(sig));
    if(sig == SIGINT || sig == SIGQUIT)
        unlink(fichier); //suppression du fichier temporaire
    if(sig == SIGQUIT) exit(0);
    if(sig == SIGUSR1) cpt++;
    if(cpt == 2) 
    {
        signal(SIGINT, SIG_DFL);
        signal(SIGQUIT,  SIG_DFL);
        signal(SIGUSR1,  SIG_DFL);
        signal(SIGUSR2,  SIG_DFL);
    }
}

int main(int argc, char **argv)
{
    //déroutements
    signal(SIGINT, derout);
    signal(SIGQUIT, derout);
    signal(SIGUSR1, derout);
    signal(SIGUSR2, derout);
   
    //création du fichier temporaire 
    sprintf(fichier,"%s/pid-%d", getenv("HOME"), getpid());
    open(fichier, O_CREAT | 0666);
    printf(fichier, "Nom du fichier temporaire: %s \n\n", fichier);	

    //boucle infinie
    while(1){
        printf("*");
        fflush(stdout);
        sleep(5);
    }
    return 0;
}
