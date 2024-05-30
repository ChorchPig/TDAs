#include <stdio.h>
#include <stdlib.h>
#include "prototipos/prototiposPila.h"

STACK_ELEMENT* crearNodoPila(SNODE_ELEMENT element) {
    STACK_ELEMENT* new_node = (STACK_ELEMENT*)malloc(sizeof(STACK_ELEMENT));
    if (new_node){
        new_node->valor=element;
        new_node->siguiente=NULL;
    }
    return new_node;
}

Pila* crearPila(int cantMaxima){
    Pila *pila=(Pila*)malloc(sizeof(Pila));
    if(!pila)return pila;
    pila->maxSize=cantMaxima;
    pila->currentSize=0;
    pila->tope=NULL;
    return pila;
}

SNODE_ELEMENT top(Pila *pila){
    return pila->tope->valor;
}

int getStackMaxSize(Pila *pila){
    return pila->maxSize;
}

int getStackCurrentSize(Pila *pila){
    return pila->currentSize;
}

int pilaLlena(Pila *pila){
    int llena=0;
    if(!pila||pila->maxSize==-1)return llena;
    if(pila->maxSize==pila->currentSize)llena=1;
    return llena;
}

int pilaVacia(Pila *pila){
    return (!pila||!pila->tope)? 1: 0;
}

void pushValue(Pila *pila, SNODE_ELEMENT element){
    if(pilaLlena(pila)||existeEnPila(pila, element))return;
    STACK_ELEMENT* aux=crearNodoPila(element);
    push(pila, aux);
}

void push(Pila *pila, STACK_ELEMENT* element){
    if(pilaLlena(pila)||existeEnPila(pila, element->valor))return;
    if(!pila->tope)pila->tope=element;
    else{
        element->siguiente=pila->tope;
        pila->tope=element;
    }
    pila->currentSize++;
}

STACK_ELEMENT* pop(Pila *pila){
    STACK_ELEMENT* nodoAEliminar = NULL;
    if(pila->tope){
        nodoAEliminar=pila->tope;
        pila->tope=pila->tope->siguiente;
        nodoAEliminar->siguiente=NULL;
        pila->currentSize--;
    }
    return nodoAEliminar;
}

void popFree(Pila *pila){
    if(pila->tope) free(pop(pila));
}

void eliminarPila(Pila **pila){
    if(!*pila)return;
    while(!pilaVacia(*pila)) popFree(*pila);
    free(*pila);
}

void imprimirPila(Pila *pila) {
    Pila *aux=crearPila(pila->currentSize);
    STACK_ELEMENT* nodoAux=NULL;
    while(!pilaVacia(pila)){
        nodoAux=pop(pila);
        printf("%d ", nodoAux->valor);
        push(aux, nodoAux);
    }
    printf("\n");
    while(!pilaVacia(aux)){
        nodoAux=pop(aux);
        push(pila, nodoAux);
    }
    eliminarPila(&aux);
}

void invertirPila(Pila *pila){
    if(!pila)return;
    int longitud=getStackCurrentSize(pila);
    SNODE_ELEMENT *arreglo=(SNODE_ELEMENT*)malloc(sizeof(SNODE_ELEMENT)*longitud);
    STACK_ELEMENT* nodoAux=NULL;
    for(int i=0; i<longitud; i++){
        nodoAux=pop(pila);
        arreglo[i]=nodoAux->valor;
        free(nodoAux);
    }
    for(int i=0; i<longitud; i++)pushValue(pila, arreglo[i]);
    free(arreglo);
}

Pila* copiarPila(Pila *pila) {
    if(!pila)return NULL;
    int longitud=getStackCurrentSize(pila);
    Pila *copiaPila=crearPila(longitud);
    SNODE_ELEMENT *arreglo=(SNODE_ELEMENT *)malloc(sizeof(SNODE_ELEMENT)*longitud);
    STACK_ELEMENT* nodoAux=NULL;
    for(int i=0; i<longitud; i++){
        nodoAux=pop(pila);
        arreglo[i]=nodoAux->valor;
        push(copiaPila, nodoAux);
    }
    for(int i=longitud; i>0; i--)pushValue(pila, arreglo[i-1]);
    invertirPila(copiaPila);
    free(arreglo);
    return copiaPila;
}

int existeEnPila(Pila *pila, SNODE_ELEMENT element){
    int existe=0;
    if(pila&&!pilaVacia(pila)){
        Pila *aux=crearPila(pila->currentSize);
        STACK_ELEMENT* nodoAux=NULL;
        while(!pilaVacia(pila)){
            nodoAux=pop(pila);
            if(nodoAux->valor==element)existe=1;
            push(aux, nodoAux);
        }
        while(!pilaVacia(aux)){
            nodoAux=pop(aux);
            push(pila, nodoAux);
        }
        eliminarPila(&aux);
    }
    return existe;
}
