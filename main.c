#include "common.h"
#include "files.h"

void dopamineBomb(tGame *game,bool active);

int main() {

    /*DEFINITION OF GLOBAL VARIABLES*/

    srand(time(0));
    bool running = true; // The game is running
    tState state = state_mainMenu; // The initial state is the main menu
    tCommand key; // Variable to hold user input
    tGame game; // Variable representing the game itself
    game.user.highScore = 0;

    initFiles(); //Initializes files, creating the necessary "player.dat" binary file, if none exists

    /*GAME LOOP: the game functions in this loop until exited from main menu, when 'running' becomes false*/
    while (running) {
        render(state, game);                 // show current state graphics

        if(state != state_deleteUser) key = getCommand(state);             // get user command

        tick(key, &running, &game, &state);  // do stuff, update variables
    }

    return 0;
}