/*
Elaborado por Reyes Udasco Rachelle Nerie
Práctica No. 10 Método de ordenamiento Quicksort
30 de noviembre del 2018
Grupo 551
Algoritmos y Estructura de Datos

Competencia: Determinar la eficiencia de un algoritmo de ordenación según su desempeño en escenarios
de prueba con distintos parámetros, para ser considerada como criterio en la selección de un algoritmo
para resolver un problema.

Suponga que los datos de los estudiantes de una escuela se almacenan en una estructura que tiene los siguientes campos:
-Nombre
-Carrera
-Promedio
-Créditos cursados

Utilizando un arreglo de 10 elementos la estructura mencionada, ordene en forma ascendente (a-z) los datos por nombre
y elabore una tabla con los siguientes datos:

Para los pasos a-d utilice el pivote que prefiera.

a.	El tiempo y la cantidad de iteraciones para el peor de los casos
b.	El tiempo y la cantidad de iteraciones para el mejor de los casos
c.	El tiempo y la cantidad de iteraciones para cualquier otro caso
d.	¿Qué pasa si todos los datos son iguales?

Utilizando el mismo conjunto de datos para los siguientes pasos determine los puntos e-h:

e.	¿Cantidad de pasadas si el pivote es el elemento de la izquierda?
f.	¿Cantidad de pasadas si el pivote es el elemento de la derecha?
g.	¿Cantidad de pasadas si el pivote es el elemento del centro del arreglo?
h.	¿Cantidad de pasadas si el pivote es un elemento aleatorio?

Repita los pasos e-h con otro conjunto de datos y responda.

-¿La selección del pivote afectó de alguna manera la cantidad de pasadas que hace el algoritmo?
-¿Hubo cambios al utilizar otros datos o se comportó igual que con el primero?
-¿Cuál forma de elegir el pivote resultó más eficiente?

-No se pide que capture los datos, inicialice el arreglo con los valores necesarios.
-Elabore y suba a moodle un reporte en formato PDF con su código, los resultados obtenidos organizados en tablas y sus conclusiones.
-La implementación debe ser un trabajo original.
-La conclusión NO es la explicación de cómo funciona el algoritmo, historia del algoritmo, etc. sino una reflexión propia de los
resultados obtenidos en los experimentos.
-La buena presentación y ortografía serán consideradas como parte de la evaluación.
-No se aceptarán trabajos plagiados, de otros compañeros o traducidos de otros lenguajes.

*/

//Declaracion de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Definicion de valores constantes
#define MAX 50   //Tamano de cadena maximo
#define registros 10  //Cantidad de registros

//Estructura del estudiante
typedef struct Estudiante_ {
    char nombre[MAX];
    char carrera[MAX];
    float promedio;
    int creditosCursados;
}Estudiante;

//Prototipo de funciones
void imprimirEstudiantes(Estudiante *arreglo, int n);
void imprimirNombres(Estudiante *arreglo, int n);
void swap(void* estudianteA, void* estudianteB, size_t tamano);
int particionDer (Estudiante *arreglo, int low, int high);
int particionIzq(Estudiante *arreglo, int low, int high);
int particionMed(Estudiante *arreglo, int low, int high);
int particionRand(Estudiante *arreglo, int low, int high);

void quickSort(Estudiante *arreglo, int low, int high,int *iteraciones);

