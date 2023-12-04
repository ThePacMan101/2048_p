#include "files.h"

#include <stdio.h>

#include "common.h"

/*
This initializeFiles function initalizes both the playerFile.dat and
the gameFile.dat files, and also checks for any problems with said files.
*/
int initializeFiles() {
    /*PLAYERFILE*/
    FILE *playerFile;     // pointer to binary playerFile
    int numberOfPlayers;  // number of players
    int key;              // key pressed

    if ((playerFile = fopen("assets/playerFile.dat", "rb+")) == NULL) {  // detecting if the file exists
        printf("Error opening player files! playerFile.dat does not exist. Do you want to create it?\n");
        printf("\nPress [1] to create file;");
        printf("\nPress [2] to finish application;");
        printf("\n\n> ");
        scanf("%d", &key);

        if (key == 1) {  // Opens file in write binary mode, deleting any pre-existed content
            printf("\n Creating new file...\n");

            fclose(playerFile);

            if ((playerFile = fopen("playerFile.dat", "wb+")) == NULL) {  // Detects if file was opened corretcly
                printf("\n\nError creating playerFile.dat. Press any key to continue\n");
                return -1;
            } else {  // Sets file up
                numberOfPlayers = 0;
                fwrite(&numberOfPlayers, sizeof(int), 1, playerFile);
            }
        } else {
            // Jogar como guest
            printf("\nClosing app...\n");
            return -1;
        }
    }

    rewind(playerFile);

    if (fread(&numberOfPlayers, sizeof(int), 1, playerFile) != 1) {
        printf("\nFile was empty. Initializing file\n");
        numberOfPlayers = 0;
        fwrite(&numberOfPlayers, sizeof(int), 1, playerFile);
    }

    // Everything OK with player file
    fclose(playerFile);

    /*GAMEFILE*/
    FILE *gameFile;  // pointer to binary playerFile

    if ((gameFile = fopen("assets/gameFile.dat", "rb+")) == NULL) {  // detecting if the file exists
        printf("Error opening game files! gameFile.dat does not exist. Do you want to create it?\n");
        printf("\nPress [1] to create file;");
        printf("\nPress [2] to finish application;");
        printf("\n\n> ");
        scanf("%d", &key);

        if (key == 1) {  // Opens file in write binary mode, deleting any pre-existed content
            printf("\n Creating new file...\n");

            fclose(playerFile);

            if ((playerFile = fopen("gameFile.dat", "wb+")) == NULL) {  // Detects if file was opened corretcly
                printf("\n\nError creating gameFile.dat. Press any key to continue\n");
                return -1;
            } else {  // Sets file up
                numberOfPlayers = 0;
                fwrite(&numberOfPlayers, sizeof(int), 1, playerFile);
            }
        } else {
            printf("\nClosing app...\n");
            return -1;
        }
    }

    // INICIALIZAR

    // Everything OK with game file
    fclose(gameFile);

    return 0;
}

/*
The function convertPlayersToVector reads all players from the players file
and converts them into a vector of type tUser, then sets the variable numbers
to the number of players read and returns the pointer to the vector
*/
tUser *convertPlayersToVector(int *number) {
    // Opens players file
    FILE *playerFile;
    if ((playerFile = (fopen("playerFile.dat", "rb"))) == NULL) {
        printf("An error has occurred. Please restart the game.\n");  // Error message
        return NULL;
    }

    // Positions file pointer at the beginning of the file
    rewind(playerFile);

    // Reads an integer, the number of players in the file
    int numberOfPlayers;
    fread(&numberOfPlayers, sizeof(int), 1, playerFile);

    // Reads from the file into the vector
    tUser *vector = malloc(sizeof(tUser) * numberOfPlayers);
    if (!vector) {
        printf("An error has occurred. Please restart the game1.\n");  // Error message
        return NULL;
    }
    if (fread((vector), sizeof(tUser), numberOfPlayers, playerFile) < numberOfPlayers) {
        printf("An error has occurred. Please restart the game2.\n");  // Error message
        return NULL;
    }

    // Sets the number given in the entry to number of players
    *number = numberOfPlayers;

    // Returns the pointer to the vector
    return vector;
}

