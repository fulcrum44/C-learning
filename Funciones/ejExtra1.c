#include <stdio.h>

const char* PEDIR_ENTRADA="Introduce una vocal mayúscula (Si quieres salir del programa introduce 0): ";
const char* VALOR_CORRECTO="\nMuy bien, valor correcto.\n";
const char* ERROR_MINUSCULA="\nLa vocal introducida debe ser mayúscula.\n";
const char* ERROR="\nValor incorrecto. Debe ser una vocal y mayúscula\n";
const char* SALIDA="\nSaliendo...";

char pedir_letra();
void comprobacion(char); // En la declaración de las funciones hay que especificar el tipo de dato que vamos a usar si queremos usar algún parámetro durante el uso de esta.

int salida=0;

int main() {
    do {
        // pedir_letra(); // REDUNDANCIA
        comprobacion(pedir_letra());
    } while (salida == 0);
    
    return 0;
}

char pedir_letra() {
    char vocal;
    printf(PEDIR_ENTRADA);
    scanf("%c", &vocal);
    while(getchar()!='\n');
    return vocal;
}

void comprobacion(char vocal) {
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

        case '0':
            puts(SALIDA);
            salida++;
            break;

        default:
            puts(ERROR);
    }
}
