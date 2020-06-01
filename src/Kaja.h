/**
 * @file Kaja.h
 * @brief
 *
 * Ez a fájl tartalmazza a Kaja függvényen belüli függvényeket és a kaja struktúráját.
 *
 * @author Szövő Roland
 */
#ifndef KAJA_H_INCLUDED
#define KAJA_H_INCLUDED
#include <SDL.h>
/** A kaját tároló struktúra*/
typedef struct food{
    SDL_Rect F; /**< Ez tárolja el a kajat koordinátáit, szélességét és magasságát*/
}food;
/**
 * Új kaját generál ha a kigyó elsõ elemének a koordinátái megegyeznek a kajáéval
 * @param f a kaja struktúrája ami a kaja koordinátáit és méretét tárolja.
 * @author Szövő Roland
 */
void Food(food *f);

#endif // KAJA_H_INCLUDED
