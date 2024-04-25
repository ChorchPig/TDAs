#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "pototipos.h"

Pila* crearPila(int maxSize){
    Pila *pila=(Pila *)malloc(sizeof(Pila));
    if(!pila)return pila;
    pila->arreglo=(STACK_ELEMENT *)malloc(sizeof(STACK_ELEMENT)*maxSize);
    pila->maxSize=maxSize;
    pila->last=0;
    return pila;
}

void eliminarPila(Pila *pila){
    if(!pila)return;
    if(pila->arreglo)free(pila->arreglo);
    free(pila);
}

int pilaLlena(Pila *pila){
    int estaLlena=0;
    if(!pila)return estaLlena;
    if(pila->last==pila->maxSize)estaLlena=1;
    return estaLlena;
}

int pilaVacia(Pila *pila){
    int estaVacia=0;
    if(!pila)estaVacia=1;
    if(!pila->last)estaVacia=1;
    return estaVacia;
}

void push(Pila *pila, int elemento){
    if(pilaLlena(pila))return;
    pila->arreglo[pila->last]=elemento;
    pila->last++;
}

STACK_ELEMENT top(Pila *pila){
    if(!pila)return -1;
    if(!pila->last)return -1;
    return pila->arreglo[pila->last-1];
}

STACK_ELEMENT pop(Pila *pila){
    if(pilaVacia(pila))return -1;
    STACK_ELEMENT elemento=pila->arreglo[pila->last-1];
    pila->last--;
    return elemento;
}

void imprimirPila(Pila *pila){
    if(!pila)return;
    int longitud=pila->last;
    STACK_ELEMENT *aux=(STACK_ELEMENT *)malloc(sizeof(STACK_ELEMENT)*longitud);
    if(aux){
        for(int i=0; i<longitud; i++)aux[i]=pop(pila);
        for(int i=longitud; i>0; i--){
            printf("%d ", aux[i-1]);
            push(pila, aux[i-1]);
        }
    }
    printf("\n");
    free(aux);
}
