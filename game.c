#pragma once
#include "common.h"
#include <stdio.h>

void tickPlayingGame(tCommand command, bool *running,tGame *game,tState *state){
    
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