#ifndef PROTOTIPOSPILA_H_INCLUDED
#define PROTOTIPOSPILA_H_INCLUDED

#define SNODE_ELEMENT int
#define STACK_ELEMENT nodoPila

typedef struct _nodeStack{
    SNODE_ELEMENT valor;
    struct _nodeStack *siguiente;
} nodoPila;

typedef struct _stack {
    STACK_ELEMENT* tope;
    int maxSize, currentSize;
} Pila;

Pila* crearPila(int);
void push(Pila*,SNODE_ELEMENT);
void pushNode(Pila*,STACK_ELEMENT*);
STACK_ELEMENT* crearNodoPila(SNODE_ELEMENT);
STACK_ELEMENT* pop(Pila*);
void popFree(Pila*);
SNODE_ELEMENT top(Pila*);
int getStackMaxSize(Pila*);
int getStackCurrentSize(Pila*);
int pilaLlena(Pila*);
int pilaVacia(Pila*);
void eliminarPila(Pila**);
int existeEnPila(Pila*,SNODE_ELEMENT);
void imprimirPila(Pila*);
void invertirPila(Pila*);
Pila* copiarPila(Pila*);

#endif // PROTOTIPOSPILA_H_INCLUDED
