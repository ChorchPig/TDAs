#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED
#define MATRIX_ELEMENT int
#define VECTOR_ELEMENT int

typedef struct{
   MATRIX_ELEMENT* arreglo;
   int rows, columns, AmountOfElements;
} matrix;

typedef struct{
    VECTOR_ELEMENT *arreglo;
    int maxSize, currentSize;
}Vector;

matrix* crearMatriz(int,int);
void eliminarMatriz(matrix*);
int getMatrixRows(matrix*);
int getMatrixColumns(matrix*);
int getAmountOfElements(matrix *matrix);
MATRIX_ELEMENT getValueIn(matrix*,int,int);
void setValueInMatrix(matrix*,MATRIX_ELEMENT);
void imprimirMatriz(matrix*);
int matrixFull(matrix*);

void reemplazarFila(matrix*, Vector*, int fila);
void reemplazarColumna(matrix*, Vector*, int columna);

matrix* sumarDosMatrices(matrix*, matrix*);
MATRIX_ELEMENT sumarDosElementos(MATRIX_ELEMENT, MATRIX_ELEMENT);
matrix* multiplicarDosMatrices(matrix*, matrix*);
void sumarVectorAFilaMatriz(matrix*, Vector*, int);
void calcularDeterminante(matrix*);
Vector* resolverSistemaEcuaciones(matrix*);

Vector* crearVector(int);
int getCurrentSize(Vector*);
int getMaxSize(Vector*);
VECTOR_ELEMENT getValueInVector(Vector*,int);
int agregarAlVector(Vector*,VECTOR_ELEMENT);
int vectorLleno(Vector*);
int eliminarDelVector(Vector*,VECTOR_ELEMENT);
int borrarDato(Vector*,int);
void eliminarVector(Vector*);
int sequential_search(int,VECTOR_ELEMENT*,int);
int binary_search(int,Vector*);
void ordenarVector(Vector*);
int criterioComparacion(VECTOR_ELEMENT,VECTOR_ELEMENT);
void bubble_sort(VECTOR_ELEMENT*,int,int);
void swap(VECTOR_ELEMENT*,VECTOR_ELEMENT*);

Vector *extraerFila(matrix*,int);
matrix *trasponerMatriz(matrix*);
int productoEscalar(Vector*,Vector*);
matrix* copiarMatriz(matrix*);

#endif // PROTOTIPOS_H_INCLUDED
