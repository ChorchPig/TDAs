#include <stdio.h>
#include <stdlib.h>
#include "prototipos.h"

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
    int grado=obtenerGradoVertice(grafo, 0);
    printf("%d\n", grado);
    eliminarGrafo(grafo);
    return 0;
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
        free(Matrix);
    }
    return nuevaMatriz;
}

int obtenerCantVertices(Grafo *grafo){
    return grafo->vertices->currentSize;
}
