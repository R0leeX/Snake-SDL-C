#include <stdbool.h>
#include <SDL.h>
#include <SDL_gfxPrimitives.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL_ttf.h> /* SDL szöveg*/
#include <time.h>

#include <SDL.h>
#include <SDL_gfxPrimitives.h>
#include <stdbool.h>


#include "menu.h"

int main(int argc, char *argv[]) {

    srand(time(0));
    TTF_Init();

    SDL_Surface *screen;

    /* SDL inicializálása és ablak megnyitása */

    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);

    screen = SDL_SetVideoMode(800, 600, 0, SDL_ANYFORMAT);

    if (!screen) {
        fprintf(stderr, "Nem sikerult megnyitni az ablakot!\n");
        exit(1);
    }
    bool quit = false;
    do{
    Menu(screen, &quit);
    }while(!quit);

    return 0;
}

