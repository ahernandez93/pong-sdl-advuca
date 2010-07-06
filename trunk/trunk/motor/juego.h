#ifndef _JUEGO_
#define _JUEGO_

#include "pong.h"
#include "marcador.h"
#include "bola.h"

/**
	@struct tipoJuego
	
	@brief Control del juego, se utiliza Juego
*/
typedef struct{
	/** Pong del jugador 1 */
	Pong pong1;
	/** Pong del jugador 2 */
	Pong pong2;
	/** Bola de juego */
	Bola bola;
	/** Marcador con las puntuaciones */
	Marcador marcador;
	/** Imagen con la mesa de juego */
	SDL_Surface* mesa;
	/** Superficie de la pantalla */
	SDL_Surface* pantalla;
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
	@param 
	
	@return
	
	Comprueba si se han producido colisiones y las trata las de rebote
*/

int Juego_comprobar_colisiones(Bola bola, Pong pong1, Pong pong2);

/**
	@param 
	
	Aumenta la puntuación del jugador que mete gol
*/

void Juego_puntuar(int jugador, Marcador marcador);

/**
	@param juego juego inicializado sobre el que ejecutar el bucle principal
	
	Ejecuta el bucle principal de juego
*/
void Juego_bucle_principal(Juego juego);

#endif
