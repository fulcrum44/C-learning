#include <stdio.h>

const char* ENTRADA="Introduce un número entero positivo: ";
const char* NEGATIVO="\n%d es negativo. El número introducido deber ser un entero positivo\n\n";
const char* ERROR="\nValor incorrecto. EL valor introucido deber ser un número entero positivo\n\n";
const char* SUMA="\nLa suma asciende a %d\n\n";

int valor;

int main(void){

    int suma=0;

    while (0==0) {
        valor=-1;
        puts(ENTRADA);
        scanf("%d", &valor);
        while(getchar()!='\n');

        if (valor < 0) {
            printf(NEGATIVO, valor);
            continue;
        } else if (valor == 0) {
            break;
        } else if (valor > 0) {
            suma+=valor;
            printf(SUMA, suma);
        } else {
            puts(ERROR);
            continue;
        }
    }

    return 0;

}