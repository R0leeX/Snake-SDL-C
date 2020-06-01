/**
 * @file Jatek.h
 * @brief
 *
 * Ez a fájl tartalmazza a Jatek függvényen belüli függvényeket.
 *
 * @author Szövő Roland
 */
#ifndef JATEK_H_INCLUDED
#define JATEK_H_INCLUDED
#include <SDL.h>
#include <stdbool.h>
#include <stdlib.h>

#include "Kaja.h"
#include "Kigyo.h"


/**
 * Időzító ami meghívja a SDL_USEREVENT-et.
 * @param ms a időtartam ami alatt meghívja a SDL_USEREVENT-et.
 * @return ms-el tér vissza.
 * @author Szövő Roland
 */
Uint32 idozit(Uint32 ms, void *param);
/**
 *  Kirajzolja a pályát, a falat, a kaját és a kigyókat.
 * @param screen a képernyő.
 * @param kigyo1 az egyes kigyó struktúrája.
 * @param kigyo2 a kettes kigyó struktúrája NULL ha egyjátékos módba van.
 * @param food a kaja struktúrája.
 * @author Szövő Roland
 */
void kirajzol(SDL_Surface *screen, kigyoElem *kigyo1, kigyoElem *kigyo2, food *f);
/**
 * Megnézi, hogy meghalt-e már a kigyó(a falnak, sajátmagának vagy kétjátékos módban egymásnak mentek-e, ha igen akkor a Játék vége függvénybe belép
 * @param screen a képernyő.
 * @param kigyo1 az egyes kigyó struktúrája.
 * @param kigyo2 a kettes kigyó struktúrája NULL ha egyjátékos módba van.
 * @return IGAZ-zal tér vissza ha meghal a kigyó, hamissal ha még nem halt meg.
 * @author Szövő Roland
 */
bool halal(kigyoElem *kigyo1, kigyoElem *kigyo2, SDL_Surface *screen);



#endif // JATEK_H_INCLUDED
