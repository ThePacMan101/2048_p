#include "preGame.h"

#include "common.h"
#include "files.h"
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
            renderLogin(game);
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
void renderLogin(tGame *game) {
    renderLogo();
    printf("\n");
    printf("\tEnter your username: ");
    scanf("%s", game->user.name);

    tUser *Players=convertPlayersToVector();
    if (searchPlayerByName(Players,game->user.name)!=-1) {
        loadGame(game , game->user.id);
        if (game == NULL) {
            printf("\tError loading game!\n");
            printf("\tPress any key to continue...\n");
            getch();
            return;
        }
    } else {
        printf("\tUser not found, user created!\n");
        printf("\tPress any key to continue...\n");
        getch();
        writeNewPlayer(&(game->user));
        //addNewPlayer(game,game->user.id);
    }
}
