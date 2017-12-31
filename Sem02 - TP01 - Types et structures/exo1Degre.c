#include <stdio.h>  
#include <stdlib.h> 

float c; // degré celsius - variable globale

//programme de calcul de conversion des °F en °c
int main(int argc, char ** argv) //point d'entrée du programme C
{
    int f; //degré Fahrenheit - variable locale

    for(f=0; f<300; f+=30)
    {
        c = (5.0/9)*(f-32);
        printf("%f C <=> %d F\n", c, f);
    }

    //complément sur les segments de mémoire
    printf("Segment de données: %p\n", &c); //%p affiche formaté d'une adresse, & opérateur d'adressage donnant l'adresse d'une variable
    printf("Segment de pile: %p\n", &f); //%p affiche formaté d'une adresse, & opérateur d'adressage donnant l'adresse d'une variable

    return EXIT_SUCCESS; 
}


