#include <stdio.h>

int op1;
float op2;

int main(void) {

    puts("Vamos a realizar el producto de dos números insertados por teclado.\n");
    puts("Introduce el primero operando: \n");
    scanf("%d", &op1);
    while(getchar()!='\n');

    puts("Introduce el segundo operando: \n");
    scanf("%f", &op2);

    printf("El producto de multiplicar %d y %0.2f es: %0.2f", op1, op2, op1 * op2);

    return 0;

}

