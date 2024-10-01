#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int tiradas;
    int cara=0;
    int cruz=0;
    int tirada;

    puts("¿Cuántas tiradas quieres realizar...?");
    scanf("%i", &tiradas);
    while(getchar()!='\n');

    for (int i=1; i<=tiradas; i++) {
        tirada=rand()%2;
        if (tirada==0) cara++;
        else cruz++;
    }

    printf("Se han realizado %i tiradas. Han salido %i veces CARA y %i CRUZ.", tiradas, cara, cruz);

}