#include "preGame.h"
#include "game.h"

void renderPreGame(tState state, tGame game) {
    renderLogo();

    printf("\t\n Press [1] to play as guest\n");
    printf("\t Press [2] to login\n\n");

    printf("\t Press [0] to exit\n");
}

void tickPreGame(tCommand command, bool *running, tGame *game, tState *state) {
    switch (command) {
        case '1':
            game->user.id = -1;
        case '2':
            startGame(game);
            *state = state_playingGame;
            break;
        case '0':
            *state = state_mainMenu;
            break;
        default:
            break;
    }
}