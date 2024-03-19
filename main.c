#include <stdio.h>
#include <locale.h>
#include "prototipos.h"

int main(){
    setlocale(LC_ALL, "spanish");
    Vector *vector=crearVector(4);
    agregarAlVector(vector, 2);
    agregarAlVector(vector, 4);
    agregarAlVector(vector, 1);
    agregarAlVector(vector, 3);
    imprimirVector(vector);
    printf("\n");
    eliminarVector(vector);
    return 0;
}
