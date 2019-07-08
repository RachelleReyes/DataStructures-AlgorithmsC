//Practica 6: Apuntadores (primer inciso)
//Elaborado por Reyes Udasco Rachelle Nerie
//Objetivo: Intercambiar valores de dos variables enteras con apuntadores

#include<stdio.h>

//Prototipos de las funciones
void swap(int *n1, int *n2);
void impresion(int a, int b);

int main()
{
    //Declaracion de variables
    int a, b;

    //Asignacion de valores a los variables
    a=11;
    b=22;

    //Impresion de los valores originales
    printf("Valor originales: ");
    impresion(a,b);

    //Llamada de la funcion swap
    swap(&a,&b);

    //Impresion de los nuevos valores
    printf("\n\nValor despues del swap: ");
    impresion(a,b);
    return 0;
}

//Funcion que intercambia el valor de las variables
void swap(int *p1, int *p2)
{
    int p;

    p = *p1;
    *p1 = *p2;
    *p2 = p;
}

//Funcion que imprime los valores
void impresion(int a, int b)
{
    printf("\n a: %d",a);
    printf("\n b: %d\n",b);
}
