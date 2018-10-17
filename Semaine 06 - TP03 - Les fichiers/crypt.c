#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <rpc/des_crypt.h>


//l'encryptage se fait par bloc de taille multiple de 8
int main(int argc, char ** argv)
{
	//definition de la cle de cryptage
	//la taille de la clé doit être inferieur à 64 octets
	char chaine[8] = "bonjour";

	//encryptage d'un bloc de 8 octets
	int status = ecb_crypt( "bonjour", chaine, 8, DES_ENCRYPT | DES_HW);
	int i;
	for (i=0; i<8; i++)
		putchar(chaine[i]);
	putchar('\n');

	//encryptage du meme bloc de 8 octets
	status = ecb_crypt( "bonjour", chaine, 8, DES_DECRYPT | DES_HW);
	for (i=0; i<8; i++)
		putchar(chaine[i]);
	putchar('\n');

	return 0;
}