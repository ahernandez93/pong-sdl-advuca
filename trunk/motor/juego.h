#ifndef _JUEGO_
#define _JUEGO_

#include "pong.h"
#include "marchador.h"
#include "bola.h"

typedef struct{
	Pong pong1;
	Pong pong2;
	Bola bola;
	Marcador marcador;
	SDL_Surface* mesa;
	SDL_Surface* pantalla;
	Uint8* teclado;
}tipoJuego;

typedef tipoJuego* Juego;

Juego Juego_crear(void);

void Juego_destruir(Juego juego);

void Juego_bucle_principal(Juego juego);

#endif
