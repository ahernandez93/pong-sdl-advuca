#ifndef _IMAGEN_
#define _IMAGEN_

#include "SDL/SDL.h"

SDL_Surface* Imagen_cargar(const char* ruta);

void Imagen_dibujar(SDL_Surface* imagen, SDL_Surface* pantalla, int x, int y);

void Imagen_borrar(SDL_Surface* imagen);


#endif
