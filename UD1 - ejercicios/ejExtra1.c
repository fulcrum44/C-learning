#include <stdio.h>

const char* PEDIR_ENTRADA="Introduce una vocal mayúscula: ";
const char* VALOR_CORRECTO="\nMuy bien, valor correcto.";
const char* ERROR_MINUSCULA="\nLa vocal introducida debe ser mayúscula.";
const char* ERROR="\nValor incorrecto. Debe ser una vocal y mayúscula";

char vocal;

int main() {

    puts(PEDIR_ENTRADA);
    scanf("%c", &vocal);

    switch(vocal) {

        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
            puts(VALOR_CORRECTO);
            break;
        
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            puts(ERROR_MINUSCULA);
            break;
        
        default:
            puts(ERROR);
    }

    return 0;
}