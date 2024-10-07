#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const char* ENTRADA_DINERO="Inserte el importe necesario para el producto deseado (No se admiten monedas menores de céntimos).: ";
const char* IMPORTE_MINIMO="\nImporte no válido. EL importe mínimo admitido es 5 céntimos.";
const char* IMPORTE_MAXIMO="\nImporte no válido. EL importe mínimo admitido es 5 euros (500 céntimos).";
const char* MINIMO_CINCO_CENTS="\nNo se aceptan monedas más pequeñas de 5 céntimos.";


int pedir_dinero();
int menu();
void comprobacion_dinero(int, int);


const int PRECIO_1=85;
const int PRECIO_2=95;
const int PRECIO_3=60;
const int PRECIO_4=100;
const int PRECIO_5=125;

int main() {

    srand(time(NULL));

    int producto;
    int precio;
    int saldo;

    saldo=pedir_dinero();
    producto=menu();

    switch(producto) {

        case 1:
            precio=PRECIO_1;
            break;
        
        case 2:
            precio=PRECIO_2;
            break;
        
        case 3:
            precio=PRECIO_3;
            break;

        case 4:
            precio=PRECIO_4;
            break;
        case 5:
            precio=PRECIO_5;
            break;
    }

    comprobacion_dinero(saldo, precio);

}

int pedir_dinero() {
    int dinero;

    do {
        printf(ENTRADA_DINERO);
        scanf("%d", &dinero);
        while(getchar()!='\n');

        // if (dinero < 5 ) printf(IMPORTE_MINIMO);
        // else if (dinero > 500 ) printf(IMPORTE_MÁXIMO);
        // else if (dinero%5 != 0 ) printf(MINIMO_CINCO_CENTS);

    } while (dinero%5 != 0 && dinero >= 5 && dinero <=500);

    return dinero;
}

int menu() {
    const char* ELEGIR="\nElige un producto:";
    const char* ERROR_MENU="\nOpción no valida. Elige de nuevo.";
    const char* PRODUCTO_1="\n1) Café solo: %i";
    const char* PRODUCTO_2="\n2) Café manchado: %i";
    const char* PRODUCTO_3="\n3) Café con leche: %i";
    const char* PRODUCTO_4="\n4) Leche con cacao: %i";
    const char* PRODUCTO_5="\n5) Capuccino: %i";
    const char* PRODUCTO_6="\n6) Sorpréndeme\n";

    int opcion_menu=0;
    while (opcion_menu > 6 || opcion_menu < 1) {

        printf(ELEGIR);
        printf(PRODUCTO_1, PRECIO_1);
        printf(PRODUCTO_2, PRECIO_2);
        printf(PRODUCTO_3, PRECIO_3);
        printf(PRODUCTO_4, PRECIO_4);
        printf(PRODUCTO_5, PRECIO_5);
        printf(PRODUCTO_6);
        scanf("%d", &opcion_menu);
        while(getchar()!='\n');

        if (opcion_menu == 6)
            opcion_menu=rand()%5 +1;
        else if (opcion_menu > 6 || opcion_menu < 1) printf(ERROR_MENU);

    }

    return opcion_menu;
}

void comprobacion_dinero(int saldo, int precio) {

    const char* SALDO_INSUFICIENTE="\nNo hay suficiente dinero para este producto.";
    const char* SALDO_SUFICIENTE="\nRecoga su producto(%d)";
    int cambio=saldo-precio;

    if (saldo < precio) printf(SALDO_INSUFICIENTE);
    else if (saldo > precio) {
        
    }


}

