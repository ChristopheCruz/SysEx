#ifndef BAT_NAV_H
#define BAT_NAV_H

#define SIZE 10
#define MER '~'

//déclaration des matrices
char tabJ1Bateaux[SIZE][SIZE];
char tabJ2Bateaux[SIZE][SIZE];
char tabJ1Tirs[SIZE][SIZE];
char tabJ2Tirs[SIZE][SIZE];

//les signatures des fonctions
void initMat(char tab[SIZE][SIZE]);
void initMatrice(void);
void afficheMat(char tab[SIZE][SIZE]);

#endif