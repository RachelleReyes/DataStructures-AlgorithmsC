/*Practica 4: Arreglos unidimensionales y bidimensionales

Elaborado por: Reyes Udasco Rachelle Nerie
Objetivo: Este programa tiene como objetivo manipular una lista formado 
por las calificaciones de las practicas de cada alumno

//Este archivo es el principal
*/
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include"calificaciones.h"

 /*Prototipo de funciones*/
 void detener_pantalla(char* mensaje);
 void instruccion();
 void generanumeros(int M[ALUM][PRAC],int row, int col);
 void ordenar(int M[][PRAC],int row, int col);
 float obtenermedia(int M[ALUM][PRAC],int row, int col);
 float obtenermediana(int M[][PRAC], int row, int col);
 void imprimir(int M[ALUM][PRAC],int row, int col);
 void calalumno(int M[ALUM][PRAC], int row, int col, int alumno);
 void calpractica(int M[ALUM][PRAC], int row, int col, int practica);
 
int main(int argc, char* argv[])
{
    //Declaracion de variables a utilizar
	int M[ALUM][PRAC],moda, num,opcion;
	float media, mediana;
	//Genera numeros aleatorios para colocarlos en la lista 
	generanumeros(M,ALUM, PRAC);
	
	//Compara si el usuario ingreso menor de dos elementos
	if(argc<2)
    {
        instruccion();
        detener_pantalla("\n\tPresione ENTER para salir");
    }
	else 
	{
		//Conversion de los argumentos dados por el usuario
		opcion = atoi(argv[1]);
		if(opcion==2 || opcion==3) {num = atoi(argv[2]);}
		
		//Compara la opcion que ingreso el usuario
		switch(opcion)
		{	
			case 1: //Imprime la lista de calificaciones
					imprimir(M,ALUM,PRAC); break;
			
			case 2: //Imprime las calificaciones del numero de usuario dado por el usuario
					if (num>0){calalumno(M,ALUM,PRAC,num);}
					else instruccion();
			break;
			
			case 3: //Imprime las calificaciones del numero de practica dado por el usuario
					if (num>0){calpractica(M,ALUM,PRAC,num);}
					else instruccion();
			break;
			
			case 4: 
					//Ordena, imprime y saca la media, moda y mediana.
				   ordenar(M,ALUM,PRAC);
				   imprimir(M,ALUM,PRAC);
				   media =  obtenermedia(M, ALUM, PRAC);
				   printf("\n\n La media es: %.3f", media);
				   
				   moda =  obtenermoda(M, ALUM, PRAC);
				   printf("\n La moda es: %d", moda);
				   
				   mediana =  obtenermediana(M, ALUM, PRAC);
				   printf("\n La mediana es: %.1f", mediana);
				  
			break;
			default: 
					instruccion();
					detener_pantalla("\n\tPresione ENTER para salir");
			break;
		}
	}
	detener_pantalla("\n\tPresione ENTER para salir");
	return 0;
}
//Funcion para detener la pantalla
void detener_pantalla (char* mensaje)
{
    printf("\n%s\n", mensaje);
    setbuf(stdin, NULL);
    getchar();
}

//Instrucciones para el usuario
void instruccion()
{
    printf("\nEscribe el numero de la opcion que deseas realizar");
	printf("\nEn caso de ser la opcion 2 y 3, ingrese el numero del alumno o la practica");
    printf("\n   [1] Mostrar tabla de calificaciones");
	printf("\n   [2] Mostrar calificaciones de un alumno");
	printf("\n   [3] Mostrar calificaciones de una practica");
	printf("\n   [4] Mostrar moda, mediana y media de calificaciones");
    printf("\n\nEjemplo:\nprac4.exe 2 2 ");
	printf("\nRecomendacion: Maximizar la pantalla para ver la tabla mejor");
}

