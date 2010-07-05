#ifndef _MARCADOR_
#define _MARCADOR_

#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"

typedef struct{
	int puntos_j1;
	int puntos_j2;
	int x;
	int y;
	SDL_Color color;
	TTF_Font *fuente;
}tipoMarcador;

typedef tipoMarcador* Marcador;


Marcador Marcador_crear(void);
void Marcador_destruir(Marcador marcador);
void Marcador_dibujar(Marcador marcador, SDL_Surface* pantalla);
void Marcador_incrementar(Marcador marcador, int jugador);



#endif
