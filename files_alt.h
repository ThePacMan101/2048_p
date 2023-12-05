#ifndef FILESALT_H
#define FILESALT_H

#include "common.h"

void initFiles();

tUser* UserListToArray(int*tam);

void saveUserList(tUser user);

void saveUser(tUser user);

void loadUser(tUser *user);

#endif