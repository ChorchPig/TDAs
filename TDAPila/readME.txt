Pila* crearPila(int maxSize)
crea unna pila vacía con mazSize como su tamaño máximo

void push(Pila *pila, NODE_ELEMENT elemento);
crea un nuevo nodo dentro de pila que almacene elemento

void pushNode(Pila *pila, STACK_ELEMENT nodo);
agrega nodo a pila

nodo* pop(Pila *pila);
quita el último nodo de la pila y devuelve su dirección de memoria

void popFree(Pila *pila);
quita el último nodo de la pila y libera la memoria

NODE_ELEMENT top(Pila *pila);
devuelve el valor que contiene el último nodo de la pila

int getStackMaxSize(Pila *pila);
int getStackCurrentSize(Pila *pila);

int pilaLlena(Pila *pila);
revisa si la pila está vacía, devuelve 1 si lo está y 0 en caso contrario

int pilaVacia(Pila *pila);
revisa si la pila está vacía, devuelve 1 si lo está o si no existe la pila y 0 en caso contrario

void eliminarPila(Pila *pila);
libera la memoria que ocupan pila y sus nodos