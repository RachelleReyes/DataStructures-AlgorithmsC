/*practica3 Programacion Estructurada*/

/* 
Elaborado por Reyes Udasco Rachelle Nerie
Práctica 3: Este programa tiene como objetivo realizar las tareas segun la opcion que elija el usuario:, 
a. Imprimir el numero en reverso = "reversa"
b. Contar los digitos de un numero = "digitos"
c. Sumar los digitos de los numeros "suma"
d. Verificar si un numero es perfecto, sumando sus divisores y comprobando si la suma es igual al numero "perfecto"
e. Comparar si dos numeros son amigos,si la suma de los divisores del primer numero es igual al segundo numero y viceversa "amigos"
*/

#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include"opciones.h"

void detener_pantalla(char* mensaje);
void informacion_err();

int main(int opcion, char* argv[])
{
    //Declaracion de variables a utilizar
    int num = 0; //La variable que se utiliza para el numero del tercer parametro
	int num2 = 0; //La variable que se utiliza para el numero del cuarto parametro

    //Comprobacion de numero de parametros ingresados por consola
    if(opcion<3)
    {
        //Por defecto el programa recibe un argumento, el nombre del archivo (ej. practica3.c).
        informacion_err();
        detener_pantalla("\n\tPresione ENTER para salir");
        return 1;
    }
    else
    {
        num = atoi(argv[2]); //Asignacion del tercer parametro al variable num
		num2 = atoi(argv[3]); //Asignacion del cuarto parametro al variable num
		
		//Comparacion de la opcion para imprimir el resultado de la tarea elegida
        if(strcmp("reversa", argv[1])==0) 
        {
		  //Impresion del reversa del numero dado por el usuario
          printf("\nEl numero: %d, al reves es: %d",num,reversa(num));
		}
        else if(strcmp("digitos", argv[1])==0)
        {
		  //Impresion del numero de digitos que contenga el numero
          printf("\El numero: %d, tiene %d digitos",num,digitos(num));
        }
        else if(strcmp("suma", argv[1])==0)
        {
		  //Impresion de la suma de numero de digitos que contenga el numero
          printf("\nLa suma de los digitos del numero: %d, es: %d",num,suma(num));
        }
		  else if(strcmp("perfecto", argv[1])==0)
        {
			/*Comparacion de la variable mandada por la funcion perfecto, si el valor es uno 
			imprime que si es perfecto, si no, imprime que no son amigos*/
          if (perfecto(num)==1) {printf("\nEl numero: %d, si es perfecto",num);}
		  else {printf("\nEl numero: %d, no es perfecto",num);}
        }
        else if(strcmp("amigos", argv[1])==0)
        {
		  /*Comparacion de la variable mandada por la funcion amigos, si el 
		  valor es uno imprime que si son amigos si no imprime que no son amigos*/
          if (amigos(num,num2)==1) {printf("\nLos numeros: %d, y %d son amigos",num,num2);}
		  else {printf("\nLos numeros: %d, y %d no son amigos", num,num2);}
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
    printf("El programa debe recibir dos parametros(tres, en caso de la opcion amigos)");
	printf("\n   [1] La tarea que se desea realizar con el numero: \"reversa\", \"digitos\", \"suma\", \"perfecto\", \"amigos\"");
    printf("\n   [2] Valor entero"); 
    printf("\n\nEjemplo:\npractica3.exe reversa 531");
}

