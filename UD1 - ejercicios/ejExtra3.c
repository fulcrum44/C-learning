#include <stdio.h>

const char* ENTRADA="Introduce un número: ";
const char* MULTIPLO="\nEl valor introducido es múltiplo de 5";
const char* NO_MULTIPLO="\nEl valor introducido NO es múltiplo de 5";
const char* ERROR="\nEl valor introducido no es un número";


int num;

int main(void) {

    puts(ENTRADA);
    scanf("%i", &num);

    if (num%5==0) {
        puts(MULTIPLO);
    } else if (num%5!=0) {
        puts(NO_MULTIPLO);
    } else {
        puts(ERROR);
    }

        return 0;
}