#include <stdio.h>
#include <stdlib.h>
#include "bola.h"

Bola Bola_crear(void)
{
	Bola B;
	
	//Se reserva memoria para una bola
	if((B=(Bola)malloc(sizeof(tipoBola))) == NULL)
		printf("Error -> Bola_crear(): Memoria insuficiente\n");
	
	//Posición inicial de la bola
	B.x=200;
	B.y=300;
	
	//Velocidad Inicial de la bola
	B.vx=10;
	B.vy=10;
	
	//Le asignamos una imagen a la bola
	B->imagen = Imagen_cargar("../multimedia/bola.png");
	
}

void Bola_destruir(Bola B)
{
	free(B->imagen);
	free(B);
}

void Bola_actualizar(Bola B)
{
	B.x += B.vx;
	B.y += B.vy;
}
	
SDL_Rect Bola_rectangulo_colision(Bola B)
{
	SDL_Rect rectangulo;
	
	rectangulo.x = B.x;
	rectangulo.y = B.y;
	rectangulo.h = B->imagen->h;
	rectangulo.w = B->imagen->w;
	
	return rectangulo;
	
}
	

	
