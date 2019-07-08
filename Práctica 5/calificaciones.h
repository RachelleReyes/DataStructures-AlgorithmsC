/*Practica 5: Estructuras de datos

Elaborado por: Reyes Udasco Rachelle Nerie
Objetivo: Este programa tiene como objetivo manipular una lista formado 
por las calificaciones de las practicas de cada alumno. De igual manera 
se encuentran guardado los datos del alumno y las practicas. 

Este archivo es la biblioteca
*/
#ifndef CALIFICACIONES
#define CALIFICACIONES

//Definicion de valores
#define PRAC 5
#define ALUM 5

//Definicion de la estructura Alumno
struct Alumno{
int ID;
char nombre[15];
char correo[15];
char genero;
int ingreso;
int periodo;
float promedio;
int edad;
}alumno[ALUM];

//Definicion de la estructura Practica
struct Practica
{
	int ID;
	char titulo[20];
	char comentario[40];
	float promedio;
}practica[PRAC];

//Declaracion de las funciones del archivo calificaciones.c
int clear_input_buffer();
void capturaAlumno(struct Alumno alumnos[],int M[ALUM][PRAC],int,int);
void capturaPractica(struct Practica practicas[],int M[ALUM][PRAC],int,int);
void listaalumnos(struct Alumno alumnos[],int);
void listapracticas(struct Practica practicas[],int);
void mostrarAlumno(struct Alumno alumnos[],int);
void mostrarPractica(struct Practica practicas[],int);
float prompracticas(int M[ALUM][PRAC],int, int);
float promalumnos(int M[ALUM][PRAC],int, int);
void calalumno(int M[ALUM][PRAC], int, int ,int);
void calpractica(int M[ALUM][PRAC],int, int,int);
void imprimir(int M[ALUM][PRAC],int, int);
void alumnosreprobados(int M[ALUM][PRAC], int , int);
void practicasreprobadas(int M[ALUM][PRAC], int, int );
void altopromedio(int M[ALUM][PRAC], int, int);
void encabezadoalumnos();
void encabezadopracticas();
void identificarAoN(int M[ALUM][PRAC], int alumno, int col);

#endif
