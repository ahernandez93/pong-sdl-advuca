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
	
	/* Posición inicial de la bola (100, 200) */

	
	/* Velocidad Inicial de la bola (5, 5) */

	
	/* Le asignamos una imagen a la bola */
	
	
	return bola;
}

void Bola_destruir(Bola bola)
{
	/* ¡Libera la imagen de la bola! */
	free(bola);
}

void Bola_dibujar(Bola bola, SDL_Surface* pantalla)
{
	/* Dibujamos la bola en su posición */
}

void Bola_actualizar(Bola bola)
{
	/* La posición de la bola se actualiza según su velocidad actual */
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


	
