#include <stdio.h>
#include <stdlib.h>
#include "prototipos/prototipos.h"

int verticesAdyacentes(VECTOR_ELEMENT vertice1, VECTOR_ELEMENT vertice2);
int* obtenerAristasSalida(Grafo*,int);

typedef struct{
    int *costos;
    char *predecesores;
}TablaD;

TablaD* algoritmoDijkstra(Grafo*, int, int);
int minimoNoVisitado(int[], TablaD*, int);

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

TablaD* algoritmoDijkstra(Grafo *grafo, int origen, int destino){
    TablaD *tabla=(TablaD*)malloc(sizeof(TablaD));
    int cantVertices=obtenerCantVertices(grafo), *visitados;
    char predecesor='a';
    for(int i=0; i<cantVertices; i++){
        tabla->costos=obtenerCostoArista(grafo, origen, i);
        tabla->predecesores=predecesor;
    }
    visitados=(int *)calloc(cantVertices, sizeof(int));
    int i=origen;
    while(i!=-1){
        visitados[i]=1;
        i=minimoNoVisitado(visitados, tabla, cantVertices);
        if(i!=-1){

        }
    }
    return TablaD;
}


int* obtenerAristasSalida(Grafo *grafo, int vertice){

}

int minimoNoVisitado(int visitados[], TablaD *tabla, int longitud){
    int indice=-1, minimo=INFINITO;
    for(int i=0; i<longitud; i++){
        if(tabla->costos[i]<minimo&&!visitados[i]){
            minimo=tabla->costos[i];
            indice=i;
        }
    }
    return indice;
}
