
#include <SDL_ttf.h>û

#include "Halal.h"
#include "Ranglista.h"


bool halal(kigyoElem *kigyo1, kigyoElem *kigyo2, SDL_Surface *screen){
     kigyoElem *mozgo1, *mozgo2;

            /*kigyó1*/
    if(kigyo1->K.x == 0 || kigyo1->K.x == 790 || kigyo1->K.y == 0 || kigyo1->K.y == 590){
        JatekVege(screen, kigyo1, kigyo2);
        return true;
        }
    for (mozgo1 = kigyo1; mozgo1->kov != NULL; mozgo1 = mozgo1->kov){
        for(mozgo2 = mozgo1->kov; mozgo2->kov != NULL; mozgo2 = mozgo2->kov)
            if(mozgo1->K.x == mozgo2->K.x && mozgo1->K.y == mozgo2->K.y){
                JatekVege(screen, kigyo1, kigyo2);
                return true;
                }
    }
            /*kigyó2*/
      if(kigyo2 != NULL){
      if(kigyo2->K.x == 0 || kigyo2->K.x == 790 || kigyo2->K.y == 0 || kigyo2->K.y == 590){
        JatekVege(screen, kigyo1, kigyo2);
        return true;
        }
    for (mozgo1 = kigyo2; mozgo1->kov != NULL; mozgo1 = mozgo1->kov){
        for(mozgo2 = mozgo1->kov; mozgo2->kov != NULL; mozgo2 = mozgo2->kov)
            if(mozgo1->K.x == mozgo2->K.x && mozgo1->K.y == mozgo2->K.y){
                JatekVege(screen, kigyo1, kigyo2);
                return true;
                }
    }
    /*Ha egymásnak mennek*/

    for (mozgo1 = kigyo1; mozgo1!= NULL; mozgo1 = mozgo1->kov){
        for(mozgo2 = kigyo2; mozgo2 != NULL; mozgo2 = mozgo2->kov)
            if(mozgo1->K.x == mozgo2->K.x && mozgo1->K.y == mozgo2->K.y){
               JatekVege(screen, kigyo1, kigyo2);
                return true;
                }
            }
      }

    return false;
}

void JatekVege(SDL_Surface *screen, kigyoElem *kigyo1, kigyoElem *kigyo2){

    TTF_Init();
    TTF_Font *font;
    int i;
        font = TTF_OpenFont("arial.ttf", 32);
    if (!font) {
        fprintf(stderr, "Nem sikerult megnyitni a fontot! %s\n", TTF_GetError());
        exit(1);
    }

      boxColor(screen, 0, 0, screen->w, screen->h, 0x000000FF); /*Letörli a képernyőt*/
     /*Kirajzolja  a hátteret*/
      for (i = 0; i < 500; ++i)
        lineRGBA(screen, rand() % screen->w, rand() % screen->h, rand() % screen->w, rand() % screen->h,
                 rand() % 256, rand() % 256, rand() % 256, 64);



     felirat = TTF_RenderText_Blended(font, "Game Over", feher);
        hely.x = (screen->w - felirat->w) /2  + 2;
        hely.y = 50;
        SDL_BlitSurface(felirat, NULL, screen, &hely);
        SDL_FreeSurface(felirat);

    felirat = TTF_RenderText_Blended(font, "Name:", feher);
        hely.x = (screen->w - felirat->w) /2  + 2;
        hely.y = 100;
        SDL_BlitSurface(felirat, NULL, screen, &hely);
        SDL_FreeSurface(felirat);

        /*Megnézi, hogy melyik játékosnak van több pontja, és aszerint kiírja, hogy melyik nyert*/
    if(kigyo2 != NULL ){
        if( kigyo1->score < kigyo2->score)
            felirat = TTF_RenderText_Blended(font, "2. Player Won ", feher);
        else if(kigyo1->score > kigyo2->score)
            felirat = TTF_RenderText_Blended(font, "1. Player Won ", feher);
        else
            felirat = TTF_RenderText_Blended(font, "Drawn", feher);

        hely.x = (screen->w - felirat->w) /2  + 2;
        hely.y = 150;
        SDL_BlitSurface(felirat, NULL, screen, &hely);
        SDL_FreeSurface(felirat);
        }
        /*Beolvassa a fájlból az adatokat, bekéri az új játékos nevét, rendezi a  meglévő adatokat és beleírja a fájlba*/
    ranglista_hozzaad(screen, kigyo1, kigyo2);


return;}
