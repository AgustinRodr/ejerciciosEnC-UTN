/*
 * utn.h
 *
 *  Created on: 2 sep. 2022
 *      Author: invitadopc
 */

#ifndef UTN_H_
#define UTN_H_

int getInt(int * pNumeroIngresado,char * mensaje,char * mensajeError,
		int maximo, int minimo, int maximoDeReintentos);

int getFloat(float * pResultado, char*pMensaje, char*pMensajeError, int minimo, int maximo, int reintentos);


#endif /* UTN_H_ */
