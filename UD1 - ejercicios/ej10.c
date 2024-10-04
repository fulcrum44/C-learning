#include <stdio.h>

int value1;

int main (void) {

    puts("Introduce un número al que quieras elevar a tres\n");
    scanf("%i", &value1);

    printf("El resultado de elevar a tres el valor %i es: %i", value1, value1 * value1 * value1);

    return 0;

}