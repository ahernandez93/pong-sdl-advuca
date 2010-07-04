#ifndef _BOLA_
#define _BOLA_

#include "SDL/SDL.h"

	typedef struct
	{
		int x,
			 y,
			 vx,
			 vy;
	
		SDL_Surface *imagen;
	}tipoBola;

	typedef tipoBola* Bola;


	Bola Bola_crear(void);
	void Bola_destruir(Bola B);
	void Bola_actualizar(Bola B);
	
	SDL_Rect Bola_rectangulo_colision(Bola B);




#endif
