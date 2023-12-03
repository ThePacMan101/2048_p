#include "common.h"
#include "files.h"
#include <stdio.h>

/*
This initializeFiles function initalizes both the playerFile.dat and 
the gameFile.dat files, and also checks for any problems with said files. 
*/
int initializeFiles() {
    /*PLAYERFILE*/
    FILE *playerFile; //pointer to binary playerFile
    int numberOfPlayers; //number of players
    int key; //key pressed
    
    if((playerFile = fopen("playerFile.dat", "rb+")) == NULL) { //detecting if the file exists
        printf("Error opening player files! playerFile.dat does not exist. Do you want to create it?\n");
        printf("\nPress [1] to create file;");
        printf("\nPress [2] to finish application;");
        printf("\n\n> ");
        scanf("%d", &key);

        if(key == 1) { //Opens file in write binary mode, deleting any pre-existed content
            printf("\n Creating new file...\n");

            fclose(playerFile);

            if((playerFile = fopen("playerFile.dat", "wb+")) == NULL) { //Detects if file was opened corretcly
                printf("\n\nError creating playerFile.dat. Press any key to continue\n");
                return -1;
            }
            else { //Sets file up
                numberOfPlayers = 0;
                fwrite(&numberOfPlayers, sizeof(int), 1, playerFile);
            }
        }
        else {
            printf("\nClosing app...\n");
            return -1;
        }
    }

    rewind(playerFile);

    if(fread(&numberOfPlayers, sizeof(int), 1, playerFile) != 1) {
        printf("\nFile was empty. Initializing file\n");
        numberOfPlayers = 0;
        fwrite(&numberOfPlayers, sizeof(int), 1, playerFile);
    }
    
    //Everything OK with player file
    fclose(playerFile);
    
    /*GAMEFILE*/
    FILE *gameFile; //pointer to binary playerFile
    
    if((gameFile = fopen("gameFile.dat", "rb+")) == NULL) { //detecting if the file exists
        printf("Error opening game files! gameFile.dat does not exist. Do you want to create it?\n");
        printf("\nPress [1] to create file;");
        printf("\nPress [2] to finish application;");
        printf("\n\n> ");
        scanf("%d", &key);

        if(key == 1) { //Opens file in write binary mode, deleting any pre-existed content
            printf("\n Creating new file...\n");

            fclose(playerFile);

            if((playerFile = fopen("gameFile.dat", "wb+")) == NULL) { //Detects if file was opened corretcly
                printf("\n\nError creating gameFile.dat. Press any key to continue\n");
                return -1;
            }
            else { //Sets file up
                numberOfPlayers = 0;
                fwrite(&numberOfPlayers, sizeof(int), 1, playerFile);
            }
        }
        else {
            printf("\nClosing app...\n");
            return -1;
        }
    }
    
    //Everything OK with game file
    fclose(gameFile);

    return 0;
}

int saveGame(tGame game, tUser user) {
    FILE *file_game;

    if((file_game = fopen("files_game.dat", "wb")) == NULL) {
        printf("Error saving game!");
        return -1;
    }

    //Detectar se já existe um jogo salvo com esse nome

    else {
        //
        
    }

    return 0;

}

int loadGame(tGame *game) {
    FILE *file_game;

    if((file_game = fopen("files_game.dat", "rb")) == NULL) {
        printf("Error saving game!");
        return -1;
    }

    else {
        fread(game, sizeof(tGame), 1, file_game);
        return 0;
    }

    //Abrir o arquivo em modo de leitura
        //Checar abertura
    //Posicionar o arquivo na posição correta
    //Ler o jogo e definir como jogo
}

