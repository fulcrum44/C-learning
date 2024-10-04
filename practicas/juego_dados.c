#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const char* SELECCION_DADOS="¿Cuántos dados quieres(1-3)?: ";
const char* UN_DADO="\nJugarás con 1 dado. Para ganar la partida no debes superar la cifra de 11. Suerte!";
const char* DOS_DADOS="\nJugarás con 2 dados. Para ganar la partida no debes superar la cifra de 21. Suerte!";
const char* TRES_DADOS="\nJugarás con 3 dados. Para ganar la partida no debes superar la cifra de 31. Suerte!";
const char* TURNO_BANCA="\nTurno de la banca: ";
const char* TURNO_JUGADOR="\nTurno del jugador: ";
const char* PTS_BANCA="\n\nPuntos de la banca: %d";
const char* PTS_JUGADOR="\nPuntos del jugador: %d";
const char* PLANTARSE="\nQuieres plantarte aquí o quieres continuar?(p/P SÍ. Otro caracter NO): ";
const char* FIN_PARTIDA="\n\n--- Fin de la partida ---";
const char* VICTORIA_JUGADOR="\n¡JUGADOR HA GANADO LA PARTIDA!";
const char* VICTORIA_BANCA="\n¡BANCA HA GANADO LA PARTIDA!";
const char* EMPATE="\nDesafortunadamente ninguno se ha superado al otro, quedando en EMPATE";
const char* AMBOS_EXCESO_PTS="\nHabéis tentado a la suerte... y de nada ha servido. Ambos habéis PERDIDO.";


int main (void) {

    srand(time(NULL));

    int dados; //Dados seleccionados para jugar
    int limite_banca; // Limite el cual la banca si supera se planta automáticamente
    int limite; // Limite de pts según los dados elegidos. No se puede superar para poder ganar.
    int dado;
    int banca_plantada=0; // Inicializada a 0 para cambiar a otro valor si queremos que la banca se plante y su turno no se ejecute.
    int jugador_plantado=0; // Mismo funcionamiento que el de la banca.
    int acumulado_ronda; // Acumularemos los puntos de los dados lanzados en una ronda.
    int pts_jugador=0; // Guardaremos y sumaremos los puntos acumulados de cada ronda de la partida.
    int pts_banca=0;
    char opcion_plantarse;

    printf(SELECCION_DADOS);
    scanf("%d", &dados);
    while(getchar()!='\n');

    switch(dados) {

        case 2:
            printf(DOS_DADOS);
            limite_banca=15;
            limite=21;
            break;
        
        case 3:
            printf(TRES_DADOS);
            limite_banca=21;
            limite=31;
            break;

        default:
            printf(UN_DADO);
            dados=1;
            limite_banca=8;
            limite=11;
            break;
    }

    do {
    
        if(banca_plantada==0) {
            printf(TURNO_BANCA);
            acumulado_ronda=0; // Inicializamos variable dentro del if ya que cuando empieza la ronda debe estar siempre a 0.
            for (int i=1; i<=dados; i++) {
                dado=rand()%6 +1;
                printf("%d ", dado);
                acumulado_ronda+=dado;
            }
            pts_banca+=acumulado_ronda;

            if (pts_banca > limite_banca) { // Comprobamos si en la ronda actual la banca ha superado el limite de puntos establecido por nosotros para que se plante automáticamente.
                banca_plantada=1;
            }
        }

        if(jugador_plantado==0) {
            printf(TURNO_JUGADOR);
            acumulado_ronda=0;
            for (int i=1; i<=dados; i++) {
                dado=rand()%6 +1;
                printf("%d ", dado);
                acumulado_ronda+=dado;
            }
            pts_jugador+=acumulado_ronda;

        }
        
        printf(PTS_BANCA, pts_banca);
        printf(PTS_JUGADOR, pts_jugador);

        if (pts_jugador > limite || pts_banca > limite) break;

        if (jugador_plantado==0) {
            printf(PLANTARSE);
            scanf("%c", &opcion_plantarse);
            while(getchar()!='\n');

            if (opcion_plantarse == 'P' || opcion_plantarse == 'p') jugador_plantado=1;
        }

        if (jugador_plantado == 1 && banca_plantada == 1) break;

    } while (1);

    printf(FIN_PARTIDA);

    if (pts_jugador > limite && pts_banca > limite) printf(AMBOS_EXCESO_PTS);
    else if (pts_jugador <= limite && pts_banca <= limite) {
        if (pts_jugador > pts_banca) printf(VICTORIA_JUGADOR);
        else if (pts_jugador == pts_banca) printf(EMPATE);
        else printf(VICTORIA_BANCA);
    } else if (pts_jugador > limite) printf(VICTORIA_BANCA);
    else if (pts_banca > limite) printf(VICTORIA_JUGADOR);

    return 0;
    
}