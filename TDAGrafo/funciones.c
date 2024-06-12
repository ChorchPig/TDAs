#include <stdio.h>
#include <stdlib.h>
#include "prototipos/prototipos.h"

Grafo* crearGrafo(int vertices){
    Grafo *nuevoGrafo=(Grafo *)malloc(sizeof(Grafo));
    if(nuevoGrafo){
        nuevoGrafo->vertices=(GRAPH_ELEMENT*)malloc(sizeof(GRAPH_ELEMENT)*vertices);
        nuevoGrafo->aristas=crearMatriz(vertices, vertices);
        nuevoGrafo->maxVertexes=vertices;
        nuevoGrafo->currentVertexes=0;
    }
    return nuevoGrafo;
}

void eliminarGrafo(Grafo *grafo){
    eliminarMatriz(grafo->aristas);
    free(grafo->vertices);
    free(grafo);
}

int grafoLleno(Grafo*grafo){ return (grafo->maxVertexes==grafo->currentVertexes); }

void crearVertice(Grafo *grafo, GRAPH_ELEMENT vertice){
    if(grafo){
        if(!grafoLleno(grafo))grafo->vertices[grafo->currentVertexes]=vertice;
        else {
            realloc(grafo->vertices, sizeof(GRAPH_ELEMENT)*(grafo->maxVertexes+1));
            grafo->maxVertexes++;
            grafo->currentVertexes=grafo->maxVertexes;
            grafo->aristas=ampliarMatriz(grafo->aristas, grafo->maxVertexes, grafo->maxVertexes);
        }
        grafo->currentVertexes++;
    }
}

void eliminarVertice(Grafo *grafo, GRAPH_ELEMENT vertice){
    if(!grafo) return;
    int indiceVertice=busquedaSecuencial(vertice, grafo->vertices, grafo->currentVertexes);
    if(indiceVertice!=1){
        deleteRow(grafo->aristas, indiceVertice);
        deleteColumn(grafo->aristas, indiceVertice);
        grafo->currentVertexes--;
    }
}

void crearArista(Grafo *grafo, GRAPH_ELEMENT origen, GRAPH_ELEMENT destino, int peso){
    if(!grafo) return;
    int indiceOrigen=busquedaSecuencial(origen, grafo->vertices, grafo->currentVertexes);
    int indiceDestino=busquedaSecuencial(destino, grafo->vertices, grafo->currentVertexes);
    if(indiceOrigen>-1&&indiceDestino>-1) setValueInMatrix(grafo->aristas, peso, indiceOrigen, indiceDestino);
}

void eliminarArista(Grafo *grafo, GRAPH_ELEMENT origen, GRAPH_ELEMENT destino){
    if(!grafo) return;
    int indiceOrigen=busquedaSecuencial(origen, grafo->vertices, grafo->currentVertexes);
    int indiceDestino=busquedaSecuencial(destino, grafo->vertices, grafo->currentVertexes);
    if(indiceOrigen>-1&&indiceDestino>-1) eliminarValorMatriz(grafo->aristas, indiceOrigen, indiceDestino);
}

void crearAristaNoDirigida(Grafo *grafo, VECTOR_ELEMENT origen, VECTOR_ELEMENT destino, int peso){
    crearArista(grafo, origen, destino, peso);
    crearArista(grafo, destino, origen, peso);
}

void eliminarAristaNoDirigida(Grafo *grafo, VECTOR_ELEMENT origen, VECTOR_ELEMENT destino){
    eliminarArista(grafo, origen, destino);
    eliminarArista(grafo, destino, origen);
}

GRAPH_ELEMENT* obtenerVertices(Grafo *grafo){ return grafo->vertices; }
matrix* obtenerAristas(Grafo *grafo){ return grafo->aristas; }
int obtenerCantVertices(Grafo *grafo){ return grafo->currentVertexes; }

int obtenerGradoVertice(Grafo *grafo, int verticeIndice){
    int grado=-1;
    Vector *conexiones=extraerFila(grafo->aristas, verticeIndice);
    if(conexiones){
        grado=0;
        int longitud=getCurrentSize(conexiones);
        for(int i=0; i<longitud; i++){
            if(getValueInVector(conexiones, i))grado++;
        }
        eliminarVector(conexiones);
    }
    return grado;
}

int obtenerPesoArista(Grafo *grafo, GRAPH_ELEMENT origen, GRAPH_ELEMENT destino){
    matrix *aristas=obtenerAristas(grafo);
    GRAPH_ELEMENT *vertices=obtenerVertices(grafo);
    int longitud=obtenerCantVertices(grafo);
    int indiceOrigen=busquedaSecuencial(origen, vertices, longitud);
    int indiceDestino=busquedaSecuencial(destino, vertices, longitud);
    return (indiceOrigen>-1&&indiceDestino>-1)? getValueInMatrix(aristas, indiceOrigen, indiceDestino) : -1;
}

int obtenerCostoArista(Grafo *grafo, VECTOR_ELEMENT origen, VECTOR_ELEMENT destino){
    int costo=obtenerPesoArista(grafo, origen, destino);
    return (costo!=-1)? costo : INFINITO;
}

