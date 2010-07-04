#include "stdio.h"
#include "stdlib.h"
#include "pong.h"

Pong Pong_crear(int jugador)
{
	Pong pong;
	
	/* Reservamos memoria para el pong */
	if((pong = (Pong)malloc(sizeof(tipoPong))) == NULL){
		printf("ERROR -> Pong_crear(): no se pudo reservar memoria para el pong\n");
		exit(1);
	}
	
	/* Cargamos la imagen del pong */
	imagen Imagen_cargar("multimedia/pong.png");
	
	/* Posicionamos al pong según el jugador que sea */
	if(jugador == J1)
		x = 15;
	else
		x = PANTALLA_ANCHO - imagen->h - 15;
	
	y = (PANTALLA_ALTO - imagen->h) / 2;
	
	/* Velocidad */
	vx = 5;
	vy = 5;
}

void Pong_destruir(Pong pong)
{
	free(pong);
}

void Pong_actualizar_entrada(Pong pong, Entrada entrada)
{
	
}

void Pong_actualizar_ia(Pong pong, IA ia)
{
	
}

SDL_Rect Pong_rectangulo_colision(Pong pong)
{
	SDL_Rect rectangulo;
	
	rectangulo.x = pong->x;
	rectangulo.y = pong->y;
	rectangulo.w = pong->imagen->w;
	rectangulo.h = pong->imagen->h;
	
	return rectangulo;
}
