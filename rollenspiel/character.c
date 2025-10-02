#include "character.h"
#include <stdio.h>
#include <string.h>

static void trim_nl(char *s) {
    size_t i = strcspn(s, "\n");
    s[i] = '\0';
}

void createCharacter(Character *ch) {
    if (!ch) return;

    printf("Geben Sie Ihren Namen ein: ");
    if (!fgets(ch->name, sizeof(ch->name), stdin)) ch->name[0] = '\0';
    trim_nl(ch->name);
    if (ch->name[0] == '\0') snprintf(ch->name, sizeof(ch->name), "Spieler");

    ch->health = 100;
    ch->attack = 20;
    ch->status.poisoned = 0;
    ch->status.stunned  = 0;

    printf("----Character------\n");
    printf("Name: %s\nGesundheit: %d\nAngriff: %d\n\n",
           ch->name, ch->health, ch->attack);
}

void displayCharacter(const Character *ch) {
    if (!ch) return;
    printf("----Character------\n");
    printf("Name: %s\n", ch->name);
    printf("Gesundheit: %d\n", ch->health);
    printf("Angriff: %d\n", ch->attack);
    printf("Status: Vergiftet: %u, Betäubt: %u\n",
           ch->status.poisoned, ch->status.stunned);
}