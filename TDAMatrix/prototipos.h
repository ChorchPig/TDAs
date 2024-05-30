#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED

#include "prototiposVector.h"
#define MATRIX_ELEMENT int

typedef struct{
   MATRIX_ELEMENT* arreglo;
   int rows, columns;
} matrix;

matrix* crearMatriz(int,int);
void eliminarDeMatriz(matrix*,int,int);
void eliminarMatriz(matrix*);
int getMatrixRows(matrix*);
int getMatrixColumns(matrix*);
MATRIX_ELEMENT getValueInMatrix(matrix*,int,int);
void setValueInMatrix(matrix*,MATRIX_ELEMENT,int,int);
void imprimirMatriz(matrix*);
matrix* trasponerMatriz(matrix*);
matrix* copiarMatriz(matrix*);
matrix* ampliarMatriz(matrix*,int,int);
Vector* extraerFila(matrix*,int);
Vector* extraerColumna(matrix*,int);
int matrizSimetrica(matrix*);
matrix* deleteRow(matrix*,int);
matrix* deleteColumn(matrix*,int);

#endif // PROTOTIPOS_H_INCLUDED
