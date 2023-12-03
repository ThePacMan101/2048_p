#include "common.h"
#include "game.h"
#include "files.h"

int main(){
    //Global variables declaration
    bool running=true;
    tCommand key;
    tGame game;
    tState state=state_playingGame;//provisory, later change to state_mainMenu
    int opc=0;

    //Initializes files
    // if(initializeFiles() == - 1) {
    //     return -1;
    // }

    tUser *players = NULL;

    // printf("Input user name: ");
    // scanf("%s", game.user.name);

    FILE *f;
    f = fopen("playerFile.dat", "wb");
    int count = 0;
    fwrite(&count, sizeof(int), 1, f);
    fclose(f);

    sprintf(game.user.name, "Paulo");
    game.user.highScore = 200;
    addNewPlayer(game.user);
    sprintf(game.user.name, "AnaLu");
    game.user.highScore = 76;
    addNewPlayer(game.user);
    sprintf(game.user.name, "Batat");
    game.user.highScore = 110;
    addNewPlayer(game.user);
    sprintf(game.user.name, "Vitor");
    game.user.highScore = 80;
    addNewPlayer(game.user);    
    sprintf(game.user.name, "Rober");
    game.user.highScore = 100;
    addNewPlayer(game.user);
    sprintf(game.user.name, "FuckM");
    game.user.highScore = 32;
    addNewPlayer(game.user);    
    sprintf(game.user.name, "HugoN");
    game.user.highScore = 34;
    addNewPlayer(game.user);
    sprintf(game.user.name, "Colie");
    game.user.highScore = 0;
    addNewPlayer(game.user);

    rankPlayers(players, 0);

    getchar();

    //later turn this into a function to initialize game
    for(int i = 0 ; i < 4 ; i ++) for(int j = 0 ; j < 4 ; j++) game.board[i][j]=0;
    game.score=0;
    
    spawnNewNumbers(&game);
    spawnNewNumbers(&game);

    // saveGame(game);

    // loadGame(&game);

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

