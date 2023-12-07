#include "credits.h"

void tickCredits(tCommand command, bool *running, tGame *game, tState *state) {
    if(command==key_LEAVE) *state=state_mainMenu;
}

void renderCredits() {
    renderLogo();
    printf("\n");

    printf("\tDeveloped by:\n");
    printf("\t\t[0] Exit\n\n");
    
    printf("\t\t\t\e[1;31m              Leonardo Lima Santos\x1b[0m \n");
    printf("\t\t\t\e[1;33m          Lucas Pimentel Alves da Costa\x1b[0m \n");
    printf("\t\t\t\e[1;34m     Paulo Roberto Ferreira de Godoy Moreira\x1b[0m\n");
    printf("\t\t\t\e[1;35m               Vitor Amaral Bedin\x1b[0m \n");

    printf("\n");
    
}
