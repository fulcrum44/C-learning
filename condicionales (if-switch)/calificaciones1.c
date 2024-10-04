#include <stdio.h>


const char* PEDIR_NOTA="Introduce tu nota: \n";
const char* ERROR="\nEste valor no es válido. Introduce un número entre 0 y 10.";
const char* SUSPENSO="\nEstás suspenso";
const char* APROBADO="\nEstás aprobado";
const char* NOTABLE="\nNotable";
const char* SOBRESALIENTE="\nSobresaliente";

int nota;

int main (void) {

    puts("Vamos a determinar qué clase de nota es la que tienes.\n");
    puts(PEDIR_NOTA);
    scanf("%d", &nota);
    while(getchar()!='\n');

    switch(nota) {

        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
            puts(SUSPENSO);
            break;

        case 5:
        case 6:
            puts(APROBADO);
            break;

        case 7:
        case 8:
            puts(NOTABLE);
            break;

        case 9:
        case 10:
            puts(SOBRESALIENTE);
            break;

        default:
            puts(ERROR); 

    }

    return 0;
}