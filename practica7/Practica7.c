/*
Elaborado por Reyes Udasco Rachelle Nerie
Práctica No. 7 Estructuras FIFO Dinámicas
24 de octubre del 2018
Grupo 551
Algoritmos y Estructura de Datos

Competencia: Generar aplicaciones de software en las que se aplique adecuadamente el principio FIFO y el concepto
de memoria dinámica para solucionar problemas de manejo de información, de manera responsable y eficiente.

Una compañía dedicada a la venta de celulares desea agradecer su preferencia a sus clientes haciéndoles regalos
que van desde recargas desde 50 pesos hasta el celular que el cliente escoja del inventario. Los clientes se han
registrado a través de una página y se ha generado una lista a partir del registro. La compañía le ha pedido que
diseñe e implemente una aplicación basada en el principio FIFO para seleccionar al cliente ganador. El algoritmo
que debe implementar es el siguiente:

Utilizando un número K aleatorio, se recorre K clientes, el K-ésimo cliente será eliminado de la cola con un premio
de consolación de $50 TA. Este proceso se repite las veces que sea necesario, en cada vuelta completa el premio de
consolación se incrementa en $50, hasta que queda solo el cliente ganador.  Por ejemplo, si los clientes son y K es 2.

Se pide que su programa tenga las siguientes opciones:
1) Agregar cliente a la lista.
2) Hacer sorteo

- La opción hacer sorteo debe mostrar el orden de eliminación.
- Puede utilizar y modificar todas las funciones vistas en clase.
- Si se terminan los clientes antes de completar K, debe continuar el conteo con el primer cliente.
- No se pide que utilice listas dobles ni circulares.
- La opción hacer sorteo debe mostrar el nombre de los cliente eliminados
- Los clientes serán ingresados por el usuario.
- El valor de K es un número aleatorio entre  1 y  5
- El valor de K puede variar en cada sorteo.
- Una vez que inicia el sorteo no puede agregar clientes.
- La cantidad de clientes es ilimitada
- Lenguaje C o Java.
- Debe utilizar una cola dinámica.
*/

//Delcaración de bibliotecas
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include <time.h>
#define MAX 50

//Estructura Nodo
struct nodo{
    char dato[MAX];
    struct nodo * sig;
};

//Prototipo de funciones
struct nodo* crearNodo(char dato[]);
struct nodo* insertar(struct nodo *inicio, char dato[]);
void mostrar(struct nodo* inicio);
struct nodo* borrar(struct nodo *inicio,char dato[]);
struct nodo* sorteo(struct nodo* inicio);

//Función principal del programa
int main() {
    struct nodo * inicio=NULL;
    char op, nombre[MAX];

   do {
        system("cls||clear");
        printf("\n=============MENU==============");
        printf("\n1) Agregar cliente a la lista");
        printf("\n2) Hacer sorteo");
        printf("\n3) Salida");
        printf("\nOpcion: ");
        op = getche();

        system("cls||clear");
        switch(op) {
            case '1':
                do {  //Ciclo que captura el nombre
                    printf("\nCaptura un nombre: ");
                    gets(nombre);
                }while(nombre[0]=='\x0');

                if(!inicio) //Comparación para ingresar el dato en la cola
                    inicio = crearNodo(nombre);
                else
                    inicio = insertar(inicio,nombre);
            break;
            case '2':
                if(inicio) {//Comparación si hay nombres en la lista
                    inicio = sorteo(inicio);
                    printf("\n\n El ganador es: %s",inicio->dato);
                }
                else
                    printf("\nNo hay nombres en la lista");
                getch();
                inicio = NULL;
            break;
            case '3':
            break;
        }
    }while(op!='3');
    return 0;
}

//Función que crea el nodo
struct nodo* crearNodo(char dato[]) {
    struct nodo * p;

    p=(struct nodo*) malloc(sizeof (struct nodo) );
    strcpy(p->dato,dato);
    p->sig=NULL;

    return(p);
}

//Función que inserta un dato a la cola
struct nodo* insertar(struct nodo *inicio, char dato[]) {
    struct nodo * p,* nuevo, *q;

    nuevo=crearNodo(dato);
    p=inicio;

    while(p!=NULL){
        q=p;
        p=p->sig;
    }
    q->sig=nuevo;

    return(inicio);
}

//Procedimiento que muestra los datos de la cola
void mostrar(struct nodo* inicio){
    struct nodo *aux;
    if (!inicio)
        printf("Vacia");
    else {
        aux=inicio;
        do{
            printf("| %s |", aux->dato);
            aux=aux->sig;
        }while(aux);
    }
    getch();
}

//Función que borra un dato de la cola
struct nodo* borrar(struct nodo *inicio,char dato[]){
    struct nodo *p, *q=NULL;
    p=inicio;

    while(p->dato!=dato && p!=NULL){
        q=p;
        p=p->sig;
    }
    if(q==NULL) {
        inicio=p->sig;
        free(p);
    }
    else
    if(p!=NULL) {
        q->sig=p->sig;
        free(p);
    }
    return inicio;
}

//Función que realiza el sorteo de los nombres
struct nodo* sorteo(struct nodo* inicio) {
    struct nodo *aux;
    srand(time(NULL));
    int i=1,k= 1+rand()%5, premio=50;
    printf("K: %d\n",k);

    if (!inicio)
        printf("Vacia");
    else {
        aux=inicio;
        mostrar(inicio);
        do{
            i++;
            if(!aux->sig) { //Comparación para dar la vuelta a la lista
                aux = inicio;
                premio+= 50;
            }else
                if(k==1)
                aux = inicio;
            else
                aux=aux->sig;

            if(i==k || k==1) { //Comparación para encontrar el nombre que sera borrado
               printf("\n\nEliminado: %s  Premio: %d\n",aux->dato,premio);
               inicio = borrar(inicio,aux->dato); //Borrado de dato
               mostrar(inicio);
               printf("\n");
               i=0;
            }
        }while(aux && inicio->sig);
    }
    return inicio;
}
