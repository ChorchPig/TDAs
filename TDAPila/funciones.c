#include <stdio.h>
#include <stdlib.h>
#include "prototipos.h"

nodo* crearNodo(STACK_ELEMENT element) {
    nodo *new_node = (nodo*)malloc(sizeof(nodo));
    if (new_node){
        new_node->valor=element;
        new_node->siguiente=NULL;
    }
    return new_node;
}

void imprimirPila(nodo* head) {
    if(!head)return;
    nodo* aux = head;
    while(aux){
        printf("%d ", obtenerValorNodo(aux));
        aux = aux->siguiente;
    }
    printf("\n");
}

STACK_ELEMENT obtenerValorNodo(nodo *Nodo){
    return Nodo->valor;
}

void agregarAPila(nodo** head, STACK_ELEMENT element) {
    nodo* aux = crearNodo(element);
    aux->siguiente = *head;
    *head = aux;
}

nodo* quitarNodoPila(nodo** head){
    nodo* node_to_remove = NULL;
    nodo** aux = head;
    node_to_remove = *aux;
    *aux = (*aux)->siguiente;
    node_to_remove->siguiente = NULL;
    return node_to_remove;
}

int eliminarNodo(nodo** head){
    int result=0;
    if(!*head)return result;
    nodo** aux = head;
    nodo* node_to_remove=*aux;
    *aux=(*aux)->siguiente;
    node_to_remove->siguiente=NULL;
    free(node_to_remove);
    result = 1;
    return result;
}

void eliminarPila(nodo **pila){
    while(*pila)eliminarNodo(pila);
}
