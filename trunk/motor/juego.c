#include <stdio.h">
#include <stdlib.h>
#include <time.h>
#include "imagen.h"
#include "juego.h"
#include "pong.h"
#include "marchador.h"
#include "bola.h"
#include "constantes.h"

SDL_Surface *Juego_iniciar_SDL(void){

	SDL_Surface* auxiliar;
	
	/* Inicializamos SDL */
	if(SDL_Init(0) < 0){
		printf("ERROR -> Juego_iniciar_SDL(): no se pudo iniciar SDL\n");
		exit(1);
	}
	
	/* Al salir, cerramos SDL */
	atexit(SDL_Quit);
	
	/* Cteamos la superficie principal */
	auxiliar = SDL_SetVideoMode(PANTALLA_ANCHO, PANTALLA_ALTO, BPP, SDL_HWSURFACE | SDL_DOUBLEBUF);

	if(screenaux == NULL){
		printf("ERROR -> Juego_iniciar_SDL(): no se pudo iniciar la ventana SDL\n");
		exit(1);
	}
	
	/* Establecemos el título de la ventana */
	SDL_WM_SetCaption("Pong - ADVUCA", NULL);
	
	/* Hacemos el cursor invisible */
	SDL_ShowCursor(SDL_DISABLE);
	
	/* Inicializamos SDL TTF */
	if(TTF_Init() == -1){
		printf("ERROR -> Juego_iniciar_SDL(): no se pudo iniciar SDL TTF\n");
		exit(1);
	}
	
	/* Al salir, cerramos SDL TTF */
	atexit(TTF_Quit);
	
	/* Inicializamos SDL Mixer */
	if(Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS, 4096) < 0){
		printf("ERROR -> Juego_iniciar_SDL(): no se pudo iniciar SDL Mixer\n");
		exit(1);
	}
	
	/* Al salir, cerramos SDL Mixer */
	atexit(Mix_CloseAudio);

	return auxiliar;
}

int Juego_procesar_eventos(void)
{
	SDL_Event event;
	int salir = 0;
	
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
	
	/* Establecemos una semilla para los números aleatorios */
	srand(time(NULL));
	
	/* Creamos los elementos del juego */
	juego->pong1 = Pong_crear(J1);
	juego->pong2 = Pong_crear(J2);
	juego->bola = Bola_crear();
	juego->mesa = Imagen_cargar("multimedia/Fondo.png");
	juego->marcador = Marcador_crear();
	
	/* Inicializamos el teclado */
	teclado = SDL_GetKeyState(NULL);
}

void Juego_destruir(Juego juego)
{
	/* Destuimos todos los elementos del juego */
	Pong_destruir(juego->pong1);
	Pong_destuir(juego->pong2);
	Bola_destuir(juego->bola);
	Marcador_destuir(juego->marcador);
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
			/* Actualizar entrada */
			teclado = SDL_GetKeyState(NULL);
			
			/* Actualizar pong de J1 según entrada */ 
			Pong_actualizar_entrada(juego->pong1, teclado);
			
			/* Actualizar pong de J2 según IA */
			Pong_actualizar_ia(juego->pong2);
			
			/* Actualizar Bola */
			Bola_actualizar(juego->bola);
			
			/* Dibujar Mesa */
			Imagen_dibujar(juego->mesa, juego->pantalla, 0, 0);
			
			/* Dibujar J1 */
			Pong_dibujar(juego->pong1, juego->pantalla);
			
			/* Dibujar J2 */
			Pong_dibujar(juego->pong2, juego->pantalla);
			
			/* Dibujar Bola */
			Bola_dibujar(juego->bola, juego->pantalla);
			
			/* Colisiones */
			
			
			/* Procesamos la cola de eventos */
			salir = Juego_procesar_eventos();
			
			/* Control de tiempo */
						
	}
}
