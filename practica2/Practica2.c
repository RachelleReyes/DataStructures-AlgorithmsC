/*
Elaborado por Reyes Udasco Rachelle Nerie
Práctica No.2 Estructuras de datos y el principio LIFO
19 de septiembre del 2018
Grupo 551
Algoritmos y Estructura de Datos

Competencia: Implementar soluciones de software creativas utilizando eficientemente las estructuras estáticas y el principio LIFO.

Se pide diseñar e implementar un algoritmo basado en pilas estáticas que reciba una expresión dada por el usuario y evalúe si la
expresión se lee de igual manera de izquierda a derecha que de derecha a izquierda.  Por ejemplo, si la frase que proporciona el
usuario es: "La ruta natural”, el programa debe arrojar como resultado:

Comparando L con l.
Comparando a con a.
Comparando r con r.
Comparando u con u.
Comparando t con t.
Comparando a con a.
Comparando n con a.
Comparando a con a.
Comparando t con t.
Comparando u con u.
Comparando r con r.
Comparando a con a.
Comparando l con L.

Todos los caracteres son iguales, la frase se lee igual en ambos sentidos.

Requisitos
-La frase debe empezar a evaluarse después de haber sido capturada.
-La frase proporcionada por el usuario puede incluir espacios, letras y números.
-Al comparar se deben considerar iguales las mayúsculas y las minúsculas.
-El algoritmo debe ignorar los espacios al evaluar la frase.
-La frase debe ser evaluada utilizando el principio LIFO.
-El programa debe presentar cada pareja de caracteres que se esté comparando durante el proceso de evaluación de la expresión.
-Las expresiones deben tener al menos un carácter.
-El tamaño máximo de la expresión será preestablecido por el programador, pero el usuario podrá introducir expresiones de menor tamaño.
-El lenguaje de programación a utilizar es libre, C o Java.
-El programa debe repetirse N veces, hasta que el usuario elija la opción de salida.
*/

//Bibliotecas
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>
#define max 50  //Tamaño máximo de la frase

//Estructura Pila
struct Pila {
    int tope;
    char dato[max];
};

//Prototipo de funciones
void push (struct Pila *, char);
char pop (struct Pila *);
int esFraseValida(char []);
void insertarFrase(struct Pila *, char []);
void comparar(struct Pila *, char []);

//Procedimiento para insertar un elemento en la pila
void push (struct Pila * pila, char dato) {
    pila->dato[pila->tope++]= dato;
}

//Función para obtener el dato en el tope de la pila
char pop (struct Pila * pila) {
    return(pila->dato[--pila->tope]);
}

//Procedimiento para insertar una cadena en la pila
void insertarFrase(struct Pila * pila, char cadena[]) {
    int i=0;
    do {
        push(pila,cadena[i]);
        i++;
    }while(cadena[i]!='\x0');
}

//Función que valida el tamaño de la frase
int esFraseValida(char cadena[]) {
   int i=0, valida = 1;
    do {
        if(!isalnum(cadena[i]) && !isspace(cadena[i])) valida =0;
        i++;
    }while (cadena[i]!='\x0');
    if(i>0 && i<=max && valida ==1) return 1;
        else return 0;
}

//Función que sirve para comparar los datos de la pila y de la cadena
void comparar(struct Pila * pila, char cadena[]) {
   int i=0, tamanio=0, palindrome =0;
   char auxPila,auxCadena; // Variables auxiliares para los datos de la pila y cadena

    do {   //Ciclo que recorre la cadena y los datos de la pila
        auxPila = pop(pila);
        auxCadena = cadena[i];

        while(isspace(auxPila)) {
            auxPila = pop(pila); //Saca otro elemento de la pila si el dato es un espacio
        }
        while(isspace(auxCadena)) {
            i++;
            auxCadena = cadena[i]; //Elige el siguiente dato del arreglo si aparece un espacio
        }
        printf("\nComparando %c con %c",auxCadena,auxPila);

        if(isalpha(auxPila)) auxPila = toupper(auxPila);
        if(isalpha(auxCadena)) auxCadena = toupper(auxCadena);

        if(auxPila==auxCadena) { //Comparación de los dos datos
            printf(": son iguales");
            palindrome++;
        }
        else printf(": no son iguales");
        tamanio++; //Tamaño de la cadena sin espacios
        i++; //Contador que recorre la cadena

    }while(pila->tope>0);
    if(palindrome == tamanio) {printf("\n\nEs pal%cndromo\n",161);}
    else printf("\n\nNo es pal%cndromo\n",161);
}

//Función Principal
int main() {
    struct Pila pila={0};
    char cadena[max], resp; //resp: respuesta del usuario

    do {  //Ciclo que se encarga de pedir la frase del usuario
        printf("\nIngrese la frase: ");
        gets(cadena);
        if(esFraseValida(cadena)) { //Validación de la frase
            insertarFrase(&pila,cadena);
            comparar(&pila,cadena);
        }
        else {
            printf("Frase no v%clida. Tiene que ser de 1 a %d caracteres, que s%clo incluye espacios, letras y n%cmeros",160,max,162,163);
        }
        printf("\nQuieres ingresar otra frase? (s/n): ");
        resp = getche();
    }while(tolower(resp)=='s');

    return 0;
}
