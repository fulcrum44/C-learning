#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); //Semilla del RANDOM. Es siempre necesario usando rand.

    int aleatorio=rand()%5 +1; // %5 = [0,4]  // %5 + 1 = [1,5] // El dígito con % es el rango de los números de los que queremos generar uno aleatorio. Sumarle un determinado valor a eso avanza el inicio de ese rango al valor puesto.
    printf("%i", aleatorio);
    return 0; 
}