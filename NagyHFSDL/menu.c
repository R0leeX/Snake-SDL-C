#include <SDL.h>
#include <SDL_gfxPrimitives.h>
#include <stdbool.h>
#include <SDL_ttf.h>

#include "menu.h"
#include "Ranglista.h"
#include "Jatek.h"


void Menu(SDL_Surface *screen, bool* quit){
    int i;

    TTF_Font *font;
     font = TTF_OpenFont("arial.ttf", 32);
    if (!font) {
        fprintf(stderr, "Nem sikerult megnyitni a fontot! %s\n", TTF_GetError());
        exit(1);
    }


    SDL_Event event;
    boxColor(screen, 0, 0, screen->w, screen->h, 0x000000FF); /* Képernyõ törlés*/
    /*Háttér*/
     for (i = 0; i < 500; ++i)
        lineRGBA(screen, rand() % screen->w, rand() % screen->h, rand() % screen->w, rand() % screen->h,
                 rand() % 256, rand() % 256, rand() % 256, 64);

    felirat = TTF_RenderText_Blended(font, "1    Singleplayer", feher);
        hely.x = (screen->w - felirat->w) /2  + 2;
        hely.y = 100;
        SDL_BlitSurface(felirat, NULL, screen, &hely);
        SDL_FreeSurface(felirat);
    felirat = TTF_RenderText_Blended(font, "2    Multiplayer", feher);
        hely.x = (screen->w - felirat->w) /2  + 2;
        hely.y = 200;
        SDL_BlitSurface(felirat, NULL, screen, &hely);
        SDL_FreeSurface(felirat);
    felirat = TTF_RenderText_Blended(font, "3    Highscores", feher);
        hely.x = (screen->w - felirat->w) /2  + 2;
        hely.y = 300;
        SDL_BlitSurface(felirat, NULL, screen, &hely);
        SDL_FreeSurface(felirat);
    felirat = TTF_RenderText_Blended(font, "0    Exit", feher);
        hely.x = (screen->w - felirat->w) /2  + 2;
        hely.y = 400;
        SDL_BlitSurface(felirat, NULL, screen, &hely);
        SDL_FreeSurface(felirat);
    felirat = TTF_RenderText_Blended(font, "Created by R0leeX", feher);
        hely.x = 500;
        hely.y = 500;
        SDL_BlitSurface(felirat, NULL, screen, &hely);
        SDL_FreeSurface(felirat);

    SDL_Flip(screen);

    while(!*quit){
        SDL_WaitEvent(&event);

        switch(event.type){
            case SDL_KEYDOWN :
                switch(event.key.keysym.sym){
                        /** egyjatekos mód*/
                    case SDLK_1 :
                        Jatek(false, screen);
                        return;
                        break;
                    case SDLK_KP1:
                        Jatek(false, screen);
                        return;
                        break;
                        /**ketjatekos mód*/
                    case SDLK_2 :
                        Jatek(true, screen);
                        return;
                        break;
                    case SDLK_KP2:
                        Jatek(true, screen);
                        return;
                        break;
                        /**  ranglista*/
                    case SDLK_3:

                        ranglista_hozzaad(screen, NULL, NULL);
                        return;
                        break;
                    case SDLK_KP3:

                        ranglista_hozzaad(screen, NULL, NULL);
                        return;
                        break;
                        /**kilépés*/
                    case SDLK_BACKQUOTE:  /*0 a magyar billentyûzeten*/
                    *quit = true;
                        break;
                        case  SDLK_KP0:
                    *quit = true;
                        break;
                    default:
                        break;
                }

        }
    }
}

