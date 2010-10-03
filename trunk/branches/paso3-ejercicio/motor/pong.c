#include <stdio.h>
#include <stdlib.h>

#include "pong.h"
#include "imagen.h"
#include "constantes.h"

Pong Pong_crear(int jugador)
{
	Pong pong;
	
	/* Reservamos memoria para el pong */
	if((pong = (Pong)malloc(sizeof(tipoPong))) == NULL){
		printf("ERROR -> Pong_crear(): no se pudo reservar memoria para el pong\n");
		exit(1);
	}
	
	/* Posicionamos al pong según el jugador que sea */
	if(jugador == J1)
	{
		/* Cargamos la imagen del pong 1*/
		
		/* Lo colocamos en x = 25 */
	}
	else
	{
		/* Cargamos la imagen del pong 2*/
		
		/* Lo colocamos en x = ancho pantalla - ancho pong (lado derecho) */
	}
	
	/* Lo colocamos centrado en el eje y */
	
	/* Velocidad x = 10 */
	
	/* Velocidad y = 10 */
	
	return pong;
}

void Pong_destruir(Pong pong)
{
	/* Liberamos la imagen del Pong */
	
	
	free(pong);
}

void Pong_dibujar(Pong pong, SDL_Surface* pantalla)
{
	/* Dibujamos la imagen del pong en su posición actual */
	
}

void Pong_actualizar_entrada(Pong pong, Uint8* teclado)
{
	/* Si pulsamos arriba nos movemos arriba */
	if(teclado[SDLK_UP]) {
	
	}
	/* Si pulsamos abajo nos movemos abajo */
	else if(teclado[SDLK_DOWN]) {
		
	}
	
	/* Controlamos no salirnos de los límites del campo */
	if(pong->y < 0) {
		
	}
	else if(pong->y + pong->imagen->h > PANTALLA_ALTO) {

	}
}
