matrix* crearMatriz(int filas, int columnas)
crea un puntero a matrix con la cantidad de filas y columnas dadas, devuelve el puntero.

void eliminarMatrix(matrix *Matrix)
libera la memoria que ocupa Matrix

int getMatrixRows(matrix *Matrix)
int getMatrixColumns(matrix *Matrix)
MATRIX_ELEMENT getValueIn(matrix *Matrix, int fila, int columna)

void setValueInMatrix(matrix *Matrix, int fila, int columna, MATRIX_ELEMENT valor)
asigna valor en la posición de Matrix deseada

void imprimirMatriz(matrix *matrix, void ptr(void*))

int matrizLlena(matrix *Matrix)
devuelve 0 si Matrix no está llena, devuelve 1 si lo está

void reemplazarFila(matrix *Matrix, Vector *vector, int fila)
reemplaza los elementos de Matrix en la fila deseada, por los elementos en vector

void reemplazarColumna(matrix *Matrix, Vector *vector, int columna)
reemplaza los elementos de Matrix en la columna deseada, por los elementos en vector

MATRIX_ELEMENT sumarDosElementos(MATRIX_ELEMENT elementos1, MATRIX_ELEMENT elementos2)
matrix* sumarDosMatrices(matrix *Matrix1, matrix *Matrix2)
devuelve un puntero a matrix con el resultado de sumar los elementos de dos matrices de mismas dimensiones

void multiplicarDosMatrices(matrix *Matrix1, matrix *Matrix2)
devuelve un puntero a matrix con el resultado de multiplicar los elementos de dos matrices de mismas dimensiones

void sumarVectorAFilasMatriz(matrix *Matrix, Vector *vector)
suma los elementos de vector en Matrix

void calcularDeterminante(matrix *Matrix)
calcula el determinante de Matrix

Vector* resolverSistemaEcuaciones(matrix *Matrix)
resuelve un sistema de ecuaciones n ecuaciones con n incógnitas, usando como coeficientes los dados en Matrix. Devuelve un puntero a Vector con los valores de las incógnitas