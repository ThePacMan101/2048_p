#ifndef FILES_H
#define FILES_H

#include "common.h"

void initFiles();

tUser* UserListToArray(int*size);

void saveUserList(tUser user);

void saveUser(tUser user);

void loadUser(tUser *user);

// void sortUsers_highScore(tUser* array,int size);

void sortUsers_name(tUser* array,int size);

tUser *sortUsers_highScore(int *size);



tUser *sortUsers(int *size, int key);

int binSearchName(char nameToBeFound[]);


#endif