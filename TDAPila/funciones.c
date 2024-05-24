#include <stdio.h>
#include <stdlib.h>
#include "prototipos.h"

Pila* crearPila(int cantMaxima){
    Pila *pila=(Pila*)malloc(sizeof(Pila));
    if(!pila)return pila;
    pila->maxSize=cantMaxima;
    pila->currentSize=0;
    pila->tope=NULL;
    return pila;
}

nodo* crearNodo(NODE_ELEMENT element) {
    nodo *new_node = (nodo*)malloc(sizeof(nodo));
    if (new_node){
        new_node->valor=element;
        new_node->siguiente=NULL;
    }
    return new_node;
}

void push(Pila *pila, NODE_ELEMENT element){
    if(pilaLlena(pila))return;
    if(!pila->tope)pila->tope=crearNodo(element);
    else{
        nodo *aux=crearNodo(element);
        aux->siguiente=pila->tope;
        pila->tope=aux;
    }
    pila->currentSize++;
}

void pushNode(Pila *pila, STACK_ELEMENT element){
    if(pilaLlena(pila))return;
    if(!pila->tope)pila->tope=element;
    else{
        element->siguiente=pila->tope;
        pila->tope=element;
    }
    pila->currentSize++;
}

nodo* pop(Pila *pila){
    nodo* nodoAEliminar = NULL;
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

NODE_ELEMENT top(Pila *pila){
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
    if(!pila)return llena;
    if(pila->maxSize==pila->currentSize)llena=1;
    return llena;
}

int pilaVacia(Pila *pila){
    if(!pila)return 1;
    if(!pila->tope) return 1;
    return 0;
}

void eliminarPila(Pila *pila){
    if(!pila)return;
    while(!pilaVacia(pila)){
        popFree(pila);
    }
    free(pila);
}

void imprimirPila(Pila *pila) {
    Pila *aux=crearPila(pila->currentSize);
    nodo *nodoAux=NULL;
    while(!pilaVacia(pila)){
        nodoAux=pop(pila);
        printf("%d ", nodoAux->valor);
        pushNode(aux, nodoAux);
    }
    printf("\n");
    while(!pilaVacia(aux)){
        nodoAux=pop(aux);
        pushNode(pila, nodoAux);
    }
    eliminarPila(aux);
}

void invertirPila(Pila *pila){
    int longitud=getStackCurrentSize(pila);
    Pila *aux1=crearPila(longitud), *aux2=crearPila(longitud);
    nodo *nodoAux=NULL;
    while(!pilaVacia(pila)){
        nodoAux=pop(pila);
        pushNode(aux1, nodoAux);
    }
    while(!pilaVacia(aux1)){
        nodoAux=pop(aux1);
        pushNode(aux2, nodoAux);
    }
    while(!pilaVacia(aux2)){
        nodoAux=pop(aux2);
        pushNode(pila, nodoAux);
    }
    eliminarPila(aux1);
    eliminarPila(aux2);
}

Pila* copiarPila(Pila *pila) {
    Pila *copiaPila=crearPila(getStackMaxSize(pila));
    int longitud=getStackCurrentSize(pila);
    NODE_ELEMENT *arreglo=(NODE_ELEMENT *)malloc(sizeof(NODE_ELEMENT)*longitud);
    nodo *nodoAux=NULL;
    for(int i=0; i<longitud; i++){
        nodoAux=pop(pila);
        arreglo[i]=nodoAux->valor;
        pushNode(copiaPila, nodoAux);
    }
    for(int i=0; i<longitud; i++)push(pila, arreglo[i]);
    invertirPila(copiaPila);
    invertirPila(pila);
    free(arreglo);
    return copiaPila;
}

NODE_ELEMENT sumarElementos(Pila *pila){
    Pila *aux=crearPila(getStackCurrentSize(pila));
    nodo *nodoAux=NULL;
    NODE_ELEMENT total=0;
    while(!pilaVacia(pila)){
        nodoAux=pop(pila);
        total+=nodoAux->valor;
        pushNode(aux, nodoAux);
    }
    while(!pilaVacia(aux)){
        nodoAux=pop(aux);
        pushNode(pila, nodoAux);
    }
    eliminarPila(aux);
    return total;
}
