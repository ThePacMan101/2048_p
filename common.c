#include "game.h"
#include <stdio.h>

void tick(tCommand command,bool*running,tGame *game,tState *state){
    switch(*state){
        case state_mainMenu:
            //TODO
            break;
        case state_optionsMenu:  
            //TODO
            break;
        case state_scoresMenu:
            //TODO
            break;
        case state_rankingMenu:
            //TODO
            break;
        case state_playingGame:
            tickPlayingGame(command,running,game,state);
            //TODO
            break;
        case state_defeatGame:
            //TODO
            break;
        case state_victoryGame:
            //TODO
            break;
        default:
            break;
    }
}

void render(tState state,tGame game, int opc){
    switch(state){
        case state_mainMenu:
            //TODO
            break;
        case state_optionsMenu:  
            //TODO
            break;
        case state_scoresMenu:
            //TODO
            break;
        case state_rankingMenu:
            //TODO
            break;
        case state_playingGame:
            renderPlayingGame(game,state);
            //TODO
            break;
        case state_defeatGame:
            //TODO
            break;
        case state_victoryGame:
            //TODO
            break;
        default:
            break;
    }
}

tCommand getCommand(){
    tCommand command = getchar();
    switch(command){
        case key_UP:
        case key_DOWN:
        case key_LEFT:
        case key_RIGHT:
        case key_E:
        case key_Q:
            return command;
        default:
            return key_INVALID;       
    }
}