#include "stdio.h"
#include "stdlib.h"
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "imagen.h"


SDL_Surface* Imagen_cargar(const char* ruta)
{
	SDL_Surface* temporal;
	SDL_Surface* imagen;
	
	/* Intentamos cargar la imagen */
	if((temporal = IMG_Load(ruta)) == NULL){
		printf("ERROR -> Imagen_cargar(): error al cargar la imagen %s\n", ruta);
		exit(1);
	}
	
	/* La adaptamos al formato de la pantalla con color transparente */
	if((imagen = SDL_DisplayFormatAlpha(temporal)) == NULL){
		printf("ERROR -> Imagen_cargar(): no se pudo adaptar la imagen $s al formato de la pantalla\n", ruta);
		exit(1);
	}
	
	/* Liberamos la imagen temporal */
	SDL_FreeSurface(temporal);
	
	return imagen;
}

void Imagen_dibujar(SDL_Surface* imagen, SDL_Surface* pantalla, int x, int y)
{
	SDL_Rect destino;
	
	/* Establecemos las coordenadas de destino */
	destino.x = x;
	destino.y = y;
	
	/* Hacemos blitting */
	SDL_BlitSurface(imagen, NULL, pantalla, &destino);
}

void Imagen_borrar(SDL_Surface* imagen)
{
	/* Liberamos la imagen */
	SDL_FreeSurface(imagen);
}
