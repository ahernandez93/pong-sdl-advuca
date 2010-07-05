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
int Bola_consultar_velocidadx(Bola bola);
int Bola_consultar_velocidady(Bola bola);
void Bola_cambiar_velocidadx(Bola bola);
void Bola_cambiar_velocidady(Bola bola);
void Bola_dibujar(Bola bola, SDL_Surface* pantalla);
void Bola_actualizar(Bola bola);
SDL_Rect Bola_rectangulo_colision(Bola bola);


#endif
