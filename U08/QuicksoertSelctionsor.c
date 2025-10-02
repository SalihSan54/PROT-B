#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Zufallsarray generieren
void generateRandomArray(int *array, int size) {
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100;  // Zahlen zwischen 0 und 99
    }
}

// Array usgabe (nur für Kontrollzweck, kann man auch weglasssen)
void printArray(int *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}
// Selection-Sort
void selectionSort(int *array, int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (array[j] < array[minIndex]) {
                minIndex = j;
            }
        }
        // Swap
        int temp = array[minIndex];
        array[minIndex] = array[i];
        array[i] = temp;
    }
}

// Vergleichs-Funktion für qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}
// Main
int main() {
    int size = 10000;   // Grösse vom Array
    int *array = malloc(size * sizeof(int));
    int *copy = malloc(size * sizeof(int));

    srand(time(NULL)); // Zufall initialisieren

    // Array mit Zufallszahllen füllen
    generateRandomArray(array, size);

    //Selection Sort messen
    for (int i = 0; i < size; i++) copy[i] = array[i];  // Kopie mache
    clock_t start = clock();
    selectionSort(copy, size);
    clock_t end = clock();
    double time_selection = (double)(end - start) / CLOCKS_PER_SEC;

    //Quicksort messen (qsort vo stdlib)
    for (int i = 0; i < size; i++) copy[i] = array[i];  // Wieder Original kopieren
    start = clock();
    qsort(copy, size, sizeof(int), compare);
    end = clock();
    double time_quick = (double)(end - start) / CLOCKS_PER_SEC;

    //Resultat ausgabe
    printf("Selection-Sort: %f Sekunden\n", time_selection);
    printf("Quick-Sort:     %f Sekunden\n", time_quick);

    free(array);
    free(copy);
    return 0;
}