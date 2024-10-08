#include <stdio.h>
#include <stdlib.h>
#include <time.h> //Añadimos esta y la anterior librería para poder generar nuestra semilla para nuestras generaciones de números aleatorios.

//Prototipos
void jugar();
void enfrentamiento(int);
int selecciona_opcion();
void configurar_tropas();
void configurar_reposicion();
void ver_puntuaciones();
int tirada();

//Constantes globales
const char* MENU_CABECERA = "\nElige una opción:\n";
const char* MENU_OPCION_1 = "1) Configurar tropas\n";
const char* MENU_OPCION_2 = "2) Configurar reposición\n";
const char* MENU_OPCION_3 = "3) Jugar\n";
const char* MENU_OPCION_4 = "4) Ver puntuaciones acumuladas\n";
const char* MENU_OPCION_5 = "5) Salir\n";
const char* MENU_ERROR_OPCION = "Opción no válida\n";
const char* DESPEDIDA = "¡Hasta otra!";
const int TROPAS_MINIMAS=3;
const int REPOSICION_MINIMA=1;
const char* MENSAJE_CONFIGURACION_TROPAS="¿Con cuántas tropas quieres jugar? (>=%d) ";
const char* MENSAJE_CONFIGURACION_REPOSICION="¿Cuántas tropas quieres reponer? (>=%d) ";
const char* MENSAJE_PUNTUACIONES_TOTALES="PUNTUACIONES TOTALES -> Humano:%d  CPU:%d\n";
const char* MENSAJE_TROPAS="\nTROPAS -> Humano:%d  CPU:%d\n";
const char* MENSAJE_TURNO_HUMANO="Turno de ataque para el humano ";
const char* MENSAJE_HUMANO_ELIGE="¿Quieres atacar o reponer? (a/r): ";
const char* MENSAJE_REPOSICION_EJECUTADA="Reposición ejecutada: +%d\n";
const char* MENSAJE_TURNO_CPU="Turno de ataque para la CPU\n";
const char* HUMANO="Humano:\t";
const char* CPU="CPU:\t";
const char* PUNTOS_ATACANTE="%d %d %d\n";
const char* PUNTOS_DEFENSOR="%d %d\n";
const char* VICTORIA_HUMANO="¡Victoria para el humano!\n";
const char* VICTORIA_CPU="¡Victoria para la CPU!\n";
const char* VICTORIA_NULA="¡Nadie gana!\n";

//Variables globales
int puntos_humano=0;
int puntos_cpu=0;
int tropas=5;//Las tropas con que se inician las partidas (configurables)
int tropas_humano;//las tropas que tienen en cada momento los jugadores
int tropas_cpu;
int reposicion=2;//la cantidad que puede reponer el humano cuando decida no atacar (configurable)


int main(void) {
  srand(time(NULL)); // Definimos la semilla para poder generar números aleatorios a lo largo de nuestro programa.

  int opcion;
  
  do {
    selecciona_opcion();
  } while(1);
  
  return 0;
}

void configurar_tropas() {
  tropas=0;

  while (tropas < TROPAS_MINIMAS) {
    printf(MENSAJE_CONFIGURACION_TROPAS, TROPAS_MINIMAS);
    scanf("%d", &tropas);
    while(getchar()!='\n');
  }

  return 0;
}

void configurar_reposicion() {
  reposicion=0;

  while (reposicion < REPOSICION_MINIMA) {
    printf(MENSAJE_CONFIGURACION_REPOSICION, REPOSICION_MINIMA);
    scanf("%d", &reposicion);
    while(getchar()!='\n');
  }

  return 0;

}

void ver_puntuaciones() {
  printf(MENSAJE_PUNTUACIONES_TOTALES, puntos_humano, puntos_cpu);

  return 0;
}

int selecciona_opcion() {
  int opcion=0;

  printf(MENU_CABECERA);
  printf(MENU_OPCION_1);
  printf(MENU_OPCION_2);
  printf(MENU_OPCION_3);
  printf(MENU_OPCION_4);
  printf(MENU_OPCION_5);

  scanf("%d", &opcion);
  while(getchar()!='\n');

  while (opcion < 1 || opcion > 5) {
    switch (opcion) {
      case 1:
        configurar_tropas();
        break;
      case 2:
        configurar_reposicion();
        break;
      case 3:
        jugar();
        break;
      case 4:
        ver_puntuaciones();
        break;
      case 5:
        printf(DESPEDIDA);
        break;
      default:
        printf(MENU_ERROR_OPCION);
        break; 
    }
  }

  return opcion;
}

