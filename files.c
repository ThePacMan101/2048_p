#include "files.h"
#include <stdio.h>
#include "common.h"



/*
This initializeFiles function initalizes both the playerFile.dat and
the gameFile.dat files, and also checks for any problems with said files.
*/
void readBinaryFile() {
    FILE *f;
    FILE *fa;
    tUser user;
    int count;

    f = fopen("assets/playerFile.dat", "rb+");
    fa = fopen("assets/playerFile.txt", "w+");

    fread(&count, sizeof(int), 1, f);
    fprintf(fa, "%d\n", count);

    for (int i = 0; i < count; i++) {
        fread(&user, sizeof(tUser), 1, f);
        fprintf(fa, "Name: %s \t ID: %d\n", user.name, user.id);
    }

    fclose(f);
    fclose(fa);
}


/*
The function convertPlayersToVector reads all Players from the Players file
and converts them into a vector of type tUser, then sets the variable numbers
to the number of Players read and returns the pointer to the vector
*/


/*
This addNewPlayer function adds a new player into the playerFile.
It saves the Players name, ID and highScore (initially 0) in game.
The ID generated for said player is just the Players position in
the file. The number of Players is kept at the top of said file.
*/

/*
This rankPlayers function orders a vector of type tUser, using
the convertPlayersToVector function, and them implements a bubble sort
algorithm to order the users by their highScores. Then, we print in
the terminal the sorted vector.
*/

/*
This orderPlayersName function orders a vector of type tUser
in alphabetical order, using the strcmp function and a
bubble sort algorithm.
*/

/*
This findPlayer function gets the alphabetically ordered vector with all Players in playerFile.dat
(using convertPlayersToVector and orderPlayersName), and implements a binary search to find the
player that has the same name passed in the argument. The function returns the vector's index
of said user, or -1 if no user with that name was found.
*/

/*
The function saveGame takes the current state of the board,
the score and the user associated to the game, and saves it to
the games file
*/

/*
This loadGame function takes the current user as an argument, and
implements a "linear search algorithm", trying to find the last 
saved game of said user, and returning it at a success (or NULL at a 
failure).
*/

/*
The resetGame function recevies a user, then seraches for
a game in the games file registered with the give user and 
writes an empty game with score 0 over the previously registered
game. If the user doesn't any saved game, the function does 
nothing with the files and shows an error message.
*/

// initializeFiles tries to open the Players file and the games file and checks if
// they already exist. If not, it creates the files and sets the header numbers to 0.
// If the operation is successfull, returns true. Otherwise, returns false.
bool initializeFiles() {
    //Opens Players file
    FILE *playerFile;
    playerFile = fopen("assets/playerFile.dat", "r+b");
    if (playerFile == NULL) { //The file does not exist yet
        printf("It seems like \"assets/playerFile.dat\" is missing.\nCreatting new file...\n");
        playerFile = fopen("assets/playerFile.dat", "w+b");

        //Writes an integer at the beginning of the file
        int numberOfPlayers = 0;
        rewind(playerFile);
        fwrite(&numberOfPlayers, sizeof(int), 1, playerFile);
        
    }
    fclose(playerFile);
    

    //Opens game saves file
    FILE *gameFile;
    gameFile = fopen("assets/gameFile.dat", "r+b");
    if (gameFile == NULL) { //The file does not exist yet
        printf("It seems like \"assets/gameFile.dat\" is missing.\nCreatting new file...\n");
        gameFile = fopen("assets/gameFile.dat", "w+b");

        //Writes an integer at the beginning of the file
        int numberOfGames = 0;
        rewind(gameFile);
        fwrite(&numberOfGames, sizeof(int), 1, gameFile);
    }
    
    //Closes files
    fclose(gameFile);

    //Success
    return true;
}

// updateNumberOfPlayers updates the number at the top of the Players
// file to a certain integer. If the operation was successfull, 
// returns true. Otherwise, returns false.
bool updateNumberOfPlayers(int *numberOfPlayers) {

    //Opens Players file
    FILE *playerFile;
    playerFile = fopen("assets/playerFile.dat", "r+b");
    if (playerFile == NULL) return false; 

    //Updates the number of Players at the top of the file
    rewind(playerFile);
    if (!fwrite(numberOfPlayers, sizeof(int), 1, playerFile)) {
        fclose(playerFile);
        return false;
    }
    //Closes the file
    fclose(playerFile);

    //Success
    return true;
}

