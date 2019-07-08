/*Practica 5: Estructuras de datos

Elaborado por: Reyes Udasco Rachelle Nerie
Objetivo: Este programa tiene como objetivo manipular una lista formado 
por las calificaciones de las practicas de cada alumno. De igual manera 
se encuentran guardado los datos del alumno y las practicas. 

Este archivo es para la biblioteca calificaciones.h
*/
//calificaciones.c
#include<stdio.h>
#include "calificaciones.h"

//Funcion que imprime el encabezado de la tabla alumnos
void encabezadoalumnos()
{		
		int i;
		//Impresion del encabezado con disenio
		printf("\n%10s","ALUMNOS\n");
		printf("  ");
		for(i=0;i<132;i++){printf("-");}
		printf("\n |");
		printf("%8s      |","ID");
		printf("%12s      |","NOMBRE");
		printf("%8s    |","EDAD");
		printf("%14s        |","CORREO");
		printf("%9s   |","GENERO");
		printf("%15s   |","ANIO INGRESO");
		printf("%10s    |","PERIODO");
		printf("%11s   |\n","PROMEDIO");
		printf("  ");
		for(i=0;i<132;i++){printf("-");}
		
}

//Funcion imprime la lista de practicas
void encabezadopracticas()
{
	int i;
	
	printf("\n%10s","PRACTICAS\n");
	printf("  ");
	for(i=0;i<90;i++){printf("-");}
	printf("\n |");
	printf("%7s    |","ID");
	printf("%12s          |","TITULO");
	printf("%23s                   |","COMENTARIO");
	printf("%9s  |\n","PROMEDIO");
	
	printf("  ");
	for(i=0;i<90;i++){printf("-");}
	
}

//Funcion que captura los datos del alumno
void capturaAlumno(struct Alumno alumnos[],int M[ALUM][PRAC],int totalalum, int col)
{
	int i;
	for(i=0 ; i<totalalum ; i++){
		
		alumnos[i].ID = i;
		printf("\n ID del alumno: %d", alumnos[i].ID);
		
		printf("\n Ingrese el nombre del alumno: ");
		scanf("%s",alumnos[i].nombre);

		printf("\n Ingrese la edad del alumno: ");
		scanf("%d", &alumnos[i].edad);

		printf("\n Ingrese el correo del alumno: ");
		scanf("%s",alumnos[i].correo);

		printf("\n Genero [M]asculino o [F]emenino: ");
		scanf(" %c", &alumnos[i].genero);

		printf("\n Anio del ingreso del alumno: ");
		scanf("%d", &alumnos[i].ingreso);

		printf("\n Periodo 1 o 2: ");
		scanf("%d", &alumnos[i].periodo);
		
		alumnos[i].promedio = promalumnos(M,i,col);
	}
}

int clear_input_buffer()
{
    int ch;
    while(((ch=getchar())!=EOF) && (ch != '\n'));
    return ch;
}

//Funcion que captura los datos de la practica
void capturaPractica(struct Practica practicas[],int M[ALUM][PRAC],int totalprac, int row)
{
	int i;
	for(i=0 ; i<totalprac ; i++)
	{
		practicas[i].ID = i;
		printf("\n ID de la practica: %d", practicas[i].ID);
		
		printf("\nIngrese el titulo de la practica: ");
		if(i==0){clear_input_buffer();}
		gets(practicas[i].titulo);
		
		printf("\nEscribe un comentario: ");
		gets(practicas[i].comentario);
		
		practicas[i].promedio = prompracticas(M,row,i);
	}
}

//Funcion que imprime la lista de alumnos
void listaalumnos(struct Alumno alumnos[],int totalalum)
{
	int i,j;
	encabezadoalumnos();
	for(i=0 ; i<totalalum ; i++){
	
		printf("\n |");
		printf("%8d      |",alumnos[i].ID);
		printf("%16s  |",alumnos[i].nombre);
		printf("%7d     |",alumnos[i].edad);
		printf("%20s  |",alumnos[i].correo);
		printf("%7c     |", alumnos[i].genero);
		printf("%11d       |", alumnos[i].ingreso);
		printf("%8d      |",alumnos[i].periodo);
		printf("%8.2f      |\n", alumnos[i].promedio);
		printf("  ");
		for(j=0;j<132;j++){printf("-");}
		
	}
}

//Funcion que imprime la lista de practicas
void listapracticas(struct Practica practicas[],int totalprac)
{
	int i,j;
	encabezadopracticas();
	for(i=0 ; i<totalprac ; i++)
	{
		printf("\n |");
		printf("%7d    |",practicas[i].ID);
		printf("%20s  |",practicas[i].titulo);
		printf("%40s  |",practicas[i].comentario);
		printf("%7.2f    |\n",practicas[i].promedio);
		
		printf("  ");
		for(j=0;j<90;j++){printf("-");}
	}

}
//Funcion que muestra el alumno del id ingresado
void mostrarAlumno(struct Alumno alumnos[],int a_id)
{
	int i;
	//encabezadoalumnos();
	
		printf("\n |");
		printf("%8d      |",alumnos[a_id].ID);
		
		printf("%16s  |",alumnos[a_id].nombre);
		
		printf("%7d     |",alumnos[a_id].edad);
		
		printf("%20s  |",alumnos[a_id].correo);
		
		printf("%7c     |", alumnos[a_id].genero);
		
		printf("%11d       |", alumnos[a_id].ingreso);
		
		printf("%8d      |",alumnos[a_id].periodo);
		
		printf("%9.2f     |\n", alumnos[a_id].promedio);
		
	
		printf("  ");
		for(i=0;i<132;i++){printf("-");}
}

