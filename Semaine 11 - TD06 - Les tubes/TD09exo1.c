//###############################################################
//#								#
//# exo1: TD09 les tubes					#
//#								#
//# remarque: 					  		#
//#								#
//###############################################################
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

//###############################################################
//#	fonction de conversion des caractères			#
//###############################################################
char conv(char c){
	if(c>='a' && c<'z')
		c-=32;
	else
	if(c>='A' && c<'Z')
		c+=32;

	return c;
}


//###############################################################
//#	fonction principale					#
//###############################################################
int main(int argc, char** argv)
{
	int count[255]; //permet de comptabiliser les caractères
	int i=0;
	for(i=0; i<255; i++)	
		count[i]=0; //initialisation du tableau
	char c;		//pour le transfert des caractères	
	int fd[2]; 	//descripteur du tube
	pipe(fd); 	//création du tube
	
	if(!fork()) 	//le père
	{
		close(fd[0]); 	//fermeture du descripteur pipe out
		fprintf(stdout,"Saisissez des caractères, terminez par Ctrl+D.\n");
		while ((c=getchar()) != EOF )
		{
			write(fd[1], &c, 1);
		}

		close(fd[1]); 	//fermeture du descripteur pipe in, broken pipe
		//attente de la fin du fils, sinon pas de traitement complet
		wait(NULL); 		

	}else{		//le fils

		close(fd[1]); 	//fermeture du descripteur pipe in
		while(read(fd[0], &c, sizeof(char) )) // boucle jusqu'au broken pipe, plus de rédacteur
		{						
			putchar(conv(c));
			count[c]++;
		}
		for(i=34; i<128; i++){	
			printf("count[%c]=%i\n", i, count[i]);		
		}	
	}
	return 0;
}
	
