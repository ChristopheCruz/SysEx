#include <stdio.h>
#include "batnavModule.h"

//programme principal
int main(int argc, char** argv)
{
	initMatrice();
	afficheMat(tabJ1Bateaux);
	libereMatrices();
	return 0;
}