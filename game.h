#ifndef GAME_H
#define GAME_H

#include "common.h"

/*
All functions in this header refer to the game itself, 
the gameplay, checking for a game over, spawning new numbers, etc.
*/

/*
Tick specific for the game.
*/
void tickPlayingGame(tCommand command, bool *running, tGame *game, tState *state);

/*
Render specific for the game.
*/
void renderPlayingGame(tState state, tGame game);

/*
This function moves the board according to user input
*/
void move(tCommand command, tGame *game);

/*
This function spawns new numbers after each movement, if possible
*/
void spawnNewNumbers(tGame *game);

/*
This function starts the game itself, calling the empty game board function, 
and spawning 2 new numbers
*/
void startGame(tGame *game);

/*
This function checks if the game is over (there are no possible movements) 
by making a copy of the board, and moving it in all 4 directions. If the board
stays the same after all movements, then there is no more movements possible. 
*/
void checkForGameOver(tGame *game, tState *state);

/*
This function defines the gradient of the number to be shown in the game board. 
*/
void printByColor(int number);

/*
This functions prints the entire board, and calls the printByColor function 
to print the numbers on the board. 
*/
void printBoard(tGame game);


#endif