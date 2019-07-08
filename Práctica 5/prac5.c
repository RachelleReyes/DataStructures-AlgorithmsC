/*Practica 5: Estructuras de datos

Elaborado por: Reyes Udasco Rachelle Nerie
Objetivo: Este programa tiene como objetivo manipular una lista formado 
por las calificaciones de las practicas de cada alumno. De igual manera 
se encuentran guardado los datos del alumno y las practicas. 

Este es el archivo principal
*/
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include"calificaciones.h"

/*Prototipo de funciones*/
void instruccion();
void generanumeros(int M[ALUM][PRAC],int row, int col);
void capturaAlumno(struct Alumno alumnos[],int M[ALUM][PRAC],int totalalum, int col);
void capturaPractica(struct Practica practicas[],int M[ALUM][PRAC],int totalprac, int row);
void listaalumnos(struct Alumno alumnos[],int totalalum);
void listapracticas(struct Practica practicas[],int totalprac);
void mostrarAlumno(struct Alumno alumnos[],int a_id);
void mostrarPractica(struct Practica practicas[],int p_id);
float prompracticas(int M[ALUM][PRAC],int row, int practica);
float promalumnos(int M[ALUM][PRAC],int alumno, int col);
void calalumno(int M[ALUM][PRAC], int row, int col, int alumno);
void calpractica(int M[ALUM][PRAC],int row, int col, int practica);
void imprimir(int M[ALUM][PRAC],int row, int col);
void alumnosreprobados(int M[ALUM][PRAC], int row, int col);
void practicasreprobadas(int M[ALUM][PRAC], int row, int col);
void altopromedio(int M[ALUM][PRAC], int row, int col);
void encabezadoalumnos();
void encabezadopracticas();
void identificarAoN(int M[ALUM][PRAC], int alumno, int col);

int main(int argc, char* argv[])
{
    //Declaracion de variables a utilizar
	int M[ALUM][PRAC], opcion, id_a, id_p;
	
	//Genera numeros aleatorios para colocarlos en la lista 
	generanumeros(M,ALUM, PRAC);
	
	//Captura de datos de alumnos y practicas
	capturaAlumno(alumno,M,ALUM,PRAC);
	capturaPractica(practica,M,PRAC,ALUM);
	
	//Ciclo que muestra el menu
	do
	{
		instruccion();
		printf("\nEscribe el numero de la opcion que deseas realizar: ");
		scanf("%d",&opcion);

		//Compara la opcion que ingreso el usuario
		switch(opcion)
		{	
			case 1: //Imprime la lista de calificaciones
					imprimir(M,ALUM,PRAC); break;
			
			case 2: //Muestra los datos del alumno por ID
			printf("\nIngrese el ID del alumno: ");
			scanf("%d",&id_a);
			encabezadoalumnos();
			mostrarAlumno(alumno,id_a); 
			printf("\nCALIFICACIONES\n");
			calalumno(M,ALUM,PRAC,id_a);
			
			break;
			
			case 3: //Muestra los datos de la practica por ID
			printf("\nIngrese el ID de la practica: ");
			scanf("%d",&id_p);
			encabezadopracticas();
			mostrarPractica(practica,id_p); 
			printf("\nCALIFICACIONES\n");
			calpractica(M,ALUM,PRAC,id_p);
			break;
			
			case 4: //Muestra la lista de alumnos
			listaalumnos(alumno,ALUM); break;
			
			case 5: //Muestra la lista de practicas
			listapracticas(practica,PRAC);break;
			
			case 6: //Muestra los alumnos con el promedio mas alto
			encabezadoalumnos();
			altopromedio(M, ALUM, PRAC);break;
			
			case 7:  //Muestra los alumnos reprobados
			encabezadoalumnos();
			alumnosreprobados(M, ALUM,PRAC);
			break;
			
			case 8:  //Muestra las practicas reprobadas
			encabezadopracticas();
			practicasreprobadas(M, ALUM,PRAC);break;
			
			case 9: //Opcion de salida
			exit(0); break;
			
			default: 
					instruccion();
			break;
		}
	}while(opcion!=9);
	return 0;
}
//Instrucciones para el usuario
void instruccion()
{
    printf("\n\n   MENU");
	printf("\n   [1] Mostrar tabla de calificaciones ");
	printf("\n   [2] Mostrar informacion del alumno por ID ");
	printf("\n   [3] Mostrar informacion de la practica por ID ");
	printf("\n   [4] Mostrar lista de alumnos ");
	printf("\n   [5] Mostrar lista de practicas ");
	printf("\n   [6] Mostrar el alumno con mayor promedio ");
	printf("\n   [7] Mostrar alumnos con calificacion reprobatoria ");
	printf("\n   [8] Mostrar practicas con promedio menor a 6 ");
    printf("\n   [9] Salir");
	printf("\n   Recomendacion: Maximizar para ver la tabla mejor\n\n");
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
