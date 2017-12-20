#include <stdio.h>
#include <stdlib.h>

//Programme d'affiche des adresses des cellules
// d'un tableau alloué de manière statique
// et de manière dynamique


int main(int argc, char**argv)
{
	int const TAILLE = 3;
	//allocation statique d'un tableau à 2 dimensions
	int tab[TAILLE][TAILLE];
	
	//allocation dynamique d'un tableau à 2 dimensions
	int** tabDynamique = (int**)calloc(TAILLE, sizeof(int*));
	int i, j;
	for(i = 0 ; i < TAILLE ; i++)
	{
		tabDynamique[i] = (int*)calloc(TAILLE, sizeof(int));
	}
	
	//affichage des adresses des cellules du tableau statique
	printf("Tableau statique\ntab=%p\n", &tab);
	for(i = 0; i < TAILLE ; i++)
	{
		printf("tab[%i] = #%p\n", i, &tab[i]);
		for(j = 0; j < TAILLE ; j++)
		{
			printf("tab[%i][%i] = #%p\n", i, j, &tab[i][j]);
		}
	}
	
	//affichage des adresses des cellules du tableau dynamique
	printf("Tableau dynamique\ntabDyn=%p\n", &tabDynamique);
	for(i = 0; i < TAILLE ; i++)
	{
		printf("tabDyn[%i] = #%p\n", i, &tabDynamique[i]);
		for(j = 0; j < TAILLE ; j++)
		{
			printf("tabDyn[%i][%i] = #%p\n", i, j, &tabDynamique[i][j]);
		}
	}
}
