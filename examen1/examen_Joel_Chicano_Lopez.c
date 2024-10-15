#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int solicitud_numero_preguntas(int);
float test(int);
int generador_preguntas();
int generador_operando();
void resultados(float);

; // Inicializamos la variable con el valor 0 para que pueda ejecutarse el bucle por primera vez.
int aciertos=0;
int fallos=0;

int main() {
    srand(time(NULL));

    resultados(test(solicitud_numero_preguntas(0)));

    return 0;
}

int solicitud_numero_preguntas(int cantidad_preguntas) {
    char* const NUMERO_PREGUNTAS="Dime cuántas preguntas quieres responder: ";

    do {
        printf(NUMERO_PREGUNTAS);
        scanf("%d", &cantidad_preguntas);
        while(getchar()!='\n');
    } while (cantidad_preguntas < 1);

    return cantidad_preguntas;
}

float test(int cantidad_preguntas) {
    char* const RESPUESTA_CORRECTA="!Bien!\n";
    char* const RESPUESTA_INCORRECTA="!Mal! (%d)\n";

    int resultado;
    int respuesta;
    float puntos=0;

    for (int i=1; i<=cantidad_preguntas; i++) {
        printf("\n%d - ", i);
        resultado=generador_preguntas(); // Guardamos el resultado de las operaciones generadas para luego comprobarlas en esta misma función.

        if (scanf("%d", &respuesta) !=1) { // Evitamos la entrada de letras del abecedario.
            printf(" ");
            i--; // Al haber introducido una letra del abecedario no nos interesa pasar a la siguiente pregunta. Queremos preguntar otra vez con el mismo número.
        } 
        else {
            if (respuesta == resultado) {
                printf(RESPUESTA_CORRECTA);
                aciertos++;
                puntos+=1;
            }
            else {
                printf(RESPUESTA_INCORRECTA, resultado);
                fallos++;
                puntos-=0.5;
            }
        }
        while(getchar()!='\n');
    }
    return puntos;
}

int  generador_preguntas() {
    int operacion; // Si es 0 se generará una suma, 1 para resta y 2 para multiplicación
    int primer_valor;
    int segundo_valor;
    int resultado;
 
    operacion=rand()%3;
    primer_valor=generador_operando();
    segundo_valor=generador_operando();

    switch (operacion){
        case 0:
            printf("¿ %d + %d ? ", primer_valor, segundo_valor);
            resultado=primer_valor+segundo_valor;
            break;
        
        case 1:
            if (primer_valor > segundo_valor) {
                printf("¿ %d - %d ? ", primer_valor, segundo_valor);
                resultado=primer_valor-segundo_valor;
            }
            else {
                printf("¿ %d - %d ? ", segundo_valor, primer_valor);
                resultado=segundo_valor-primer_valor;
            }
            break;

        case 2:
            printf("¿ %d * %d ? ", primer_valor, segundo_valor);
            resultado=primer_valor*segundo_valor;
            break;
    }
    
    return resultado;
}

int generador_operando() {
    int operador;
    operador=rand()%11; //Generamos un valor entre 0 y 10

    return operador;
}

void resultados(float puntos) {
    char* const ACIERTOS="\nAciertos: %d --> %.2f puntos";
    char* const FALLOS="\nFallos: %d --> %.2f puntos";
    char* const PUNTUACION="\nPuntuación: %.2f/%.2f --> ";

    float puntuacion_maxima=aciertos+fallos;

    printf(ACIERTOS, aciertos, aciertos * 1.0);
    printf(FALLOS, fallos, fallos * -0.5);

    printf(PUNTUACION, puntos, puntuacion_maxima);
    printf((puntos >= (puntuacion_maxima/2)? "APTO" : "NO APTO")); //Operador ternario

}