#include "common.h"
#include "files.h"
#include "game.h"
#include "menu.h"
// #include "menu.h"
// #include "pregame.h"
// #include "credits.h"
// #include "defeatGame.h"
// #include "options.h"
// #include "ranking.h"

void tick(tCommand command, bool *running, tGame *game, tState *state) {
    switch (*state) { //Redirects the tick depending on the current state of the game
        case state_mainMenu:
            tickMainMenu(command, running, game, state);
            break;
        case state_optionsMenu:
            tickOptions(command, running, game, state);
            break;
        case state_scoresMenu:
            // TODO
            break;
        case state_rankingMenu:
            tickRanking(command, running, game, state);
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
            break;
        case state_creditsMenu:
            tickCredits(command, running, game, state);
            break;
        case state_deleteUser:
            tickDeleteUser(command, running, game, state);
            break;
        case state_deleteUser1:
            tickDeleteUser1(command, running, game, state);
            break;
        default:
            break;
    }
}

void render(tState state, tGame game) {
    switch (state) { //Redirects the render depending on the current state of the game
        case state_mainMenu: 
            renderMainMenu(state);
            break;
        case state_optionsMenu:
            renderOptions();
            break;
        case state_scoresMenu:
            // TODO
            break;
        case state_rankingMenu:
            renderRanking();
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
            break;
        case state_creditsMenu:
            renderCredits();
            break;
        case state_deleteUser:
            renderDeleteUser();
            break;
        case state_deleteUser1:
            renderDeleteUser1(game);
            break;
        default:
            break;
    }
}

tCommand getCommand(tState state) {
    tCommand command = getch();
    if ((state == state_mainMenu) && (command < '0' || command > '4')) return getCommand(state);
    return command;
}

void emptyGameBoard(tGame *game) {
    game->board[0][0] = 0;
    game->board[0][1] = 0;
    game->board[0][2] = 0;
    game->board[0][3] = 0;
    game->board[1][0] = 0;
    game->board[1][1] = 0;
    game->board[1][2] = 0;
    game->board[1][3] = 0;
    game->board[2][0] = 0;
    game->board[2][1] = 0;
    game->board[2][2] = 0;
    game->board[2][3] = 0;
    game->board[3][0] = 0;
    game->board[3][1] = 0;
    game->board[3][2] = 0;
    game->board[3][3] = 0;
    return;
}
