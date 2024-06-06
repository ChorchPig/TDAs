#ifndef PROTOTIPOSMATRIZ_H_INCLUDED
#define PROTOTIPOSMATRIZ_H_INCLUDED

#include "prototiposVector.h"
#define MATRIX_ELEMENT int

typedef struct{
   MATRIX_ELEMENT** datos;
   int rows, columns;
} matrix;

matrix* crearMatriz(int,int);
void setValueInMatrix(matrix*,MATRIX_ELEMENT,int,int);
int getMatrixRows(matrix*);
int getMatrixColumns(matrix*);
MATRIX_ELEMENT getValueInMatrix(matrix*,int,int);
void eliminarValorMatriz(matrix*,int,int);
void deleteRow(matrix*,int);
void deleteColumn(matrix*,int);
void eliminarMatriz(matrix*);
void imprimirMatriz(matrix*); //pasar el print como función
matrix* trasponerMatriz(matrix*); //Revisar más tarde
matrix* copiarMatriz(matrix*);
matrix* ampliarMatriz(matrix*,int,int);
Vector* extraerFila(matrix*,int);
Vector* extraerColumna(matrix*,int);
int matrizSimetrica(matrix*);


#endif // PROTOTIPOSMATRIZ_H_INCLUDED
