#include <stdio.h>
#include <stdlib.h>
#include "prototipos/prototiposFila.h"

QUEUE_ELEMENT* crearNodoFila(NODE_ELEMENT element) {
    QUEUE_ELEMENT* new_node = (QUEUE_ELEMENT*)malloc(sizeof(QUEUE_ELEMENT));
    if (new_node){
        new_node->valor=element;
        new_node->siguiente=NULL;
    }
    return new_node;
}

Fila* crearFila(int maximo){
    Fila *fila=(Fila*)malloc(sizeof(fila));
    fila->inicioFila=NULL;
    fila->finalFila=NULL;
    fila->currentSize=0;
    fila->maxSize=maximo;
    return fila;
}

int filaLlena(Fila *fila){
    int estaLlena=0;
    if(!fila||fila->maxSize==-1)return estaLlena;
    if(fila->currentSize==fila->maxSize)estaLlena=1;
    return estaLlena;
}

int filaVacia(Fila *fila){
    int estaVacia=1;
    if(!fila)return estaVacia;
    if(fila->inicioFila)estaVacia=0;
    return estaVacia;
}

void enqueue(Fila *fila, NODE_ELEMENT element) {
    QUEUE_ELEMENT* aux=crearNodoFila(element);
    if(filaLlena(fila))return;
    if(fila->inicioFila){
        fila->finalFila->siguiente=aux;
        fila->finalFila=aux;
    }
    else {
        fila->inicioFila=aux;
        fila->finalFila=aux;
    }
    fila->currentSize++;
}

void enqueueNode(Fila *fila, QUEUE_ELEMENT* nuevoNodo){
    if(filaLlena(fila))return;
    if(fila->inicioFila){
        fila->finalFila->siguiente=nuevoNodo;
        fila->finalFila=nuevoNodo;
    }
    else {
        fila->inicioFila=nuevoNodo;
        fila->finalFila=nuevoNodo;
    }
    fila->currentSize++;
}

QUEUE_ELEMENT* dequeue(Fila *fila){
    QUEUE_ELEMENT* aux=fila->inicioFila;
    fila->inicioFila=fila->inicioFila->siguiente;
    aux->siguiente=NULL;
    fila->currentSize--;
    return aux;
}

void dequeueFree(Fila *fila){
    QUEUE_ELEMENT* aux=fila->inicioFila;
    fila->inicioFila=fila->inicioFila->siguiente;
    aux->siguiente=NULL;
    fila->currentSize--;
    free(aux);
}

NODE_ELEMENT getFirstValue(Fila *fila){
    return fila->inicioFila->valor;
}

void eliminarFila(Fila *fila){
    if(!fila)return;
    while(!filaVacia(fila))dequeueFree(fila);
    free(fila);
}

void imprimirFila(Fila *fila){
    if(!fila)return;
    Fila *aux=crearFila(fila->currentSize);
    QUEUE_ELEMENT* nodoAux=NULL;
    while(!filaVacia(fila)){
        nodoAux=dequeue(fila);
        printf("%d ", nodoAux->valor);
        enqueueNode(aux, nodoAux);
    }
    while(!filaVacia(aux)){
        nodoAux=dequeue(aux);
        enqueueNode(fila, nodoAux);
    }
    eliminarFila(aux);
    printf("\n");
}

void invertirFila(Fila *fila){
    int longitud=fila->currentSize;
    NODE_ELEMENT *arreglo=(NODE_ELEMENT*)malloc(sizeof(NODE_ELEMENT)*longitud);
    QUEUE_ELEMENT* nodoAux=NULL;
    for(int i=0; i<longitud; i++){
        nodoAux=dequeue(fila);
        arreglo[i]=nodoAux->valor;
    }
    for(int i=longitud; i>0; i--)enqueue(fila, arreglo[i-1]);
    free(arreglo);
}

NODE_ELEMENT sumarElementos(Fila *fila){
    int longitud=fila->currentSize;
    NODE_ELEMENT total=0;
    QUEUE_ELEMENT* nodoAux=NULL;
    Fila *aux=crearFila(fila->currentSize);
    for(int i=0; i<longitud; i++){
        nodoAux=dequeue(fila);
        total+=nodoAux->valor;
        enqueueNode(aux, nodoAux);
    }
    for(int i=0; i<longitud; i++){
        nodoAux=dequeue(aux);
        enqueueNode(fila, nodoAux);
    }
    eliminarFila(aux);
    return total;
}

Fila *copiarFila(Fila *fila){
    Fila *copiaFila=crearFila(fila->maxSize);
    int longitud=fila->currentSize;
    NODE_ELEMENT *arreglo=(NODE_ELEMENT*)malloc(sizeof(NODE_ELEMENT)*longitud);
    QUEUE_ELEMENT* nodoAux=NULL;
    for(int i=0; i<longitud; i++){
        nodoAux=dequeue(fila);
        arreglo[i]=nodoAux->valor;
    }
    for(int i=0; i<longitud; i++){
        enqueue(fila, arreglo[i]);
        enqueue(copiaFila, arreglo[i]);
    }
    free(arreglo);
    return copiaFila;
}
