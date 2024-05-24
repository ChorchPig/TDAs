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
    printf("\n");
    eliminarGrafo(grafo);
    return 0;
}
