#ifndef ATTACK_H
#define ATTACK_H

#include "character.h"
#include "monster.h"

typedef enum {
    ATTACK_PHYSICAL = 1,
    ATTACK_MAGICAL  = 2,
    ATTACK_RANGED   = 3,
    ATTACK_POISON   = 4
} AttackType;

double      calcDamage(int base, AttackType t);
void        performAttack(Character *attacker, Monster *defender, AttackType t);
void        performMonsterAttack(Monster *attacker, Character *defender);
const char* attackName(AttackType t);

#endif // ATTACK_H