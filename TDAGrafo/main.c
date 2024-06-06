#include <stdio.h>
#include <stdlib.h>
#include "prototipos/prototipos.h"

int verticesAdyacentes(VECTOR_ELEMENT vertice1, VECTOR_ELEMENT vertice2);
int obtenerCostoArista(Grafo*,char origen, char destino);

int main(){
    Grafo *grafo=crearGrafo(5);
    crearVertice(grafo, 'a');
    crearVertice(grafo, 'b');
    crearVertice(grafo, 'c');
    crearVertice(grafo, 'd');
    crearVertice(grafo, 'e');
    crearAristaNoDirigida(grafo, 'a', 'c', 1);
    crearAristaNoDirigida(grafo, 'a', 'd', 1);
    crearAristaNoDirigida(grafo, 'b', 'd', 1);
    crearAristaNoDirigida(grafo, 'b', 'e', 1);
    crearAristaNoDirigida(grafo, 'a', 'c', 1);
    crearAristaNoDirigida(grafo, 'e', 'c', 1);
    eliminarGrafo(grafo);
    return 0;
}

int obtenerPesoArista(Grafo *grafo, VECTOR_ELEMENT origen, VECTOR_ELEMENT destino){//Conoce la implementación del TDAVector
    matrix *aristas=obtenerAristas(grafo);
    Vector *vertices=obtenerVertices(grafo);
    int longitud=getCurrentSize(vertices);
    int indiceOrigen=sequential_search(origen, vertices->arreglo, longitud);
    int indiceDestino=sequential_search(destino, vertices->arreglo, longitud);
    return (indiceOrigen>-1&&indiceDestino>-1)? getValueInMatrix(aristas, indiceOrigen, indiceDestino) : -1;
}
