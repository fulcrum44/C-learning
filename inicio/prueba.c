# include <stdio.h>
# define IVA 0.20f // Definición de constantes. Con f = float. SIn f = double



int main(){
        const int EDAD=10; // Const hace que el valor de una variable sea constante. Tomará el valor que se le haya dado inicialmente. Las variables constantes se suelen declrar en mayúsculas.
        int altura;
        // altura=120;
        char sexo='H';

        puts("Hola"); // puts sirve para mostrar en pantalla solo texto sin haberle dado ningún valor ni variables. Mejor usar printf.
        printf("\nLa edad es %i", EDAD);
        printf("\nEl sexo es %c", sexo);
        printf("\nLa edad es %i y el sexo %c", EDAD, sexo); //Se ponen las variables que queremos uar separadas entre coma en orden según hayamos puesto los parámetros en nuestra salida.

        altura=EDAD; //Esto es una asignación. La variable de la izquierda toma el valor de la variable de la derecha.

        printf("\n\nEL iva está a %06.2f", IVA); // Al parámetro float se le puede especificar cuántos decimales queremos que salgan en salida, especficado a la derecha del punto. A la izquiera del punto podemos especificar la longitud del número que queremos en salida. Debemos poner un 0 delante si queremos que la falta de dígitios se ocupen por cero.

        printf("\nLa edad es %i, la altura es %i y el sexo es %c", EDAD, altura, sexo);
        
        return 0;
}

/* Tipos de variables: 

int -> números enteros, tanto positivos como negativos y el cero

float -> numeros enteros que pueden tener decimal

double -> números enteros que pueden tener decimales con más precisión que el float 

char -> Cadenas de caracteres. Deben ser almacenadas con comillas simples.
*/