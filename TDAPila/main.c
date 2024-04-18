#include <stdio.h>
#include <stdlib.h>
#include "prototipos.h"

int main(){
    nodo *pila=NULL;
    agregarAPila(&pila, 1);
    agregarAPila(&pila, 2);
    agregarAPila(&pila, 3);
    agregarAPila(&pila, 4);
    agregarAPila(&pila, 5);
    agregarAPila(&pila, 6);
    imprimirPila(pila);
    eliminarPila(&pila);
    return 0;
}
