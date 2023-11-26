#pragma once
#include "common.h"
#include "queue.h"
#include <stdio.h>

void tickPlayingGame(tCommand command, bool *running,tGame *game,tState *state){
    switch(command){
        case key_UP:

            break;
        case key_DOWN:
        case key_LEFT:
        case key_RIGHT:
        case key_E:
        case key_Q:      
    }
}

void renderPlayingGame(tGame game,tState state){
    //provisory, change later
    printf("user: %s\nscore: %d\n\n",game.user,game.score);
    for(int i = 0 ; i < 4 ; i++){
        printf("\t\t");
        for(int j = 0 ; j < 4 ; j ++ ) printf("[%d\t]",game.board[i][j]);
        printf("\n");
    }
}