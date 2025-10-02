#include "monster.h"
#include <stdio.h>
#include <stdlib.h>

Monster* createMonsters(size_t count) {
    if (count == 0) return NULL;
    Monster *arr = (Monster*)calloc(count, sizeof(Monster));
    if (!arr) return NULL;

    const int hp[]  = {83, 77, 93};
    const int atk[] = {16, 15, 15};

    for (size_t i = 0; i < count; ++i) {
        snprintf(arr[i].name, sizeof(arr[i].name), "Monster %zu", i + 1);
        arr[i].health = (i < 3) ? hp[i]  : 75;
        arr[i].attack = (i < 3) ? atk[i] : 14;
        arr[i].alive = 1;
        arr[i].status.poisoned = 0;
        arr[i].status.stunned  = 0;
    }
    return arr;
}

void displayMonster(const Monster *m) {
    if (!m) return;
    printf("----Monster------\n");
    printf("Name: %s\nGesundheit: %d\nAngriff: %d\n",
           m->name, m->health, m->attack);
}

void freeMonsters(Monster *arr) { free(arr); }