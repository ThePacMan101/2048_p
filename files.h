#ifndef FILES_H
#define FILES_H

#include "common.h"

/*
The initFiles function opens every file that will be further used in the program.
If they don't exist yet, the function creates them.
*/
void initFiles();

/*
The userListToArray function takes all the players from the players.dat file
and translates them into a vector, then returns the pointer to the said vector.
Besides that, it also deposits the size of the vector into a variable wich pointer
is passed as an argument.
*/
tUser *userListToArray(int *size);


/*
The saveUserList function reveives a user and adds their name to the
players.dat file.
*/
void saveUserList(tUser user);

/*
The saveUser function, similarly saves a user's information in a file. Except,
this time, in a unique file for that specific player.
*/
void saveUser(tUser user);

/*
The loadUser function receives a pointer to a tUser variable, than
reads its name and tries to load all user data into the variable, if the file for that user
exists. If not, then, the function creates a user by calling saveUserList and saveUser.
*/
void loadUser(tUser *user);

/*
The function sortUsersByName receives an array of tUser variables and its size.
Then, it uses the bubble sort method to sort the array based on the function strcmp.
*/
void sortUsersByName(tUser *array, int size);

/*
The sortUsersByHighScore function receives a pointer to the size variable, then
creates an array of tUser variables pulled from the players file and uses the bubble sort
method to sort the array using the players' high score as criteria.
*/
tUser *sortUsersByHighScore(int *size);

/*
The binSearchName receives a sorted array of tUser variables, the size of
this array and a string, the name of the player to be found. Then, it, using the binary search method, 
returns the player's position in the array. If there is no player with such name in the array,
it returns -1 (invalid position).
*/
int binSearchName(tUser *array, int size, char nameToBeFound[]);

/*
The deleteUser function takes a player's name, then deletes the register
of this player out of the players file and deletes the unique file for the player.
It uses the binSearchName to find the player in the file based on their name.
*/
bool deleteUser(char *name);

#endif