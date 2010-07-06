#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "imagen.h"
#include "juego.h"
#include "pong.h"
#include "marcador.h"
#include "bola.h"
#include "constantes.h"

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
	
	/* Establecemos una semilla para los números aleatorios */
	srand(time(NULL));
	
	/* Creamos los elementos del juego */
	juego->pong1 = Pong_crear(J1);
	juego->pong2 = Pong_crear(J2);
	juego->bola = Bola_crear();
	juego->mesa = Imagen_cargar("multimedia/Fondo.png");
	juego->marcador = Marcador_crear();
	
	/* Inicializamos el teclado */
	juego->teclado = SDL_GetKeyState(NULL);
	
	return juego;
}

void Juego_destruir(Juego juego)
{
	/* Destuimos todos los elementos del juego */
	Pong_destruir(juego->pong1);
	Pong_destruir(juego->pong2);
	Bola_destruir(juego->bola);
	Marcador_destruir(juego->marcador);
	Imagen_borrar(juego->mesa);
	
	/* Cerramos SDL */
	SDL_Quit();
	
	/* Liberamos la memoria de juego */
	free(juego);
}

int Juego_comprobar_colisiones(Bola bola, Pong pong1, Pong pong2)
{
	SDL_Rect rectangulo_bola;
	SDL_Rect rectangulo_pong1;
	SDL_Rect rectangulo_pong2;
	
	/* Obtenemos las dimensiones de la bola y el pong */
	rectangulo_bola = Bola_rectangulo_colision(bola);
	rectangulo_pong1 = Pong_rectangulo_colision(pong2);
	rectangulo_pong2 = Pong_rectangulo_colision(pong2);

	/* Comprobamos si hay colisión con el extremo superior e inferior */
	if(rectangulo_bola.y <= 0 || (rectangulo_bola.y+rectangulo_bola.h) >= PANTALLA_ALTO){
		Bola_invertir_velocidadY(bola);
		return NADA;
	}

	/* Comprobamos si hay colisión con el pong1 */
	else if(rectangulo_bola.x <= (rectangulo_pong1.x + rectangulo_pong1.w) &&
		rectangulo_bola.x >= rectangulo_pong1.x								&&
		rectangulo_bola.y >= rectangulo_pong1.y 								&&
		rectangulo_bola.y <= (rectangulo_pong1.y + rectangulo_pong1.h)){
		
			Bola_invertir_velocidadX(bola);
			return NADA;
		
		}
		
	/* Comprobamos si hay colisión con el pong2 */
	else if((rectangulo_bola.x + rectangulo_bola.w) >= rectangulo_pong2.x  &&
		rectangulo_bola.x <= (rectangulo_pong2.x + rectangulo_pong2.w) &&
		(rectangulo_bola.y + rectangulo_bola.h) >= rectangulo_pong2.y  &&
		(rectangulo_bola.y + rectangulo_bola.h) <= (rectangulo_pong2.y + rectangulo_pong2.h)){
		
			Bola_invertir_velocidadX(bola);
			return NADA;
		
		}

	/* Comprobamos si ha entrado en alguna de las dos porterías */
	else if(rectangulo_bola.x <= 0){ /* Gol del jugador 2 */
		bola->x = 200;
		bola->y = 300;
		return J2;
	}
	else if(rectangulo_bola.x >= PANTALLA_ANCHO){ /* Gol del jugador 1 */
		bola->x = 200;
		bola->y = 300;
		return J1;
	}
	else{
		return NADA;
	}
}

void Juego_puntuar(int jugador, Marcador marcador)
{
	if(jugador != NADA)
	{
		Marcador_incrementar(marcador, jugador);
	}
}

void Juego_bucle_principal(Juego juego)
{
	int salir = 0, colision;
	
	/* Mientras no queramos salir */
	while(!salir){
		/* Actualizar entrada */
		juego->teclado = SDL_GetKeyState(NULL);
		
		/* Actualizar pong de J1 según entrada */ 
		Pong_actualizar_entrada(juego->pong1, juego->teclado);
			
		/* Actualizar pong de J2 según IA */
		/* Pong_actualizar_ia(juego->pong2);*/
			
		/* Actualizar Bola */
		Bola_actualizar(juego->bola);
		
		/* Borramos la pantalla */
		SDL_FillRect(juego->pantalla, NULL, SDL_MapRGB(juego->pantalla->format, 0, 0, 0));
			
		/* Dibujar Mesa */
		Imagen_dibujar(juego->mesa, juego->pantalla, 0, 0);
			
		/* Dibujar J1 */
		Pong_dibujar(juego->pong1, juego->pantalla);

			
		/* Dibujar J2 */
		Pong_dibujar(juego->pong2, juego->pantalla);
			
		/* Dibujar Bola */
		Bola_dibujar(juego->bola, juego->pantalla);
		
		/* Dibujar Marcador */
		Marcador_dibujar(juego->marcador, juego->pantalla);
		
		/* Flipping, intercambio de superficies (mostramos la pantalla) */
		SDL_Flip(juego->pantalla);
			
		/* Colisiones */
		colision = Juego_comprobar_colisiones(juego->bola, juego->pong1,juego->pong2);
		Juego_puntuar(colision, juego->marcador);
		
		/* Procesamos la cola de eventos */
		salir = Juego_procesar_eventos();
		
		/* Control de tiempo */
						
	}
}
