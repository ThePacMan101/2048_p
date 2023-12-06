#include "files.h"

#include "common.h"

void initFiles() {
    FILE *f = fopen("assets/players.dat", "r+b");
    if (!f) f = fopen("assets/players.dat", "w+b");
    fclose(f);
}

void saveUserList(tUser user) {
    FILE *f;
    f = fopen("assets/players.dat", "r+b");
    if (!f) fopen("assets/players.dat", "w+b");
    fseek(f, 0, SEEK_END);
    fwrite(user.name, 20, 1, f);
    fclose(f);
}

tUser *userListToArray(int *size) {
    FILE *listFile = fopen("assets/players.dat", "r+b");
    FILE *aux;
    char filename[30];
    char name[20];
    fseek(listFile, 0, SEEK_END);
    *size = ftell(listFile) / 20;
    tUser *array = (tUser *)malloc((*size) * sizeof(tUser));
    rewind(listFile);
    for (int i = 0; i < *size; i++) {
        fread(name, 20, 1, listFile);
        strcpy(filename, "assets/");
        strcat(filename, name);
        strcat(filename, ".dat");

        aux = fopen(filename, "r+b");
        fread(array + i, sizeof(tUser), 1, aux);
        fclose(aux);
    }
    fclose(listFile);
    return array;
    return (tUser *)NULL;
}

void saveUser(tUser user) {
    if (user.id == -1) return;
    FILE *f;
    char filename[30] = "assets/";
    strcat(filename, user.name);
    strcat(filename, ".dat");
    f = fopen(filename, "r+b");
    if (!f) f = fopen(filename, "w+b");
    if (!f) {
        printf("\tCould not save user\n");
        printf("Press any key to continue...\n");
        getch();
        return;
    }
    fwrite(&user, sizeof(tUser), 1, f);
    fclose(f);
}

void loadUser(tUser *user) {
    FILE *f;
    user->highScore = 0;
    user->id = 0;
    char filename[30] = "assets/";

    strcat(filename, user->name);
    strcat(filename, ".dat");
    f = fopen(filename, "r+b");
    if (!f) {
        // fclose(f);
        saveUserList(*user);
        saveUser(*user);
        return;
    }
    if (!fread(user, sizeof(tUser), 1, f)) {
        fclose(f);
        saveUserList(*user);
        saveUser(*user);
        return;
    }
    fclose(f);
    return;
}

tUser *sortUsersByHighScore(int *size) {
    tUser *array;
    array = userListToArray(size);

    bool unordered = true;
    int k = 0;
    tUser aux;
    while (unordered) {
        unordered = false;
        for (int i = 0; i < *size - 1 - k; i++) {
            if (array[i].highScore < array[i + 1].highScore) {
                aux = array[i];
                array[i] = array[i + 1];
                array[i + 1] = aux;
                unordered = true;
            }
        }
        k++;
    }
    printf("\n");
    printf("\t\t\t\t \033[1;33m%d:      %-6d         %s\033[0m\n", 1, array[0].highScore, array[0].name);
    printf("\t\t\t\t %d:      %-6d         %s\n", 2, array[1].highScore, array[1].name);
    printf("\t\t\t\t \x1b[38;5;172m%d:      %-6d         %s\033[0m\n", 3, array[2].highScore, array[2].name);
    printf("\n");
    for (int i = 3; i < *size; i++) {
        printf("\t\t\t\t \033[1;30m%d:      %-6d         %s\033[0m\n", i + 1, array[i].highScore, array[i].name);
    }

    return array;
}

void sortUsersByName(tUser *array, int size) {
    bool unordered = true;
    int k = 0;
    tUser aux;
    while (unordered) {
        unordered = false;
        for (int i = 0; i < size - 1 - k; i++) {
            if (strcmp(array[i].name, array[i + 1].name) > 0) {
                aux = array[i];
                array[i] = array[i + 1];
                array[i + 1] = aux;
                unordered = true;
            }
        }
        k++;
    }
}

int binSearchName(tUser *array, int size, char nameToBeFound[]) {
    int left = 0;
    int right = size - 1;

    int middle;

    while (left <= right) {
        middle = (left + right) / 2;
        if (strcmp((*(array + middle)).name, nameToBeFound) > 0)
            right = middle - 1;
        else if (strcmp((*(array + middle)).name, nameToBeFound) < 0)
            left = middle + 1;
        else
            return middle;
    }

    return -1;
}

bool deleteUser(char *name) {
    int size, idx;
    FILE *f;
    tUser *array;
    array = userListToArray(&size);
    sortUsersByName(array, size);
    idx = binSearchName(array, size, name);

    if (idx == -1)
        return false;
    else {
        f = fopen("assets/players.dat", "wb");
        if (!f) return false;
        for (int i = 0; i < size - 1; i++) {
            if (i != idx) fwrite(array[i].name, 20, 1, f);
        }
        fclose(f);
    }

    char filename[30] = "assets/";
    strcat(filename, name);
    strcat(filename, ".dat");

    if (remove(filename)) return false;

    return true;
}