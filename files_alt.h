#ifndef FILESALT_H
#define FILESALT_H

#include "common.h"

tUser* UserListToArray(int*tam);

void saveUserList(tUser user);

void saveUser(tUser user);

void loadUser(tUser *user);

#endif