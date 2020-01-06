#include <pthread.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

#define CLEARSCR "\x1B[2J\x1B[;H" // Clear Screen
#define GOTOYX "\x1B[%.2d;%.2dH" // Goto at (y,x)
#define INSERTMOD "\x1B[4h" // Mode insertion
#define CLEARCDW "\x1B[0J" // Clear Curseur Down
#define CURSOFF "\x1B[?25l" //Cache curseur

#define BALLE O

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;

struct point{
    int x;
    int y;
    int id;
};

//Liste des coordonnées des balles
struct point *points;
int nbThread;

//fonction d'initalisation des coordonnées
void initCoordonnees(int x,int y, struct point* points){
    int i =0;
    while(points[i].id != 0) i++;
    points[i].id = pthread_self();
    points[i].x = x;
    points[i].y = y;
}

//fonction de débug
void affichePoints(struct point* points, int taille){
    int i =0;
    for(i=0; i<taille; i++)
        printf("id %i - x %i - y %i\n", points[i].id, points[i].x, points[i].y);
}

void * tAction (){
    //printf("BALLE id=%i\n", (int)pthread_self());

    //taille de la fenêtre du terminal
    struct winsize w;
    ioctl(0, TIOCGWINSZ, &w);
    
    int color = (rand()%255);
    int background = (rand()%255);

    //initialisation des coordonnées et de idThread
    int x = (rand()%(w.ws_col-6))+3;
    int y = (rand()%(w.ws_row-6))+3;
    int decalx = 1;
    if (rand()%10>5) decalx = -1;
    int decaly = 1;
    if (rand()%10>5) decaly = -1;
    initCoordonnees(x,y, points);

    while(1) {
        pthread_mutex_lock( &mutex1 );
        printf(GOTOYX, y,x);
        printf(" \n");
        pthread_mutex_unlock( &mutex1 );
        if(x>w.ws_col || x<2) {
            decalx=-decalx;
        }
        
        if(y>w.ws_row-3 || y<2) {
            decaly=-decaly;
        }
        x+=decalx;
        y+=decaly;
        int collision = 0;
        int i;
        for(i=0; i<nbThread; i++)
        {
            if(points[i].x==x && points[i].y==y)
            {
                collision = 1;
                printf("Collision %i !!!!", i);
                decalx=-decalx;
                decaly=-decaly;
                break;
            }
        }

        pthread_mutex_lock( &mutex1 );
        printf(GOTOYX, y,x);
        printf("\e\e[38;5;%im%c\n", color,'O');
        pthread_mutex_unlock( &mutex1 );
        usleep(100000);
    }
    printf(CLEARSCR);
    return 0;
}
void main(int argc, char** argv) {
    int i;
    // initialisation de la séquence pseudo-aléatoire
    srand(time(NULL));

    //initialisation de l'écran
    printf(CLEARSCR);
    printf(CURSOFF);
    
    //definition du nombre de thread
    nbThread = atoi(argv[1]);
    pthread_t thread[nbThread];
    int resultat[nbThread];
    
    // initialisation des coordonnées
    points = (struct point*) malloc(sizeof(struct point)*nbThread); 
    for(i=0; i<nbThread; i++)
        points[i].id = 0;

    for(i=0; i<nbThread; i++)
    {
        usleep(10000);
        resultat[i] = pthread_create (&thread[i], NULL, tAction, NULL);
    }    
    
    affichePoints(points, nbThread);


    for(i=0; i<nbThread; i++)
        pthread_join(thread[i], NULL);   
    
}
