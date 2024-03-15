#include <stdio.h>
#include <locale.h>
#include "prototipos.h"

Vector* crearVector(int initialSize){
    Vector *ptr=(Vector)malloc(sizeof(Vector));
    //verificar que ptr y arreglo no sean NULL
    ptr->arreglo=(VECTOR_ELEMENT *)malloc(sizeof(VECTOR_ELEMENT)*initialSize);
    //verificar que initialSize no sea 0
}

int agregarAlVector(Vector *, VECTOR_ELEMENT);
