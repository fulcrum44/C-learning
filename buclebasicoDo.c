#include <stdio.h>

const int CANTIDAD=1000;

int main() {

    int contador=0; // Una variable dentro de un bloque solo es accesible para ese bloque. Uno fuera de los bloques es accesible para todos los bloques.

    do {
        contador++;
        printf("%i. Bucles!!!!!!!!!!!!\n", contador);
    } while (contador<CANTIDAD);

    return 0;

}