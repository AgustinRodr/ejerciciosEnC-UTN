/*
 ============================================================================
 Name        : ejercicio2-3.c
 Author      : Agustin
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style

 Debemos alquilar el servicio de transporte para llegar a Mar del Plata con un grupo de personas (no más de 100),
 de cada persona debemos obtener los siguientes datos:
 número de cliente,
 estado civil ('s' para soltero", 'c' para casado o 'v' viudo),
 edad( solo mayores de edad, más de 17),
 temperatura corporal (validar por favor)
 y genero('f' para femenino, 'm' para masculino, 'o' para no binario).
 NOTA: El precio por pasajero es de $600.
 Se debe informar (solo si corresponde):
 a) La cantidad de personas con estado  civil"viudo" de más de 60 años.
 b) el número de cliente y edad de la mujer soltera más joven.
 c) cuánto sale el viaje total sin descuento.
 d) si hay más del 50% de los pasajeros que tiene más de 60 años ,
 el precio final tiene un descuento del 25%, que solo mostramos si corresponde.

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define PASAJE 600
#define DESCUENTO 0.25

int main(void) {

	setbuf(stdout, NULL);
	int numeroDeCliente;
	char estadoCivil;
	int edad;
	int edadMujerSolteraMasJoven;
	int numeroDeClienteMujerSolteraMasJoven;
	float temperaturaCorporal;
	char sexoIngresado;
	float viajeTotalSinDescuento;
	estadoCivil = 's';
	estadoCivil = 'c';
	estadoCivil = 'v';
	sexoIngresado = 'f';
	sexoIngresado = 'm';
	sexoIngresado = 'o';
	int pasajeros;
	float viajeTotalConDescuento;
	int contadorViudos;
	contadorViudos = 0;
	int flag = 0;

	char respuesta = 's';

	do {
		printf("Ingrese su Numero de cliente:");
		scanf("%d", &numeroDeCliente);

		printf("Ingrese la cantidad de pasajeros:($600, por pasajero)");
		scanf("%d", &pasajeros);

		printf("Ingrese su estado civil. Indique: s - para soltero, c- casado, v - viudo");
		fflush(stdin);
		scanf("%c", &estadoCivil);

		printf("Ingrese su edad (Mayor de 17) :");
		scanf("%d", &edad);

		printf("Ingrese su temperatura corporal (36 a 42) :");
		scanf("%f", &temperaturaCorporal);

		printf("Ingrese su sexo. Indique:\nf - femenino.\nm - masculino.\no - no binario.");
		fflush(stdin);
		scanf("%c", &sexoIngresado);

		if(edad <= 16){
			printf("Ocurrio un error.\nTiene que ser mayor de 17 años.\n");
		}
		if(temperaturaCorporal <= 35 && temperaturaCorporal >= 43){
			printf("Ocurrio un error.\nLa temperatura tiene que estar dentro del rango especificado.");
		}
		if(estadoCivil == 'v' && edad >= 60) {
			contadorViudos++;
		}
		if(estadoCivil == 's' && sexoIngresado == 'f') {
			if(flag == 0 || edadMujerSolteraMasJoven > edad){
			edadMujerSolteraMasJoven = edad;
			numeroDeClienteMujerSolteraMasJoven = numeroDeCliente;
			flag = 1;
			}
		}
		if(edad > 60) {
			viajeTotalConDescuento = pasajeros * PASAJE * DESCUENTO;
		}

		printf("Desea seguir cargando datos? (s/n)");
		fflush(stdin);
		scanf("%c", &respuesta);
	} while (respuesta == 's');

	viajeTotalSinDescuento = PASAJE * pasajeros;

	printf("La cantidad de personas con estado  civil viudo, de más de 60 años: %d es la cantidad.\n",contadorViudos);
	printf("El número de cliente y edad de la mujer soltera más joven: %d, %d años.\n",numeroDeClienteMujerSolteraMasJoven, edadMujerSolteraMasJoven);
	printf("El viaje total sin descuento: %.2f \n", viajeTotalSinDescuento);
	printf("el precio final tiene un descuento del 25 porciento : %.2f",
			viajeTotalConDescuento);

	return EXIT_SUCCESS;
}
