/*
 * utn.c
 *
 *  Created on: 12 sep. 2022
 *      Author: invitadopc
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "utn.h"

int utn_getNumero(int * pResultado, char*pMensaje, char*pMensajeError, int minimo, int maximo, int reintentos){
	int retorno;
	int buffer;

	retorno = -1;

	if (pResultado != NULL && pMensaje != NULL && pMensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do{
		printf("%s",pMensaje);
		scanf("%i", &buffer);
		fflush(stdin);
		if(pResultado > 0 && buffer >= minimo && buffer <= maximo){
			*pResultado = buffer;
			retorno = 0;
			break;
		}
		else{
			printf("%s",pMensajeError);
			reintentos--;
		}
		}while(reintentos >= 0);
	}
	return retorno;
}

int pedirCosto(float* pCosto,char* pMensaje,char* pMensajeDeError,int reintentos){
	int retorno;
	float costo;
	retorno = -1;
	if(pCosto != NULL && pMensaje != NULL && pMensajeDeError != NULL && reintentos >= 0){
		do{
			printf("%s",pMensaje);
			fflush(stdin);
			scanf("%f",&costo);
			if(costo > 0){
				retorno = 0;
				*pCosto = costo;
				break;
			}else{
				reintentos--;
				printf("%s",pMensajeDeError);
			}
		}while(reintentos >= 0);
	}
	return retorno;
}


int utn_getInt(int* pResultado,char* pMensaje,char* pMensajeError,int minimo,int maximo,int reintentos){
	int retorno;
	int buffer;
	retorno = -1;
	if(pResultado != NULL && pMensaje != NULL && pMensajeError != NULL && minimo <= maximo && reintentos >= 0){
		while(reintentos>0){
			printf(pMensaje);
			fflush(stdin);
			if(getInt(&buffer)==1){
				if(buffer <= maximo && buffer >= minimo){
					break;
				}
			}
			fflush(stdin);
			reintentos--;
			printf(pMensajeError);
		}
		if(reintentos==0){
			retorno=-1;
		}else{
			retorno = 0;
			*pResultado = buffer;
		}
	}
	return retorno;
}


int getInt(int* pResultado){
	int retorno;
	char buffer[64];
	retorno = -1;
	if(pResultado != NULL){
		if(myGets(buffer,sizeof(buffer))==0 && esNumerica(buffer)){
			*pResultado = atoi(buffer);
			retorno = 1;
		}
	}
	return retorno;
}

int myGets(char* cadena,int longitud){
	int retorno;
	retorno = -1;
	if(cadena != NULL && longitud > 0 && fgets(cadena,longitud,stdin)==cadena){
		fflush(stdin);
		if(cadena[strlen(cadena)-1]== '\n'){
			cadena[strlen(cadena)-1] = '\0';
		}
		retorno = 0;
	}
	return retorno;
}

int esNumerica(char* cadena){
	int i;
	int retorno;
	i = 0;
	retorno = 1;
	if(cadena != NULL && strlen(cadena) > 0)
	{
		while(cadena[i] != '\0')
		{
			if(cadena[i] < '0' || cadena[i] > '9')
			{
				retorno = 0;
				break;
			}
			i++;
		}
	}
	return retorno;
}


int esNombre(char* cadena){
	int retorno;
	retorno = 1;
	int esLetra;
	int i = 0;
	if(cadena != NULL){
		while(cadena[i]!='\0'){
			esLetra=isalpha(cadena[i]);
			if(esLetra!= 0 || cadena[i] == ' '){
				i++;
			}else{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}


int getString(char cadena[],char mensaje[],char mensajeError[],int reintentos){
	int retorno;
	retorno = -1;
	char cadenaAux[51];
	if(mensaje != NULL && cadena != NULL && mensajeError != 0 && reintentos > 0){
		do{
			printf("%s",mensaje);
			fflush(stdin);
			if(myGets(cadenaAux,sizeof(cadenaAux)) ==0 && esNombre(cadenaAux) == 1){
				strcpy(cadena,cadenaAux);
				retorno = 0;
				break;
			}else{
				printf("%s",mensajeError);
				reintentos--;
				retorno = 1;
			}
		}while(reintentos >= 0);
	}
	return retorno;
}


int mensajeGenerico(char* mensaje){
	printf("%s",mensaje);
	return 0;
}

void mostrarInformesDeTodosLosResultados(float promUefa,float promConmebol,float promConcacaf,float promAfc
		,float promOfc,float promCaf,float costoDeMantenimientoOriginal,float costoMantenimientoConAumento,float nuevoCosto){
	printf("\n\tInformar todos los resultados\n\n");
	printf("Porcentaje Uefa %.2f\n",promUefa);
	printf("Porcentaje Conmebol %.2f\n",promConmebol);
	printf("Porcentaje Concacaf %.2f\n",promConcacaf);
	printf("Porcentaje Afc %.2f\n",promAfc);
	printf("Porcentaje Ofc %.2f\n",promOfc);
	printf("Porcentaje Caf %.2f\n",promCaf);
	printf("El costo de mantenimiento era de $%4.f y recibio un aumento de $%4.f, su nuevo valor es de: $%4.f",costoDeMantenimientoOriginal,costoMantenimientoConAumento,nuevoCosto);

}
