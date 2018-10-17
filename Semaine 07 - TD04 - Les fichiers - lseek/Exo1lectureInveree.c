#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

// Exercice 1 - se
// C. Cruz - 15/10/2018
// Lecture inversée d'un fichier

int main(int argc, char** argv)
{
    // Vérifiaction des arguments
    if (argc <1)
    {
        printf("USAGE: %s <fichier>\n", argv[0]);
        exit(1);
    }

    // Ouverture du fichier
    int fd = open(argv[1], O_RDONLY);

    // Taille du fichier
    int taille = lseek(fd, 0, SEEK_END);
    printf("Taille fichier: %i\n", taille);

    // Affichage inversée
    int i, nbLu;
    char c = 0;

    for(i=0; i<taille; i++)
    {
        // se positionner sur le caractère à lire
        lseek(fd, -i, SEEK_END);
        nbLu = read(fd, &c, 1);
        putchar(c);
    }
    return 0;
}