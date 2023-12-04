#ifndef COMMON_H
#define COMMON_H

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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
// [...]
// Each state defines a screen that a user may interact with

typedef char tCommand;
#define key_UP 'w'
#define key_DOWN 's'
#define key_LEFT 'a'
#define key_RIGHT 'd'
#define key_E 'e'
#define key_Q 'q'
#define key_LEAVE '0'
#define key_INVALID '\0'

typedef struct {
    int id;
    char name[20];
    int highScore;
    bool hasSave;
    //[...] TODO
} tUser;

typedef struct {
    int board[4][4];
    tUser user;
    int score;
} tGame;

/*
The tick function calls other functions depending on the current state
it also updates all global variables based on user's last input key
*/

void tick(tCommand command, bool *running, tGame *game, tState *state);

/*
The render function calls other functions to show the screen based on the
current state and the game variable
*/
void render(tState state, tGame game, int opc);

tCommand getCommand();

/*
The renderLogo function shows the game logo art on the screen
*/
void renderLogo();

#endif