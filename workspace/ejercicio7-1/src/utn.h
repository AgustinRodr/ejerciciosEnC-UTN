/*
 * utn.h
 *
 *  Created on: 12 sep. 2022
 *      Author: invitadopc
 */
#ifndef UTN_H_
#define UTN_H_

/// @brief funcion que se utiliza para obtener un numero entero en un rango determinado
///
/// @param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
/// @param pMensaje puntero al espacio de memoria del mensaje a ser mostrado
/// @param pMensajeError puntero al espacio de memoria del mensaje de error a ser mostrado
/// @param minimo es el numero minimo a ser aceptado
/// @param maximo es el numero maximo a ser aceptado
/// @param reintentos Parametro que determina la cantidad de reintentos antes de que la funcion finalice
/// @return retorna 0 si se obtuvo el numero, sino retorna -1
int utn_getNumero(int * pResultado,char*pMensaje, char*pMensajeError, int minimo, int maximo, int reintentos);


int pedirCosto(float* pCosto,char* pMensaje,char* pMensajeDeError,int reintentos);

/// @brief Funcion que se utiliza para obtener un numero entero en un rango determinado por la misma
///
/// @param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
/// @param pMensaje Es el mensaje a ser mostrado
/// @param pMensajeError Es el mensaje de error a ser mostrad
/// @param minimo El numero minimo aceptado
/// @param maximo El numero maximo aceptado
/// @param reintentos
/// @return
int utn_getInt(int* pResultado,char* pMensaje,char* pMensajeError,int minimo,int maximo,int reintentos);

/// @brief Funcion que verifica si la cadena igresada es numerica
///
/// @param pResultado Es el puntero al espacio de memoria donde se dejara el resultado de la funcion
/// @return Retorna 0 (EXITOSO) si se obtiene un numero entero y sino retorna -1 (ERROR)
int getInt(int* pResultado);


/// @brief Esta funcion lee stin hasta que encuentra un '\n' o hasta que haya copiado en cadena
/// un *maximo de 'longitud -1 ' caracteres
///
/// @param cadena puntero al espacio de memoria donde se copiara lac adena obtenida
/// @param longitud define el tamaño de cadena
/// @return retorna 0 (EXITOSO) si se obtiene una cadena y -1 (ERROR) si no
int myGets(char* cadena,int longitud);

/// @brief verifica si la cadena ingresada es un nombre (letras y espacios)
///
/// @param cadena
/// @return  retorna 1 si esta ok y si es valida, y 0 si fallo alguna validacion
int esNombre(char* cadena);

/// @brief funcion que verifica si la cadena ingresada es numerica
///
/// @param cadena cadena ed caracteres que va a ser analizada
/// @return esta funcion retorna 1 (TRUE) si la cadena es numerica sino 0 (FALSO) si no lo es
int esNumerica(char* cadena);

int utn_getFloat(float* pResultado, char* pMensaje, char* pMensajeError, int minimo, int maximo, int reintentos);
int getFloat(float* pResultado);
int esNumericaDecimal(char* cadena);
/// @brief Obtiene una cadena de caracteres valido conformado por letras || espacios
///
/// @param cadena cadena
/// @param mensaje mensaje a ser mostrado
/// @param mensajeError el mensaje de error a ser mostrado
/// @param reintentos reintentos es el parametro que determina la cantidad de reintentos antes de que la funcion termine
///
/// @return retorna 0 Si se obtuvo la cadena de caracteres sino la pudo obtener retorna -1
int getString(char cadena[],char mensaje[],char mensajeError[],int reintentos);

/// @brief Funcion que imprime mensaje generico
///
/// @param mensaje mensaje a ser mostrado
/// @return
int mensajeGenerico(char* mensaje);

/// @brief Funcion que utilizo para imprimir los informes correspondientes
///
/// @param promUefa
/// @param promConmebol
/// @param promConcacaf
/// @param promAfc
/// @param promOfc
/// @param promCaf
/// @param costoDeMantenimientoOriginal
/// @param costoMantenimientoConAumento
/// @param nuevoCosto
void mostrarInformesDeTodosLosResultados(float promUefa,float promConmebol,float promConcacaf,float promAfc
		,float promOfc,float promCaf,float costoDeMantenimientoOriginal,float costoMantenimientoConAumento,float nuevoCosto);

#endif /* UTN_H_ */
