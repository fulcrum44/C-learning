#include <stdio.h>

const int CANTIDAD=10;

int main() {

    int contador=0; // Una variable dentro de un bloque solo es accesible para ese bloque. Uno fuera de los bloques es accesible para todos los bloques.

    while (contador<CANTIDAD) {
        contador++;
        if (contador%2==0) continue; //Dentro de un while si ponemos una condicion seguida de un continue hará que no ejecute el resto del código del while cuando se cumpla dicha condición.
        printf("%i. vendo opel corsa\n", contador);
    }

    return 0;

}