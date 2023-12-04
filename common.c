#include "common.h"
#include "menu.h"
#include "game.h"

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
            // TODO
            break;
        case state_victoryGame:
            // TODO
            break;
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
            // TODO
            break;
        case state_victoryGame:
            // TODO
            break;
        default:
            break;
    }
}

tCommand getCommand() {
    tCommand command = getch();
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