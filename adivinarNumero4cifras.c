#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 3. Adivina el número. Crea un programa que genere un nº de 4 cifras DISTINTAS, sin mostrarselo al usuario y le pida que lo adivine. De manera repetida, leerá la información que le de el usuario, y mostrará unas pistas:
//  + significa que ha acertado el número de esa posición.
//  - significa que no ha acertado el nº de esa posición.
//  * significa que el nº está presente pero no en esa posición
// Por ejemplo. Supongamos que el programa ha generado el nº 2468
//  Si el ususario introduce 1234 -> el programa contesta -*-*
//  Si el ususario introduce 2456 -> el programa contesta ++-*
//  Si el ususario introduce 2468 -> el programa contesta ++++ y entonces termina


const char* PEDIR_NUMERO="\nIntroduce un número de 4 cifras diferentes.\n";
const char* ACIERTO="\n\nMuy bien!";
const char* INTENTOS_CERO="\n\nNo vales para esto... El número oculto era: %c%c%c%c";

char primera, segunda, tercera, cuarta;
char u1, u2, u3, u4;
int aciertos;
int intentos=5;


int main() {
    srand(time(NULL));

    // do {
    //     primera='0' + rand()%10;
    //     segunda='0' + rand()%10;
    //     tercera='0' + rand()%10;
    //     cuarta='0' + rand()%10;

    // } while (
    //     primera == segunda || primera == tercera || primera == cuarta || segunda == tercera || segunda == cuarta || tercera == cuarta
    // );

    primera='0' + rand()%10;
    do {
        segunda='0' + rand()%10;
    } while (primera == segunda);

    do {
        tercera='0' + rand()%10;
    } while (primera == tercera || segunda == tercera);

    do {
        cuarta='0' + rand()%10;
    } while (primera == cuarta || segunda == cuarta || tercera == cuarta);

    do {
        do {
            printf(PEDIR_NUMERO);
            scanf("%c%c%c%c", &u1, &u2, &u3, &u4);
            while(getchar()!='\n');
        } while ( !(
            (u1 >= '0' && u1 <= '9') &&
            (u2 >= '0' && u2 <= '9' && u2 != u1) &&
            (u3 >= '0' && u3 <= '9' && u3 != u1 && u3 != u2 ) &&
            (u4 >= '0' && u4 <= '9' && u4 != u1 && u4 != u2 && u4 != u3))
        );

        puts("");
        aciertos=0; //Asignamos el valor 0 a la variable en esta posición dentro del bucle para reiniciar su valor.

        if(u1 == primera) {
            printf("+");
            aciertos++;
        } else if (u1 == segunda || u1 == tercera || u1 == cuarta) {
            printf("*");
        } else {
            printf("-");
        }

        if(u2 == segunda) {
            printf("+");
            aciertos++;
        } else if (u2 == primera || u2 == tercera || u2 == cuarta) {
            printf("*");
        } else {
            printf("-");
        }

        if(u3 == tercera) {
            printf("+");
            aciertos++;
        } else if (u3 == primera || u3 == segunda || u3 == cuarta) {
            printf("*");
        } else {
            printf("-");
        }
        
        if(u4 == cuarta) {
            printf("+");
            aciertos++;
        } else if (u4 == primera || u4 == segunda || u4 == tercera) {
            printf("*");
        } else {
            printf("-");
        }

        intentos--;
    } while(aciertos < 4 && intentos > 0);

    // printf("c", (u4 == cuarta)? '+' : ((u4 == primera || u4 == segunda || u4 == tercera)? '*' : '-'));  // Podría ser otra manera de comprobar las cifras.

    if (aciertos == 4) {
        puts(ACIERTO);
    } else if (intentos == 0) {
        printf(INTENTOS_CERO, primera, segunda, tercera, cuarta);
    }

    return 0;
}