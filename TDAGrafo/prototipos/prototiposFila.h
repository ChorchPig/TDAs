#ifndef PROTOTIPOSFILA_H_INCLUDED
#define PROTOTIPOSFILA_H_INCLUDED

#define NODE_ELEMENT int
#define QUEUE_ELEMENT nodoFila

typedef struct _nodeQueue {
    NODE_ELEMENT valor;
    struct _nodeQueue *siguiente;
} nodoFila;

typedef struct _queue{
    QUEUE_ELEMENT* inicioFila;
    QUEUE_ELEMENT* finalFila;
    int maxSize, currentSize;
}Fila;

QUEUE_ELEMENT* crearNodoFila(NODE_ELEMENT);
Fila* crearFila(int);
void enqueue(Fila*,NODE_ELEMENT);
void enqueueNode(Fila*, QUEUE_ELEMENT*);
QUEUE_ELEMENT* dequeue(Fila*);
void dequeueFree(Fila*);
int filaLlena(Fila*);
int filaVacia(Fila*);
void eliminarFila(Fila*);
NODE_ELEMENT getFirstValue(Fila*);

void imprimirFila(Fila*);
void invertirFila(Fila*);
Fila* copiarFila(Fila*);

#endif // PROTOTIPOSFILA_H_INCLUDED
