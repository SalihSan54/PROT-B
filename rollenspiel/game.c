#include "game.h"
#include <stdio.h>

static int monstersAlive(Monster *arr, int n) {
    for (int i = 0; i < n; ++i)
        if (arr[i].alive) return 1;
    return 0;
}

static void poisonTick(Character *ch, Monster *m) {
    const int t = 5;
    if (m && m->alive && m->status.poisoned) {
        m->health -= t;
        printf("Gift verursacht %d Schaden an %s.\n", t, m->name);
        if (m->health <= 0) m->alive = 0;
    }
    if (ch && ch->status.poisoned) {
        ch->health -= t;
        printf("Gift verursacht %d Schaden an %s.\n", t, ch->name);
    }
}

AttackType selectAttack(void) {
    int x = 0;
    printf("\nWählen Sie eine Angriffsart:\n");
    printf("1: Physischer Angriff\n");
    printf("2: Magischer Angriff\n");
    printf("3: Fernkampfangriff\n");
    printf("4: Giftangriff\n");
    printf("Geben Sie die Nummer der Angriffsart ein: ");
    while (scanf("%d", &x) != 1 || x < 1 || x > 4) {
        while (getchar() != '\n');
        printf("Bitte 1-4 eingeben: ");
    }
    while (getchar() != '\n');
    return (AttackType)x;
}

void selectMonster(Monster *arr, int n, int *indexOut) {
    printf("\nWählen Sie ein Monster zum Kämpfen:\n");
    for (int i = 0; i < n; ++i) {
        printf("%d: %s (Gesundheit: %d, Angriff: %d)%s\n",
               i + 1, arr[i].name, arr[i].health, arr[i].attack,
               arr[i].alive ? "" : " [besiegt]");
    }
    printf("Geben Sie die Nummer des Monsters ein: ");
    int x = 0;
    while (scanf("%d", &x) != 1 || x < 1 || x > n || !arr[x-1].alive) {
        while (getchar() != '\n');
        printf("Bitte lebendes Monster (1-%d) wählen: ", n);
    }
    while (getchar() != '\n');
    *indexOut = x - 1;
}

void startGame(Character *player, Monster *arr, int n) {
    if (!player || !arr || n <= 0) return;

    while (player->health > 0 && monstersAlive(arr, n)) {
        int idx = 0;
        selectMonster(arr, n, &idx);

        AttackType t = selectAttack();
        performAttack(player, &arr[idx], t);
        poisonTick(player, &arr[idx]);

        if (!arr[idx].alive) {
            printf("\nSie haben %s besiegt!\n", arr[idx].name);
            if (!monstersAlive(arr, n)) break;
            continue;
        }

        performMonsterAttack(&arr[idx], player);
        poisonTick(player, &arr[idx]);

        printf("\nZwischenstand:\n");
        printf("%s: Gesundheit %d\n", player->name, player->health);
        printf("%s: Gesundheit %d\n\n", arr[idx].name, arr[idx].health);
    }

    if (player->health > 0 && !monstersAlive(arr, n)) {
        printf("Glückwunsch, Sie haben alle Monster besiegt!\n");
    } else if (player->health <= 0) {
        printf("Sie wurden besiegt...\n");
    }
}