//Funcion principal
int main(){
    int iteraciones = 0;
    double tiempo;
    clock_t inicio, fin;  //Variables utilizadas para medir el tiempo

    //Arreglo no ordenado
   Estudiante estudiante[registros] = {  //Declaracion e inicializacion de la variable
        {"Cesena Rosa", "Docencia",98.50,200},
        {"Robles Karla", "Docencia",95.20,123},
        {"Lagarda Paola", "QFB",97.8,197},
        {"Galindo Itzel", "Economia",90.50,176},
        {"Soto Paola", "Odontologia",89.50,234},
        {"Leal Rodrigo", "Ing. en Computacion",87.50,157},
        {"Hernandez Alexia", "Mercadotecnia",92.75,134},
        {"Saucedo Sylvia", "Idiomas",92.34,165},
        {"Gamboa Israel", "Psicologia",89.50,236},
        {"Hernandez Edson", "Idiomas",90.58,189}
    };
/*
    //Arreglo ordenado
    Estudiante estudiante[registros] = {  //Declaracion e inicializacion de la variable
        {"Cesena Rosa", "Docencia",98.50,200},
        {"Galindo Itzel", "Economia",90.50,176},
        {"Gamboa Israel", "Psicologia",89.50,236},
        {"Hernandez Alexia", "Mercadotecnia",92.75,134},
        {"Hernandez Edson", "Idiomas",90.58,189},
        {"Lagarda Paola", "QFB",97.8,197},
        {"Leal Rodrigo", "Ing. en Computacion",87.50,157},
        {"Robles Karla", "Docencia",95.20,123},
        {"Saucedo Sylvia", "Idiomas",92.34,165},
        {"Soto Paola", "Odontologia",89.50,234}
    };
*/
/*
 //Arreglo
   Estudiante estudiante[registros] = {  //Declaracion e inicializacion de la variable
        {"Cesena Rosa", "Docencia",98.50,200},
        {"Robles Karla", "Docencia",95.20,123},
        {"Lagarda Paola", "QFB",97.8,197},
        {"Hernandez Alexia", "Mercadotecnia",92.75,134},
        {"Galindo Itzel", "Economia",90.50,176},
        {"Soto Paola", "Odontologia",89.50,234},
        {"Leal Rodrigo", "Ing. en Computacion",87.50,157},
        {"Hernandez Edson", "Idiomas",90.58,189},
        {"Saucedo Sylvia", "Idiomas",92.34,165},
        {"Gamboa Israel", "Psicologia",89.50,236}
    };
*/
/*
    //Arreglo de datos iguales
   Estudiante estudiante[registros] = {  //Declaracion e inicializacion de la variable
        {"Robles Karla", "Docencia",95.20,123},
        {"Robles Karla", "Docencia",95.20,123},
        {"Robles Karla", "Docencia",95.20,123},
        {"Robles Karla", "Docencia",95.20,123},
        {"Robles Karla", "Docencia",95.20,123},
        {"Robles Karla", "Docencia",95.20,123},
        {"Robles Karla", "Docencia",95.20,123},
        {"Robles Karla", "Docencia",95.20,123},
        {"Robles Karla", "Docencia",95.20,123},
        {"Robles Karla", "Docencia",95.20,123},
    };
*/
/*
 //Arreglo con otros datos
   Estudiante estudiante[registros] = {  //Declaracion e inicializacion de la variable
        {"Ruiz Olivia", "Ing. en Quimica",98.50,200},
        {"Torres Gustavo", "Ing. en Computacion",95.20,123},
        {"Angulo Ana", "Mercadotecnia",97.8,197},
        {"Osuna Eduardo", "Administracion",92.75,134},
        {"Agreda Samara", "Negocios Internacionales",90.50,176},
        {"Aguila Santiago", "Ing. en Sistemas",89.50,234},
        {"Castellon Alan", "Energias Renovables",87.50,157},
        {"Cota Brandon", "Ing. en Sistemas",90.58,189},
        {"Soto Alex", "Energias Renovables",92.34,165},
        {"Ruiz Carissa", "Medicina",89.50,236}
    };
*/
    printf(" Arreglo original\n");
    imprimirNombres(estudiante, 10);

    inicio = clock();  //Inicia el reloj
    quickSort(estudiante, 0, registros-1, &iteraciones);
    fin = clock();     //Detiene el reloj
    tiempo = (double)(fin - inicio)/CLOCKS_PER_SEC;  //Obtiene el tiempo transucrrido

    printf("\n\n Iteraciones: %d", iteraciones);
    printf("\n Tiempo transcurrido en s: %f\n ", tiempo);
    printf("\n\n%20s\t%20s\t%15s\t%15s","NOMBRE","CARRERA","PROMEDIO","CREDITOS");
    imprimirEstudiantes(estudiante,registros);

    return 0;
}

//Procedimiento que imprime los registros de estudiantes
void imprimirEstudiantes(Estudiante *arreglo, int n) {
    int i;

    for(i=0;i<n;i++) {
        printf("\n%20s\t%20s\t%15f%15d",arreglo[i].nombre,arreglo[i].carrera,arreglo[i].promedio,arreglo[i].creditosCursados);
    }
    printf("\n");
}

