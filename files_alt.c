#include "files.h"
#include <stdio.h>
#include "common.h"

void saveUser(tUser user){
    FILE *f;
    char filename="assets/";
    strcat(filename,user.name);
    f = fopen(filename,"r+b");
    if(!f) f = fopen(filename,"w+b");
    if(!f){
        printf("\tCould not save user\n");
        printf("\tPress any key to continue...\n");
        getch();
        return;
    }
    fwrite(&user,sizeof(tUser),1,f);
    fclose(f);
}

tUser loadUser(char*name){
    FILE *f;
    tUser user;
    char filename="assets/";
    strcat(filename,name);
    f=fopen(filename,"r+b");
    if(!f){
        printf("\tThis user does not exist\n");
        printf("\tPress any key to continue...\n");
        getch();
        user.id=-1;
        strcpy(user.name,"invalid-user");
        return user;
    }
    if(fread(&user,sizeof(tUser),1,f)) return user;
    printf("\tCould not load user\n");
    getch();
    user.id=-1;
    strcpy(user.name,"invalid-user");
    return user;
}
