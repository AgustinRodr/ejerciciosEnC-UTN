/*
 ============================================================================
 Name        : ejercicio1-1.c
 Author      : Agustin
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style

 Ingresar dos números enteros, sumarlos y mostrar el resultado.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);

	int numeroUno;
	int numeroDos;
	int resultado;

	printf("Ingrese el primero numero: ");
	scanf("%d",&numeroUno);

	printf("Ingrese el segundo numero: ");
	scanf("%d",&numeroDos);

	resultado = numeroUno + numeroDos;

	printf("La suma entre %d + %d da como resultado: %d ",numeroUno, numeroDos, resultado);

	return EXIT_SUCCESS;
}
