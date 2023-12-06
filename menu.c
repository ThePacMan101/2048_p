#include "menu.h"

#include "game.h"

void tickMainMenu(tCommand command, bool *running, tGame *game, tState *state) {
    switch (command) {
        case '1':
            *state = state_preGame;
            break;
        case '2':
            *state = state_optionsMenu;
            break;
        case '3':
            *state = state_rankingMenu;
            break;
        case '4':
            *state = state_creditsMenu;
            break;
        case '0':
            *running = false;
            break;
        default:
            break;
    }
}

void renderMainMenu(tState state) {
    renderLogo();
    renderOptions();
}

//           ---------------------------------------------------------------------------------
//          ____/\\\\\\\\\_________/\\\\\\\_______________/\\\________/\\\\\\\\\____
//           __/\\\///////\\\_____/\\\/////\\\___________/\\\\\______/\\\///////\\\__
//            _\///______\//\\\___/\\\____\//\\\________/\\\/\\\_____\/\\\_____\/\\\__
//             ___________/\\\/___\/\\\_____\/\\\______/\\\/\/\\\_____\///\\\\\\\\\/___
//              ________/\\\//_____\/\\\_____\/\\\____/\\\/__\/\\\______/\\\///////\\\__
//               _____/\\\//________\/\\\_____\/\\\__/\\\\\\\\\\\\\\\\__/\\\______\//\\\_
//                ___/\\\/___________\//\\\____/\\\__\///////////\\\//__\//\\\______/\\\__
//                 __/\\\\\\\\\\\\\\\__\///\\\\\\\/_____________\/\\\_____\///\\\\\\\\\/___
//                  _\///////////////_____\///////_______________\///________\/////////_____

//            ---------------------------------------------------------------------------------
void renderOptions() {
    printf("\t                                 \033[1mWelcome to 2048!\033[0m                          \n");
    printf("\tChoose an option:\n");
    printf("\t\t[1] Play\n");
    printf("\t\t[2] Options\n");
    printf("\t\t[3] Ranking\n");
    printf("\t\t[4] Credits\n");
    printf("\t\t[0] Exit\n");
}
