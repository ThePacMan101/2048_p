#ifndef FILES_H
#define FILES_H

#include "common.h"
void readBinaryFile();

/*
int initializeFiles();
tUser *convertPlayersToVector(int *number);
int addNewPlayer(tUser user);
void orderPlayersName(tUser *players, int numberOfPlayers);
void rankPlayers(tUser *players, int numberOfPlayers);
int findPlayer(tUser *players, int numberOfPlayers, char nome[]);
bool saveGame(tGame game);
tGame *loadGame(tUser user);
bool resetGame(tUser user);
*/

bool initializeFiles();

bool updateNumberOfPlayers(int *numberOfPlayers);
bool updateNumberOfGames(int *numberOfGames);

bool writeNewPlayer(tUser *player);
bool writeNewGame(tGame *game);

int readNumberOfPlayers();
int readNumberOfGames();

bool saveGame(tGame *game);
bool loadGame(tGame *game, int userID);

tUser *convertPlayersToVector();

void sortPlayersByName();
void rankPlayersByScore();

int searchPlayerByName(tUser *vector, char name[]);

#endif