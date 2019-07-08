//bubblesort.c

/* Práctica 9: Elaborado por Reyes Udasco Rachelle Nerie*/

#include "bubblesort.h"
#include <stdio.h>

//Funcion que ordena los datos de acuerdo al campo que desea el usuario
void bubbleSort(void* array, int n, int size,int(*cmp)(const void*, const void*))
{
    int i,j;
    for(i=0; i<n-1;i++)
    {
        for(j=i+1; j<n;j++)
        {
            //Multiplica la direccion por el tamaño del dato
            if(cmp((array+i*size),(array+j*size))>0)
            swap(array+i*size,array+j*size,size);
        }
    }
}

//Funcion que intercambia la direccion de cada registro
void swap(void *a, void *b,unsigned int size)
{
    int i;
    unsigned char aux;

    for(i=0;i<size;i++)
    {
        aux = *(unsigned char*)(a+i);
        *(unsigned char*)(a+i) = *(unsigned char*)(b+i);
        *(unsigned char*)(b+i)=aux;
    }
}
