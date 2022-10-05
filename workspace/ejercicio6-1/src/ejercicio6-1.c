/*
 ============================================================================
 Name        : ejercicio6-1.c
 Author      : Agustin
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style

 Disponemos de dos variables numéricas (a y b).
 Realizar un algoritmo que permita el intercambio de valores de dichas variables.

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout,NULL);

	int a;
	int b;
	int auxiliar;

	printf("Valor 1:");
	scanf("%d",&a);

	printf("Valor 2:");
	scanf("%d",&b);

	printf("\n\nIntercambiando valores...\n\n");

	auxiliar = a;
	a = b;
	b = auxiliar;

	printf("\nAhora el valor de V1 es: %d\n",a);
	printf("Ahora el valor de V2 es: %d\n",b);

	return EXIT_SUCCESS;
}
