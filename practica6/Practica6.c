/*

Elaborado por Reyes Udasco Rachelle Nerie
Práctica No. 6 Recursividad
13 de octubre del 2018
Grupo 551
Algoritmos y Estructura de Datos

Competencia: Diseñar soluciones creativas donde se aplique apropiadamente el concepto de recursividad a problemas reales.
Una hembra canina no esterilizada tendrá en su primer año fértil dos celos y como producto al menos 16 cachorros.
Supongamos que de los 16, la mitad, o sea 8, serán hembras las cuales no estarán esterilizadas. Transcurrido un año,
la hembra original tendrá otros 16 cachorros y sus 8 primeras descendientes repetirán el patrón y tendrán cada una otros
16 cachorros, haciendo un total de (8 x 16 =128) + 16=144.  al cabo de 5 años los descendientes de los descendientes
habrán procreado 74899 caninos.  Esta progresión se verifica en la siguiente relación:

1 año: 16
2 año: 16 +128 =144
3 año: 16+128+ 1024 = 1168
4 año: 16+128+1024+8192=9360
5 año: 16+128+1024+8192+65536=74899

Tabla 1.
Diseñe e implemente un programa basado en funciones recursivas que calculen la cantidad de perros que nacerán en un
período determinado. El usuario debe proporcionar el tamaño de la camada y la cantidad de años que se desea calcular.
En la tabla 1, la cantidad de cachorros es 16 y la proyección se realizó a 5 años.

-No se aceptarán prácticas sin recursividad.
-Lenguaje C/Java -
-El usuario debe proporcionar el tamaño de la camada
*/

//Declaracion de bibliotecas
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

//Prototipo de funciones
int contarDescendientes(int, int, int,int [],int );
int sumarValores(int [],int);
int esNumero(char *);
int capturarNumero();


//Funcion principal
int main() {
    char cadena[10],resp;
    int cantidad, anios,indice;

    do{
        system("cls||clear");

        printf("\n Ingrese el tama%co de la camada: ",164);
        cantidad = capturarNumero();

        printf("\n Ingrese la cantidad de a%cos: ",164);
        anios = capturarNumero();

        int impresion[anios];
        indice =0;

        printf("\n\n Tama%co de la camada: %d \n Cantidad de a%cos: %d \n Total de descendientes: %d",164,cantidad,164,anios,contarDescendientes(cantidad,cantidad,anios,impresion,indice));

        printf("\n\n %cDeseas calcular de nuevo? (s/n): ",168);
        resp = getche();
    }while(tolower(resp)=='s');

    return 0;

}

//Función recursiva que cuenta la cantidad de nacimientos en un periodo de tiempo
int contarDescendientes(int cantidad, int total, int anios, int impresion[],int indice) {

    impresion[indice] = total; //Guarda los valores en un vector sólo para la impresión
    printf("\n A%cos: %d, Total: %d",164, indice+1,sumarValores(impresion,indice));  //Impresión de valores

    if (anios>1)
        return total + contarDescendientes(cantidad,(total/2*cantidad),anios-1,impresion,indice+1);
    else
        return total;
}

/* Función recursiva sin la impresión del proceso

int contarDescendientes(int cantidad, int anios) {
    if (anios>1)
        return (cantidad +(cantidad/2)*contarDescendientes(cantidad,anios-1));
    else
        return cantidad;
}

*/

//Función que sirve para validar si el dato ingresado es un número
int esNumero(char * cadena) {
    int i, siNumero=1;

    for(i=0; i<strlen(cadena); i++){
        if(!(cadena[i]>='0' && cadena[i]<='9'))
           siNumero =0;
    }
    return siNumero;
}

//Función que captura un número
int capturarNumero() {
    char cadena[15];

    gets(cadena);
    while(!esNumero(cadena)) {
        printf("\n Ingrese un n%cmero v%clido: ",163,160);
        gets(cadena);
    }

    return atoi(cadena);
}

//Función que ayuda a sumar los valores para la impresión de los valores
int sumarValores(int vector[],int tamanio) {
    int i=0,total=0;

    while(i<=tamanio)
        total+= vector[i++];

    return total;
}
