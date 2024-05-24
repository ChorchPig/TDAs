#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED

#define NODE_ELEMENT int
#define STACK_ELEMENT nodo*


typedef struct _node {
    NODE_ELEMENT valor;
    struct _node *siguiente;
} nodo;

typedef struct _stack {
    STACK_ELEMENT tope;
    int maxSize, currentSize;
} Pila;

//Forman parte del TDA
Pila* crearPila(int);
void push(Pila*,NODE_ELEMENT);
void pushNode(Pila*,STACK_ELEMENT);
nodo* crearNodo(NODE_ELEMENT);
nodo* pop(Pila*);
void popFree(Pila*);
NODE_ELEMENT top(Pila*);
int getStackMaxSize(Pila*);
int getStackCurrentSize(Pila*);
int pilaLlena(Pila*);
int pilaVacia(Pila*);
void eliminarPila(Pila*);

//No forman parte del TDA
void imprimirPila(Pila*);
void invertirPila(Pila*);
Pila* copiarPila(Pila*);
NODE_ELEMENT sumarElementos(Pila*);

#endif // PROTOTIPOS_H_INCLUDED
