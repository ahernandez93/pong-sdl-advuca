#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include "bola.h"
#include "imagen.h"
#include "constantes.h"

Bola Bola_crear(void)
{
	Bola bola;
	
	/* Se reserva memoria para una bola */
	if((bola = (Bola)malloc(sizeof(tipoBola))) == NULL){
		printf("ERROR -> Bola_crear(): Memoria insuficiente\n");
		exit(1);
	}
	
	/* Posición inicial de la bola */
	bola->x = 200;
	bola->y = 300;
	
	/* Velocidad Inicial de la bola */
	bola->vx = 1;
	bola->vy = 1;
	
	/* Le asignamos una imagen a la bola */
	bola->imagen = Imagen_cargar("multimedia/bola.png");
	
	return bola;
}

void Bola_destruir(Bola bola)
{
	Imagen_borrar(bola->imagen);
	free(bola);
}

void Bola_dibujar(Bola bola, SDL_Surface* pantalla)
{
	Imagen_dibujar(bola->imagen, pantalla, bola->x, bola->y);
}

void Bola_actualizar(Bola bola)
{
	bola->x += bola->vx;
	bola->y += bola->vy;
}
	
SDL_Rect Bola_rectangulo_colision(Bola bola)
{
	SDL_Rect rectangulo;
	
	rectangulo.x = bola->x;
	rectangulo.y = bola->y;
	rectangulo.h = bola->imagen->h;
	rectangulo.w = bola->imagen->w;
	
	return rectangulo;
}

void Bola_invertir_velocidadX(Bola bola)
{
	bola->vx *= -1;
}
void Bola_invertir_velocidadY(Bola bola)
{
	bola->vy *= -1;
}


	
