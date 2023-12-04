#include "preGame.h"

void renderPreGame(tState state, tGame game) {
    renderLogo();

    printf("\t Press [1] to play as guest\n");
    printf("\t Press [2] to login\n");
}

void tickPreGame(tCommand command, bool *running, tGame *game, tState *state) {
    switch (command)
    {
    case '1':
        game->user.id = -1;
        startGame(game);
        *state = state_playingGame;
        break;
    case '2':
        
        break;
    default:
        break;
    }
}

renderLoginMenu() {
    renderLogo();
    printf("\n");
    printf("\tEnter your username: ");
}