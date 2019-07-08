/*
Practica 10: Continuación de archivos binarios
Elaborado por Reyes Udasco Rachelle Nerie
El objetivo del programa es crear registros de anuncios ingresados por el usuario
Se dara un menu para poder registrar, editar, cancelar, ordenar y consultar anuncios.
El proceso de ordenamiento se realiza intercambiando las direcciones de cada registro
*/

//Librerias incluidas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "bubblesort.h"

//Limpia la pantalla
#define CLEAR() system("CLS")

//Definicion de la estructura de la fecha
typedef struct Date_
{
  int dia;
  int mes;
  int anio;
}Date;

//Definicion de la estructura del anuncio
typedef struct Anuncio_
{
  int numero;
  char clasificacion[15];
  char responsable[20];
  char telefono[13];
  char contenido[100];
  Date fecha;
}Anuncio;

//Prototipo de funciones que se utilizarán
int imprimirmenu();
void elegiropcion(Anuncio *, Anuncio, int, int);
void captura(Anuncio * );
void grabar(Anuncio);
void mostrar();
int menuclasificacion();
char * elegirclasificacion(int);
int busqueda (int llave);
void borrar();
void editar();
void consultaresponsable();
void consultaclasificacion();
void imprimir(Anuncio);
void pausa();
void ordenar();
long int tamano(FILE *);
void mostraranuncioactuales();
void crearrespaldo();
void respaldo_texto();
void imprimiranuncios(Anuncio *anuncioPtr, int);
void imprimiranuncio(Anuncio *anuncioPtr, int);
int tamano_archivo();
void lectura(Anuncio *anuncioPtr);
int compararA_clas(const void *a, const void *b);
int compararA_num(const void *a, const void *b);
int compararA_fecha(const void *a, const void *b);

//Funcion principal
int main()
{
	//Declaración de variables
    Anuncio registro, *anuncioPtr;
    int opc,tam;
	
	tam = tamano_archivo();
	anuncioPtr = malloc(tam*sizeof(Anuncio));
	lectura(anuncioPtr);
	
    //EXTRA 10%
    clock_t start = clock();

    do
    {   CLEAR();
        
		//Obtiene la opcion elegida por el usuario
		opc = imprimirmenu();
		
		elegiropcion(anuncioPtr, registro, tam, opc);
		
       
    }while (opc!=0);

    printf("Tiempo transcurrido: %f", ((double)clock() - start) / CLOCKS_PER_SEC);
	
	free(anuncioPtr);
    return 0;
}

//Funcion que imprime el menu al ejecutar el programa
int imprimirmenu()
{
	int opc;
	CLEAR();
	
	//Impresion de las opciones
	puts("1) Registrar anuncio");
	puts("2) Cancelar anuncio");
	puts("3) Editar anuncio");
	puts("4) Consultar por clasificacion");
	puts("5) Consultar por responsable");
	puts("6) Ordenar por responsable");
	puts("7) Mostrar anuncios actuales");
	puts("8) Crear respaldo del registro");
	puts("9) Crear respaldo del registro(archivo txt)");
	puts("10) Mostrar en orden por fecha");
	puts("11) Mostrar en orden por clasificacion");
	puts("12) Mostrar en orden por numero de publicacion");
	puts("13) Mostrar todos los registros");
	puts("0) Salir");
	printf("Opcion:");
	setbuf(stdin, 0);
	//Obtiene la opción ingresada por el usuario
	scanf("%d",&opc);

	return opc;
}

//Funcón que compara la opcion elegida por el usuario
void elegiropcion(Anuncio *anuncioPtr, Anuncio registro, int tam, int opc)
{
		tam = tamano_archivo();
		anuncioPtr = malloc(tam*sizeof(Anuncio));
		lectura(anuncioPtr);
		
		//Comapra el valor de la variable opc
		switch(opc)
        {
            case 1:  captura(&registro);
                        grabar(registro);break;
            case 2:  borrar(); break;
            case 3:  editar();break;
            case 4:  consultaclasificacion(); break;
            case 5:  consultaresponsable();  break;
            case 6:  ordenar(); break;
            case 7:  mostraranuncioactuales(); break;
            case 8:  crearrespaldo();  break;
            case 9:  respaldo_texto();  break;
            case 10: bubbleSort(anuncioPtr,tam,sizeof(Anuncio),compararA_fecha); 
					 imprimiranuncios(anuncioPtr,tam); 
					 pausa(); break;
            case 11: bubbleSort(anuncioPtr,tam,sizeof(Anuncio),compararA_clas); 
					 imprimiranuncios(anuncioPtr,tam); 
					 pausa(); break;
            case 12: bubbleSort(anuncioPtr,tam,sizeof(Anuncio),compararA_num); 
					 imprimiranuncios(anuncioPtr,tam); 
					 pausa(); break;
            case 13:  mostrar(); break;
        }
	
}

