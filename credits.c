#include "credits.h"

void tickCredits(tCommand command, bool *running, tGame *game, tState *state) {
    if(command==key_LEAVE) *state=state_mainMenu;
}

void renderCredits() {
    renderLogo();
    printf("\n");

    printf("\tDeveloped by:\n\n");
    
    printf("\t \e[1;31mLeonardo Lima Santos\x1b[0m \n");
    printf("\t \e[1;33mLucas Pimentel Alves da Costa\x1b[0m \n");
    printf("\t \e[1;34mPaulo Roberto Ferreira de Godoy Moreira\x1b[0m\n");
    printf("\t \e[1;35mVitor Amaral Bedin\x1b[0m \n");

    printf("\n");
    printf("\t[0] Exit\n");
}