/*
Temporary function to convert binary files in text files.
Now, it is set to read the "playerFile.dat" file.
*/
void readBinaryFile() {
    FILE *f;
    FILE *fa;
    tUser user;
    int count;

    f = fopen("playerFile.dat", "rb+");
    fa = fopen("playerFile.txt", "w+");

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
This addNewPlayer function adds a new player into the playerFile.
It saves the players name, ID and highScore (initially 0) in game.
The ID generated for said player is just the players position in
the file. The number of players is kept at the top of said file.
*/
int addNewPlayer(tUser user) {
    // Creating pointer to binary file playerFile.dat and checking for errors
    FILE *playerFile;
    if ((playerFile = fopen("playerFile.dat", "rb+")) == NULL) {
        printf("Error adding new player! Press any key to continue\n");
        getchar();
        return -1;
    }

    // Reading the number of players at the top of the file
    int numberOfPlayers;
    fread(&numberOfPlayers, sizeof(int), 1, playerFile);

    numberOfPlayers++;          // updates the number of players
    user.id = numberOfPlayers;  // new player's ID

    // Writes new player at the end of file
    fseek(playerFile, 0, SEEK_END);
    fwrite(&user, sizeof(tUser), 1, playerFile);

    // Updates the number of players in the beginning of the file
    rewind(playerFile);
    fwrite(&numberOfPlayers, sizeof(int), 1, playerFile);

    fclose(playerFile);  // closes playerFile
    return 0;
}

/*
This rankPlayers function orders a vector of type tUser, using
the convertPlayersToVector function, and them implements a bubble sort
algorithm to order the users by their highScores. Then, we print in
the terminal the sorted vector.
*/
void rankPlayers(tUser *players, int numberOfPlayers) {
    players = convertPlayersToVector(&numberOfPlayers);  // Gets the vector with all players

    tUser temporary;
    bool change = false;  // Flag to check if any changes were made in the last iteration

    /*BUBBLE SORT ALGORITHM*/
    for (int end = numberOfPlayers - 1; end > 0; end--) {
        for (int i = 0; i < end; i++) {
            if (((*(players + i)).highScore) > ((*(players + i + 1)).highScore)) {
                change = true;
                temporary = *(players + i);
                *(players + i) = *(players + i + 1);
                *(players + i + 1) = temporary;
            }
        }

        if (change == false) break;  // If no changes were made, then the vector is already ordered
    }

    /*PRINTING PLAYER'S RANK IN TERMINAL*/

    printf("\n\t\t\tRANK\n");

    for (int i = numberOfPlayers - 1; i >= 0; i--) {
        printf("\t\tPosition: %d \t Name: %s \t HightScore: %d\n", (i + 1), (*(players + i)).name, (*(players + i)).highScore);
    }
}

/*
This orderPlayersName function orders a vector of type tUser
in alphabetical order, using the strcmp function and a
bubble sort algorithm.
*/
void orderPlayersName(tUser *players, int numberOfPlayers) {
    tUser temporary;
    bool change = false;  // Flag to check if any changes were made in the last iteration

    /*BUBBLE SORT ALGORITHM*/
    for (int end = numberOfPlayers - 1; end > 0; end--) {
        for (int i = 0; i < end; i++) {
            if (strcmp((*(players + i)).name, (*(players + i + 1)).name) > 0) {
                change = true;
                temporary = *(players + i);
                *(players + i) = *(players + i + 1);
                *(players + i + 1) = temporary;
            }
        }

        if (change == false) break;  // If no changes were made, the vector is already ordered
    }
}

/*
This findPlayer function gets the alphabetically ordered vector with all players in playerFile.dat
(using convertPlayersToVector and orderPlayersName), and implements a binary search to find the
player that has the same name passed in the argument. The function returns the vector's index
of said user, or -1 if no user with that name was found.
*/
int findPlayer(tUser *players, int numberOfPlayers, char name[]) {
    players = convertPlayersToVector(&numberOfPlayers);
    orderPlayersName(players, numberOfPlayers);

    /*BINARY SEARCH ALGORITHM*/

    int left = 0, right = numberOfPlayers - 1;
    int middle;

    while (left <= right) {
        middle = (left + right) / 2;

        if (strcmp((*(players + middle)).name, name) < 0)
            left = middle + 1;
        else if (strcmp((*(players + middle)).name, name) > 0)
            right = middle - 1;
        else
            return middle;
    }

    return -1;
}

/*
The function saveGame takes the current state of the board,
the score and the user associated to the game and saves it to
the games file
*/
bool saveGame(tGame game) {
    // Current game
    tGame current = game;

    // Opens the players file
    FILE *playerFile;
    if ((playerFile = fopen("playerFile.dat", "rb")) == NULL) {
        printf("Error opening \"playerFile.dat\". Please check if the file already exists.\n");
        return false;  // Game has NOT been successfully saved
    }

    // Opens the games file
    FILE *gameFile;
    if ((gameFile = fopen("gameFile.dat", "r+b")) == NULL) {
        printf("Error opening \"gameFile.dat\". Please check if the file already exists.\n");
        return false;  // Game has NOT been successfully saved
    }

    // Positions the file pointer at the and of the file
    fseek(gameFile, 0, SEEK_END);

    // Checks if the user already has a save
    if (game.user.hasSave == true) {
        printf("User \"%s\" already has a saved game. Do you want to delete it?\n", game.user.name);
        printf("\nPress [1] to delete previously saved game;");
        printf("\nPress [2] to cancel operation;");
        int key;
        printf("\n\n> ");
        scanf("%d", &key);
        while (key != 1) {
            if (key == 2) {
                return false;  // Game has NOT been successfully saved
            }
            printf("Invalid key. Please press [1] or [2].\n");
            printf("\n\n> ");
            scanf("%d", &key);
        }

        // Positions the file pointer at the beginning of the file and reads the number of games
        rewind(gameFile);
        int numberOfGames;
        fread(&numberOfGames, sizeof(int), 1, gameFile);

        // Positions the file pointer right before the game to be overwritten
        tGame comparisonGame;
        for (int i = 0; i < numberOfGames; i++) {
            fread(&comparisonGame, sizeof(tGame), 1, gameFile);
            if (comparisonGame.user.id == game.user.id) {
                fseek(gameFile, (sizeof(tGame)), SEEK_CUR);
                break;
            }
        }
    }

    // Writes the new game to the games file and updates hasSave to true
    fwrite(&current, sizeof(tGame), 1, gameFile);
    game.user.hasSave = true;
    return true;  // Game has been successfully saved
}