#ifndef _BOLA_
#define _BOLA_

#include <SDL/SDL.h>

/**
	@struct tipoBola
	
	@brief Estructura de la Bola, se utiliza Bola
*/
typedef struct{
	/** Coordenada en el eje x de la bola */
	int x;
	/** Coordenada en el eje y de la bola */
	int y;
	/** Velocidad en el eje x de la bola */
	int vx;
	/** Velocidad en el eje y de la bola */
	int vy;
	/** Imagen de la bola */
	SDL_Surface *imagen;
}tipoBola;


/**
	@struct Bola
	
	@brief Estructura de la bola
	
	Representa a la bola de juego
	
	Se define como un puntero a tipoBola (para no tener que manejar punteros en las funciones)
	
	La documentación de las funciones de este TAD en bola.h
	
	Ejemplo de uso:
	
	\code
		Bola bola;
		
		bola = Bola_crear();
		
		while(!salir){
			...
			
			Bola_actualizar_entrada(bola;
			Bola_dibujar(bola, pantalla);
			
			...
		}
		
		...
		
		Bola_destruir(bola);
	\endcode
*/
typedef tipoBola* Bola;

/**
	@return bola inicializada
*/
Bola Bola_crear(void);

/**
	@param bola Bola a destruir
	
	Libera la memoria ocupada por la bola
*/
void Bola_destruir(Bola bola);

/**
	@param bola bola a modificar
	
	Invierte la velocidad en el eje x de la bola
*/
void Bola_invertir_velocidadX(Bola bola);

/**
	@param bola bola a modificar
	
	Invierte la velocidad en el eje y de la bola
*/
void Bola_invertir_velocidadY(Bola bola);

/**
	@param bola bola a dibujar
	@param pantalla superficie sobre la que se dibujará la bola
	
	Hace blitting de la bola sobre la superficie
*/
void Bola_dibujar(Bola bola, SDL_Surface* pantalla);

/**
	@param bola bola a actualizar
	
	Actualiza la posición de la bola según su velocidad
*/
void Bola_actualizar(Bola bola);

/**
	@param bola bola a consultar
	@return rectángulo que envuelve a la bola
*/
SDL_Rect Bola_rectangulo_colision(Bola bola);


#endif
