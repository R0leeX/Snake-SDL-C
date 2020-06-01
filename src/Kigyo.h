/**
 * @file Kigyo.h
 * @brief
 *
 * Ez a fájl tartalmazza a Kigyo függvényen belüli függvényeket és a kigyoElem Struktúrát.
 *
 * @author Szövő Roland
 */
#ifndef KIGYO_H_INCLUDED
#define KIGYO_H_INCLUDED
#include <SDL.h>

#include "Konstansok.h"
/**Ez a struktúra tárolja a kigyót */
typedef struct kigyoElem{
    SDL_Rect K; /**< A kigyóelem koordinátáit, a szélességét és a magasságát tárolja*/
    irany i; /**< A kigyóelem irányát tárolja*/
    unsigned int score;/**< a kigyó pontját*/
    struct kigyoElem *kov, *eloz; /**< az előző és a következő kigyóra mutató pointer*/
}kigyoElem;
/**
 * hozzáfűz egy elemet a kigyóhoz.
 * @param kigyo struktúra a paramétere így könnyen bele írható egy függvénybe az egyes és a kettes kigyó is csak kétszer kell meghívni a függvényt.
 * @return visszatér a megnövelt lista elejével.
 * @author Szövő Roland
 */
kigyoElem *noveles(kigyoElem *kigyo);
/**
 * Irány szerint változtatja a kigyó x és y koordinátáját majd hátulról az elõzõ átadja a mögötte levõnek az irányát.
 * @param kigyo struktúra a paramétere így könnyen bele írható egy függvénybe az egyes és a kettes kigyó is csak kétszer kell meghívni a függvényt.
 * @return visszatér a módosult lista elejével.
 * @author Szövő Roland
 */
kigyoElem *lepes(kigyoElem *kigyo);

/**
 * Megnöveli a kigyó pontját (ami kezdetben nulla), amikor felszed egy kaját.
 * @param kigyo struktúra
 * @author Szövő Roland
 */
void increaseScore(kigyoElem *kigyo);

#endif // KIGYO_H_INCLUDED
