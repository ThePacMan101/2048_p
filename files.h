#ifndef FILES_H
#define FILES_H

#include "common.h"

void initFiles();

tUser *userListToArray(int *size);

void saveUserList(tUser user);

void saveUser(tUser user);

void loadUser(tUser *user);

void sortUsersByName(tUser *array, int size);

tUser *sortUsersByHighScore(int *size);

tUser *sortUsers(int *size, int key);

int binSearchName(tUser *array, int size, char nameToBeFound[]);

bool deleteUser(char *name);

#endif