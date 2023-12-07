#ifndef OPTIONS_H
#define OPTIONS_H

#include "common.h"
#include "files.h"


void tickOptions(tCommand command, bool *running, tGame *game, tState *state);

void renderOptionsOptions();

void tickDeleteUser(tCommand command, bool *running, tGame *game, tState *state);

void tickDeleteUser1(tCommand command, bool *running, tGame *game, tState *state);

void renderDeleteUser();

void renderDeleteUser1(tGame game);


#endif