#include "common.h"

int main(){

    //Global variables declaration
    bool running=true;
    int key;
    tGame game;
    tState state=state_playingGame;//provisory, later change to state_mainMenu
    int opc=0;


    //later turn this into a function to initialize game
    for(int i = 0 ; i < 4 ; i ++) for(int j = 0 ; j < 4 ; j++) game.board[i][j]=0;
    game.score=0;
    sprintf(game.user.name,"no-user");
    srand(time(NULL));
    game.board[rand()%4][rand()%4]=(rand()%2 +1)*2;
    game.board[rand()%4][rand()%4]=(rand()%2 +1)*2;


    //Game loop
    while(running){
        render(state,game,opc);             //show current state graphics
        key = getCommand();                 //get user command
        tick(key,&running,&game,&state);    //do stuff, update variables
    }

    return 0;   
}


/*
Main menu screen:

        //stylized big 2048


            > play
              select user
              scores
              options
              exit

controls ">" with wasd or arrow keys, selects with E, exits with Q

*/