//Funcion que captura un registro ingresado por el usuario
void captura(Anuncio * registro)
{
    int clasif, auxnum,repetido=0;
    CLEAR();
    //Ciclo para comprobar si el numero se repite
    do
    {
        printf("Numero: "); scanf("%d",&auxnum);
        //Comapracion si el numero ya esta disponible
        if(busqueda(auxnum)==-1)
        {
            registro->numero = auxnum;
            repetido=1;
        }
        else
        {
            puts("Numero de anuncio repetido");
        }
    } while(repetido==0);

    setbuf(stdin,0);
    //Muestra un menu para elegir la clasificacion
    printf("Clasificacion: ");
        clasif = menuclasificacion();
        strcpy(registro->clasificacion,elegirclasificacion(clasif));
    setbuf(stdin,0);
    printf("Responsable: "); gets(registro->responsable);
    setbuf(stdin,0);
    printf("Telefono: "); gets(registro->telefono);
    setbuf(stdin,0);
    printf("Contenido: "); gets(registro->contenido);
    setbuf(stdin,0);
    printf("Fecha(dia mes anio): "); scanf("%d %d %d",&registro->fecha.dia,&registro->fecha.mes,&registro->fecha.anio);
}

//FUncion que imprime el contenido de cierto registro
void imprimir(Anuncio registro)
{
    printf("\n Numero: %d",registro.numero);
    printf("\n Clasificacion: %s", registro.clasificacion);
    printf("\n Responsable: %s",registro.responsable);
    printf("\n Telefono: %s",registro.telefono);
    printf("\n Contenido: %s",registro.contenido);
    printf("\n Fecha: %d/%d/%d",registro.fecha.dia,registro.fecha.mes,registro.fecha.anio);
}

//Funcion que realiza una pausa
void pausa()
{
    setbuf(stdin,0);
    getchar();
}

//Funcion que graba los datos ingresados por el usuario
void grabar(Anuncio registro)
{
    FILE * flujo;
    imprimir(registro);
    getchar();
    flujo= fopen("registros.dat","ab");
	
	//Comparación si el archivo fue abierto
    if (flujo!=NULL)
    {
		//Graba el registro en el archivo
        fwrite(&registro,sizeof(Anuncio),1,flujo);
        fclose(flujo);
    }
    else
        printf("No se pudo abrir");
}

//Funcion que muestra todos los registros
void mostrar()
{
    FILE * flujo;
    Anuncio registro;
    int cont=1;
    flujo= fopen("registros.dat","rb");
	
	//Comparación si el archivo fue abierto
    if (flujo)
    {
		//Ciclo que imprime los registros
        while(fread(&registro,sizeof(Anuncio),1,flujo)>0)
        {
            printf("\n\n  Registro No. %d\n", cont);
            imprimir(registro);
            pausa();
            cont++;
        }
    }
    fclose(flujo);
}

//Funcion que imprime el menu para elegir la clasificacion
int menuclasificacion()
{
        int clasf;
        puts("Elige la clasificacion escribiendo su numero:");
        puts("1) Venta varios");
        puts("2) Autos");
        puts("3) Mascotas");
        puts("4) Empleos");
        puts("5) Renta");
        puts("6) Traspasos");
        puts("7) Otros");

        scanf("%d",&clasf);
        return clasf;
}

//Funcion para elegir la clasificacion
char * elegirclasificacion(int opcion)
{
    char *clasific;
    //Comparacion de la opcion ingresado
    switch(opcion)
    {
        case 1: clasific = "Venta varios"; break;
        case 2: clasific = "Autos"; break;
        case 3: clasific = "Mascotas"; break;
        case 4: clasific = "Empleos"; break;
        case 5: clasific = "Renta"; break;
        case 6: clasific = "Traspasos"; break;
        case 7: clasific = "Otros"; break;
    }
    return clasific;
}

//Funcion que realiza la busqueda por el numero del anuncio
int busqueda (int llave)
{
    FILE * flujo;
    Anuncio registro;
    int cont=0;
    flujo= fopen("registros.dat","rb");
	
	//Comparación si el archivo fue abierto
    if (flujo)
    {
        while( fread(&registro,sizeof(Anuncio),1,flujo)>0)
        {
            cont++;
            //Comparacion que busca registros con el numero ingresado
            if (registro.numero == llave)
            {
                getchar();
                fclose(flujo);
                return cont;
            }
        }
        fclose(flujo);

    }
    return -1;
}

