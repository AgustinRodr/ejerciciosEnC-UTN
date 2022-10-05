/*
 * arrayProductos.c
 *
 *  Created on: 27 sep. 2022
 *      Author: invitadopc
 */

#include "arrayProductos.h"

int initProductosApple(productosApple *list,int len){
    int retorno;
    retorno = -1;
    if(list != NULL && len > 0){
        for(int i = 0; i < len; i++){
        	list[i].isEmpty = 1;
        }
        retorno = 0;
    }
    return retorno;
}

int findProductById(productosApple *list, int len, int id){
    int retorno;
    retorno = -1;
    if(list != NULL && len > 0 && id > 0){
        for(int i = 0; i < len; i++){
            if(list[i].id == id && list[i].isEmpty == 0){
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int findFreeIndex(productosApple *list,int len){
    int retorno;
    retorno = -1;
    if(list != NULL && len > 0){
        for(int i = 0; i < len; i++){
            if(list[i].isEmpty == 1){
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int productosId(void){
    static int id = 999;
    id++;
    return id;
}

int addProducts(productosApple *list,int len, int id,char descripcion[],int nacionalidad, int tipo,float precio){
    int retorno;
    int pudoAsignar;
    int indiceVacio;

    retorno = -1;
    pudoAsignar = 0;

    if(list != NULL && len > 0 && descripcion != NULL && nacionalidad > 0 &&
        tipo > 0 && precio > 0){
    	indiceVacio = findFreeIndex(list, len);
        if(indiceVacio != -1){
        	list[indiceVacio].isEmpty = 0;
        	strcpy(list[indiceVacio].descripcion, descripcion);
            list[indiceVacio].id = productosId();
            list[indiceVacio].nacionalidad = nacionalidad;
            list[indiceVacio].tipo = tipo;
            list[indiceVacio].precio = precio;
            pudoAsignar = 1;

           }
        }

      if(pudoAsignar == 1){
            printf("\nProducto cargado correctamente.\n");
            retorno = 0;
        }
        return retorno;
}

int thereIsProduct(productosApple *list, int len){
	int retorno;
	int i;
	i = 0;
	retorno = 0;
	if(list != NULL && len > 0){
		for(i = 0; i < len; i++){
			if(list[i].isEmpty == 0){
				retorno = 1;
				break;
			}
		}
	}
	return retorno;
}

int removeProducts(productosApple *list, int len, int id, char * descripcionAnterior){
    int retorno;
    int indiceAEliminar;
    retorno = -1;
    if(list != NULL && len > 0 && id > 0){
    	indiceAEliminar = findProductById(list,len, id);
        if(indiceAEliminar != -1){
        	strcpy(descripcionAnterior, list[indiceAEliminar].descripcion);
            list[indiceAEliminar].isEmpty = 1;
            retorno = 0;
            printf("Producto eliminado con exito.\n");
        }else{
            printf("El ID no coincide con ningun producto cargado.\n");
        }
    }
    return retorno;
}

int modifyProduct(productosApple *list, int len, int id, char descripcion[], float *precio, int *modificoProducto){
    int retorno = -1;
    int indiceAModificar;
    int opcion;

    char descripcionAux[51];
    int nacionalidadAux;
    int tipoAux;
    float precioAux;

    if(list != NULL && len > 0 && id > 0){
        indiceAModificar = findProductById(list, len, id);
        if(indiceAModificar != -1){
            do{
                if(utn_getInt(&opcion,"¿Que desea modificar?\n\n1)Descripcion.\n\n2)Nacionalidad.\n\n3)Tipo.\n\n4)Precio.\n\n5)Volver al menu principal.","Ingrese una opcion valida.\n",1,5,2) == 0){
                    switch(opcion){
                    case 1:
                           if(getString(descripcionAux,"Introduzca la nueva descripcion del producto:\n","La descripcion no pudo ser validada, ingreselo nuevamente:\n",2)==0){
                        	   strcpy(list[indiceAModificar].descripcion, descripcionAux);
                        	   strncpy(list[indiceAModificar].descripcion, descripcionAux,sizeof(list[indiceAModificar].descripcion));
                               retorno = 0;
                               *modificoProducto = 0;
                               printf("Descripcion actualizada.\n");
                           }else{
                               printf("Fallo la modificacion.\n");
                           }
                           break;
                    case 2:
                           if(utn_getInt(&nacionalidadAux,"Ingrese la nueva nacionalidad del producto:\n1-EEUU.\n2-CHINA.\n3-OTRO.","Ingrese una opcion valida.\n", 1,3,2)==0){
                               retorno = 0;
                               list[indiceAModificar].nacionalidad = nacionalidadAux;
                               printf("Nacionalidad actualizada.\n");
                               *modificoProducto = 0;
                           }else{
                               printf("Fallo la modificacion.\n");
                           }
                           break;
                    case 3:
                           if(utn_getInt(&tipoAux,"Ingrese el nuevo tipo del producto:\n1-IPHONE.\n2-MAC.\n3-IPAD.\n4-ACCESORIOS.","Ingrese una opcion valida.\n",1,4,2)==0){
                               retorno = 0;
                               list[indiceAModificar].tipo = tipoAux;
                               printf("Tipo de producto actualizado.\n");
                               *modificoProducto = 0;
                           }else{
                               printf("Fallo la modificacion.\n");
                           }
                           break;
                    case 4:
                           if(utn_getFloat(&precioAux,"Ingrese el nuevo precio del producto:","El valor es incorrecto, ingreselo nuevamente:\n",10000,1000000,2)==0){
                               list[indiceAModificar].precio = precioAux;
                               printf("Precio actualizado.\n");
                               retorno = 0;
                               *modificoProducto = 0;
                           }else{
                               printf("Fallo la modificacion.\n");
                           }
                           break;
                    case 5:
                           printf("Volviendo al menu principal...\n\n");
                           break;
                    }
                }
            }while(opcion != 5);
        }else{
            printf("El ID no pertenece a ningun producto cargado.\n");
        }
    }
    return retorno;
}

int listadoDeProductos(productosApple *list, int lenght){
    char tipoProductoAux[16];
    if(list !=  NULL && lenght > 0){
        printf("\nDESCRIPCION      NACIONALIDAD           TIPO           PRECIO          ID");
        for(int i = 0; i < lenght; i++){
             switch(list[i].tipo){
             case IPHONE:
            	 	 	strcpy(tipoProductoAux,"IPHONE");
                 break;
             case MAC:
                        strcpy(tipoProductoAux,"MAC");
                 break;
             case IPAD:
                        strcpy(tipoProductoAux,"IPAD");
                 break;
             case ACCESORIOS:
                        strcpy(tipoProductoAux,"ACCESORIOS");
                 break;
                }
                if(list[i].isEmpty == 0){
                  printf("\n\n%-15s\t\t%d\t\t%-15s$%-9.2f    \t%-5i\n",list[i].descripcion, list[i].nacionalidad, tipoProductoAux, list[i].precio, list[i].id);
              }
           }
        }
    return 0;
}
