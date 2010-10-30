#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>

#include "juego.h"
#include "constantes.h"
#include "imagen.h"
#include "pong.h"

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
	SDL_WM_SetCaption("Pong - ADVUCA - Paso 3", NULL);
	
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
	juego->pong1 = Pong_crear(J1);
	juego->pong2 = Pong_crear(J2);
	juego->mesa = Imagen_cargar("multimedia/Fondo.png");
	
	/* Inicializamos el teclado */
	juego->teclado = SDL_GetKeyState(NULL);
	
	/* Inicio del control de tiempo */
	juego->tiempo0 = 0;
	
	return juego;
}

void Juego_destruir(Juego juego)
{	
	/* Destuimos todos los elementos del juego */
	Pong_destruir(juego->pong1);
	Pong_destruir(juego->pong2);
	Imagen_borrar(juego->mesa);
	
	/* Cerramos SDL */
	SDL_Quit();
	
	/* Liberamos la memoria de juego */
	free(juego);
}

void Juego_control_tiempo(Juego juego)
{	
	/* Tiempo del último frame = Tiempo total - Tiempo de frames anteriores */
	juego->tiempo1 = SDL_GetTicks();
	
	/* Esperamos lo que nos falta para mantener 25 fps */
	if((juego->tiempo1 - juego->tiempo0) < (1000 / FPS))	
		SDL_Delay((1000 / FPS) - (juego->tiempo1 - juego->tiempo0));
		
	juego->tiempo0 = juego->tiempo1;
}

void Juego_bucle_principal(Juego juego)
{
	int salir = 0;
	
	/* Mientras no queramos salir */
	while(!salir){
		/* Actualizamos la entrada y procesamos la cola de eventos */
		salir = Juego_procesar_eventos(juego);
		
		/* Actualizar pong de J1 según entrada */ 
		Pong_actualizar_entrada(juego->pong1, juego->teclado);
		
		/* Dibujar Mesa */
		Imagen_dibujar(juego->mesa, juego->pantalla, 0, 0);
		
		/* Dibujar J1 */
		Pong_dibujar(juego->pong1, juego->pantalla);
	
		/* Dibujar J2 */
		Pong_dibujar(juego->pong2, juego->pantalla);
		
		/* Flipping, intercambio de superficies (mostramos la pantalla) */
		SDL_Flip(juego->pantalla);
		
		/* Control de tiempo */
		Juego_control_tiempo(juego);
	}
}
