#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED

#include "prototiposMatriz.h"
#include "prototiposFila.h"
#include "prototiposPila.h"
#define GRAPH_ELEMENT char
#define INFINITO 9999

typedef struct{
    matrix *aristas;
    GRAPH_ELEMENT *vertices;
    int maxVertexes, currentVertexes;
}Grafo;

Grafo* crearGrafo(int);
void crearVertice(Grafo*,GRAPH_ELEMENT);
void crearArista(Grafo*,GRAPH_ELEMENT,GRAPH_ELEMENT, int);
void crearAristaNoDirigida(Grafo*,GRAPH_ELEMENT,GRAPH_ELEMENT, int);
void eliminarGrafo(Grafo*);
int grafoLleno(Grafo*grafo);
void eliminarVertice(Grafo*,GRAPH_ELEMENT);
void eliminarArista(Grafo*,GRAPH_ELEMENT,GRAPH_ELEMENT);
void eliminarAristaNoDirigida(Grafo*,GRAPH_ELEMENT,GRAPH_ELEMENT);

GRAPH_ELEMENT* obtenerVertices(Grafo*);
int obtenerCantVertices(Grafo*);
matrix* obtenerAristas(Grafo*);
int obtenerGradoVertice(Grafo*,int);
int obtenerPesoArista(Grafo *grafo, GRAPH_ELEMENT origen, GRAPH_ELEMENT destino);
int obtenerCostoArista(Grafo*,GRAPH_ELEMENT origen, GRAPH_ELEMENT destino);

void recorridoAmplitud(Grafo*,void(),void*);
void recorridoProfundidad(Grafo*,void(),void*);

void imprimirVertice(Grafo*,int,char*);//conoce la estructura
int grafoDirigido(Grafo*);
int grafoCompleto(Grafo*);
int grafoVacio(Grafo*);
int busquedaSecuencial(GRAPH_ELEMENT,GRAPH_ELEMENT*,int);//conoce la estructura

int verticesAdyacentes(VECTOR_ELEMENT vertice1, VECTOR_ELEMENT vertice2);

typedef struct{
    int *costos;
    GRAPH_ELEMENT *predecesores;
}TablaD;

TablaD* algoritmoDijkstra(Grafo*, int, int);
int minimoNoVisitado(int[], TablaD*, int);
int obtenerCostoArista2(Grafo *grafo, int origen, int destino);
int obtenerPesoArista2(Grafo *grafo, int origen, int destino);

#endif // PROTOTIPOS_H_INCLUDED
