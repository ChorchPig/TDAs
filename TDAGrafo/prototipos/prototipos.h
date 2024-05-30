#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED

#include "prototiposMatriz.h"
#include "prototiposFila.h"
#include "prototiposPila.h"

typedef struct{
    matrix *aristas;
    Vector *vertices;
}Grafo;

Grafo* crearGrafo(int);
void crearVertice(Grafo*,VECTOR_ELEMENT);
void crearArista(Grafo*,VECTOR_ELEMENT,VECTOR_ELEMENT);
void eliminarGrafo(Grafo*);
void eliminarVertice(Grafo*,VECTOR_ELEMENT);
void eliminarArista(Grafo*,VECTOR_ELEMENT,VECTOR_ELEMENT);

Vector* obtenerVertices(Grafo*);
int obtenerCantVertices(Grafo*);
matrix* obtenerAristas(Grafo*);
int obtenerGradoVertice(Grafo*,int);
void recorridoAmplitud(Grafo*,void(),void*);
void recorridoProfundidad(Grafo*,void(),void*);
void imprimirVertice(Grafo*,int,char*);
int grafoDirigido(Grafo*);
int grafoCompleto(Grafo*);
int grafoVacio(Grafo*);

#endif // PROTOTIPOS_H_INCLUDED
