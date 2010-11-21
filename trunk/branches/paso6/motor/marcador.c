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
	marcador->x = 75;
	marcador->y = 25;

	/* Valor inicial del marcador para cada jugador */
	marcador->p_actuales = 0;
	marcador->p_record = 0;
	
	/* Le asignamos una fuente */
	if((marcador->fuente = TTF_OpenFont("multimedia/marcador.ttf", 30)) == NULL){
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
	TTF_CloseFont(marcador->fuente);
	
	/* Liberamos la memoria de marcador */
	free(marcador);
}

void Marcador_incrementar(Marcador marcador)
{
	marcador->p_actuales++;
	
	if(marcador->p_actuales > marcador->p_record)
		marcador->p_record = marcador->p_actuales;
}

void Marcador_reiniciar(Marcador marcador)
{
	marcador->p_actuales = 0;
}

void Marcador_dibujar(Marcador marcador, SDL_Surface* pantalla)
{
	char buffer[30];
	SDL_Surface* temporal;
	SDL_Surface* superficie;
	SDL_Rect destino;
	
	/* Puntos del jugador 1 */
	sprintf(buffer, "Actuales: %d", marcador->p_actuales);
	
	if((temporal = TTF_RenderUTF8_Blended(marcador->fuente, buffer, marcador->color)) == NULL){
		printf("ERROR -> Marcador_dibujar(): No se pudo renderizar el texto\n");
		exit(1);
	}

	if((superficie = SDL_DisplayFormatAlpha(temporal)) == NULL){
		printf("ERROR -> Marcador_dibujar(): No se pudo adaptar el texto renderizado a la pantalla\n");
		exit(1);
	}
	
	destino.x = marcador->x;
	destino.y = marcador->y;
	destino.w = superficie->w;
	destino.h = superficie->h;
	
	SDL_BlitSurface(superficie, NULL, pantalla, &destino);
	
	SDL_FreeSurface(temporal);
	SDL_FreeSurface(superficie);
	
	/* Puntos del jugador 2 */
	sprintf(buffer, "Récord: %d", marcador->p_record);
	
	if((temporal = TTF_RenderUTF8_Blended(marcador->fuente, buffer, marcador->color)) == NULL){
		printf("ERROR -> Marcador_dibujar(): No se pudo renderizar el texto\n");
		exit(1);
	}

	if((superficie = SDL_DisplayFormatAlpha(temporal)) == NULL){
		printf("ERROR -> Marcador_dibujar(): No se pudo adaptar el texto renderizado a la pantalla\n");
		exit(1);
	}
	
	destino.x = marcador->x + 325;
	destino.y = marcador->y;
	destino.w = superficie->w;
	destino.h = superficie->h;
	
	SDL_BlitSurface(superficie, NULL, pantalla, &destino);
	
	SDL_FreeSurface(temporal);
	SDL_FreeSurface(superficie);
}
