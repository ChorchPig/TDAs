#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED

#define STACK_ELEMENT int

typedef struct _node {
    STACK_ELEMENT valor;
    struct _node *siguiente;
} nodo;

nodo* crearNodo(STACK_ELEMENT);
void agregarAPila(nodo**,STACK_ELEMENT);
nodo* quitarNodoPila(nodo**);
int eliminarNodo(nodo**);
void imprimirPila(nodo*);
STACK_ELEMENT obtenerValorNodo(nodo*);
void eliminarPila(nodo**);


#endif // PROTOTIPOS_H_INCLUDED
