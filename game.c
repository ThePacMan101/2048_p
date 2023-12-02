#include "common.h"
#include "queue.h"
#include "game.h"
#include <stdio.h>

void printByColor(int number);
void move(tCommand command,tGame *game);
void spawnNewNumbers(tGame* game);
void tickplayingGame(tCommand command, bool *running,tGame *game,tState *state);
void renderPlayingGame(tState state, tGame game);


void tickPlayingGame(tCommand command, bool *running,tGame *game,tState *state){
    switch(command){
        case key_E:
            break;
        case key_Q:
            break;
        case key_DOWN:case key_LEFT: case key_RIGHT: case key_UP: 
            move(command,game);
            spawnNewNumbers(game);
            break;   
        default:
            break;
    }
    
}

#define b(i,j) game->board[i][j] 
void spawnNewNumbers(tGame* game){
    int v[16]={0};
    int k=0;
    for(int i=0;i<4;i++) for(int j=0;j<4;j++)
        if(!b(i,j)) v[4*i+j]=++k;
    if(!k) return;
    
    int random = rand()%k+1;
    for(int i=0;i<16;i++) 
        if(random==v[i]){
            v[i]=0;
            b(i/4,i%4)=(rand()%2 +1)*2;
            break;
        }
}

void renderPlayingGame(tState state, tGame game) {
    system("cls");
    printf("user: %s\nscore: %d\n\n", game.user.name, game.score);
    for (int i = 0; i < 4; i++) {
        printf("\t\t");
        printf("| ");
        for (int j = 0; j < 4; j++) {
            if (game.board[i][j]) {
                printByColor(game.board[i][j]);
            } else {
                printf("     | ");
            }
        }
        printf("\n");
    }
    
    printf("\nPress [Q] to quit.\n");
    printf("Press arrow keys to move.\n");
}

// 4 8 8 2 -> 4 0 16 2 -> 0 4 16 2
// prev = 2 / idx = 3
// 
void move(tCommand command,tGame *game){
        int prev=0;
        int idx=-1;
        tQueue *qp=(tQueue*)malloc(sizeof(tQueue));
        startQueue(qp);
        tKey aux;
        switch (command){
        case key_RIGHT:
            for(int i = 0 ; i < 4 ; i++){
                prev=0;
                idx=-1;
                for(int j = 3 ; j>=0 ; j--)
                    if(b(i,j)){
                        if(prev==b(i,j)){
                            b(i,j)=0;
                            b(i,idx)=2*prev;
                            game->score+=2*prev;
                            prev=0;
                            idx=-1;
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
                prev=0;
                idx=-1;
                for(int j = 0 ; j<4 ; j++)
                    if(b(i,j)){
                        if(prev==b(i,j)){
                            b(i,j)=0;
                            b(i,idx)=2*prev;
                            game->score+=2*prev;
                            prev=0;
                            idx=-1;
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
        case key_UP: // 4 0 0 4
            for(int i = 0 ; i < 4 ; i++){
                prev=0;
                idx=-1;
                for(int j = 0 ; j<4 ; j++)
                    if(b(j,i)){
                        if(prev==b(j,i)){
                            b(j,i)=0;
                            b(idx,i)=2*prev;
                            game->score+=2*prev;
                            prev=0;
                            idx=-1;
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
                prev=0;
                idx=-1;
                for(int j = 3 ; j>=0 ; j--)
                    if(b(j,i)){
                        if(prev==b(j,i)){
                            b(j,i)=0;
                            b(idx,i)=2*prev;
                            game->score+=2*prev;
                            prev=0;
                            idx=-1;
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

void printByColor(int number) {
    int exponent = 0;
    while (number > 1) {
        number /= 2;
        exponent++;
    }
    int red = 255 - (exponent * 255) / 11;  // Calculate red component
    int green = (exponent * 255) / 11;      // Calculate blue component
    printf("\033[38;2;%d;0;%dm%-4d\033[0m", red, green, 1 << exponent);
    printf(" | ");
    return;
}
