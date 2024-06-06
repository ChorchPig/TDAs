#include <stdio.h>
#include <stdlib.h>
#include "prototipos/prototiposMatriz.h"

matrix* crearMatriz(int filas, int columnas){
    matrix *Matrix=(matrix*)malloc(sizeof(matrix));
    if(!Matrix||filas<=0||columnas<=0)return Matrix;
    Matrix->datos=(MATRIX_ELEMENT **)malloc(sizeof(MATRIX_ELEMENT*)*filas);
    for(int i=0; i<filas; i++)Matrix->datos[i]=(MATRIX_ELEMENT*)calloc(columnas,sizeof(MATRIX_ELEMENT));
    if(Matrix->datos){
        Matrix->rows=filas;
        Matrix->columns=columnas;
    }
    return Matrix;
}

void eliminarValorMatriz(matrix *Matrix, int fila, int columna){
    if(Matrix)setValueInMatrix(Matrix, 0, fila, columna);
}

void eliminarMatriz(matrix* Matrix){
    for(int i=0; i<Matrix->rows; i++) free(Matrix->datos[i]);
    free(Matrix->datos);
    free(Matrix);
}

int getMatrixRows(matrix* Matrix){ return Matrix->rows; }
int getMatrixColumns(matrix* Matrix){ return Matrix->columns; }
MATRIX_ELEMENT getValueInMatrix(matrix* Matrix, int row, int column){ return Matrix->datos[row][column]; }

void setValueInMatrix(matrix* Matrix, MATRIX_ELEMENT value, int fila, int columna){
    if(Matrix&&fila>=0&&fila<Matrix->rows&&columna>=0&&columna<Matrix->columns){
        Matrix->datos[fila][columna]=value;
    }
}

void deleteRow(matrix *Matrix, int filaAEliminar){
    int filas=getMatrixRows(Matrix), columnas=getMatrixColumns(Matrix);
    for(int j=0; j<columnas; j++){
        for(int i=filaAEliminar; i<filas-1; i++){
            Matrix->datos[i][j]=Matrix->datos[i+1][j];
        }
    }
    MATRIX_ELEMENT **aux=&Matrix->datos[filas];
    Matrix->datos[filas]=NULL;
    free(*aux);
    Matrix->rows--;
}

void deleteColumn(matrix *Matrix, int columnaAEliminar){
    int filas=getMatrixRows(Matrix), columnas=getMatrixColumns(Matrix);
    for(int i=0; i<filas; i++){
        for(int j=columnaAEliminar; j<columnas-1; j++){
            Matrix->datos[i][j]=Matrix->datos[i][j+1];
        }
//        Matrix->datos[i][columnas-1]=0;
    }
    Matrix->columns--;
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

matrix *trasponerMatriz(matrix *Matrix){//Revisar más tarde
    matrix *ptr=copiarMatriz(Matrix);
    if(ptr){
        int filas=getMatrixRows(ptr), columnas=getMatrixColumns(ptr);
        for(int i=0; i<filas; i++){
            for(int j=0; j<columnas; j++){
                if(i!=j)swap(&ptr->datos[i][j], &ptr->datos[j][i]);
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
        eliminarMatriz(Matrix);
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

void imprimirMatriz(matrix* Matrix){//pasar el print como función
    int columnas=getMatrixColumns(Matrix), filas=getMatrixRows(Matrix);
    for(int i=0; i<filas; i++){
        for(int j=0; j<columnas; j++)printf("%d ", getValueInMatrix(Matrix, i, j));
        printf("\n");
    }
}
