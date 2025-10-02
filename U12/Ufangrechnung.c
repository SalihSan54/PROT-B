#include <stdio.h>
#define PI 3.141592653589793

// Funktion zur Berechnung von Fläche und Umfang
void rechne_kreisdaten(double radius, double *flaeche, double *umfang) {
    *flaeche = PI * radius * radius;     // Fläche = π * r²
    *umfang  = 2 * PI * radius;          // Umfang = 2 * π * r
}

int main() {
    double r;
    double f, u;

    printf("Bitte Radius eingeben: ");
    scanf("%lf", &r);

    // Funktionsaufruf
    rechne_kreisdaten(r, &f, &u);

    printf("Radius: %.2f\n", r);
    printf("Flaeche: %.2f\n", f);
    printf("Umfang: %.2f\n", u);

    return 0;
}
