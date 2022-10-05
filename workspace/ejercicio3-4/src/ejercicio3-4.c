/*
 ============================================================================
 Name        : ejercicio3-4.c
 Author      : Agustin
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style

 Especializar la función anterior para que permita validar el entero ingresado en un rango determinado.

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int pidoEntero(int maximo, int minimo);

int main(void) {
	setbuf(stdout,NULL);

	int numeroIngresado;
	numeroIngresado = pidoEntero(100,1);
	printf("Numero ingresado: %d", numeroIngresado);

	return EXIT_SUCCESS;
}

int pidoEntero(int maximo, int minimo){
	int numeroIngresado;
	int retorno;
	retorno = -1;
	printf("Ingrese un numero entero:");
	scanf("%d",&numeroIngresado);
	if(numeroIngresado >= minimo && numeroIngresado <= maximo){
		retorno = 0;
	}
	return retorno;
}

