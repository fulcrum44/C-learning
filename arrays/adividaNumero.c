#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#define LONGITUD 4

// 3. Adivina el número. Crea un programa que genere un nº de 4 cifras DISTINTAS, sin mostrarselo al usuario y le pida que lo adivine. De manera repetida, leerá la información que le de el usuario, y mostrará unas pistas:
//  + significa que ha acertado el número de esa posición.
//  - significa que no ha acertado el nº de esa posición.
//  * significa que el nº está presente pero no en esa posición
// Por ejemplo. Supongamos que el programa ha generado el nº 2468
//  Si el ususario introduce 1234 -> el programa contesta -*-*
//  Si el ususario introduce 2456 -> el programa contesta ++-*
//  Si el ususario introduce 2468 -> el programa contesta ++++ y entonces termina


const char* PEDIR_NUMERO="\nIntroduce un número de 4 cifras diferentes.\n";

void generador_oculto();
void pide_numero();
void compara();

int oculto[LONGITUD];
int usuario[LONGITUD];

int main () {
    srand(time(NULL));

    generador_oculto();
    pide_numero();
    compara();

    return 0;

}

void generador_oculto() {
    bool repetido; //Establecemos un booleano para luego evitar cifras repetidas.
    
    do {
        for (int i=0; i<LONGITUD; i++) {
            oculto[i]=rand()%10;
            repetido=false; //De primeras no hay ningún número repetido, por lo que establecemos su variable como false. 
            printf("%d", oculto[i]);

            for (int j=0; j<i; j++) {
                if (oculto[i] == oculto[j])
                repetido=true; // Si se repite un número cambiará a true, dando por terminado el bucle en ejecución.
                break;
            }
        }
    } while(repetido); // El bucle se ejecutará repetidas veces siempre y cuando el boolean repetido se encuentre en situación 'true'. No queremos ningún número repetido.

}

void pide_numero() {
    bool valido;

    // Pedimos un número al usuario de tantas cifras como se haya definido.

    do {
        printf(PEDIR_NUMERO);

        for (int i=0; i<LONGITUD; i++) {
            scanf("%d", &usuario[i]);
            while(getchar()!='\n');
        }

        valido=true;

        for (int i=0; i<LONGITUD; i++) {
            if (usuario[i] < 0|| usuario[i] > 9) {
                valido=false;
                break;
            }

            for (int j=0; j<i; j++) {
                if (usuario[j] == usuario[i]) {
                    valido=false;
                    break;
                }
            }

            if (!valido) break;
        }

    } while (!valido);
}

void compara() {
    bool coincidencia;
    
    for (int i=0; i<LONGITUD; i++) { //Revisamos las cifras introducidas con las del número oculto.
        coincidencia=false;

        for (int j=0; j<LONGITUD; j++) {
            if (usuario[i] == oculto[j]) {
                coincidencia=true;
                if (i == j) printf("+");
                else printf("*");
                break;
            }
        }
    }

    if (!coincidencia) printf("-");
}