/*
 ============================================================================
 Name        : ejercicio2.c
 Author      : Agustin
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    setbuf(stdout, NULL);
    int numero;
    int i;
    int numeroMayor;
    int numeroMenor;
    int flag = 0;

    for(i = 0; i < 5; i++){
        printf("Ingrese un numero:");
        scanf("%d", &numero);

        if(flag == 0 || numero < numeroMenor){
            numeroMenor = numero;
        }if(flag == 0 || numero > numeroMayor){
            flag = 1;
            numeroMayor = numero;
        }
    }

    printf("El numero mayor es %d, El numero menor es %d.", numeroMayor, numeroMenor);

    return 0;
}