//Funcion que cancela el anuncio
void borrar()
{
   //Declaracion de variables
   FILE *original, *copia;
   int llave,ban;
   Anuncio aux;
   //Se abren el archivo original para leer y se crea uno nuevo
   original=fopen("registros.dat","rb");
   copia=fopen("temporal.dat","wb");

   //Si alguno de los dos archivos no fue abierto, la eliminación no se ejecuta
   if (!original || !copia)
      printf("No se puede realizar la operacion");
   else
   {
       printf("Numero de anuncio que desea eliminar: ");
       scanf("%d",&llave);
       ban=busqueda(llave);
	   //Elimina el registro si fue encontrado
       if (ban!=-1)
       {
           while(fread(&aux,sizeof(Anuncio),1,original)>0)
           {
               if(aux.numero!=llave)
                   fwrite(&aux,sizeof(Anuncio),1,copia);
           }
           fclose(original);
           fclose(copia);
           remove("registros.dat");
           rename("temporal.dat", "registros.dat");
           printf("\nBorrado...");getchar();
       }
       else
            printf("No se encontro");
   }
}

//Funcion que permite editar el anuncio con su numero
void editar()
{
    int ban,llave,clasif;
    char dato;
    Anuncio registro;

    FILE * flujo;
    setbuf(stdin,0);
    printf("Numero del anuncio: "); scanf("%d",&llave);
    ban=busqueda(llave);

    //Comparacion si se encontro un anuncio con el numero ingresado
    if (ban!=-1)
    {
        flujo= fopen("registros.dat","rb+");
        if (flujo!=NULL)
        {   fseek(flujo,(ban-1)*sizeof(Anuncio),SEEK_SET);
            fread(&registro,sizeof(Anuncio),1,flujo);
            printf("\n Encontrado en el Registro No. %d \n", ban);
            printf("\nNumero: %d \n",registro.numero);
            printf("a.)Clasificacion: %s \n", registro.clasificacion);
            printf("b.)Responsable: %s \n",registro.responsable);
            printf("c.)Telefono: %s \n",registro.telefono);
            printf("d.)Contenido: %s \n",registro.contenido);
            printf("e.)Fecha: %d/%d/%d \n", registro.fecha.dia,registro.fecha.mes,registro.fecha.anio);

            printf("\nIngrese la letra del dato que deseas modificar: "); scanf("%c",&dato);

            //Comparacion del dato que desea modificar
            switch(dato)
            {
                case 'a': setbuf(stdin,0);
                        printf("Clasificacion: ");
                        clasif = menuclasificacion();
                        strcpy(registro.clasificacion,elegirclasificacion(clasif));
                        break;
                case 'b': setbuf(stdin,0);
                        printf("Responsable: "); gets(registro.responsable);
                        break;
                case 'c': setbuf(stdin,0);
                        printf("Telefono: "); gets(registro.telefono);
                        break;
                case 'd': setbuf(stdin,0);
                        printf("Contenido: "); gets(registro.contenido);
                        break;
                case 'e': setbuf(stdin,0);
                        printf("Fecha(dia mes anio): "); scanf("%d %d %d",&registro.fecha.dia,&registro.fecha.mes,&registro.fecha.anio);
                        break;
            }
            fseek(flujo,(ban-1)*sizeof(Anuncio),SEEK_SET);
            fwrite(&registro,sizeof(Anuncio),1,flujo);
            fclose(flujo);
        }
        else
            printf("No se pudo abrir el archivo");
    }
    else
            printf("No se encontro");
}

//Funcion que permite la consulta por el nombre del responsable
void consultaresponsable()
{
    FILE * flujo;
    Anuncio registro;
    char nombre[20];
    int encontrado =-1;
    flujo= fopen("registros.dat","rb");
        setbuf(stdin,0);
        printf("\nIngrese el nombre del responsable que deseas consultar: ");
        gets(nombre);
    //Si se abrio el archivo, se realiza la busqueda
    if (flujo)
    {
        while((fread(&registro,sizeof(Anuncio),1,flujo)>0)&& !feof(flujo))
        {
            if (strcmpi(registro.responsable,nombre)== 0)
            {
                imprimir(registro);
                pausa();
                encontrado=0;
            }
        }
        //Imprime un mensaje si ningun anuncio cumple con dicha caracteristica
        if(encontrado==-1){
                printf("\nNo hay anuncios con dicho responsable");
                pausa();}
        fclose(flujo);
    }
}

