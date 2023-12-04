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
//