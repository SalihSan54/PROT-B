#ifndef MONSTER_H
#define MONSTER_H

#include <stddef.h>

typedef struct {
    char name[50];
    int  health;
    int  attack;
    int  alive;  // 1 = lebt
    struct {
        unsigned poisoned : 1;
        unsigned stunned  : 1;
    } status;
} Monster;

Monster* createMonsters(size_t count);
void     displayMonster(const Monster *m);
void     freeMonsters(Monster *arr);

#endif // MONSTER_H