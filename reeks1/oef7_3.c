#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    const int van = -3200;
    const int tot = 3200;

    srand(time(NULL));
    double hoek = (double)(van + rand() % (tot - van)) / 1000;
    //  OF
    //  double hoek = (van + rand() % (tot - van)) / 1000.0;
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
    return 0;
}