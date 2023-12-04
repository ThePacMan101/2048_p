#include "queue.h"

void startQueue(tQueue *f) {
    f->start = NULL;
    f->end = NULL;
}
int sizeQueue(tQueue *f) {
    tElement *end = f->start;
    int tam = 0;
    while (end != NULL) {
        tam++;
        end = end->next;
    }
    return tam;
}
void showQueue(tQueue *f) {
    tElement *end = f->start;
    printf("tQueue: \" ");
    while (end != NULL) {
        // printf("[%i %i] ", end->key.idx,end->key.number);
        printf("[%i] ", end->key.number);
        end = end->next;
    }
    printf("\"\n");
}
bool pushQueue(tQueue *f, tKey key) {
    tElement *new = (tElement *)malloc(sizeof(tElement));
    new->key = key;
    new->next = NULL;
    if (f->start == NULL)
        f->start = new;
    else
        f->end->next = new;
    f->end = new;
    return true;
}
bool popQueue(tQueue *f, tKey *key) {
    if (f->start == NULL)
        return false;
    *key = f->start->key;
    tElement *delete = f->start;
    f->start = f->start->next;
    free(delete);
    if (f->start == NULL)
        f->end = NULL;
    return true;
}
void restartQueue(tQueue *f) {
    tElement *end = f->start;
    while (end != NULL) {
        tElement *delete = end;
        end = end->next;
        free(delete);
    }
    f->start = NULL;
    f->end = NULL;
}