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
#include "bola.h"

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
	SDL_WM_SetCaption("Pong - ADVUCA - Paso 4", NULL);
	
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
	juego->bola = Bola_crear();
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
	Bola_destruir(juego->bola);
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
	
	/* Esperamos lo que nos falta para mantener 15fps */
	if((juego->tiempo1 - juego->tiempo0) < (1000 / FPS))	
		SDL_Delay((1000 / FPS) - (juego->tiempo1 - juego->tiempo0));
		
	juego->tiempo0 = juego->tiempo1;
}

int Juego_colisiones_rectangulo(SDL_Rect rect1, SDL_Rect rect2)
{
	if(((rect1.x + rect1.w) > rect2.x) &&
	   ((rect1.y + rect1.h) > rect2.y) &&
	   ((rect2.x + rect2.w) > rect1.x) &&
	   ((rect2.y + rect2.h) > rect1.y))
		return 1;
	else
		return 0;
		
}

void Juego_comprobar_colisiones(Bola bola, Pong pong1, Pong pong2)
{
	SDL_Rect rectangulo_bola;
	SDL_Rect rectangulo_pong1;
	SDL_Rect rectangulo_pong2;
	
	/* Obtenemos las dimensiones de la bola y el pong */
	rectangulo_bola = Bola_rectangulo_colision(bola);
	rectangulo_pong1 = Pong_rectangulo_colision(pong1);
	rectangulo_pong2 = Pong_rectangulo_colision(pong2);

	/* Comprobamos si hay colisión con el extremo superior e inferior */
	if(rectangulo_bola.y <= 0 || (rectangulo_bola.y+rectangulo_bola.h) >= PANTALLA_ALTO){
		Bola_invertir_velocidadY(bola);
	}

	/* Comprobamos si hay colisión con el pong 1 */
	else if(/* */)){
			/* Rebote, invierte velocidad X*/
	}
		
	/* Comprobamos si hay colisión con el pong 2 */
	else if(/* */)){
			/* Rebote, invierte velocidad X*/
	}

	/* Comprobamos si ha entrado en alguna de las dos porterías */
	else if(/*  */){ /* Gol del jugador 2 */
		/* Restauramos posición y velocidad */
	}
	else if(/* */){ /* Gol del jugador 1 */
		/* Restauramos posición */
	}
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
		
		/* Actualizar pong de J2 según IA */
		
		
		/* Actualizar Bola */
		Bola_actualizar(juego->bola);
		
		/* Colisiones */
		Juego_comprobar_colisiones(juego->bola, juego->pong1, juego->pong2);
		
		/* Dibujar Mesa */
		Imagen_dibujar(juego->mesa, juego->pantalla, 0, 0);
		
		/* Dibujar J1 */
		Pong_dibujar(juego->pong1, juego->pantalla);
	
		/* Dibujar J2 */
		Pong_dibujar(juego->pong2, juego->pantalla);
		
		/* Dibujar Bola */
		Bola_dibujar(juego->bola, juego->pantalla);
		
		/* Flipping, intercambio de superficies (mostramos la pantalla) */
		SDL_Flip(juego->pantalla);
		
		/* Control de tiempo */
		Juego_control_tiempo(juego);
	}
}
