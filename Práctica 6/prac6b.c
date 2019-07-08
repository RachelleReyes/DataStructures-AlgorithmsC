//Practica 6: Apuntadores (segundo inciso)
//Elaborado por Reyes Udasco Rachelle Nerie
//Objetivo: Intercambiar valores de dos cadenas con apuntadores

#include<stdio.h>

//Prototipos de las funciones
void swap_strings(char** p1, char** p2);
void imprimir(char* s1,char *s2);

int main()
{
    //Declaracion y asignacion de las variables;
    char *s1 = "Esta es la primera cadena";
    char *s2 = "Esta es la segunda cadena";

    //Impresion del contenido original de las variables
    printf("Cadena original: ");
    imprimir(s1,s2);

    //Llamada de la funcion para intercambiar el contenido
    swap_strings(&s1,&s2);

    //Impresion del contenido intercambiado de las variables
    printf("\n\nCadena despues del swap: ");
    imprimir(s1,s2);

    return 0;
}

//Funcion que intercambia el contenido de las dos cadenas
void swap_strings(char** p1, char** p2)
{
    char *p ;

    p = *p1;
    *p1 = *p2;
    *p2 = p;
}

//Funcion que imprime los contenidos
void imprimir(char* s1,char *s2)
{
    printf("\n string 1: %s",s1);
    printf("\n string 2: %s\n",s2);
}
