/*
 ============================================================================
 Name        : ejercicio3-3.c
 Author      : Agustin
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style

 Crear una función que pida el ingreso de un entero y lo retorne.

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int pidoEntero(void);

int main(void) {
	setbuf(stdout, NULL);

	int numeroIngresado;
	numeroIngresado = pidoEntero();
	printf("Numero ingresado: %d", numeroIngresado);
	return EXIT_SUCCESS;
}

int pidoEntero(void){
	int numeroIngresado;
	printf("Ingrese un numero entero:");
	scanf("%d",&numeroIngresado);
	return numeroIngresado;
}
