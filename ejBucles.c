#include <stdio.h>

int main (void) {

    //ej 23
    for (int i=1; i<=100; i+=3) {
        printf("%i ", i);
    }

    puts("\n");

    //ej 24
    int i=1;
    while (i<=100) {
        printf("%i ", i);
        i+=3;
    }

    puts("\n");

    //ej 25
    int j=1;
    do {
        printf("%i ", j);
        j+=3;
    } while (j<=100);

    return 0;
}