#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED
#define VECTOR_ELEMENT int

typedef struct{
    VECTOR_ELEMENT *arreglo;
    int maxSize, currentSize;
}Vector;

Vector* crearVector(int);
int sumaElementosVector(Vector*);
int sumarDosVectores(Vector*, Vector*);
int apareceEnVector(Vector*, VECTOR_ELEMENT);
void ordenarVector(Vector*);//ascendente o descendente
void agregarYOrdenarVector(Vector*);
Vector* generarVectorOrdenado(Vector*);
int busquedaSecuencial(Vector*);
int busquedaBinaria(Vector*);
Vector* mezclarDosVectores(Vector*, Vector*);

#endif // PROTOTIPOS_H_INCLUDED
