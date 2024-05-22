#include <stdio.h>
#include <stdlib.h>
#include "prototipos.h"

binTree* btn_new(t_elem_btree value){
    binTree *nuevoNodo=(binTree*)malloc(sizeof(binTree));
    if(nuevoNodo){
        nuevoNodo->treeValue=value;
        nuevoNodo->left=NULL;
        nuevoNodo->right=NULL;
    }
    return nuevoNodo;
}

void agregaNodo(binTree **arbol, binTree *nuevoNodo){
    if(!*arbol)(*arbol)=nuevoNodo;
    else{
        if(!(*arbol)->left) (*arbol)->left=nuevoNodo;
        else if(!(*arbol)->right) (*arbol)->right=nuevoNodo;
        else agregaNodo(&(*arbol)->left, nuevoNodo);
    }
}

void agregaValor(binTree **arbol, t_elem_btree valor){
    binTree *nuevoNodo=btn_new(valor);
    agregaNodo(arbol, nuevoNodo);
}

binTree** binTreeFind2(binTree **node, t_elem_btree value){
    binTree** result=NULL;
    if(*node){
        if((*node)->treeValue==value)result=node;
        else{
            result=binTreeFind2(&(*node)->left, value);
            if(!result) result=binTreeFind2(&(*node)->right, value);
        }
    }
    return result;
}

binTree* quitarNodo(binTree** node, t_elem_btree data){
    binTree* result = NULL;
    binTree** found = binTreeFind2(node, data);
    if (*found){
        result = *found;
        agregaNodo(&(*found)->left, (*found)->right);
        *found = (*found)->left;
        result->left = NULL;
        result->right = NULL;
    }
    return result;
}

void eliminarArbol(binTree **arbol, int cmp(t_elem_btree, t_elem_btree)){
    while(*arbol) free(quitarNodoABB(arbol, (*arbol)->treeValue, cmp));
}

binTree* eliminarDuplicados(binTree **arbol){
    binTree *aux=NULL, *nuevoArbol=NULL;
    while(*arbol){
        aux=quitarNodo(arbol, (*arbol)->treeValue);
        int existe=existeDentroArbol(nuevoArbol, aux->treeValue);
        if(existe)free(aux);
        else agregaNodo(&nuevoArbol, aux);
    }
    return nuevoArbol;
}

binTree **obtenerMinimoDeArbol(binTree **arbol, binTree **funcionComp(binTree**,binTree**)){
    if(!*arbol)return arbol;
    binTree **nodoMinimo=NULL;
    binTree **aux1=obtenerMinimoDeArbol(&(*arbol)->right, funcionComp);
    binTree **aux2=obtenerMinimoDeArbol(&(*arbol)->left, funcionComp);
    nodoMinimo=funcionComp(aux1, aux2);
    return funcionComp(nodoMinimo, arbol);
}

void copiarYOrdenarArbol(binTree **arbol, binTree **nuevoArbol){
    if(!*arbol) return;
    btn_insert_value(nuevoArbol, (*arbol)->treeValue);
    copiarYOrdenarArbol(&(*arbol)->left, nuevoArbol);
    copiarYOrdenarArbol(&(*arbol)->right, nuevoArbol);
}

void btn_inorder(binTree *node, void btn_do(binTree*, void*), void *contexto){
    if(!node) return;
    btn_inorder(node->left, btn_do, contexto);
    btn_do(node, contexto);
    btn_inorder(node->right, btn_do, contexto);
}

void btn_postorder(binTree *node, void btn_do(binTree*, void*), void *contexto){
    if (!node) return;
    btn_postorder(node->left, btn_do, contexto);
    btn_postorder(node->right, btn_do, contexto);
    btn_do(node, contexto);
}

void btn_preorder(binTree *node, void btn_do(binTree*, void*), void *contexto){
    if (!node) return;
    btn_do(node, contexto);
    btn_preorder(node->left, btn_do, contexto);
    btn_preorder(node->right, btn_do, contexto);
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

t_elem_btree btn_height(binTree *node){
    int result = -1;
    if(node) result=_max(btn_height(node->left), btn_height(node->right))+1;
    return result;
}

int existeDentroArbol(binTree *arbol, t_elem_btree valor){
    int existe=0;
    if(arbol){
        if(arbol->treeValue==valor)existe=1;
        else existe=existeDentroArbol(arbol->left, valor)||existeDentroArbol(arbol->right, valor);
    }
    return existe;
}

int btn_isLeaf(binTree *node){
    return node&&!node->left&&!node->right;
}

int padreSumaDeHijos(binTree *arbol){
    int booleano=1;
    if(!arbol||btn_isLeaf(arbol))return booleano;
    if(arbol->treeValue!=arbol->left->treeValue+arbol->right->treeValue)booleano=0;
    if(booleano){
        booleano=padreSumaDeHijos(arbol->left)&&padreSumaDeHijos(arbol->right);
    }
    return booleano;
}

int esBinarioBusqueda(binTree *arbol){
    int booleano=1;
    if(!arbol||btn_isLeaf(arbol))return booleano;
    if(arbol->left&&arbol->treeValue<arbol->left->treeValue)booleano=0;
    if(arbol->right&&arbol->treeValue>arbol->right->treeValue)booleano=0;
    if(booleano){
        booleano=esBinarioBusqueda(arbol->left)&&esBinarioBusqueda(arbol->right);
    }
    return booleano;
}

void sumarElementos(binTree *arbol, int *total){ (*total)+=arbol->treeValue; }

int restarDosEnteros(int a, int b) { return a-b; }

int _max(int a, int b) { return (a > b) ? a : b; }

void imprimirValor(binTree *arbol, char *caracter){
    switch(*caracter){
        case 'i' : printf("%d ", arbol->treeValue); break;
        case 'f' : printf("%.2f ", arbol->treeValue); break;
        case 'c' : printf("%c ", arbol->treeValue); break;
        case 's' : printf("%s ", arbol->treeValue); break;
    }
}

void contarNodos(binTree *arbol, int *cantNodos){
    if(!arbol)return;
    (*cantNodos)++;
}

binTree **minimo(binTree **ptr1, binTree **ptr2){
    if(!*ptr1)return ptr2;
    if(!*ptr2)return ptr1;
    return ((*ptr1)->treeValue<(*ptr2)->treeValue)? ptr1 : ptr2;
}
