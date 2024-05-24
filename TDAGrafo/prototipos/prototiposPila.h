#ifndef PROTOTIPOSPILA_H_INCLUDED
#define PROTOTIPOSPILA_H_INCLUDED

#define NODE_ELEMENT int
#define STACK_ELEMENT nodoPila

typedef struct _nodeStack{
    NODE_ELEMENT valor;
    struct _nodeStack *siguiente;
} nodoPila;

typedef struct _stack {
    STACK_ELEMENT* tope;
    int maxSize, currentSize;
} Pila;

Pila* crearPila(int);
void push(Pila*,NODE_ELEMENT);
void pushNode(Pila*,STACK_ELEMENT*);
STACK_ELEMENT* crearNodoPila(NODE_ELEMENT);
STACK_ELEMENT* pop(Pila*);
void popFree(Pila*);
NODE_ELEMENT top(Pila*);
int getStackMaxSize(Pila*);
int getStackCurrentSize(Pila*);
int pilaLlena(Pila*);
int pilaVacia(Pila*);
void eliminarPila(Pila*);

void imprimirPila(Pila*);
void invertirPila(Pila*);
Pila* copiarPila(Pila*);

#endif // PROTOTIPOSPILA_H_INCLUDED
