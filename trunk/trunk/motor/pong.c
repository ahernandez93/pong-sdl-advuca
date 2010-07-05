#include "stdio.h"
#include "stdlib.h"
#include "pong.h"
#include "imagen.h"

Pong Pong_crear(int jugador)
{
	Pong pong;
	
	/* Reservamos memoria para el pong */
	if((pong = (Pong)malloc(sizeof(tipoPong))) == NULL){
		printf("ERROR -> Pong_crear(): no se pudo reservar memoria para el pong\n");
		exit(1);
	}
	
	/* Cargamos la imagen del pong */
	pong->imagen = Imagen_cargar("multimedia/pong.png");
	
	/* Posicionamos al pong según el jugador que sea */
	if(jugador == J1)
		pong->x = 15;
	else
		pong->x = PANTALLA_ANCHO - pong->imagen->h - 15;
	
	pong->y = (PANTALLA_ALTO - pong->imagen->h) / 2;
	
	/* Velocidad */
	pong->vx = 5;
	pong->vy = 5;
	
	return pong;
}

void Pong_destruir(Pong pong)
{
	/* Liberamos la memoria ocupada por el Pong */
	Imagen_borrar(pong->imagen);
	free(pong);
}

void Pong_dibujar(Pong pong, SDL_Surface* pantalla)
{
	Imagen_dibujar(pong->imagen, pantalla, pong->x, pong->y);
}

void Pong_actualizar_entrada(Pong pong, Uint8* teclado)
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
