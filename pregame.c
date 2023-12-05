#include "preGame.h"
#include "common.h"
#include "game.h"

void renderPreGame(tState state, tGame game) {
    renderLogo();
    printf("\n");
    printf("\tChoose an option:\n");
    printf("\t\t[1] Play as guest\n");
    printf("\t\t[2] Login\n");
    printf("\t\t[0] Exit\n");
}

void tickPreGame(tCommand command, bool *running, tGame *game, tState *state) {
    switch (command) {
        case '1':
            game->user.id = -1;
            startGame(game);
            *state = state_playingGame;
            break;
        case '2':
            game->user.id = 1;  // provisory, to be changed
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
/**/
void renderLogin() {
    renderLogo();
    printf("\n");
    printf("\tEnter your username: ");
    scanf("%s", game.user.username);
}
