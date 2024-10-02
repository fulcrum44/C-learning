#include <stdio.h>

int pide();

const char* INFO="\nEste programa suma dos números";
const char* PIDE_NUMERO="\nDame un nº entre 1 y 1000: ";
const char* AGRADECIMIENTO="\nBien, gracias";
const char* RESULTADO="\nLa suma de %d y %d da como resultado %d";


int main(void) {
    printf(INFO);
    int primero=0;
    int segundo=0;
    
    primero=pide();
    printf(AGRADECIMIENTO);
    segundo=pide();
    printf(RESULTADO, primero, segundo, primero + segundo);

    return 0;
}

int pide(){
    int dato;
    do {
        printf(PIDE_NUMERO);
        scanf("%d", &dato);
        while(getchar()!='\n');
    } while (dato <= 0);

    return dato;
}