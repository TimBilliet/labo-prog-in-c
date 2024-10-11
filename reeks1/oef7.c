#include <stdbool.h>
#include <stdio.h>
int main() {
    const double hoek = 5;
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
    for (int i = 1; i <= AANTALTERMEN * 2; i++) {
        int n = 2 * i + 1;
        faculteit = faculteit * n * (n - 1);
        x = x * hoek * hoek;

        if (minOfPlus) {
            resultaat -= x / faculteit;
        } else {
            resultaat += x / faculteit;
        }
        minOfPlus = !minOfPlus;
    }

    printf("Sinus van %frad = %f\n", hoek, resultaat);
    return 0;
}