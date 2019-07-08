//Practica 6: Apuntadores (tercer inciso)
//Elaborado por Reyes Udasco Rachelle Nerie
//Objetivo: Guardar numeros enteros en un arreglo usando malloc y realloc

#include<stdio.h>
#include<stdlib.h>

//Prototipo de funciones
int capturavalores();
void imprimirvalores(int *arreglo,int elementos);
void sumavalores(int *arreglo,int elementos);
void mayor(int *arreglo,int elementos);
void menor(int *arreglo,int elementos);

int main()
{
     //Declaracion de variables
     int elementos =0;
     char resp;
     int *arreglo,n=0;
     arreglo = (int*)malloc(sizeof(int));

    do
    {
         printf("\n¿Deseas guardar un valor(s/n)?");
         scanf(" %c",&resp);
         if (resp== 's')
         {
            if (arreglo==NULL){printf("ERROR");}
            else
            {
                elementos++;
                arreglo = realloc(arreglo,elementos*sizeof(int));
                *(arreglo+n) = capturavalores();
                n++;
            }
         }
         else if(resp =='n')
         {
             printf("\nProceso terminado");
         }
         else
         {
             printf("\nEscribe s o n");
             resp ='s';
         }

    }while(resp=='s');

    //Llamada de las funciones que se utilizaran
    imprimirvalores(arreglo,elementos);
    sumavalores(arreglo,elementos);
    mayor(arreglo,elementos);
    menor(arreglo,elementos);

    free(arreglo);
    return 0;
}

//Funcion que captura los valores
int capturavalores()
{
    int num;
     printf("\nIngresa el valor: ");
     scanf("%d",&num);
     return num;
}

//Funcion que imprime cada uno de los valores
void imprimirvalores(int *arreglo,int elementos)
{
    int i;
    //Ciclo de impresion
    for (i=0;i<elementos;i++)
    {
        printf("\nNumero %d, Valor: %d",i,*(arreglo+i));
    }
}

//Funcion que imprime la suma de los valores
void sumavalores(int *arreglo,int elementos)
{
    //Declaracion de variables
    int suma=0,i;

    //Ciclo que suma los valores
    for (i=0;i<elementos;i++)
    {
       suma = suma + *(arreglo+i);

    }

    //Impresion de la suma
    printf("\n\nLa suma de los elementos es: %d",suma);

}

//Funcion que imprime el mayor de los valores
void mayor(int *arreglo,int elementos)
{
    //Declaracion de variables
    int mayor,i;
    mayor = *(arreglo+0);

    //Ciclo que obtiene el numero mayor
    for(i=1;i<elementos;i++)
    {
        if(*(arreglo+i)>mayor){mayor = *(arreglo+i);}
    }

    //Impresion del valor mayor
    printf("\n\nEl valor mayor es: %d", mayor);

}

//Funcion que imprime el menor de los valores
void menor(int *arreglo,int elementos)
{
    //Declaracion de variables
    int menor,i;
    menor = *(arreglo+0);

    //Ciclo que obtiene el numero menor
    for(i=1;i<elementos;i++)
    {
        if(*(arreglo+i)<menor){menor = *(arreglo+i);}
    }

    //Impresion del valor
    printf("\n\nEl valor menor es: %d", menor);
}