// updateNumberOfGames updates the number at the top of the games
// file to a certain integer. If the operation was successfull, 
// returns true. Otherwise, returns false.
bool updateNumberOfGames(int *numberOfGames) {

    //Opens games file
    FILE *gameFile;
    gameFile = fopen("assets/gameFile.dat", "r+b");
    if (gameFile == NULL) return false; 

    //Updates the number of Players at the top of the file
    rewind(gameFile);
    if (!fwrite(numberOfGames, sizeof(int), 1, gameFile)) {
        fclose(gameFile);
        return false;
    }

    //Closes the file
    fclose(gameFile);

    //Success
    return true;
}

// writeNewPlayer writes a new player at the end of
// in the Players file. If the operation was successfull,
// returns true. Otherwise returns false.
bool writeNewPlayer(tUser *player) {

    //Opens Players file
    FILE *playerFile;
    playerFile = fopen("assets/playerFile.dat", "a+b");
    if (playerFile == NULL) return false; 

    //Reads the number of Players
    int numberOfPlayers;
    rewind(playerFile);
    fread(&numberOfPlayers, sizeof(int), 1, playerFile);
    
    //Positions file cursor at the end of the file and writes new player
    fseek(playerFile, 0, SEEK_END);
    if (!fwrite(player, sizeof(tUser), 1, playerFile)) {
        fclose(playerFile);
        return false;
    }

    //Closes file
    fclose(playerFile);

    //Increases the number of Players
    numberOfPlayers++;
    updateNumberOfPlayers(&numberOfPlayers);

    //Success
    return true;
}

// writeNewGame writes a new player at the end of
// in the games file. If the operation was successfull,
// returns true. Otherwise returns false.
bool writeNewGame(tGame *game) {

    //Opens games file
    FILE *gameFile;
    gameFile = fopen("assets/gameFile.dat", "a+b");
    if (gameFile == NULL) return false; 

    //Reads the number of games
    int numberOfGames;
    rewind(gameFile);
    fread(&numberOfGames, sizeof(tGame), 1, gameFile);

    //Positions file cursor at the end of the file and writes new game
    fseek(gameFile, 0, SEEK_END);
    if (!fwrite(game, sizeof(tGame), 1, gameFile)) {
        fclose(gameFile);
        return false;
    }

    //Closes file
    fclose(gameFile);

    //Increases the number of games
    numberOfGames++;
    updateNumberOfGames(&numberOfGames);

    //Success
    return true;
}

// readNumberOfPlayers reads the number at the top of the Players file
// and returns it. In case of an error, it returns -1.
int readNumberOfPlayers() {
    //Opens Players file
    FILE *playerFile;
    playerFile = fopen("assets/playerFile.dat", "rb");
    
    if (playerFile == NULL) return -1;

    //Reads the number
    int numberOfPlayers;
    rewind(playerFile);
    fread(&numberOfPlayers, sizeof(int), 1, playerFile);
    //Returns the number
    return numberOfPlayers;
}

// readNumberOfGames reads the number at the top of the games file
// and returns it. In case of an error, it returns -1.
int readNumberOfGames() {

    //Opens games file
    FILE *gameFile;
    gameFile = fopen("assets/gameFile.dat", "rb");
    if (gameFile == NULL) return -1;

    //Reads the number
    int numberOfGames;
    rewind(gameFile);
    fread(&numberOfGames, sizeof(int), 1, gameFile);
    printf("%d",numberOfGames);
    getchar();
    getchar();

    //Returns the number
    return numberOfGames;
}

// saveGame saves a game into the games file, either
// adding it to the end using writeNewGame or over writting
// a previously saved game in the name of the game's user
bool saveGame(tGame *game) {

    //Reads the number of games
    int numberOfGames = readNumberOfGames();
    if (numberOfGames == -1) return false;

    //Opens games file
    FILE *gameFile;
    gameFile = fopen("assets/gameFile.dat", "r+b");
    if (gameFile == NULL) return false;

    //Skips the integer at the beginning of the file
    fseek(gameFile, sizeof(int), SEEK_SET);

    //Iterates through the saved games searching for the user
    tGame comparisonGame;
    for (int i = 0; i < numberOfGames; i++) {
        fread(&comparisonGame, sizeof(tGame), 1, gameFile);
        if (game->user.id == comparisonGame.user.id) {
            fseek(gameFile, (-1) * sizeof(tGame), SEEK_CUR);
            if (!fwrite(game, sizeof(tGame), 1, gameFile)) {
                fclose(gameFile);
                return false;
            }
            fclose(gameFile);
            return true;
        }
    }

    //If no game was found, that is the first time a game is being saved for this user
    fclose(gameFile);

    //Writes new game and updates number of games
    writeNewGame(game);
    numberOfGames++;
    updateNumberOfGames(&numberOfGames);
}

