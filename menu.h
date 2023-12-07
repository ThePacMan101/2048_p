#ifndef MENU_H
#define MENU_H

#include "common.h"
#include "files.h"

/*
This header contains all tick and render functions (except the ones related to the running game state). 
Its main use is to define the menus, and to redirect the user according to its input. 
*/

void renderLogo(); //renders the game logo, being used in all menus

/*MAIN MENU HEADER*/

//renders the main menu screen
void renderMainMenu(tState state);

//redirects the user to the desired state shown in the main menu
void tickMainMenu(tCommand command, bool *running, tGame *game, tState *state);

/*DEFEAT GAME HEADER*/

//renders the defeat game screen
void renderDefeatGame(tGame game);

///redirects the user from the defeat game state back to the main menu state
void tickDefeatGame(tCommand command, bool *running, tGame *game, tState *state);  


/*OPTIONS HEADER*/

//redirects the user to the desired state shown in the options menu 
void tickOptions(tCommand command, bool *running, tGame *game, tState *state);

//renders the options screen
void renderOptions();

/*DELETE USER HEADER*/

//renders the delete user screen
void renderDeleteUser();

//gets the name of the user to be deleted
void tickDeleteUser(tCommand command, bool *running, tGame *game, tState *state);

//renders the menu to confirm the deletion of said user
void renderDeleteUser1(tGame game);

//gets the user input to confirm deletion, and shows if the user was found (and deleted) or not. 
//also redirects to main menu
void tickDeleteUser1(tCommand command, bool *running, tGame *game, tState *state);

/*PREGAME HEADER*/

//renderts the menu to choose between playing as a guest or login in
void renderPreGame(tState state, tGame game);


//this function gets the name of the player who wants to login, 
//defines it to lower case, and tries to load an already pre-existed
//user with the loadGame function in files.c
void login(tGame *game);

//checks if the user wants to play the game as a guest or by login in, and starts
//the game. Note that, if the player wants to login, this function calls the login
//function. 
void tickPreGame(tCommand command, bool *running, tGame *game, tState *state);

/*RANKING HEADER*/

//this function shows the 10 top ranking players, from highest to lowest highScores
void renderRanking();

//upon user input, this function returns the player to the main menu state
void tickRanking(tCommand command, bool *running, tGame *game, tState *state);

/*CREDITS HEADER*/

//upon user input, this function returns the player to the main menu state
void tickCredits(tCommand command, bool *running, tGame *game, tState *state);

//this function shows the credits screen on terminal
void renderCredits();

#endif