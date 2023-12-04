#ifndef GAME_H
#define GAME_H

#include "common.h"

void tickPlayingGame(tCommand command, bool *running, tGame *game, tState *state);

void renderPlayingGame(tState state, tGame game);

void move(tCommand command, tGame *game);

void spawnNewNumbers(tGame *game);

void printByColor(int number);

#endif