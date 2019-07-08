#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include<windows.h>

#define STRING_LEN 255
#define forg 10
#define back  0


void opcion1();
void opcion2();
void opcion3();
void opcion4();

void gotoxy(int x,int y);
void pintaOpcion (int x, int y, int frente, int fondo, char opcion [] );
void pintaMenu(int x, int y, int frente, int fondo, int n, char opciones[][10]);
void setColorAndBackground(int ForgC, int BackC);
int menu(int x, int y, int frente, int fondo, int n, char [][10] );

int main()
{  char opciones[4][10]={"altas","bajas","consulta","salir"};
   int opcion;

   opcion= menu(10,5, forg, back, 4, opciones);


return 0;
}
void pintaOpcion (int x, int y, int frente, int fondo, char opcion [] )
{
    gotoxy(x,y);
    setColorAndBackground(frente,fondo);
    printf("%s", opcion);
}

void pintaMenu(int x, int y, int frente, int fondo, int n, char opciones[][10])
{
    int i;
    for (i=0;i<n;i++)
        pintaOpcion(x,y+i, frente,fondo, opciones[i] );
}


 void gotoxy(int x,int y)
 { COORD coord={0,0};
   coord.X=x;
   coord.Y=y;
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
 }

 void setColorAndBackground(int ForgC, int BackC)
{
     WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);;
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
     return;
}

int menu( int x, int y, int frente, int fondo, int n, char opciones [] [10])
{ int actual=0;
  int salir=0;
  int tecla;
    do
    {
        pintaMenu(x,y, frente,fondo,n,opciones);
        pintaOpcion(x,y+actual, fondo, frente,opciones[actual] );

        tecla=getch();

        pintaOpcion(x,y+actual, frente, fondo,opciones[actual] );

        if(tecla == 0 || tecla  == 224)
        {
            switch(getch())
            {
                case 72:     actual --;// arriba
                             if (actual<0) actual=n-1;
                             break;
                case 80:     actual ++; //abajo
                             if (actual==n) actual=0;
                             break;
                case 75:
                           //izquierda
                    break;
                case 77:
                           //derecha
                    break;
            }
        }

        if (tecla==13)
        {
            switch(actual)
            {
                case 0: opcion1();break;
                case 1: opcion2();break;
                case 2: opcion3();break;
                case 3: opcion4();
                        salir=1;
                break;
            }

            system("cls");
        }

       }while (tecla!=27 && salir==0);

//getchar();
 return 0;
}


void opcion1()
{
   printf("Elegiste la primera opción");
}

void opcion2()
{
   printf("Elegiste la segunda opción");
}

void opcion3()
{
   printf("Elegiste la tercera opción");
}

void opcion4()
{
   printf("Elegiste la salida");
}
