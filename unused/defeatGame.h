#ifndef DEFEATGAME_H
#define DEFEATGAME_H

#include "common.h"

void tickDefeatGame(tCommand command, bool *running, tGame *game, tState *state);

void renderDefeatGame(tGame game);

#endif