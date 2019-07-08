/*Practica 4: Arreglos unidimensionales y bidimensionales

Elaborado por: Reyes Udasco Rachelle Nerie
Objetivo: Este programa tiene como objetivo manipular una lista formado 
por las calificaciones de las practicas de cada alumno

Este archivo es la biblioteca
*/
#ifndef CALIFICACIONES
#define CALIFICACIONES

//Definicion de valores
#define PRAC 10
#define ALUM 20

//Declaracion de las funciones del archivo calificaciones.c
void generanumeros(int[ALUM][PRAC], int, int);
void ordenar(int[][PRAC],int, int);
float obtenermedia(int[ALUM][PRAC],int, int);
int obtenermoda(int[ALUM][PRAC],int, int);
float obtenermediana(int[][PRAC], int, int);
void imprimir(int[ALUM][PRAC], int, int);
void calalumno(int[ALUM][PRAC], int, int, int);
void calpractica(int[ALUM][PRAC], int, int, int);

#endif
