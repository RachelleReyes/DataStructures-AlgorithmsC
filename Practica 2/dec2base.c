//dec2base.c
#include "dec2base.h"
#include <stdio.h>

/*Las funciones dec2bin, dec2oct, y dec2hex fueron elaboradas por Reyes Udasco Rachelle Nerie
Estas funciones convierte al número decimal a binario, hexadecimal y octal respectivamente*/


void dec2binchar (int value, char* binchar, int size)
{
    //Basado en la solucion de su companero
    //Ricardo Castañon Renteria
    int cociente, residuo, i;
    cociente=value;

    //Comentar por que esta instruccion es utlizada
    /*Se usa para terminar el string, se usa como caracter nulo*/
    binchar[size] = '\0';

    //Comentar en que sentido se asignan variables al arreglo
    /*Asigna el valor de cero a cada uno de los valores del arreglo*/

    //Comentar por que es necesario este proceso
    /*Es necesario porque cada lugar en el arreglo tendrá que estar ocupada por un caracter
    de otra forma este regresaría un valor aleatorio al momento de imprimirlo*/

    //Investigar funcionamiento de la funcion memset y como se podria implementar
    /*La biblioteca de C función void * memset (void * str, int c, size_t n) copia el carácter c
    (unsigned char) para los n primeros caracteres de la cadena apuntada por el argumento str.
    Se podría implementar para iniciar o llenar un arreglo o cadena de caracteres
    con un caracter específico.*/

    for(i=0; i<size; i++)
    {
        binchar[i]='0';
    }
    i=1;

    //Comentar en que sentido se le asignan valores al arreglo y por que
    /*Asigna el valor '1' a cada uno de los valores en donde hay residuo porque
    es la forma para convertirlo a binario*/

    while(cociente!=0)
    {
        residuo=cociente%2;
        cociente= cociente/2;
        //por que solo se encuentra la variable residuo en la condicion
        /*Porque es viable hacerlo al momento de comparar si una variable esta vacía o no*/
        if(residuo)
        {
            binchar[size-i]='1';

        }
        i++;
    }
}

//Función que convierte a un numero decimal a binario
void dec2bin(int value, int* bin, int size)
{
    //Declaración de variables
    int cociente, residuo, contador;
    cociente=value;

    //binchar[size] = '\0';

    for(contador=0; contador<size; contador++)   //Ciclo que coloca 0 a todos los elementos del arreglo
    {
        bin[contador]=0;
    }
    contador=1;

    //Ciclo que coloca 1 los lugares del arreglo si hay residuo,termina la condición cuando el cociente es 0
    while(cociente!=0)
    {
        residuo=cociente%2;  //Saca el residuo de la división del cociente entre 2
        cociente= cociente/2; //Coloca la división del cociente entre 2 en la variable cociente
        if(residuo) //Comparación si hay residuo para colocar los 1
        {
            bin[size-contador]=1;
        }
        contador++;
    }
}

//Función que convierte a un numero decimal en hexadecimal
void dec2hex(int value, char* hex, int size)
{
    //Declaración de variables
     int cociente, residuo, contador;
     //Variable que guarda los valores para el hexadecimal
     char hexadec[16]= {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    cociente=value;

    hex[size] = '\0';  //Coloca un valor nulo al final de la cadena de caracteres

    for(contador=0; contador<size; contador++)  //Ciclo que coloca 0 a todos los elementos del arreglo
    {
        hex[contador]='0';
    }
    contador=1;

    //Ciclo que coloca los valores hexadecimales a sus respectivos lugares
    //Termina cuando el cociente es cero
    while(cociente!=0)
    {
        residuo=cociente%16;//Saca el residuo de la división del cociente entre 16
        cociente= cociente/16;
        if(residuo)
        {
            hex[size-contador]=hexadec[residuo]; //Coloca el valor hexadecimal en la cadena hex
        }
        contador++;
    }
}

//Función que convierte a un numero decimal en hexadecimal
void dec2oct(int value, int* oct, int size)
{
    //Declaración de variables
    int cociente, residuo, contador;
    cociente=value;

    for(contador=0; contador<size; contador++) //Ciclo que coloca 0 a todos los elementos del arreglo
    {
        oct[contador]=0;
    }
    contador=1;

    //Ciclo que coloca los residuos a sus respectivos lugares, termina cuando el cociente es 0
    while(cociente!=0)
    {
        residuo=cociente%8;
        cociente= cociente/8;
        if(residuo)
        {
            oct[size-contador]=residuo; //Coloca el valor hexadecimal en la cadena oct
        }
        contador++;
    }
}
