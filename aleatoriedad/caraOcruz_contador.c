#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//2. Crea un programa que simule el lanzamiento de una moneda. La lanzará tantas veces como diga el usuario. Al final mostará simplemente la cantidad de caras y cruces que han salido en los "lanzamientos"

const char* NUM_TIRADAS="¿Cuántas tiradas quieres realizar...?";
const char* RESULTADO="\n\nSe han realizado %i tiradas. Han salido %i veces CARA y %i CRUZ.";

int main() {
    srand(time(NULL));
    int tiradas;
    int cara=0;
    int cruz=0;
    int tirada;

    do {
        puts(NUM_TIRADAS);
        scanf("%i", &tiradas);
        while(getchar()!='\n');
    } while(tiradas < 1);

    for (int i=1; i<=tiradas; i++) {
        tirada=rand()%2;
        printf("%c", (tirada==0)? 'X' : 'C'); //Operador ternario
        if (tirada==0) cara++;
        else cruz++;
    }

    printf(RESULTADO , tiradas, cara, cruz);

    return 0;
}