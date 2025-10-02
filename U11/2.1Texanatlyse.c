// counttext.c
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
    const char *filename = (argc >= 2) ? argv[1] : "Beispieldatei.txt";
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        perror("Datei konnte nicht geöffnet werden");
        return 1;
    }

    long bytes = 0;
    long lines = 0;
    long words = 0;

    bool in_word = false;
    int ch, last = -1;

    while ((ch = fgetc(fp)) != EOF) {
        bytes++;

        if (ch == '\n') lines++;

        if (isspace((unsigned char)ch)) {
            in_word = false;
        } else {
            if (!in_word) {  // Start eines neuen Wortes
                words++;
                in_word = true;
            }
        }
        last = ch;
    }
    fclose(fp);

    // Falls die Datei nicht mit '\n' endet, zählt die letzte Zeile trotzdem
    if (bytes > 0 && last != '\n') lines++;

    printf("Datei: %s\n", filename);
    printf("Zeilen:    %ld\n", lines);
    printf("Wörter:    %ld\n", words);
    printf("Zeichen*:  %ld\n", bytes);
    printf("* Zeichen = Bytes (wie 'wc').\n");
    return 0;
}
