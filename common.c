#include "common.h"
#include "preGame.h"
#include "game.h"
#include "menu.h"
#include "defeatGame.h"
#include "files.h"

void tick(tCommand command, bool *running, tGame *game, tState *state) {
    switch (*state) {
        case state_mainMenu:
            tickMainMenu(command, running, game, state);
            break;
        case state_optionsMenu:
            // TODO
            break;
        case state_scoresMenu:
            // TODO
            break;
        case state_rankingMenu:
            // TODO
            break;
        case state_playingGame:
            tickPlayingGame(command, running, game, state);
            // TODO
            break;
        case state_defeatGame:
            tickDefeatGame(command, running, game, state);
            break;
        case state_victoryGame:
            // TODO
            break;
        case state_preGame:
            tickPreGame(command, running, game, state);
        default:
            break;
    }
}

void render(tState state, tGame game, int opc) {
    switch (state) {
        case state_mainMenu:
            renderMainMenu(state);
            break;
        case state_optionsMenu:
            // TODO
            break;
        case state_scoresMenu:
            // TODO
            break;
        case state_rankingMenu:
            // TODO
            break;
        case state_playingGame:
            renderPlayingGame(state, game);
            // TODO
            break;
        case state_defeatGame:
            renderDefeatGame(game);
            break;
        case state_victoryGame:
            // TODO
            break;
        case state_preGame:
            renderPreGame(state, game);
        default:
            break;
    }
}

tCommand getCommand() {
    tCommand command = getch();
    return command;
}
//

void renderLogo() {
    system("cls");
    printf("\t___________________________________________________________________________________\n\n\n");
    //          ---------------------------------------------------------------------------------
    printf("\t\033[38;2;0;0;255m    /\\\\\\\\\\\\\\\\\\         /\\\\\\\\\\\\\\               /\\\\\\        /\\\\\\\\\\\\\\\\\\            \033[0m\n");
    printf("\t\033[38;2;0;0;255m   /\\\\\\///////\\\\\\     /\\\\\\/////\\\\\\           /\\\\\\\\\\      /\\\\\\///////\\\\\\         \033[0m\n");
    printf("\t\033[38;2;0;0;255m   \\///      \\//\\\\\\   /\\\\\\    \\//\\\\\\        /\\\\\\/\\\\\\     \\/\\\\\\     \\/\\\\\\        \033[0m\n");
    printf("\t\033[38;2;0;0;255m              /\\\\\\/   \\/\\\\\\     \\/\\\\\\      /\\\\\\/\\/\\\\\\     \\///\\\\\\\\\\\\\\\\\\/        \033[0m\n");
    printf("\t\033[38;2;0;0;255m            /\\\\\\//     \\/\\\\\\     \\/\\\\\\    /\\\\\\/  \\/\\\\\\      /\\\\\\///////\\\\\\      \033[0m\n");
    printf("\t\033[38;2;0;0;255m          /\\\\\\//        \\/\\\\\\     \\/\\\\\\  /\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\  /\\\\\\      \\//\\\\\\    \033[0m\n");
    printf("\t\033[38;2;0;0;255m         /\\\\\\/           \\//\\\\\\    /\\\\\\  \\///////////\\\\\\//  \\//\\\\\\      /\\\\\\    \033[0m\n");
    printf("\t\033[38;2;0;0;255m         /\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\  \\///\\\\\\\\\\\\\\/             \\/\\\\\\     \\///\\\\\\\\\\\\\\\\\\/    \033[0m\n");
    printf("\t\033[38;2;0;0;255m         \\///////////////     \\///////               \\///        \\/////////     \033[0m\n");
    printf("\n");
    printf("\t___________________________________________________________________________________\n");
}