/*Practica 4: Arreglos unidimensionales y bidimensionales

Elaborado por: Reyes Udasco Rachelle Nerie
Objetivo: Este programa tiene como objetivo manipular una lista formado 
por las calificaciones de las practicas de cada alumno

Este archivo es para la biblioteca calificaciones.h
*/
//calificaciones.c
#include "calificaciones.h"


struct Alumno{
int ID;
char nombre[15];
char correo[20];
char genero;
int ingreso;
int periodo;
float promedio;
int edad;
};

struct Practica
{
	int ID;
	char titulo[15];
	char comentario[50];
	float promedio;
	
};

void capturaAlumno(struct Alumno alumnos[],int indice)
{
	//Captura nombre,edad, etc
	//scanf("%d",&alumno[indice].ID);
	
	printf("\n Ingrese el nombre del alumno: ");
	scanf("%s",&alumno[indice].nombre);
	
	printf("\n Ingrese la edad del alumno: ");
	scanf("%d",&alumno[indice].edad);
	
	printf("\n Ingrese el correo del alumno: ");
	scanf("%s",&alumno[indice].correo);
	
	printf("\n Genero: [M]asculino o [F]emenino ");
	scanf("%c",&alumno[indice].genero);
	
	printf("\n Anio del ingreso del alumno: ");
	scanf("%d",&alumno[indice].ingreso);
	
	printf("\n Periodo: 1 o 2");
	scanf("%d",&alumno[indice].periodo);
	
	//scanf("%f",&alumno[indice].promedio);
}
void mostrarAlumno(struct Alumno alumno)
{
	//mostrar Alumno(a[0]);
	
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
