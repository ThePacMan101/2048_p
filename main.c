#include "common.h"

int main(){

    //Global variables declaration
    bool running=true;
    int key;
    tGame game;

    for(int i = 0 ; i < 4 ; i ++) for(int j = 0 ; j < 4 ; j++) game.board[i][j]=0;
    game.score=0;
    sprintf(game.user.name,"no-user");
    game.board[0][1]=2;
    game.board[0][2]=2;

    tState state=state_playingGame;//provisory, later change to state_mainMenu
    int opc=0;
    //Game loop
    while(running){
        render(state,game,opc);                 //show current state graphics
        key = getCommand();                 //get user command
        tick(key,&running,&game,&state);    //do stuff, update variables
    }

    return 0;   
}


/*
Main menu screen:

        //stylized big 2038


            > play
              select user
              scores
              options
              exit

controls ">" with wasd or arrow keys, selects with E

*/