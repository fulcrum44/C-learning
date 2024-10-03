#include <stdio.h>

const char* PEDIR_ENTRADA="Introduce una letra mayúscula: ";
const char* VALOR_CORRECTO="\nMuy bien, valor correcto.";
const char* ERROR_MINUSCULA="\nLa letra introducida debe ser mayúscula.";
const char* ERROR="\nValor incorrecto. Debe ser una letra mayúscula";

void comprobacion();

char letra;

int main(void) {

    puts(PEDIR_ENTRADA);
    scanf("%c", &letra);
    while(getchar()!='\n');
    comprobacion();

    return 0;

}

void comprobacion() {
    // Las letras se pueden tratar como números al poder ser leídos en su código ASCII

    if (letra >= 'A' && letra <= 'Z') {
        puts(VALOR_CORRECTO);
    } else if (letra >= 'a' && letra <= 'z') {
        puts(ERROR_MINUSCULA);
    } else {
        puts(ERROR);
    }
}