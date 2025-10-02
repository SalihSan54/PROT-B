#include "attack.h"
#include <stdio.h>

const char* attackName(AttackType t) {
    switch (t) {
        case ATTACK_PHYSICAL: return "physischem Angriff";
        case ATTACK_MAGICAL:  return "magischem Angriff";
        case ATTACK_RANGED:   return "Fernkampfangriff";
        case ATTACK_POISON:   return "Giftangriff";
        default:              return "Angriff";
    }
}

double calcDamage(int base, AttackType t) {
    switch (t) {
        case ATTACK_PHYSICAL: return base * 1.0;
        case ATTACK_MAGICAL:  return base * 1.5;
        case ATTACK_RANGED:   return base * 1.2; // frei festgelegt
        case ATTACK_POISON:   return base * 0.5; // Sofortschaden
        default:              return base;
    }
}

void performAttack(Character *attacker, Monster *defender, AttackType t) {
    if (!attacker || !defender || !defender->alive) return;

    int dmg = (int)(calcDamage(attacker->attack, t) + 0.5);
    printf("%s greift %s mit einem %s an!\n",
           attacker->name, defender->name, attackName(t));

    defender->health -= dmg;
    printf("Schaden %s: %d\n", defender->name, dmg);

    if (t == ATTACK_POISON && defender->health > 0) {
        defender->status.poisoned = 1;
        printf("%s ist vergiftet!\n", defender->name);
    }
    if (defender->health <= 0) defender->alive = 0;
}

void performMonsterAttack(Monster *attacker, Character *defender) {
    if (!attacker || !defender || !attacker->alive) return;
    printf("%s greift %s an!\n", attacker->name, defender->name);
    defender->health -= attacker->attack;
    printf("Veränderung Gesundheit Character: -%d\n", attacker->attack);
}