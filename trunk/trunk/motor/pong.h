#ifndef _PONG_
#define _PONG_

#include "SDL/SDL.h"


typedef struct{
	int x;
	int y;
	int vx;
	int vy;
	SDL_Surface* imagen;
}tipoPong;

typedef tipoPong* Pong;

Pong Pong_crear(int jugador);

void Pong_destruir(Pong pong);

void Pong_actualizar_entrada(Pong pong, Entrada entrada);

void Pong_actualizar_ia(Pong pong, IA ia);

SDL_Rect Pong_rectangulo_colision(Pong pong);

#endif
