/**
 * @file menu.h
 * @brief
 *
 * Ez a fájl tartalmazza a menu függvényeit.
 *
 * @author Szövő Roland
 */
#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <SDL.h>

/**
 * Kirajzolja a menüt és itt választhatunk, hogy 1 vagy 2 játékos módban akarunk játszani, a ranglistát akarjuk megnézni vagy kiléphetünk
 * @param screen a képernyő.
 * @param quit egy bool változó ami igazra vált ha kilépünk.
 * @author Szövő Roland
 */
void Menu(SDL_Surface *screen, bool* quit);

/**
 * Létrehozza a kigyót/kigyókat és a kaját, nézi hogy milyen billentyût nyomunk le és belép a többi függvénybe
 * @param is_multiplayer ha két játékos módra megyünk a menüben akkor ez IGAZ-ra vált egyébként HAMIS-ra.
 * @param screen a képernyő.
 * @author Szövő Roland
 */
void Jatek(bool is_multiplayer, SDL_Surface *screen);


#endif // MENU_H_INCLUDED
