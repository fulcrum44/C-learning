#include <stdio.h>

const char* ENTRADA="Introduce un año: ";
const char* BISIESTO="\n%i es bisiesto";
const char* NO_BISIESTO="\n%i no es bisiesto";
const char* ERROR="\nEl valor introducido no es numérico.";

int year;

int main(void){

    puts(ENTRADA);
    scanf("%i", &year);

    // while () {
        if (year%4==0) {
            if (year%100==0 && year%400==0) {
                printf(BISIESTO, year);
            } else if (year%100==0 && year%400!=0) {
                printf(NO_BISIESTO, year);
            } else {
                printf(BISIESTO, year);
            }
        } else {
            printf(NO_BISIESTO, year);
        }
    //}

}