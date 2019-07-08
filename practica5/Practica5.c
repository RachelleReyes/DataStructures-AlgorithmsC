/*
Elaborado por Reyes Udasco Rachelle Nerie
Práctica No.5 Estructuras FIFO Estáticas
7 de octubre del 2018
Grupo 551
Algoritmos y Estructura de Datos

Competencia: Implementar soluciones de software utilizando eficientemente el principio FIFO en las estructuras estáticas

Un dispositivo reproductor de canciones tiene capacidad para una cantidad limitada de canciones,
se le pide implementar un programa basado en el principio FIFO para administrar las canciones de la lista.
Se desea que la aplicación cuente con las siguientes opciones:

1) Agregar una canción a la lista
2) Remover  canción
3) Reproducir lista completa. 
4) Salida

Por cada canción se registra la siguiente información:
-Intérprete
-título
-duración

Requisitos

-Por cada opción debe haber al menos una función.
-La cantidad de canciones está limitada por el programador
-Las canciones se agregan solo al final de la lista.
-Las canciones se pueden remover solo del inicio de la lista.
-La reproducción de una lista debe simular que la canción se está ejecutando.
-La reproducción de la canción se puede simular presentando el título en pantalla y el tiempo transcurrido.
-Durante la simulación debe mostrarse el tiempo que dura y el tiempo que ha transcurrido.
-Durante la simulación no debe estar activa ninguna otra operación.
-El programa puede ser en cualquier lenguaje C o Java.
-Envíe mensajes adecuados cuando se requiera, por ejemplo:” No hay canciones”, “NO hay espacio en la lista”
*/

//Bibliotecas
#include<stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<time.h>
#include<string.h>
#define MAX 30
#define MAXCADENA 50

//Estructura Duración de la canción
struct Duracion {
    int minuto,segundo;
};

//Estructura de la canción
struct Cancion {
    char interprete[MAXCADENA];
    char titulo[MAXCADENA];
    struct Duracion duracion;
};

//Estructura de la cola
struct Cola {
    struct Cancion cancionCola[MAX];
    int inicio,fin;
};

//Prototipo de funciones
void crearCola(struct Cola * q);
int llena(struct Cola q);
int vacia(struct Cola q);
void insertar(struct Cola *q, struct Cancion cancion);
struct Cancion remover (struct Cola *q);
void capturarCancion(struct Cancion * cancion);
void imprimirCancion(struct Cancion cancion);
void mostrarPlaylist(struct Cola q);

//Función principal
int main() {
    struct Cancion cancion;
    struct Cola cola;
    char op;
    crearCola(&cola);

    do {
        system("cls||clear");
        printf("\n=============PLAYLIST=============");
        printf("\n1) Agregar una canci%cn a la lista",162);
        printf("\n2) Remover canci%cn",162);
        printf("\n3) Reproducir lista completa");
        printf("\n4) Salida");
        printf("\nOpcion: ");
        op = getche();

        system("cls||clear");
        switch(op) {
            case '1':
                if(!llena(cola)) {
                   capturarCancion(&cancion);
                   insertar(&cola,cancion);
                }
                else {
                    printf("\nNo hay espacios en la lista");
                    getche();
                }
            break;
            case '2':
                if(!vacia(cola)) {
                     imprimirCancion(remover(&cola));
                    printf("\nCanci%cn extraida",162);
                }
                else
                    printf("\nNo hay canciones en la lista");
                getche();
            break;
            case '3':
                if(!vacia(cola))
                    mostrarPlaylist(cola);
                else
                    printf("\nNo hay canciones en la lista");
                getche();
            break;
            case '4':
            break;
        }
    }while(op!='4');
    return 0;
}

//Procedimiento para crear la cola
void crearCola(struct Cola * q) {
    q->inicio = -1;
    q->fin = 0;
}

//Función para saber si la cola está llena
int llena(struct Cola q) {
    if (q.fin==MAX)
        return 1;
    return 0;
}

//Función para saber si la cola está vacía
int vacia(struct Cola q) {
    if(q.fin==0)
        return 1;
    return 0;
}

//Procedimiento para insertar una canción a la cola
void insertar(struct Cola *q, struct Cancion cancion) {
    q->cancionCola[q->fin] = cancion;
    q->fin++;
}

