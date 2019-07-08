//Programa elaborado por Reyes Udasco Rachelle Nerie
/*El objetivo de este programa es leer un archivo
por consola haciendo pausas por cierta cantidad de lineas*/

#include<stdio.h>
#include<stdlib.h>
//Definicion de constantes
#define INTRO 15
#define NLINEA 10

void error(int err);

int main(int argc, char** argv)
{
    //Declaracion de variables
    FILE* file;
    char input[100];
	int lineas=0, n=INTRO,i;

	//Revison del numero de argumentos ingresado
    if(!(argc>1)) { error(0); }

    //Lee el archivo
    file = fopen(argv[1], "r");

    //El programa termina si el archivo no se lee exitosamente
    if(!file) { error(1); }

    //Ciclo que lee el archivo
	while(!feof(file))
	{
		for(i=0; i<n; i++)
		{
			//Lectura de cadenas
			fgets(input,100,file);
			lineas++;
			//Impresion de linea, impresion del numero de linea agregada para facilitar revision
			printf("Linea %d: %s",lineas, input);
			if(feof(file)) {break;}
		}
        //Comparacion si las primeras 15 lineas o 10 lineas fueron leidas
	  if(lineas==INTRO || (lineas-INTRO)%NLINEA == 0)
	  {
		  getchar();
		  n=NLINEA;
	  }
	}
    fclose(file);

    return EXIT_SUCCESS;
}

//Funcion para imprimir mensajes de error
void error(int err)
{
    switch(err)
    {
        case 0:
            printf("Error en los parametros por consola.\nRequiere nombre de archivo a leer.");
            exit(-1);
        break;
         case 1:
        printf("Error al abrir flujo de archivo.");
        exit(-1);
        break;
    }
}
