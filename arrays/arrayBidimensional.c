#include <stdio.h>
#include <stdbool.h>

int main() {

    int tabla[4][3]={{5,6,7},{1,2,3},{4,12,0},{7,-1,45}}; // Filas y columnas, en ese orden, son los parámteros definidos en un array bidimensional

    for (int i=0; i<4; i++) {
        puts("");
        for (int j=0; j<3; j++){
            printf("%d ", tabla[i][j]);
        }
    }

    return 0;
}