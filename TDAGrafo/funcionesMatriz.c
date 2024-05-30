#include <stdio.h>
#include <stdlib.h>
#include "prototipos/prototiposMatriz.h"

matrix* crearMatriz(int filas, int columnas){
    matrix *Matrix=(matrix*)malloc(sizeof(matrix));
    if(!Matrix||filas<=0||columnas<=0)return Matrix;
    Matrix->arreglo=(MATRIX_ELEMENT *)malloc(sizeof(MATRIX_ELEMENT *)*filas*columnas);
    if(Matrix->arreglo){
        Matrix->rows=filas;
        Matrix->columns=columnas;
        for(int i=0; i<filas; i++){
            for(int j=0; j<columnas; j++) setValueInMatrix(Matrix, 0, i, j);
        }
    }
    return Matrix;
}

void eliminarDeMatriz(matrix *Matrix, int fila, int columna){
    if(Matrix)setValueInMatrix(Matrix, 0, fila, columna);
}

void eliminarMatriz(matrix* Matrix){
    free(Matrix->arreglo);
    free(Matrix);
}

int getMatrixRows(matrix* Matrix){
    return Matrix->rows;
}

int getMatrixColumns(matrix* Matrix){
    return Matrix->columns;
}

MATRIX_ELEMENT getValueInMatrix(matrix* Matrix, int row, int column){
    return Matrix->arreglo[row*Matrix->rows+column];
}

void setValueInMatrix(matrix* Matrix, MATRIX_ELEMENT value, int fila, int columna){
    if(Matrix){
        if(fila<0||fila>=Matrix->rows)return;
        if(columna<0||columna>=Matrix->columns)return;
        Matrix->arreglo[fila*Matrix->rows+columna]=value;
    }
}

void imprimirMatriz(matrix* Matrix){//void prt(void*), imprime una matriz 3*3 incluso si no hay valores asignados
    int columnas=getMatrixColumns(Matrix), filas=getMatrixRows(Matrix);
    for(int i=0; i<filas; i++){
        for(int j=0; j<columnas; j++)printf("%d ", getValueInMatrix(Matrix, i, j));
        printf("\n");
    }
}

Vector *extraerFila(matrix *Matrix, int fila){
    if(!Matrix)return NULL;
    if(fila<0||fila>=getMatrixRows(Matrix))return NULL;
    int longitud=getMatrixColumns(Matrix);
    Vector *vector=crearVector(longitud);
    for(int i=0; i<longitud;i++){
        agregarAlVector(vector, getValueInMatrix(Matrix, fila, i));
    }
    return vector;
}

Vector *extraerColumna(matrix *Matrix, int columna){
    if(!Matrix)return NULL;
    if(columna<0||columna>=getMatrixColumns(Matrix))return NULL;
    int longitud=getMatrixRows(Matrix);
    Vector *vector=crearVector(longitud);
    for(int i=0; i<longitud;i++){
        agregarAlVector(vector, getValueInMatrix(Matrix, i, columna));
    }
    return vector;
}

matrix* copiarMatriz(matrix *Matrix){
    if(!Matrix)return Matrix;
    int filas=getMatrixRows(Matrix), columnas=getMatrixColumns(Matrix);
    matrix *copiaMatriz=crearMatriz(filas, columnas);
    for(int i=0; i<filas; i++){
        for(int j=0; j<columnas; j++){
            setValueInMatrix(copiaMatriz, getValueInMatrix(Matrix, i, j), i, j);
        }
    }
    return copiaMatriz;
}

matrix *trasponerMatriz(matrix *Matrix){
    matrix *ptr=copiarMatriz(Matrix);
    if(ptr){
        int filas=getMatrixRows(ptr), columnas=getMatrixColumns(ptr);
        for(int i=0; i<filas; i++){
            for(int j=0; j<columnas; j++){
                if(i!=j)swap(&ptr->arreglo[i*filas+j], &ptr->arreglo[j*filas+i]);
            }
        }
    }
    return ptr;
}

matrix* ampliarMatriz(matrix *Matrix, int filas, int columnas){
    if(!Matrix)return Matrix;
    matrix *nuevaMatriz=crearMatriz(filas, columnas);
    if(nuevaMatriz){
        int filasViejas=getMatrixRows(Matrix), columnasViejas=getMatrixColumns(Matrix);
        for(int i=0; i<filas; i++){
            for(int j=0; j<columnas; j++){
                if(i<filasViejas&&j<columnasViejas){
                    setValueInMatrix(nuevaMatriz, getValueInMatrix(Matrix, i, j), i, j);
                }
            }
        }
        free(Matrix);
    }
    return nuevaMatriz;
}

int matrizSimetrica(matrix *Matrix){
    int simetrica=1;
    int i=0, filas=getMatrixRows(Matrix), columnas=getMatrixColumns(Matrix);
    while(i<filas&&simetrica){
        int j=i+1;
        while(j<columnas&&simetrica){
            if(getValueInMatrix(Matrix, i, j)!=getValueInMatrix(Matrix, j, i))simetrica=0;
            j++;
        }
        i++;
    }
    return simetrica;
}
