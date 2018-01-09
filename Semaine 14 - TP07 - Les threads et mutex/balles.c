#include <pthread.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <time.h>
#define CLEARSCR "\x1B[2J\x1B[;H" // Clear Screen
#define GOTOYX "\x1B[%.2d;%.2dH" // Goto at (y,x)
#define INSERTMOD "\x1B[4h" // Mode insertion
#define CLEARCDW "\x1B[0J" // Clear Curseur Down
#define CURSOFF "\x1B[?25l" //Cache curseur

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;



void * tAction (){
    int x = (rand()%10)+3;
    int y = (rand()%10)+3;
    int decalx = 1;
    if (rand()%10>5) decalx = -1;
    int decaly = 1;
    if (rand()%10>5) decaly = -1;

    struct winsize w;
    ioctl(0, TIOCGWINSZ, &w);

    /*printf ("lines %d\n", w.ws_row);
    printf ("columns %d\n", w.ws_col);*/

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
        pthread_mutex_lock( &mutex1 );
        printf(GOTOYX, y,x);
        printf("0\n");
        pthread_mutex_unlock( &mutex1 );
        usleep(100000);
    }
    printf(CLEARSCR);
    return 0;
}
void main() {
    srand(time(NULL));
    printf(CLEARSCR);
    printf(CURSOFF);
    pthread_t thread1, thread2, thread3;
    int resultat1, resultat2, resultat3;
    resultat1 = pthread_create (&thread1, NULL, tAction, NULL);
    resultat2 = pthread_create (&thread2, NULL, tAction, NULL);
    resultat3 = pthread_create (&thread3, NULL, tAction, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);
}
