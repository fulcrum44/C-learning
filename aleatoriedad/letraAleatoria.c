#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 1. Muestra en pantalla un nombre compuesto por 5 letras mayúsculas elegidas al azar.


int main() {
    srand(time(NULL));
    int num_aleatorio;
    char letra_aleatoria;

    for (int i=1; i<=5; i++) {
        num_aleatorio=rand()%26+65; // En ASCII el abecedario en mayúsculas es de 65 a 90, ambos inclusive. En total son 26 letras.
        printf("%c", num_aleatorio);

    }

    puts (" ");

    for (int i=1; i<=5; i++) {
        letra_aleatoria='A'+rand()%26;
        printf("%c", letra_aleatoria);
    }

    return 0;
}