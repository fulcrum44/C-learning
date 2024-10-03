#include <stdio.h>

const char* ENTRADA="Introduce un número (Si quieres salir del programa introduce 0): ";
const char* MULTIPLO="\nEl valor introducido es múltiplo de 5\n";
const char* NO_MULTIPLO="\nEl valor introducido NO es múltiplo de 5\n";
const char* ERROR="\nEl valor introducido no es un número\n";
const char* SALIDA="\nSaliendo...";

int pedir_numero();
void comprobacion_multiplo(int);

int salida=0;

int main() {
    do {
        comprobacion_multiplo(pedir_numero());
    } while (salida == 0);
    
    return 0;
}

int pedir_numero() {
    int num;
    puts(ENTRADA);
    scanf("%i", &num);
    while(getchar()!='\n');

    return num;
}

void comprobacion_multiplo(int num) {
    if (num == 0) salida++, printf(SALIDA);
    else if (num%5==0) {
        puts(MULTIPLO);
    } else if (num%5!=0) {
        puts(NO_MULTIPLO);
    } else {
        puts(ERROR);
    }
}