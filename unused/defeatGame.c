#include "defeatGame.h"
#include "game.h"
#include "files.h"

void tickDefeatGame(tCommand command, bool *running, tGame *game, tState *state) {
    
    switch (command) {
        case key_LEAVE:
            *state = state_mainMenu;
            break;
        default:
            break;
    }
    return;
}

void renderDefeatGame(tGame game) {
    renderLogo();

    printf("\n\tGame over!\n\n");

    printf("\n\n");
    printBoard(game);
    printf("\n\n");

    if(game.user.id!=-1) printf("\t\tPlayer Name: %s\n", game.user.name);
    printf("\t\tScore:       %d\n", game.score);
    if(game.user.id!=-1){
        if (game.user.highScore > game.score) {
            printf("\t\tHighscore:   %d\n\n", game.user.highScore);
        } else {
            printf("\t\tHighscore:   %d!\n\n", game.score);
        }
    }
    printf("\t\tPress [0] to continue.\n");
    return;
}
