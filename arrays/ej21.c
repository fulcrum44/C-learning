#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int CANTIDAD=15;

int main() {

    srand(time(NULL));

    int numeros[CANTIDAD];

    for (int i=0; i<=CANTIDAD; i++) {
        numeros[i] = rand()%100 +1;
        printf("%d: %d ", i, numeros[i]);
    }

    puts("");

    for (int i=CANTIDAD; i>=0; i--) {
        printf("%d ", numeros[i]);
    }

    return 0;
}