int tirada() {
  int numero;

  numero=rand()%6 + 1;

  return numero;
}

void jugar(){
  int turno=1;//1=humano, 0=cpu
  char eleccion;//sólo para el humano
  int unidades_repuestas;//0 ó reposición, dependiendo de una moneda a cara-cruz
  //inicializamos los ejércitos
  tropas_humano=tropas;
  tropas_cpu=tropas;
  do{//Este es el bucle del juego propiamente dicho
    //Lo primero siempre es mostrar la unidades de cada uno
    printf(MENSAJE_TROPAS,tropas_humano,tropas_cpu);
    //Luego, es el turno de uno u otro alternativamente
    if(turno==1){
      printf(MENSAJE_TURNO_HUMANO);
      printf(MENSAJE_HUMANO_ELIGE);
      do{
        scanf("%c",&eleccion);
        while(getchar()!='\n');
      }while(eleccion!='a' && eleccion!='r');
      if(eleccion=='r'){
        //// EJERCICIO 9////
        tropas_humano+=reposicion;
        printf(MENSAJE_REPOSICION_EJECUTADA);
      }else{
        //// EJERCICIO 10////
        enfrentamiento(1);
      }
    }else{
      printf(MENSAJE_TURNO_CPU);
      //// EJERCICIO 10////
      enfrentamiento(0);
    }
    //Cambio de turno
    //// EJERCICIO 8////
    turno = (turno == 1) ? 0 : 1; // Si se cumple la condición descrita el valor de turno será el primero, en caso falso será el segundo. 
  }while(tropas_humano > 0 && tropas_cpu > 0);//// EJERCICIO 7////
  //Mensaje de victoria
  printf(MENSAJE_TROPAS,tropas_humano,tropas_cpu);
  //// EJERCICIO 11////
  printf((tropas_humano = tropas_cpu)? VICTORIA_NULA : (tropas_humano > tropas_cpu) ?  VICTORIA_HUMANO : VICTORIA_CPU);
}


void enfrentamiento(int turno){
  int dado;//tirada para luego guardarla en a1, a2, a3, d1, d2
  int a1, a2, a3;//dados de atacante ordenados de mayor a menor
  int d1, d2;//datos de defensor ordenados de mayor a menor
  //Tiradas del atacante
  a1=tirada();
  dado=tirada();
  if(dado>a1){
    a2=a1;
    a1=dado;
  }else{
    a2=dado;
  }
  dado=tirada();
  if(dado<a2){
    a3=dado;
  }else{
    a3=a2;
    if(dado<a1){
      a2=dado;
    }else{
      a2=a1;
      a1=dado;
    }
  }
  //Tiradas del defensor
  d1=tirada();
  dado=tirada();
  if(dado>d1){
    d2=d1;
    d1=dado;
  }else{
    d2=dado;
  }
  //Muestro el resultado de las tiradas
  printf((turno)?HUMANO:CPU);
  printf(PUNTOS_ATACANTE,a1,a2,a3);
  printf((turno)?CPU:HUMANO);
  printf(PUNTOS_DEFENSOR,d1,d2);
  //Actualizo las tropas
  if(turno){//este es el caso de que el atacante sea el humano
    if(a1>d1) tropas_cpu--;
    if(a1<d1) tropas_humano--;
    if(a2>d2) tropas_cpu--;
    if(a2<d2) tropas_humano--;
  }else{//este es el caso de que el atacante sea la CPU
      if(a1>d1) tropas_humano--;
      if(a1<d1) tropas_cpu--;
      if(a2>d2) tropas_humano--;
      if(a2<d2) tropas_cpu--;
  }
  //Evito que puedan quedar negativas
  if(tropas_cpu<0) tropas_cpu=0;
  if(tropas_humano<0) tropas_humano=0;
}

 
