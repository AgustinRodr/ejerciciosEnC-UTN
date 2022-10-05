/*
 ============================================================================
 Name        : ejercicio2-1.c
 Author      : Agustin
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);

	int numeroIngresado;
	int i;
	int contadorNumeros;
	int acumuladorNumeros;
	int promedioNumeros;
	contadorNumeros = 0;
	acumuladorNumeros = 0;
	for(i = 0; i<5;i++){
		printf("Ingrese un numero:");
		scanf("%d", &numeroIngresado);
		if(numeroIngresado>0){
			contadorNumeros++;
			acumuladorNumeros+=numeroIngresado;
		}
	}
	promedioNumeros=acumuladorNumeros/contadorNumeros;
	printf("El promedio de los numeros ingresados: %d", promedioNumeros);

	return EXIT_SUCCESS;
}
