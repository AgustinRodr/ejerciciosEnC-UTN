/*
 ============================================================================
 Name        : ejercicio5-2.c
 Author      : Agustin
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style

 Pedir el ingreso de 10 números enteros entre -1000 y 1000. Determinar:
 Cantidad de positivos y negativos.
 Sumatoria de los pares.
 El mayor de los impares.
 Listado de los números ingresados.
 Listado de los números pares.
 Listado de los números de las posiciones impares.

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "arrays.h"

#define LEN 5

void contadorNumerosPositivosYNegativos(int pArray[],int len);
void listadoNumerosPares(int pArray[],int len);
void listadoPosicionesImpares(int pArray[],int len);
void mayorDeLosImpares(int pArray[],int len, int * pImpares);
int buscarMaximo(int pArray[],int len);

int main(void) {
	setbuf(stdout, NULL);

	int arraysNumeros[LEN];
	int suma;
	int mayorImpar;
	mayorImpar = 0;

	pedirNumeros(arraysNumeros, LEN, 1000, -1000);
	contadorNumerosPositivosYNegativos(arraysNumeros,LEN);
	sumarNumerosEnArray(arraysNumeros, LEN, &suma);

	printf("La suma de los numeros es: %d\n",suma);

	mostrarNumeros(arraysNumeros, LEN);

	mayorDeLosImpares(arraysNumeros, LEN, &mayorImpar);

	listadoNumerosPares(arraysNumeros,LEN);

	listadoPosicionesImpares(arraysNumeros,LEN);

	return EXIT_SUCCESS;
}

void contadorNumerosPositivosYNegativos(int pArray[],int len){
	int i;
	int negativo = 0;
	int positivo = 0;
	i = 0;

	for(i = 0; i < len; i++){
		if(pArray[i]>0){
			positivo++;
		}else{
			negativo++;
		}
	}
	if(negativo == 0){
		printf("No hay numeros negativos ingresados.\n");
	}
	if(positivo == 0){
		printf("No hay numeros positivos ingresados.\n");
	}
	printf("\nLa cantidad de numeros POSITIVOS: %d\nLa cantidad de numeros NEGATIVOS: %d\n", positivo, negativo);
}

void mayorDeLosImpares(int pArray[],int len, int * pImpares){
	int i = 0;
	int impares = 0;
	int busquedaMaximo;

	for(i = 0; i < len; i++){
		if(i % 2 != 0){
			impares++;
			*pImpares = impares;
		}
	}
		busquedaMaximo = buscarMaximo(pArray, len);
		printf("El numero maximo de los impares es : %d\n",busquedaMaximo);
}


void listadoNumerosPares(int pArray[],int len){
	int i;
	i = 0;
	for(i = 0; i < len; i++){
		if(pArray[i] % 2 == 0){
			printf("\nLista numeros pares.\n%d\n", pArray[i]);
		}
	}
}

int buscarMaximo(int pArray[],int len){
	int retorno = -1;
	int i = 0;
	int maximo;
	for(i = 0; i < len; i++){
		if(pArray != NULL){
			if(pArray[i] > maximo){
				maximo = pArray[i];
				retorno = 0;
			}
		}
	}
	return retorno;
}

void listadoPosicionesImpares(int pArray[],int len){
	int i = 0;
	for(i = 0; i < len; i++){
		if(pArray[i] % 2 == 1){
			printf("El contenido de esta posicion impar %d es %d\n", i + 1, pArray[i]);
		}
	}
}
