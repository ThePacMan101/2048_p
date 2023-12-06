#include "options.h"
#include "common.h"
#include "files.h"

void tickOptions(tCommand command, bool *running, tGame *game, tState *state) {
    switch (command) {
        case '1':
            *state = state_deleteUser;
            break;
        case '0':
            *state = state_mainMenu;
            break;
        default:
            break;
    }
}

void renderOptionsOptions() {
    renderLogo();
    printf("\n");
    printf("\t Options\n");
    printf("\t\t[1] Delete User\n");
    printf("\t\t[0] Exit\n");
}

void tickDeleteUser(tCommand command, bool *running, tGame *game, tState *state) {
    scanf("%s", game->user.name);
    *state = state_deleteUser1;
}

void renderDeleteUser() {
    renderLogo();
    printf("\n");
    printf("\tDelete User\n");
    printf("\t\tName: ");
}

void tickDeleteUser1(tCommand command, bool *running, tGame *game, tState *state) {
    switch (command) {
        case '1':
            if (deleteUser(game->user.name)) {
                renderLogo();
                printf("\n");
                printf("\tUser deleted successfully!\n");

            } else {
                renderLogo();
                printf("\n");
                printf("\tUser not found!\n");
            }
            printf("\tPress any key to continue...\n");
            getch();
            *state = state_mainMenu;
            break;
        case '0':
            *state = state_mainMenu;
            break;
        default:
            break;
    }
}

void renderDeleteUser1(tGame game) {
    renderLogo();
    printf("\n");
    printf("\tName: %s\n", game.user.name);
    printf("\tAre you sure you want to delete this user?\n\n");
    printf("\t\t[1] Delete\n");
    printf("\t\t[0] Cancel and Exit\n");
}