#include <stdio.h>
#include <stdlib.h>
#include "prototipos/prototipos.h"

Grafo* crearGrafo(int vertices){
    Grafo *nuevoGrafo=(Grafo *)malloc(sizeof(Grafo));
    if(nuevoGrafo){
        nuevoGrafo->vertices=crearVector(vertices);
        nuevoGrafo->aristas=crearMatriz(vertices, vertices);
    }
    return nuevoGrafo;
}

void eliminarGrafo(Grafo *grafo){
    free(grafo->aristas);
    free(grafo->vertices);
    free(grafo);
}

void crearVertice(Grafo *grafo, VECTOR_ELEMENT vertice){
    if(!grafo) return;
    agregarAlVector(grafo->vertices, vertice);
    int cantVertices=getCurrentSize(grafo->vertices), filasMatriz=getMatrixRows(grafo->aristas);
    if(cantVertices>filasMatriz)ampliarMatriz(grafo->aristas, cantVertices, cantVertices);
}

void eliminarVertice(Grafo *grafo, VECTOR_ELEMENT vertice){
    if(!grafo) return;
    eliminarDelVector(grafo->vertices, vertice);
}

void crearArista(Grafo *grafo, VECTOR_ELEMENT origen, VECTOR_ELEMENT destino){
    if(!grafo) return;
    Vector *vertices=obtenerVertices(grafo);
    int indiceOrigen=sequential_search(origen, vertices->arreglo, vertices->currentSize);
    int indiceDestino=sequential_search(destino, vertices->arreglo, vertices->currentSize);
    if(indiceOrigen>-1&&indiceDestino>-1){
        setValueInMatrix(grafo->aristas, 1, indiceOrigen, indiceDestino);
        setValueInMatrix(grafo->aristas, 1, indiceDestino, indiceOrigen); //esta invocación es por que el grafo no es dirigido
    }
}

void eliminarArista(Grafo *grafo, VECTOR_ELEMENT origen, VECTOR_ELEMENT destino){
    if(!grafo) return;
    Vector *vertices=obtenerVertices(grafo);
    int indiceOrigen=sequential_search(origen, vertices->arreglo, vertices->currentSize);
    int indiceDestino=sequential_search(destino, vertices->arreglo, vertices->currentSize);
    if(indiceOrigen>-1&&indiceDestino>-1){
        eliminarDeMatriz(grafo->aristas, indiceOrigen, indiceDestino);
        eliminarDeMatriz(grafo->aristas, indiceDestino, indiceOrigen); //esta invocación es por que el grafo no es dirigido
    }
}

Vector* obtenerVertices(Grafo *grafo){ return grafo->vertices; }
matrix* obtenerAristas(Grafo *grafo){ return grafo->aristas; }

int obtenerCantVertices(Grafo *grafo){
    return grafo->vertices->currentSize;
}

int obtenerGradoVertice(Grafo *grafo, int verticeIndice){
    int grado=-1;
    Vector *conexiones=extraerFila(grafo->aristas, verticeIndice);
    if(conexiones){
        grado=0;
        int longitud=getCurrentSize(conexiones);
        for(int i=0; i<longitud; i++){
            if(getValueInVector(conexiones, i))grado++;
        }
        free(conexiones);
    }
    return grado;
}

void recorridoAmplitud(Grafo *grafo, void grafo_do(), void *contexto){
    if(!grafo)return;
    int longitud=obtenerCantVertices(grafo), position=0;
    int *visitados=(int*)calloc(longitud, sizeof(int));
    QUEUE_ELEMENT* nodoAux;
    Vector *aristas;
    Fila *aux=crearFila(-1);
    enqueue(aux, position);
    while(!filaVacia(aux)){
        nodoAux=dequeue(aux);
        position=nodoAux->valor;
        visitados[position]=1;
        aristas=extraerFila(obtenerAristas(grafo), position);
        for(int i=0; i<longitud; i++){
            if(getValueInVector(aristas, i)&&!visitados[i]) enqueue(aux, i);
        }
        grafo_do(grafo, position, contexto);
        free(nodoAux);
        eliminarVector(aristas);
    }
    eliminarFila(aux);
    free(visitados);
}

void recorridoProfundidad(Grafo *grafo, void grafo_do(), void *contexto){
    if(!grafo)return;
    int longitud=obtenerCantVertices(grafo), position=0;
    int *visitados=(int*)calloc(longitud, sizeof(int));
    STACK_ELEMENT* nodoAux;
    Vector *aristas;
    Pila *aux=crearPila(-1);
    push(aux, position);
    while(!pilaVacia(aux)){
        nodoAux=pop(aux);
        position=nodoAux->valor;
        visitados[position]=1;
        aristas=extraerFila(obtenerAristas(grafo), position);
        for(int i=0; i<longitud; i++){
            if(getValueInVector(aristas, i)&&!visitados[i]) push(aux, i);
        }
        grafo_do(grafo, position, contexto);
        free(nodoAux);
        eliminarVector(aristas);
    }
    eliminarPila(aux);
    free(visitados);
}

void imprimirVertice(Grafo *grafo, int position, char *formato){
    Vector *vertices=obtenerVertices(grafo);
    switch(*formato){
        case 'i': printf("%d ", getValueInVector(vertices, position)); break;
        case 'f': printf("%.2f ", getValueInVector(vertices, position)); break;
        case 'c': printf("%c ", getValueInVector(vertices, position)); break;
        case 's': printf("%s ", getValueInVector(vertices, position)); break;
    }
}
