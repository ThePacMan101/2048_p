
#include "files.h"
#include "ranking.h"

void tickRanking(tCommand command, bool *running, tGame *game, tState *state) {
    switch (command) {
        case '0':
            *state = state_mainMenu;
            break;

        default:

            break;
    }
}

void renderRanking() {
    renderLogo();
    printf("\n");
    printf("\t Ranking \t\t #: \t Highscore      Name\n");
    printf("\t\t[0] Exit\n");

    int size;
    
    tUser *array = sortUsersByHighScore(&size);

    
    
    
}