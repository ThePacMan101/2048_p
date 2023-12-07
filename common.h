#ifndef COMMON_H
#define COMMON_H

#include <conio.h> // Comment this line if on Linux and uncomment the following one
//#include "my_conio.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
//#include <windows.h>

#define bool int
#define true 1
#define false 0

// game-states definition:
typedef int tState;
#define state_mainMenu 0
#define state_optionsMenu 1
#define state_scoresMenu 2
#define state_rankingMenu 3
#define state_playingGame 4
#define state_defeatGame 5
#define state_victoryGame 6
#define state_preGame 7
#define state_creditsMenu 8
#define state_deleteUser 9
#define state_deleteUser1 10
// Each state defines a screen that a user may interact with

// key definitions: 
typedef char tCommand;
#define key_UP 'w'
#define key_DOWN 's'
#define key_LEFT 'a'
#define key_RIGHT 'd'
#define key_E 'e' //I think we can take this out
#define key_Q 'q' //I think we can take this out
#define key_LEAVE '0'
#define key_INVALID '\0'
// Each key is used to identify a specific user input

// Definition of a user: 
typedef struct {
    int id; //A user has an ID (0 if it is a user, or -1 if it is a guest)
    char name[20]; //A user has a name
    int highScore; //A user has a high score
} tUser;

// Definition of a game: 
typedef struct {
    int board[4][4]; 
    tUser user; //An associated user
    int score;
} tGame;

/*
The tick function calls other functions depending on the current state of the program.
It also updates all global variables (3 last parameters) based on user's last input key
*/
void tick(tCommand command, bool *running, tGame *game, tState *state);

/*
The render function calls other functions to show the screen based on the
current state of the program and the game variables at the moment. 
*/
void render(tState state, tGame game);


/*
getCommand reads an input coming from the user's keyboard and loads the next game state. If the command is invalid, it reads again 
until the key pressed is a valid one.
*/
tCommand getCommand(tState state);

/*
The renderLogo function shows the game logo art on the top of the screen
*/
void renderLogo();

/*
The empty game board empties the game board, making all elements 
in the board matrix equal to 0. 
*/
void emptyGameBoard(tGame *game);

#endif