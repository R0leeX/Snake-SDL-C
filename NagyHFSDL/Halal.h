/**
 * @file Halal.h
 * @brief
 *
 * Ez a fájl tartalmazza a Halal függvényen belüli függvényeket.
 *
 * @author Szövő Roland
 */
#ifndef HALAL_H_INCLUDED
#define HALAL_H_INCLUDED
#include <SDL.h>
#include "Kigyo.h"

/**
 * Bekéri a játékos nevét, módosítja a ranglistát és kiírja azt.
 * @param screen a képernyő.
 * @param kigyo1 és kigyo2 struktúrája.
 * @author Szövő Roland
 */
void JatekVege(SDL_Surface *screen, kigyoElem *kigyo1, kigyoElem *kigyo2 );

#endif // HALAL_H_INCLUDED
