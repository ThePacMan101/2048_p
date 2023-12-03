#include "common.h"

int initializeFiles();
int addNewPlayer(tUser user);
void orderPlayersName(tUser *players, int numberOfPlayers);
void readBinaryFile();

tUser *convertPlayersToVector(int *number);

void rankPlayers();

int findPlayer(tUser user);
int saveGame(tGame game, tUser user);
int loadGame(tGame *game);
int binarySearch(tUser user);
// int rankUsers();
int convertVector(tGame *games);



//Função para update no highScore. 