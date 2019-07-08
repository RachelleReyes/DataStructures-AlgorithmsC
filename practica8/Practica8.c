/*
Elaborado por Reyes Udasco Rachelle Nerie
Práctica No. 8 Listas Enlazadas
30 de octubre del 2018
Grupo 551
Algoritmos y Estructura de Datos

Competencia: El alumno creará programas que resuelvan problemas utilizando como estructura
de datos principal la lista dinámica.

Una pantalla de leds que presenta mensajes de texto en forma continua, almacena las palabras
en una lista enlazada

Se desea elaborar un simulador cuente con las siguientes opciones:

1) Agregar una palabra al final del mensaje.
2) Insertar una palabra en el mensaje.
3) Eliminar una palabra
4) Reproducir mensaje

 -La aplicación debe ser desarrollada en lenguaje C o Java
 -La estructura de datos que se va a usar es libre.
 -La opción 1 agrega solo UNA palabra al final de la lista
 -La opción 2 inserta una palabra en el lugar que el usuario decida.
 -El usuario debe indicar la palabra después de la cual se va a insertar.
 -Si la palabra que eligió no existe, entonces no se realiza la inserción.
 -La opción eliminar borra la palabra que el usuario escriba.
 -En la opción eliminar, si la palabra aparece más de una vez en el mensaje, solo borra la primera.
 -La reproducción de la lista no elimina palabras.
 -El formato de reproducción del mensaje es libre.
 -Cada módulo estará implementado en una o más funciones o métodos.
 -En cada caso envíe mensajes apropiados para orientar al usuario. No se encontró, etc
*/

//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include<windows.h>

#define forg 14 //Color de las letras
#define back 0 //Color del fondo
#define MAX 50 //Cantidad maxima de cadena
#define horizontal 35 //Coordenada en x
#define vertical 4 //Coordenada en y

//Prototipo de funciones para la parte grafica
void gotoxy(int x,int y);
void pintaCadena (int x, int y, int frente, int fondo, char opcion [] );
void pintaMenu(int x, int y, int frente, int fondo, int n, char opciones[][MAX]);
void setColorAndBackground(int ForgC, int BackC);
int menu(int x, int y, int frente, int fondo, int n, char [][MAX]);
void delay(unsigned int mseconds);

//Prototipo de funciones para la lista
void capturar(char palabra[], char cadena[]);
struct nodo * crearNodo(char dato[]);
struct nodo* insertarAlFinal(struct nodo *inicio,char dato[]);
struct nodo* insertarEnMedio(struct nodo *inicio, char datoAnterior[],char datoNuevo[]);
void mostrar(struct nodo *inicio);
struct nodo* eliminar(struct nodo *inicio,char dato[]);

//Estructura de la lista enlazada
struct nodo{
    char dato[MAX];
    struct nodo * ant;
    struct nodo * sig;
};

//Funcion principal del programa
int main(){
    char opciones[5][MAX]= {"Agregar una palabra al final del mensaje","Insertar una palabra en el mensaje","Eliminar una palabra","Reproducir mensaje","Salir"};
    int opcion;
    opcion= menu(horizontal,vertical, forg, back, 5, opciones);
    return 0;
}

//Procedimiento que pinta una cadena
void pintaCadena (int x, int y, int frente, int fondo, char cadena [] ) {
    gotoxy(x,y);
    setColorAndBackground(frente,fondo);
    printf("%s", cadena);
}

//Procedimiento que pinta el menu
void pintaMenu(int x, int y, int frente, int fondo, int n, char opciones[][MAX]){
    int i;
    for (i=0;i<n;i++)
        pintaCadena(x,y+i, frente,fondo, opciones[i] );
}

//Procedimiento que se usa para imprimir en una coordenada especifica
 void gotoxy(int x,int y){
    COORD coord={0,0};
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
 }

//Procedimiento que se encarga de ajustar colores
 void setColorAndBackground(int ForgC, int BackC){
     WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);;
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
     return;
}

