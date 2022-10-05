/*
 ============================================================================
 Name        : ejercicio2-2.c
 Author      : Agustin
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style

 Ingresar 10 números enteros, distintos de cero. Mostrar:
Cantidad de pares e impares.
El menor número ingresado.
De los pares el mayor número ingresado.
Suma de los positivos.
Producto de los negativos.


 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	setbuf(stdout, NULL);
	int numeroIngresado;
	int numeroMenorIngresado;
	int numeroMayorParIngresado;
	int acumuladorPositivos;
	int i;
	int productoNegativos;
	int acumuladorNegativos;
	int contadorNumerosPares;
	int contadorNumerosImpares;
	int flag;
	contadorNumerosPares = 0;
	contadorNumerosImpares = 0;
	acumuladorPositivos = 0;
	acumuladorNegativos = 0;
	flag = 0;

	for(i = 0; i < 10; i++){
		printf("Ingrese un numero:");
		scanf("%d", &numeroIngresado);
		if(numeroIngresado %2 == 0){
			contadorNumerosPares++;
		}else{
			contadorNumerosImpares++;
		}
		if(flag == 0 || numeroIngresado < numeroMenorIngresado){
			numeroMenorIngresado=numeroIngresado;
			flag = 1;
		}
		if(flag == 0 || numeroIngresado %2 == 0){
			numeroMayorParIngresado=numeroIngresado;
			flag = 1;
		}
		if(numeroIngresado>=0){
	        acumuladorPositivos+=numeroIngresado;
	    }else{
	        acumuladorNegativos+=numeroIngresado;
	        flag = 1;
	    }
	}
	if(numeroIngresado < 0){
		productoNegativos=acumuladorNegativos*numeroIngresado;
	}
	printf("La cantidad de numeros pares: %d \nLa cantidad de numeros impares: %d \nEl numero menor ingresado es: %d \nDe los pares el mayor numero ingresado: %d\nLa suma de los positivos: %.1d \nEl producto de los negativos: %.2d"
			, contadorNumerosPares, contadorNumerosImpares, numeroMenorIngresado, numeroMayorParIngresado, acumuladorPositivos, productoNegativos);

	return EXIT_SUCCESS;
}
