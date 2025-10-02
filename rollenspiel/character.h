#ifndef CHARACTER_H
#define CHARACTER_H

typedef struct {
    char name[50];
    int  health;
    int  attack;
    struct {
        unsigned poisoned : 1;
        unsigned stunned  : 1;
    } status;
} Character;

void createCharacter(Character *ch);
void displayCharacter(const Character *ch);

#endif // CHARACTER_H