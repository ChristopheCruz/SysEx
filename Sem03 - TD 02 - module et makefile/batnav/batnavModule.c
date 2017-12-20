#include <stdio.h>
#include "batnavModule.h"

//initialisation d'une matrice
void initMat(char tab[SIZE][SIZE])
{
		int i,j;
		for(i=0; i<SIZE; i++)
			for(j=0; j<SIZE; j++)
			{
				tab[i][j]=MER;
			}
}

//initialisation des matrices
void initMatrice(void)
{
	initMat(tabJ1Bateaux);
	initMat(tabJ2Bateaux);
	initMat(tabJ1Tirs);
	initMat(tabJ2Tirs);
}

//affichage d'une matrice
void afficheMat(char tab[SIZE][SIZE])
{
		int i,j;
		for(i=0; i<SIZE; i++)
		{
			for(j=0; j<SIZE; j++)
			{
				putchar(tab[i][j]);
				putchar(' ');
			}
			putchar('\n');
		}
}