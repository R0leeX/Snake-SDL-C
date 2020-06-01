#include <SDL.h>
#include <SDL_gfxPrimitives.h>
#include <SDL_ttf.h>

#include "Ranglista.h"
#include "Konstansok.h"

void ranglista_hozzaad(SDL_Surface *screen, kigyoElem *kigyo1, kigyoElem *kigyo2){


     TTF_Font *font;
        font = TTF_OpenFont("arial.ttf", 32);
    if (!font) {
        fprintf(stderr, "Nem sikerult megnyitni a fontot! %s\n", TTF_GetError());
        exit(1);
    }

    char nev[20+1];
    int i = 0;
    FILE *fp;
    top5 jatekos[6];

    fp = fopen("ranglista.txt", "rt"); /* beolvasás*/
    if(fp != NULL){
        while( i < 5 && fscanf(fp,"%s %u\n",jatekos[i].nev, &jatekos[i].score) != EOF)
            i++;
        fclose(fp);
    }
    /* AZ i értéke annyi lesz, ahány elemet beolvastunk. MAX 5.*/
    /*megvannak a fájlban lévõ pontszámok, hozzárakhatjuk az újat.*/
      if(kigyo1 != NULL){
             /*név beolvasása*/
    nev_beolvas(nev, screen, font);
            /*Adatok másolása, gyöztes eldöntése */
        strcpy(jatekos[i].nev, nev);
        if(kigyo2 == NULL)
            jatekos[i].score = kigyo1->score;
        else if (kigyo1->score < kigyo2->score)
            jatekos[i].score = kigyo2->score;
        else
            jatekos[i].score = kigyo1->score;

    ++i;

    /*Rendezzük*/
    tomb_rendez(jatekos, i);
    }

    /*Majd az elsõ 5 elemet írjuk ki, ha van annyi, ha nincs annyit amennyi van.*/
    if(i>5)
        --i;
    fp = fopen("ranglista.txt", "wt");
    int j;
    for(j=0; j<i; ++j)
        fprintf(fp, "%s %u\n", jatekos[j].nev, jatekos[j].score);
    /*Kiíjuk a ranglistát*/
    ranglista_kiiras(screen, jatekos, font, i);


    fclose(fp);
return;}

void tomb_rendez(top5 *jatekos,int jatekosdb){
    int i, j;

   for (i = jatekosdb-1; i > 0; --i)

      for (j = 0; j < i; ++j)
         if (jatekos[j+1].score > jatekos[j].score) {
            top5 temp = jatekos[j];
            jatekos[j] = jatekos[j+1];         /* csere */
            jatekos[j+1] = temp;
         }
}

        /*SDL A billentyûzet kezelése infoc.eet.bme.hu*/
bool input_text(char *dest, int x, int y, int sz, int m, SDL_Color hatter, SDL_Color szin, TTF_Font *font, SDL_Surface *screen) {
    SDL_Rect forras = { 0, 0, sz, m}, cel = { x, y, sz, m };

    SDL_Event event;

    int hossz = 0;
    dest[hossz] = 0x0000;   /* lezaro 0 */
    SDL_EnableUNICODE(1);
    bool enter = false;
    bool kilep = false;
    while (!kilep && !enter) {
        /* szoveg kirajzolasa */
        boxRGBA(screen, x, y, x + sz - 1, y + m - 1, hatter.r, hatter.g, hatter.b, 255);
        felirat = TTF_RenderText_Blended(font, dest, szin);
        SDL_BlitSurface(felirat, &forras, screen, &cel);
        SDL_FreeSurface(felirat);
        rectangleRGBA(screen, x, y, x + sz - 1, y + m - 1, 0, 255, 0, 255);
        /* updaterect: mint az sdl_flip, de csak a kepernyo egy darabjat */
        SDL_UpdateRect(screen, x, y, sz, m);

        SDL_WaitEvent(&event);
        switch (event.type) {
            case SDL_KEYDOWN:
                switch (event.key.keysym.unicode) {
                    case 0x0000:
                        /* nincs neki megfelelo karakter (pl. shift gomb) */
                        break;
                    case '\r':
                    case '\n':
                        /* enter: bevitel vege */
                        enter = true;
                        break;
                    case '\b':
                        /* backspace: torles visszafele, ha van karakter */
                        if (hossz > 0)
                            dest[--hossz] = 0x0000;
                        break;
                    default:
                        /* karakter: tombbe vele, plusz lezaro nulla */
                        dest[hossz++] = event.key.keysym.unicode;
                        dest[hossz] = 0x0000;
                        break;
                    }
                break;
            case SDL_QUIT:
                /* visszatesszuk a sorba ezt az eventet, mert
                 * sok mindent nem tudunk vele kezdeni */
                SDL_PushEvent(&event);
                kilep = true;
                break;
        }
    }

    /* igaz jelzi a helyes beolvasast; = ha enter miatt allt meg a ciklus */
    return enter;
}

void nev_beolvas(char* nev, SDL_Surface *screen,  TTF_Font *font){

    SDL_EnableKeyRepeat(500, 30);
    SDL_Color feher = {255, 255, 255}, fekete = { 0, 0, 0 };

      SDL_Flip(screen);
    input_text(nev, 200, 300, 400, 40, fekete, feher, font, screen);

}

void ranglista_kiiras(SDL_Surface *screen, top5 *jatekos,  TTF_Font *font, int j){

        SDL_Surface *feliratRanglista;
        SDL_Event event;
        int i;


        boxColor(screen, 0, 0, screen->w, screen->h, 0x000000FF);
            /*Háttér*/
         for (i = 0; i < 500; ++i)
        lineRGBA(screen, rand() % screen->w, rand() % screen->h, rand() % screen->w, rand() % screen->h,
                 rand() % 256, rand() % 256, rand() % 256, 64);


         feliratRanglista = TTF_RenderText_Blended(font, "Highscores", feher);
        hely.x = (screen->w - feliratRanglista->w) /2  + 2;
        hely.y = 50;
        SDL_BlitSurface(feliratRanglista, NULL, screen, &hely);
        SDL_FreeSurface(feliratRanglista);


        for(i = 0; i < j; ++i){
                /*Nevek*/
                if (jatekos[i].nev != 0x0000) {
       char sor[100];
                sprintf(sor,"%s %u",jatekos[i].nev, jatekos[i].score);
        felirat = TTF_RenderText_Blended(font, sor, feher);
        hely.x = (screen->w - felirat->w) / 2 + 2;
        hely.y = 200+50*i;
        SDL_BlitSurface(felirat, NULL, screen, &hely);
        SDL_FreeSurface(felirat);}
        }

        felirat = TTF_RenderText_Blended(font, "Press 0 to exit", feher);
        hely.x = (screen->w - felirat->w) / 2 + 2;
        hely.y = 500;
        SDL_BlitSurface(felirat, NULL, screen, &hely);
        SDL_FreeSurface(felirat);


        SDL_Flip(screen);
        TTF_CloseFont(font);
        bool quit = false;
    while(!quit){
        SDL_WaitEvent(&event);

        switch(event.type){
            case SDL_KEYDOWN :
                switch(event.key.keysym.sym){

                    case SDLK_BACKQUOTE:  /*0 a magyar billentyûzeten*/
                    quit = true;
                    return;
                        break;
                    case  SDLK_KP0:
                    quit = true;
                    return;
                        break;
                    default:
                        break;
                }

        case SDL_QUIT:
                /* visszatesszuk a sorba ezt az eventet, mert
                 * sok mindent nem tudunk vele kezdeni */
                SDL_PushEvent(&event);
                quit = true;
                break;
            }
    }

}
