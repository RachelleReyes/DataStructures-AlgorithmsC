#include<time.h>
#include<stdio.h>

int main() {
    unsigned int minutos = 0;
    unsigned int segundos =0;
    unsigned int tiempoTotal,tiempoRestante = 0,aux=0;

    clock_t inicio,fin;
    tiempoTotal = 90;

    inicio = clock();
    tiempoRestante = 0;
    aux = 0;

    while(tiempoRestante<tiempoTotal) {
        fin = clock();
        tiempoRestante = ((fin-inicio)/CLOCKS_PER_SEC);
     //   minutos =  (fin-inicio)/(CLOCKS_PER_SEC)/60;

        //tiempoRestante = segundos + minutos*60;
        if(tiempoRestante==(aux+1)) {
            printf("\nTienes %d:%d",tiempoRestante/60, tiempoRestante-60*(tiempoRestante/60));
            aux++;
        }

    }
    printf("\nTiempo acabado");

}
