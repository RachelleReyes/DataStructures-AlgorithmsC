#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Windows
#define CLEAR() system("CLS")
//UNIX
//#define CLEAR() system("clear")

struct articulo
{
  char descrip[50];
  int clave;
  int cantidad;
  float precio;
};

void captura(struct articulo * );
void grabar(struct articulo);
void mostrar();
int busqueda (char llave[] );
void borrar();
void editar ();
void ordenar();
long int tamano(FILE *);

int main()
{
    struct articulo registro;
    char opc;

    do
    {   CLEAR();
        puts("1) Dar de Alta");
        puts("2) Dar de Baja");
        puts("3) Editar");
        puts("4) Mostrar todos");
        puts("5) Ordenar");
        puts("0) Salir");
        printf("Opcion:");
        //Pasamos el bufer(teclado), limpia el teclado
        setbuf(stdin, 0);
        opc=getchar();

        switch(opc)
        {
            case '1':   captura(&registro);
                        grabar(registro);
                        break;
            case '2': borrar(); break;
            case '3': editar(); break;
            case '4': mostrar(); break;
            case '5': ordenar(); break;
        }
    }while (opc!=48);

    return 0;
}

void captura(struct articulo * registro)
{   float aux;
    CLEAR();
    printf("Clave: "); scanf("%d",&registro->clave);
    setbuf(stdin,0);
    printf("Descripcion: "); gets(registro->descrip);
    printf("Precio: "); scanf("%f",&aux);
    registro->precio=aux;
    printf("Cantidad:"); scanf("%d",&registro->cantidad);

}
void grabar(struct articulo registro)
{
    FILE * flujo;
    printf("\n Clave: %d",registro.clave);
    printf("\n Descripcion: %s ", registro.descrip);
    printf("\n Precio: %f",registro.precio);
    printf("\nCantidad: %d",registro.cantidad);
    getchar();
    flujo= fopen("registros.dat","ab");
    if (flujo!=NULL)
    {
        fwrite(&registro,sizeof(struct articulo),1,flujo);
        fclose(flujo);
    }
    else
        printf("No se pudo abrir");

}

void mostrar()
{
    FILE * flujo;
    struct articulo registro;
    int cont=1;
    flujo= fopen("registros.dat","rb");
    if (flujo)
    {
        while( fread(&registro,sizeof(struct articulo),1,flujo)>0)
        {
            printf("\n\n  Registro No. %d\n", cont);
            printf("Clave: %d \n", registro.clave);
            printf("Descripcion: %s \n", registro.descrip);
            printf("Precio: %f \n", registro.precio);
            printf("Cantidad: %d \n", registro.cantidad);
            setbuf(stdin,0);
            getchar();
            cont++;
        }
    }
    fclose(flujo);
}
int busqueda (char llave[] )
{
    FILE * flujo;
    struct articulo registro;
    int cont=0;
    flujo= fopen("registros.dat","rb");
    if (flujo)
    {
        while( fread(&registro,sizeof(struct articulo),1,flujo)>0)
        {
            cont++;
            if (strcmpi(registro.descrip,llave)==0)
            {
                printf("\n Clave: %d",registro.clave);
                printf("\n Descripcion: %s ", registro.descrip);
                printf("\n Precio: %f",registro.precio);
                printf("\n Cantidad: %d",registro.cantidad);
                getchar();
                fclose(flujo);
                return cont;
            }
        }
        fclose(flujo);

    }
    return -1;
}
void editar()
{
    int ban;
    char llave[50];
    struct articulo registro;

    FILE * flujo;
    setbuf(stdin,0);
    printf("Descripción del articulo: "); gets(llave);
    ban=busqueda(llave);

    if (ban!=-1)
    {
        flujo= fopen("registros.dat","rb+");
        if (flujo!=NULL)
        {   fseek(flujo,(ban-1)*sizeof(struct articulo),SEEK_SET);
            fread(&registro,sizeof(struct articulo),1,flujo);
            printf("\n Encontrado en el Registro No. %d \n", ban);
            printf("\n Clave: %d \n",registro.clave);
            printf("Descripcion: %s \n", registro.descrip);
            printf("Precio: %f \n",registro.precio);
            printf("Cantidad Actual: %d \n",registro.cantidad);
            printf("Escriba la nueva cantidad: "); scanf("%d",&registro.cantidad);
            fseek(flujo,(ban-1)*sizeof(struct articulo),SEEK_SET);
            fwrite(&registro,sizeof(struct articulo),1,flujo);
            fclose(flujo);
        }
        else
            printf("No se pudo abrir el archivo");
    }
    else
            printf("No se encontro");
}
void borrar()
{
   FILE *original, *copia;
   char llave[50];
   int ban;
   struct articulo aux;
   original=fopen("registros.dat","rb");
   copia=fopen("temporal.dat","wb");
   if (!original || !copia)
      printf("No se puede realizar la operacion");
   else
   {
       printf("Descripcion del articulo que desea eliminar: ");
       setbuf(stdin, 0);
       gets(llave);
       ban=busqueda(llave);
       if (ban!=-1)
       {
           while(fread(&aux,sizeof(struct articulo),1,original)>0)
           {    if(strcmpi(aux.descrip,llave)!=0)
                   fwrite(&aux,sizeof(struct articulo),1,copia);
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


void ordenar()
{
   FILE *flujo;
   int i, j;

   int n;
   struct articulo a,b;

   flujo=fopen("registros.dat","rb+");

   if (flujo==NULL)
      printf("No se puede realizar la operacion");
   else
   {       i=0;
           //fseek(flujo,0,SEEK_END);
           //n=ftell(flujo)/sizeof(struct articulo);
           n=tamano(flujo)/sizeof(struct articulo);
           printf("Ordenando %d registros ", n);
           getchar();
           for(i=0;i<n-1;i++)
           {
              for(j=i+1;j<n;j++)
              {
                fseek(flujo,i*sizeof(struct articulo),SEEK_SET);
                fread(&a,sizeof(struct articulo),1,flujo);
                fseek(flujo,j*sizeof(struct articulo),SEEK_SET);
                fread(&b,sizeof(struct articulo),1,flujo);
                printf("%d, %d, %s con %s \n", i,j,a.descrip, b.descrip);
                getchar();
                if( strcmpi(a.descrip,b.descrip)>0)
                {
                    fseek(flujo,i*sizeof(struct articulo),SEEK_SET);
                    fwrite(&b,sizeof(struct articulo),1,flujo);
                    fseek(flujo,j*sizeof(struct articulo),SEEK_SET);
                    fwrite(&a,sizeof(struct articulo),1,flujo);
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

