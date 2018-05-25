#include <SDL_gfxPrimitives.h>
#include <SDL.h>

#include "Jatek.h"
#include "Kigyo.h"
#include "Halal.h"
#include "Kaja.h"
#include "Konstansok.h"

Uint32 idozit(Uint32 ms, void *param) {
    SDL_Event event;
    event.type = SDL_USEREVENT;
    SDL_PushEvent(&event);
    return ms;
}

void Jatek(bool is_multiplayer,SDL_Surface *screen){
    kigyoElem *kigyo1 = (kigyoElem*) malloc(sizeof(kigyoElem));
    kigyo1->K.h = KIGYO_M;
    kigyo1->K.w = KIGYO_SZ;
    kigyo1->K.x = 500;
    kigyo1->K.y = 300;
    kigyo1->kov = NULL;
    kigyo1->eloz = NULL;
    kigyo1->score = 0;
    kigyoElem *kigyo2 = NULL;
    if(is_multiplayer){
        kigyo2 = (kigyoElem*) malloc(sizeof(kigyoElem));
        kigyo2->K.h = KIGYO_M;
        kigyo2->K.w = KIGYO_SZ;
        kigyo2->K.x = 300;
        kigyo2->K.y = 300;
        kigyo2->kov = NULL;
        kigyo2->eloz = NULL;
        kigyo2->score = 0;
    }
    /*hogy egyszerre ne lehessen lenyomni két gombot egy usereventbe mert úgy megfordulna a kigyó*/
    bool gomb = true;
    bool gomb2 = true;

    food f;

    f.F.h=10;
    f.F.w=10;
    f.F.x=(((rand()%77)+1)*10);
    f.F.y=(((rand()%57)+1)*10);

    SDL_Event event;
    SDL_TimerID id;


    id = SDL_AddTimer(100, idozit, NULL); /*idõzítõ*/

    bool quit = false;
    while (!quit) {

        SDL_WaitEvent(&event);


        switch(event.type){


            case SDL_KEYDOWN :
                switch(event.key.keysym.sym){

                    case SDLK_UP:
                        if(kigyo1->i!=le && gomb){
                            kigyo1->i=fel;
                            gomb = false;
                        }
                        break;
                    case SDLK_w:
                        if(kigyo2 != NULL){
                            if(kigyo2->i!=le && gomb2){
                            kigyo2->i=fel;
                            gomb2 = false;
                            }
                        }
                            break;
                    case SDLK_DOWN:
                       if(kigyo1->i!=fel && gomb){
                            kigyo1->i=le;
                       gomb = false;
                       }
                        break;
                    case SDLK_s:
                       if(kigyo2 != NULL){
                       if(kigyo2->i!=fel && gomb2){
                            kigyo2->i=le;
                            gomb2 = false;
                            }
                       }
                        break;
                    case SDLK_RIGHT:
                        if(kigyo1->i!=balra && gomb){
                            kigyo1->i=jobbra;
                            gomb = false;
                        }
                        break;
                    case SDLK_d:
                        if(kigyo2 != NULL){
                        if(kigyo2->i!=balra && gomb2){
                            kigyo2->i=jobbra;
                            gomb2 = false;
                            }
                        }
                        break;
                    case SDLK_LEFT:
                        if(kigyo1->i!=jobbra && gomb){
                            kigyo1->i=balra;
                            gomb = false;
                        }
                        break;
                    case SDLK_a:
                        if(kigyo2 != NULL){
                        if(kigyo2->i!=jobbra && gomb2){
                            kigyo2->i=balra;
                            gomb2 = false;
                            }
                        }
                        break;
                    case SDLK_ESCAPE:
                            quit = true;
                        break;

                    default:
                        break;
                }

                break;

          case SDL_QUIT:
            quit = true;
            break;

          case SDL_USEREVENT:
                /*Egész képernyõ törlése*/
                boxColor(screen,0,0,800,600,0x50b262FF);
                /*Mozgatás*/

                kigyo1 = lepes(kigyo1);
                if (kigyo2 != NULL)
                    kigyo2 = lepes(kigyo2);


                    /*Ha felszed egy kaját*/
                if(kigyo1->K.x == f.F.x && kigyo1->K.y == f.F.y){
                    increaseScore(kigyo1);
                    kigyo1 = noveles(kigyo1);
                    Food(&f);}
                if (kigyo2 != NULL)
                    if(kigyo2->K.x == f.F.x && kigyo2->K.y == f.F.y){
                    increaseScore(kigyo2);
                    kigyo2 = noveles(kigyo2);
                    Food(&f);}
                /*Ujrarajzolas*/
                    kirajzol(screen, kigyo1, kigyo2, &f);
                    gomb = true;
                    if(kigyo2 != NULL)
                    gomb2 = true;
                    /*Ha neki megy a pályának vagy magának*/
                        if(halal(kigyo1, kigyo2, screen))
                            quit = true;

                    break;

        }
    }
     SDL_RemoveTimer(id);
return;
}

void kirajzol(SDL_Surface *screen, kigyoElem *kigyo1, kigyoElem *kigyo2, food *f){
             kigyoElem *mozgo;

                  /*Palya*/
                   int x, y;
                SDL_Rect Fal;
                Fal.h = Falvastagsag;
                Fal.w = Falvastagsag;
                for(Fal.x = 0; Fal.x < 800; Fal.x += 10){
                    for(Fal.y = 0; Fal.y < 600; Fal.y += 10){
                        if(Fal.x == 0 )
                            SDL_FillRect(screen, &Fal, 0xFF003009);
                        else if(Fal.y == 0)
                            SDL_FillRect(screen, &Fal, 0xFF003009);
                        else if ( Fal.x == 790)
                            SDL_FillRect(screen, &Fal, 0xFF003009);
                        else if(Fal.y == 590)
                            SDL_FillRect(screen, &Fal, 0xFF003009);}}

                    /*Kaja*/
                SDL_FillRect(screen, &f->F, 0xFFED0909);

                    /*Kigyo*/
                for(mozgo = kigyo1; mozgo != NULL; mozgo = mozgo->kov)
                    SDL_FillRect(screen, &(mozgo->K), 0xFF003009);
                    char score1[20];
                    sprintf(score1,"Score: Player 1 = %u", kigyo1->score);

                    stringRGBA(screen, 100, 591, score1, 255, 255, 255, 255);
                 if (kigyo2 != NULL){
                        for(mozgo = kigyo2; mozgo != NULL; mozgo = mozgo->kov)
                            SDL_FillRect(screen, &mozgo->K, 0xFF19589C);
                            char score2[20];
                            sprintf(score2, "Player 2 = %u", kigyo2->score);
                            stringRGBA(screen, 300, 591, score2, 255, 255, 255, 255);}



                SDL_Flip(screen);

}
