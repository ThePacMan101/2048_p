#include "common.h"
#include "files.h"

void initFiles(){
    FILE* f = fopen("assets/players.dat","r+b");
    if(!f) f = fopen("assets/players.dat","w+b");
    fclose(f);
}

void saveUserList(tUser user){
    FILE *f;
    f=fopen("assets/players.dat","r+b");
    if(!f) fopen("assets/players.dat","w+b");
    fseek(f,0,SEEK_END);
    fwrite(user.name,20,1,f);
    fclose(f);
}

tUser* UserListToArray(int*tam){
    FILE *listFile=fopen("assets/players.dat","r+b");
    FILE *aux;
    char filename[30];
    char name[20];
    fseek(listFile,0,SEEK_END);
    *tam=ftell(listFile)/20;
    tUser *array=(tUser*)malloc((*tam)*sizeof(tUser));
    rewind(listFile);
    for(int i = 0 ; i < *tam ; i ++){
        fread(name,20,1,listFile);
        strcpy(filename,"assets/");
        strcat(filename,name);
        strcat(filename,".dat");

        aux=fopen(filename,"r+b");
        fread(array+i,sizeof(tUser),1,aux);
        fclose(aux);
    }
    fclose(listFile);
    return array;
    return (tUser*)NULL;
}

void saveUser(tUser user){
    if(user.id==-1) return;
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
        //fclose(f);
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

void sortUsers_highScore(tUser* array,int tam){
    bool unordered = true;
    int k=0;
    tUser aux;
    while(unordered){
        unordered=false;
        for(int i = 0 ; i < tam-1-k ; i++){
            if(array[i].highScore<array[i+1].highScore){
                aux=array[i];
                array[i]=array[i+1];
                array[i+1]=aux;
                unordered=true;
            }
        }
        k++;
    }
}

void sortUsers_name(tUser* array,int tam){
    bool unordered = true;
    int k=0;
    tUser aux;
    while(unordered){
        unordered=false;
        for(int i = 0 ; i < tam-1-k ; i++){
            if(strcmp(array[i].name,array[i+1].name)>0){
                aux=array[i];
                array[i]=array[i+1];
                array[i+1]=aux;
                unordered=true;
            }
        }
        k++;
    }
}

tUser *sortUsers(int key){

    tUser* array;
    int tam;

    array = UserListToArray(&tam);

    bool unordered = true;
    int k=0;
    tUser aux;

    switch(key) {
        case 1:
            while(unordered){
                unordered=false;
                for(int i = 0 ; i < tam-1-k ; i++){
                    if(array[i].highScore<array[i+1].highScore){
                        aux=array[i];
                        array[i]=array[i+1];
                        array[i+1]=aux;
                        unordered=true;
                    }
                }
                k++;
            }
            break;
        case 2:
            while(unordered){
                unordered=false;
                for(int i = 0 ; i < tam-1-k ; i++){
                    if(strcmp(array[i].name,array[i+1].name)>0){
                        aux=array[i];
                        array[i]=array[i+1];
                        array[i+1]=aux;
                        unordered=true;
                    }
                }
                k++;
            }
        break;
    }


    return array;
}