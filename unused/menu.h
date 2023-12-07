#ifndef MENU_H
#define MENU_H

#include "common.h"

void tickMainMenu(tCommand command, bool *running, tGame *game, tState *state);

void renderMainMenu(tState state);

void renderLogo();

void renderOptions();

#endif