#include "common.h"

int initializeFiles();
int addNewPlayer(tUser user);

void readBinaryFile();

int saveGame(tGame game, tUser user);
int loadGame(tGame *game);
int binarySearch();
int rankUsers();
int convertVector(tGame *games);



//Função para update no highScore. 