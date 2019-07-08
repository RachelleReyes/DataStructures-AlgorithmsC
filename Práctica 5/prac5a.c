/*Practica 5 Estructura de datos

Elaborado por: Reyes Udasco Rachelle Nerie
Objetivo: Este programa tiene como objetivo manipular una lista formado 
por las calificaciones de las practicas de cada alumno usando datos del 
alumno asi como de de las practicas
//Archivo principal
*/
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include"calificaciones.h"

//DEFINICION DE ESTRUCTURAS EN .H

 /*Prototipo de funciones*/
 void instruccion();
 void generanumeros(int M[ALUM][PRAC],int row, int col);
 
 
 void imprimir(int M[ALUM][PRAC],int row, int col);
 void calalumno(int M[ALUM][PRAC], int row, int col, int alumno);
 void calpractica(int M[ALUM][PRAC], int row, int col, int practica);
 
int main(int argc, char* argv[])
{
    //Declaracion de variables a utilizar
	int M[ALUM][PRAC];
	//float media, mediana;
	int opcion, alumno;
	
	//Genera numeros aleatorios para colocarlos en la lista 
	generanumeros(M,ALUM, PRAC);
	
	do
	{
		instrucccion();
		printf("\nEscribe el numero de la opcion que deseas realizar");
		scanf("%d",opcion);
		
		if(opcion==2 ||opcion==3)
		{
			printf("\nIngrese el ID del alumno");
			scanf("%d",alumno);
		}
	
			//Compara la opcion que ingreso el usuario
		switch(opcion)
		{	
			case 1: //Imprime la lista de calificaciones
					imprimir(M,ALUM,PRAC); break;
			
			case 2: break;
			
			case 3: break;
			
			case 4: break;
			
			default: 
					instruccion();
			break;
		}
	}while(opcion!=5);
	
}
//Instrucciones para el usuario
void instruccion()
{
    printf("\n   [1] Mostrar tabla de calificaciones");
	printf("\n   [2] Mostrar informacion del alumno por ID");
	printf("\n   [3] Mostrar informacion de la practica por ID");
	printf("\n   [4] Mostrar lista de alumnos");
	printf("\n   [5] Mostrar lista de practicas");
	printf("\n   [6] Mostrar el alumno con mayor promedio");
	printf("\n   [7] Mostrar alumnos con calificacion reprobatoria");
	printf("\n   [8] Mostrar practicas con promedio menor a 6");
    printf("\n   [9] Salir");
	printf("\nRecomendacion: Maximizar la pantalla para ver la tabla mejor");
}

//Funcion que genera numeros aleatorios
void generanumeros(int M[ALUM][PRAC],int row, int col)
{
	//Declaracion de dos contadores
	int i,j;

	//Ciclo que coloca numeros aleatorios
	for(i=0; i<row; i++)
	{
		for(j=0; j<col; j++)
		{
			M[i][j] = rand()%11;
		}
	}
}

