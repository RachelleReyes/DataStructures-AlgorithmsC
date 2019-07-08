/*
Elaborado por Reyes Udasco Rachelle Nerie
Pr�ctica No. 4 Estructuras LIFO
29 de septiembre del 2018
Grupo 551
Algoritmos y Estructura de Datos

Competencia. Aplicar eficientemente el principio LIFO para generar soluciones creativas a problemas
de ingenier�a, optimizando el uso de los recursos de manera responsable, preservando la integridad de los datos.

La conversi�n de un n�mero en base decimal a base binaria se lleva a cabo dividiendo el n�mero entre 2 n veces
hasta que ya no se pueda dividir, el n�mero en binario est� formado por todos los residuos de las divisiones, el
d�gito m�s significativo es el �ltimo residuo obtenido mientras que el d�gito menos significativo es el residuo
de la primera divisi�n realizada. Por ejemplo, si el usuario desea convertir el n�mero 60 a	binario, se	realizan
las operaciones siguientes,	el primer 0 es el �ltimo d�gito del resultado mientras que el residuo de la �ltima
divisi�n es el primer d�gito del resultado, de manera que el equivalente en binario de 60 es 111100.

Se pide que implemente un programa basado en el principio LIFO que lea un n�mero entero en base 10 y lo convierta
a una cadena que contenga su equivalente binario.
- No debe utilizar funciones para invertir cadenas.
- Debe aplicar el principio LIFO.
- Puede utilizar memoria din�mica o est�tica.
- Debe considerar todo el rango de los n�meros enteros.
- El lenguaje puede ser C o Java.
- Debe implementar las funciones pop y push.
- No se	pide que muestre las divisiones de la figura.
- El resultado debe quedar en una variable, no solo en pantalla
*/

//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>
#include <string.h>
#include <conio.h>

//Estructura Pila
struct Nodo {
    char dato;
    struct Nodo *anterior;
};

//Prototipo de funciones
int vacia(struct Nodo *);
void push(char, struct Nodo **);
char pop(struct Nodo **);
int esNumero(char *);
void insertarDatos(int, struct Nodo **);
void removerDatos(struct Nodo **, char *);
void imprimirBinario(char *);

//Funci�n principal del programa
int main() {
    struct Nodo * pila=NULL;
    char resp, numero[40], maxNum[11]={0}, binario[32]={0}; //maxNum(variable para el n�mero m�ximo de int), binario (n�mero binario convertido)
    int max = INT_MAX, i=0;

    itoa(INT_MAX, maxNum,10); //Convierte el valor del m�ximo entero en una cadena
    maxNum[10] = '\x0';

    do{
        system("cls||clear");
        printf("\n Ingrese un n%cmero para convertir: ",163);
        gets(numero);

        if (atof(numero)<=INT_MAX && esNumero(numero) ) { //Validaci�n del n�mero
            insertarDatos(atoi(numero),&pila); //Inserta la representacion binaria en la pila
            removerDatos(&pila, binario); //Quita los elementos de la pila y los guarda en una variable
            printf("\n Decimal: %s", numero);
            printf("\n Binario: ");
            imprimirBinario(binario);
        } else printf("\n N%cmero inv%clido",163,160);

        printf("\n\n Deseas ingresar otro n%cmero? (s/n): ",163);
        resp = getche();
    }while(tolower(resp)=='s');

    return 0;
}

//Funci�n que indica si la pila esta vac�a
int vacia(struct Nodo *cima) {
    if(!cima)return 1;
        else return 0;
}

//Procedimiento que inserta un dato en la pila
void push(char dato, struct Nodo **cima ){
    struct Nodo * tempo;
    tempo= (struct Nodo *) malloc(sizeof(struct Nodo));
    tempo->dato=dato;
    if(*cima==NULL) tempo->anterior=NULL;
    else tempo->anterior=*cima;
    *cima=tempo;
}

//Funci�n que saca el elemento que se encuentra en el tope de la pila
char pop(struct Nodo ** cima){
    struct Nodo *tempo;
    char regresa;
    tempo=*cima;
    regresa=(*cima)->dato;
    *cima=(*cima)->anterior;
    free(tempo);
    return (regresa);
}

//Funci�n que sirve para validar si el dato ingresado es un n�mero
int esNumero(char * cadena) {
    int i=0, siNumero=1;

    while(cadena[i]!='\x0') {
        if(!(cadena[i]>='0' && cadena[i]<='9')) siNumero =0;
        i++;
    }
    return siNumero;
}

//Procedimiento  que inserta los residuos del m�dulo del n�mero en la pila
void insertarDatos(int numero, struct Nodo **cima) {
    int residuo;
    char dato;

    if(numero==0) {
        push('0', cima);
    }
    else {
        while (numero>0) {
            residuo = numero%2;
            dato = residuo + '0';
            push(dato, cima);
            numero = numero/2;
        }
    }
}

//Procedimiento que quita todos los datos de la pila
void removerDatos(struct Nodo **cima, char * binario) {
   char dato;
   int i=0;

    while(!vacia(*cima)) {
        dato=pop(cima);
        binario[i++] = dato;
    }
    binario[i] = '\x0';
}

//Procedimiento que imprime el n�mero binario en grupos de cuatro para facilitar la lectura al usuario
void imprimirBinario(char * datos) {
   int i =0, primero, espacio=0;
   primero = strlen(datos)%4;

    while(datos[i]!='\x0') {
        if(i == primero || espacio ==3) {
            printf(" ");
            espacio=0;
        } else espacio++;
        printf("%c", datos[i++]);
    }
}
