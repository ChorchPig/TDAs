#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED

#define NODE_ELEMENT int
#define QUEUE_ELEMENT nodo*

typedef struct _node {
    NODE_ELEMENT valor;
    struct _node *siguiente;
} nodo;

typedef struct _queue{
    QUEUE_ELEMENT inicioFila;
    QUEUE_ELEMENT finalFila;
    int maxSize, currentSize;
}Fila;

//Forman parte del TDA
QUEUE_ELEMENT crearNodo(NODE_ELEMENT);
Fila* crearFila(int);
void enqueue(Fila*,NODE_ELEMENT);
void enqueueNode(Fila*, QUEUE_ELEMENT);
QUEUE_ELEMENT dequeue(Fila*);
void dequeueFree(Fila*);
int filaLlena(Fila*);
int filaVacia(Fila*);
void eliminarFila(Fila*);
NODE_ELEMENT getFirstValue(Fila*);


//No forman parte del TDA
void imprimirFila(Fila*);
void invertirFila(Fila*);
Fila* copiarFila(Fila*);
NODE_ELEMENT sumarElementos(Fila*);

#endif // PROTOTIPOS_H_INCLUDED
