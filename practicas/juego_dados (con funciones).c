#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int asignar_dados();
void juego(int);
int tirada(int);
void pregunta_plantarse();
void resultado_final();

int jugador_plantado=0;
int pts_banca=0;
int pts_jugador=0;
int limite_banca; // Limite el cual la banca si supera se planta automáticamente
int limite; // Limite de pts según los dados elegidos. No se puede superar para poder ganar.

int main () {
    srand(time(NULL));

    juego(asignar_dados());
    resultado_final();

}

int asignar_dados() {
    const char* SELECCION_DADOS="¿Cuántos dados quieres(1-3)?: ";
    const char* UN_DADO="\nJugarás con 1 dado. Para ganar la partida no debes superar la cifra de 11. Suerte!";
    const char* DOS_DADOS="\nJugarás con 2 dados. Para ganar la partida no debes superar la cifra de 21. Suerte!";
    const char* TRES_DADOS="\nJugarás con 3 dados. Para ganar la partida no debes superar la cifra de 31. Suerte!";

    int dados;

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

    return dados;

}

void juego(int dados) {
    const char* TURNO_BANCA="\nTurno de la banca: ";
    const char* TURNO_JUGADOR="\nTurno del jugador: ";
    const char* PTS_BANCA="\n\nPuntos de la banca: %d";
    const char* PTS_JUGADOR="\nPuntos del jugador: %d";

    int banca_plantada=0;
    
    do {
        if(banca_plantada==0) {
                printf(TURNO_BANCA);
                pts_banca+=tirada(dados);
                if (pts_banca > limite_banca) { // Comprobamos si en la ronda actual la banca ha superado el limite de puntos establecido por nosotros para que se plante automáticamente.
                    banca_plantada=1;
                }
            }

            if(jugador_plantado==0) {
                printf(TURNO_JUGADOR);
                pts_jugador+=tirada(dados);
            }

            printf(PTS_BANCA, pts_banca);
            printf(PTS_JUGADOR, pts_jugador);

            if (pts_jugador > limite || pts_banca > limite) break;

            pregunta_plantarse();

    } while (!(jugador_plantado == 1 && banca_plantada == 1));
}

int tirada(int dados) {
    int acumulado_ronda;
    int dado;

    acumulado_ronda=0;  // Inicializamos variable dentro del if ya que cuando empieza la ronda debe estar siempre a 0.
    for (int i=1; i<=dados; i++) {
        dado=rand()%6 +1;
        printf("%d ", dado);
        acumulado_ronda+=dado;
    }
    return acumulado_ronda;
}

void pregunta_plantarse() {
    const char* PLANTARSE="\nQuieres plantarte aquí o quieres continuar?(p/P SÍ. Otro caracter NO): ";

    char eleccion_plantarse;

    if (jugador_plantado==0) {
            printf(PLANTARSE);
            scanf("%c", &eleccion_plantarse);
            while(getchar()!='\n');

            if (eleccion_plantarse == 'P' || eleccion_plantarse == 'p') jugador_plantado=1;
        }
}

void resultado_final() {
    const char* FIN_PARTIDA="\n\n--- Fin de la partida ---";
    const char* VICTORIA_JUGADOR="\n¡JUGADOR HA GANADO LA PARTIDA!";
    const char* VICTORIA_BANCA="\n¡BANCA HA GANADO LA PARTIDA!";
    const char* EMPATE="\nDesafortunadamente ninguno se ha superado al otro, quedando en EMPATE";
    const char* AMBOS_EXCESO_PTS="\nHabéis tentado a la suerte... y de nada ha servido. Ambos habéis PERDIDO.";

    printf(FIN_PARTIDA);

    if (pts_jugador > limite && pts_banca > limite) printf(AMBOS_EXCESO_PTS);
    else if (pts_jugador <= limite && pts_banca <= limite) {
        if (pts_jugador > pts_banca) printf(VICTORIA_JUGADOR);
        else if (pts_jugador == pts_banca) printf(EMPATE);
        else printf(VICTORIA_BANCA);
    } else if (pts_jugador > limite) printf(VICTORIA_BANCA);
    else if (pts_banca > limite) printf(VICTORIA_JUGADOR);
}
