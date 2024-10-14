#include <stdio.h>

int main() {

    int cantidad;
    int suma;
    puts("\nDime la cantidad de números que quieres sumar: ");
    scanf("%d", &cantidad);
    while(getchar()!='\n');
    int numeros[cantidad];

    for (int i=0; i<cantidad; i++) {
        puts("\n Dame un número: ");
        scanf("%d", &numeros[i]);
        while(getchar()!='\n');
        suma+=numeros[i];
    }

    puts("");
    for (int i=0; i<cantidad; i++) {
        if (i>0) printf ("+");
        printf("%d", numeros[i]);
    }

    printf("=%d", suma);

    return 0;
}