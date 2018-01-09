#include <stdio.h>  
#include <stdlib.h> 
 
#define _SIZE_ 10
#define _MER_ '~'

// déclaration des matrices de jeux, bâteaux et tirs des deux joueurs 
char J1Bateaux[_SIZE_][_SIZE_];
char J2Bateaux[_SIZE_][_SIZE_];
char J1Tirs[_SIZE_][_SIZE_];
char J2Tirs[_SIZE_][_SIZE_];

//initialisation d'un matrice de jeu sans bâteaux
void initMatrice(char tab[_SIZE_][_SIZE_])
{
    int i,j;
    for(i=0; i<_SIZE_; i++)
    {
        for(j=0; j<_SIZE_; j++)
        {
            tab[i][j] = _MER_;
        }
    }
}

//affichage d'un matrice de jeu
void afficheMatrice(char tab[_SIZE_][_SIZE_])
{
    int i,j;
    for(i=0; i<_SIZE_; i++)
    {
        for(j=0; j<_SIZE_; j++)
        {
            putchar(tab[i][j]);
            putchar(' ');
        }
        putchar('\n'); // attention 'a' pour un cactère et "aaa" pour une chaîne de caractères 
    }
}

//Programme principal de la bataille navale

int main(int argc, char ** argv)
{
    //initialisation de la matrice de bâteaux du joueur 1 (vide)
    initMatrice(J1Bateaux);
    //affichage de cette matrice de bâteaux
    afficheMatrice(J1Bateaux);
    return EXIT_SUCCESS; 
}
