#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h> // Librería para la función sleep

// Máquina expendedora. En esta versión aún no sabemos hacer que una función nos devuelva más de un dato, lo que sería útil. A la vez, con arrays podríamos simplificar la manera en la que guardamos y accedemos a los números de los productos y sus precios.

int pedir_dinero();
int menu(int);
void comprobacion_dinero(int, int, int);

const int PRECIO_1=85;
const int PRECIO_2=95;
const int PRECIO_3=60;
const int PRECIO_4=100;
const int PRECIO_5=125;

int precio;

int main() {
    srand(time(NULL));

    int saldo;

    saldo=pedir_dinero();
    sleep(2);
    system("cls");
    comprobacion_dinero(saldo, precio, menu(saldo));

}

int pedir_dinero() {
    const char* ENTRADA_DINERO="Inserte el importe necesario para el producto deseado (No se admiten monedas menores de céntimos).: ";
    const char* IMPORTE_MINIMO="\nImporte no válido. EL importe mínimo admitido es 5 céntimos.";
    const char* IMPORTE_MAXIMO="\nImporte no válido. EL importe mínimo admitido es 5 euros (500 céntimos).";
    const char* MINIMO_CINCO_CENTS="\nNo se aceptan monedas más pequeñas de 5 céntimos.";

    int dinero;

    do {
        printf(ENTRADA_DINERO);
        scanf("%d", &dinero);
        while(getchar()!='\n');

        if (dinero < 5 ) printf(IMPORTE_MINIMO);
        else if (dinero > 500 ) printf(IMPORTE_MAXIMO);
        else if (dinero%5 != 0 ) printf(MINIMO_CINCO_CENTS);

    } while (dinero%5 != 0 && dinero >= 5 && dinero <=500);

    return dinero;
}

int menu(int saldo) {
    const char* SALDO_DISPONIBLE="Saldo disponible: %d";
    const char* MENU_ELEGIR="\n\nElige un producto:\n1) Café solo: 0.85€\n2) Café manchado: 0.95€\n3) Café con leche: 0.60€\n4) Leche con cacao: 1.00€\n5) Capuccino: 1.25€\n6) Sorpréndeme\n";
    const char* ERROR_MENU="\nOpción no valida. (Pulsa ENTER para continuar)";

    int producto;

    while (producto < 1 || producto > 6) {
        printf(SALDO_DISPONIBLE, saldo );
        printf(MENU_ELEGIR);
        scanf("%d", &producto);
        while(getchar()!='\n');

        if (producto == 6) producto=rand()%5 +1;

        switch (producto) {
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
            default:
                printf(ERROR_MENU);
                getchar();
                system("cls");
                break; 
        }
    }
    return producto;
}

void comprobacion_dinero(int saldo, int precio, int producto) {

    const char* SALDO_INSUFICIENTE="\nNo hay suficiente dinero para este producto.";
    const char* SALDO_JUSTO="\nRecoga su producto(%d)";
    const char* TEXTO_CAMBIO=" y su cambio: ";
    
    int cambio=saldo-precio;

    if(cambio<0){
        puts(SALDO_INSUFICIENTE);
    }else{
        printf(SALDO_JUSTO, producto);
    } 
    
    if(cambio>0){
        printf(TEXTO_CAMBIO);
        if(cambio>=200){
            printf("%dx2€",cambio/200);
            cambio%=200;
        }
        if(cambio>=100){
            printf("%dx1€",cambio/100);
            cambio%=100;
        }
        if(cambio>=50){
            printf("%dx50c",cambio/50);
            cambio%=50;
        }
        if(cambio>=20){
            printf("%dx20c",cambio/20);
            cambio%=20;
        }
        if(cambio>=10){
            printf("%dx10c",cambio/10);
            cambio%=10;
        }
        printf("%dx5c",cambio/5);
    }
}