//Muestra la practica segunn el id ingresado
void mostrarPractica(struct Practica practicas[],int p_id)
{
		int i;
		printf("\n |");
		printf("%7d    |",practicas[p_id].ID);
		printf("%20s  |",practicas[p_id].titulo);
		printf("%40s  |",practicas[p_id].comentario);
		printf("%7.2f    |\n",practicas[p_id].promedio);
		
		printf("  ");
		for(i=0;i<90;i++){printf("-");}
}

//Muestra los alumnos reprobados
void alumnosreprobados(int M[ALUM][PRAC], int row, int col)
{
	int i;
	
	for(i=0;i<row;i++)
	{
		if((promalumnos(M,i,col))<6)
		{
			mostrarAlumno(alumno,i);
		}
	}
}

//Muestra las practicas reprobadas
void practicasreprobadas(int M[ALUM][PRAC], int row, int col)
{
	int i;
	
	for(i=0;i<row;i++)
	{
		if((prompracticas(M,row,i))<6)
		{
			mostrarPractica(practica,i);
		}
	}
}

//Obtiene el promedio de cada practica
float prompracticas(int M[ALUM][PRAC],int row, int practica)
{
	//Declaracion de variables
	int  i;
	float suma=0,promPx;

	for(i=0; i<row; i++)
	{
		suma = suma + M[i][practica];
	}
	promPx= suma/row;
	return promPx;
	
}

//Obtiene el promedio de cada alumno
float promalumnos(int M[ALUM][PRAC],int alumno, int col)
{
	//Declaracion de variables
	int  j;
	float suma=0,promAx;

	for(j=0; j<col; j++)
	{
		suma = suma + M[alumno][j];
	}
	promAx= suma/col;
	return promAx;
	
}

//Funcion que imprime las calificaciones de los alumnos segun lo que el usuario desee
void calalumno(int M[ALUM][PRAC], int row, int col, int alumno)
{
	//Declaracion de contadores
	int i,j;

	printf("\n            ALUMNO\n");
	printf("PRACTICA");
	
	for(i=0; i<col; i++)
	{
		if (i==0){printf("%16d",i);}
		else {printf("%8d",i);}
	}
	
	printf("   PROMEDIO");
	printf("\n\n%16d",alumno);
	
	//Ciclo que imprime las calificaciones del alumno
	for(j=0; j<col; j++)
	{
		printf("%8d",M[alumno][j]);
	}
	
	printf("%8.2f", promalumnos(M,alumno,col));	
}

//Funcion que imprime las calificaciones de las practicas segun lo que el usuario desee
void calpractica(int M[ALUM][PRAC],int row, int col, int practica)
{
	//Declaracion del contador
	int j;
	printf("\n\n    ALUMNO 	     PRACTICA\n");
	
	//Ciclo que imprime las calificaciones del alumno
	for(j=0; j<row; j++)
	{
		printf("%8d",j);
		printf("%16d\n",M[j][practica]);
	}
	printf("\nPromedio        ");
		
	printf("%8.2f", prompracticas(M,row,practica));	
}

//Imprime los datos del alumno con mayor promedio
void altopromedio(int M[ALUM][PRAC], int row, int col)
{
	int i,j,mayor,altopromid;

	mayor = (promalumnos(M,0,col));
	altopromid=0;
	
	for(i=0;i<row;i++)
	{
		if((promalumnos(M,i,col))>=mayor)
		{
			mayor = promalumnos(M,i,col);
			altopromid = i;
		}
	}
	mostrarAlumno(alumno,altopromid);
	
	for(j=0;j<row;j++)
	{
		if(j!=altopromid && (promalumnos(M,altopromid,col))==mayor)
		{
			mostrarAlumno(alumno,j);
		}
	}
}

void identificarAoN(int M[ALUM][PRAC], int alumno, int col)
{
	if((promalumnos(M,alumno,col))<6)
	{
		printf("%5c    |",'N');
	}
	else 
	{
		printf("%5c    |",'A');
	}
}

//Funcion que imprime la tabla de calificaciones con los promedios
void imprimir(int M[ALUM][PRAC],int row, int col)
{
	
	//Declaracion de contadores
	int i,j,k;
	int n;
	n = 33+(col*10);
	
	printf("\n  ");
	for(k=0;k<13;k++){ if(k==0){printf("%13s","-");}else {printf("-");}}
	printf("\n%23s   |","|  ALUMNO");
	printf("\n  ");
	
	for(k=0;k<n;k++){ if(k==0){printf("%2s","-");}else {printf("-");}}
	
	printf("\n%3s","|");
	printf("%4s","  PRACTICA |");
	
	for(i=0; i<col; i++)
	{
		if(i==0){printf("%17d    |",i);}
		else{printf("%5d    |",i);}
	}
	printf("%7s  |","PROM");
	
	printf("\n  ");
	for(k=0;k<n+10;k++){ if(k==0){printf("%2s","-");}else {printf("-");}}
	
	//Impresion de la tabla de calificaciones
	printf("\n");
	for(i=0; i<row; i++)
	{
		//here
		printf("%15s","|");
		printf("%5d      |",i);
		
		for(j=0; j<=col; j++)
		{
			if(j==col){
				printf("%7.2f  |", promalumnos(M,i,col));
				identificarAoN(M,i,col);
			}
			else {printf("%5d    |",M[i][j]);}
		}
		printf("\n  ");
		for(k=0;k<n;k++){ if(k==0){printf("%13s","-");}else {printf("-");}}
		//for(k=0;k<n;k++){printf("-");}
		printf("\n");
	}
	
	printf("%25s |","|  PROMEDIO");
	
	for(j=0; j<col; j++)
		{
			printf("%7.2f  |", prompracticas(M,row,j));	
		}
		printf("\n  ");
		for(k=0;k<(n-20);k++){ if(k==0){printf("%13s","-");}else {printf("-");}}
}