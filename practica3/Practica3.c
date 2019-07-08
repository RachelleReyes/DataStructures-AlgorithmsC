/*
Elaborado por Reyes Udasco Rachelle Nerie
Práctica No.3 Estructuras LIFO Dinámicas
25 de septiembre del 2018
Grupo 551
Algoritmos y Estructura de Datos

Competencia.
Aplicar	eficientemente el principio	LIFO para generar soluciones creativas a problemas de ingeniería,
optimizando	el uso de los recursos de manera responsable, preservando la integridad de los datos.

Un método simple para encriptar mensajes, aunque no muy eficiente, consiste en colocar paréntesis de
manera arbitraria dentro de la frase original, y todo lo que esté dentro de un par de paréntesis, escribirlo
al revés, por ejemplo, la frase “Ingeniería en Computación” se puede encriptar como “Ingenier(ai) en C(upmo)tación”.

Diseñe e implemente un algoritmo basado en el principio LIFO, que lea de teclado una frase ya encriptada y obtenga
el mensaje desencriptado. Si el usuario introduce la frase “Algorit(som) y Estruc(sarut) de Datos” el programa debe
mostrar las operaciones (push pop) que está realizando:

Algorit
(
 ***push s
 ***push o
 ***push m
)
pop()
Algoritm
pop()
Algoritmo
pop()
Algoritmos
Algoritmos y Estruc
(
***push	s
***push	a
***push	r
***push	u
***push	t
)
Pop()
Algoritmos y Estruct
Pop()
Algoritmos y Estructu
Pop()
Algoritmos y Estructur
Pop()
Algoritmos y Estructura
Pop()
Algoritmos y Estructuras
Algoritmos	y Estructuras de Dato
la frase desencriptada es: “Algoritmos y Estructuras de Datos”

• El programa debe mostrar el estado de la pila durante	el proceso de evaluación del mensaje
• EL mensaje que introduzca el usuario debe estar YA encriptado. No se pide que elabore la función de encriptación.
• La frase debe ser evaluada una vez que haya sido capturada.
• El tamaño del	mensaje debe ser ilimitado.
• El lenguaje de programación a utilizar es C.
• Evite utilizar variables globales.
• El programa debe organizado en funciones.
• Debe respetar	el principio LIFO.
• Push y pop solo hacen las operaciones de meter y sacar datos de la pila
*/

//Bibliotecas
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>

//Estructura Pila
struct Nodo {
    char dato;
    struct Nodo *anterior;
};

//Prototipo de funciones
int vacia(struct Nodo *);
struct Nodo * crearNodo(char);
struct Nodo* push(struct Nodo *,char);
struct Nodo* pop(struct Nodo *, char* );
int validarParentesis(char *);
void capturarMensaje(char * , int *);
void imprimirCadena(char *, int longitud);
void desencriptar(struct Nodo *, char *, char *,int ,int*, int *);

//Función principal del programa
int main() {
    struct Nodo *tope=NULL;
    int i=0, j=0, parentesis =0, caracteres=0, tamanio=0;
    char dato,* mensaje,*auxiliar;

    mensaje = (char *) malloc(sizeof(char));
    printf("\nIngrese un mensaje encriptado: ");
    capturarMensaje(mensaje, &tamanio);
    auxiliar = (char *) malloc(tamanio*sizeof(char));

    /*Evaluación del mensaje encriptado*/
    while(mensaje[i]!='\x0') {
        if(mensaje[i] == '(' && validarParentesis(mensaje)) {
            desencriptar(tope, mensaje, auxiliar, i, &caracteres, &parentesis);
            parentesis = parentesis +2;
            i = i + caracteres +2;
            j+= caracteres;
        } else {
            *(auxiliar+j) = mensaje[i];
            imprimirCadena(auxiliar,j);
            i++;
            j++;
        }
    }
    auxiliar[j] = '\x0';

    /*Impresión del mensaje encriptado y desencriptado*/
    printf("\nMensaje: ");
    imprimirCadena(mensaje,i);
    printf("\nMensaje desencriptado: ");
    imprimirCadena(auxiliar,j);

    free(mensaje);
    free(auxiliar);
    return 0;
}

//Función que indica si la pila esta vacía
int vacia(struct Nodo *tope) {
    if(!tope)return 1;
        else return 0;
}

//Función que crea un nodo en la pila
struct Nodo * crearNodo(char dato) {
    struct Nodo* nodo;
    nodo=(struct Nodo*)malloc (sizeof (nodo));
    nodo->dato=dato;
    nodo->anterior=NULL;
    return(nodo);
}

//Función que inserta un dato en la pila
struct Nodo* push(struct Nodo * tope,char dato) {
    struct Nodo *auxiliar;
    auxiliar=crearNodo(dato);
    auxiliar->anterior=tope;
    tope=auxiliar;
    return(tope);
}

//Función que saca el elemento que se encuentra en el tope de la pila
struct Nodo* pop(struct Nodo *tope, char* valor) {
    struct Nodo *auxiliar;
    char dato;
    auxiliar=tope;
    *valor=tope->dato;
    tope=tope->anterior;
    free(auxiliar);
    return(tope);
}

//Función que valida si el mensaje contiene paréntesis que no se cierran
int validarParentesis(char *cadena) {
    int i=0, parentesis=0, activado=0;
    while(cadena[i]!='\x0') {
        if(cadena[i]=='(') {
            parentesis++;
            activado = 1;
        } else if(cadena[i]==')' && activado) {
                parentesis++;
                activado =0;
        }
        i++;
    }
    if(parentesis%2==0) return 1;
        else return 0;
}

//Procedimiento que captura el mensaje
void capturarMensaje(char * mensaje, int *tamanio){
    char dato;
    int i=0;

    while((dato = getchar()) != '\n') {
    *(mensaje+i) = dato;
     i++;
    }
    mensaje[i] = '\0';
    *tamanio = i;
}

//Procedimiento que imprime una cadena
void imprimirCadena(char *cadena, int longitud) {
    int i=0;
    do {
        printf("%c",cadena[i++]);
    }while(i<=longitud);
    printf("\n");
}

//Procedimiento que desencripta las partes del mensaje que se encuentra entre paréntesis
void desencriptar(struct Nodo *tope, char * mensaje, char * auxiliar, int posicionOriginal,int*caracteres, int *parentesis) {
    int i,caracteresPila, aux=0;
    i= posicionOriginal+1;
    printf("(");

    //Mete los datos en la pila
    while(mensaje[i]!=')' && mensaje[i]!='\n') {
        if(tope==NULL) tope=crearNodo(mensaje[i]);
        else tope = push(tope,mensaje[i]);
        printf("\n ***push %c",mensaje[i]);
        i++;
    }

    printf("\n)\n");
    caracteresPila = i- posicionOriginal-1;
    *caracteres = caracteresPila;
    aux = posicionOriginal - *parentesis;

    //Saca los datos de la pila
    while(caracteresPila>0) {
        printf("Pop()");
        tope=pop(tope,(auxiliar+(aux++)));
        caracteresPila--;
        printf("\n");
        imprimirCadena(auxiliar,aux-1);
    }
}
