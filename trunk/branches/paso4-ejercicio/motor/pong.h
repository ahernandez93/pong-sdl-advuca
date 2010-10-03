#ifndef _PONG_
#define _PONG_

#include <SDL/SDL.h>

/**
	@struct tipoPong
	
	@brief Estructura de la pala (pong), se utiliza Pong
*/
typedef struct{
	/** Coordenada en el eje x del pong */
	int x;
	/** Coordenada en el eje y del pong */
	int y;
	/** Velocidad en el eje x del pong */
	int vx;
	/** Velocidad en el eje y del pong */
	int vy;
	/** Superficie con la imagen del pong */
	SDL_Surface* imagen;
}tipoPong;

/**
	@struct Pong
	
	@brief Estructura de la pala
	
	Representa a la pala de juego
	
	Se define como un puntero a tipoPong (para no tener que manejar punteros en las funciones)
	
	La documentación de las funciones de este TAD en pong.h
	
	Ejemplo de uso:
	
	\code
		Pong pong;
		
		pong = Pong_crear(J1);
		
		while(!salir){
			...
			
			Pong_actualizar_entrada(pong, teclado);
			Pong_dibujar(pong, pantalla);
			
			...
		}
		
		...
		
		Pong_destruir(pong);
	\endcode
*/
typedef tipoPong* Pong;

/**
	@param jugador Jugador del que se quiere crear el pong (J1 o J2)
	@return pala de pong inicializada
*/
Pong Pong_crear(int jugador);

/**
	@param pong pala que se quiere destuir
	
	Libera la memoria ocupada por la pala
*/
void Pong_destruir(Pong pong);

/**
	@param pong pala a dibujar
	@param pantalla superficie sobre la que se dibujará la pala
*/
void Pong_dibujar(Pong pong, SDL_Surface* pantalla);

/**
	@param pong pala a actualizar
	@param teclado vector con el estado del teclado según el cual se actualizará la pala
	
	Actualiza la posición de la pala según las teclas
*/
void Pong_actualizar_entrada(Pong pong, Uint8* teclado);

#endif
