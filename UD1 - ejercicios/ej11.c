#include <stdio.h>

int value1;
int value2;
int value;

int main (void) {

    puts("Almacenaremos dos números en dos variables difentes y luego las invertiremos.\n");
    puts("Introduce el primer número: ");
    scanf("%i", &value1);

    puts("\nIntroduce el segundo número: ");
    scanf("%i", &value2);

    printf("\nEn este momento el primer valor es %i y el segundo es %i", value1, value2);

    value1=value;
    value2=value1;
    value=value2;

    printf("\nAhora el primer valor es: %i", value1);
    printf("\nAhora el segundo valor es: %i", value2);

    return 0;

}