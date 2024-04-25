#ifndef POTOTIPOS_H_INCLUDED
#define POTOTIPOS_H_INCLUDED

#define STACK_ELEMENT int

typedef struct _pila{
    STACK_ELEMENT *arreglo;
    int last, maxSize;
}Pila;

Pila* crearPila(int);
void push(Pila*,STACK_ELEMENT);
STACK_ELEMENT pop(Pila*);
STACK_ELEMENT top(Pila*);
int pilaLlena(Pila*);
int pilaVacia(Pila*);
int getCurrentSize(Pila*);
int getMaxSize(Pila*);
void eliminarPila(Pila*);
void imprimirPila(Pila*);

#endif // POTOTIPOS_H_INCLUDED
