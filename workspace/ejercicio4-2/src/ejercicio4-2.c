/*
 ============================================================================
 Name        : ejercicio4-2.c
 Author      : Agustin
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style

Realizar un programa que permita la carga de temperaturas en celsius y fahrenheit ,

validando que las temperaturas ingresadas estén entre el punto de congelación y ebullición del agua para cada tipo de escala.

Las validaciones se hacen en una biblioteca.

Las funciones de transformación de fahrenheit a celsius y de celsius a fahrenheit se hacen en otra biblioteca.

Extra:


 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "temperatura.h"

int main(void) {
	setbuf(stdout, NULL);
	float fahrenheit = 0;
	float celsius = 0;
	int opcionMenu;
	int validacionRetorno;
	float equivalencia;

	do{
		printf("******************MENU PRINCIPAL******************\n\n1)Ingresar grados F°\n2)Ingresar grados C°\n3)Calcular de F° a C°\n4)Calcular de C° a F°\n5)Mostrar resultados\n6)Salir\n\n");
		validacionRetorno = getInt(&opcionMenu,"Selecione una opcion.\n","Error. Ingrese una opcion valida.\n",6,1,0);
		if(validacionRetorno == 0){
			switch(opcionMenu){
				case 1:
					printf("Ingrese grados F°:");
					scanf("%f",&fahrenheit);
					break;
				case 2:
					printf("Ingrese grados C°:");
					scanf("%f",&celsius);
					break;
				case 3:
					equivalencia = fahrenheitAcelsius(fahrenheit);
					break;
				case 4:
					equivalencia = celsiusAfahrenheit(celsius);
					break;
				case 5:
					printf("%.2f F° equivalen a %.2f C°.\n",fahrenheit,equivalencia);
					printf("%.2f C° equivalen a %.2f F°.\n",celsius,equivalencia);
					break;
				case 6:
					printf("El programa termino.");
					break;
			}
		}
	}while(opcionMenu != 6);

	return EXIT_SUCCESS;
}

int pidoEntero(int maximo, int minimo){
	int numeroIngresado;
	int retorno;
	retorno = -1;
	printf("Ingrese los grados:");
	scanf("%d",&numeroIngresado);
	if(numeroIngresado >= minimo && numeroIngresado <= maximo){
		retorno = 0;
	}
	return retorno;
}

