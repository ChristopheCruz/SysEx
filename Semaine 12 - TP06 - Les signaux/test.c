#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <fcntl.h>

char fichier[255];
int cpt = 0;
//focntion de déroutement
void derout(int sig)
{
    printf("Signal %d reçu \n", sig);
    if(sig == SIGINT || sig == SIGQUIT)
        unlink(fichier);
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
    
    sprintf(fichier,"pid-%d",getpid());
    open(fichier, O_CREAT | 0666);

    while(1){
        printf("*");
        fflush(stdout);
        sleep(10);
    }
    return 0;
}