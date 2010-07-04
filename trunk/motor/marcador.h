#ifndef _MARCADOR_
#define _MARCADOR_

#include "SDL/SDL.h"

	typedef struct
	{
		int J1,
			 J2,
			 x,
			 y;
		SDL_Color *color;
		TTF_Font *texto;
	}tipoMarcador;

	typedef tipoMarcador* Marcador;


	Marcador Marcador_crear(void);
	void Marcador_destruir(Marcador B);
	void Marcador_actualizar(Marcador B, int player);



#endif
