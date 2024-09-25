# include <stdio.h>


int main(){
        int edad;
        float altura;
        char sexo;

        puts("Hola");

        puts("\nDime tu edad: ");
        scanf("%d", &edad); // Scanf sirve para leer una entrada por teclado. Se especifica el tipo de dato que vamos a introducir y luego especificamos la variable donde guardaremos ese dato.
        while(getchar()!='\n'); // Explicación próximamente.
        puts("\nDime tu altura: ");
        scanf("%f", &altura);        
        while(getchar()!='\n');
        puts("\nDime tu sexo: ");
        scanf("%c", &sexo);        
        
        printf("\nLa edad es %i, la altura es %f y el sexo es %c", edad, altura, sexo);
        
        return 0;
}

/* Tipos de variables: 

int -> números enteros, tanto positivos como negativos y el cero

float -> numeros enteros que pueden tener decimal

double -> números enteros que pueden tener decimales con más precisión que el float 

char -> Cadenas de caracteres. Deben ser almacenadas con comillas simples.
*/