/*
 * arrays.h
 *
 *  Created on: 2 sep. 2022
 *      Author: invitadopc
 */

#ifndef ARRAYS_H_
#define ARRAYS_H_

#include <stdio.h>
#include <stdlib.h>

//toma de datos
int pedirNumeros(int array[], int longitud, int maximo, int minimo);
//muesta
int mostrarNumeros(int array[], int longitud);
//suma
int sumarNumerosEnArray(int array[], int longitud, int* pAcumulador);
//contador positivos
int contador(int* array,int len,int*contadorNegativos,int* contadorPositivos);
//acumulador de impares, se obtiene el mayor.





#endif /* ARRAYS_H_ */
