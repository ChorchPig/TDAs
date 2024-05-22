#include <stdio.h>
#include <stdlib.h>
#include "prototipos.h"

binTree** binTreeFind3(binTree**,t_elem_btree); //Acomoda los nodos para que los más buscados estén más cerca de la raíz
void btn_mirrored_insert(binTree**,binTree*);

int main(){
    binTree *arbol=NULL;
    btn_insert_value(&arbol, 10);
    btn_insert_value(&arbol, 15);
    btn_insert_value(&arbol, 5);
    btn_insert_value(&arbol, 1);
    btn_insert_value(&arbol, 9);
    btn_insert_value(&arbol, 11);
    btn_insert_value(&arbol, 20);
    btn_insert_value(&arbol, 16);
    char formato='i';
    btn_preorder(arbol, imprimirValor, &formato);
    printf("\n");
    eliminarArbol(&arbol, restarDosEnteros);
    return 0;
}
