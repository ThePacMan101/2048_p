#ifndef QUEUE_H
#define QUEUE_H

#include "common.h"

/*
This header has all definitions of a queue, as shown in class
*/

typedef struct key {
    int number;
    // int idx;
} tKey;

typedef struct tElement {
    tKey key;
    struct tElement *next;
} tElement;

typedef struct
{
    tElement *start;
    tElement *end;
} tQueue;

void startQueue(tQueue *f);
int sizeQueue(tQueue *f);
void showQueue(tQueue *f);
bool pushQueue(tQueue *f, tKey key);
bool popQueue(tQueue *f, tKey *key);
void restartQueue(tQueue *f);

#endif