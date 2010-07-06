#ifndef _MARCADOR_
#define _MARCADOR_

#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"

/**
	@struct tipoMarcador
	
	@brief Estructura del marcador, se utiliza Marcador
*/
typedef struct{
	/** Puntos del jugador 1 */
	int puntos_j1;
	/** Puntos del jugador 2 */
	int puntos_j2;
	/** Posición x del marcador */
	int x;
	/** Posición y del marcador */
	int y;
	/** Color en el que se renderizarán los puntos */
	SDL_Color color;
	/** Fuente con la que se renderizarán los puntos */
	TTF_Font *fuente;
}tipoMarcador;

/**
	@struct Marcador
	
	@brief Estructura del marcador
	
	Representa al marcador de juego
	
	Se define como un puntero a tipoMarcador (para no tener que manejar punteros en las funciones)
	
	La documentación de las funciones de este TAD en marcador.h
	
	Ejemplo de uso:
	
	\code
		Marcador marcador;
		
		marcador = Marcador_crear();
		
		while(!salir){
			...
			
			if() // El jugador J1 marca un punto
				Marcador_incrementar(marcador, J1);
			...
			
			Marcador_dibujar(marcador, pantalla);
		}
		
		...
		
		Marcador_destruir(marcador);
	\endcode
*/
typedef tipoMarcador* Marcador;

/**
	@return marcador creado e inicializado con los puntos de los dos jugadores a 0
*/
Marcador Marcador_crear(void);

/**
	@param marcador marcador a destruir
	
	Libera la memoria ocupada por el marcador
*/
void Marcador_destruir(Marcador marcador);

/**
	@param marcador marcador a dibujar
	@param pantalla superficie sobre la que se dibujará el marcador
	
	Dibuja el marcador en la superficie dada
*/
void Marcador_dibujar(Marcador marcador, SDL_Surface* pantalla);

/**
	@param marcador marcador a modificar
	@param jugador J1 o J2, incrementa en 1 los puntos del jugador indicado
*/
void Marcador_incrementar(Marcador marcador, int jugador);



#endif
