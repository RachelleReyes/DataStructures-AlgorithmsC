/*
Elaborado el Reyes Udasco Rachelle Nerie
Práctica No.1 Estructura de Datos

Competencia: Aplicar los conceptos de arreglos, y estructura de datos y apuntadores para proponer
soluciones eficientes para problemas de manejo de información

Utilizando arreglos de estructuras implemente un sistema para administrar la renta de
películas en un videoclub. Se pide que el sistema registre por cada servicio de
renta los siguientes datos:

    Nombre del cliente
    Título rentado
    Clasificación (Estreno, Catálogo, Adultos, etc.)
    Fecha de Renta

Se requiere que el sistema cuente con los siguientes módulos

1.) Renta. Máximo 3 películas por cliente
2.) Regresar películas
3.) Mostrar las rentas

Requisitos:
Evitar el uso de variables globales
Un cliente solo puede rentar una vez
En cada renta el cliente puede llevar hasta 3 películas
El cliente no puede rentar si ya tiene una renta registrada
La opción de renta solo registra un cliente a la vez, no llenta todo el arreglo
El tamaño del arreglo de rentas es de máximo 50.
Para regresar una película se debe proporcionar el nombre del cliente
La opción mostrar presenta todas las rentas con los datos que se hayan registrado

12 de septiembre del 2018, Grupo 551
Algoritmos y Estructura de Datos
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Estructura para una fecha*/
struct fecha {
    int dia;
    int mes;
    int anio;
};

/*Estructura para una pelicula*/
struct pelicula {
    char nombrePelicula[30];
    char clasificacion[30];
};

/*Registro de renta para un cliente*/
struct registro {
    char nombreCliente[50];
    int numPeliculasRentadas;
    struct pelicula peliculas[3];
    struct fecha fechaRenta;
};

/*Prototipos de función*/
int elegirOpcion(char[15], char [][30], int);
void rentar(struct registro *, int *);
void mostrarRentas(struct registro);
void regresarPeliculas(struct registro *, int *);
int buscarCliente(struct registro *, int, char *);
int rangoNumero(int,int, int);
int esNumero(char *);

/*Función principal*/
int main() {
    struct registro rentas[50];  //Arreglo de estructuras
    char menu[4][30] = {"Rentar una pelicula","Regresar peliculas","Mostrar las rentas","Salir"}; //Opciones del menú
    int opcion =0, clientes=0; //opcion: variable para la opción elegida del menú, clientes: número de clientes

    //Ciclo para el menú principal del programa
    do {
        opcion = elegirOpcion("\n=============MENU===============\n",menu,4);

        //Comparación de la opción elegida
        switch(opcion) {
            case 1: //Renta de películas
               if(clientes<=50) {
                    rentar(&rentas[0], &clientes);
               } else {
                   printf("Ya no hay espacio para m%cs registros",160);
               }
                break;
            case 2: //Regresar películas
                regresarPeliculas(&rentas[0], &clientes);
                break;
            case 3: //Mostrar todas las rentas
                for(int i=0;i<clientes;i++){
                     mostrarRentas(rentas[i]);
                }
                break;
            case 4: exit(1); //Salirse del programa
                break;
            default:
                printf("Selecci%cn inv%clida\n",162,160);
        }
    }while(opcion!=4);

    return 0;
}

/*Función para mostrar el menú y elegir una opción*/
//Recibe una cadena que sirve como letrero, y el arreglo de cadenas para las opciones del menú. Retorna un entero
int elegirOpcion(char letrero[15], char cadena [][30], int tamanio) {
    char datoIngresado[30]; //Dato que se ingresa
    int opcion,i,entradaInvalida=1; //opcion: opcion elegida del menú, i: contador, entradaInvalida: bandera que indica si se ingresó un valor no válido

    printf(letrero);
    printf("\nIngrese el n%cmero de la opci%cn: \n\n",163,162);

    //Imprime cada una de las opciones del menú
    for(i =0; i<tamanio;i++) {
        printf("(%d) %s\n",i+1,cadena[i]);
    }

    //Validación del dato de entrada para la opción elegida
    while(entradaInvalida==1) {
       scanf("%s",datoIngresado);
        if(esNumero(datoIngresado)) {
            opcion = atoi(datoIngresado);
            entradaInvalida =0;
        } else {
            printf("\nEntrada inv%clida. Elige otra opci%cn\n",160,162);
        }
    }
    return opcion;
}

