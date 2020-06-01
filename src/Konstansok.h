/**
 * @file Konstansok.h
 * @brief
 *
 * Ez a fájl tartalmazza a konstansokat.
 *
 * @author Szövő Roland
 */
#ifndef KONSTANSOK_H_INCLUDED
#define KONSTANSOK_H_INCLUDED

#include <SDL.h>
#include <SDL_gfxPrimitives.h>
/**Itt definiálom irányokat*/
typedef enum irany{
        fel = 1,
        balra = 2,
        le = 3,
        jobbra = 4
}irany;

enum{
    KIGYO_SZ = 10,
    KIGYO_M = 10,
    Falvastagsag = 25
};
static SDL_Surface  *felirat;
static SDL_Rect hely;
static SDL_Color feher = {255, 255, 255};

#endif // KONSTANSOK_H_INCLUDED
