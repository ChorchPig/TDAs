#include <stdio.h>
#include <stdlib.h>
#include "prototipos.h"

void btn_insert(binTree **node, binTree *newNode){
    if(!newNode)return;
    binTree **aux=btn_find(node, newNode->treeValue, restarDosEnteros);
    if(!*aux)*aux=newNode;
}

int btn_insert_value(binTree **node, int value){
    int insertado=0;
    binTree **aux=btn_find(node, value, restarDosEnteros);
    if(!*aux){
        binTree *nuevoNodo=btn_new(value);
        *aux=nuevoNodo;
        insertado=1;
    }
    return insertado;
}

binTree** btn_find(binTree** node, t_elem_btree valor, int cmp(t_elem_btree, t_elem_btree)){
    if(!*node || (*node)->treeValue==valor) return node;
    binTree **aux=node;
    while (*aux&&(*aux)->treeValue!=valor){
        if(cmp(valor, (*aux)->treeValue)<0)aux=&(*aux)->left;
        else aux=&(*aux)->right;
    }
    return aux;
}

int existeEnABB(binTree **arbol, t_elem_btree valor, int cmp(t_elem_btree, t_elem_btree)){
    binTree **existe=btn_find(arbol, valor, cmp);
    return (*existe)? 1 : 0;
}

binTree* quitarNodoABB(binTree** node, t_elem_btree data, int cmp(t_elem_btree, t_elem_btree)){
    binTree* result = NULL;
    binTree** found = btn_find(node, data, cmp);
    if (*found) {
        result = *found;
        btn_insert(&(*found)->left, (*found)->right);
        *found = (*found)->left;
        result->left = NULL;
        result->right = NULL;
    }
    return result;
}

void fusionarArboles(binTree **arbol1, binTree **arbol2, int cmp(t_elem_btree, t_elem_btree)){
    binTree *aux=NULL;
    while(*arbol2){
        aux=quitarNodoABB(arbol2, (*arbol2)->treeValue, cmp);
        if(aux&&!existeEnABB(arbol1, aux->treeValue, cmp)){
            btn_insert(arbol1, aux);
        }
        else free(aux);
    }
}

int btn_level(binTree* root, t_elem_btree value, int cmp(t_elem_btree, t_elem_btree)){
    if(!root) return -1;
    int nivel=-1;
    binTree **aux=btn_find(&root, value, cmp);
    if(*aux){
        nivel=0;
        if(root->treeValue!=value){
            aux=btn_find(&root->left, value, cmp);
            if(*aux)nivel=1+btn_level(root->left, value, cmp);
            else nivel=1+btn_level(root->right, value, cmp);
        }
    }
    return nivel;
}
