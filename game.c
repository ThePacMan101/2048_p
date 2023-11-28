#include "common.h"
#include "queue.h"
#include "game.h"
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

void renderPlayingGame(tState state,tGame game){
    //provisory, change later
    system("cls");
    printf("user: %s\nscore: %d\n\n",game.user.name,game.score);
    for(int i = 0 ; i < 4 ; i++){
        printf("\t\t");
        for(int j = 0 ; j < 4 ; j ++ ) printf("[%d\t]",game.board[i][j]);
        printf("\n");
    }
}


#define b(i,j) game->board[i][j] 
void move(tCommand command,tGame *game){
        int prev=0;
        int idx=-1;
        tQueue *qp=(tQueue*)malloc(sizeof(tQueue));
        startQueue(qp);
        tKey aux;
        switch (command){
        case key_RIGHT:
            for(int i = 0 ; i < 4 ; i++){
                for(int j = 3 ; j>=0 ; j--)
                    if(b(i,j)){
                        if(prev==b(i,j)){
                            b(i,j)=0;
                            b(i,idx)=2*prev;
                        }else{
                            prev=b(i,j);
                            idx=j;
                        }
                    }
            } 
            for (int i = 0; i < 4; i++){
                for(int j = 3 ; j >= 0 ; j--)
                    if(b(i,j)){
                        aux.number=b(i,j);
                        b(i,j)=0;
                        pushQueue(qp,aux);
                    }
                int k=3;
                while(popQueue(qp,&aux)) b(i,k--)=aux.number;
            }
            break;
        case key_LEFT:
            for(int i = 0 ; i < 4 ; i++){
                for(int j = 0 ; j<4 ; j++)
                    if(b(i,j)){
                        if(prev==b(i,j)){
                            b(i,j)=0;
                            b(i,idx)=2*prev;
                        }else{
                            prev=b(i,j);
                            idx=j;
                        }
                    }
            } 
            for (int i = 0; i < 4; i++){
                for(int j = 0 ; j < 4 ; j++)
                    if(b(i,j)){
                        aux.number=b(i,j);
                        b(i,j)=0;
                        pushQueue(qp,aux);
                    }
                int k=0;
                while(popQueue(qp,&aux)) b(i,k++)=aux.number;
            }
            break;
        case key_UP:
            for(int i = 0 ; i < 4 ; i++){
                for(int j = 0 ; j<4 ; j++)
                    if(b(j,i)){
                        if(prev==b(j,i)){
                            b(j,i)=0;
                            b(idx,i)=2*prev;
                        }else{
                            prev=b(j,i);
                            idx=j;
                        }
                    }
            } 
            for (int i = 0; i < 4; i++){
                for(int j = 0 ; j < 4 ; j++)
                    if(b(j,i)){
                        aux.number=b(j,i);
                        b(j,i)=0;
                        pushQueue(qp,aux);
                    }
                int k=0;
                while(popQueue(qp,&aux)) b(k++,i)=aux.number;
            }
            break;
        case key_DOWN:
            for(int i = 0 ; i < 4 ; i++){
                for(int j = 3 ; j>=0 ; j--)
                    if(b(j,i)){
                        if(prev==b(j,i)){
                            b(j,i)=0;
                            b(idx,i)=2*prev;
                        }else{
                            prev=b(j,i);
                            idx=j;
                        }
                    }
            } 
            for (int i = 0; i < 4; i++){
                for(int j = 3 ; j >= 0 ; j--)
                    if(b(j,i)){
                        aux.number=b(j,i);
                        b(j,i)=0;
                        pushQueue(qp,aux);
                    }
                int k=3;
                while(popQueue(qp,&aux)) b(k--,i)=aux.number;
            }
            break;
        default:
            break;
        }

        free(qp);
}