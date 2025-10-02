#include "character.h"
#include "monster.h"
#include "game.h"

int main(void) {
    Character player;
    createCharacter(&player);

    const int num = 3;
    Monster *monsters = createMonsters(num);

    startGame(&player, monsters, num);

    freeMonsters(monsters);
    return 0;
}