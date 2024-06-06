#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED

#include "prototiposMatriz.h"
#include "prototiposFila.h"
#include "prototiposPila.h"
#define INFINITO 9999

typedef struct{
    matrix *aristas;
    Vector *vertices;
}Grafo;

Grafo* crearGrafo(int);
void crearVertice(Grafo*,VECTOR_ELEMENT);
void crearArista(Grafo*,VECTOR_ELEMENT,VECTOR_ELEMENT, int); //Conoce la implementación del TDAVector
void crearAristaNoDirigida(Grafo*,VECTOR_ELEMENT,VECTOR_ELEMENT, int);
void eliminarGrafo(Grafo*);
void eliminarVertice(Grafo*,VECTOR_ELEMENT); //Conoce la implementación del TDAVector
void eliminarArista(Grafo*,VECTOR_ELEMENT,VECTOR_ELEMENT); //Conoce la implementación del TDAVector
void eliminarAristaNoDirigida(Grafo*,VECTOR_ELEMENT,VECTOR_ELEMENT);

Vector* obtenerVertices(Grafo*);
int obtenerCantVertices(Grafo*);
matrix* obtenerAristas(Grafo*);
int obtenerGradoVertice(Grafo*,int);
int obtenerPesoArista(Grafo *grafo, char origen, char destino); //Conoce la implementación del TDAVector

void recorridoAmplitud(Grafo*,void(),void*);
void recorridoProfundidad(Grafo*,void(),void*);
void imprimirVertice(Grafo*,int,char*);
int grafoDirigido(Grafo*);
int grafoCompleto(Grafo*);
int grafoVacio(Grafo*);

#endif // PROTOTIPOS_H_INCLUDED