/*Función que sirve para registrar un cliente */
//Recibe el arreglo de estructura de rentas. No retorna ningún valor.
void rentar(struct registro *rentas, int * clientes) {
    char clasificacion[4][30] = {"Estreno","Catlogo","Adultos","Otros"}; //Opciones para la clasificación de las películas
    char datoIngresado[30]; //Variable que recibe datos que se ingresan
    int clasif, esValido=0, entradaInvalida=1; //clasif: opcion elegida para la clasificación, esValido y entradaValida son banderas para los datos de entrada

    printf("Nombre del cliente: ");
    getchar();
    gets(datoIngresado); //Recibe el nombre del cliente

    //Compara si el registro ya existe
    if(buscarCliente(&rentas[0], *clientes,datoIngresado)==-1) {
    strcpy((rentas+(*clientes))->nombreCliente, datoIngresado);
    printf("Cantidad de pel%cculas que se van a rentar: ",161); //Pregunta la cantidad de películas

         //Valida el dato ingresado para la cantidad de películas
        while(entradaInvalida==1) {
           scanf("%s",datoIngresado);
            if(esNumero(datoIngresado)) {
                 if(rangoNumero(atoi(datoIngresado),1,3)) {
                    (rentas+(*clientes))->numPeliculasRentadas = atoi(datoIngresado);
                    entradaInvalida=0;
                  } else {
                       printf("S%clo se rentan entre 1 a 3 pel%cculas\n",162,161);
                  }
            } else {
                printf("\nEntrada inv%clida. Solo se aceptan n%cmeros\n",160,163);
            }
        }
        //Ciclo que se encarga de guardar el nombre de las películas con su respectiva clasificación
        for(int i=0;i<(rentas+(*clientes))->numPeliculasRentadas;i++){
            printf("Pel%ccula: ",161);
            getchar();
            gets((rentas+(*clientes))->peliculas[i].nombrePelicula);

            //Guarda los valores de la clasificación de las películas
            clasif = elegirOpcion("\nClasificacion", clasificacion,4);
            switch(clasif) {
                case 1: strcpy((rentas+(*clientes))->peliculas[i].clasificacion, clasificacion[0]);
                    break;
                case 2: strcpy((rentas+(*clientes))->peliculas[i].clasificacion, clasificacion[1]);
                    break;
                case 3: strcpy((rentas+(*clientes))->peliculas[i].clasificacion, clasificacion[2]);
                    break;
                case 4: printf("Escribe la clasificacion: ");
                    getchar();
                    gets(rentas->peliculas[i].clasificacion);
                    break;
                default: printf("\nOpci%cn inv%clida, Pel%ccula clasificada bajo Otros\n",162,160,161);
                    strcpy((rentas+(*clientes))->peliculas[i].clasificacion, clasificacion[3]);
                    break;
            }
        }

        /*Validaciones para ingresar la fecha*/
        printf("Fecha de renta(dd/mm/aaaa)\n");
        do {
            printf("D%ca: ",161);
            scanf("%s",datoIngresado);
            if(esNumero(datoIngresado)) {
            esValido = rangoNumero(atoi(datoIngresado),1,31); //Validación del día
                if(esValido) {
                     (rentas+(*clientes))->fechaRenta.dia =atoi(datoIngresado);
                }
            }
        }while(esValido==0);

        esValido =0;
        do {
            printf("Mes: ");
            scanf("%s",datoIngresado);
            if(esNumero(datoIngresado)) {
            esValido = rangoNumero(atoi(datoIngresado),1,12); //Validación del mes
                if(esValido) {
                     (rentas+(*clientes))->fechaRenta.mes = atoi(datoIngresado);
                }
            }
        }while(esValido==0);

        esValido =0;
        do {
            printf("A%co: ",164);
             scanf("%s",datoIngresado);
            if(esNumero(datoIngresado)) {
            esValido = rangoNumero(atoi(datoIngresado),1900,2018); //Validación del año
                if(esValido) {
                     (rentas+(*clientes))->fechaRenta.anio = atoi(datoIngresado);
                }
            }
        }while(esValido==0);

        (*clientes)++;
    }
    else {
        printf("\nYa tiene pel%cculas registradas\n",161);
    }
}