void recorridoAmplitud(Grafo *grafo, void grafo_do(), void *contexto){
    if(!grafo)return;
    int longitud=obtenerCantVertices(grafo), position=0;
    int *visitados=(int*)calloc(longitud, sizeof(int));
    QUEUE_ELEMENT* nodoAux;
    Vector *aristas;
    Fila *aux=crearFila(-1);
    enqueueValue(&aux, position);
    while(!filaVacia(aux)){
        nodoAux=dequeue(&aux);
        position=nodoAux->valor;
        visitados[position]=1;
        aristas=extraerFila(obtenerAristas(grafo), position);
        for(int i=0; i<longitud; i++){
            if(getValueInVector(aristas, i)&&!visitados[i]) enqueueValue(&aux, i);
        }
        grafo_do(grafo, position, contexto);
        free(nodoAux);
        eliminarVector(aristas);
    }
    eliminarFila(&aux);
    free(visitados);
}

void recorridoProfundidad(Grafo *grafo, void grafo_do(), void *contexto){
    if(!grafo)return;
    int longitud=obtenerCantVertices(grafo), position=0;
    int *visitados=(int*)calloc(longitud, sizeof(int));
    STACK_ELEMENT* nodoAux;
    Vector *aristas;
    Pila *aux=crearPila(-1);
    pushValue(aux, position);
    while(!pilaVacia(aux)){
        nodoAux=pop(aux);
        position=nodoAux->valor;
        visitados[position]=1;
        aristas=extraerFila(obtenerAristas(grafo), position);
        for(int i=0; i<longitud; i++){
            if(getValueInVector(aristas, i)&&!visitados[i]) pushValue(aux, i);
        }
        grafo_do(grafo, position, contexto);
        free(nodoAux);
        eliminarVector(aristas);
    }
    eliminarPila(&aux);
    free(visitados);
}

void imprimirVertice(Grafo *grafo, int position, char *formato){//conoce la estructura
    GRAPH_ELEMENT *vertices=obtenerVertices(grafo);
    switch(*formato){
        case 'i': printf("%d ", vertices[position]); break;
        case 'f': printf("%.2f ", vertices[position]); break;
        case 'c': printf("%c ", vertices[position]); break;
        case 's': printf("%s ", vertices[position]); break;
    }
}

int grafoCompleto(Grafo *grafo){
    int completo=0;
    if(grafo){
        completo=1;
        matrix* Matrix=obtenerAristas(grafo);
        int i=0, filas=getMatrixRows(Matrix), columnas=getMatrixColumns(Matrix);
        while(i<filas&&completo){
            int j=0;
            while(j<columnas&&completo){
                if(i!=j&&!getValueInMatrix(Matrix, i, j))completo=0;
                j++;
            }
            i++;
        }
    }
    return completo;
}

int grafoVacio(Grafo *grafo){
    int vacio=1;
    if(grafo){
        matrix* Matrix=obtenerAristas(grafo);
        int i=0, filas=getMatrixRows(Matrix), columnas=getMatrixColumns(Matrix);
        while(i<filas&&vacio){
            int j=0;
            while(j<columnas&&vacio){
                if(i!=j&&getValueInMatrix(Matrix, i, j))vacio=0;
                j++;
            }
            i++;
        }
    }
    return vacio;
}

int grafoDirigido(Grafo* grafo){
    matrix *aristas=obtenerAristas(grafo);
    return !matrizSimetrica(aristas);
}

int busquedaSecuencial(GRAPH_ELEMENT key,GRAPH_ELEMENT *arreglo,int n){//conoce la estructura
    int i=0;
    while ((i<n)&&(arreglo[i]!=key)){
        i++;
    }
    return (i>=n)? -1 : i;
}

TablaD* algoritmoDijkstra(Grafo *grafo, int origen, int destino){
    TablaD *tabla=(TablaD*)malloc(sizeof(TablaD));
    int cantVertices=obtenerCantVertices(grafo), *visitados;
    tabla->costos=(int *)malloc(sizeof(int)*cantVertices);
    tabla->predecesores=(char *)malloc(sizeof(char)*cantVertices);
    char predecesor='a';
    for(int i=0; i<cantVertices; i++){
        tabla->costos[i]=obtenerCostoArista2(grafo, origen, i);
        tabla->predecesores[i]=predecesor;
    }
    visitados=(int *)calloc(cantVertices, sizeof(int));
    int i=origen;
    while(i!=-1){
        visitados[i]=1;
        i=minimoNoVisitado(visitados, tabla, cantVertices);
        if(i!=-1){
            int costoAlternativo=0;
            for(int j=0; j<cantVertices; j++){
                costoAlternativo=tabla->costos[i]+obtenerCostoArista2(grafo, i, j);
                if(costoAlternativo<tabla->costos[j]){
                    tabla->costos[j]=costoAlternativo;
                    tabla->predecesores[j]=predecesor+i;
                }
            }
        }
    }
    return tabla;
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

int obtenerCostoArista2(Grafo *grafo, int origen, int destino){
    int costo=obtenerPesoArista2(grafo, origen, destino);
    return (costo)? costo : INFINITO;
}

int obtenerPesoArista2(Grafo *grafo, int origen, int destino){
    matrix *aristas=obtenerAristas(grafo);
    return (origen>-1&&destino>-1)? getValueInMatrix(aristas, origen, destino) : -1;
}
