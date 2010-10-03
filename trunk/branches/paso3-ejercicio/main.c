#include <stdio.h>

#include "motor/juego.h"

int main(int argc, char **argv)
{
	Juego juego;
	
	juego = Juego_crear();
	Juego_bucle_principal(juego);
	Juego_destruir(juego);
	
	return 0;
}
