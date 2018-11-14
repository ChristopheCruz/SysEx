# include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/*
 * Ce programme est un mini bash permettant à l'utilisateur de renseigner des fichiers
 * pour que le programme puisse afficher le contenu à l'écran
 * Le mini bash permettra de se déplacer dans l'arborescence
 * à l'aide des chaines de caractères ** et *.
 */

int main(int argc, char** argv)
{
    char nomFichier[255];

    // boucle infinie, se termine avec la commande \fin
    while(1){
        printf(">");
        scanf("%s", nomFichier);

        // commande pour mettre fin au mini bash
        if(!strcmp(nomFichier, "\\fin"))
            exit(0);
        
        // affiche le contenu du répertoire de travail
        else if(!strcmp(nomFichier, "\\ls")){
            if(!fork())
            {
                execlp("ls","ls",NULL);
                exit(EXIT_FAILURE);
            }
            wait(NULL);
        }

        // affiche le chenmin du répertoire de travail
        else if(!strcmp(nomFichier, "\\pwd")){
            if(!fork())
            {
                execlp("pwd","pwd",NULL);
                exit(EXIT_FAILURE);
            }
            wait(NULL);
        }

        // remonte d'un niveau dans l'arborescence
        else if(!strcmp(nomFichier, "**")){
            chdir("..");
            if(!fork())
            {
                execlp("pwd","pwd",NULL);
                exit(EXIT_FAILURE);
            }
            wait(NULL);
        }

        // descend dans le répertoire passé à la commande
        else if(!strcmp(nomFichier, "*")){
            scanf("%s", nomFichier);
            chdir(nomFichier);
        }
        
        // affiche le contenu du fichier passé au bash
        else {
            if(!fork())
            {
                execlp("cat","cat", nomFichier, NULL);
                exit(EXIT_FAILURE);
            }
            wait(NULL);
        }
    }
    return EXIT_SUCCESS; 
}