//Procedimiento que imprime los nombres
void imprimirNombres(Estudiante *arreglo, int n) {
    int i;

    for(i=0;i<n;i++) {
        printf(" %s,",arreglo[i].nombre);
        if(i==4)
            printf("\n");
    }
}

//Funcion que intercambia el valor de dos variables
void swap(void* estudianteA, void* estudianteB, size_t tamano) {
    void* tmp = malloc(tamano);
    memcpy(tmp, estudianteA, tamano);
    memcpy(estudianteA, estudianteB, tamano);
    memcpy(estudianteB, tmp, tamano);
    free(tmp);
}


//Funcion que realiza la particion con el elemento a la derecha
int particionDer (Estudiante *arreglo, int low, int high) {
    Estudiante auxiliar, pivote;
    pivote = arreglo[high];
    int i=0, j;
    i= (low-1);

    for (j=low; j<=high-1; j++) {
        if (strcmp(arreglo[j].nombre, pivote.nombre)<=0) {
            i++;
            swap(&arreglo[i],&arreglo[j],sizeof(Estudiante));
        }
    }
    swap(&arreglo[i+1],&arreglo[high],sizeof(Estudiante));
    return (i+1);
}

//Funcion que realiza la particion con el elemento a la izquierda
int particionIzq(Estudiante *arreglo, int low, int high) {

   Estudiante pivote = arreglo[low], temp;
   int j,i = low+1;

   for(j=low+1;j<=high;j++) {
    if(strcmp(arreglo[j].nombre, pivote.nombre)<0) {
        if(i!=j) {
            swap(&arreglo[i],&arreglo[j],sizeof(Estudiante));
        }
        i++;
    }
   }
    arreglo[low] = arreglo[i-1];
    arreglo[i-1] = pivote;
    return i-1;
}

//Funcion que realiza la particion con el elemento en el medio
int particionMed(Estudiante *arreglo, int low, int high) {

    int indicePivote = (low+high)/2;
    Estudiante pivote = arreglo[indicePivote];
    swap(&arreglo[indicePivote],&arreglo[high],sizeof(Estudiante));

    indicePivote = high;
    int i = low -1;

    for(int j=low; j<=high-1; j++) {
        if(strcmp(arreglo[j].nombre, pivote.nombre)<=0) {
            i = i+1;
            swap(&arreglo[i],&arreglo[j],sizeof(Estudiante));

        }
    }
    swap(&arreglo[i+1],&arreglo[indicePivote],sizeof(Estudiante));
    return i+1;

}

//Funcion que realiza la particion con un elemento al azar
int particionRand(Estudiante *arreglo, int low, int high) {

    srand(time(NULL));
    int indicePivote = low + rand() % (high-low+1);
    Estudiante pivote = arreglo[indicePivote];
    swap(&arreglo[indicePivote],&arreglo[high],sizeof(Estudiante));

    indicePivote = high;
    int i = low -1;

    for(int j=low; j<=high-1; j++) {
        if(strcmp(arreglo[j].nombre, pivote.nombre)<=0) {
            i = i+1;
            swap(&arreglo[i],&arreglo[j],sizeof(Estudiante));

        }
    }
    swap(&arreglo[i+1],&arreglo[indicePivote],sizeof(Estudiante));
    return i+1;

}

//Funcion que realiza el quickSort
void quickSort(Estudiante *arreglo, int low, int high, int * iteraciones) {
    int pivote;
    if (low<high) {
        *iteraciones = *iteraciones +1;
        pivote = particionRand(arreglo,low,high);
        printf("\n\n Pivote: %d, Valor: %s\n",pivote,arreglo[pivote].nombre);
        imprimirNombres(arreglo, registros);
        quickSort(arreglo, low, pivote-1, iteraciones);
        quickSort(arreglo, pivote+1, high, iteraciones);
    }
}

/* Funcion que realiza el quickSort sin impresiones
void quickSort(Estudiante *arreglo, int low, int high) {
    int pivote;

    if (low<high) {
        pivote = particionDer(arreglo,low,high);
        quickSort(arreglo, low, pivote-1);
        quickSort(arreglo, pivote+1, high);
    }
}
*/
