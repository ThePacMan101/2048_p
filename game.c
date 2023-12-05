#include "game.h"

#include "common.h"
#include "menu.h"
#include "queue.h"

void printByColor(int number);
void move(tCommand command, tGame *game);
void spawnNewNumbers(tGame *game);
void tickplayingGame(tCommand command, bool *running, tGame *game, tState *state);
void renderPlayingGame(tState state, tGame game);

void tickPlayingGame(tCommand command, bool *running, tGame *game, tState *state) {
    switch (command) {
        case key_E:
            break;
        case key_LEAVE:
            *state = state_mainMenu;
            break;
        case key_DOWN:
        case key_LEFT:
        case key_RIGHT:
        case key_UP:
            checkForGameOver(*game, state);
            tGame gameBeforeMove = *game;
            move(command, game);
            if (memcmp(&gameBeforeMove, game, sizeof(tGame)) == 0) {
                break;
            }
            spawnNewNumbers(game);
            break;
        default:
            break;
    }
}

#define b(i, j) game->board[i][j]
void spawnNewNumbers(tGame *game) {
    int v[16] = {0};
    int k = 0;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (!b(i, j)) {
                v[4 * i + j] = ++k;
            }
    if (!k) return;

    int random = rand() % k + 1;
    for (int i = 0; i < 16; i++)
        if (random == v[i]) {
            v[i] = 0;
            b(i / 4, i % 4) = (rand() % 2 + 1) * 2;
            break;
        }
}

void renderPlayingGame(tState state, tGame game) {
    system("cls");
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
        printf("\tScore:       %d\n", game.score);
        printf("\tHighscore:   %d", game.score);
    }

    printf("\n\n");
    printBoard(game);
    printf("\n\n");

    printf("\tPress [W] to move up.\n");
    printf("\tPress [A] to move left.\n");
    printf("\tPress [S] to move down.\n");
    printf("\tPress [D] to move right.\n");

    printf("\n\n");
    if (game.user.id != -1) {
        printf("\tPress [E] to save and quit.\n");
    }

    printf("\tPress [0] to quit.\n");
}

void printBoard(tGame game) {
    printf("\n");
    for (int i = 0; i < 4; i++) {
        printf("\t\t\t\t  ");
        printf("| ");
        for (int j = 0; j < 4; j++) {
            if (game.board[i][j]) {
                printByColor(game.board[i][j]);
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
        exponent++;
    }
    int red = 255 - (exponent * 255) / 11;  // Calculate red component
    int blue = (exponent * 255) / 11;       // Calculate blue component
    printf("\033[38;2;%d;0;%dm%-4d\033[0m", red, blue, 1 << exponent);
    printf(" | ");
    return;
}

void startGame(tGame *game) {
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++) game->board[i][j] = 0;
    game->score = 0;
    spawnNewNumbers(game);
    spawnNewNumbers(game);
}

void checkForGameOver(tGame game, tState *state) {
    tGame auxiliar = game;
    move(key_UP, &auxiliar);
    if (memcmp(&auxiliar, &game, sizeof(tGame)) == 0)
        move(key_LEFT, &auxiliar);
    if (memcmp(&auxiliar, &game, sizeof(tGame)) == 0)
        move(key_DOWN, &auxiliar);
    if (memcmp(&auxiliar, &game, sizeof(tGame)) == 0)
        move(key_RIGHT, &auxiliar);
    if (memcmp(&auxiliar, &game, sizeof(tGame)) == 0)
        *state = state_defeatGame;
    return;
}
