#include "common.h"
#include "files_alt.h"

void saveUserList(tUser user){
    FILE *f;
    f=fopen("assets/players.dat","r+b");
    if(!f) fopen("assets/players.dat","w+b");
    fseek(f,0,SEEK_END);
    fwrite(user.name,20,1,f);
    fclose(f);
}

tUser* UserListToArray(int*tam){
    /*FILE *listFile=fopen("assets/players.dat","r+b");
    FILE *aux;
    char filename[30];
    char name[20];
    fseek(listFile,0,SEEK_END);
    *tam=ftell(listFile)/20;
    tUser *array=(tUser*)malloc((*tam)*sizeof(tUser));
    rewind(listFile);
    printf("%d\n",*tam);
    for(int i = 0 ; i < *tam ; i ++){
        fread(name,20,1,listFile);
        strcpy(filename,"assets/");
        strcat(filename,name);
        strcat(filename,".dat");

        aux=fopen(filename,"r+b");
        fread(array+i,sizeof(tUser),1,aux);
        fclose(aux);

        //printf("{\n");
        //printf("\t%s\n\t%d",array[i].name,array[i].highScore);
        //printf("\n}");

    }

    getch();

    fclose(listFile);
    return array;*/
    return (tUser*)NULL;
}

void saveUser(tUser user){
    FILE *f;
    char filename[30]="assets/";
    strcat(filename,user.name);
    strcat(filename,".dat");
    f = fopen(filename,"r+b");
    if(!f) f = fopen(filename,"w+b");
    if(!f){
        printf("\tCould not save user\n");
        printf("Press any key to continue...\n");
        getch();
        return;
    }
    fwrite(&user,sizeof(tUser),1,f);
    fclose(f);
}

void loadUser(tUser *user){

    FILE *f;
    user->highScore=0;
    user->id=0;
    char filename[30]="assets/";
    
    strcat(filename,user->name);
    strcat(filename,".dat");
    f=fopen(filename,"r+b");
    if(!f){
        fclose(f);
        saveUserList(*user);
        saveUser(*user);
        return;
    }
    if(!fread(user,sizeof(tUser),1,f)){
        fclose(f);
        saveUserList(*user);
        saveUser(*user);
        return;
    }
    fclose(f);
    return;
}
