#ifndef COMMON_H
#define COMMON_H

#include <conio.h>              // Comment this line if on Linux and uncomment the following one
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

// Game-states definition:
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
// [...]
// Each state defines a screen that a user may interact with

// Associations between each key yhe user may press with a character:
typedef char tCommand;
#define key_UP 'w'
#define key_DOWN 's'
#define key_LEFT 'a'
#define key_RIGHT 'd'
#define key_E 'e'
#define key_Q 'q'
#define key_LEAVE '0'
#define key_INVALID '\0'

// Struct used to describe the players
typedef struct {
    int id;         // Can later be used to save and load unfinished games
    char name[20];
    int highScore;
    //[...] TODO
} tUser;

// Struct used to describe the games
typedef struct {
    int board[4][4];
    tUser user;
    int score;
} tGame;

/*
The tick function calls other functions depending on the current state of the program.
It also updates all global variables (3 last parameters) based on user's last input key.
*/
void tick(tCommand command, bool *running, tGame *game, tState *state);

/*
The render function calls other functions to show the screen based on the
current state of the program and the game variables at the moment.
*/
void render(tState state, tGame game);

/* 
getCommand reads an input coming from the user's keyboard and loads the next game state.
If the command is invalid, it reads again until the key pressed is a valid one.
*/ 
tCommand getCommand(tState state);

/*
The renderLogo function shows the game logo art on the top of the screen.
*/
void renderLogo();

/*
The emptyGameBoard function simply turns all of the elements of the board matrix to 0.
*/
void emptyGameBoard(tGame *game);

#endif