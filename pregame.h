#ifndef PREGAME_H
#define PREGAME_H

#include "common.h"

void tickPreGame(tCommand command, bool *running, tGame *game, tState *state);

void renderPreGame(tState state, tGame game);

bool login(tGame *game,tState *state);

#endif