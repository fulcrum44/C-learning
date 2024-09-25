#include <stdio.h>

const char* OPCION_A="a) Ingresar factura\n";  // Por ahora el asterísco sirve para la definción de un string.
const char* OPCION_B="b) Modificar factura\n";
const char* OPCION_C="c) Borrar factura\n";
const char* OPCION_D="d) Listar factura\n";
const char* PREGUNTA_OPCION="Elige una opción...";
const char* RESULTADO_A="Ahora deberías INTRODUCIR los datos de la factura\n";
const char* RESULTADO_B="Ahora deberías MODIFICAR los datos de la factura\n";
const char* RESULTADO_C="Ahora deberías BORRAR los datos de la factura\n";
const char* RESULTADO_D="Ahora deberías LISTAR los datos de la factura\n";
const char* ERROR_OPCION="La opción elegida no es válida\n";

char opcion;

int main (void) {

    puts(OPCION_A);
    puts(OPCION_B);
    puts(OPCION_C);
    puts(OPCION_D);

    puts(PREGUNTA_OPCION);
    scanf("%c", &opcion);

    // if (opcion=='a'){
    //     puts(RESULTADO_A);
    // }else if (opcion=='b') {
    //     puts(RESULTADO_B);
    // }else if (opcion=='c') {
    //     puts(RESULTADO_C);
    // }else if (opcion=='d') {
    //     puts(RESULTADO_D);
    // }else {
    //     puts(ERROR_OPCION);
    // }

    switch(opcion) {
        case 'a':
            puts(RESULTADO_A);
            break;
        case 'b':
            puts(RESULTADO_B);
            break;
        case 'c':
            puts(RESULTADO_C);
            break;
        case 'd':
            puts(RESULTADO_D);
            break;
        default:
            puts(ERROR_OPCION);
    }

    return 0;
}