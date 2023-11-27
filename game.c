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

#define MAX(a,b) (a>b)?a:b


// Tried working with Queues... didn't work
/*void move(tCommand command,tGame *game){
        tQueue q,*qp=&q;
        startQueue(qp);
        tKey aux;
        switch (command){
        case key_RIGHT:
            for(int i = 0 ; i < 4 ; i++){
                for(int j = 3 ; j>=0 ; j--){
                    if(game->board[i][j]){
                        if(popQueue(qp,&aux)){
                            if(aux.number==game->board[i][j]){
                                game->board[i][aux.idx]=2*game->board[i][j];
                                game->board[i][j]=0;
                            }
                        }else{
                            aux.idx=j;
                            aux.number=game->board[i][j];
                            pushQueue(qp,aux);
                            game->board[i][j]=0;
                        }
                    }
                }
                
                //if(!popQueue(qp,&aux1)) continue;
                //if(!popQueue(qp,&aux2)){    //just a single non-zero value
                //    game->board[i][3]=aux1.number;
                //    continue;
                //}if(!popQueue(qp,&aux3)){   //only two non-zero values
                //    if(aux1.number==aux2.number) game->board[i][aux1.idx]=2*aux1.number;
                //}
                
            }
            
            break;
        default:
            break;
        }
        free(qp);
}*/

#define b(i,j) game->board[i][j] 
void move(tCommand command,tGame *game){
        int prev=0;
        int idx=-1;
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
            //Now, move everyone to the right until all the zeros are to the left of the non-zero numbers
            //TODO
            
            break;
        default:
            break;
        }
}