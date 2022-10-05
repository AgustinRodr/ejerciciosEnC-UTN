/*
 ============================================================================
 Name        : ejercicio6-2.c
 Author      : Agustin
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style

 Realizar un programa que permita el ingreso de 10 números enteros (positivos y negativos).
  Necesito generar un listado de los números positivos de manera creciente y negativos de manera decreciente.
  (Como máximo 5 estructuras repetitivas)
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

#define LEN 10

void cargarArray(int pArray[]);
void ordenamientoBurbuja(int pArray[]);
int imprimirArray(int pArray[]);

int main(void) {
	setbuf(stdout, NULL);

	int arrayNumeros[LEN];

	cargarArray(arrayNumeros);
	ordenamientoBurbuja(arrayNumeros);
	imprimirArray(arrayNumeros);

	return EXIT_SUCCESS;
}

void cargarArray(int pArray[]){
	int i;
	i = 0;
	for(i = 0;i < LEN; i++){
		printf("Ingrese un numero: ");
		scanf("%d",&pArray[i]);
	}
}

void ordenamientoBurbuja(int pArray[]){
	int i;
	int j;
	int aux;
	i = 0;

	for(i = 0;i < LEN-1; i++){
		for(j = i + 1; j < LEN; j++){
			if(pArray[i] < pArray[j]){
				aux = pArray[i];
				pArray[i] = pArray[j];
				pArray[j] = aux;
			}
		}
	}
}

int imprimirArray(int pArray[]){
	int retorno;
	int i;
	retorno = -1;
	i = 0;
	if(pArray != NULL){
		retorno = 0;
		for(i = 0;i < LEN;i++){
			printf("%d\n",pArray[i]);
		}
	}
	return retorno;
}
