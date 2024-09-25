#include <stdio.h>

const int CANTIDAD=10;

int main() {

    for (int i=1; i<=CANTIDAD; i++) { //1º inicializador. 2º Condición para que se siga ejecutando. 3º Modificación que se hace al ejecutarse el código dentro del bucle(PODRÍA PONERSE DENTRO DEL BUCLE AL FINAL). 
        printf("%i. vendo opel corsa\n", i);
    }

    return 0;

}