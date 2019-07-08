/*Practica 4: Arreglos unidimensionales y bidimensionales

Elaborado por: Reyes Udasco Rachelle Nerie
Objetivo: Este programa tiene como objetivo manipular una lista formado 
por las calificaciones de las practicas de cada alumno

Este archivo es para la biblioteca calificaciones.h
*/
//calificaciones.c
#include "calificaciones.h"
#include <stdio.h>
#include <stdlib.h>

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

//Funcion que ordena los numeros de la lista de calificaciones
void ordenar(int M[][PRAC],int row, int col )
{
	//Declaracion de variables
	int i,n,cal,j=0, cambiado=1;

	n = row*col;

	//Ciclo que ordena los numeros de menor a mayor
	while (cambiado)
	{
		cambiado = 0;
		j++;
		for (i=0; i<n-j; i++)
		{
			if (M[0][i] > M[0][i + 1])
			{
				cal = M[0][i];
				M[0][i] = M[0][i + 1];
				M[0][i + 1] = cal;
				cambiado = 1;
			}
		}
	}
}

//Funcion que saca el promedio de las practicas
void prompracticas(int M[ALUM][PRAC], int row, int col, int practica)
{
	//Declaracion de variables
	int  i, j;
	float pprac[col], suma=0; //pprac es un vector que guarda los promedios de las practicas
	
	//Ciclo que guarda el promedio de cada una de las practicas
	for(j=0; j<col; j++)
	{
		for(i=0; i<row; i++)
		{
			suma = suma + M[i][j];
			if(i==(row-1))
			{ 
				pprac[j]=suma/row;
			}
		}
		suma =0;
	}
	//Imprime el promedio
	printf("%8.2f",pprac[practica]);
}

//Funcion que saca el promedio de las calificaciones del alumno
void promalumnos(int M[ALUM][PRAC], int row, int col, int alumno)
{
	//Declaracion de variables
	int i, j;
	float palum[row],suma =0; //palum es una matriz que guarda el promedio de alumnos
	
	//Ciclo que guarda el promedio de lo alumnos
	for(i=0; i<row; i++)
	{
		for(j=0; j<col; j++)
		{
			suma = suma + M[i][j];
			if(j==(col-1))
			{ 
				palum[i]=suma/col;
			}
		}
		suma =0;
	}
	//Imprime el promedio
	printf("%8.2f",palum[alumno]);
	
}

//Funcion que obtiene la media de las calificaciones
float obtenermedia(int M[ALUM][PRAC],int row, int col)
{
	//Declaracion de variables
	int i,j,n;
	float suma=0, media=0;
	
	n=row*col;
	//Ciclo que guarda las sumas de las calificaciones
	for(i=0; i<ALUM; i++)
	{
		for(j=0; j<PRAC; j++)
		{
			suma = suma + M[i][j];
		}
	}
	//Saca el promedio
	media = suma/n;
	return media;
}

//Funcion que obtiene la moda de las calificaciones
int obtenermoda(int M[ALUM][PRAC], int row, int col)
{
	//Declaracion de variables
	int num[11]={0}, moda=0, i, j, temp;
	
	//Ciclo que usa el vector para contar cuantas veces se repite la calificacion
	for(i=0; i<row; i++)
	{
		for(j=0; j<col; j++)
		{
			num[M[i][j]]++;
		}
	}
	temp = num[0];
	
	//Ciclo para comparar el numero que mas se repite
	for(i=1; i<=10; i++)
	{
		if (num[i]>temp)
		{
			temp = num[i];
			moda =i;
		}
	}
	return moda;
}

//Funcion que obtiene la mediana de las calificaciones
float obtenermediana(int M[][PRAC], int row, int col)
{
	//Declaracion de variables
	float mediana, suma;
	int n;
	
	n = row*col;
	
	//Comparacion que obtiene la mediana segun la cantidad total de las calificaciones
	if(n%2 == 0)
	{
		suma = (M[0][n/2-1]+M[0][n/2]);
		mediana =suma/2;
	}
	else
	{
		mediana = (M[0][n/2]);
	}
	return mediana;
}

//Funcion que imprime las calificaciones de los alumnos segun lo que el usuario desee
void calalumno(int M[ALUM][PRAC], int row, int col, int alumno)
{
	//Declaracion de contadores
	int i,j;

	printf("\n            ALUMNO\n");
	printf("PRACTICA");
	
	for(i=1; i<=col; i++)
	{
		if (i==1){printf("%16d",i);}
		else {printf("%8d",i);}
	}
	
	printf("   PROMEDIO");
	printf("\n\n%16d",alumno);
	
	//Ciclo que imprime las calificaciones del alumno
	for(j=0; j<col; j++)
	{
		printf("%8d",M[alumno-1][j]);
	}
	
	promalumnos(M,row,col,alumno-1);
}

//Funcion que imprime las calificaciones de las practicas segun lo que el usuario desee
void calpractica(int M[ALUM][PRAC], int row, int col, int practica)
{
	//Declaracion del contador
	int j;
	printf("\n\n    ALUMNO 	     PRACTICA\n");
	
	//Ciclo que imprime las calificaciones del alumno
	for(j=1; j<=row; j++)
	{
		printf("%8d",j);
		printf("%16d\n",M[j-1][practica-1]);
	}
	printf("\nPromedio        ");
		
	prompracticas(M,row,col,practica-1);
}

//Funcion que imprime la tabla de calificaciones con los promedios
void imprimir(int M[ALUM][PRAC],int row, int col)
{
	//Declaracion de contadores
	int i,j;
	printf("\n            ALUMNO\n");
	
	printf("PRACTICA");
	
	for(i=0; i<=col; i++)
	{
		printf("%8d",i);
	}
	
	printf("   PROMEDIO");
	
	//Impresion de la tabla de calificaciones
	printf("\n\n");
	for(i=0; i<row; i++)
	{
		printf("%16d",i+1);
		
		for(j=0; j<=col; j++)
		{
			if(j==col){promalumnos(M,row,col,i);}
			else {printf("%8d",M[i][j]);}
		}
		printf("\n");
	}
	
	printf("\n        PROMEDIO");
	
	for(j=0; j<col; j++)
		{
			prompracticas(M,row,col,j);
		}
}
