#ifndef PROTOTIPOSVECTOR_H_INCLUDED
#define PROTOTIPOSVECTOR_H_INCLUDED

#define VECTOR_ELEMENT char

typedef struct{
    VECTOR_ELEMENT *arreglo;
    int maxSize, currentSize;
}Vector;

Vector* crearVector(int);
int getCurrentSize(Vector*);
int getMaxSize(Vector*);
VECTOR_ELEMENT getValueInVector(Vector*,int);
int agregarAlVector(Vector*,VECTOR_ELEMENT);
int vectorLleno(Vector*);
int eliminarDelVector(Vector*,VECTOR_ELEMENT);
int borrarDato(Vector*,int);
void eliminarVector(Vector*);

int criterioComparacion(VECTOR_ELEMENT elemento1, VECTOR_ELEMENT elemento2);
void swap(void*,void*);
void bubble_sort(VECTOR_ELEMENT *vector, int n, int criterio);
int sequential_search(VECTOR_ELEMENT,VECTOR_ELEMENT*,int);
int binary_search(int key, Vector *vector);

#endif // PROTOTIPOSVECTOR_H_INCLUDED
