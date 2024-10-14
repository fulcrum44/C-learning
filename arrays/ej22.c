#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

const int CANTIDAD=20;

int main() {

    srand(time(NULL));

    int numeros[CANTIDAD];
    int mayor_numero=INT_MIN;
    int celda;

    for (int i=0; i<CANTIDAD; i++) {
        numeros[i] = rand()%20 +1;
        printf("\n%d: %d ", i+1, numeros[i]);

        if (numeros[i] > mayor_numero) {
            mayor_numero=numeros[i];
            celda=i;
        }
    }

    printf("\nEl número más grande es %d y está en la posición %d", mayor_numero, celda);

    return 0;
}