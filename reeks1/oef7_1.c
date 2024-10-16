#include <math.h>
#include <stdio.h>

int main() {
    const double hoek = 4;
    double faculteit = 1;
    int minOfPlus = 1;
    double x = hoek;
    double resultaat = hoek;
    const int AANTALTERMEN = 10;
    // V1
    // for (int i = 1; i <= AANTALTERMEN * 2; i++) {
    //     faculteit = faculteit * i;

    //     if (i > 1) {
    //         x = x * hoek;
    //         if (i % 2 != 0) {
    //             printf("%d! = %f  macht=%f\n", i, faculteit, x);

    //             if (minOfPlus) {
    //                 resultaat -= (1 / faculteit) * x;
    //             } else if (!minOfPlus) {
    //                 resultaat += (1 / faculteit) * x;
    //             }
    //             minOfPlus = !minOfPlus;
    //         }
    //     }
    // }

    // V2
    for (int i = 1; i <= AANTALTERMEN; i++) {
        int n = 2 * i + 1;
        faculteit = faculteit * n * (n - 1);
        x = x * hoek * hoek;
        resultaat += (minOfPlus ? -1 : 1) * (x / faculteit);
        minOfPlus = !minOfPlus;
    }

    printf("Sinus van %frad = %f\n", hoek, resultaat);
    printf("Sinus van %frad met math.h = %f\n", hoek, sin(hoek));  // bij 0.23 is het resultaat is gelijk tot 6 cijfers na de komma bij 8.2 is het  resultaat maar correct tot 1 cijfer na de komma
    return 0;
}