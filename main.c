#include "common.h"
#include "game.h"
int main(){
    //Global variables declaration
    bool running=true;
    tCommand key;
    tGame game;
    tState state=state_playingGame;//provisory, later change to state_mainMenu
    int opc=0;


    //later turn this into a function to initialize game
    for(int i = 0 ; i < 4 ; i ++) for(int j = 0 ; j < 4 ; j++) game.board[i][j]=0;
    game.score=0;
    sprintf(game.user.name,"no-user");
    

    spawnNewNumbers(&game);
    spawnNewNumbers(&game);
    
    //Game loop
    while(running){
        render(state,game,opc);             //show current state graphics
        key = getCommand();                 //get user command
        tick(key,&running,&game,&state);    //do stuff, update variables
        if(key==key_Q) running=false;
    }

    return 0;   
}
/*
opc = 0


arr{
0[191]
1[192]
2[193]
3[194]}

switch case(arr[opc])
case 191:
case 192:
...

*/



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