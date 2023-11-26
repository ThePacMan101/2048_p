#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "common.h"

typedef struct tElement{
    int key;
    tElement *next;
} tElement;

typedef struct
{
    tElement* start;
    tElement* end;
} tQueue;

void startQueue(tQueue *f);
int sizeQueue(tQueue *f);
void showQueue(tQueue *f);
bool pushQueue(tQueue *f, int key);
bool popQueue(tQueue *f, int *key);
void restartQueue(tQueue *f);