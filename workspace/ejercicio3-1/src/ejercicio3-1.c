/*
 ============================================================================
 Name        : ejercicio3-1.c
 Author      : Agustin
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style

 Crear una funci�n que muestre por pantalla el n�mero flotante  que recibe como par�metro.

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int mostrarPorPantallaNumeroFlotante(float numeroUno);

int main(void) {
	setbuf(stdout, NULL);

	mostrarPorPantallaNumeroFlotante(2.6);

	return EXIT_SUCCESS;
}

int mostrarPorPantallaNumeroFlotante(float numeroUno){

	printf("Numero flotante: %.2f", numeroUno);

	return 0;
}


