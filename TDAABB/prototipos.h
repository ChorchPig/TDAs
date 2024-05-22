#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED

#define t_elem_btree int

typedef struct _btn {
    t_elem_btree treeValue;
    struct _btn *left;
    struct _btn *right;
} binTree;

binTree* btn_new(t_elem_btree);
void agregaNodo(binTree**,binTree*);
void agregaValor(binTree**,t_elem_btree);
binTree** binTreeFind2(binTree**,t_elem_btree);
void copiarYOrdenarArbol(binTree**, binTree **);
binTree* reconstruirArbol(t_elem_btree *, t_elem_btree *, int);
binTree* eliminarDuplicados(binTree**);
binTree* quitarNodo(binTree** node, t_elem_btree data);
void eliminarArbol(binTree **, int());

t_elem_btree btn_height(binTree*);
void btn_inorder(binTree*,void(), void*);
void btn_postorder(binTree*,void(), void*);
void btn_preorder(binTree*,void(), void*);
void recorridoAmplitud(binTree*, void(), void*);

binTree **obtenerMinimoDeArbol(binTree**, binTree**());

int existeDentroArbol(binTree*,t_elem_btree);
int btn_isLeaf(binTree*);
int esBinarioBusqueda(binTree*);
int padreSumaDeHijos(binTree*);

//Se rompen si el árbol no es binario de búsqueda
void btn_insert(binTree**,binTree*);
int btn_insert_value(binTree**,int);
binTree** btn_find(binTree**, t_elem_btree, int());
int existeEnABB(binTree**, t_elem_btree valor, int());
binTree* quitarNodoABB(binTree**,t_elem_btree,int());
void fusionarArboles(binTree**, binTree**, int());
int btn_level(binTree*,t_elem_btree,int());

//funciones auxiliares
int restarDosEnteros(int,int);
int _max(int,int);
void imprimirValor(binTree*, char*);
void contarNodos(binTree*,int*);
binTree **minimo(binTree**,binTree**);
void sumarElementos(binTree*,int*);

//TDA fila

#define NODE_ELEMENT binTree*
#define QUEUE_ELEMENT nodo*

typedef struct _node {
    NODE_ELEMENT nodeValue;
    struct _node *siguiente;
} nodo;

typedef struct _queue{
    QUEUE_ELEMENT inicioFila;
    QUEUE_ELEMENT finalFila;
    int maxSize, currentSize;
}Fila;

QUEUE_ELEMENT crearNodo(NODE_ELEMENT);
Fila* crearFila(int);
void enqueue(Fila*,NODE_ELEMENT);
void enqueueNode(Fila*, QUEUE_ELEMENT);
QUEUE_ELEMENT dequeue(Fila*);
void dequeueFree(Fila*);
int filaLlena(Fila*);
int filaVacia(Fila*);
void eliminarFila(Fila*);
NODE_ELEMENT getFirstValue(Fila*);
void imprimirFila(Fila*);

#endif // PROTOTIPOS_H_INCLUDED
