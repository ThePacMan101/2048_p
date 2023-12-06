#ifndef MYCONIO_H
#define MYCONIO_H

#include <termios.h>
#include <unistd.h>
#include <stdio.h>

// reads from keypress, doesn't echo
int getch(void);

// credits: https://stackoverflow.com/questions/3276546/how-to-implement-getch-function-of-c-in-linux


#endif