#include <stdio.h>
#include <stdlib.h>
#include "prototipos.h"

int main(){
    matrix *Matrix=crearMatriz(3, 3);
    Vector *vector=crearVector(3);
    if(!Matrix || !vector)printf("No memory allocated.\n");
    else{
        setValueInMatrix(Matrix, 1);
        setValueInMatrix(Matrix, 2);
        setValueInMatrix(Matrix, 3);
        setValueInMatrix(Matrix, 4);
        setValueInMatrix(Matrix, 5);
        setValueInMatrix(Matrix, 6);
        setValueInMatrix(Matrix, 7);
        setValueInMatrix(Matrix, 8);
        setValueInMatrix(Matrix, 9);
        imprimirMatriz(Matrix);
        agregarAlVector(vector, 10);
        agregarAlVector(vector, 11);
        agregarAlVector(vector, 12);
        sumarVectorAFilaMatriz(Matrix, vector, 0);
        printf("\n");
        imprimirMatriz(Matrix);
        eliminarVector(vector);
        eliminarMatriz(Matrix);
    }
    return 0;
}
