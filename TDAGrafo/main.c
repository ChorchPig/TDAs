#include <stdio.h>
#include <stdlib.h>
#include "prototipos/prototipos.h"

int main(){
    Grafo *grafo=crearGrafo(5);
    crearVertice(grafo, 'a');
    crearVertice(grafo, 'b');
    crearVertice(grafo, 'c');
    crearVertice(grafo, 'd');
    crearVertice(grafo, 'e');
    crearVertice(grafo, 'f');
    crearVertice(grafo, 'g');
    crearVertice(grafo, 'h');
    crearVertice(grafo, 'i');
    crearVertice(grafo, 'j');
    crearVertice(grafo, 'k');
    crearArista(grafo, 'a', 'b', 3);
    crearArista(grafo, 'a', 'e', 5);
    crearArista(grafo, 'a', 'h', 4);
    crearArista(grafo, 'b', 'c', 2);
    crearArista(grafo, 'b', 'f', 7);
    crearArista(grafo, 'c', 'd', 3);
    crearArista(grafo, 'c', 'f', 2);
    crearArista(grafo, 'c', 'g', 6);
    crearArista(grafo, 'd', 'k', 7);
    crearArista(grafo, 'e', 'b', 5);
    crearArista(grafo, 'e', 'f', 4);
    crearArista(grafo, 'e', 'h', 7);
    crearArista(grafo, 'f', 'g', 4);
    crearArista(grafo, 'f', 'j', 3);
    crearArista(grafo, 'g', 'd', 2);
    crearArista(grafo, 'g', 'k', 3);
    crearArista(grafo, 'g', 'j', 4);
    crearArista(grafo, 'h', 'f', 5);
    crearArista(grafo, 'h', 'i', 2);
    crearArista(grafo, 'i', 'f', 4);
    crearArista(grafo, 'i', 'j', 6);
    crearArista(grafo, 'j', 'k', 2);
    TablaD* tabla=algoritmoDijkstra(grafo, 0, 10);
    int cantVertices=obtenerCantVertices(grafo);
    for(int i=0; i<cantVertices; i++){
        printf("Costo: %d Predecesor: %c\n", tabla->costos[i], tabla->predecesores[i]);
    }
    free(tabla->costos);
    free(tabla->predecesores);
    free(tabla);
    eliminarGrafo(grafo);
    return 0;
}
