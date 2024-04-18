#include <stdio.h>
#include <stdlib.h>
#include "prototipos.h"

int main(){
    nodo *fila=NULL;
    queue_add(&fila, 1);
    queue_add(&fila, 2);
    queue_add(&fila, 3);
    queue_add(&fila, 4);
    queue_add(&fila, 5);
    queue_add(&fila, 6);
    imprimirFila(fila);
    eliminarFila(&fila);
    return 0;
}
