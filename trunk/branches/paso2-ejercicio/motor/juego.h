#ifndef _JUEGO_
#define _JUEGO_

#include <SDL/SDL.h>

/**
	@struct tipoJuego
	
	@brief Control del juego, se utiliza Juego
*/
typedef struct{
	/** Superficie de la pantalla */
	SDL_Surface* pantalla;
	/** Imagen con la mesa de juego */
	SDL_Surface* mesa;
	/** Estado del teclado */
	Uint8* teclado;
}tipoJuego;

/**
	@struct Juego
	
	@brief Control del juego
	
	Estructura que contiene los elementos del juego, los inicializa, destruye y controla el bucle principal.
	
	Se define como un puntero a tipoJuego (para no tener que manejar punteros en las funciones)
	
	La documentación de las funciones de este TAD en juego.h
	
	Ejemplo de uso:
	
	\code
		int main(int argc, char **argv)
		{
			Juego juego;
			
			juego = Juego_crear();
			Juego_bucle_principal(juego);
			Juego_destruir(juego);
			
			return 0;
		}
	\endcode
*/
typedef tipoJuego* Juego;

/**
	@return juego inicializado
	
	Inicializa SDL, crea y devuelve la estructura del juego
*/
Juego Juego_crear(void);

/**
	@param juego Juego a ser destruido
	
	Libera la memoria ocupada por el juego y cierra la SDL
*/
void Juego_destruir(Juego juego);

/**
	@param juego juego inicializado sobre el que ejecutar el bucle principal
	
	Ejecuta el bucle principal de juego
*/
void Juego_bucle_principal(Juego juego);

#endif
