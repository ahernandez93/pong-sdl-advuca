#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

#include "juego.h"
#include "constantes.h"
#include "imagen.h"

SDL_Surface *Juego_iniciar_SDL(void){

	SDL_Surface* auxiliar;

	/* Inicializamos SDL */
	if(SDL_Init(SDL_INIT_EVERYTHING) < 0){
		printf("ERROR -> Juego_iniciar_SDL(): no se pudo iniciar SDL\n");
		exit(1);
	}

	/* Al salir, cerramos SDL */
	atexit(SDL_Quit);

	/* Cteamos la superficie principal */
	auxiliar = SDL_SetVideoMode(PANTALLA_ANCHO, PANTALLA_ALTO, BPP, SDL_HWSURFACE | SDL_DOUBLEBUF);

	if(auxiliar == NULL){
		printf("ERROR -> Juego_iniciar_SDL(): no se pudo iniciar la ventana SDL\n");
		exit(1);
	}

	/* Establecemos el título de la ventana */
	SDL_WM_SetCaption("Pong - ADVUCA - Paso 2", NULL);

	/* Hacemos el cursor invisible */
	SDL_ShowCursor(SDL_DISABLE);

	/* Inicializamos SDL TTF */
	if(TTF_Init() == -1){
		printf("ERROR -> Juego_iniciar_SDL(): no se pudo iniciar SDL TTF\n");
		exit(1);
	}

	/* Al salir, cerramos SDL TTF */
	atexit(TTF_Quit);

	return auxiliar;
}

int Juego_procesar_eventos(Juego juego)
{
	SDL_Event event;
	int salir = 0;

	/* Actualizamos el teclado */
	juego->teclado = SDL_GetKeyState(NULL);

	/* Mientras queden eventos en la cola de eventos */
	while(SDL_PollEvent(&event)){
		switch(event.type){
			/* Si es de cierre de ventana */
			case SDL_QUIT:
				salir = 1;
				break;
			/* Si es de pulsación de tecla */
			case SDL_KEYDOWN:
				/* Si pulsamos q */
				if(event.key.keysym.sym == SDLK_q)
					salir = 1;
				break;
		}
	}

	SDL_PumpEvents();

	return salir;
}

Juego Juego_crear(void)
{
	Juego juego;

	/* Reservamos memoria para el juego */
	if((juego = (Juego)malloc(sizeof(tipoJuego))) == NULL){
		printf("ERROR -> Juego_crear(): no se pudo reservar memoria para el juego\n");
		exit(1);
	}

	/* Inicializamos SDL */
	juego->pantalla = Juego_iniciar_SDL();

	/* Creamos los elementos del juego */
	juego->mesa = Imagen_cargar("multimedia/Fondo.png");

	/* Inicializamos el teclado */
	juego->teclado = SDL_GetKeyState(NULL);

	return juego;
}

void Juego_destruir(Juego juego)
{
	/* Destuimos todos los elementos del juego */
	Imagen_borrar(juego->mesa);

	/* Cerramos SDL */
	SDL_Quit();

	/* Liberamos la memoria de juego */
	free(juego);
}

void Juego_bucle_principal(Juego juego)
{
	int salir = 0;

	/* Mientras no queramos salir */
	while(!salir){
		/* Actualizamos la entrada y procesamos la cola de eventos */
		salir = Juego_procesar_eventos(juego);

		/* Dibujar Mesa */
		Imagen_dibujar(juego->mesa, juego->pantalla, 0, 0);

		/* Flipping, intercambio de superficies (mostramos la pantalla) */
		SDL_Flip(juego->pantalla);
	}
}
