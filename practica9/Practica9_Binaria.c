/*Practica9_Binaria.c

Elaborado por Reyes Udasco Rachelle Nerie
Práctica No. 9 Análisis de Algoritmos Empírico en búsquedas recursivas.
23 de noviembre del 2018
Grupo 551
Algoritmos y Estructura de Datos

Competencia: Clasificar los algoritmos de búsqueda según su desempeño en escenarios 
de prueba con distintos parámetros, para ser la selección del método más adecuado 
para la solución de problemas de manejo de información.

Implemente la búsqueda binaria e interpolada para tamaño N,

Utilizando inicialmente un arreglo tipo int de 20 posiciones elabore una tabla con los siguientes datos:

a)	El tiempo para el peor de los casos
b)	El tiempo para el mejor de los casos
c)	El tiempo para cualquier otro caso
d)	La cantidad de iteraciones realizadas en ambas búsquedas para cada caso
e)	¿Qué pasa al cambiar el tipo de datos del vector de int a float?
f)	¿Qué pasa al aumentar el tamaño de N?
g)	¿Qué pasa si el elemento NO está en el arreglo
Determine nuevamente los incisos a-g pero con la búsqueda interpolada.
h)	¿Se puede utilizar la búsqueda binaria para cadenas? ¿Sí o no, por qué?
i)	¿Se puede utilizar la búsqueda interpolada para cadenas? ¿Sí o no, por qué?

-No se pide que capture las datos, inicialice los arreglos con los valores necesarios.
-Las funciones deben presentar en todo momento en pantalla los datos sobre los que se está realizando la búsqueda.
-Lenguaje libre.
-Elabore un reporte que inclúyelos resultados obtenidos y las conclusiones.

*/

//Bibliotecas
#include<stdio.h>
#include<time.h>

//Prototipo de funciones
int busquedaBinaria(int vector[], int llave, int izq, int der,int *iteraciones);
void imprimirVector(int vector[],int izq, int der);
void imprimirVectorFloat(float vector[],float izq, float der);


//Función principal
int main() {
    int numero, iteraciones=0,tamano, posicion;
    double tiempo;
    clock_t inicio, fin;  //Variables utilizadas para medir el tiempo

    int vector[] = {1,3,6,7,12,15,25,27,30,34,42,59,63,64,70,73,75,82,95,97}; //CASO INT
    tamano = sizeof(vector)/sizeof(int);

	
   printf("MEJOR CASO \n");
    numero = 34; //Mejor caso
/*	
    printf("CASO PROMEDIO \n");
    numero = 15;

    printf("PEOR CASO \n");
    numero = 97;

    printf("CASO NO ENCONTRADO\n");
    numero = 60;
*/

	//Impresion del vector y de la llave
    printf("\nVector: ");
    imprimirVector(vector,0,tamano-1);
    printf("Llave: %d\n\n",numero);

    inicio = clock();  //Inicia el reloj
    posicion = busquedaBinaria(vector,numero,0,tamano-1,&iteraciones); //Realiza la busqueda
    fin = clock();     //Detiene el reloj
    tiempo = (double)(fin - inicio) * 1000.0/CLOCKS_PER_SEC;  //Obtiene el tiempo transucrrido
    printf("\nPosicion: %d\n",posicion);
    printf("Tiempo transcurrido en ms: %f\n ", tiempo);

    return 0;
}

//Funcion de la busqueda binaria recursiva
int busquedaBinaria(int vector[], int llave, int izq, int der,int *iteraciones) {
    int medio;
	
    medio = (izq+der)/2;
    *iteraciones+=1;
	
	//Impresion de variables utilizados y el vector a comparar en la iteracion
    printf("\nIndices => Izquierda: %d, Medio: %d, Derecha: %d, Numero comparado con llave: %d",izq,medio,der,vector[medio]);
    printf("\nVector => ");
    imprimirVector(vector,izq,der);

    if(izq>der) {
        printf("\nIteraciones: %d",*iteraciones);  //Elemento no encontrado
        return -1;
    }else
        if (vector[medio]>llave)  
        return busquedaBinaria(vector,llave,izq,medio-1,iteraciones);  //Elemento ubicado en la parte izquierda
    else
        if (vector[medio]<llave)
        return busquedaBinaria(vector,llave,medio+1,der,iteraciones); //Elemento ubicado en la parte derecha
    else{   
        printf("\nIteraciones: %d",*iteraciones);  //Elemento encontrado
        return medio;
    }
    return 0;
}

//Procedimiento que imprime el vector de enteros
void imprimirVector(int vector[],int izq, int der) {
    int i;
    for(i=izq; i<=der; i++) {
        printf("%d ",vector[i]);
    }
    printf("\n");
}

//Procedimiento que imprime el vector de flotantes
void imprimirVectorFloat(float vector[],float izq, float der) {
    int i;
    for(i=izq; i<=der; i++) {
        printf("%.1f,",vector[i]);
    }
    printf("\n");
}
