/*
 ============================================================================
 Name        : ejercicio7-1.c
 Author      : Agustin
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style

idProducto (numerico)
descripcion (alfanumérico)
nacionalidad (numérico, por el momento utilizaremos un define: 1-EEUU.\n 2-CHINA.\n 3-OTRO.\n)
tipo (numérico, por el momento utilizaremos un define: IPHONE -MAC - IPAD - ACCESORIOS)
precio (numérico decimal)

Realizar un programa que permita interactuar con un menú de usuarios con las siguientes opciones:
ALTA Producto: Se ingresan los datos de UN solo producto. Siempre y cuando haya espacio disponible en el array.
BAJA Producto: A partir del ingreso del ID. Si existe el producto desaparece de la lista, dejando espacio disponible para un nuevo producto.
MODIFICACIÓN Producto: A partir del ingreso del ID. Si existe se podrá modificar el precio o el tipo.
LISTADO Productos.
LISTADO ordenado por precio.
LISTADO ordenado por descripción.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "arrayProductos.h"

int sortProductsByPrice(productosApple *list, int len, int order);
int sortProductByDescription(productosApple *list, int len, int order);

int main(void) {
	setbuf(stdout, NULL);
	int opcionMenuPrincipal;
	int opcionSubmenu;
	char descripcionAux[51];
	char descripcionAuxModify[51];
	char descripcionAuxAnterior[51];
	int tipoAux;
	int idAux = 0;
	int nacionalidadAux;
	float precioAux;
	float precioAuxModify;
	int productoModify;
	int orderAux;

	productosApple producto[CANT_PRODUCTOS];
	initProductosApple(producto,CANT_PRODUCTOS);

	do{
		if(utn_getInt(&opcionMenuPrincipal,"\tBienvenido al sistema.\n¿Que desea hacer?\n\n1-Alta de productos.\n\n2-Modificacion de productos.\n\n3-Baja de un producto.\n\n4-Informes.\n\n5-Carga forzada de productos.\n\n6-Cerrar programa.\n\n","Ingrese una opcion valida.",1,6,2) == 0){
			switch(opcionMenuPrincipal){
			case 1:
				if(findFreeIndex(producto,CANT_PRODUCTOS) != -1){
					if(getString(descripcionAux,"Introduzca la descripcion del producto:\n","La descripcion no pudo ser validada.\n",2)==0 && utn_getInt(&nacionalidadAux,"Ingrese la nacionalidad del producto:\n\n1-EEUU.\n\n2-CHINA.\n\n3-OTRO.\n","Ingrese una opcion valida",1,3,2)==0 && utn_getInt(&tipoAux,"Ingrese el tipo de producto:\n1-IPHONE.\n\n2-MAC.\n\n3-IPAD.\n\n4-ACCESORIOS.","Ingrese una opcion valida",1,4,2)==0 && utn_getFloat(&precioAux,"Ingrese el precio del producto:\n","\nEl valor es incorrecto, ingreselo nuevamente\n",1000,1000000,2)==0){
						if(addProducts(producto,CANT_PRODUCTOS,idAux,descripcionAux,nacionalidadAux,tipoAux,precioAux)==0){

						}else{
							mensajeGenerico("Error en la carga del producto, volviendo al menu principal...\n");
						}
					}else{
						mensajeGenerico("\nError en la carga del producto, volviendo al menu principal...\n");
					}
				}else{
					mensajeGenerico("No hay espacio disponible para agregar productos.\n");
				}
				break;
			case 2:
				if(thereIsProduct(producto, CANT_PRODUCTOS)==1){
					if(utn_getInt(&idAux,"Ingrese el id del producto que desea eliminar","Indique un numero valido",0,16000, 2)== 0){
						removeProducts(producto, CANT_PRODUCTOS,idAux,descripcionAuxAnterior);
					}
				}
				break;
			case 3:
				if(thereIsProduct(producto, CANT_PRODUCTOS)==1){
					if(utn_getInt(&idAux,"Ingrese el id del pasajero que desea modificar:\n","Por favor, ingrese una id valida.",1000,70000,2) == 0){
						if(modifyProduct(producto, CANT_PRODUCTOS, idAux,descripcionAuxModify,&precioAuxModify,&productoModify) ==0){

						}
					}
				}else{
					printf("Aun no cargo ningun producto.\n");
				}
				break;
			case 4:
				if(thereIsProduct(producto, CANT_PRODUCTOS)==1){
					if(utn_getInt(&opcionSubmenu,"¿De que manera quiere ver el listado?\n1-Ordenado por precio.\n2-Ordenado por descripcion.\n3-Listado total de los productos.\n4-Volver al menu principal","Indique una opcion valida:\n",1, 4, 2) == 0){
						switch(opcionSubmenu){
						case 1:
							if(utn_getInt(&orderAux,"Indique 0 para descendente o 1 para ascendente.","Indique una opcion valida:\n",0, 1, 2)==0){
								if(sortProductsByPrice(producto,CANT_PRODUCTOS,orderAux)==0){
									listadoDeProductos(producto,CANT_PRODUCTOS);
									mensajeGenerico("Presione cualquier tecla para continuar.");
									fflush(stdin);
									getchar();
								}else{
									mensajeGenerico("El ordenamiento tuvo un error.\n");
								}
							}
							break;
						case 2:
							if(utn_getInt(&orderAux,"Indique 0 para descende o 1 para ascendente.","Indique una opcion valida:\n",0, 1, 2) == 0){
								if(sortProductByDescription(producto,CANT_PRODUCTOS,orderAux)==0){
									listadoDeProductos(producto,CANT_PRODUCTOS);
									mensajeGenerico("Presione cualquier tecla para continuar.");
									fflush(stdin);
									getchar();
								}else{
									mensajeGenerico("El ordenamiento tuvo un error.\n");
								}
							}
							break;
						}
					}
				}
//				listadoDeProductos(producto, CANT_PRODUCTOS);
//				sortProductsByPrice(producto, CANT_PRODUCTOS,orderAux);
				break;
			case 5:
				break;

			}
		}
	}while(opcionMenuPrincipal != 6);

	return EXIT_SUCCESS;
}

int sortProductsByPrice(productosApple *list, int len, int order){
	int retorno;
	int i;
	int estaOrdenado;

	productosApple aux;

	if(list != NULL && len > 0){
		if(order == 0){
			do{
				estaOrdenado = 1;
				len--;
				for(i = 0; i < len; i++){
					if(list[i].precio < list[i + 1].precio){
						aux = list[i];
						list[i] = list[i + 1];
						list[i + 1] = aux;
						estaOrdenado = 0;
					}else if(list[i].precio > list[i + 1].precio){
						aux = list[i];
						list[i] = list[i + 1];
						list[i + 1] = aux;
						estaOrdenado = 0;
					}
				}
			}while(estaOrdenado == 0);
		}else if(order == 1){
			do{
				estaOrdenado = 1;
				len--;
				for(i = 0; i < len; i++){
					if(list[i].precio > list[i + 1].precio){
						aux = list[i];
						list[i] = list[i + 1];
						list[i + 1] = aux;
						estaOrdenado = 0;
					}else if(list[i].precio < list[i + 1].precio){
						aux = list[i];
						list[i] = list[i + 1];
						list[i + 1] = aux;
						estaOrdenado = 0;
					}
				}
			}while(estaOrdenado == 0);
		}
		retorno = 0;
	}
	return retorno;
}

int sortProductByDescription(productosApple *list, int len, int order){
	int retorno;
	int i;
	int estaOrdenado;

	productosApple aux;

	if(list != NULL && len > 0){
		if(order == 0){
			do{
				estaOrdenado = 1;
				len--;
				for(i = 0; i < len; i++){
					if(stricmp(list[i].descripcion, list[i + 1].descripcion) < 0){
						aux = list[i];
						list[i] = list[i + 1];
						list[i + 1] = aux;
						estaOrdenado = 0;
					}
				}
			}while(estaOrdenado == 0);
			retorno = 0;
		}else if(order == 1){
			do{
				estaOrdenado = 1;
				len--;
				for(i = 0; i < len; i++){
					if(stricmp(list[i].descripcion, list[i + 1].descripcion) > 0){
						aux = list[i];
						list[i] = list[i + 1];
						list[i + 1] = aux;
						estaOrdenado = 0;
					}
				}
			}while(estaOrdenado == 0);
		}
		retorno = 0;
	}
	return retorno;
}
