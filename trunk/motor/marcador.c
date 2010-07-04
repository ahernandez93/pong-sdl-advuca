#include <stdio.h>
#include <stdlib.h>
#include "marcador.h"
#include <SDL/SDL_ttf.h>

Marcador Marcador_crear(void)
{
	Marcador M;
	
	//Se reserva memoria para el marcador
	if((M=(Marcador)malloc(sizeof(tipoMarcador))) == NULL)
	{
		printf("Error -> Marcador_crear(): Memoria insuficiente\n");
		exit(1);	
	}
	
	//Posición inicial de la bola
	M.x=290;
	M.y=350;

	//Valor inicial del marcador para cada jugador
	M.J1=0;
	M.J2=0;
	
	//Se inicializa la librería auxiliar para los ttf
	if(!TTF_Init() < 0)
	{
		printf(stderr, "No se puede inicializar SDL_ttf\n");
		exit(1);
	}
	//Le asignamos una fuente
	if((font = TTF_OpenFont("../multimedia/Marcador_font", 30)) == NULL)
	{
		printf("Error -> Marcador_crear(): Memoria para la fuente insuficiente\n");
		exit(1);
	}
	
	//Le indicamos el color de la fuente
	M->color={0,0,0}; //Negro en este caso
	
	return M;
}

void Marcador_destruir(Marcador B)
{
	TTF_CloseFont(B->texto);
	atexit(TTF_QUIT());
	free(texto);
	free(B);
}

void Marcador_actualizar(Marcador B, player)
{
	if(player==1)
		B.J1++;
	else if(player==2)
		B.J2++;
}




