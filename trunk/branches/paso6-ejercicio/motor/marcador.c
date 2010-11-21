#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <SDL/SDL_ttf.h>

#include "marcador.h"
#include "constantes.h"

Marcador Marcador_crear(void)
{
	Marcador marcador;
	
	/* Se reserva memoria para el marcador */
	if((marcador = (Marcador)malloc(sizeof(tipoMarcador))) == NULL){
		printf("ERROR -> Marcador_crear(): Memoria insuficiente\n");
		exit(1);	
	}
	
	/* Posición del marcador */
	/* "x -> 75" e "y -> 25" */

	/* Valor inicial del marcador récord y puntos actuales */
	
	
	/* Le asignamos una fuente. Cargamos la fuente a tamaño 30 */
	if((marcador->fuente = /* */) == NULL){
		printf("ERROR -> Marcador_crear(): No se pudo inicializar la fuente multimedia/marcador.ttf\n");
		exit(1);
	}
	
	/* Le indicamos el color de la fuente (blanco) */
	marcador->color.r = 255;
	marcador->color.g = 255;
	marcador->color.b = 255;
	
	return marcador;
}

void Marcador_destruir(Marcador marcador)
{
	/* Destuimos la fuente cargada */
	
	
	/* Liberamos la memoria de marcador */
	free(marcador);
}

void Marcador_incrementar(Marcador marcador)
{
	/* Incrementamos los puntos actuales */
	
	if(/* ¿Hemos superado el récord? */) {
		/* Actualizar récord */
	}
}

void Marcador_reiniciar(Marcador marcador)
{
	/* Ponemos los puntos actuales a 0 */
}

void Marcador_dibujar(Marcador marcador, SDL_Surface* pantalla)
{
	char buffer[30];
	SDL_Surface* temporal;
	SDL_Surface* superficie;
	SDL_Rect destino;
	
	/* Puntos actuales */
	sprintf(buffer, "Actuales: %d", marcador->p_actuales);
	
	/* Renderizamos el texto en una superficie temporal */
	if((temporal = TTF_RenderUTF8_Blended(marcador->fuente, buffer, marcador->color)) == NULL){
		printf("ERROR -> Marcador_dibujar(): No se pudo renderizar el texto\n");
		exit(1);
	}

	/* Adaptamos la superficie a la pantalla */
	if((superficie = SDL_DisplayFormatAlpha(temporal)) == NULL){
		printf("ERROR -> Marcador_dibujar(): No se pudo adaptar el texto renderizado a la pantalla\n");
		exit(1);
	}
	
	destino.x = marcador->x;
	destino.y = marcador->y;
	destino.w = superficie->w;
	destino.h = superficie->h;
	
	/* Volcamos la superficie en la pantalla */
	SDL_BlitSurface(superficie, NULL, pantalla, &destino);
	
	/* Liberamos las superficies temporales */
	SDL_FreeSurface(temporal);
	SDL_FreeSurface(superficie);
	
	/* Puntos récord */
	sprintf(/* */);
	
	/* Renderizamos el texto en una superficie temporal */
	if((temporal = /* */) == NULL){
		printf("ERROR -> Marcador_dibujar(): No se pudo renderizar el texto\n");
		exit(1);
	}

	/* Adaptamos la superficie temporal a la pantalla */
	if((superficie = /* */) == NULL){
		printf("ERROR -> Marcador_dibujar(): No se pudo adaptar el texto renderizado a la pantalla\n");
		exit(1);
	}
	
	destino.x = marcador->x + 325;
	destino.y = marcador->y;
	destino.w = superficie->w;
	destino.h = superficie->h;
	
	/* Volcamos la superficie en la pantalla */
	
	
	
	/* Liberamos superficies temporales */
	SDL_FreeSurface(temporal);
	SDL_FreeSurface(superficie);
}
