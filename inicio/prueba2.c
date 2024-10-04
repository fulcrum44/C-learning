#include <stdio.h>

int x, y, z=0;

int main (void){
    x=3;
    y=5;
    x*=10; // x=x*10;
    x-=5; // x=x-5; Estas dos últimas asignaciones son la manera abreviada de escribirlas cuando estas están basadas en variaciones numéricas.
    z++; // z+=1 // z=z+1
    y=10%x;
    printf("\nx=%d y=%d z=%d", x, y, z);
}