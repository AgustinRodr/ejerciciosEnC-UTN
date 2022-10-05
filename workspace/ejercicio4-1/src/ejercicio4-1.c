/*
 ============================================================================
 Name        : ejercicio4-1.c
 Author      : Agustin
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style

 Realizar un programa EN EL MAIN que permita calcular y mostrar el factorial de un número.
  Utilizar la función PedirNumero de la ejercitación 3-4.

Por ejemplo:
5! = 5*4*3*2*1 = 120


 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int calcularFactorial(int numero);

int main(void) {
	setbuf(stdout, NULL);

	int numero = 0;

	numero = calcularFactorial(numero);

	return EXIT_SUCCESS;
}

int calcularFactorial(int numero){
	int i, n, fact = 1;
	printf("Ingresa un número para calcular su factorial:");
	scanf("%d",&n);
	for(i = 1; i <= n; i++){
		fact = fact * i;
	}
	printf("Factorial de %d es: %d\n", n, fact);
	return 0;
}
