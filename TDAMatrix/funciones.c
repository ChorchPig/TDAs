#include <stdio.h>
#include <stdlib.h>
#include "prototipos.h"

matrix* crearMatriz(int filas, int columnas){
    matrix *Matrix=(matrix*)malloc(sizeof(matrix));
    if(!Matrix)return Matrix;
    if(filas==0||columnas==0)return Matrix;
    Matrix->arreglo=(MATRIX_ELEMENT *)malloc(sizeof(MATRIX_ELEMENT *)*filas*columnas);
    if(Matrix->arreglo){
        Matrix->rows=filas;
        Matrix->columns=columnas;
        Matrix->AmountOfElements=0;
    }
    return Matrix;
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

int getAmountOfElements(matrix *Matrix){
    return Matrix->AmountOfElements;
}

MATRIX_ELEMENT getValueIn(matrix* Matrix, int row, int column){
    return Matrix->arreglo[row*getMatrixRows(Matrix)+column];
}

void setValueInMatrix(matrix* Matrix, MATRIX_ELEMENT value){
    if(!matrixFull(Matrix)){
        Matrix->arreglo[getAmountOfElements(Matrix)]=value;
        Matrix->AmountOfElements++;
    }
}

int matrixFull(matrix *Matrix){
    if(getMatrixColumns(Matrix)*getMatrixRows(Matrix)==getAmountOfElements(Matrix))return 1;
    return 0;
}

void imprimirMatriz(matrix* Matrix){//void prt(void*), imprime una matriz 3*3 incluso si no hay valores asignados
    int columnas=getMatrixColumns(Matrix), filas=getMatrixRows(Matrix);
    for(int i=0; i<filas; i++){
        for(int j=0; j<columnas; j++)printf("%d ", getValueIn(Matrix, i, j));
        printf("\n");
    }
}

void reemplazarFila(matrix *Matrix, Vector *vector, int fila){
    int vectorSize=getCurrentSize(vector);
    if(fila<0||fila>=getMatrixRows(Matrix))return;
    if(vectorSize>getMatrixColumns(Matrix))return;
    for(int i=0; i<vectorSize; i++)Matrix->arreglo[fila*getMatrixRows(Matrix)+i]=vector->arreglo[i];
}

void reemplazarColumna(matrix *Matrix, Vector *vector, int columna){
    int vectorSize=getCurrentSize(vector);
    if(columna<0||columna>=getMatrixColumns(Matrix))return;
    if(vectorSize>getMatrixRows(Matrix))return;
    for(int i=0; i<vectorSize; i++)Matrix->arreglo[i*getMatrixRows(Matrix)+columna]=vector->arreglo[i];
}

matrix* sumarDosMatrices(matrix *Matrix1, matrix *Matrix2){
    int filas=getMatrixRows(Matrix1), columnas=getMatrixColumns(Matrix1);
    if(getMatrixRows(Matrix1)!=getMatrixRows(Matrix2)||getMatrixColumns(Matrix1)!=getMatrixColumns(Matrix2))return NULL;
    matrix *resultado=crearMatriz(filas, columnas);
    for(int i=0; i<filas; i++){
        for(int j=0; j<columnas; j++){
            resultado->arreglo[i*filas+j]=sumarDosElementos(getValueIn(Matrix1,i,j), getValueIn(Matrix2,i,j));
        }
    }
    return resultado;
}

void sumarVectorAFilaMatriz(matrix *Matrix, Vector *vector, int fila){
    int vectorSize=getCurrentSize(vector);
    if(fila<0||fila>=getMatrixRows(Matrix))return;
    if(vectorSize>getMatrixColumns(Matrix))return;
    for(int i=0; i<vectorSize; i++)Matrix->arreglo[fila*getMatrixRows(Matrix)+i]+=vector->arreglo[i];
}

MATRIX_ELEMENT sumarDosElementos(MATRIX_ELEMENT elemento1, MATRIX_ELEMENT elemento2){
    return elemento1+elemento2;
}

matrix *multiplicarDosMatrices(matrix *Matrix1, matrix *Matrix2){
    if(getMatrixRows(Matrix2)!=getMatrixColumns(Matrix1))return NULL;
    matrix *ptr=crearMatriz(getMatrixRows(Matrix1), getMatrixColumns(Matrix2));
    matrix *Matrix2Traspuesta=trasponerMatriz(Matrix2);
    Vector *vector1=NULL, *vector2=NULL;
    int filas=getMatrixRows(ptr), columnas=getMatrixColumns(ptr), valor=0;
    for(int i=0; i<filas; i++){
        for(int j=0; j<columnas; j++){
            vector1=extraerFila(Matrix1, i);
            vector2=extraerFila(Matrix2Traspuesta, j);
            valor=productoEscalar(vector1, vector2);
            setValueInMatrix(ptr, valor);
        }
    }
    return ptr;
}

matrix *trasponerMatriz(matrix *Matrix){
    matrix *ptr=copiarMatriz(Matrix);
    int filas=getMatrixRows(ptr), columnas=getMatrixColumns(ptr);
    for(int i=0; i<filas; i++){
        for(int j=0; j<columnas; j++){
            if(i!=j)swap(&ptr->arreglo[i*filas+j], &ptr->arreglo[j*filas+i]);
        }
    }
    return ptr;
}

Vector *extraerFila(matrix *Matrix, int fila){
    if(fila<0||fila>=getMatrixRows(Matrix))return NULL;
    int longitud=getMatrixColumns(Matrix);
    Vector *vector=crearVector(longitud);
    for(int i=0; i<longitud;i++){
        agregarAlVector(vector, getValueIn(Matrix, fila, i));
    }
    return vector;
}

matrix* copiarMatriz(matrix *Matrix){
    int filas=getMatrixRows(Matrix), columnas=getMatrixColumns(Matrix);
    matrix *copiaMatriz=crearMatriz(filas, columnas);
    for(int i=0; i<filas; i++){
        for(int j=0; j<columnas; j++){
            setValueInMatrix(copiaMatriz, getValueIn(Matrix, i, j));
        }
    }
    return copiaMatriz;
}
