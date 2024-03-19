#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED
#define VECTOR_ELEMENT int

typedef struct{
    VECTOR_ELEMENT *arreglo;
    int maxSize, currentSize;
}Vector;

Vector* crearVector(int);
int agregarAlVector(Vector *, VECTOR_ELEMENT);
int vectorLleno(Vector *);
int getCurrentSize(Vector*);
int getMaxSize(Vector*);
int eliminarDelVector(Vector*,VECTOR_ELEMENT);
int borrarDato(Vector*,int);
void eliminarVector(Vector*);
void imprimirVector(Vector*);
Vector* copiarVector(Vector*);

int sumaElementosVector(Vector*);
Vector* sumarDosVectores(Vector*, Vector*);

int apareceEnVector(Vector*, VECTOR_ELEMENT);

void agregarYOrdenarVector(Vector*, VECTOR_ELEMENT);
Vector* generarVectorOrdenado(Vector*);

Vector* mezclarDosVectores(Vector*, Vector*);

int sequential_search(int,VECTOR_ELEMENT*,int);
int binary_search(int, Vector*);

void ordenarVector(Vector*);
void bubble_sort(VECTOR_ELEMENT*,int,int);
int criterioComparacion(VECTOR_ELEMENT, VECTOR_ELEMENT);
void swap(VECTOR_ELEMENT*,VECTOR_ELEMENT*);

#endif // PROTOTIPOS_H_INCLUDED
