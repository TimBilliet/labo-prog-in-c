#include <math.h>
#include <stdio.h>

int main() {
    const double hoek = 8.2;
    int minOfPlus = 1;
    double x = hoek;
    double resultaat = 0;
    double term = hoek;
    int n = 0;
    while (((term < 0) ? -term : term) > 1e-16) {  //(x < 0) ? -x : x) = absolute waarde van x
        resultaat += term;
        n += 2;
        term *= -1 * (hoek * hoek / (n * (n - 1)));
    }

    printf("Sinus van %frad = %f\n", hoek, resultaat);
    printf("Sinus van %frad met math.h = %f\n", hoek, sin(hoek));  // bij 0.23 is het resultaat is gelijk tot 6 cijfers na de komma bij 8.2 is het  resultaat maar correct tot 1 cijfer na de komma
    return 0;
}