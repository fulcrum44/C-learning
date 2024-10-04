#include <stdio.h>

const char* ENTRADA="\nIntroduce un número entero positivo";
const char* ERROR="\nEl valor introducido no es un número entero positivo. Vuelve a probar.";
const char* SALIDA="\n%i --> %i cifras";

int main(void) {
    int valor=0;
    while (valor<=0) {
        puts(ENTRADA);
        scanf("%i", &valor);
        while(getchar()!='\n');
        if (valor>0) {
            break;
        } else {
            puts(ERROR);
        }
    }

    int cifras=0;
    int dividendo=valor;
    while (dividendo>0) {
        dividendo=dividendo/10;
        cifras++;      
    }

    printf(SALIDA, valor, cifras);

    return 0;
}