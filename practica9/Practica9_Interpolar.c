/*Practica9_Interpolar.c

Elaborado por Reyes Udasco Rachelle Nerie
Práctica No. 9 Análisis de Algoritmos Empírico en búsquedas recursivas.
23 de noviembre del 2018
Grupo 551
Algoritmos y Estructura de Datos

Competencia: Clasificar los algoritmos de búsqueda según su desempeño en escenarios 
de prueba con distintos parámetros, para ser la selección del método más adecuado 
para la solución de problemas de manejo de información.

*/

//Bibliotecas
#include<stdio.h>
#include<time.h>

//Prototipo de funciones
int busquedaInterpolada(int vector[], int llave, int i, int j,int *iteraciones);
void imprimirVector(int vector[],int izq, int der);
void imprimirVectorFloat(float vector[],float izq, float der);

//Función principal
int main() {
    int numero, iteraciones=0,tamano, posicion;
	double tiempo;
    clock_t inicio, fin; //Variables utilizadas para medir el tiempo

	printf("MEJOR CASO \n");
	int vector[] = {1,3,5,7,9,11,13,15,17,19,21,23,25,27,29,31,33,35,37,40,42,44};
	numero = 50;
/*	
		printf("CASO NO ENCONTRADO\n");
		int vector[] = {1,3,5,7,9,11,13,15,17,19,21,23,25,27,29,31,33,35,37,40,42,44};
		numero = 60; 

		printf("CASO PROMEDIO \n");
		int vector[] = {1,3,6,8,11,13,15,18,21,23,25,27,29,31,33,35,38,40,42,45,47,50};
		numero = 8;
	
		printf("PEOR CASO \n");
		int vector[] = {1,5,12,17,22,27,34,39,42,47,50,59,67,78,81,86,90,94,98,100,104,111};
		numero = 18;
*/
	
	tamano = sizeof(vector)/sizeof(int);
	
	printf("\nVector: ");
    imprimirVector(vector,0,tamano-1);
    printf("Llave: %d\n",numero); //Impresion del vector y de la llave

    inicio = clock();  //Inicia el reloj
    posicion = busquedaInterpolada(vector,numero,0,tamano-1,&iteraciones); //Realiza la busqueda
    fin = clock();	//Detiene el reloj

    tiempo = (double)(fin - inicio) * 1000.0/CLOCKS_PER_SEC; //Obtiene el tiempo transucrrido
    printf("\nPosicion: %d\n",posicion);
    printf("Tiempo transcurrido en ms: %f\n ", tiempo);

    return 0;
}

//Funcion de la busqueda interpolada recursiva
int busquedaInterpolada(int vector[], int llave, int i, int j,int *iteraciones){

   int pos = i + (((int)(j-i) / (vector[j]-vector[i]))*(llave - vector[i])); 
	*iteraciones+=1;
	
	//Impresion de variables utilizados y el vector a comparar en la iteracion
	printf("\nIndices => Izquierda: %d, Pos: %d, Derecha: %d, Numero comparado con llave: %d",i,pos,j,vector[pos]);
	printf("\nVector => ");
	imprimirVector(vector,i,j);

    if (i <= j && llave >= vector[i] && llave <= vector[j]) { 
        if (vector[pos] < llave) 
			return busquedaInterpolada(vector, llave, pos + 1, j,iteraciones) ; //Elemento ubicado en la parte derecha
        else
			if (vector[pos] > llave) 
			return busquedaInterpolada(vector,llave,i, pos - 1, iteraciones) ;  //Elemento ubicado en la parte izquierda
		else {
			 printf("\nIteraciones: %d",*iteraciones);
			 return pos;  //Elemento encontrado
		}
    } 
	printf("\nIteraciones: %d",*iteraciones);
    return -1; //Elemento no encontrado
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