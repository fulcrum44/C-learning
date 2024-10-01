#include <stdio.h>

int main(void) {
    int producto;
    for (int i=1; i<=10; i++) { // Un valor por línea
        // Comienzo de cada línea
        printf("\n%2d  ->  ", i);
        for (int j=1; j<=15; j++) { // Repeticiones que habrá en la líneas definidas en el bucle anterior.
            producto=i*j;
            if ((producto)>=50) {
                break;
            } else if ((producto)%5==0) {
                printf("---  ");
            } else {
                printf("%3d  ", producto);
            }
        }
    }

    return 0;
}