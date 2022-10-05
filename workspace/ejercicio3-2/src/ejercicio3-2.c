/*
 ============================================================================
 Name        : ejercicio3-2.c
 Author      : Agustin
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style

 Crear una función que permita determinar si un número es par o no.
  La función retorna 1 en caso afirmativo y 0 en caso contrario. Probar en el main.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int numeroPar(int numeroUno);

int main(void) {
	setbuf(stdout, NULL);
	numeroPar(2);
	return EXIT_SUCCESS;
}

int numeroPar(int numeroUno){

	int numero;
	int retorno;
	retorno = 1;

	printf("Ingrese un numero: ");
	scanf("%d", &numero);

	if(numero % 2 == 0){
		printf("El numero es par.");
	}else{
		printf("El numero es impar. Retorna 0.");
		retorno = 0;
	}
	return retorno;
}
