#ifndef _IMAGEN_
#define _IMAGEN_

#include "SDL/SDL.h"

/**
	@param ruta Ruta con la imagen a cargar
	@return superficie con la imagen cargada
	
	Carga y devuelve la superficie con la imagen indicada por ruta
*/
SDL_Surface* Imagen_cargar(const char* ruta);

/**
	@param imagen superficie con la imagen a dibujar
	@param pantalla superficie destino donde se dibujará la imagen
	@param x coordenada en el eje x donde se dibujará la imagen
	@param y coordenada en el eje y donde se dibujará la imagen
*/
void Imagen_dibujar(SDL_Surface* imagen, SDL_Surface* pantalla, int x, int y);

/**
	@param imagen superficie a eliminar
	
	Libera la memoria ocupada por la imagen
*/
void Imagen_borrar(SDL_Surface* imagen);


#endif
