#ifndef GAME_H
#define GAME_H

#include "attack.h"

AttackType selectAttack(void);
void       selectMonster(Monster *arr, int count, int *indexOut);
void       startGame(Character *player, Monster *arr, int count);

#endif // GAME_H