int convertVector(tGame *games) {
    
    tGame game;
    FILE *file_game;

    int count = 0;

    if((file_game = fopen("files_game.dat", "rb")) == NULL) {
        printf("Error opening file!");
        return -1;
    }

    while (!fread(&game, sizeof(tGame), 1, file_game)) {
        count++;
    } 
    
    fseek(file_game, 0, SEEK_SET);

    games = (tGame *) malloc(sizeof(tGame)*count);

    int i = 0;
    while (!fread(&game, sizeof(tGame), 1, file_game)) {
        *(games + i) = game;
        i++;
    }

    return 0;
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

    for(int i = 0; i < count; i++) {
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
    
    //Creating pointer to binary file playerFile.dat and checking for errors
    FILE *playerFile;
    if((playerFile = fopen("playerFile.dat", "rb+")) == NULL) {
        printf("Error adding new player! Press any key to continue\n");
        getchar();
        return -1;
    }

    //Reading the number of players at the top of the file
    int numberOfPlayers; 
    fread(&numberOfPlayers, sizeof(int), 1, playerFile);

    numberOfPlayers++; //updates the number of players
    user.id = numberOfPlayers; //new player's ID 

    //Writes new player at the end of file
    fseek(playerFile, 0, SEEK_END); 
    fwrite(&user, sizeof(tUser), 1, playerFile);

    //Updates the number of players in the beginning of the file
    rewind(playerFile);
    fwrite(&numberOfPlayers, sizeof(int), 1, playerFile);
    
    fclose(playerFile); //closes playerFile
    return 0;
}

// void orderPlayersName(tUser *players, int numberOfPlayers) {
//     tUser temporary;
//     bool change = false;

// 	for (int end = numberOfPlayers - 1; end > 0; end--) {
// 		for (int i = 0; i < end; i++) {
// 			if (strcmp(*(players + i)->name, *(players + i)->name) == 1) {
//                 change = true;
//                 temporary = *(players + i);
//                 *(players + i) = *(players + i + 1);
//                 *(players + i + 1) = temporary;
//             }
//         }

//         if (change == false) return;
//     }
// }



/*
The function convertPlayersToVector reads all players from the players file 
and converts them into a vector of type TUser, then sets the variable numbers
to the number of players read and returns the pointer to the vector
*/
tUser *convertPlayersToVector(int *number) {

    //Opens players file
    FILE *playerFile;
    if ((playerFile = (fopen("playerFile.dat", "rb"))) == NULL) {
        printf("An error has occurred. Please restart the game.\n");//Error message
        return NULL;
    }

    //Positions file pointer at the beginning of the file
    rewind(playerFile);

    //Reads an integer, the number of players in the file 
    int numberOfPlayers;
    fread(&numberOfPlayers, sizeof(int), 1, playerFile);

    //Reads from the file into the vector
    tUser *vector = malloc(sizeof(tUser) *numberOfPlayers);
    if (!vector) {
        printf("An error has occurred. Please restart the game.\n"); //Error message
        return NULL;
    }
    if(fread((vector), sizeof(tUser), numberOfPlayers, playerFile) < numberOfPlayers) {
        printf("An error has occurred. Please restart the game.\n"); //Error message
        return NULL;
    }

    //Sets the number given in the entry to number of players
    *number = numberOfPlayers;

    //Returns the pointer to the vector
    return vector;
}

void rankPlayers(tUser *players, int numberOfPlayers) {
    players = convertPlayersToVector(&numberOfPlayers);

    tUser temporary;
    bool change = false;

    for (int end = numberOfPlayers - 1; end > 0; end--) {
		for (int i = 0; i < end; i++) {
			if (((*(players + i)).highScore) > ((*(players + i + 1)).highScore)) {
                change = true;
                temporary = *(players + i);
                *(players + i) = *(players + i + 1);
                *(players + i + 1) = temporary;
            }
        }

        if (change == false) break;
    }

    printf("\n\t\t\tRANK DE JOGADORES\n");

    for(int i = numberOfPlayers - 1; i >= 0; i--) {
        printf("\t\tPosition: %d \t Name: %s \t HightScore: %d\n", (i + 1), (*(players+i)).name, (*(players+i)).highScore);
    }
}