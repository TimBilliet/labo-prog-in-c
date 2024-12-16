#include <math.h>
#include <stdio.h>

int main() {
    const double hoek = 0.402;
    double resultaat = 0;
    const int AANTALTERMEN = 10;
    double term = hoek;

    int n = 1;

    for (int i = 1; i <= AANTALTERMEN; i++) {
        resultaat += term;
        n += 2;
        term *= -1 * (hoek * hoek / (n * (n - 1)));
    }

    printf("Sinus van %frad = %f\n", hoek, resultaat);
    printf("Sinus van %frad met math.h = %f\n", hoek, sin(hoek));  // bij 0.23 is het resultaat is gelijk tot 6 cijfers na de komma bij 8.2 is het  resultaat maar correct tot 1 cijfer na de komma
    return 0;
}