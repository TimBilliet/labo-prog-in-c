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
    double resultaat = 0;
    double term = hoek;

    int n = 1;
    while (((term < 0) ? -term : term) > 1e-16) {  //(x < 0) ? -x : x) = absolute waarde van x
        resultaat += term;
        n += 2;
        term *= -1 * (hoek * hoek / (n * (n - 1)));
    }

    printf("Sinus van %frad = %f\n", hoek, resultaat);
    return 0;
}