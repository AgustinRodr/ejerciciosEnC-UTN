/*
 ============================================================================
 Name        : ejercicio3-5.c
 Author      : Agustin
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style

 Realizar un programa en donde se puedan utilizar los prototipos de la función Sumar en sus 4 combinaciones.


int Sumar1(int, int);
int Sumar2(void);
void Sumar3(int, int);
void Sumar4(void);


 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

//int sumar1(int numeroUno, int numeroDos);
//int sumar2(void);
//void sumar3(int numeroUno, int numeroDos);
void sumar4(void);

int main(void) {
	setbuf(stdout, NULL);

	sumar4();

	return EXIT_SUCCESS;
}

void sumar4(void){
	int numero1;
	int numero2;
	int resultado;
	printf("Ingrese un numero: ");
	scanf("%d",&numero1);
	printf("Ingrese otro numero: ");
	scanf("%d",&numero2);
	resultado = numero1 + numero2;
	printf("El resultado de la suma es: %d",resultado);
}


//void sumar3(int numeroUno, int numeroDos){
//	int numero1;
//	int numero2;
//	int resultado;
//	printf("Ingrese un numero: ");
//	scanf("%d",&numero1);
//	printf("Ingrese otro numero: ");
//	scanf("%d",&numero2);
//	resultado = numero1 + numero2;
//	printf("El resultado de la suma es: %d",resultado);
//}


//int sumar2(void){
//	int numero1;
//	int numero2;
//	int resultado;
//	printf("Ingrese un numero: ");
//	scanf("%d",&numero1);
//	printf("Ingrese otro numero: ");
//	scanf("%d",&numero2);
//	resultado = numero1 + numero2;
//	printf("El resultado de la suma es: %d",resultado);
//
//	return 0;
//}


//int sumar1(int numeroUno, int numeroDos){
//	int numero1;
//	int numero2;
//	int resultado;
//	printf("Ingrese un numero: ");
//	scanf("%d",&numero1);
//
//	printf("Ingrese un numero: ");
//	scanf("%d",&numero2);
//
//	resultado = numero1 + numero2;
//
//	printf("La suma es %d", resultado);
//
//	return resultado;
//}
