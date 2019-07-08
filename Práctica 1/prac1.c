#include<stdio.h>
#include<stdlib.h>

/* Elaborado por Reyes Udasco Rachelle Nerie
Práctica 1: Este juego genera un número al azar entre 1 y 1000 dándole al
jugador el objetivo de adivinarlo con el menor número de intentos posibles.*/

int mensajeinicial()
{
	printf("Tengo un numero entre 1 y 1000"); //Imprime los mensajes
	printf("\nPuedes adivinar mi numero?");
	return 0;
}

int generanum() //Genera números aleatorios
{
	int numr; //numr es el número aleatorio
	numr = (rand() % 1000) +1; //Genera un número aleatorio entre 1 y 1000
	return numr; //Regresa el número aleatorio
}

int comparanum(int numr,int numu) //Compara el número aleatorio y el número dado por el usuario, regresa un mensaje
{
	if(numu<numr) {printf("\nMuy bajo. Intentalo nuevamente");}
	else if (numu>numr) {printf("\nMuy alto. Intentalo nuevamente");}
	else {printf("\nExcelente! has adivinado el numero!");}
	return 0;
}

int compintento (int intento)  //Compara el número de intentos, regresa un mensaje
{
	if (intento<10) {printf( "\nFelicidades!! has adivinado en pocos intentos");}
	else if (intento>10) {printf( "\nLo puedes hacer mejor!!!");}
	else {printf("\nHaaa!! ya conoces el numero secreto");}
	return 0;
}

int main() //Función principal
{
	int adivinado=0, intento=0, numr, numu; //Declaración de variables
	char resp;

	numr = generanum(); //Asigna la funcion generanum a la variable numr
    mensajeinicial();

	do
	{
		printf("\nIngrese tu numero: "); //Pide un número al usuario
		scanf("%d", &numu);

		comparanum(numr,numu); //Imprime el mensaje de la comparación de los dos números
		if(numr==numu) adivinado=1;
		intento++;

		if(adivinado==1) //Hace una comparación cuando el número es adivinado
		{
			compintento(intento); //Imprime el mensaje de los número de intentos
			printf("\nQuieres jugar una vez mas (y/n)?"); //Opción para reiniciar el juego
			scanf("%s",&resp);
			if(resp == 'y') {numr= generanum(); intento=0; adivinado =0;} //Comparación de la respuesta
			else if(resp =='n') {adivinado=1;}
		}
	}while(adivinado ==0);//El ciclo no se terminará si no se adivina el número
	return 0;
}