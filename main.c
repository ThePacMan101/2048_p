#include "common.h"
#include "files.h"

#define DOPAMINEBOMB 0
void dopamineBomb(tGame *game,bool active);

int main() {
    srand(time(0));
    // SetConsoleTitle("2048");
    bool running = true;
    tCommand key;
    tGame game;
    game.user.highScore = 0;
    tState state = state_mainMenu;

    dopamineBomb(&game,DOPAMINEBOMB);

    initFiles();

    tUser *array;
    int d;
    array = sortUsers_highScore(&d); 
    
        
    printf("\nSorted:\n");
    for(int i = 0; i < d; i++) {
        printf("\n\n%s %d\n\n", (*(array + i)).name, (*(array+i)).highScore);
    }
    
    
    getchar();
    

    // int d;
    // d = binSearchName("lucas");
    // printf("\n\n%d\n\n", &d);

    // getchar();


    while (running) {
        render(state, game);                 // show current state graphics
        key = getCommand(state);             // get user command
        tick(key, &running, &game, &state);  // do stuff, update variables
    }

    return 0;
}

void dopamineBomb(tGame *game,bool active){
    if(!active) return;
    game->board[0][0] = 2;
    game->board[0][1] = 2;
    game->board[0][2] = 4;
    game->board[0][3] = 8;
    game->board[1][0] = 128;
    game->board[1][1] = 64;
    game->board[1][2] = 32;
    game->board[1][3] = 16;
    game->board[2][0] = 256;
    game->board[2][1] = 512;
    game->board[2][2] = 1024;
    game->board[2][3] = 2048;
    game->board[3][0] = 32768;
    game->board[3][1] = 16384;
    game->board[3][2] = 8192;
    game->board[3][3] = 4096;
}
