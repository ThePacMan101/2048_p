#include "game.h"
#include "common.h"
#include "files.h"
#include "queue.h"
#include "menu.h"

//This definition of the game board is used to help the developers code/type
#define b(i, j) game->board[i][j] 

void tickPlayingGame(tCommand command, bool *running, tGame *game, tState *state) {
    switch (command) {
        case key_LEAVE:
            if(game->user.id!=-1) saveUser(game->user);
            *state = state_mainMenu;
            break;
        //If any command key is pressed (Down, left, right, up):  
        case key_DOWN:
        case key_LEFT:
        case key_RIGHT:
        case key_UP:
            checkForGameOver(game, state); //Checks for game over
            tGame gameBeforeMove = *game; 
            move(command, game); //Makes the move inputed by the user
            if(game->score > game->user.highScore) game->user.highScore=game->score; //Updates the user highscore if needed
            if (memcmp(&gameBeforeMove, game, sizeof(tGame)) == 0) {
                break;
            }
            spawnNewNumbers(game);
            break;
        default:
            break;
    }
}

void spawnNewNumbers(tGame *game) {
    int v[16] = {0};
    int k = 0;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (!b(i, j)) {
                v[4 * i + j] = ++k;
            }
    if (!k) return; //There are no blank positions 

    int random = rand() % k + 1;
    for (int i = 0; i < 16; i++)
        if (random == v[i]) {
            v[i] = 0;
            b(i / 4, i % 4) = (rand() % 2 + 1) * 2;
            break;
        }
}

void renderPlayingGame(tState state, tGame game) {
    renderLogo();
    printf("\n");

    if (game.user.id != -1) {
        printf("\tPlayer Name: %s\n", game.user.name);
        printf("\tScore:       %d\n", game.score);
        if (game.user.highScore > game.score) {
            printf("\tHighscore:   %d", game.user.highScore);
        } else {
            printf("\tHighscore:   %d!", game.score);
        }
    } else {
        printf("\tScore:       %d\n\n", game.score);
    }

    printf("\n\n");
    printBoard(game);
    printf("\n\n");

    printf("\t[W] UP                 ");
    printf("[A] LEFT                 ");
    printf("[S] DOWN                 ");
    printf("[D] RIGHT\n");

    printf("\n");
    printf("\t[0] Quit.\n");
}

void printBoard(tGame game) {
    printf("\n");
    for (int i = 0; i < 4; i++) {
        printf("\t\t\t\t  ");
        printf("| ");
        for (int j = 0; j < 4; j++) {
            if (game.board[i][j]) {
                printByColor(game.board[i][j]);
                printf(" | ");
            } else {
                printf("     | ");
            };
        }
        printf("\n\n");
    }
}