//Funcion que permite la consulta por la clasificaciones
void consultaclasificacion()
{
    //Declaracion de los variables
    FILE * flujo;
    Anuncio registro;
    char clasificacion[15];
    int encontrado=-1;

    flujo= fopen("registros.dat","rb");
        setbuf(stdin,0);
        printf("\nIngrese la clasificacion que deseas consultar: ");
        gets(clasificacion);

     //Si se abrio el archivo, se realiza la busqueda
    if (flujo)
    {
        while((fread(&registro,sizeof(Anuncio),1,flujo)>0)&& !feof(flujo))
        {
            if (strcmpi(registro.clasificacion,clasificacion)== 0)
            {
                imprimir(registro);
                pausa();
                encontrado=0;
            }
        }
        //Imprime un mensaje si ningun anuncio cumple con dicha caracteristica
        if(encontrado==-1)
        {
            printf("\nNo hay anuncios con dicha clasificacion");
            pausa();
        }
        fclose(flujo);
    }
}

//Funcion que ordena los registros de acuerdo al nombre del responsable
void ordenar()
{
   FILE *flujo;
   int i, j;

   int n;
   Anuncio a,b;

   flujo=fopen("registros.dat","rb+");

   //Comparacion si el archivo se abre o no
   if (flujo==NULL)
      printf("No se puede realizar la operacion");
   else
   {       i=0;
           n=tamano(flujo)/sizeof(Anuncio);
           printf("Ordenando %d registros ", n);
           getchar();
           for(i=0;i<n-1;i++)
           {
              for(j=i+1;j<n;j++)
              {
                fseek(flujo,i*sizeof(Anuncio),SEEK_SET);
                fread(&a,sizeof(Anuncio),1,flujo);
                fseek(flujo,j*sizeof(Anuncio),SEEK_SET);
                fread(&b,sizeof(Anuncio),1,flujo);
                printf("%d, %d, %s con %s \n", i,j,a.responsable, b.responsable);
                getchar();
                if( strcmpi(a.responsable,b.responsable)>0)
                {
                    fseek(flujo,i*sizeof(Anuncio),SEEK_SET);
                    fwrite(&b,sizeof(Anuncio),1,flujo);
                    fseek(flujo,j*sizeof(Anuncio),SEEK_SET);
                    fwrite(&a,sizeof(Anuncio),1,flujo);
                }
              }
           }
           fclose(flujo);
       }
}
long int tamano(FILE *file)
{
    char buffer;
    long int size=0;
    fseek(file, 0, SEEK_SET);
    while(fread(&buffer, 1, 1, file)>0)size++;
    fseek(file, 0, SEEK_SET);
    return size;
}

//Funcion que muestra los anuncions actuales
void mostraranuncioactuales()
{
    FILE * flujo;
    Anuncio registro;
    int encontrado=-1;
    //Para sacar la fecha del sistema
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
	
    flujo= fopen("registros.dat","rb");
    if (flujo)
    {
        while((fread(&registro,sizeof(Anuncio),1,flujo)>0)&& !feof(flujo))
        {
            if((tm.tm_year + 1900)>=registro.fecha.anio && (tm.tm_mon + 1)>=registro.fecha.mes && (tm.tm_mday)>=registro.fecha.dia)
            {
                imprimir(registro);
                pausa();
                encontrado =0;
            }
        }
        //Imprime un mensaje si ningun anuncio cumple con dicha caracteristica
        if(encontrado==-1)
        {
            printf("\nNo hay anuncios actuales");
            pausa();
        }
        fclose(flujo);
    }
}

//Funcion que crea un respaldo de los registros actuales
void crearrespaldo()
{
   FILE *original, *copia;
   char respaldo[10],extension[] =".dat";
   Anuncio aux;

   printf("Ingrese el nombre del respaldo sin extension: ");
   setbuf(stdin, 0);
   gets(respaldo);

   //Abre los dos archivos
   original=fopen("registros.dat","rb");
   copia=fopen(strcat(respaldo, extension),"wb");

   //Comapracion si uno de los dos archivos no fue abierto
   if (!original || !copia)
      printf("No se puede realizar la operacion");
   else
   {
       while(fread(&aux,sizeof(Anuncio),1,original)>0)
       {
           fwrite(&aux,sizeof(Anuncio),1,copia);
       }
       fclose(original);
       fclose(copia);
       printf("\nRespaldo creado");
       pausa();
   }
}

