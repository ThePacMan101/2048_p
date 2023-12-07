#include "menu.h"
#include "game.h"
#include "files.h"
#include "common.h"

void tickMainMenu(tCommand command, bool *running, tGame *game, tState *state) {
    switch (command) {
        case '1':
            *state = state_preGame;
            break;
        case '2':
            *state = state_optionsMenu;
            break;
        case '3':
            *state = state_rankingMenu;
            break;
        case '4':
            *state = state_creditsMenu;
            break;
        case '0':
            *running = false;
            break;
        default:
            break;
    }
}

void renderMainMenu(tState state) {
    renderLogo();
    printf("\t                                 \033[1mWelcome to 2048!\033[0m                          \n");
    printf("\tChoose an option:\n");
    printf("\t\t[1] Play\n");
    printf("\t\t[2] Options\n");
    printf("\t\t[3] Ranking\n");
    printf("\t\t[4] Credits\n");
    printf("\t\t[0] Exit\n");
}

void tickDefeatGame(tCommand command, bool *running, tGame *game, tState *state) {
    
    switch (command) {
        case key_LEAVE:
            *state = state_mainMenu;
            break;
        default:
            break;
    }
    return;
}

void renderDefeatGame(tGame game) {
    renderLogo();

    printf("\n\tGame over!\n\n");

    printf("\n\n");
    printBoard(game);
    printf("\n\n");

    if(game.user.id!=-1) printf("\t\tPlayer Name: %s\n", game.user.name);
    printf("\t\tScore:       %d\n", game.score);
    if(game.user.id!=-1){
        if (game.user.highScore > game.score) {
            printf("\t\tHighscore:   %d\n\n", game.user.highScore);
        } else {
            printf("\t\tHighscore:   %d!\n\n", game.score);
        }
    }
    printf("\t\tPress [0] to continue.\n");
    return;
}

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

void renderOptions() {
    renderLogo();
    printf("\n");
    printf("\t Options\n");
    printf("\t\t[1] Delete User\n");
    printf("\t\t[0] Exit\n");
}

void tickDeleteUser(tCommand command, bool *running, tGame *game, tState *state) {
    char aux[20];             
    scanf("%s", aux);
    strcpy(game->user.name,aux);        
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

void renderPreGame(tState state, tGame game) {
    renderLogo();
    printf("\n");
    printf("\tChoose an option:\n");
    printf("\t\t[1] Play as guest\n");
    printf("\t\t[2] Login\n");
    printf("\t\t[0] Exit\n");
}

void tickPreGame(tCommand command, bool *running, tGame *game, tState *state) {
    switch (command) {
        case '1':
            strcpy(game->user.name,"guest-user");
            game->user.id=-1;
            *state = state_playingGame;
            startGame(game);
            break;
        case '2':
            login(game);
            *state = state_playingGame;
            startGame(game);
            break;
        case '0':
            *state = state_mainMenu;
            break;
        default:
            break;
    }
}

void login(tGame *game) {
    tUser user;
    renderLogo();
    printf("\n");
    printf("\tEnter your username (max 20 letters): ");
    scanf("%s", user.name); //gets the user's name
    int i = 0;
    while(user.name[i]!='\0'){ user.name[i]=tolower(user.name[i]);i++;} //defines all characters as lower case
    loadUser(&user); //tries loading said user
    game->user=user;
}

void tickRanking(tCommand command, bool *running, tGame *game, tState *state) {
    switch (command) {
        case '0':
            *state = state_mainMenu;
            break;

        default:

            break;
    }
}

void renderRanking() {
    renderLogo();
    printf("\n");
    printf("\t Ranking \t\t #: \t Highscore      Name\n");
    printf("\t\t[0] Exit\n");

    int size;
    
    sortUsersByHighScore(&size);

    
    
    
}

void tickCredits(tCommand command, bool *running, tGame *game, tState *state) {
    if(command==key_LEAVE) *state=state_mainMenu;
}

void renderCredits() {
    renderLogo();
    printf("\n");

    printf("\tDeveloped by:\n");
    printf("\t\t[0] Exit\n\n");
    
    printf("\t\t\t\e[1;31m              Leonardo Lima Santos\x1b[0m \n");
    printf("\t\t\t\e[1;33m          Lucas Pimentel Alves da Costa\x1b[0m \n");
    printf("\t\t\t\e[1;34m     Paulo Roberto Ferreira de Godoy Moreira\x1b[0m\n");
    printf("\t\t\t\e[1;35m               Vitor Amaral Bedin\x1b[0m \n");

    printf("\n");
    
}

void renderLogo() {
    printf("\e[1;1H\e[2J");
    printf("\t___________________________________________________________________________________\n\n\n");
    //          ---------------------------------------------------------------------------------
    printf("\t\033[38;2;0;0;255m    /\\\\\\\\\\\\\\\\\\         /\\\\\\\\\\\\\\               /\\\\\\        /\\\\\\\\\\\\\\\\\\            \033[0m\n");
    printf("\t\033[38;2;0;0;255m   /\\\\\\///////\\\\\\     /\\\\\\/////\\\\\\           /\\\\\\\\\\      /\\\\\\///////\\\\\\         \033[0m\n");
    printf("\t\033[38;2;0;0;255m   \\///      \\//\\\\\\   /\\\\\\    \\//\\\\\\        /\\\\\\/\\\\\\     \\/\\\\\\     \\/\\\\\\        \033[0m\n");
    printf("\t\033[38;2;0;0;255m              /\\\\\\/   \\/\\\\\\     \\/\\\\\\      /\\\\\\/\\/\\\\\\     \\///\\\\\\\\\\\\\\\\\\/        \033[0m\n");
    printf("\t\033[38;2;0;0;255m            /\\\\\\//     \\/\\\\\\     \\/\\\\\\    /\\\\\\/  \\/\\\\\\      /\\\\\\///////\\\\\\      \033[0m\n");
    printf("\t\033[38;2;0;0;255m          /\\\\\\//        \\/\\\\\\     \\/\\\\\\  /\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\  /\\\\\\      \\//\\\\\\    \033[0m\n");
    printf("\t\033[38;2;0;0;255m         /\\\\\\/           \\//\\\\\\    /\\\\\\  \\///////////\\\\\\//  \\//\\\\\\      /\\\\\\    \033[0m\n");
    printf("\t\033[38;2;0;0;255m         /\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\  \\///\\\\\\\\\\\\\\/             \\/\\\\\\     \\///\\\\\\\\\\\\\\\\\\/    \033[0m\n");
    printf("\t\033[38;2;0;0;255m         \\///////////////     \\///////               \\///        \\/////////     \033[0m\n");
    printf("\n");
    printf("\t___________________________________________________________________________________\n");
}