#include<stdio.h>
#include<time.h>

int main()
{

    time_t t = time(NULL);
    struct tm fecha = *localtime(&t);

    printf("Anio: %d",fecha.tm_year + 1900);
    printf("\nMes: %d",fecha.tm_mon + 1);
    printf("\nDia: %d",fecha.tm_mday);
    printf("\nHora: %d",fecha.tm_hour);
    printf("\nMinuto: %d",fecha.tm_min);
    printf("\nSegundo: %d",fecha.tm_sec);
    //printf("\n: %d",fecha.tm_wday);

    return 0;
}