/*Función que sirve para regresar las películas rentadas*/
//Recibe el arreglo de estructuras de las rentas y la cantidad de clientes, no retorna ningún valor.
void regresarPeliculas(struct registro *rentas, int *clientes) {
    char nombre[50]; //Nombre que se ingresará para buscar el registro
    int registro,i=0,j=0; //registro: índice del registro encontrado, i y j son variables de control.

    printf("\nIngrese el nombre del cliente: ");
    getchar();
    gets(nombre);

    /*Busca el nombre del cliente en los registros, en caso de que sí existe,
    "borra" dicho registro recorriendo el contenido de los siguientes registros en posicion-1*/
   if(buscarCliente(&rentas[0], *clientes,nombre)!=-1) {
        registro = buscarCliente(&rentas[0], *clientes,nombre);
        (*clientes)--;

        //Ciclo que recorre los registros en posición -1
        for(i=registro;i<*clientes;i++) {
            strcpy((rentas+(i))->nombreCliente,(rentas+(i+1))->nombreCliente);
            do {
                strcpy((rentas+(i))->peliculas[j].nombrePelicula,(rentas+(i+1))->peliculas[j].nombrePelicula);
                strcpy((rentas+(i))->peliculas[j].clasificacion,(rentas+(i+1))->peliculas[j].clasificacion);
                j++;
            }while (j<((rentas+(i+1))->numPeliculasRentadas));

            (rentas+(i))->fechaRenta.dia=(rentas+(i+1))->fechaRenta.dia;
            (rentas+(i))->fechaRenta.mes=(rentas+(i+1))->fechaRenta.mes;
            (rentas+(i))->fechaRenta.anio=(rentas+(i+1))->fechaRenta.anio;
      }
        printf("\nPel%culas Entregadas\n",161);
    } else {
        printf("\nRegistro no encontrado\n");
    }
}

/*Función que muestra las rentas*/
//Recibe un registro de la estructura rentas. No retorna ningún valor.
void mostrarRentas(struct registro rentas){
    int i;

    /*Impresión de cada uno de los campos del registro*/
    printf("\nNombre: %s\n",rentas.nombreCliente);
    for(i=0;i<rentas.numPeliculasRentadas;i++) { //Ciclo para imprimir cada película y su respectiva clasificación
        printf("Pel%ccula: %s\n", 161,rentas.peliculas[i].nombrePelicula);
        printf("Clasificaci%cn: %s\n", 162,rentas.peliculas[i].clasificacion);
    }
    printf("Fecha de Renta: %d/%d/%d\n",rentas.fechaRenta.dia,rentas.fechaRenta.mes,rentas.fechaRenta.anio);
}

/*Función que busca el nombre de un cliente*/
//Recibe un arreglo de la estructura de las rentas, el número de clientes y el nombre buscado. Regresa un número entero.
int buscarCliente(struct registro *rentas, int clientes, char * nombre) {
    int registroEncontrado=-1, i=0; //registroEncontrado: variable de control, i:contador

    //Ciclo que se usa para comparar el nombre ingresado con cada uno de los registros
     while(i<clientes && registroEncontrado!=0){
        registroEncontrado = strcmp(strupr((rentas+i)->nombreCliente),strupr(nombre)); //Compara el nombre con los registros
        i++;
    }

    //Si el registro fue encontrado se manda el valor del índice del registro, sino se mandará un valor -1
    if(registroEncontrado==0 && clientes>=1) {
        return --i;
    } else {
        return -1;
    }
}

/*Función que sirve para validar si el dato ingresado es un número*/
//Recibe un arreglo de char que es la cadena ingresada y regresa un entero que indica si es un número o no
int esNumero(char * cadena) {
    int i, siNumero=1; //i: contador, siNumero = variable de control para indicar si la cadena es un número

    //Ciclo for que valida cada caracter de la cadena
    for(i=0; i<strlen(cadena); i++){
        if(!(cadena[i]>='0' && cadena[i]<='9'))
           siNumero =0;
    }
    return siNumero;
}

/*Función que sirve para validar el rango de un número*/
//Recibe el número y el rango de valores, el mínimo y máximo. Regresa un número entero
int rangoNumero(int numero, int min, int max) {
    if(numero>=min && numero<=max){ //Comparación si un número se encuentra dentro del rango
        return 1;
    } else {
        return 0;
    }
}
