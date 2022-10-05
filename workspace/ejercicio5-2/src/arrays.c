/*
 * arrays.c
 *
 *  Created on: 7 sep. 2022
 *      Author: invitadopc
 */

#include <stdio.h>
#include <stdlib.h>


int pedirNumeros(int array[], int longitud, int maximo, int minimo){

	int retorno;
	retorno = -1;

	if(longitud > 0 && array!=NULL && maximo >= minimo){
		for(int i = 0; i<longitud; i++){
			printf("Ingrese un numero: ");
			scanf("%d", &array[i]);
		}
		retorno = 0;
	}
	return retorno;
}

int mostrarNumeros(int array[], int longitud){
	int retorno;
	retorno = -1;

	if(longitud > 0 && array!=NULL){
		for(int i = 0; i<longitud; i++){
				printf("%d\n", array[i]);
			}
		retorno = 0;
	}
	return retorno;
}

//suma
int sumarNumerosEnArray(int array[], int longitud, int* pAcumulador){
	int retorno;
	int acumuladorAuxiliar;

	retorno = -1;
	acumuladorAuxiliar = 0;

	if(longitud > 0 && array!=NULL && pAcumulador!=NULL){
		for(int i = 0; i<longitud; i++){
			acumuladorAuxiliar += array[i];
		}
		*pAcumulador = acumuladorAuxiliar;
		retorno = 0;
	}
	return retorno;
}

int contador(int* array,int len,int*contadorNegativos,int* contadorPositivos){
	int retorno;
	int contadorAuxiliarNegativos = 0;
	int contadorAuxiliarPositivos = 0;
	retorno = -1;
	if(len > 0 && array != NULL && contadorNegativos != NULL && contadorPositivos != NULL){
		for(int i = 0;i < len;i++){
			if(array > 0){
				contadorAuxiliarPositivos++;
			}else{
				contadorAuxiliarNegativos++;
			}
			*contadorPositivos = contadorAuxiliarPositivos;
			*contadorNegativos=contadorAuxiliarNegativos;
			retorno = 0;
		}
	}
	return retorno;
}