void move(tCommand command, tGame *game) {
    int prev = 0;
    int idx = -1;
    tQueue *qp = (tQueue *)malloc(sizeof(tQueue));
    startQueue(qp);
    tKey aux;
    switch (command) {
        case key_RIGHT:
            for (int i = 0; i < 4; i++) {
                prev = 0;
                idx = -1;
                for (int j = 3; j >= 0; j--)
                    if (b(i, j)) {
                        if (prev == b(i, j)) {
                            b(i, j) = 0;
                            b(i, idx) = 2 * prev;
                            game->score += 2 * prev; //Updates the game score
                            prev = 0;
                            idx = -1;
                        } else {
                            prev = b(i, j);
                            idx = j;
                        }
                    }
            }
            for (int i = 0; i < 4; i++) {
                for (int j = 3; j >= 0; j--)
                    if (b(i, j)) {
                        aux.number = b(i, j);
                        b(i, j) = 0;
                        pushQueue(qp, aux);
                    }
                int k = 3;
                while (popQueue(qp, &aux)) b(i, k--) = aux.number;
            }
            break;
        case key_LEFT:
            for (int i = 0; i < 4; i++) {
                prev = 0;
                idx = -1;
                for (int j = 0; j < 4; j++)
                    if (b(i, j)) {
                        if (prev == b(i, j)) {
                            b(i, j) = 0;
                            b(i, idx) = 2 * prev;
                            game->score += 2 * prev;
                            prev = 0;
                            idx = -1;
                        } else {
                            prev = b(i, j);
                            idx = j;
                        }
                    }
            }
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++)
                    if (b(i, j)) {
                        aux.number = b(i, j);
                        b(i, j) = 0;
                        pushQueue(qp, aux);
                    }
                int k = 0;
                while (popQueue(qp, &aux)) b(i, k++) = aux.number;
            }
            break;
        case key_UP:
            for (int i = 0; i < 4; i++) {
                prev = 0;
                idx = -1;
                for (int j = 0; j < 4; j++)
                    if (b(j, i)) {
                        if (prev == b(j, i)) {
                            b(j, i) = 0;
                            b(idx, i) = 2 * prev;
                            game->score += 2 * prev;
                            prev = 0;
                            idx = -1;
                        } else {
                            prev = b(j, i);
                            idx = j;
                        }
                    }
            }
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++)
                    if (b(j, i)) {
                        aux.number = b(j, i);
                        b(j, i) = 0;
                        pushQueue(qp, aux);
                    }
                int k = 0;
                while (popQueue(qp, &aux)) b(k++, i) = aux.number;
            }
            break;
        case key_DOWN:
            for (int i = 0; i < 4; i++) {
                prev = 0;
                idx = -1;
                for (int j = 3; j >= 0; j--)
                    if (b(j, i)) {
                        if (prev == b(j, i)) {
                            b(j, i) = 0;
                            b(idx, i) = 2 * prev;
                            game->score += 2 * prev;
                            prev = 0;
                            idx = -1;
                        } else {
                            prev = b(j, i);
                            idx = j;
                        }
                    }
            }
            for (int i = 0; i < 4; i++) {
                for (int j = 3; j >= 0; j--)
                    if (b(j, i)) {
                        aux.number = b(j, i);
                        b(j, i) = 0;
                        pushQueue(qp, aux);
                    }
                int k = 3;
                while (popQueue(qp, &aux)) b(k--, i) = aux.number;
            }
            break;
        default:
            break;
    }

    free(qp);
}

void printByColor(int number) {
    int exponent = 0;
    while (number > 1) {
        number /= 2;
        exponent++; //Defines what exponent of 2 the number is 
    }
    int red = 255 - (exponent * 255) / 11;  // Calculate red component
    int blue = (exponent * 255) / 11;       // Calculate blue component
    printf("\033[38;2;%d;0;%dm%-4d\033[0m", red, blue, 1 << exponent); //prints with specific color
    return;
}

void startGame(tGame *game) {

    emptyGameBoard(game);

    // for (int i = 0; i < 4; i++)
    //     for (int j = 0; j < 4; j++) game->board[i][j] = 0;
    game->score = 0;

    //All games start with 2 random numbers. 
    spawnNewNumbers(game); 
    spawnNewNumbers(game);
}

void checkForGameOver(tGame *game, tState *state) {
    tGame auxiliar = *game;
    move(key_UP, &auxiliar);
    if (memcmp(&auxiliar, game, sizeof(tGame)) == 0) //Check if we can move the game up
        move(key_LEFT, &auxiliar);
    if (memcmp(&auxiliar, game, sizeof(tGame)) == 0) //Check if we can move the game left
        move(key_DOWN, &auxiliar);
    if (memcmp(&auxiliar, game, sizeof(tGame)) == 0) //Check if we can move the game down
        move(key_RIGHT, &auxiliar);
    if (memcmp(&auxiliar, game, sizeof(tGame)) == 0) //Check if we can move the game right
        *state = state_defeatGame; // If the board didn't change in any of the moves, then the game is over
    saveUser(game->user);
    return;
}