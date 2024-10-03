#include <stdio.h>

const char* ENTRADA_DINERO="Inserte el importe necesario para el producto deseado (No se admiten monedas menores de céntimos): ";

int pedir_dinero();
int comprobacion_dinero();

int main() {



}

int pedir_dinero() {
    int moneda;
    printf(ENTRADA_DINERO);
    scanf("%d", &moneda);
    while(getchar()!='\n');

    return moneda;
}

int comprobacion_dinero(int moneda) {

}

