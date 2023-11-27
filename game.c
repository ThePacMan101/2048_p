#pragma once
#include "common.h"
#include "queue.h"
#include <stdio.h>

void tickPlayingGame(tCommand command, bool *running,tGame *game,tState *state){
    switch(command){
        case key_E:
            break;
        case key_Q:
            break; 
        default:
            move(command,game);   
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

#define MAX(a,b) (a>b)?a:b

void move(tCommand command,tGame *game){
        tQueue q,*qp=&q;
        startQueue(qp);
        tKey aux,prev;
        int availableIdx;
        switch (command){
        case key_RIGHT:
            for(int i = 0 ; i < 4 ; i++){
                for(int j = 3 ; j>=0 ; j--){
                    if(game->board[i][j]){
                        aux.idx=j;
                        aux.number=game->board[i][j];
                        pushQueue(qp,aux);
                    }
                }
                popQueue(qp,&aux);

                popQueue(qp,&prev);
                popQueue(qp,&aux);
                if(aux.number==prev.number) game->board[i][prev.idx]=aux.number+prev.number;
            }
            
            break;
        default:
            break;
        }
        free(qp);
}