#include <stdio.h>

int edad;

int main (void){

    puts("Introduce tu edad: ");
    scanf("%d", &edad);

    if (edad < 65 && edad >= 18){
        printf("\nUsted es mayor de edad pero sin ser aun un jubilado.");
    } else {
        puts("\nEres un niño o un jubilado.");
    }

    return 0;
}
