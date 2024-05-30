#include <stdio.h>
#include <stdlib.h>
#include "prototipos/prototipos.h"

int verticesAdyacentes(VECTOR_ELEMENT vertice1, VECTOR_ELEMENT vertice2);
int obtenerPesoArista(Grafo *grafo, char origen, char destino);
int obtenerCostoArista(Grafo*,char origen, char destino);


int main(){
    Grafo *grafo=crearGrafo(5);
    crearVertice(grafo, 'a');
    crearVertice(grafo, 'b');
    crearVertice(grafo, 'c');
    crearVertice(grafo, 'd');
    crearVertice(grafo, 'e');
    crearArista(grafo, 'a', 'c');
    crearArista(grafo, 'a', 'd');
    crearArista(grafo, 'b', 'd');
    crearArista(grafo, 'b', 'e');
    crearArista(grafo, 'a', 'c');
    crearArista(grafo, 'e', 'c');
    matrix *aristas=obtenerAristas(grafo);
    imprimirMatriz(aristas);
    printf("\n");
    char formato='c';
    recorridoAmplitud(grafo, imprimirVertice, &formato);
    eliminarVertice(grafo, 'a');
    aristas=obtenerAristas(grafo);
    printf("\n");
    imprimirMatriz(aristas);
    eliminarGrafo(grafo);
    return 0;
}

matrix* deleteRow(matrix *Matrix, int filaAEliminar){
    int filas=getMatrixRows(Matrix), columnas=getMatrixColumns(Matrix);
    matrix* nuevaMatriz=crearMatriz(filas-1, columnas);
    for(int i=0; i<filas; i++){
        if(i!=filaAEliminar){
            for(int j=0; j<columnas; j++)setValueInMatrix(nuevaMatriz, getValueInMatrix(Matrix, i,j),i,j);
        }
    }
    free(Matrix);
    return nuevaMatriz;
}

matrix* deleteColumn(matrix *Matrix, int columnaAEliminar){
    int filas=getMatrixRows(Matrix), columnas=getMatrixColumns(Matrix);
    matrix* nuevaMatriz=crearMatriz(filas, columnas-1);
    for(int j=0; j<columnas; j++){
        if(j!=columnaAEliminar){
            for(int i=0; i<filas; i++)setValueInMatrix(nuevaMatriz, getValueInMatrix(Matrix, i,j),i,j);
        }
    }
    free(Matrix);
    return nuevaMatriz;
}
