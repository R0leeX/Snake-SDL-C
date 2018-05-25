/**
 * @file Ranglista.h
 * @brief
 *
 * Ez a fájl tartalmazza a Ranglista függvényeit és a legjobb játékosok struktúráját.
 *
 * @author Szövő Roland
 */
#ifndef RANGLISTA_H_INCLUDED
#define RANGLISTA_H_INCLUDED

#include <stdbool.h>

#include "Kigyo.h"
/**Ez tárolja a játékosokat*/
typedef struct top5{
        char nev[20+1]; /**< eltárolja a játékos nevét*/
        unsigned int score; /**< eltárolja a játékos pontját*/
}top5;

/**
 * Beolvassa a fájlból az adatokat, bekéri az új játékos nevét, rendezi a  meglévõ adatokat és beleírja a fájlba
 * @param screen a képernyő.
 * @param kigyo1 és kigyo2 struktúrája.
 * @author Szövő Roland
 */
void ranglista_hozzaad(SDL_Surface *screen, kigyoElem *kigyo1, kigyoElem *kigyo2);

/**
 * Sorba rendezi a játékosokat pontszám szerint
 * @param jatekos a játékosok neve és pontja.
 * @param jatekosdb megmondja hány játékost kell rendezni.
 * @author Szövő Roland
 */
void tomb_rendez(top5 *jatekos,int jatekosdb);

/**
 * Beolvassa a nevet
 * @param dest karakter tömb amibe a név kerül.
 * @param x, y, sz, m az x, y koordináta illettve a szélesség, magasság.
 * @param hatter a háttér színe.
 * @param szín a felirat színe.
 * @param font a betűtípus.
 * @param screen a képernyő.
 * @return IGAZ-zal tér vissza ha sikerült a bevitel.
 * @author Szövő Roland
 */
bool input_text(char *dest, int x, int y, int sz, int m, SDL_Color hatter, SDL_Color szin, TTF_Font *font, SDL_Surface *screen);

/**
 * Beolvassa és kiírja a beolvasott nevet a képernyõre
 * @param nev a nevek tömbje.
 * @param screen a képernyő.
 * @param font a betűtípus.
 * @author Szövő Roland
 */
void nev_beolvas(char* nev, SDL_Surface *screen, TTF_Font *font);

/**
 * Kiírja a Ranglistát
 * @param screen a képernyő.
 * @param jatekos a játékosok neve és pontja.
 * @param font a betűtípus.
 * @param j a játékosok száma.
 * @author Szövő Roland
 */
void ranglista_kiiras(SDL_Surface *screen, top5 *jatekos, TTF_Font *font, int j);

#endif // RANGLISTA_H_INCLUDED
