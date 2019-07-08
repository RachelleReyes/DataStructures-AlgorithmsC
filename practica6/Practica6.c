/*

Elaborado por Reyes Udasco Rachelle Nerie
Pr�ctica No. 6 Recursividad
13 de octubre del 2018
Grupo 551
Algoritmos y Estructura de Datos

Competencia: Dise�ar soluciones creativas donde se aplique apropiadamente el concepto de recursividad a problemas reales.
Una hembra canina no esterilizada tendr� en su primer a�o f�rtil dos celos y como producto al menos 16 cachorros.
Supongamos que de los 16, la mitad, o sea 8, ser�n hembras las cuales no estar�n esterilizadas. Transcurrido un a�o,
la hembra original tendr� otros 16 cachorros y sus 8 primeras descendientes repetir�n el patr�n y tendr�n cada una otros
16 cachorros, haciendo un total de (8 x 16 =128) + 16=144.  al cabo de 5 a�os los descendientes de los descendientes
habr�n procreado 74899 caninos.  Esta progresi�n se verifica en la siguiente relaci�n:

1 a�o: 16
2 a�o: 16 +128 =144
3 a�o: 16+128+ 1024 = 1168
4 a�o: 16+128+1024+8192=9360
5 a�o: 16+128+1024+8192+65536=74899

Tabla 1.
Dise�e e implemente un programa basado en funciones recursivas que calculen la cantidad de perros que nacer�n en un
per�odo determinado. El usuario debe proporcionar el tama�o de la camada y la cantidad de a�os que se desea calcular.
En la tabla 1, la cantidad de cachorros es 16 y la proyecci�n se realiz� a 5 a�os.

-No se aceptar�n pr�cticas sin recursividad.
-Lenguaje C/Java -
-El usuario debe proporcionar el tama�o de la camada
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

//Funci�n recursiva que cuenta la cantidad de nacimientos en un periodo de tiempo
int contarDescendientes(int cantidad, int total, int anios, int impresion[],int indice) {

    impresion[indice] = total; //Guarda los valores en un vector s�lo para la impresi�n
    printf("\n A%cos: %d, Total: %d",164, indice+1,sumarValores(impresion,indice));  //Impresi�n de valores

    if (anios>1)
        return total + contarDescendientes(cantidad,(total/2*cantidad),anios-1,impresion,indice+1);
    else
        return total;
}

/* Funci�n recursiva sin la impresi�n del proceso

int contarDescendientes(int cantidad, int anios) {
    if (anios>1)
        return (cantidad +(cantidad/2)*contarDescendientes(cantidad,anios-1));
    else
        return cantidad;
}

*/

//Funci�n que sirve para validar si el dato ingresado es un n�mero
int esNumero(char * cadena) {
    int i, siNumero=1;

    for(i=0; i<strlen(cadena); i++){
        if(!(cadena[i]>='0' && cadena[i]<='9'))
           siNumero =0;
    }
    return siNumero;
}

//Funci�n que captura un n�mero
int capturarNumero() {
    char cadena[15];

    gets(cadena);
    while(!esNumero(cadena)) {
        printf("\n Ingrese un n%cmero v%clido: ",163,160);
        gets(cadena);
    }

    return atoi(cadena);
}

//Funci�n que ayuda a sumar los valores para la impresi�n de los valores
int sumarValores(int vector[],int tamanio) {
    int i=0,total=0;

    while(i<=tamanio)
        total+= vector[i++];

    return total;
}
