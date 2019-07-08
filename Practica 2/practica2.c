/*practica2 Programacion Estructurada*/

/* Las funciones en el archivo dec2base.c fueron elaboradas por Reyes Udasco Rachelle Nerie
Práctica 2: Este programa tiene como objetivo convertir el numero decimal a
binario, hexadecimal u octal de acuerdo a lo que el usuario desee*/

#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include"dec2base.h"

//Indicar que hace define
/*Asigna el valor 10 a MAX, esta tendrá un valor constante 10*/
#define MAX 10

void detener_pantalla(char* mensaje);
void informacion_err();

int main(int argc, char* argv[])
{
    //Declaración de variables a utilizar
    int num = 0,i=0,imprime=0;
    //Indicar por qué se declara en el main la cadena a mostrar
    /*Porque dicha variable se usara en la función main, y debería
    ser declarada con la cantidad de elementos que podría tener*/

    char binchar[MAX];
    //int bin[MAX];
    char hex[MAX];
    int oct[MAX];

    //Comprobacion de numero de parametros ingresados por consola
    if(argc<3)
    {
        //Por defecto el programa recibe un argumento, el nombre del archivo (ej. practica2.c).
        informacion_err();
        detener_pantalla("\n\tPresione ENTER para salir");
        return 1;
    }
    else
    {
        num = atoi(argv[2]);
        //Comparación si el usuario desea convertir a binario
        if(strcmp("bin", argv[1])==0)
        {
          //Indicar de que forma se envia el arreglo binchar y por que?
          /*Se envía como un parámetro de la función dec2binchar porque es una
          de las formas en las que se podrían mandar arreglos*/
          dec2binchar(num, binchar, MAX);
          printf("\nEl numero: %d, en binario es: ",num);

            while(i<10) //Ciclo que imprime los numeros quitando los ceros al principio
            {
                if(imprime==0 && binchar[i]!='0'){ imprime=1; }
                if(imprime==1){ printf("%c", binchar[i]);}
                i++;
            }
          /*
           Si se usa la segunda función para convertir a binario
           dec2bin(num, bin, MAX);
           printf("\nEl numero: %d, en binario es: ",num);
           while(i<10) //Ciclo que imprime los numeros quitando los ceros al principio
            {
                if(imprime==0 && binchar[i]!=0){ imprime=1; }
                if(imprime==1){ printf("%d", binchar[i]);}
                i++;
            }
           */
        }

        //Comparación si el usuario desea convertir a hexadecimal
        else if(strcmp("hex", argv[1])==0)
        {
            dec2hex(num, hex, MAX);
            printf("\nEl numero: %d, en hexadecimal es: " ,num);

            while(i<10) //Ciclo que imprime los numeros
            {
                if(imprime==0 && hex[i]!='0'){ imprime=1; }
                if(imprime==1){ printf("%c", hex[i]);}
                i++;
            }
        }

        //Comparación si el usuario desea convertir a octal
        else if(strcmp("oct", argv[1])==0)
        {
            dec2oct(num, oct, MAX);
            //printf("\nEl numero: %d, en octal es: %d",num,oct);
            printf("\nEl numero: %d, en octal es: ",num);
            i=0;
            while(i<10) //Ciclo que imprime los numeros sin los ceros al principio
            {
                if(imprime==0 && oct[i]!=0){ imprime=1; }
                if(imprime==1){ printf("%d", oct[i]);}
                i++;
            }
        }
        else
        {
            informacion_err();
            detener_pantalla("\n\tPresione ENTER para salir");
            return 1;
        }
    }

    detener_pantalla("\n\tPresione ENTER para salir");
    return 0;
}

void detener_pantalla (char* mensaje)
{
    printf("\n%s\n", mensaje);
    setbuf(stdin, NULL);
    getchar();
}

void informacion_err()
{
    printf("El programa debe recibir dos parametros");
    printf("\n   [1] Base a convertir el valor entero: \"bin\", \"hex\", \"oct\"");
    printf("\n   [2] Valor entero decimal");
    printf("\n\nEjemplo:\nprac2.exe bin 5");
}

