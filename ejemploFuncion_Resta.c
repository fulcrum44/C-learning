#include <stdio.h>

int pide(int);

const char* INFO="\nEste programa resta dos números";
const char* PIDE_NUMERO="\nDame un nº entre 1 y %d: ";
const char* AGRADECIMIENTO="\nBien, gracias";
const char* RESULTADO="\nLa resta de %d y %d da como resultado %d";


int main() {
    printf(INFO);
    int primero=0;
    int segundo=0;
    
    primero=pide(1000);
    printf(AGRADECIMIENTO);
    segundo=pide(primero);
    printf(RESULTADO, primero, segundo, primero - segundo);

    return 0;
}

int pide(int limite){
    int dato;
    do {
        printf(PIDE_NUMERO, limite);
        scanf("%d", &dato);
        while(getchar()!='\n');
    } while (dato <= 0 || dato > limite);

    return dato;
}