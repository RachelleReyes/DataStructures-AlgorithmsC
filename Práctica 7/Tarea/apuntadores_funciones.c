//Programa elaborado por Reyes Udasco Rachelle Nerie
/*El objetivo de este programa es leer un archivo
por consola y guardar numeros enteros en un arreglo,
enseguida, obtener media, moda, mediana, max, min y desviacion estandar*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>

//Prototipo de funciones
void captura(char*, int*, int*);
int compare (const void *, const void *);
float max(int*, int);
float min(int*, int);
//EXTRA
float desviacion(int*, int);
float media(int*, int);
float mediana(int*, int);
float moda(int*, int);
int tamanoarreglo(char* archivo);
void error(int);

/*
Funcion que recibe el nombre del archivo a leer y
regresa un arreglo unidimensional con los valores contendos
en el archivo. Usar memoria dinamica.
*/
FILE* file;
int main(int argc, char* argv[])
{
	int *arreglo, size, i,tam=0;
    //arreglo de apuntadores a funciones
    float (*funciones[])(int*, int) = {max, min, media, mediana, moda,desviacion };
    char* nombres[] = {"maximo", "minimo", "media", "mediana", "moda", "desviacion"};
    char *nombre_archivo;

   //Comparobacion si el usuario ingreso el nombre de archivo
    if(!(argc>1)) { error(0);}
	nombre_archivo = argv[1];

    file = fopen(nombre_archivo, "r");
    if(!file){error(1);}

    tam = tamanoarreglo(nombre_archivo);
	arreglo = (int*)malloc(tam*sizeof(int));

	//Lectura del archivo
	file = fopen(nombre_archivo, "r");
    captura(nombre_archivo, arreglo, &tam);

	//Nos contara los elementos
    size = sizeof(funciones)/sizeof(funciones[0]);
    for(i=0; i<size; i++)
        printf("%s: %.3f\n", nombres[i], funciones[i](arreglo,tam));
	free(arreglo);
    return EXIT_SUCCESS;
}

//Funcion que imprime mensajes de errores
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


//Funcion que captura los numeros enteros del archivo leido
void captura(char* archivo, int* arreglo, int* tamano)
{
	int i=0;
	//Ciclo que lee el archivo
    while(!feof(file))
    {
	   fscanf(file, "%d", arreglo+i);
	   printf("%d\n",*(arreglo+i));
	   i++;
    }
    fclose(file);
}


//Cuenta el tamanio del arreglo
int tamanoarreglo(char* archivo)
{
    int i=0,j=-1;
    while(!feof(file))
    {
	   fscanf(file, "%d", &j);
        if(j!=-1)
        {
            i++;
        }
	   j=-1;

    }
     fclose(file);
     return i;
}

//Funcion que imprime el mayor de los valores
float max(int* array, int size)
{
    //Declaracion de variables
    int i=0;
    float mayor;
    mayor = *(array+i);

    //Ciclo que obtiene el numero menor
    for(i=1;i<size;i++)
    {
        if(*(array+i) > mayor)
		{
			mayor = *(array+i);
		}
    }
	return mayor;
}

//Funcion que imprime el menor de los valores
float min(int* array, int size)
{
    //Declaracion de variables
    int i=0;
    float menor;
    menor = *(array+i);

    //Ciclo que obtiene el numero menor
    for(i=1;i<size;i++)
    {
        if(*(array+i) < menor)
		{
			menor = *(array+i);
		}
    }
	return menor;
}

//Funcion que compara si un numero es mayor que otro
int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

//Funcion que imprime la media de los valores
float media(int* array, int size)
{
	//Declaracion de variables
	int i;
	float suma=0, media=0;

	//Ciclo que guarda las suma de los valores
	for(i=0; i<size; i++)
	{
		suma = suma + *(array+i);
	}
	//Saca el promedio
	media = suma/size;

	return media;
}

//Funcion que imprime la mediana de los valores
float mediana(int* array, int size)
{
   float mediana, suma;

    //Ordena los datos
	 qsort (array, size, sizeof(int), compare);

	//Comparacion que obtiene la mediana segun la cantidad total de los valores
	if(size%2 == 0)
	{
		suma = *(array+((size/2)-1))+ *(array+(size/2));
		mediana =suma/2;
	}
	else
	{
		mediana = *(array+(size/2));
	}
	return mediana;
}

//Funcion que imprime la moda de los valores
float moda(int* array, int size)
{
   	int moda, i=0, temp;
   	int nmax,nmin;

   	nmax = max(array,size);
    nmin = min(array,size);
    int num[nmax+1];

    //Inicializa los valores en 0;
    for(i=nmin; i<=nmax; i++)
	{
        num[i] =0;
	}

	//Cuenta cuantas veces se repite un numero
	for(i=0; i<size; i++)
	{
		num[*(array+i)]++;
	}
	temp = num[nmin];

	//Ciclo para comparar el numero que mas se repite
	for(i=nmin; i<=nmax; i++)
	{
		if (num[i]>=temp)
		{
			temp = num[i];
			moda =i;
		}
	}
	return moda;
}

//Funcion que imprime la desviacion estandar de los valores
float desviacion(int* array, int size)
{
	//Declaracion de variables
	int i;
	float promedio, desv=0;
    promedio= media(array,size);

    //Ciclo que obtiene la sumatoria
    for(i=0;i<size;i++)
    {
        desv  = desv + (pow((array[i]-promedio),2));
    }

    desv = sqrt(desv/size);
	return desv;
}

