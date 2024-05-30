#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "prototipos/prototiposVector.h"

Vector* crearVector(int initialSize){
    Vector *ptr=(Vector *)malloc(sizeof(Vector));
    if(!ptr)return ptr;
    if(initialSize>0)ptr->arreglo=(VECTOR_ELEMENT *)malloc(sizeof(VECTOR_ELEMENT)*initialSize);
    if(!ptr->arreglo)return ptr;
    ptr->currentSize=0;
    ptr->maxSize=initialSize;
    return ptr;
}

int getCurrentSize(Vector *vector){
    return vector->currentSize;
}

int getMaxSize(Vector *vector){
    return vector->maxSize;
}

VECTOR_ELEMENT getValueInVector(Vector *vector, int position){
    return vector->arreglo[position];
}

int agregarAlVector(Vector *vector, VECTOR_ELEMENT valor){
    int resultado=0;
    if(vectorLleno(vector)){
        vector->arreglo=(VECTOR_ELEMENT *)realloc(vector->arreglo, sizeof(VECTOR_ELEMENT)*getMaxSize(vector)*2);
        if(!vector->arreglo)resultado=1;
    }
    if(resultado==0){
        vector->arreglo[getCurrentSize(vector)]=valor;
        vector->currentSize++;
    }
    return resultado;
}

int vectorLleno(Vector *vector){
    int estaLleno=0;
    if(getCurrentSize(vector)==getMaxSize(vector))estaLleno=-1;
    return estaLleno;
}

int eliminarDelVector(Vector *vector, VECTOR_ELEMENT valor){
    int position=sequential_search(valor, vector->arreglo, getCurrentSize(vector));
    if(position!=getCurrentSize(vector))borrarDato(vector, position);
    return position;
}

int borrarDato(Vector *vector, int position){
    int value = vector->arreglo[position], n=getCurrentSize(vector);
    vector->currentSize--;
    for (int i = position; i<n; i++) {
        vector->arreglo[i]=vector->arreglo[i+1];
    }
    return value;
}

void eliminarVector(Vector *vector){
    free(vector->arreglo);
    free(vector);
}

int sequential_search(VECTOR_ELEMENT key, VECTOR_ELEMENT *arreglo, int n){
    int i=0;
    while ((i<n)&&(arreglo[i]!=key)){
        i++;
    }
    return (i>=n)? -1 : i;
}

int binary_search(int key, Vector *vector){
    int low=0, high=getCurrentSize(vector)-1;
    int mid=(high-low)/2;
    while ((low<high)&&(vector->arreglo[mid]!=key)){
        if (key < vector->arreglo[mid]) {
            high=mid-1;
        } else{
            low=mid+1;
        }
        mid=(high+low)/2;
    }
    return (vector->arreglo[mid] == key) ? mid : getCurrentSize(vector);
}

void ordenarVector(Vector *vector){
    setlocale(LC_ALL, "spanish");
    int option=0;
    printf("Elige el orden de los elementos:\n\t1.Ascendente\n\t2.Descendente\n");
    scanf("%i", &option);
    (option==1)? bubble_sort(vector->arreglo, getCurrentSize(vector), criterioComparacion(2, 1)) : bubble_sort(vector->arreglo, getCurrentSize(vector), criterioComparacion(1, 2));
}

int criterioComparacion(VECTOR_ELEMENT elemento1, VECTOR_ELEMENT elemento2){ return elemento1-elemento2; }

void bubble_sort(VECTOR_ELEMENT *vector, int n, int criterio){
    char swapped = 1;
    while ((swapped!=0)&&(n>0)){
        swapped=0;
        for (int i=1; i<n; i++){
            if (criterioComparacion(vector[i-1], vector[i])>0&&criterio>0){
                swap(&vector[i-1], &vector[i]);
                swapped=1;
            }
            if (criterioComparacion(vector[i-1], vector[i])<0&&criterio<0){
                swap(&vector[i-1], &vector[i]);
                swapped=1;
            }
        }
        n--;
    }
}

void swap(void *a, void *b){
    void *aux = a;
    a = b;
    b = aux;
}
