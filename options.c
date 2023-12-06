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
    printf("%c",command);
    char aux[20],aux2[20];              //  This is a workaround wichcraft so that
    scanf("%s", aux2);                  //  the input works properly
    aux[0]=command;                     //  wasn't working before due to the getch()   
    aux[1]='\0';                        //  function in getCommand() in the main.c file
    strcat(aux,aux2);                   //  skipping the first letter of the input
    strcpy(game->user.name,aux);        //  the fix is to concat some strings
    //printf("\n\n%s",game->user.name); //  so that in the end whe have that
    //getch();                          //  game->user.name == command+(result of scanf)
    *state = state_deleteUser1;         //  it also prints command on screen so that it gets seemless
}                                       //  to the user. Known Issue: Cannot erase first letter after
                                        //  typing once
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