// loadGame searches for any saved game in the games file with the given
// user ID, then loads it into the game variable whose pointer was given in 
// the entry of the function. If the operation is successfull, returns true.
// If an error occurres, or if there is no game saved with the give ID, returns
// false.
bool loadGame(tGame *game, int wantedID) {
    
    //Reads the number of games
    int numberOfGames = readNumberOfGames();
    if (numberOfGames == -1) return false;

    //Opens games file
    FILE *gameFile;
    gameFile = fopen("assets/gameFile.dat", "rb");
    if (gameFile == NULL) return false;

    //Skips the integer at the top of the file
    fseek(gameFile, sizeof(int), SEEK_SET);

    //Iterates through the saved games, searching for the ID
    tGame comparisonGame;
    for (int i = 0; i < numberOfGames; i++) {
        fread(&comparisonGame, sizeof(tGame), 1, gameFile);
        if (comparisonGame.user.id == wantedID) {
            *game = comparisonGame;
            fclose(gameFile);
            return true;
        }
    }

    //If no game was found, there is no game saved with this user ID
    fclose(gameFile);
    return false;
}

// convertPlayersToVector reads the Players file and puts each one of the Players
// registered there into a vector of size numberOfPlayers, then returns the pointer
// to the created vector. Returns NULL if an error occurres.
tUser *convertPlayersToVector() {
    
    //Reads the number of Players
    int numberOfPlayers = readNumberOfPlayers();
    if (numberOfPlayers == -1) return NULL;
    //Opens Players file
    FILE *playerFile;
    playerFile = fopen("assets/playerFile.dat", "a+b");
    if (playerFile == NULL) return NULL;

    //Skips the integer at the top
    fseek(playerFile, sizeof(int), SEEK_SET);
    
    //Allocates memory for the vector
    tUser *vector = (tUser *) malloc(sizeof(tUser) * numberOfPlayers);

    //Puts each player in the Players file into the vector
    tUser currentUser;
    for (int i = 0; i < numberOfPlayers; i++) {
        fread(&currentUser, sizeof(tUser), 1, playerFile);
        *(vector + i) = currentUser;
    }

    //Closes the file
    fclose(playerFile);

    //Returns pointer to the first element of the vector
    return vector;
}

// sortPlayersByName uses the bubble sort method to sort a
// vector of Players in alphabetical order using the function strcmp().
void sortPlayersByName() {

    //Reads the size of the vector
    int numberOfPlayers = readNumberOfPlayers();

    //Allocates the vector and converts the Players
    tUser *vector = convertPlayersToVector();

    //Uses the bubble sort method on the vector
    for (int end = numberOfPlayers - 1; end > 0; end--) {
        for (int i = 0; i < end; i++) {
            if (strcmp(vector[i].name, vector[i + 1].name) > 0) {
                tUser aux = vector[i];
                vector[i] = vector[i + 1];
                vector[i + 1] = aux;
            }
        }
    }   
}

// sortPlayersByScore uses the bubble sort method to sort a
// vector of Players from the highest to the lowest hogh score.
void rankPlayersByScore() {

    //Reads the size of the vector
    int numberOfPlayers = readNumberOfPlayers();

    //Allocates the vector and converts the Players
    tUser *vector = convertPlayersToVector();

    //Uses the bubble sort method on the vector
    for (int end = numberOfPlayers - 1; end > 0; end--) {
        for (int i = 0; i < end; i++) {
            if (vector[i].highScore < vector[i + 1].highScore) {
                tUser aux = vector[i];
                vector[i] = vector[i + 1];
                vector[i + 1] = aux;
            }
        }
    }   
}

// searchPlayerByName searches for a player in an alphabetically ordered
// vector with a certain name using the binary search method. 
// Then, if the element exists, returns the player's ID. 
// If there is no player with such name, returns -1.
int searchPlayerByName(tUser *vector, char name[]) {
    if(vector == NULL) return -1;
    //Reads the size of the vector
    int numberOfPlayers = readNumberOfPlayers();
    if (numberOfPlayers == -1) return -1;

    //Uses the binary search method
    int left, right, mid;
    left = 0;
    right = numberOfPlayers - 1;
    while(left <= right) {
        mid = (left + right) / 2;
        if (strcmp(vector[mid].name, name) == 0) {
            return vector[mid].id;
        }
        if (strcmp(vector[mid].name, name) > 0) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    //If there is no player with such name, returns -1
    return -1;
}
