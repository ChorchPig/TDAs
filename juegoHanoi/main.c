#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "pototipos.h"

void imprimirPilas(Pila**, int);
void moverDisco(Pila**,int,int,int);

int main(){
    setlocale(LC_ALL, "spanish");
    int totalPilas, discos, option=1, origen, destino;
    printf("Cantidad de pilas: ");
    scanf("%i", &totalPilas);
    printf("\nCantidad de discos: ");
    scanf("%i", &discos);
    Pila **pilas=(Pila **)malloc(sizeof(Pila*)*totalPilas);
    for(int i=0; i<totalPilas; i++)pilas[i]=crearPila(discos);
    for(int i=discos; i>0; i--)push(pilas[0], i);
    while(option){
        for(int i=0; i<totalPilas; i++)imprimirPila(pilas[i]);
        printf("0. Salir del programa\n1.Mover disco\n");
        scanf("%i", &option);
        if(option){
            printf("\nOrigen: ");
            scanf("%i", &origen);
            printf("\nDestino: ");
            scanf("%i", &destino);
            moverDisco(pilas, totalPilas, origen, destino);
        }
    }
    for(int i=0; i<totalPilas; i++)eliminarPila(pilas[i]);
    free(pilas);
    return 0;
}

void moverDisco(Pila **pilas, int totalPilas, int origen, int destino){
    if(origen<0||origen>=totalPilas||destino<0||destino>=totalPilas)return;
    //verificar movimientos ilegales
    STACK_ELEMENT elemento=pop(pilas[origen]);
    push(pilas[destino], elemento);
}
