#ifndef _BOLA_
#define _BOLA_

#include "SDL/SDL.h"

typedef struct{
	int x;
	int y;
	int vx;
	int vy;
	SDL_Surface *imagen;
}tipoBola;

typedef tipoBola* Bola;


Bola Bola_crear(void);
void Bola_destruir(Bola bola);
void Bola_invertir_velocidadX(Bola bola);
void Bola_invertir_velocidadY(Bola bola);
void Bola_dibujar(Bola bola, SDL_Surface* pantalla);
void Bola_actualizar(Bola bola);
SDL_Rect Bola_rectangulo_colision(Bola bola);


#endif
