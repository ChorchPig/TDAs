#include <stdio.h>
#include <stdlib.h>
#include "prototipos.h"

binTree** binTreeFind3(binTree**,t_elem_btree); //Acomoda los nodos para que los más buscados estén más cerca de la raíz
void binTreeMirrorInsert(binTree**,binTree*,int());
int restarDosEnteros2(int,int);

int main(){
    binTree *arbol=NULL, *arbolEspejado=NULL;
    btn_insert_value(&arbol, 10, restarDosEnteros);
    btn_insert_value(&arbol, 15, restarDosEnteros);
    btn_insert_value(&arbol, 5, restarDosEnteros);
    btn_insert_value(&arbol, 1, restarDosEnteros);
    btn_insert_value(&arbol, 9, restarDosEnteros);
    btn_insert_value(&arbol, 11, restarDosEnteros);
    btn_insert_value(&arbol, 20, restarDosEnteros);
    btn_insert_value(&arbol, 16, restarDosEnteros);
    btn_insert_value(&arbolEspejado, 10, restarDosEnteros2);
    btn_insert_value(&arbolEspejado, 15, restarDosEnteros2);
    btn_insert_value(&arbolEspejado, 5, restarDosEnteros2);
    btn_insert_value(&arbolEspejado, 1, restarDosEnteros2);
    btn_insert_value(&arbolEspejado, 9, restarDosEnteros2);
    btn_insert_value(&arbolEspejado, 11, restarDosEnteros2);
    btn_insert_value(&arbolEspejado, 20, restarDosEnteros2);
    btn_insert_value(&arbolEspejado, 16, restarDosEnteros2);
    char formato='i';
    recorridoAmplitud(arbol, imprimirValor, &formato);
    printf("\n");
    //binTreeMirrorInsert(arbol, arbolEspejado, restarDosEnteros2);
    recorridoAmplitud(arbolEspejado, imprimirValor, &formato);
    printf("\n");
    eliminarArbol(&arbol, restarDosEnteros);
    return 0;
}

void recorridoAmplitud(binTree *arbol, void btn_do(binTree*,void*), void *contexto){
    nodo *aux=NULL;
    Fila *fila=crearFila(-1);
    enqueue(fila, arbol);
    while(!filaVacia(fila)){
        aux=dequeue(fila);
        btn_do(aux->nodeValue, contexto);
        if(aux->nodeValue->left)enqueue(fila, aux->nodeValue->left);
        if(aux->nodeValue->right)enqueue(fila, aux->nodeValue->right);
    }
    eliminarFila(fila);
}

void eliminarFila(Fila *fila){
    if(!fila)return;
    while(!filaVacia(fila))dequeueFree(fila);
    free(fila); //por alguna razón se traba acá
}

int restarDosEnteros2(int a, int b) { return b-a; }
