//Programa elaborado por Reyes Udasco Rachelle Nerie
/*El objetivo de este programa es leer un archivo
por consola e invertir las mayusculas en minusculas, y viceversa*/
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>


void error(int);

int main(int argc, char** argv)
{
    FILE* file, *file2;
	char c;

    if(!(argc>1)) { error(0);}
    if (argv[2]!=NULL)
	{
		file2 = fopen(argv[2], "w+");
		if(!file2) { error(1);}
	}
	//Lee el archivo
    file = fopen(argv[1], "r");
    //Comapracion si el archivo se pudo abrir
    if(!file){ error(2); }
    //Lectura del archivo

    //Ciclo que lee el archivo hasta que llega al final de ello
	while(!feof(file))
	{
		c = fgetc(file);
		//Comapracion si es mayuscula o minuscula
		if(c>=65 && c<=95)
		{
			c = c+32;
		}
		else if(c>=97 && c<=122)
		{
			c = c-32;
		}
		if(argv[2]==NULL)
		{
			printf("%c",c);
		}
		else
		{
			fprintf(file2,"%c",c);
		}
	}

    fclose(file);
    //Cierra el segundo archivo, si el usuario eligio leer el texto en ello
	if (argv[2]!=NULL) {fclose(file2);}

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
         case 1: printf("Error al abrir flujo del nuevo archivo.");
			exit(-1);
        break;
         case 2:
        printf("Error al abrir flujo de archivo.");
        exit(-1);
        break;
    }
}
