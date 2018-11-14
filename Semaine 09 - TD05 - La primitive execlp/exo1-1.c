#include <stdio.h>
#include <errno.h>
#include <unistd.h>

/*
 * Exemple 1: "les petits ruisseux font les grandes rivières"
 */

int main(int argc, char** argv)
{
	printf("Les petits ruisseaux ");
	fflush(stdout);
	execlp("/bin/echo", "echo", "font les grandes", "rivières", NULL);
	//     |	    |       |                     |          |
	//     -> chemin    -> nom  -> premier paramètre  -> deuxième-> fin des paramètres	
	//	 de la 	       de la                        paramètre
	//	 commande    commande
	perror("Excel erreur !\n");
	fflush(stdout); // Pour viderr le buffer de sortie standard
	return 0;
}
