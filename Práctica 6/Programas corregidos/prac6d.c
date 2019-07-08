//Practica 6: Apuntadores (cuarto inciso)
//Elaborado por Reyes Udasco Rachelle Nerie
//Objetivo: Guardar numeros flotantes en una matriz con las dimensiones dadas por el usuario

#include<stdio.h>
#include<stdlib.h>

//Prototipo de funciones
void dimensionmatriz(int *renglon, int *columna);
float generanumero();
void definirmatriz(float *matriz,int elementos);
void imprimematriz(float *matriz,int renglon,int columna);

int main()
{
    //Declaracion de variables
    int renglon,columna,elementos;
    float *matriz;

    dimensionmatriz(&renglon,&columna);
    elementos = renglon*columna;

    matriz = (float*) malloc(sizeof(float)*elementos);
    definirmatriz(matriz,elementos);
    imprimematriz(matriz,renglon,columna);

    free(matriz);
    return 0;
}

//Funcion que pide la dimension de la matriz al usuario
void dimensionmatriz(int *renglon, int *columna)
{
    printf("\nIngrese el tamanio de la matriz: ");
    printf("\nRenglon: ");
    scanf("%d",renglon);
    printf("Columna: ");
    scanf("%d",columna);
}
//Funcion que genera numeros aleatorios flotantes
float generanumero()
{
    float nrand;
    //Genera numeros aleatorios flotantes de -10 a 10
    nrand =(((float)rand()/(float)(RAND_MAX)) * 20.0)-10;
    return nrand;
}

//Función que asigna los numeros aleatorios a la matriz
void definirmatriz(float *matriz,int elementos)
{
    int i;

     for(i=1;i<=elementos;i++)
    {
        *(matriz+i) = generanumero();
    }
}

//Funcion que imprime la matriz
void imprimematriz(float *matriz,int renglon,int columna)
{
    int i,j,k=0;

    //Ciclo de impresion por renglon y columna
     for(i=1;i<=renglon;i++)
    {
        for(j=1;j<=columna;j++)
        {
            k++;
            printf("%8.3f",*(matriz+k));
        }
       printf("\n");
    }
}