//Procedimiento que genera un retardo
void delay(unsigned int mseconds){
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

//Funcion que crea el nodo
struct nodo * crearNodo(char dato[]){
    struct nodo *p;
    p=(struct nodo*)malloc (sizeof (struct nodo));
    strcpy(p->dato,dato);
    p->sig=NULL;
    p->ant=NULL;
    return(p);
}

//Funcion que inserta el dato al final
struct nodo* insertarAlFinal(struct nodo *inicio,char dato[]){
    struct nodo *p, *q=NULL, *nuevo;
    p=inicio;
    nuevo=crearNodo(dato);

    while(p!=NULL){ //Ciclo que recorre la lista
        q=p;
        p=p->sig;
    }
    if (q==NULL){ //Comparacion si es el primer elemento
        nuevo->sig=p;
        p->ant=nuevo;
        inicio=nuevo;
    }else {
        q->sig=nuevo;
        nuevo->ant=q;
        nuevo->sig=p;
        if(p!=NULL)
            p->ant=nuevo;
    }
    return(inicio);
}

//Funcion que inserta un dato en la lista
struct nodo* insertarEnMedio(struct nodo *inicio, char datoAnterior[],char datoNuevo[]){
    struct nodo *p, *q=NULL, *nuevo;
    int banderaEncontrado=0;
    p=inicio;
    nuevo=crearNodo (datoNuevo);

    while(strcmpi(p->dato,datoAnterior)!=0 && p!=NULL){ //Ciclo que recorre la lista hasta encontrar el dato o llegar al final
        q=p;
        p=p->sig;
    }
    if(strcmpi(p->dato,datoAnterior)==0) { //Comparacion si se encontro el dato
        if(q==NULL){ //Primer elemento
            nuevo->ant = p;
            nuevo->sig = p->sig;
            p->sig = nuevo;
        }else if(p->sig==NULL){ //Si el dato se encuentra al final
            nuevo->ant = p;
            p->sig = nuevo;
        }else if(p!=NULL){ //Si el dato se encuentra en medio
            nuevo->ant = p;
            nuevo->sig = p->sig;
            p->sig = nuevo;
            nuevo->sig->ant = nuevo;
        }
    } else {
        system("cls||clear");
        pintaCadena(horizontal,vertical,forg,back,"No encontrado");
    }
    return inicio;
}

//Procedimiento que muestra la lista completa
void mostrar(struct nodo *inicio){
    struct nodo *aux;
    int x;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    x=csbi.srWindow.Right;

    system("cls||clear");
    if(!inicio)
        pintaCadena(horizontal,vertical,forg,back,"La lista esta vacia");
    else{
        printf("\n");
        while (!kbhit()) {
            aux=inicio;
            system("cls||clear");
            gotoxy(x,vertical);
            do{ //Ciclo que imprime las palabras de la lista
                printf("%s ",aux->dato);
                aux=aux->sig;
            }while(aux);
            delay(90);
            x--;;
            if(x<=0) //Condicion si llega al extremo derecho
                x=csbi.srWindow.Right;
        }
    }
    getch();
}

//Funcion que elimina una palabra de la lista
struct nodo* eliminar(struct nodo *inicio,char dato[]){
    struct nodo *p, *q=NULL;
    p=inicio;
    while(strcmpi(p->dato,dato)!=0 && p!=NULL){  //Ciclo que recorre la lista hasta encontrar la palabra o llegar al final
        q=p;
        p=p->sig;
    }
   if(strcmpi(p->dato,dato)==0){ //Si se encontro el dato en otro lugar
        if(q==NULL) { //Primer dato
            if(p->sig!=NULL){
                inicio=p->sig;
                inicio->ant=NULL;
            }else
                if(p->sig==NULL){
                    inicio=NULL;
            }
            free(p);
        }  else
        if(p->sig==NULL){ //Ultimo dato
            q->sig=NULL;
            free(p);
        }else
        if(p!=NULL){ //En medio
            q->sig=p->sig;
            p->sig->ant=q;
            free(p);
        }
    }else {
        system("cls||clear");
        pintaCadena(horizontal,vertical,forg,back,"No encontrado");
    }
    return inicio;
}

//Procedimiento que captura una cadena
void capturar(char palabra[], char cadena[]){
    system("cls||clear");
    gotoxy(horizontal,vertical);
     do {  //Ciclo que captura la palabra
          pintaCadena(horizontal,vertical,forg,back,cadena);
        scanf("%s",palabra);
    }while(palabra[0]=='\x0');

}

//Funcion que imprime el menu
int menu( int x, int y, int frente, int fondo, int n, char opciones [][MAX]){
    int actual=0;
    int salir=0;
    int tecla;
    struct nodo * inicio=NULL;
    char palabra[MAX],palabraAnterior[MAX];

    do {
        pintaCadena(x-4,y-3,15,0,"==================MENU PRINCIPAL==================");
        pintaCadena(x+4,y-2,15,0,"--------Elija una opcion--------");
        pintaMenu(x,y, frente,fondo,n,opciones);
        pintaCadena(x,y+actual, fondo, frente,opciones[actual] );
        tecla=getch();

        pintaCadena(x,y+actual, frente, fondo,opciones[actual] );

        if(tecla == 0 || tecla  == 224) {
            switch(getch()) {
                case 72:     actual --;
                             if (actual<0) actual=n-1;
                             break;
                case 80:     actual ++;
                             if (actual==n) actual=0;
                             break;
            }
        }

        if (tecla==13) {
            switch(actual) {
                case 0: //1) Agregar una palabra al final del mensaje.
                    capturar(palabra,"Ingrese una palabra: ");
                        if(!inicio)
                            inicio = crearNodo(palabra);
                        else
                            inicio = insertarAlFinal(inicio,palabra);
                        system("cls||clear");
                        pintaCadena(x,y,frente,fondo,"Palabra almacenada");
                        getch();
                        break;

                case 1: //2) Insertar una palabra en el mensaje.
                        if(inicio) {
                            capturar(palabra,"Ingrese una palabra: ");
                            capturar(palabraAnterior,"Despues de que palabra la deseas de ingresar: ");
                            system("cls||clear");
                            pintaCadena(x,y,frente,fondo,"Palabra almacenada");
                            inicio = insertarEnMedio(inicio,palabraAnterior,palabra);
                        }else {
                            system("cls||clear");
                            pintaCadena(x,y,frente,fondo,"No hay palabras en la lista");
                        }
                        getch();
                        break;

                case 2: //3) Eliminar una palabra
                        if(inicio) {
                            capturar(palabra,"Ingrese la palabra que deseas eliminar: ");
                            system("cls||clear");
                            pintaCadena(x,y,frente,fondo,"Palabra eliminada");
                            inicio = eliminar(inicio,palabra);
                        } else {
                            system("cls||clear");
                            pintaCadena(x,y,frente,fondo,"No hay palabras en la lista");
                        }
                         getch();
                        break;

                case 3: //4) Reproducir mensaje
                        mostrar(inicio);
                        break;

                case 4: salir =1;
                break;
            }
            system("cls||clear");
        }
       }while (tecla!=27 && salir==0);
    system("cls||clear");
    return 0;
}
