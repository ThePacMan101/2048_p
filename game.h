#ifndef GAME_H
#define GAME_H

void tickPlayingGame(tCommand command, bool *running,tGame *game,tState *state);

void renderPlayingGame(tState state,tGame game);

void move(tCommand command,tGame *game);

void spawnNewNumbers(tGame* game);

#endif