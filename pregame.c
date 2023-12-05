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
            *state = state_playingGame;
            startGame(game);
            break;
        case '2':
            if(login(game,state)) startGame(game);
            break;
        case '0':
            *state = state_mainMenu;
            break;
        default:
            break;
    }
}

bool login(tGame *game,tState*state) {
    renderLogo();
    printf("\n");
    printf("\tEnter your username: ");
    scanf("%s", game->user.name);

    tUser *Players=convertPlayersToVector();
    game->user.id=searchPlayerByName(Players,game->user.name);
    if ((Players!=NULL)&&(game->user.id!=-1)) {
        if(loadGame(game , game->user.id)) return true;
        else{
            printf("\tError loading game!\n");
            printf("\tThis user has no active games\n");
            printf("\tPress any key to continue...\n");
            getch();
            *state=state_mainMenu;
            return false;
        }
        if (game == NULL) {
            printf("\tError loading game!\n");
            printf("\tPress any key to continue...\n");
            getch();
            *state=state_mainMenu;
            return false;
        }
    } else {
        writeNewPlayer(&(game->user));
        *state=state_playingGame;
        printf("\tUser not found, user created!\n");
        printf("\tPress any key to continue...\n");
        getch();
        return true;
    }
}
