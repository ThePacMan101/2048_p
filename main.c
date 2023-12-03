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

    //DOPAMINE BOMB
/*
game.board[0][0]=2;
game.board[0][1]=2;
game.board[0][2]=4;
game.board[0][3]=8;
game.board[1][0]=128;
game.board[1][1]=64;
game.board[1][2]=32;
game.board[1][3]=16;
game.board[2][0]=256;
game.board[2][1]=512;
game.board[2][2]=1024;
game.board[2][3]=2048;
game.board[3][0]=32768;
game.board[3][1]=16384;
game.board[3][2]=8192;
game.board[3][3]=4096;
*/

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

