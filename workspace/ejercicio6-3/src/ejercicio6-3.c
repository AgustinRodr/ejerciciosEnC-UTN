/*
 ============================================================================
 Name        : ejercicio6-3.c
 Author      : Agustin
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style

 Pedirle al usuario su nombre y apellido (en variables separadas, una para el nombre y otra para el apellido).
 Ninguna de las dos variables se puede modificar.
Debemos lograr guardar en una tercer variable el apellido y el nombre con el siguiente formato:
Por ejemplo:
Si el nombre es juan ignacio y el apellido es gOmEz, la salida debería ser:

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 30
#define MAXNOMBREYAPELLIDO 50

int main(void) {
	setbuf(stdout, NULL);

	char nombre[MAX];
	char apellido[MAX];
	char nombreYApellido[MAXNOMBREYAPELLIDO];

	printf("Ingrese su nombre: ");
	fflush(stdin);
	gets(nombre);
	strlwr(nombre);
	nombre[0] = toupper(nombre[0]);
	printf("Su nombre es: %s \n",nombre);

	printf("Ingrese su apellido: ");
	fflush(stdin);
	gets(apellido);
	strlwr(apellido);
	apellido[0] = toupper(apellido[0]);
	printf("\nSu apellido es: %s \n",apellido);

	strcpy(nombreYApellido, apellido);
	strcat(nombreYApellido, ", ");
	strcat(nombreYApellido, nombre);

	printf("\nSu nombre es %s", nombreYApellido);

	return EXIT_SUCCESS;
}
