/*
 ============================================================================
 Name        : ejercicio1-2.c
 Author      : Agustin
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style

 ingresar 3 números y mostrar cuál de los tres es el mayor.

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);

	int numeroUno;
	int numeroDos;
	int numeroTres;
	int numeroMasGrande;

	printf("Ingrese el 1er numero: ");
	scanf("%d",&numeroUno);

	printf("Ingrese el 2do numero: ");
	scanf("%d",&numeroDos);

	printf("Ingrese el 3er numero: ");
	scanf("%d",&numeroTres);

	if(numeroUno > numeroDos && numeroUno > numeroTres){
		numeroMasGrande = numeroUno;
	}else if(numeroDos > numeroUno && numeroDos > numeroTres){
		numeroMasGrande = numeroDos;
	}else if(numeroTres > numeroUno && numeroTres > numeroDos){
		numeroMasGrande = numeroTres;
	}

	printf("El numero mas grande es: %d", numeroMasGrande);

	return EXIT_SUCCESS;
}
