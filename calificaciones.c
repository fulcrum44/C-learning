#include <stdio.h>

const char* PEDIR_NOTA="Introduce tu nota: \n";
const char* ERROR="\nEste valor no es válido. Introduce un número entre 0 y 10.";
const char* SUSPENSO="\nTu nota es un %0.2f, estás suspenso";
const char* APROBADO="\nTu nota es un %0.2f, estás aprobado";
const char* NOTABLE="\nTu nota es un %0.2f, tienes un notable";
const char* SOBRESALIENTE="\nTu nota es un %0.2f, tienes un sobresaliente";

float nota;

int main (void) {

    puts("Vamos a determinar qué clase de nota es la que tienes.\n");
    puts(PEDIR_NOTA);
    scanf("%f", &nota);
    while(getchar()!='\n');

    if (nota < 0 || nota > 10) {
        puts(ERROR);
    } else if (nota < 5) {
        printf(SUSPENSO, nota);
    } else if (nota < 7){
        printf(APROBADO, nota);
    } else if (nota < 9){
        printf(NOTABLE, nota);
    } else {
        printf(SOBRESALIENTE, nota);
    }

    return 0;
}