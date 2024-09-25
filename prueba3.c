#include <stdio.h>

int edad;
int dni;
char letra;

int main (void){
    printf("Cual es tu edad?: ");
    scanf("%d", &edad);

    if (edad >= 14) {
        puts("\nEscribe tu dni sin la letra: ");
        scanf("%d", &dni);
        while(getchar()!='\n');

        puts("\nEscribe ahora la letra de tu dni: ");
        scanf("%d%c", &dni, &letra);
        while(getchar()!='\n');

        printf("\nEres parte de la sociedad, %d-%c. Ahora está vendido al ruso menos peligroso.", dni, letra);
    
    } else if (edad <= 0) {
            puts("La edad introducida debe ser un valor positivo.");
    } else {
            puts("\nEres menor de edad. Estás protegido (teóricamente)");
    }
    
    return 0;

}

