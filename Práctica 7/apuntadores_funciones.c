#include<stdio.h>

float max(int*, int);
float min(int*, int);
//EXTRA
//float desviacion(int*, int);
float media(int*, int);
float mediana(int*, int);
float moda(int*, int);

/*
Funcion que recibe el nombre del archivo a leer y 
regresa un arreglo unidimensional con los valores contendos
en el archivo. Usar memoria dinamica.
*/
//void captura(char* archivo, int* arreglo, int* tamano);

int main(int argc, char* argv[])
{
    int size, i, *arreglo, tam;
    //arreglo de apuntadores a funciones
    float (*funciones[])(int*, int) = {max, min, media, mediana, moda };
    char* nombres[] = {"maximo", "minimo", "media", "mediana", "moda"};
    
    //ejemplo de uso de funcion captura
    //captura(nombre_archivo, arreglo, &tam);
    
	//Nos contara los elementos
    size = sizeof(funciones)/sizeof(funciones[0]);
    for(i=0; i<size; i++)
        printf("%s: %.3f\n", nombres[i], funciones[i](arreglo,tam));
    return 0;
}

float max(int* array, int size)
{
    return 0;
}

float min(int* array, int size)
{
    return 1;
}

float media(int* array, int size)
{
    return 2;
}

float mediana(int* array, int size)
{
    return 3;
}

float moda(int* array, int size)
{
    return 4;
}
