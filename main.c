#include <stdio.h>
#include <stdlib.h>
#include "common.h"

int main(){
    //Global variables declaration
    bool running=true;
    int key;
    tGame game;
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