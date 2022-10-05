/*
 ============================================================================
 Name        : ejercicio1-3.c
 Author      : Agustin
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style

 ingresar 3 números y mostrar el número del medio, sólo si existe. En caso de que no exista también informarlo

 1   5   3     el 3 es del medio
 5   1   5    no hay numero del medio
 3   5   1     el 3 es del medio
 3   1   5    el 3 es del medio
 5   3   1    el 3 es del medio



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
	int numeroMasChico;
	int numeroMedio;

	printf("Numero uno: ");
	scanf("%d", &numeroUno);
	printf("Numero dos: ");
	scanf("%d", &numeroDos);
	printf("Numero tres: ");
	scanf("%d", &numeroTres);

	if (numeroUno >= numeroDos && numeroUno >= numeroTres) {
		numeroMasGrande = numeroUno;
	}else if (numeroDos >= numeroUno && numeroDos >= numeroTres) {
		numeroMasGrande = numeroDos;
	}else if (numeroTres >= numeroUno && numeroTres >= numeroDos) {
		numeroMasGrande = numeroTres;
	}
	if(numeroUno <= numeroDos && numeroUno <= numeroTres) {
		numeroMasChico = numeroUno;
	}
	else if (numeroDos <= numeroUno && numeroDos <= numeroTres) {
		numeroMasChico = numeroDos;
	}
	else if (numeroTres <= numeroUno && numeroTres <= numeroDos) {
		numeroMasChico = numeroTres;
	}
	if (numeroUno < numeroMasGrande && numeroUno > numeroMasChico) {
		numeroMedio = numeroUno;
	}
	else if (numeroDos < numeroMasGrande && numeroDos > numeroMasChico) {
		numeroMedio = numeroDos;
	}
	else if (numeroTres < numeroMasGrande && numeroTres > numeroMasChico) {
		numeroMedio = numeroTres;
	}
	else {
		printf("No hay numero del medio\n");
	}

	printf("El numero mas chico es:%d\nEl numero del medio es:%d\nEl numero mas grande es:%d",numeroMasChico,numeroMedio,numeroMasGrande);

	return 0;
}
