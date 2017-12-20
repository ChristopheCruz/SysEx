#include <stdio.h>
#include <stdlib.h>
#include "batnavModule.h"

//initialisation d'une matrice
char** initMat()
{
	//mémoire alloué dans le tas
	int i,j;
	//allocation dynamique
	char **mat=(char**) calloc(SIZE, sizeof(char*));
	for(i=0; i<SIZE; i++)
		mat[i]=(char*) calloc(SIZE, sizeof(char));
		
	//initialisation de la matrice
	for(i=0; i<SIZE; i++)
		for(j=0; j<SIZE; j++)
		{
			mat[i][j]=MER;
		}
	
	return mat;//adresse des données dans le tas
}

//libérartion de l'espace dans le tas
void libMat(char** mat)
{
	int i;
	//libérer chacun des tableaux
	for(i=0; i<SIZE; i++)
		free(mat[i]);
		
	//libération de la mémoire pour le tableau de char*
	free(mat);
}

//affichage d'une matrice
void afficheMat(char **tab)
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

//initialisation des matrices
void initMatrice(void)
{
	tabJ1Bateaux = initMat();
	tabJ2Bateaux = initMat();
	tabJ1Tirs = initMat();
	tabJ2Tirs = initMat();
}

//initialisation des matrices
void libereMatrices(void)
{
	libMat(tabJ1Bateaux);
	libMat(tabJ2Bateaux);
	libMat(tabJ1Tirs);
	libMat(tabJ2Tirs);
}