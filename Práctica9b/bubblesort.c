//bubblesort.c

/* Práctica 9: Elaborado por Reyes Udasco Rachelle Nerie*/

#include "bubblesort.h"
#include <stdio.h>

//Funcion que ordena los datos de acuerdo al campo que desea el usuario
void bubbleSort(void** array, int n, int(*cmp)(const void**, const void**))
{
    int i,j;
    for(i=0; i<n-1;i++)
    {
        for(j=i+1; j<n;j++)
        {
            //Multiplica la direccion por el tamaño del dato
            if(cmp((const void**)(array+i),(const void**)(array+j))>0)
            swap(array+i,array+j);
        }
    }
}

//Funcion que intercambia la direccion de cada registro
void swap(void **a, void **b)
{
    unsigned char *aux;

	aux = *(unsigned char**)(a);
	*(unsigned char**)(a) = *(unsigned char**)(b);
	*(unsigned char**)(b) = aux;
}
