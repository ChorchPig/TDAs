crearVector(int initialSize)
crea un puntero a la estructura Vector y lo devuelve.

getCurrentSize(Vector *vector)

getMaxSize(Vector *vector)

agregarAlVector(Vector *vector, VECTOR_ELEMENT valor)
añade valor dentro del arreglo de vector, devuelve 0 si se ejecutó correctamente y otro valor si no lo hizo.

vectorLleno(Vector *vector)
si el arreglo dentro de vector está lleno devuelve -1 y si no lo está devuelve 0.

eliminarDelVector(Vector *vector, VECTOR_ELEMENT valor)
elimina valor de vector si es que existe, devuelve la posición donde estaba el valor o el tamaño del arreglo si valor no está dentro del arreglo.

borrarDato(Vector *vector, int position)
elimina el valor del vector en la posición position, devuelve el valor eliminado.

eliminarVector(Vector *vector)
libera la memoria de vector->arreglo y vector.

imprimirVector()

sumaElementosVector(Vector *vector)
suma todos los elementos de vector y devuelve el resultado.

sumarDosVectores(Vector *vector1, Vector *vector2)
suma los valores de vector1->arreglo y vector2->arreglo siempre y cuando ambos tengan el mismo currentSize.

apareceEnVector(Vector *vector, VECTOR_ELEMENT valor)
cuenta las veces que aparece valor en vector, devuelve el resultado.

sequential_search()
binary_search()

ordenarVector(Vector *vector)
ordena vector de forma ascendente o descendente según el usuario lo decida.

bubble_sort(VECTOR_ELEMENT *vector, int n, int criterio)
mediante el método del burbujeo se ordena de forma ascendente o descendente en base al criterio seleccionado (si criterio es menor a uno es descendente, si es mayor a uno ascendente).

swap(VECTOR_ELEMENT *a, VECTOR_ELEMENT *b)
intercambia los contenidos de a y b.

agregarYOrdenarVector(Vector *vector, VECTOR_ELEMENT valor)
agrega valor a vector y luego lo ordena.

generarVectorOrdenado(Vector *vector)
crea una copia de vector, ordena la copia y la dievuelve.

mezclarDosVectores()