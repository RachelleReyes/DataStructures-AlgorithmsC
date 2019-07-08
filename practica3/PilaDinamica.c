#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

struct nodo {
    int dato;
    struct nodo * ant;
};

int vacia(struct nodo *tope) {
    return (!tope)? 1:0;
}

struct nodo * crearnodo(int dato) {
    struct nodo* p;
    p=(struct nodo*)malloc (sizeof (struct nodo));
    p->dato=dato;
    p->ant=NULL;
    return(p);
}

struct nodo* push(struct nodo * tope,int dato) {
    struct nodo *aux;
    aux=crearnodo(dato);
    aux->ant=tope;
    tope=aux;
    return(tope);
}

void mostrar(struct nodo *tope){
    struct nodo *aux;
   // clrscr();
    if(!tope) printf("\nEsta vacia");
    else { aux=tope;
        do{
            printf("\n%d",aux->dato);
            aux=aux->ant;
        }while(aux!= NULL);
    }
    getch();
}

struct nodo* pop(struct nodo *tope,int* valor) {
    struct nodo *aux;
    int dato;
    aux=tope;
    *valor=tope->dato;
    tope=tope->ant;
    free(aux);
    return(tope);
}

void main() {
    struct nodo *tope=NULL;
    char opc;
    int dato,ban;

    do{
        //clrscr ();
        printf("\n 1. Push");
        printf("\n 2. Pop");
        printf("\n 3. Mostrar Pila");
        printf("\n 4. Salir");
        printf("\nOpcion: [ ]\b\b");
        opc=getche();

        switch(opc){
            case '1':
                //clrscr();
                printf("\nEscribe dato: ");
                scanf("%d",&dato);
                if(tope==NULL) tope=crearnodo(dato);
                else tope=push(tope,dato);
            break;

            case '2':
                //clrscr();
                if(!vacia(tope)) {
                    tope=pop(tope,&dato);
                    printf("\nEl dato en la cima es: %d",dato);
                }
                else printf("\nPila Vacia");
                getch();
            break;

            case '3':
                if (!vacia(tope)) mostrar(tope);
                else printf("\nPila Vacia");
            break;
            case '4':
            break;
        }
    }while(opc!='4');
}