//Función para remover una canción de la cola
struct Cancion remover (struct Cola *q) {
    struct Cancion cancion;
    int i;

    cancion = q->cancionCola[0];
    for(i=0; i<q->fin-1;i++)
        q->cancionCola[i] = q->cancionCola[i+1];
    q->fin--;
    return cancion;
};

//Función que sirve para validar si el dato ingresado es un número
int esNumero(char * cadena) {
    int i, siNumero=1;

    //Ciclo for que valida cada caracter de la cadena
    for(i=0; i<strlen(cadena); i++){
        if(!(cadena[i]>='0' && cadena[i]<='9'))
           siNumero =0;
    }
    return siNumero;
}

//Función que sirve para validar el rango de un número
int rangoNumero(int numero, int min, int max) {
    if(numero>=min && numero<=max)//Comparación si un número se encuentra dentro del rango
        return 1;
    else
        return 0;
}

//Procedimiento que captura el mensaje
void capturarCadena(char mensaje []){
    char dato;
    int i=0, invalido;

    dato = getchar();
    while(dato =='\n' && i==0)
        dato = getchar();

    mensaje[i++] =dato;
    while((dato = getchar()) != '\n' && i<=MAXCADENA)
        mensaje[i++] = dato;

    mensaje[i] = '\x0';
}

//Función que valida el tiempo
int validarTiempo(char cadena[]){
    if(esNumero(cadena)) {
        if(rangoNumero(atoi(cadena),0,59))
            return 1;
    }
    return 0;
}

//Procedimiento para capturar la canción
void capturarCancion(struct Cancion * cancion) {
    char numeroIngresado[10];

    printf("\n\nInt%crprete: ",130);
    capturarCadena(cancion->interprete);

    printf("\nT%ctulo: ",161);
    capturarCadena(cancion->titulo);

    printf("\nDuraci%cn",162);
    do { //Ciclo que captura y valida la cantidad de minutos ingresado
        printf("\nMinutos: ");
        capturarCadena(numeroIngresado);
        if(validarTiempo(numeroIngresado))
            cancion->duracion.minuto = atoi(numeroIngresado);
        else
            printf("\n N%cmero inv%clido",163,160);
    }while(!validarTiempo(numeroIngresado));

    do { //Ciclo que captura y valida la cantidad de segundos ingresado
        printf("\nSegundos: ");
        capturarCadena(numeroIngresado);
        if(validarTiempo(numeroIngresado))
            cancion->duracion.segundo = atoi(numeroIngresado);
        else
            printf("\n N%cmero inv%clido",163,160);
    }while(!validarTiempo(numeroIngresado));
}

//Procedimiento para imprimir la canción
void imprimirCancion(struct Cancion cancion) {
    printf("\n\nInt%crprete: %s",130,cancion.interprete);
    printf("\nT%ctulo: %s",161,cancion.titulo);
    printf("\nDuraci%cn: %d:%d",162,cancion.duracion.minuto, cancion.duracion.segundo);
}

//Procedimiento que muestra el Playlist
void mostrarPlaylist(struct Cola q) {
    struct Cola aux;
    struct Cancion cancion;
    int i=0, tiempoTotal =0,tiempoTranscurrido=0,auxTiempo=0;
    clock_t inicio,fin;

    do{ //Ciclo que simula el playlist mostrando las canciones
        tiempoTotal = q.cancionCola[i].duracion.segundo+q.cancionCola[i].duracion.minuto*60;
        inicio = clock();
        tiempoTranscurrido = 0;
        auxTiempo = 0;

       while(tiempoTranscurrido<tiempoTotal) {
            fin = clock();
            tiempoTranscurrido= ((fin-inicio)/CLOCKS_PER_SEC);

            if(tiempoTranscurrido==(auxTiempo+1)){
                system("cls||clear");
                imprimirCancion(q.cancionCola[i]);
                printf("\nTiempo Transcurrido: %d:%d",tiempoTranscurrido/60,tiempoTranscurrido-60*(tiempoTranscurrido/60));
                auxTiempo++;
            }
        }
        i++;
    }while(i<(q.fin));
}
