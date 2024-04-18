#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED

#define QUEUE_ELEMENT int

typedef struct _node {
    QUEUE_ELEMENT valor;
    struct _node *siguiente;
} nodo;

nodo* crearNodo(QUEUE_ELEMENT);
void queue_add(nodo**,QUEUE_ELEMENT);
nodo* quitarNodoFila(nodo**);
int eliminarNodo(nodo**);
void imprimirFila(nodo*);
QUEUE_ELEMENT obtenerValorNodo(nodo*);
void eliminarFila(nodo**);

#endif // PROTOTIPOS_H_INCLUDED
