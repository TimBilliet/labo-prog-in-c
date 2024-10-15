#include <math.h>
#include <stdio.h>

int main() {
    const double hoek = -8.2;
    double faculteit = 1;
    int minOfPlus = 1;
    double x = hoek;
    double resultaat = hoek;
    long long teller = 1;
    double hoekKwadraat = hoek * hoek;  // op voorhand berekenen om een extra vermenigvuldiging te vermijden

    while (((x < 0) ? -x : x) / faculteit > 1e-16) {  //(x < 0) ? -x : x) = absolute waarde van x
        int n = 2 * teller + 1;
        faculteit = faculteit * n * (n - 1);
        x *= hoekKwadraat;
        resultaat += (minOfPlus ? -1 : 1) * (x / faculteit);
        minOfPlus = !minOfPlus;
        teller++;
    }

    printf("Sinus van %frad = %f\n", hoek, resultaat);
    printf("Sinus van %frad met math.h = %f\n", hoek, sin(hoek));  // bij 0.23 is het resultaat is gelijk tot 6 cijfers na de komma bij 8.2 is het  resultaat maar correct tot 1 cijfer na de komma
    return 0;
}