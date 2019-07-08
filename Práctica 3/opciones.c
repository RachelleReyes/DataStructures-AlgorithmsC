//opciones.c

/* Práctica 3: Elaborado por Reyes Udasco Rachelle Nerie*/

#include "opciones.h"
#include <stdio.h>

//Funcion que saca el residuo de un numero dividido entre diez. Recibe el residuo y el num como parametros. 
int sacarresiduo(int residuo, int num)
{
    residuo = num%10;
    return residuo;
}

/*Funcion que manipula el numero dado, resta el residuo del numero y 
lo divide entre 10. Recibe el residuo y el num como parametros. */
int sacarnumero(int residuo, int num)
{
    num = num - residuo;
    num = num/10;
    return num;
}

//Funcion que imprime el numero al reves. Recibe como parametro el valor del numero dado por el usuario
int reversa(int value)
{
	//Declaracion de variables
	int num,residuo, numreverso=0;
    num=value;
	/*Comparacion si el numero es mayor a 9, con el proposito de no entrar el ciclo 
	 cuando tengamos un numero de un digito*/
	if (num>9)
	{
       //Ciclo que termina cuando el numero ya no es mayor a nueve
	   do
		{
		residuo = sacarresiduo(residuo,num); //Saca residuo del numero
		num = sacarnumero(residuo,num); //La variable num se iguala al nuevo valor 
		numreverso = numreverso+ residuo; //Se acumula el residuo en la variable numreverso
		numreverso = numreverso*10; //Se recorre el lugar del residuo
		}while(num>9);
        numreverso = numreverso+ num; //Por el ultimo digito que se quedo
	}
	else{numreverso = num;} //Asignacion del valor de num a numreverso, si el usuario ingresa un numero de un solo digito
	
	return numreverso;
}

//Funcion que cuenta el numero de digitos que contiene un numero
int digitos(int value)
{
	//Declaracion de variables
	int num,residuo,digitos=1;
    num=value;
	
	//Ciclo que termina cuando el numero ya no es mayor a nueve
	if (num>9)
	{
		//Ciclo que termina cuando el numero ya no es mayor a nueve
        do
            {
                residuo = sacarresiduo(residuo,num); //Saca residuo del numero
                num = sacarnumero(residuo,num); //La variable num se iguala al nuevo valor 
				digitos++; //Se usa como contador de los digitos
            }while(num>9);
	}
	
	return digitos;
}

//Funcion que calcula la suma de los digitos de un numero
int suma(int value)
{
	//Declaracion de variables
	int num,residuo, suma=0;
    num=value;
	
	//Ciclo que termina cuando el numero ya no es mayor a nueve
	if (num>9)
	{
		//Ciclo que termina cuando el numero ya no es mayor a nueve
        do
            {
                residuo = sacarresiduo(residuo,num); //Saca residuo del numero
                num = sacarnumero(residuo,num); //La variable num se iguala al nuevo valor 
                suma = suma+ residuo; //Acumulacion del residuo
            }while(num>9);
			suma = suma+num;;
	}
	else{suma = num;} //Si el usuario ingresa un numero de un digito
	
	return suma;
}

//Funcion que compara si un numero es "perfecto"
int perfecto(int value)
{
	//Declaracion de variables
	int num,residuo, suma=0, perfecto=0, contador=1;
    num=value;
	
	//Ciclo que termina cuando ya se recorrieron los divisores del propio numero
    do
    {
        residuo = num%contador;
        if(residuo==0)
        {
            suma=suma+contador; //Acumulacion del variable contador
        }
        contador++; 
	}while(contador<num);

	if(suma==num){perfecto=1;} //Si la suma y el numero son iguales, envia el numero 1, si no, envia 0
	return perfecto;
}

//Funcion que compara si dos numeros son "amigos"
int amigos(int value1, int value2)
{
	//Declaracion de variables
	int amigos=0, num1,residuo1, suma1=0,contador1=1,num2,residuo2, suma2=0,contador2=1;

    num1=value1;
    num2=value2;

	//Ciclo que termina cuando ya se recorrieron los divisores del propio numero
   //Acumula los valores de sus divisores
   do
    {
		residuo1 = num1%contador1;
		//Comparacion: si es divisor no debera tener residuo
		if(residuo1==0)
		{
			suma1=suma1+contador1;
		}
		contador1++;
	}while(contador1<num1);

	//Ciclo que termina cuando ya se recorrieron los divisores del propio numero.
	//Acumula los valores de sus divisores
	 do
    {
        residuo2 = num2%contador2;
		//Comparacion: si es divisor no debera tener residuo
        if(residuo2==0)
        {
            suma2=suma2+contador2;
        }
        contador2++;
	}while(contador2<num2);

	if(suma1==num2 || suma2==num1){amigos=1;} //Si la comparacion se cumple envia 1, al contrario envia 0
	
	return amigos;
}

