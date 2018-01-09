#ifndef BAT_NAV_H
#define BAT_NAV_H

#define SIZE 10
#define MER '~'

//déclaration des matrices
char **tabJ1Bateaux;
char **tabJ2Bateaux;
char **tabJ1Tirs;
char **tabJ2Tirs;

//les signatures des fonctions
char** initMat();
void initMatrice(void);
void afficheMat(char **tab);
void libereMatrices(void);
void libMat(char** mat);

#endif