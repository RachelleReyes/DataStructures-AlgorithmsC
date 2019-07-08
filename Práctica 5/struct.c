#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

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
	
};

int main()
{
	//struct Alumno al1;
	struct Alumno a[ALUM];
	//a[0].ID=0;  es el indice
	//a[0].promedio
	
	//scanf("%s",&al1.nombre);
	//printf("%s",al1.nombre);
}

void capturaAlumno(struct Alumno alumnos[],int indice)
{
	//Captura nombre,edad, etc
	//printf()
	scanf("%s",&alumno[indice].nombre);
	
}
void mostrarAlumno(struct Alumno alumno)
{
	//mostrar Alumno(a[0]);
	
}