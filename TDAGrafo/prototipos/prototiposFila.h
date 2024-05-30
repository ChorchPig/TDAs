#ifndef PROTOTIPOSFILA_H_INCLUDED
#define PROTOTIPOSFILA_H_INCLUDED

#define QNODE_ELEMENT int
#define QUEUE_ELEMENT nodoFila

typedef struct _nodeQueue {
    QNODE_ELEMENT valor;
    struct _nodeQueue *siguiente;
} nodoFila;

typedef struct _queue{
    QUEUE_ELEMENT* inicioFila;
    QUEUE_ELEMENT* finalFila;
    int maxSize, currentSize;
}Fila;

QUEUE_ELEMENT* crearNodoFila(QNODE_ELEMENT);
Fila* crearFila(int);
void enqueueValue(Fila**,QNODE_ELEMENT);
void enqueue(Fila**, QUEUE_ELEMENT*);
QUEUE_ELEMENT* dequeue(Fila**);
void dequeueFree(Fila**);
int filaLlena(Fila*);
int filaVacia(Fila*);
void eliminarFila(Fila**);
QNODE_ELEMENT getFirstValue(Fila*);
int existeEnFila(Fila**,QNODE_ELEMENT);
void imprimirFila(Fila**);
void invertirFila(Fila**);
Fila* copiarFila(Fila**);

#endif // PROTOTIPOSFILA_H_INCLUDED
