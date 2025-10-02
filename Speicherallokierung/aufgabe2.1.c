#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;          // Anzahl der Elemente
    int *array;     // Zeiger auf dynamisches Array
    int sum = 0;    // Summe der Elemente
    double avg;     // Durchschnittswert

    // 1. Eingabe der Anzahl der Elemente
    printf("Geben Sie die Anzahl der Elemente ein: ");
    scanf("%d", &n);

    // 2. Dynamische Speicherzuweisung mit malloc()
    array = (int *)malloc(n * sizeof(int)); //resreviert speicher für n ganze Zahlen
    if (array == NULL) { //if (array == NULL) prüft, ob die Speicheranforderung fehlgeschlagen ist
        printf("Fehler: Speicher konnte nicht zugewiesen werden!\n");
        return 1; // Programm beenden, wenn malloc fehlschlägt
    }

    // 3. Eingabe der Array-Elemente
    printf("Geben Sie %d ganze Zahlen ein:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &array[i]);
        sum += array[i]; // gleichzeitig Summe berechnen
    }

    // 4. Durchschnitt berechnen und ausgeben
    avg = (double)sum / n;
    printf("Der Durchschnitt der Elemente ist: %.2f\n", avg);

    // 5. Speicher wieder freigeben
    free(array); //mit free(array) wird der Speicher am Ende wieder freigegeben.

    return 0;
}