//Función que crea un respaldo de texto 
void respaldo_texto()
{
    FILE * original,*respaldo;
	char nombre[10],extension[] =".txt";
    Anuncio registro;
	
	//Pide un nombre de archivo al usuario
	printf("Ingrese el nombre del respaldo sin extension: ");
	setbuf(stdin, 0);
	gets(nombre);
	
	//Abre los dos archivos
    original= fopen("registros.dat","rb");
    respaldo= fopen(strcat(nombre, extension),"w");
	
	//Si se abre el archivo se imprimen los registros en el nuevo archivo
    if (original)
    {
        while(fread(&registro,sizeof(Anuncio),1,original)>0)
        {
            fprintf(respaldo,"%d,",registro.numero);
            fprintf(respaldo,"%s,", registro.clasificacion);
            fprintf(respaldo,"%s,",registro.responsable);
            fprintf(respaldo,"%s,",registro.telefono);
            fprintf(respaldo,"%s,",registro.contenido);
            fprintf(respaldo,"%d/%d/%d\n",registro.fecha.dia,registro.fecha.mes,registro.fecha.anio);
        }
    }
    fclose(original);
    fclose(respaldo);
}


//Funcion que cuenta cuantos registros hay en el archivo
int tamano_archivo()
{
    FILE * flujo;
    Anuncio registro;
    int tamano=0;
	
    flujo= fopen("registros.dat","rb");
	//Cuenta la cantidad de registros del archivo
    if (flujo)
    {
        while((fread(&registro,sizeof(Anuncio),1,flujo)>0)&& !feof(flujo))
        {
            tamano++;
        }
        fclose(flujo);
    }
    return tamano;
}

//Funcion que lee los registros del archivo
void lectura(Anuncio *anuncioPtr)
{
    FILE * flujo;
    Anuncio registro;
    int size =0;

    flujo= fopen("registros.dat","rb");
	//Si el archivo se abre, lee los registros uno por uno y lo guarda en el arreglo
    if (flujo)
    {
        while((fread(&registro,sizeof(Anuncio),1,flujo)>0)&& !feof(flujo))
        {
            anuncioPtr[size].numero = registro.numero;
            strcpy(anuncioPtr[size].clasificacion,registro.clasificacion);
            strcpy(anuncioPtr[size].responsable,registro.responsable);
            strcpy(anuncioPtr[size].telefono,registro.telefono);
            strcpy(anuncioPtr[size].contenido,registro.contenido);
            anuncioPtr[size].fecha.anio = registro.fecha.anio;
            anuncioPtr[size].fecha.mes = registro.fecha.mes;
            anuncioPtr[size].fecha.dia = registro.fecha.dia;
            //imprimiranuncios(anuncioPtr,size);
            size++;
        }
        fclose(flujo);
    }
}

//Funcion que compara los registros de acuerdo a su fecha
int compararA_fecha(const void *a, const void *b)
{
    //Asigna todos los valores que contiene la estructura
    Anuncio anuncioA = *(Anuncio*)a;
    Anuncio anuncioB = *(Anuncio*)b;
    return ((anuncioA.fecha.anio)*10000+(anuncioA.fecha.mes)*100+(anuncioA.fecha.dia))-((anuncioB.fecha.anio)*10000+(anuncioB.fecha.mes)*100+(anuncioB.fecha.dia));
}

//Funcion que compara los registros de acuerdo a su numero
int compararA_num(const void *a, const void *b)
{
    //Asigna todos los valores que contiene la estructura
    Anuncio anuncioA = *(Anuncio*)a;
    Anuncio anuncioB = *(Anuncio*)b;
    return anuncioA.numero-anuncioB.numero;
}

//Funcion que compara los registros de acuerdo a su clasficacion
int compararA_clas(const void *a, const void *b)
{
    //Asigna todos los valores que contiene la estructura
    Anuncio anuncioA = *(Anuncio*)a;
    Anuncio anuncioB = *(Anuncio*)b;
    return strcmp(anuncioA.clasificacion, anuncioB.clasificacion);
}

//Funcion que imprime el registro en el archivo de texto para convertirlo a un archivo csv después
void imprimiranuncio(Anuncio *anuncioPtr, int registro)
{
    printf("%d\n",anuncioPtr[registro].numero);
    printf("%s\n",anuncioPtr[registro].clasificacion);
    printf("%s\n",anuncioPtr[registro].responsable);
    printf("%s\n",anuncioPtr[registro].telefono);
    printf("%s\n",anuncioPtr[registro].contenido);
    printf("%d/%d/%d\n",anuncioPtr[registro].fecha.dia,anuncioPtr[registro].fecha.mes,anuncioPtr[registro].fecha.anio);
    printf("\n");
}

//Funcion que imprime los anuncios
void imprimiranuncios(Anuncio *anuncioPtr, int n)
{
    int i;

    for(i=0;i<n;i++)
    {
        imprimiranuncio(anuncioPtr,i);
    }
}