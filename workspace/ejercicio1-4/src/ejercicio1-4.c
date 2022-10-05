/*
 ============================================================================
 Name        : ejercicio1-4.c
 Author      : Agustin
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style

 Ingresar 5 caracteres e informar cuantas letras p (minúsculas) se ingresaron.

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout,NULL);

	char caracterUno;
	char caracterDos;
	char caracterTres;
	char caracterCuatro;
	char caracterCinco;
	int contadorP;
	contadorP= 0;

	printf("Ingrese un caracter(a/z): ");
	fflush(stdin);
	scanf("%c",&caracterUno);

	printf("Ingrese un 2do caracter(a/z): ");
	fflush(stdin);
	scanf("%c",&caracterDos);

	printf("Ingrese un 3er caracter(a/z): ");
	fflush(stdin);
	scanf("%c",&caracterTres);

	printf("Ingrese un 4to caracter(a/z): ");
	fflush(stdin);
	scanf("%c",&caracterCuatro);

	printf("Ingrese un 5to caracter(a/z): ");
	fflush(stdin);
	scanf("%c",&caracterCinco);

	if(caracterUno == 'p' && caracterDos == 'p' && caracterTres == 'p' && caracterCuatro == 'p' && caracterCinco == 'p'){
		contadorP++;
	}

	printf("La cantidad de letras p minusculas que se ingresaron fueron: %d\n", contadorP);

	return EXIT_SUCCESS;
}
