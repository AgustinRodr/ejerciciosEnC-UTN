/*
 * arrayProductos.h
 *
 *  Created on: 27 sep. 2022
 *      Author: invitadopc
 */

#ifndef ARRAYPRODUCTOS_H_
#define ARRAYPRODUCTOS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"

#define IPHONE 1
#define MAC 2
#define IPAD 3
#define ACCESORIOS 4
#define EEUU 1
#define CHINA 2
#define OTRO 3
#define CANT_PRODUCTOS 10

struct{
    int id;
    char descripcion[51];
    int nacionalidad;
    int tipo;
    float precio;
    int isEmpty;
} typedef productosApple;

/// @brief para indicar que todas las posiciones en la matriz estan vacias, est funcion coloca la bandera (isEmpty)*en verdadero*
/// en todas las posiciones de la matriz
///
/// @param list* productosApple Puntero a una matriz de pasajeros
/// @param len longitud del arreglo
/// @return int devuelve -1 si hay error (len no valida o puntero NULL) y 0 si esta bien
int initProductosApple(productosApple *list,int len);
/// @brief Encuentra un indice libre en la matriz de productos
///
/// @param list productosApple*
/// @param len longitud int
/// @return devuelve -1 si hay un error (len no vlida o puntero NULL o si no se puede encontrar un producto, indice libre si esta ok
int findFreeIndex(productosApple *list,int len);
/// @brief genera un id autoincremental
///
/// @return retorna el numero del id
int productosId(void);
/// @brief agrega en una lista existente lo productos los valores recibidos como parametros (en la primera posicion vacia)
///
/// @param list lista de productos
/// @param len int
/// @param id int
/// @param descripcion char[]
/// @param nacionalidad int
/// @param tipo int
/// @param precio float
/// @return devuelve menos - 1 si hay error (len no valida o puntero NULL o sin espacio libre)  0 si esta bien
int addProducts(productosApple *list,int len, int id,char descripcion[],int nacionalidad, int tipo,float precio);
/// @brief find a Product By Id devuelve la posicion del indice en la matriz
///
/// @param list *productosApple
/// @param len int
/// @param id int
/// @return Posicion de indice de producto de retorno -1 si longitud no es valida o puntero NULL recibido o producto no encontrado
int findProductById(productosApple *list, int len, int id);
/// @brief verifica si hay almenos un producto cargado en el array de productos
///
/// @param list productosApple*
/// @param len longitud int
/// @return retorna -1 si tiene eerror o no puede encontrar un producto, retorna 1 si hay al menos uno
int thereIsProduct(productosApple *list, int len);
/// @brief Eliminar un producto por id ( colocar el indicador isEmpty en 1)
///
/// @param list productosApple*
/// @param len int
/// @param id int
/// @return devuelve -1 si hay error (len no valida o puntero NULL o si no se puede encontrar un producto) y 0 si esta ok
int removeProducts(productosApple *list, int len, int id, char * descripcionAnterior);
/// @brief funcion que modifica un campo del producto indicando por el usuario. En caso d modificar el estado
///
/// @param list
/// @param len
/// @param id
/// @param descripcion
/// @param precio
/// @param modificoProducto
/// @return
int modifyProduct(productosApple *list, int len, int id, char descripcion[], float *precio, int *modificoProducto);
int listadoDeProductos(productosApple *list, int lenght);

#endif /* ARRAYPRODUCTOS_H_ */
