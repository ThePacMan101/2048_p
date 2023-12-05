#include "common.h"
#include "game.h"
#include "pregame.h"
#include "files_alt.h"
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
            strcpy(game->user.name,"guest-user");
            game->user.id=-1;
            *state = state_playingGame;
            startGame(game);
            break;
        case '2':
            login(game);
            *state = state_playingGame;
            startGame(game);
            break;
        case '0':
            *state = state_mainMenu;
            break;
        default:
            break;
    }
}

void login(tGame *game) {
    tUser user;
    renderLogo();
    printf("\n");
    printf("\tEnter your username: ");
    scanf("%s", user.name);
    loadUser(&user);
    game->user=user;
}
