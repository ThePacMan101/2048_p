#include "common.h"

int initializeFiles();

tUser *convertPlayersToVector(int *number);
void readBinaryFile();

int addNewPlayer(tUser user);
void orderPlayersName(tUser *players, int numberOfPlayers);
void rankPlayers(tUser *players, int numberOfPlayers);
int findPlayer(tUser *players, int numberOfPlayers, char nome[]);
bool saveGame(tGame game);
tGame *loadGame(tUser user);